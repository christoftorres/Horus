#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from utils import settings
from tracer.graph.Neo4J import Neo4J
from tracer.ethereum.etherscan import Etherscan

class Tracer:
    def __init__(self, neo4j_connection, neo4j_user, neo4j_password):
        self.etherscan = Etherscan(api_key=settings.ETHERSCAN_API_TOKEN)
        self.graph = Neo4J(uri=neo4j_connection, user=neo4j_user, password=neo4j_password)
        self.graph.delete_graph()
        self.labeled_accounts = self.etherscan.get_labels()
        self.geographic_locations = self.etherscan.get_geographic_locations_of_exchanges(self.labeled_accounts)

    def trace_normal_transactions(self, attacker, account, block_number, direction, hops, hop=1, start_block=0, visited_accounts=[]):
        if hop <= hops and account not in visited_accounts:
            visited_accounts.append(account)
            transactions = self.etherscan.get_normal_transactions(account, start_block=start_block, offset=settings.ETHERSCAN_OFFSET)
            spaces = ""
            for _ in range(hop - 1):
                spaces += "  "
            print("-> "+spaces+account+" "+str(hop)+" hop(s) "+str(len(transactions))+" transaction(s)")
            if   direction == "forwards":
                transactions = [transaction for transaction in transactions if transaction["from"] == account and transaction["to"] != "" and float(transaction["value"]) >= settings.MIN_AMOUNT and int(transaction["blockNumber"]) >= block_number]
            elif direction == "backwards":
                transactions = [transaction for transaction in transactions if transaction["to"] == account and int(transaction["blockNumber"]) <= block_number]
            if len(transactions) <= settings.MAX_TRANSACTIONS:
                self.graph.store_normal_transactions(transactions, attacker, self.labeled_accounts, direction)
                for transaction in transactions:
                    if   direction == "forwards":
                        self.trace_normal_transactions(attacker, transaction["to"], block_number, direction, hops, hop + 1, start_block, visited_accounts)
                    elif direction == "backwards":
                        self.trace_normal_transactions(attacker, transaction["from"], block_number, direction, hops, hop + 1, start_block, visited_accounts)

    def trace_internal_transactions(self, attacker, account, block_number, direction, hops, hop=1, start_block=0, visited_accounts=[]):
        if hop <= hops and account not in visited_accounts:
            visited_accounts.append(account)
            transactions = self.etherscan.get_internal_transactions(account, start_block=start_block, offset=settings.ETHERSCAN_OFFSET)
            spaces = ""
            for _ in range(hop - 1):
                spaces += "  "
            print("-> "+spaces+account+" "+str(hop)+" hop(s) "+str(len(transactions))+" transaction(s)")
            if   direction == "forwards":
                transactions = [transaction for transaction in transactions if transaction["from"] == account and transaction["to"] != "" and float(transaction["value"]) >= settings.MIN_AMOUNT and int(transaction["blockNumber"]) >= block_number]
            elif direction == "backwards":
                transactions = [transaction for transaction in transactions if transaction["to"] == account and int(transaction["blockNumber"]) <= block_number]
            if len(transactions) <= settings.MAX_TRANSACTIONS:
                self.graph.store_internal_transactions(transactions, attacker, self.labeled_accounts, direction)
                for transaction in transactions:
                    if   direction == "forwards":
                        self.trace_internal_transactions(attacker, transaction["to"], block_number, direction, hops, hop + 1, start_block, visited_accounts)
                    elif direction == "backwards":
                        self.trace_internal_transactions(attacker, transaction["from"], block_number, direction, hops, hop + 1, start_block, visited_accounts)

    def trace_token_transactions(self, attacker, account, block_number, direction, hops, hop=1, start_block=0, visited_accounts=[]):
        if hop <= hops and account not in visited_accounts:
            visited_accounts.append(account)
            transactions = self.etherscan.get_token_transactions(account, start_block=start_block, offset=settings.ETHERSCAN_OFFSET)
            spaces = ""
            for _ in range(hop - 1):
                spaces += "  "
            print("-> "+spaces+account+" "+str(hop)+" hop(s) "+str(len(transactions))+" transaction(s)")
            if   direction == "forwards":
                transactions = [transaction for transaction in transactions if transaction["from"] == account and int(transaction["value"]) > 0 and int(transaction["blockNumber"]) >= block_number]
            elif direction == "backwards":
                transactions = [transaction for transaction in transactions if transaction["to"] == account and int(transaction["blockNumber"]) <= block_number]
            if len(transactions) <= settings.MAX_TRANSACTIONS:
                self.graph.store_token_transactions(transactions, attacker, self.labeled_accounts, direction)
                for transaction in transactions:
                    if   direction == "forwards":
                        self.trace_token_transactions(attacker, transaction["to"], block_number, direction, hops, hop + 1, start_block, visited_accounts)
                    elif direction == "backwards":
                        self.trace_token_transactions(attacker, transaction["from"], block_number, direction, hops, hop + 1, start_block, visited_accounts)
