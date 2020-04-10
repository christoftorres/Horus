#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import csv
import time
import shutil
import datetime
import tracemalloc

csv.field_size_limit(sys.maxsize)

BATCH_SIZE = 1000000
FOLDER = "/work/projects/horus/"

def main():
    tracemalloc.start()
    if os.path.isfile(FOLDER+"create_extractor_files.log"):
        os.remove(FOLDER+"create_extractor_files.log")

    # Load contract addresses into memory
    start = time.time()
    contract_addresses = {}
    with open(FOLDER+"contract_addresses.txt", "r") as txtfile:
        for address in txtfile:
            contract_addresses[address.rstrip()] = True
    end = time.time()
    log = open(FOLDER+"create_extractor_files.log", "a")
    print("Loaded "+str(len(contract_addresses))+" contract addresses into memory in "+str(end - start)+" seconds.")
    log.write("Loaded "+str(len(contract_addresses))+" contract addresses into memory in "+str(end - start)+" seconds.\n")
    log.close()
    print_memory_usage()

    # Load necessary block information into memory
    start = time.time()
    blocks = {}
    with open(FOLDER+"blocks.csv", "r") as csvfile:
        csvreader = csv.reader(csvfile)
        for row in csvreader:
            if csvreader.line_num > 1:
                blocks[row[0]] = [int(row[15]), int(row[14]), int(row[16])]
    end = time.time()
    log = open(FOLDER+"create_extractor_files.log", "a")
    print("Loaded "+str(len(blocks))+" blocks into memory in "+str(end - start)+" seconds.")
    log.write("Loaded "+str(len(blocks))+" blocks into memory in "+str(end - start)+" seconds.\n")
    log.close()
    print_memory_usage()

    # Loop through transactions and aggregate information
    start = time.time()
    contracts = {}
    transaction_count = 0
    contract_count = 0
    transaction_hash = ""
    total_transactions = 0
    batch_count = 0
    if os.path.isdir(FOLDER+"contracts"):
        shutil.rmtree(FOLDER+"contracts")
    if not os.path.isdir(FOLDER+"contracts"):
        os.mkdir(FOLDER+"contracts")
    with open(FOLDER+"transactions.csv", "r") as csvfile:
        csvreader = csv.reader(csvfile)
        for row in csvreader:
            if csvreader.line_num > 1 and int(row[8]) > 21000: # Check if transaction uses more than 21000 gas
                address = row[6]
                transaction_hash = row[0]
                total_transactions += 1
                if address in contract_addresses:
                    if not address in contracts:
                        contracts[address] = []
                    data = [row[0], row[5], row[6], row[10], int(row[3])]
                    data += blocks[row[3]]
                    contracts[address].append(data)
                    transaction_count += 1
                    batch_count += 1
            if batch_count >= BATCH_SIZE:
                print_memory_usage()
                contract_count = dump_to_storage(contracts, contract_count, transaction_hash, batch_count, transaction_count, total_transactions)
                batch_count = 0
                # Free memory
                del contracts
                contracts = {}
                print_memory_usage()
    if contracts:
        contract_count = dump_to_storage(contracts, contract_count, transaction_hash, batch_count, transaction_count, total_transactions)
    end = time.time()
    log = open(FOLDER+"create_extractor_files.log", "a")
    print("Aggregated "+str(transaction_count)+" transactions into "+str(contract_count)+" contracts to disk in "+str(end - start)+" seconds.")
    log.write("Aggregated "+str(transaction_count)+" transactions into "+str(contract_count)+" contracts to disk in "+str(end - start)+" seconds.\n")
    log.close()
    print_memory_usage()

def dump_to_storage(contracts, contract_count, transaction_hash, batch_count, transaction_count, total_transactions):
    log = open(FOLDER+"create_extractor_files.log", "a")
    print("Dumping contracts to disk... "+str(datetime.datetime.now())+" "+str(transaction_hash)+" "+str(batch_count)+" "+str(transaction_count)+" "+str(total_transactions))
    log.write("Dumping contracts to disk... "+str(datetime.datetime.now())+" "+str(transaction_hash)+" "+str(batch_count)+" "+str(transaction_count)+" "+str(total_transactions)+"\n")
    log.close()
    for address in contracts:
        if os.path.isfile(FOLDER+"contracts/"+str(address)+".csv"):
            with open(FOLDER+"contracts/"+str(address)+".csv", "a+") as write_obj:
                csv_writer = csv.writer(write_obj)
                for data in contracts[address]:
                    csv_writer.writerow(data)
        else:
            with open(FOLDER+"contracts/"+str(address)+".csv", "w") as write_obj:
                csv_writer = csv.writer(write_obj)
                for data in contracts[address]:
                    csv_writer.writerow(data)
                contract_count += 1
    return contract_count

def print_memory_usage():
    current, peak = tracemalloc.get_traced_memory()
    log = open(FOLDER+"create_extractor_files.log", "a")
    print("Current: %d MB, Peak %d MB" % (int(current/1024/1024), int(peak/1024/1024)))
    log.write("Current: %d MB, Peak %d MB\n" % (int(current/1024/1024), int(peak/1024/1024)))
    log.close()

if __name__ == '__main__':
    main()
