#!/usr/bin/python
# -*- coding: utf-8 -*-

import re
import os
import csv
import sys
import math
import json
import shutil
import zipfile
import requests
import traceback


import cfscrape

import decimal

from io import StringIO
from pathlib import Path
from web3 import Web3
from tqdm import tqdm
from datetime import datetime
from collections import OrderedDict
from pyetherchain.pyetherchain import EtherChainApi

FOLDER = "/Users/Christof/Downloads/results"

print("Evaluating results...")

transactions = {
    "reentrancy": set(),
    "erc777_reentrancy": set(),
    "cross_function_reentrancy": set(),
    "delegated_reentrancy": set(),
    "create_based_reentrancy": set(),
    "unhandled_exception": set(),
    "transaction_order_dependence": set(),
    "block_state_dependence": set(),
    "timestamp_dependence": set(),
    "transaction_state_dependence": set(),
    "call_stack_depth": set(),
    "integer_overflow_addition": set(),
    "integer_overflow_multiplication": set(),
    "integer_underflow": set(),
    "dos_with_unexpected_throw": set(),
    "dos_with_block_gas_limit": set(),
    "short_address": set(),
    "unchecked_delegatecall": set(),
    "unchecked_suicide": set(),
    "parity_wallet_hack_1": set(),
    "parity_wallet_hack_2": set(),
    "block_stuffing": set(),
    "insufficient_gas": set()
}

contracts = {
    "reentrancy": set(),
    "erc777_reentrancy": set(),
    "cross_function_reentrancy": set(),
    "delegated_reentrancy": set(),
    "create_based_reentrancy": set(),
    "unhandled_exception": set(),
    "transaction_order_dependence": set(),
    "block_state_dependence": set(),
    "timestamp_dependence": set(),
    "transaction_state_dependence": set(),
    "call_stack_depth": set(),
    "integer_overflow_addition": set(),
    "integer_overflow_multiplication": set(),
    "integer_underflow": set(),
    "dos_with_unexpected_throw": set(),
    "dos_with_block_gas_limit": set(),
    "short_address": set(),
    "unchecked_delegatecall": set(),
    "unchecked_suicide": set(),
    "parity_wallet_hack_1": set(),
    "parity_wallet_hack_2": set(),
    "block_stuffing": set(),
    "insufficient_gas": set()
}

contracts_total = set()
transactions_total = set()

if __name__ == '__main__':
    if os.path.isdir('results'):
        shutil.rmtree('results')
    os.mkdir('results')

    reentrancy_results_file                         = open('results/reentrancy.csv', 'w')
    cross_function_reentrancy_results_file          = open('results/cross_function_reentrancy.csv', 'w')
    delegated_reentrancy_results_file               = open('results/delegated_reentrancy.csv', 'w')
    create_based_reentrancy_results_file            = open('results/create_based_reentrancy.csv', 'w')
    erc777_reentrancy_results_file                  = open('results/erc777_reentrancy.csv', 'w')
    unhandled_exception_results_file                = open('results/unhandled_exception.csv', 'w')
    transaction_order_dependence_results_file       = open('results/transaction_order_dependence.csv', 'w')
    block_state_dependence_results_file             = open('results/block_state_dependence.csv', 'w')
    timestamp_dependence_results_file               = open('results/timestamp_dependence.csv', 'w')
    transaction_state_dependence_results_file       = open('results/transaction_state_dependence.csv', 'w')
    call_stack_depth_results_file                   = open('results/call_stack_depth.csv', 'w')
    integer_overflow_addition_results_file          = open('results/integer_overflow_addition.csv', 'w')
    integer_overflow_multiplication_results_file    = open('results/integer_overflow_multiplication.csv', 'w')
    integer_underflow_results_file                  = open('results/integer_underflow.csv', 'w')
    dos_with_unexpected_throw_results_file          = open('results/dos_with_unexpected_throw.csv', 'w')
    dos_with_block_gas_limit_results_file           = open('results/dos_with_block_gas_limit.csv', 'w')
    short_address_results_file                      = open('results/short_address.csv', 'w')
    unchecked_delegatecall_results_file             = open('results/unchecked_delegatecall.csv', 'w')
    unchecked_suicide_results_file                  = open('results/unchecked_suicide.csv', 'w')
    parity_wallet_hack_1_results_file               = open('results/parity_wallet_hack_1.csv', 'w')
    parity_wallet_hack_2_results_file               = open('results/parity_wallet_hack_2.csv', 'w')
    block_stuffing_results_file                     = open('results/block_stuffing.csv', 'w')
    insufficient_gas_results_file                   = open('results/insufficient_gas.csv', 'w')

    reentrancy_results_writer = csv.writer(reentrancy_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    cross_function_reentrancy_results_writer = csv.writer(cross_function_reentrancy_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    delegated_reentrancy_results_writer = csv.writer(delegated_reentrancy_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    create_based_reentrancy_results_writer = csv.writer(create_based_reentrancy_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    erc777_reentrancy_results_writer = csv.writer(erc777_reentrancy_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    unhandled_exception_results_writer = csv.writer(unhandled_exception_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    transaction_order_dependence_results_writer = csv.writer(transaction_order_dependence_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    block_state_dependence_results_writer = csv.writer(block_state_dependence_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    timestamp_dependence_results_writer = csv.writer(timestamp_dependence_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    transaction_state_dependence_results_writer = csv.writer(transaction_state_dependence_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    call_stack_depth_results_writer = csv.writer(call_stack_depth_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    integer_overflow_addition_results_writer = csv.writer(integer_overflow_addition_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    integer_overflow_multiplication_results_writer = csv.writer(integer_overflow_multiplication_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    integer_underflow_results_writer = csv.writer(integer_underflow_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    dos_with_unexpected_throw_results_writer = csv.writer(dos_with_unexpected_throw_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    dos_with_block_gas_limit_results_writer = csv.writer(dos_with_block_gas_limit_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    short_address_results_writer = csv.writer(short_address_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    unchecked_delegatecall_results_writer = csv.writer(unchecked_delegatecall_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    unchecked_suicide_results_writer = csv.writer(unchecked_suicide_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    parity_wallet_hack_1_results_writer = csv.writer(parity_wallet_hack_1_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    parity_wallet_hack_2_results_writer = csv.writer(parity_wallet_hack_2_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    block_stuffing_results_writer = csv.writer(block_stuffing_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    insufficient_gas_results_writer = csv.writer(insufficient_gas_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)

    pathlist = Path(FOLDER).glob('**/*.zip')
    with tqdm(total=len(list(Path(FOLDER).glob('**/*.zip'))), unit=" contract", leave=False, smoothing=0.1) as pbar:
        for path in pathlist:
            contract = str(path).split('/')[-1].split('.')[0]
            try:
                with zipfile.ZipFile(path) as z:
                    for filename in z.namelist():
                        if filename.endswith(".csv"):
                            with z.open(filename) as f:
                                csv.field_size_limit(sys.maxsize)
                                s = StringIO(f.read().decode("utf-8"))
                                reader = csv.reader(s, delimiter='\t')
                                for row in reader:
                                    attack = os.path.splitext(os.path.basename(filename))[0]

                                    if attack == "CallStackDepth":
                                        contract = row[3]
                                        contracts["call_stack_depth"].add(contract)
                                        transactions["call_stack_depth"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        call_stack_depth_results_writer.writerow(row)

                                    elif attack == "Reentrancy":
                                        contract = row[2]
                                        contracts["reentrancy"].add(contract)
                                        transactions["reentrancy"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        reentrancy_results_writer.writerow(row)

                                    elif attack == "ERC777Reentrancy":
                                        contract = row[2]
                                        contracts["erc777_reentrancy"].add(contract)
                                        transactions["erc777_reentrancy"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        erc777_reentrancy_results_writer.writerow(row)

                                    elif attack == "CrossFunctionReentrancy":
                                        contract = row[2]
                                        contracts["cross_function_reentrancy"].add(contract)
                                        transactions["cross_function_reentrancy"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        cross_function_reentrancy_results_writer.writerow(row)

                                    elif attack == "DelegatedReentrancy":
                                        contract = row[2]
                                        contracts["delegated_reentrancy"].add(contract)
                                        transactions["delegated_reentrancy"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        delegated_reentrancy_results_writer.writerow(row)

                                    elif attack == "CreateBasedReentrancy":
                                        contract = row[2]
                                        contracts["create_based_reentrancy"].add(contract)
                                        transactions["create_based_reentrancy"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        create_based_reentrancy_results_writer.writerow(row)

                                    elif attack == "UnhandledException":
                                        contract = row[3]
                                        contracts["unhandled_exception"].add(contract)
                                        transactions["unhandled_exception"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        unhandled_exception_results_writer.writerow(row)

                                    elif attack == "IntegerOverflow":
                                        if row[4] == "ADD":
                                            contracts["integer_overflow_addition"].add(contract)
                                            transactions["integer_overflow_addition"].add(row[0])
                                            contracts_total.add(contract)
                                            transactions_total.add(row[0])
                                            row.insert(0, contract)
                                            integer_overflow_addition_results_writer.writerow(row)
                                        elif row[4] == "MUL":
                                            contracts["integer_overflow_multiplication"].add(contract)
                                            transactions["integer_overflow_multiplication"].add(row[0])
                                            contracts_total.add(contract)
                                            transactions_total.add(row[0])
                                            row.insert(0, contract)
                                            integer_overflow_multiplication_results_writer.writerow(row)

                                    elif attack == "IntegerUnderflow":
                                        contracts["integer_underflow"].add(contract)
                                        transactions["integer_underflow"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        integer_underflow_results_writer.writerow(row)

                                    elif attack == "TransactionOrderDependency":
                                        contract = row[4]
                                        contracts["transaction_order_dependence"].add(contract)
                                        transactions["transaction_order_dependence"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        transaction_order_dependence_results_writer.writerow(row)

                                    elif attack == "UncheckedSuicide":
                                        contract = row[4]
                                        contracts["unchecked_suicide"].add(contract)
                                        transactions["unchecked_suicide"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        unchecked_suicide_results_writer.writerow(row)

                                    elif attack == "UncheckedDelegatecall":
                                        contract = row[3]
                                        contracts["unchecked_delegatecall"].add(contract)
                                        transactions["unchecked_delegatecall"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        unchecked_delegatecall_results_writer.writerow(row)

                                    elif attack == "ParityWalletHack1":
                                        contract = row[4]
                                        contracts["parity_wallet_hack_1"].add(contract)
                                        transactions["parity_wallet_hack_1"].add(row[1])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[1])
                                        row.insert(0, contract)
                                        parity_wallet_hack_1_results_writer.writerow(row)

                                    elif attack == "ParityWalletHack2":
                                        contract = row[5]
                                        contracts["parity_wallet_hack_2"].add(contract)
                                        transactions["parity_wallet_hack_2"].add(row[1])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[1])
                                        row.insert(0, contract)
                                        parity_wallet_hack_2_results_writer.writerow(row)

                                    elif attack == "ShortAddress":
                                        contracts["short_address"].add(contract)
                                        transactions["short_address"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        short_address_results_writer.writerow(row)

                                    elif attack == "DoSWithUnexpectedThrow":
                                        contract = row[3]
                                        contracts["dos_with_unexpected_throw"].add(contract)
                                        transactions["dos_with_unexpected_throw"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        dos_with_unexpected_throw_results_writer.writerow(row)

                                    elif attack == "DoSWithBlockGasLimit":
                                        contract = row[4]
                                        contracts["dos_with_block_gas_limit"].add(contract)
                                        transactions["dos_with_block_gas_limit"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        dos_with_block_gas_limit_results_writer.writerow(row)

                                    elif attack == "TimestampDependence":
                                        contract = row[3]
                                        contracts["timestamp_dependence"].add(contract)
                                        transactions["timestamp_dependence"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        timestamp_dependence_results_writer.writerow(row)

                                    elif attack == "TransactionStateDependence":
                                        contract = row[3]
                                        contracts["transaction_state_dependence"].add(contract)
                                        transactions["transaction_state_dependence"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        transaction_state_dependence_results_writer.writerow(row)

                                    elif attack == "BlockStateDependence":
                                        contract = row[3]
                                        contracts["block_state_dependence"].add(contract)
                                        transactions["block_state_dependence"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        block_state_dependence_results_writer.writerow(row)

                                    elif attack == "BlockStuffing":
                                        contract = row[3]
                                        contracts["block_stuffing"].add(contract)
                                        transactions["block_stuffing"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        block_stuffing_results_writer.writerow(row)

                                    elif attack == "InsufficientGas":
                                        contract = row[3]
                                        contracts["insufficient_gas"].add(contract)
                                        transactions["insufficient_gas"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        row.insert(0, contract)
                                        insufficient_gas_results_writer.writerow(row)
            except Exception as e:
                print(e)
                print(path)
                traceback.print_exc(file=sys.stdout)
                pass
            pbar.update(1)

    reentrancy_results_file.close()
    cross_function_reentrancy_results_file.close()
    delegated_reentrancy_results_file.close()
    create_based_reentrancy_results_file.close()
    erc777_reentrancy_results_file.close()
    unhandled_exception_results_file.close()
    transaction_order_dependence_results_file.close()
    block_state_dependence_results_file.close()
    timestamp_dependence_results_file.close()
    transaction_state_dependence_results_file.close()
    call_stack_depth_results_file.close()
    integer_overflow_addition_results_file.close()
    integer_overflow_multiplication_results_file.close()
    integer_underflow_results_file.close()
    dos_with_unexpected_throw_results_file.close()
    dos_with_block_gas_limit_results_file.close()
    short_address_results_file.close()
    unchecked_delegatecall_results_file.close()
    unchecked_suicide_results_file.close()
    parity_wallet_hack_1_results_file.close()
    parity_wallet_hack_2_results_file.close()
    block_stuffing_results_file.close()
    insufficient_gas_results_file.close()

    f = open("results.tex", "w")
    f.write(r"\begin{tabular}{l r r r}"+"\n")
    f.write(r"\toprule"+"\n")
    f.write(r"\textbf{Vulnerability} & \textbf{Contracts} & \textbf{Transactions} \\"+"\n")
    f.write(r"\midrule"+"\n")
    f.write("Same-Function Reentrancy & "+str(len(contracts["reentrancy"]))+" & "+str(len(transactions["reentrancy"]))+r" \\"+"\n")
    f.write("Cross-Function Reentrancy & "+str(len(contracts["cross_function_reentrancy"]))+" & "+str(len(transactions["cross_function_reentrancy"]))+r" \\"+"\n")
    f.write("Delegated Reentrancy & "+str(len(contracts["delegated_reentrancy"]))+" & "+str(len(transactions["delegated_reentrancy"]))+r" \\"+"\n")
    f.write("Create-Based Reentrancy & "+str(len(contracts["create_based_reentrancy"]))+" & "+str(len(transactions["create_based_reentrancy"]))+r" \\"+"\n")
    f.write("ERC777-Based Reentrancy & "+str(len(contracts["erc777_reentrancy"]))+" & "+str(len(transactions["erc777_reentrancy"]))+r" \\"+"\n")
    f.write("Transaction Origin & "+str(len(contracts["transaction_state_dependence"]))+" & "+str(len(transactions["transaction_state_dependence"]))+r" \\"+"\n")
    f.write("Unchecked Delegatecall & "+str(len(contracts["unchecked_delegatecall"]))+" & "+str(len(transactions["unchecked_delegatecall"]))+r" \\"+"\n")
    f.write("Parity Wallet Hack 1 & "+str(len(contracts["parity_wallet_hack_1"]))+" & "+str(len(transactions["parity_wallet_hack_1"]))+r" \\"+"\n")
    f.write("Unchecked Selfdestruct & "+str(len(contracts["unchecked_suicide"]))+" & "+str(len(transactions["unchecked_suicide"]))+r" \\"+"\n")
    f.write("Integer Overflow (Addition) & "+str(len(contracts["integer_overflow_addition"]))+" & "+str(len(transactions["integer_overflow_addition"]))+r" \\"+"\n")
    f.write("Integer Overflow (Multiplication) & "+str(len(contracts["integer_overflow_multiplication"]))+" & "+str(len(transactions["integer_overflow_multiplication"]))+r" \\"+"\n")
    f.write("Integer Underflow & "+str(len(contracts["integer_underflow"]))+" & "+str(len(transactions["integer_underflow"]))+r" \\"+"\n")
    f.write("Unhandled Exception & "+str(len(contracts["unhandled_exception"]))+" & "+str(len(transactions["unhandled_exception"]))+r" \\"+"\n")
    f.write("Unexpected Throw & "+str(len(contracts["dos_with_unexpected_throw"]))+" & "+str(len(transactions["dos_with_unexpected_throw"]))+r" \\"+"\n")
    f.write("Insufficient Gas Griefing & "+str(len(contracts["insufficient_gas"]))+" & "+str(len(transactions["insufficient_gas"]))+r" \\"+"\n")
    f.write("Block Gas Limit & "+str(len(contracts["dos_with_block_gas_limit"]))+" & "+str(len(transactions["dos_with_block_gas_limit"]))+r" \\"+"\n")
    f.write("Block Stuffing & "+str(len(contracts["block_stuffing"]))+" & "+str(len(transactions["block_stuffing"]))+r" \\"+"\n")
    f.write("Parity Wallet Hack 2 & "+str(len(contracts["parity_wallet_hack_2"]))+" & "+str(len(transactions["parity_wallet_hack_2"]))+r" \\"+"\n")
    f.write("Bad Randomness & "+str(len(contracts["block_state_dependence"]))+" & "+str(len(transactions["block_state_dependence"]))+r" \\"+"\n")
    f.write("Front Running & "+str(len(contracts["transaction_order_dependence"]))+" & "+str(len(transactions["transaction_order_dependence"]))+r" \\"+"\n")
    f.write("Time Manipulation & "+str(len(contracts["timestamp_dependence"]))+" & "+str(len(transactions["timestamp_dependence"]))+r" \\"+"\n")
    f.write("Short Address & "+str(len(contracts["short_address"]))+" & "+str(len(transactions["short_address"]))+r" \\"+"\n")
    f.write("Call Stack Depth Limit & "+str(len(contracts["call_stack_depth"]))+" & "+str(len(transactions["call_stack_depth"]))+r" \\"+"\n")
    f.write(r"\midrule"+"\n")
    f.write(r"\textbf{Total Unique} & \textbf{"+str(len(contracts_total))+r"} & \textbf{"+str(len(transactions_total))+r"} \\"+"\n")
    f.write(r"\bottomrule"+"\n")
    f.write(r"\end{tabular"+"\n")
    f.close()

    """print("")
    print("Number of analyzed contracts: "+str(contracts))
    print("")
    print("Total number of transactions per contract: "+str(sum(transactions)))
    print("Min number of transactions per contract: "+str(min(transactions)))
    print("Mean number of transactions per contract: "+str(mean(transactions)))
    print("Median number of transactions per contract: "+str(median(transactions)))
    print("Max number of transactions per contract: "+str(max(transactions)))
    print("")
    print("Min number of execution time per transaction: "+str(min(execution_times)))
    print("Mean number of execution time per transaction: "+str(mean(execution_times)))
    print("Median number of execution time per transaction: "+str(median(execution_times)))
    print("Max number of execution time per transaction: "+str(max(execution_times)))
    print("")
    #print("Min number of retrieval time per transaction: "+str(min(retrieval_times)))
    #print("Mean number of retrieval time per transaction: "+str(mean(retrieval_times)))
    #print("Median number of retrieval time per transaction: "+str(median(retrieval_times)))
    #print("Max number of retrieval time per transaction: "+str(max(retrieval_times)))
    #print("")"""
    print(" \t \t \t \t \t \t \t \t Contracts \t Transactions")
    print("---------------------------------------------------------------------------------------------")
    print("Number of reentrancy vulnerable contracts: \t \t \t "+str(len(contracts["reentrancy"]))+" \t \t "+str(len(transactions["reentrancy"])))
    print("Number of cross-function reentrancy vulnerable contracts: \t "+str(len(contracts["cross_function_reentrancy"]))+" \t \t "+str(len(transactions["cross_function_reentrancy"])))
    print("Number of delegated reentrancy vulnerable contracts: \t \t "+str(len(contracts["delegated_reentrancy"]))+" \t \t "+str(len(transactions["delegated_reentrancy"])))
    print("Number of create-based reentrancy vulnerable contracts: \t "+str(len(contracts["create_based_reentrancy"]))+" \t \t "+str(len(transactions["create_based_reentrancy"])))
    print("Number of ERC-777 reentrancy vulnerable contracts: \t \t "+str(len(contracts["erc777_reentrancy"]))+" \t \t "+str(len(transactions["erc777_reentrancy"])))
    print("Number of unhandled exception vulnerable contracts: \t \t "+str(len(contracts["unhandled_exception"]))+" \t \t "+str(len(transactions["unhandled_exception"])))
    print("Number of transaction order dependence vulnerable contracts: \t "+str(len(contracts["transaction_order_dependence"]))+" \t \t "+str(len(transactions["transaction_order_dependence"])))
    print("Number of block state dependence vulnerable contracts: \t \t "+str(len(contracts["block_state_dependence"]))+" \t \t "+str(len(transactions["block_state_dependence"])))
    print("Number of timestamp dependence vulnerable contracts: \t \t "+str(len(contracts["timestamp_dependence"]))+" \t \t "+str(len(transactions["timestamp_dependence"])))
    print("Number of transaction state dependence vulnerable contracts: \t "+str(len(contracts["transaction_state_dependence"]))+" \t \t "+str(len(transactions["transaction_state_dependence"])))
    print("Number of call stack depth vulnerable contracts: \t \t "+str(len(contracts["call_stack_depth"]))+" \t \t "+str(len(transactions["call_stack_depth"])))
    print("Number of integer overflow addition vulnerable contracts: \t "+str(len(contracts["integer_overflow_addition"]))+" \t \t "+str(len(transactions["integer_overflow_addition"])))
    print("Number of integer overflow multiplication vulnerable contracts:  "+str(len(contracts["integer_overflow_multiplication"]))+" \t \t "+str(len(transactions["integer_overflow_multiplication"])))
    print("Number of integer underflow vulnerable contracts: \t \t "+str(len(contracts["integer_underflow"]))+" \t \t "+str(len(transactions["integer_underflow"])))
    print("Number of DoS with unexpected throw vulnerable contracts: \t "+str(len(contracts["dos_with_unexpected_throw"]))+" \t \t "+str(len(transactions["dos_with_unexpected_throw"])))
    print("Number of DoS with block gas limit vulnerable contracts: \t "+str(len(contracts["dos_with_block_gas_limit"]))+" \t \t "+str(len(transactions["dos_with_block_gas_limit"])))
    print("Number of block stuffing contracts: \t \t  \t "+str(len(contracts["block_stuffing"]))+" \t \t "+str(len(transactions["block_stuffing"])))
    print("Number of short address vulnerable contracts: \t \t \t "+str(len(contracts["short_address"]))+" \t \t "+str(len(transactions["short_address"])))
    print("Number of unchecked delegatecall vulnerable contracts: \t \t "+str(len(contracts["unchecked_delegatecall"]))+" \t \t "+str(len(transactions["unchecked_delegatecall"])))
    print("Number of unchecked suicide vulnerable contracts: \t \t "+str(len(contracts["unchecked_suicide"]))+" \t \t "+str(len(transactions["unchecked_suicide"])))
    print("Number of Parity wallet hack 1 vulnerable contracts: \t \t "+str(len(contracts["parity_wallet_hack_1"]))+" \t \t "+str(len(transactions["parity_wallet_hack_1"])))
    print("Number of Parity wallet hack 2 vulnerable contracts: \t \t "+str(len(contracts["parity_wallet_hack_2"]))+" \t \t "+str(len(transactions["parity_wallet_hack_2"])))
    print("Number of insufficient gas vulnerable contracts: \t \t "+str(len(contracts["insufficient_gas"]))+" \t \t "+str(len(transactions["insufficient_gas"])))
    print("---------------------------------------------------------------------------------------------")
    print("Total number of vulnerable contracts: \t \t \t \t "+str(len(contracts_total))+"/"+str(len(list(Path(FOLDER).glob('**/*.zip'))))+" \t "+str(len(transactions_total)))
