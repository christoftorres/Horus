#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import csv
import time
import http
import shutil
import requests
import argparse
import traceback

from web3 import Web3

from utils.utils import *
from utils import settings

from extractor import Extractor
from analyzer import Analyzer
from tracer import Tracer

def main():
    execution_begin = time.time()
    connection = None

    try:
        global args

        print()
        print("@@@  @@@   @@@@@@   @@@@@@@   @@@  @@@   @@@@@@ ")
        print("@@@  @@@  @@@@@@@@  @@@@@@@@  @@@  @@@  @@@@@@@ ")
        print("@@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  !@@     ")
        print("!@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  !@!     ")
        print("@!@!@!@!  @!@  !@!  @!@!!@!   @!@  !@!  !!@@!!  ")
        print("!!!@!!!!  !@!  !!!  !!@!@!    !@!  !!!   !!@!!! ")
        print("!!:  !!!  !!:  !!!  !!: :!!   !!:  !!!       !:!")
        print(":!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!      !:! ")
        print("::   :::  ::::: ::  ::   :::  ::::: ::  :::: :: ")
        print(":   : :   : :  :    :   : :   : :  :   :: : :   ")
        print()

        parser = argparse.ArgumentParser()

        group1 = parser.add_mutually_exclusive_group(required=True)
        group1.add_argument(
            "-e", "--extract", action="store_true", help="extract Datalog facts for a transaction, block or contract")
        group1.add_argument(
            "-a", "--analyze", action="store_true", help="analyze Datalog facts")
        group1.add_argument(
            "-t", "--trace", action="store_true", help="trace Datalog results")

        group2 = parser.add_mutually_exclusive_group()
        group2.add_argument(
            "-tx", "--transaction-hash", type=str, help="transaction hash to be extracted")
        group2.add_argument(
            "-b", "--block-number", type=str, help="block number or block range to be extracted")
        group2.add_argument(
            "-c", "--contract-address", type=str, help="contract address or CSV file with transactions to be extracted")

        parser.add_argument(
            "-f", "--facts-folder", type=str, help="folder where Datalog facts should be extracted/analyzed (default: '"+settings.FACTS_FOLDER+"')")
        parser.add_argument(
            "-r", "--results-folder", type=str, help="folder where results should be saved (default: '"+settings.RESULTS_FOLDER+"')")
        parser.add_argument(
            "-d", "--datalog-file", type=str, help="file with Datalog rules and queries to be analyzed (default: '"+settings.DATALOG_FILE+"')")
        parser.add_argument(
            "-n", "--number-of-threads", type=int, help="number of threads available to the Datalog program to run in parallel")
        parser.add_argument(
            "-p", "--profile", action="store_true", help="run the Souffle profiler during the execution of the Datalog program")

        parser.add_argument(
            "--neo4j-connection", type=str, default="bolt://localhost:7687", help="Neo4J server connection string (default: 'bolt://localhost:7687')")
        parser.add_argument(
            "--neo4j-user", type=str, default="neo4j", help="Neo4J username")
        parser.add_argument(
            "--neo4j-password", type=str, default="ethereum", help="Neo4J password")

        parser.add_argument(
            "--type", type=str, default="normal", help="transaction type to trace: 'normal', 'internal', or 'token' (default: 'normal')")
        parser.add_argument(
            "--direction", type=str, default="forwards", help="tracing direction: 'forwards' or 'backwards' (default: 'forwards')")
        parser.add_argument(
            "--hops", type=int, default=3, help="number of hops to be traced (default: 3)")

        parser.add_argument(
            "--compress", action="store_true", help="compress facts and results into ZIP files")
        parser.add_argument(
            "--debug", action="store_true", help="print debug information to the console")
        parser.add_argument(
            "--host", type=str, help="Ethereum client HTTP-RPC host (default: '"+settings.RPC_HOST+"')")
        parser.add_argument(
            "--port", type=int, help="Ethereum client HTTP-RPC port (default: '"+str(settings.RPC_PORT)+"')")
        parser.add_argument(
            "-v", "--version", action="version", version="Horus version 0.0.1 - 'Ramses II'")

        args = parser.parse_args()

        if args.extract and not args.transaction_hash and not args.block_number and not args.contract_address:
            parser.error("--extract requires --transaction, --block or --contract")
        if args.analyze and (args.transaction_hash or args.block_number or args.contract_address):
            parser.error("--analyze does not work in conjunction with --transaction, --block or --contract")
        if args.facts_folder:
            settings.FACTS_FOLDER = args.facts_folder
        if args.results_folder:
            settings.RESULTS_FOLDER = args.results_folder
        if args.datalog_file:
            settings.DATALOG_FILE = args.datalog_file
        if args.debug:
            settings.DEBUG_MODE = args.debug
        if args.host:
            settings.RPC_HOST = args.host
        if args.port:
            settings.RPC_PORT = args.port

        if args.extract and (args.transaction_hash or args.block_number or args.contract_address) or args.trace:
            tries = 0
            network = ""
            print("Connecting to http://"+settings.RPC_HOST+":"+str(settings.RPC_PORT)+"...")
            while not settings.W3 and tries < settings.CONNECTION_RETRIES:
                try:
                    tries += 1
                    settings.W3 = Web3(Web3.HTTPProvider("http://"+settings.RPC_HOST+":"+str(settings.RPC_PORT)))
                    if settings.W3.isConnected():
                        if not "api" in dir(settings.W3):
                            chain_id = settings.W3.version.network
                            client_info = settings.W3.version.node
                        else:
                            chain_id = str(settings.W3.eth.chainId)
                            client_info = settings.W3.clientVersion
                        network = ""
                        if   chain_id == "1":
                            network = "mainnet"
                        elif chain_id == "2":
                            network = "morden"
                        elif chain_id == "3":
                            network = "ropsten"
                        else:
                            network = "unknown"
                        print("Connected to "+str(client_info)+" ("+network+")")
                    else:
                        print("Error: Could not connect to Ethereum client. Please make sure the client is running and settings are correct.")
                    if not settings.W3.eth.syncing:
                        print("Blockchain is in sync.")
                        print("Latest block: "+str(settings.W3.eth.blockNumber))
                        print()
                    else:
                        print("Blockchain is syncing... (synced at %.2f%%)" % (settings.W3.eth.syncing.currentBlock/settings.W3.eth.syncing.highestBlock*100.0))
                        print("Latest block: "+str(settings.W3.eth.syncing.currentBlock))
                        print()
                    connection = http.client.HTTPConnection(settings.RPC_HOST, settings.RPC_PORT)
                except Exception as e:
                    print(e)
                    if tries < settings.CONNECTION_RETRIES:
                        print("Retrying to connect to http://"+settings.RPC_HOST+":"+str(settings.RPC_PORT))
                        time.sleep(settings.CONNECTION_RETRY_INTERVAL)
                    else:
                        print(e)
                        return

        if args.extract and args.transaction_hash:
            transactions = []
            blocks = {}
            try:
                transaction = format_transaction(settings.W3.eth.getTransaction(args.transaction_hash))
                if transaction["gas"] > 21000:
                    transactions.append(transaction)
            except Exception as e:
                print(e)
                print("Error: Blockchain is not in sync with transaction: "+args.transaction_hash)
            extractor = Extractor()
            extractor.extract_facts_from_transactions(connection, transactions, blocks, settings.FACTS_FOLDER, args.compress)

        if args.extract and args.block_number:
            if " " in args.block_number:
                if len(args.block_number.split(" ")) != 2:
                    parser.error("--block-number has to be a number or a range of two numbers")
                block_start = args.block_number.split(" ")[0]
                if not block_start.isnumeric():
                    parser.error("--block-number has to be a number or a range of two numbers")
                block_end = args.block_number.split(" ")[1]
                if not block_end.isnumeric():
                    parser.error("--block-number has to be a number or a range of two numbers")

                if args.compress:
                    if os.path.exists(settings.FACTS_FOLDER+".zip"):
                        print("Facts have already been extracted for block: "+args.block_number)
                        return
                else:
                    if os.path.exists(settings.FACTS_FOLDER):
                        print("Facts have already been extracted for block: "+args.block_number)
                        return

                stats = {"retrieval_times": [], "extraction_times": []}
                for i in range(int(block_start), int(block_end)+1):
                    if is_block_within_ranges(i, settings.DOS_ATTACK_BLOCK_RANGES):
                        print("Error: Skipping block number "+args.block_number+" as it is within DoS attack block ranges.")
                        continue
                    print("Analyzing block "+str(i))
                    transactions = []
                    try:
                        block = settings.W3.eth.getBlock(i)
                        for j in block["transactions"]:
                            transaction = format_transaction(settings.W3.eth.getTransaction(j))
                            transactions.append(transaction)
                    except:
                        print("Error: Blockchain is not in sync with block number: "+args.block_number)
                        return
                    print("Retrieving "+str(len(transactions))+" transaction(s).\n")
                    extractor = Extractor()
                    extractor.extract_facts_from_block(connection, i, transactions, block, settings.FACTS_FOLDER, args.compress, stats)
            else:
                if not args.block_number.isnumeric():
                    parser.error("--block-number has to be a number or a range of two numbers")

                if is_block_within_ranges(int(args.block_number), settings.DOS_ATTACK_BLOCK_RANGES):
                    print("Error: Skipping block number "+args.block_number+" as it is within DoS attack block ranges.")
                    return

                if args.compress:
                    if os.path.exists(settings.FACTS_FOLDER+".zip"):
                        print("Facts have already been extracted for block: "+args.block_number)
                        return
                else:
                    if os.path.exists(settings.FACTS_FOLDER):
                        print("Facts have already been extracted for block: "+args.block_number)
                        return

                stats = {"retrieval_times": [], "extraction_times": []}
                transactions = []
                try:
                    block = settings.W3.eth.getBlock(int(args.block_number))
                    for i in block["transactions"]:
                        transaction = format_transaction(settings.W3.eth.getTransaction(i))
                        transactions.append(transaction)
                except:
                    print("Error: Blockchain is not in sync with block number: "+args.block_number)
                    return
                print("Retrieving "+str(len(transactions))+" transaction(s).\n")
                extractor = Extractor()
                extractor.extract_facts_from_block(connection, int(args.block_number), transactions, block, settings.FACTS_FOLDER, args.compress, stats)

        if args.extract and args.contract_address:
            transactions = []
            blocks = {}
            if args.contract_address.startswith("0x") and not args.contract_address.endswith(".csv") and not args.contract_address.endswith(".json"):
                api_network = "api" if network == "mainnet" else "api-"+network
                # Get the list of "normal" transactions for the given contract address
                page = 1
                while True:
                    api_response = requests.get("https://"+api_network+".etherscan.io/api?module=account&action=txlist&address="+args.contract_address+"&startblock=0&endblock="+str(settings.MAX_BLOCK_HEIGHT)+"&page="+str(page)+"&offset=10000&sort=asc&apikey="+settings.ETHERSCAN_API_TOKEN).json()
                    if not api_response or "error" in api_response:
                        if "error" in api_response:
                            print("An error occured in retrieving the list of transactions: "+str(api_response["error"]))
                        else:
                            print("An unknown error ocurred in retrieving the list of transactions!")
                    elif "result" in api_response:
                        if not api_response["result"] or len(api_response["result"]) == 0:
                            break
                        else:
                            page += 1
                            for result in api_response["result"]:
                                transaction = format_transaction(settings.W3.eth.getTransaction(result["hash"]))
                                if transaction["gas"] > 21000:
                                    if not is_block_within_ranges(transaction["blockNumber"], settings.DOS_ATTACK_BLOCK_RANGES):
                                        if not transaction in transactions:
                                            transactions.append(transaction)
                    else:
                        break
                # Get the list of "internal" transactions for the given contract address
                """page = 1
                while True:
                    api_response = requests.get("https://"+api_network+".etherscan.io/api?module=account&action=txlistinternal&address="+args.contract_address+"&startblock=0&endblock="+str(settings.MAX_BLOCK_HEIGHT)+"&page="+str(page)+"&offset=10000&sort=asc&apikey="+settings.ETHERSCAN_API_TOKEN).json()
                    if not api_response or "error" in api_response:
                        if "error" in api_response:
                            print("An error occured in retrieving the list of transactions: "+str(api_response["error"]))
                        else:
                            print("An unknown error ocurred in retrieving the list of transactions!")
                    elif "result" in api_response:
                        if len(api_response["result"]) == 0:
                            break
                        #elif len(api_response["result"]) > 100:
                        #    print(len(api_response["result"]))
                        #    break
                        else:
                            page += 1
                            for result in api_response["result"]:
                                transaction = format_transaction(settings.W3.eth.getTransaction(result["hash"]))
                                if transaction["gas"] > 21000:
                                    if not is_block_within_ranges(transaction["blockNumber"], settings.DOS_ATTACK_BLOCK_RANGES):
                                        if not transaction in transactions:
                                            transactions.append(transaction)
                    else:
                        break
                # Sort the list of transactions
                from operator import itemgetter
                transactions = sorted(transactions, key=itemgetter('blockNumber', 'transactionIndex'))"""
            elif args.contract_address.endswith(".csv"):
                csv.field_size_limit(sys.maxsize) #https://stackoverflow.com/questions/15063936/csv-error-field-larger-than-field-limit-131072
                with open(args.contract_address) as csvfile:
                    reader = csv.reader(csvfile)
                    for row in reader:
                        transaction = {}
                        transaction['hash'] = row[0]
                        transaction['from'] = row[1]
                        transaction['to'] = row[2]
                        transaction['input'] = row[3]
                        transaction['blockNumber'] = int(row[4])
                        if not is_block_within_ranges(transaction['blockNumber'], settings.DOS_ATTACK_BLOCK_RANGES):
                            transactions.append(transaction)
                        else:
                            print("Ignoring transaction "+transaction['hash']+" since it is part of the DoS attack block range.")
                        if row[4] not in blocks:
                            block = {}
                            block['number'] = int(row[4])
                            block['gasUsed'] = int(row[5])
                            block['gasLimit'] = int(row[6])
                            block['timestamp'] = int(row[7])
                            blocks[transaction['blockNumber']] = block
            elif args.contract_address.endswith(".json"):
                with open(args.contract_address, "r") as f:
                    confirmed_ct_txs = json.load(f)
                    all_txs = set()
                    for attack_type, ct_txs in confirmed_ct_txs.items():
                        if attack_type == "call-injection" or attack_type == "reentrancy" or attack_type == "call-after-destruct" or attack_type == "integer-overflow":
                            for ct, txs in ct_txs.items():
                                all_txs.update(txs)
                    transactions = []
                    for tx in all_txs:
                        transaction = format_transaction(settings.W3.eth.getTransaction(tx))
                        transactions.append(transaction)
                    extractor = Extractor()
                    extractor.extract_facts_from_transactions(connection, transactions, blocks, settings.FACTS_FOLDER, args.compress)
            else:
                print("Contract requires to be either an address, a CSV file, or a JOSN file")
                return
            print("Retrieving "+str(len(transactions))+" transaction(s).\n")
            extractor = Extractor()
            extractor.extract_facts_from_transactions(connection, transactions, blocks, settings.FACTS_FOLDER, args.compress)

        if args.analyze:
            if not has_souffle_installed():
                return
            analyzer = Analyzer()
            if not os.path.isdir(settings.RESULTS_FOLDER) or not os.listdir(settings.RESULTS_FOLDER):
                analyzer.analyze_facts(args.number_of_threads, args.profile, settings.FACTS_FOLDER, settings.RESULTS_FOLDER, settings.DATALOG_FILE, args.compress, settings.TMP_FOLDER)
            else:
                print("Datalog facts have already been analyzed.")

        if args.trace:
            tracer = Tracer(args.neo4j_connection, args.neo4j_user, args.neo4j_password)

            if args.direction != "forwards" and args.direction != "backwards":
                parser.error("--direction must be either 'forwards' or 'backwards'")

            if args.type != "normal" and args.type != "internal" and args.type != "token":
                parser.error("--type must be either 'normal', 'internal', or 'token'")

            attackers, block_numbers = [], []
            for filename in os.listdir(settings.RESULTS_FOLDER):
                if filename.endswith(".csv"):
                    with open(os.path.join(settings.RESULTS_FOLDER, filename)) as csv_file:
                        reader = csv.reader(csv_file, delimiter='\t')
                        for row in reader:
                            transaction = settings.W3.eth.getTransaction(row[0])
                            if not transaction["from"].lower() in attackers:
                                attackers.append(transaction["from"].lower())
                                block_numbers.append(transaction["blockNumber"])

            print("Found "+str(len(attackers))+" account(s).")
            for i in range(len(attackers)):
                attacker, block_number = attackers[i], block_numbers[i]
                print("Tracing "+args.type+" transactions "+args.direction+" for account "+attacker+" for up to "+str(args.hops)+" hops...")
                print()
                if   args.type == "normal":
                    tracer.trace_normal_transactions(attacker, attacker, block_number, args.direction, args.hops)
                elif args.type == "internal":
                    tracer.trace_internal_transactions(attacker, attacker, block_number, args.direction, args.hops)
                elif args.type == "token":
                    tracer.trace_token_transactions(attacker, attacker, block_number, args.direction, args.hops)

        print()
    except argparse.ArgumentTypeError as e:
        print(e)
    except Exception:
        traceback.print_exc()
        print(args)
    finally:
        if connection:
            connection.close()
            print("Connection closed.")

    execution_end = time.time()
    execution_delta = execution_end - execution_begin
    print("Overall execution took %.2f second(s)." % execution_delta)

if __name__ == '__main__':
    main()
