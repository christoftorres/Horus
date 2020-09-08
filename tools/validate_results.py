#!/usr/bin/python
# -*- coding: utf-8 -*-

import queue
import threading
import os
import csv
import requests

exitFlag = 0

global fp
global tp

#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/reentrancy"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/cross_function_reentrancy"
FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/block_state_dependence"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/transaction_state_dependence"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/timestamp_dependence"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/short_address"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/parity_wallet_hack_1"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/parity_wallet_hack_2"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/unchecked_delegatecall"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/unchecked_suicide"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/transaction_order_dependence"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/integer_underflow"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/integer_overflow_addition"
#FOLDER = "/Users/christof.torres/Git/Horus/tools/source_code/integer_overflow_multiplication"

class searchThread(threading.Thread):
   def __init__(self, threadID, queue):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.queue = queue

   def run(self):
      searchContract(self.queue)

def searchContract(queue):
    global fp
    global tp
    while not exitFlag:
        queueLock.acquire()
        if not queue.empty():
            attack, filename = queue.get()
            queueLock.release()
            with open(filename, 'r') as file:
                source = file.read()
                if attack == "reentrancy" or attack == "cross_function_reentrancy":
                    if ".call.value" in source or not "ReentrancyGuard" in source :
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "transaction_state_dependence":
                    if "tx.origin" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "timestamp_dependence":
                    if "block.timestamp" in source or "now" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "short_address":
                    if "transfer" in source or "transferFrom" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "parity_wallet_hack_1":
                    if "initWallet" in source and "execute" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "parity_wallet_hack_2":
                    if "initWallet" in source and "kill" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "block_state_dependence":
                    if "blockhash" in source or "block.coinbase" in source or "block.difficulty" in source or "block.gaslimit" in source or "block.number" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "unchecked_delegatecall":
                    if "delegatecall" in source and not "msg.sender" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "unchecked_suicide":
                    if "selfdestruct" in source or "suicide" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "transaction_order_dependence":
                    if "transferFrom" in source and "approve" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "integer_underflow":
                    if "-=" in source or " - " in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "integer_overflow_addition":
                    if "+=" in source or " + " in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()
                elif attack == "integer_overflow_multiplication":
                    if "*=" in source or not "SafeMath" in source:
                        print("TP "+filename)
                        writeLock.acquire()
                        tp += 1
                        writeLock.release()
                    else:
                        print("FP "+filename)
                        writeLock.acquire()
                        fp += 1
                        writeLock.release()


        else:
            queueLock.release()

if __name__ == "__main__":
    global fp
    global tp
    contractQueue = queue.Queue()

    queueLock = threading.Lock()
    writeLock = threading.Lock()

    fp = 0
    tp = 0

    # Create new threads
    threads = []
    threadID = 1
    for i in range(100):
        thread = searchThread(threadID, contractQueue)
        thread.start()
        threads.append(thread)
        threadID += 1

    # Fill the queue with contract addresses
    queueLock.acquire()
    for filename in os.listdir(FOLDER):
        attack = FOLDER.split("/")[-1]
        contractQueue.put((attack, FOLDER+"/"+filename))
    queueLock.release()

    print('Validating '+str(contractQueue.qsize())+' contracts...\n')

    # Wait for queue to empty
    while not contractQueue.empty():
        pass

    # Notify threads it's time to exit
    exitFlag = 1

    # Wait for all threads to complete
    for t in threads:
       t.join()

    print("FP: "+str(fp))
    print("TP: "+str(tp))
    print("p: "+str(tp/(tp+fp)))

    print('\nDone')
