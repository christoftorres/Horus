#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import shlex
import subprocess
import multiprocessing
import multiprocessing.managers

NUMBER_OF_JOBS = multiprocessing.cpu_count()

HOST = "localhost"
PORT = 8989
PASSWORD = b"Ramses II"
REMOTE_PATH = "facts"

RPC_HOST = "localhost"
RPC_PORT = 8545

############################################
#                  Server                  #
############################################

class RemoteManager(multiprocessing.managers.BaseManager):
    pass

def write_file(file_name, file_contents):
    fh = None
    try:
        fh = open(file_name, "wb")
        fh.write(file_contents)
        print("Wrote file "+file_name+" to disk.")
        return True
    except Exception as e:
        print("Error: Could not write file "+file_name+" to disk, because "+str(e))
        return False
    finally:
    	if fh is not None:
    	    fh.close()

RemoteManager.register("write_file", write_file)

def file_exists(file_name):
    print("Checking if file "+file_name+" exists...")
    return os.path.exists(file_name)

RemoteManager.register("file_exists", file_exists)

def get_list_of_missing_files(block_range):
    missing_files = []
    for i in range(block_range[0], block_range[1]):
        file_name = REMOTE_PATH+"/facts_"+str(i)+".zip"
        if not os.path.exists(file_name):
            missing_files.append(file_name)
    return missing_files

RemoteManager.register("get_list_of_missing_files", get_list_of_missing_files)

def start_server(port, password):
    print("Listening for incoming connections...")
    mgr = RemoteManager(address=('', port), authkey=password)
    server = mgr.get_server()
    server.serve_forever()

############################################
#                  Client                  #
############################################

def run_extractor(argument):
    block_number = argument
    if argument.startswith(REMOTE_PATH):
        block_number = int(argument.split("/")[-1].split(".")[0].replace("facts_", ""))
    remote = RemoteManager(address=(HOST, PORT), authkey=PASSWORD)
    remote.connect()
    exists = False
    if not argument.startswith(REMOTE_PATH):
        exists = remote.file_exists(REMOTE_PATH+"/facts_"+str(block_number)+".zip")._getvalue()
    if not exists:
        print("Extracting facts for block "+str(block_number))
        cmd = 'python3 ../horus/horus.py -e -b '+str(block_number)+' -f ../horus/facts/facts_'+str(block_number)+' --host '+RPC_HOST+' --port '+str(RPC_PORT)+' --compress'
        print(cmd)
        proc = subprocess.Popen(shlex.split(cmd), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = proc.communicate()
        if os.path.exists("../horus/facts/facts_"+str(block_number)+".zip"):
            print("Extracted facts for block "+str(block_number))
            fh = None
            try:
                fh = open("../horus/facts/facts_"+str(block_number)+".zip", "rb")
                file_contents = fh.read()
                remote_write_ok = remote.write_file(REMOTE_PATH+"/facts_"+str(block_number)+".zip", file_contents)._getvalue()
                if remote_write_ok:
                    print("Facts for block "+str(block_number)+" have been written remotely.")
                else:
                    print("Facts for block "+str(block_number)+" could not be written remotely.")
            finally:
                if fh is not None:
                    fh.close()
                os.remove("../horus/facts/facts_"+str(block_number)+".zip")
        else:
            print("Could not extract facts for block: "+str(block_number))
            print(out)
            print(err)
    else:
        print("Facts for block "+str(block_number)+" have already been extracted!")

############################################
#                   Main                   #
############################################

if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == "--server":
        start_server(PORT, PASSWORD)
    else:
        remote = RemoteManager(address=(HOST, PORT), authkey=PASSWORD)
        remote.connect()
        arguments = remote.get_list_of_missing_files((1, 10000001))._getvalue()
        print("Number of missing blocks: "+str(len(arguments)))
        print("Number of jobs: "+str(NUMBER_OF_JOBS))
        with multiprocessing.Pool(NUMBER_OF_JOBS) as pool:
            pool.map(run_extractor, arguments)
