#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import time
import http
import shutil
import requests
import argparse
import traceback

from web3 import Web3

from utils.utils import *
from utils import settings

from analyzer import Analyzer
from extractor import Extractor

def main():
    execution_begin = time.time()
    connection = None

    try:
        global args

        print("")
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
        print("")

        parser = argparse.ArgumentParser()

        group1 = parser.add_mutually_exclusive_group(required=True)
        group1.add_argument(
            "-e", "--extract", action="store_true", help="extract datalog facts for a transaction, block or contract")
        group1.add_argument(
            "-a", "--analyze", action="store_true", help="analyze datalog facts")

        group2 = parser.add_mutually_exclusive_group()
        group2.add_argument(
            "-t", "--transaction-hash", type=str, help="transaction hash to be extracted")
        group2.add_argument(
            "-b", "--block-number", type=int, help="block number to be extracted")
        group2.add_argument(
            "-c", "--contract-address", type=str, help="contract address to be extracted")

        parser.add_argument(
            "-f", "--facts-folder", type=str, help="folder where datalog facts should be extracted/analyzed (default: '"+settings.FACTS_FOLDER+"')")
        parser.add_argument(
            "-r", "--results-folder", type=str, help="folder where results should be saved (default: '"+settings.RESULTS_FOLDER+"')")
        parser.add_argument(
            "-d", "--datalog-file", type=str, help="file with datalog rules and queries to be analyzed (default: '"+settings.DATALOG_FILE+"')")

        parser.add_argument(
            "--debug", action="store_true", help="print debug information to the console")
        parser.add_argument(
            "--host", type=str, help="client HTTP-RPC listening interface (default: '"+settings.RPC_HOST+"')")
        parser.add_argument(
            "--port", type=int, help="client HTTP-RPC listening port (default: '"+str(settings.RPC_PORT)+"')")
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

        if args.extract and (args.transaction_hash or args.block_number or args.contract_address):
            tries = 0
            network = ""
            while not settings.W3 and tries < settings.CONNECTION_RETRIES:
                try:
                    tries += 1
                    settings.W3 = Web3(Web3.HTTPProvider("http://"+settings.RPC_HOST+":"+str(settings.RPC_PORT)))
                    if settings.W3.isConnected():
                        network = ""
                        if settings.W3.version.network   == "1":
                            network = "mainnet"
                        elif settings.W3.version.network == "2":
                            network = "morden"
                        elif settings.W3.version.network == "3":
                            network = "ropsten"
                        else:
                            network = "unknown"
                        print("Connected to "+str(settings.W3.version.node)+" ("+network+")")
                    else:
                        print("Error: Could not connect to Ethereum client. Please make sure the client is running and settings are correct.")
                    if not settings.W3.eth.syncing:
                        print("Blockchain is in sync.")
                        print("Latest block: "+str(settings.W3.eth.blockNumber))
                        print("")
                    else:
                        print("Blockchain is syncing... (synced at %.2f%%)" % (settings.W3.eth.syncing.currentBlock/settings.W3.eth.syncing.highestBlock*100.0))
                        print("Latest block: "+str(settings.W3.eth.syncing.currentBlock))
                        print("")
                    connection = http.client.HTTPConnection(settings.RPC_HOST, settings.RPC_PORT)
                except Exception as e:
                    if tries < settings.CONNECTION_RETRIES:
                        print("Retrying to connect to http://"+settings.RPC_HOST+":"+str(settings.RPC_PORT))
                        time.sleep(settings.CONNECTION_RETRY_INTERVAL)
                    else:
                        print(e)
                        return

        if args.extract and args.transaction_hash:
            transactions = []
            try:
                transaction = format_transaction(settings.W3.eth.getTransaction(args.transaction_hash))
                if transaction["to"] and transaction["gas"] > 21000:
                    transactions.append(transaction)
            except Exception as e:
                print(e)
                print("Error: Blockchain is not in sync with transaction: "+args.transaction_hash)
            extractor = Extractor()
            extractor.extract_facts_from_transactions(connection, transactions, settings.FACTS_FOLDER)

        if args.extract and args.block_number:
            transactions = []
            try:
                block = settings.W3.eth.getBlock(args.block_number)
                for i in block["transactions"]:
                    transaction = format_transaction(settings.W3.eth.getTransaction(i))
                    if transaction["to"] and transaction["gas"] > 21000:
                        transactions.append(transaction)
            except:
                print("Error: Blockchain is not in sync with block number: "+args.block_number[0])
            print("Retrieving "+str(len(transactions))+" transaction(s).\n")
            extractor = Extractor()
            extractor.extract_facts_from_transactions(connection, transactions, settings.FACTS_FOLDER)

        if args.extract and args.contract_address:
            transactions = []
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
                            if transaction["to"] and transaction["gas"] > 21000:
                                if not is_block_within_ranges(transaction["blockNumber"], settings.DOS_ATTACK_BLOCK_RANGES):
                                    if not transaction in transactions:
                                        transactions.append(transaction)
                else:
                    break
            """# Get the list of "internal" transactions for the given contract address
            page = 1
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
                    else:
                        page += 1
                        for result in api_response["result"]:
                            transaction = format_transaction(settings.W3.eth.getTransaction(result["hash"]))
                            if transaction["to"] and transaction["gas"] > 21000:
                                if not is_block_within_ranges(transaction["blockNumber"], settings.DOS_ATTACK_BLOCK_RANGES):
                                    if not transaction in transactions:
                                        transactions.append(transaction)
                else:
                    break
            # Sort the list of transactions
            from operator import itemgetter
            transactions = sorted(transactions, key=itemgetter('blockNumber', 'transactionIndex'))"""
            print("Retrieving "+str(len(transactions))+" transaction(s).\n")
            extractor = Extractor()
            extractor.extract_facts_from_transactions(connection, transactions, settings.FACTS_FOLDER)

        if args.analyze:
            if os.path.isdir(settings.RESULTS_FOLDER):
                shutil.rmtree(settings.RESULTS_FOLDER)
            if not os.path.isdir(settings.RESULTS_FOLDER):
                os.mkdir(settings.RESULTS_FOLDER)
            analyzer = Analyzer()
            analyzer.analyze_facts(settings.FACTS_FOLDER, settings.RESULTS_FOLDER, settings.DATALOG_FILE)

        print("")
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