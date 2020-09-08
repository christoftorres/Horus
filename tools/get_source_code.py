#!/usr/bin/python
# -*- coding: utf-8 -*-

import queue
import threading
import os
import csv
import requests

exitFlag = 0

FOLDER = "results"

class searchThread(threading.Thread):
   def __init__(self, threadID, queue, downloaded):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.queue = queue
      self.downloaded = downloaded

   def run(self):
      searchContract(self.queue, self.downloaded)

def searchContract(queue, downloaded):
    while not exitFlag:
        queueLock.acquire()
        if not queue.empty():
            attack, address = queue.get()
            queueLock.release()
            print('Checking if source code exists for contract: '+str(address))
            try:
                response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+address+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                if response['status'] == '1' and response['message'] == 'OK':
                    if response['result'][0]['SourceCode']:
                        if not os.path.isdir('source_code'):
                            os.mkdir('source_code')
                        if not os.path.isdir('source_code/'+attack):
                            os.mkdir('source_code/'+attack)
                        writeLock.acquire()
                        if len(downloaded[attack]) < 100:
                            file = open('source_code/'+attack+'/'+str(address)+'.sol', 'w')
                            file.write(response['result'][0]['SourceCode'])
                            file.close()
                            downloaded[attack].append(address)
                            print('Downloaded source code for contract: '+str(address))
                        writeLock.release()
                else:
                    print(response['result'])
            except Exception as e:
                print(e)
                pass
        else:
            queueLock.release()

if __name__ == "__main__":
    contractQueue = queue.Queue()

    queueLock = threading.Lock()
    writeLock = threading.Lock()

    downloaded = {}

    # Create new threads
    threads = []
    threadID = 1
    for i in range(5):
        thread = searchThread(threadID, contractQueue, downloaded)
        thread.start()
        threads.append(thread)
        threadID += 1

    contracts = {}
    for filename in os.listdir(FOLDER):
        if filename.endswith(".csv"):
            attack = filename.split(".")[0]
            contracts[attack] = set()
            downloaded[attack] = []
            with open(os.path.join(FOLDER, filename)) as file:
                reader = csv.reader(file)
                count = 0
                for row in reader:
                    address = row[0]
                    if not os.path.isfile('source_code/'+attack+'/'+str(address)+'.sol'):
                        contracts[attack].add(address)
                        count += 1
                    if count == 5000:
                        break

    # Fill the queue with contract addresses
    queueLock.acquire()
    for attack in contracts:
        for address in contracts[attack]:
            contractQueue.put((attack, address))
    queueLock.release()

    print('Searching for '+str(contractQueue.qsize())+' contracts...\n')

    # Wait for queue to empty
    while not contractQueue.empty():
        pass

    # Notify threads it's time to exit
    exitFlag = 1

    # Wait for all threads to complete
    for t in threads:
       t.join()

    print('\nDone')
