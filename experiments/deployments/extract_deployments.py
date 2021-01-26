#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time
import numpy
import pymongo
import multiprocessing

from web3 import Web3

class colors:
    INFO = '\033[94m'
    OK = '\033[92m'
    FAIL = '\033[91m'
    END = '\033[0m'

def analyze_block(block_number):
    start = time.time()
    print("Analyzing block number: "+str(block_number))

    status = mongo_connection["ethereum"]["contracts_status"].find_one({"block_number": block_number})
    if status:
        print("Block "+str(block_number)+" already analyzed!")
        return status["execution_time"]

    block = w3.eth.getBlock(block_number, True)
    for tx in block["transactions"]:
        if tx["to"] == None:
            contract = dict()

            contract["block_number"] = tx["blockNumber"]
            contract["block_timestamp"] = block["timestamp"]
            contract["gas"] = tx["gas"]
            contract["gas_price"] = tx["gasPrice"]
            contract["hash"] = tx["hash"].hex()
            contract["deployment_bytecode"] = tx["input"]
            contract["deployer_address"] = tx["from"]

            receipt = w3.eth.getTransactionReceipt(contract["hash"])
            contract["contract_address"] = receipt["contractAddress"]
            contract["gas_used"] = receipt["gasUsed"]
            if "status" in receipt:
                contract["status"] = receipt["status"]
            else:
                contract["status"] = None

            contract["bytecode"] = w3.eth.getCode(contract["contract_address"], block_number).hex()

            collection = mongo_connection["ethereum"]["contracts"]
            collection.insert_one(contract)

            # Indexing...
            if 'block_number' not in collection.index_information():
                collection.create_index('block_number')
                collection.create_index('block_timestamp')
                collection.create_index('gas')
                collection.create_index('hash')
                collection.create_index('deployment_bytecode')
                collection.create_index('deployer_address')
                collection.create_index('contract_address')
                collection.create_index('gas_used')
                collection.create_index('status')
                collection.create_index('bytecode')

            print(colors.OK+"Found contract: "+contract["contract_address"]+colors.END)

    end = time.time()
    collection = mongo_connection["ethereum"]["contracts_status"]
    collection.insert_one({"block_number": block_number, "execution_time": end-start})
    # Indexing...
    if 'block_number' not in collection.index_information():
        collection.create_index('block_number')

    return end-start

def init_child():
    global w3
    global mongo_connection

    w3 = Web3(Web3.HTTPProvider("http://localhost:8545"))
    mongo_connection = pymongo.MongoClient("mongodb://localhost:27017", maxPoolSize=None)

def main():
    execution_times = []
    multiprocessing.set_start_method('fork')
    with multiprocessing.Pool(processes=multiprocessing.cpu_count(), initializer=init_child, initargs=()) as pool:
        start_total = time.time()
        execution_times += pool.map(analyze_block, range(1, 10000001))
        end_total = time.time()
        print("Total execution time: "+str(end_total - start_total))
        print()
        if execution_times:
            print("Max execution time: "+str(numpy.max(execution_times)))
            print("Mean execution time: "+str(numpy.mean(execution_times)))
            print("Median execution time: "+str(numpy.median(execution_times)))
            print("Min execution time: "+str(numpy.min(execution_times)))

if __name__ == "__main__":
    main()
