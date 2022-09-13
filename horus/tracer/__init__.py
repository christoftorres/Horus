#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import json

from datetime import datetime

from utils import settings
from tracer.graph.Neo4J import Neo4J
from tracer.ethereum.etherscan import Etherscan

class Tracer:
    def __init__(self, neo4j_connection, neo4j_user, neo4j_password):
        self.etherscan = Etherscan(api_key=settings.ETHERSCAN_API_TOKEN)
        self.graph = Neo4J(uri=neo4j_connection, user=neo4j_user, password=neo4j_password)
        self.graph.delete_graph()
        self.labeled_accounts = self.etherscan.get_labels()
        self.geographic_locations = self.etherscan.get_geographic_locations()

    def trace_normal_transactions(self, attacker, account, timestamp, direction, hops, trace, hop=1, start_block=0, visited_accounts=[]):
        if hop <= hops and account not in visited_accounts:
            visited_accounts.append(account)
            if not os.path.exists(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json"):
                transactions = self.etherscan.get_normal_transactions(account, start_block=start_block, offset=settings.ETHERSCAN_OFFSET)
                with open(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json", "w") as f:
                    json.dump(transactions, f)
            else:
                with open(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json", "r") as f:
                    transactions = json.load(f)
            spaces = ""
            for _ in range(hop - 1):
                spaces += "  "
            print("-> "+spaces+account+" "+str(hop)+" hop(s) "+str(len(transactions))+" transaction(s)")
            if   direction == "forwards":
                transactions = [transaction for transaction in transactions if transaction["from"] == account and transaction["to"] != "" and float(transaction["value"]) >= settings.MIN_AMOUNT and int(transaction["timeStamp"]) >= timestamp]
            elif direction == "backwards":
                transactions = [transaction for transaction in transactions if transaction["to"] == account and int(transaction["timeStamp"]) <= timestamp]
            if len(transactions) <= settings.MAX_TRANSACTIONS:
                if trace != None:
                    # ------ TRACE ------
                    for transaction in transactions:
                        if transaction["from"] == attacker:
                            if not transaction["to"] in trace:
                                trace[transaction["to"]] = dict()
                                trace[transaction["to"]]["date"] = datetime.fromtimestamp(int(transaction["timeStamp"])).strftime("%d/%m/%Y %H:%M:%S")
                                if transaction["to"] in self.labeled_accounts and len(self.labeled_accounts[transaction["to"]]["labels"]):
                                    trace[transaction["to"]]["label"] = self.labeled_accounts[transaction["to"]]["labels"][0]
                                    trace[transaction["to"]]["category"] = self.labeled_accounts[transaction["to"]]["category"]
                                    if transaction["to"] in self.geographic_locations:
                                        location = self.geographic_locations[transaction["to"]]
                                        trace[transaction["to"]]["location"] = location["city"] + ", " + location["regionName"] + ", " + location["countryCode"] + "<br/>ISP: " + location["isp"] + "<br/>IP: " + location["query"]
                                    else:
                                        trace[transaction["to"]]["location"] = ""
                                else:
                                    trace[transaction["to"]]["label"] = ""
                                    trace[transaction["to"]]["category"] = ""
                                    trace[transaction["to"]]["location"] = ""
                                trace[transaction["to"]]["tokens"] = dict()
                    # -------------------
                self.graph.store_normal_transactions(transactions, attacker, self.labeled_accounts, direction)
                for transaction in transactions:
                    if   direction == "forwards":
                        self.trace_normal_transactions(attacker, transaction["to"], timestamp, direction, hops, trace, hop + 1, start_block, visited_accounts)
                    elif direction == "backwards":
                        self.trace_normal_transactions(attacker, transaction["from"], timestamp, direction, hops, trace, hop + 1, start_block, visited_accounts)

    def trace_internal_transactions(self, attacker, account, timestamp, direction, hops, hop=1, start_block=0, visited_accounts=[]):
        if hop <= hops and account not in visited_accounts:
            visited_accounts.append(account)
            if not os.path.exists(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json"):
                transactions = self.etherscan.get_internal_transactions(account, start_block=start_block, offset=settings.ETHERSCAN_OFFSET)
                with open(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json", "w") as f:
                    json.dump(transactions, f)
            else:
                with open(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json", "r") as f:
                    transactions = json.load(f)
            spaces = ""
            for _ in range(hop - 1):
                spaces += "  "
            print("-> "+spaces+account+" "+str(hop)+" hop(s) "+str(len(transactions))+" transaction(s)")
            if   direction == "forwards":
                transactions = [transaction for transaction in transactions if transaction["from"] == account and transaction["to"] != "" and float(transaction["value"]) >= settings.MIN_AMOUNT and int(transaction["timeStamp"]) >= timestamp]
            elif direction == "backwards":
                transactions = [transaction for transaction in transactions if transaction["to"] == account and int(transaction["timeStamp"]) <= timestamp]
            if len(transactions) <= settings.MAX_TRANSACTIONS:
                if trace != None:
                    # ------ TRACE ------
                    for transaction in transactions:
                        if transaction["from"] == attacker:
                            if not transaction["to"] in trace:
                                trace[transaction["to"]] = dict()
                                trace[transaction["to"]]["date"] = datetime.fromtimestamp(int(transaction["timeStamp"])).strftime("%d/%m/%Y %H:%M:%S")
                                if transaction["to"] in self.labeled_accounts and len(self.labeled_accounts[transaction["to"]]["labels"]):
                                    trace[transaction["to"]]["label"] = self.labeled_accounts[transaction["to"]]["labels"][0]
                                    trace[transaction["to"]]["category"] = self.labeled_accounts[transaction["to"]]["category"]
                                    if transaction["to"] in self.geographic_locations:
                                        location = self.geographic_locations[transaction["to"]]
                                        trace[transaction["to"]]["location"] = location["city"] + ", " + location["regionName"] + ", " + location["countryCode"] + "<br/>ISP: " + location["isp"] + "<br/>IP: " + location["query"]
                                    else:
                                        trace[transaction["to"]]["location"] = ""
                                else:
                                    trace[transaction["to"]]["label"] = ""
                                    trace[transaction["to"]]["category"] = ""
                                    trace[transaction["to"]]["location"] = ""
                                trace[transaction["to"]]["tokens"] = dict()
                    # -------------------
                self.graph.store_internal_transactions(transactions, attacker, self.labeled_accounts, direction)
                for transaction in transactions:
                    if   direction == "forwards":
                        self.trace_internal_transactions(attacker, transaction["to"], timestamp, direction, hops, trace, hop + 1, start_block, visited_accounts)
                    elif direction == "backwards":
                        self.trace_internal_transactions(attacker, transaction["from"], timestamp, direction, hops, trace, hop + 1, start_block, visited_accounts)

    def trace_token_transactions(self, attacker, account, timestamp, direction, hops, trace, hop=1, start_block=0, visited_accounts=[]):
        if hop <= hops and account not in visited_accounts:
            visited_accounts.append(account)
            if not os.path.exists(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json"):
                transactions = self.etherscan.get_token_transactions(account, start_block=start_block, offset=settings.ETHERSCAN_OFFSET)
                with open(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json", "w") as f:
                    json.dump(transactions, f)
            else:
                with open(settings.TRACES_FOLDER+"/"+attacker+"/"+account+".json", "r") as f:
                    transactions = json.load(f)
            spaces = ""
            for _ in range(hop - 1):
                spaces += "  "
            print("-> "+spaces+account+" "+str(hop)+" hop(s) "+str(len(transactions))+" transaction(s)")
            if   direction == "forwards":
                transactions = [transaction for transaction in transactions if transaction["from"] == account and int(transaction["value"]) > 0 and int(transaction["timeStamp"]) >= timestamp]
            elif direction == "backwards":
                transactions = [transaction for transaction in transactions if transaction["to"] == account and int(transaction["timeStamp"]) <= timestamp]
            if len(transactions) <= settings.MAX_TRANSACTIONS:
                if trace != None:
                    # ------ TRACE ------
                    for transaction in transactions:
                        if transaction["from"] == attacker:
                            if not transaction["to"] in trace:
                                trace[transaction["to"]] = dict()
                                trace[transaction["to"]]["date"] = datetime.fromtimestamp(int(transaction["timeStamp"])).strftime("%d/%m/%Y %H:%M:%S")
                                if transaction["to"] in self.labeled_accounts and len(self.labeled_accounts[transaction["to"]]["labels"]):
                                    trace[transaction["to"]]["label"] = self.labeled_accounts[transaction["to"]]["labels"][0]
                                    trace[transaction["to"]]["category"] = self.labeled_accounts[transaction["to"]]["category"]
                                    if transaction["to"] in self.geographic_locations:
                                        location = self.geographic_locations[transaction["to"]]
                                        trace[transaction["to"]]["location"] = location["city"] + ", " + location["regionName"] + ", " + location["countryCode"] + "<br/>ISP: " + location["isp"] + "<br/>IP: " + location["query"]
                                    else:
                                        trace[transaction["to"]]["location"] = ""
                                else:
                                    trace[transaction["to"]]["label"] = ""
                                    trace[transaction["to"]]["category"] = ""
                                    trace[transaction["to"]]["location"] = ""
                                trace[transaction["to"]]["tokens"] = dict()
                            if not transaction["tokenSymbol"] in trace[transaction["to"]]["tokens"]:
                                trace[transaction["to"]]["tokens"][transaction["tokenSymbol"]] = 0
                            trace[transaction["to"]]["tokens"][transaction["tokenSymbol"]] += int(int(transaction["value"]) / (int(10)**int(transaction["tokenDecimal"])))
                    # -------------------
                self.graph.store_token_transactions(transactions, attacker, self.labeled_accounts, direction)
                for transaction in transactions:
                    if   direction == "forwards":
                        self.trace_token_transactions(attacker, transaction["to"], timestamp, direction, hops, trace, hop + 1, start_block, visited_accounts)
                    elif direction == "backwards":
                        self.trace_token_transactions(attacker, transaction["from"], timestamp, direction, hops, trace, hop + 1, start_block, visited_accounts)
