#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from neo4j.exceptions import ClientError
from neo4j import GraphDatabase
from datetime import datetime
from web3 import Web3

from utils import settings

class Neo4J:
    def __init__(self, uri, user, password):
        self._driver = GraphDatabase.driver(uri, auth=(user, password), encrypted=False)

    def close(self):
        self._driver.close()

    @staticmethod
    def _store_normal_transaction(tx, transaction, attacker, labeled_accounts, direction):
        if transaction["from"] == attacker:
            from_account_type = "Attacker"
        elif transaction["from"] in labeled_accounts:
            from_account_type = "Labeled_Account"
        else:
            from_account_type = "Account"

        if transaction["to"] == attacker:
            to_account_type = "Attacker"
        elif transaction["to"] in labeled_accounts:
            to_account_type = "Labeled_Account"
        else:
            to_account_type = "Account"

        account_info_from = "{address:'"+transaction["from"]+"'"
        if from_account_type == "Labeled_Account":
            account_info_from += ",label:'"+labeled_accounts[transaction["from"]]["labels"][0]+"'"
            account_info_from += ",category:'"+labeled_accounts[transaction["from"]]["category"]+"'"
        account_info_from += "}"

        account_info_to = "{address:'"+transaction["to"]+"'"
        if to_account_type == "Labeled_Account":
            account_info_to += ",label:'"+labeled_accounts[transaction["to"]]["labels"][0]+"'"
            account_info_to += ",category:'"+labeled_accounts[transaction["to"]]["category"]+"'"
        account_info_to += "}"

        if direction == "forwards":
            value = str(int(Web3.fromWei(int(transaction["value"]), 'ether')))
        else:
            value = str(Web3.fromWei(int(transaction["value"]), 'ether'))

        tx.run("""MERGE (from:"""+from_account_type+""" """+account_info_from+""")
                  MERGE (to:"""+to_account_type+""" """+account_info_to+""")
                  MERGE (from)-[:NORMAL_TRANSACTION {
                    value:$value,
                    hash:$hash,
                    block:$block,
                    timestamp:$timestamp
                }]->(to)""",
               value=value,
               hash=transaction["hash"],
               block=transaction["blockNumber"],
               timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])))

    @staticmethod
    def _store_internal_transaction(tx, transaction, attacker, labeled_accounts, direction):
        if transaction["from"] == attacker:
            from_account_type = "Attacker"
        elif transaction["from"] in labeled_accounts:
            from_account_type = "Labeled_Account"
        else:
            from_account_type = "Account"

        if transaction["to"] == attacker:
            to_account_type = "Attacker"
        elif transaction["to"] in labeled_accounts:
            to_account_type = "Labeled_Account"
        else:
            to_account_type = "Account"

        account_info_from = "{address:'"+transaction["from"]+"'"
        if from_account_type == "Labeled_Account":
            account_info_from += ",label:'"+labeled_accounts[transaction["from"]]["labels"][0]+"'"
            account_info_from += ",category:'"+labeled_accounts[transaction["from"]]["category"]+"'"
        account_info_from += "}"

        account_info_to = "{address:'"+transaction["to"]+"'"
        if to_account_type == "Labeled_Account":
            account_info_to += ",label:'"+labeled_accounts[transaction["to"]]["labels"][0]+"'"
            account_info_to += ",category:'"+labeled_accounts[transaction["to"]]["category"]+"'"
        account_info_to += "}"

        if direction == "forwards":
            value = str(int(Web3.fromWei(int(transaction["value"]), 'ether')))
        else:
            value = str(Web3.fromWei(int(transaction["value"]), 'ether'))

        tx.run("""MERGE (from:"""+from_account_type+""" """+account_info_from+""")
                  MERGE (to:"""+to_account_type+""" """+account_info_to+""")
                  MERGE (from)-[:INTERNAL_TRANSACTION {
                    value:$value,
                    hash:$hash,
                    block:$block,
                    timestamp:$timestamp
                }]->(to)""",
               value=value,
               hash=transaction["hash"],
               block=transaction["blockNumber"],
               timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])))

    @staticmethod
    def _store_token_transaction(tx, transaction, attacker, labeled_accounts, direction):
        if transaction["from"] == attacker:
            from_account_type = "Attacker"
        elif transaction["from"] in labeled_accounts:
            from_account_type = "Labeled_Account"
        else:
            from_account_type = "Account"

        if transaction["to"] == attacker:
            to_account_type = "Attacker"
        elif transaction["to"] in labeled_accounts:
            to_account_type = "Labeled_Account"
        else:
            to_account_type = "Account"

        account_info_from = "{address:'"+transaction["from"]+"'"
        if from_account_type == "Labeled_Account":
            account_info_from += ",label:'"+labeled_accounts[transaction["from"]]["labels"][0]+"'"
            account_info_from += ",category:'"+labeled_accounts[transaction["from"]]["category"]+"'"
        account_info_from += "}"

        account_info_to = "{address:'"+transaction["to"]+"'"
        if to_account_type == "Labeled_Account":
            account_info_to += ",label:'"+labeled_accounts[transaction["to"]]["labels"][0]+"'"
            account_info_to += ",category:'"+labeled_accounts[transaction["to"]]["category"]+"'"
        account_info_to += "}"

        value = str(int(int(transaction["value"]) / (int(10)**int(transaction["tokenDecimal"]))))+" "+transaction["tokenSymbol"]

        tx.run("""MERGE (from:"""+from_account_type+""" """+account_info_from+""")
                  MERGE (to:"""+to_account_type+""" """+account_info_to+""")
                  MERGE (from)-[:TOKEN_TRANSACTION {
                    value:$value,
                    hash:$hash,
                    block:$block,
                    token_name:$token_name,
                    token_symbol:$token_symbol,
                    token_decimal:$token_decimal,
                    timestamp:$timestamp
                }]->(to)""",
               value=value,
               hash=transaction["hash"],
               block=transaction["blockNumber"],
               token_name=transaction["tokenName"],
               token_symbol=transaction["tokenSymbol"],
               token_decimal=transaction["tokenDecimal"],
               timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])))

    def delete_graph(self):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    tx.run("""
                            MATCH (n)
                            DETACH DELETE n
                           """)
                except ClientError as e:
                    print(e)

    @staticmethod
    def _group_transactions_together(transactions):
        aggregated_transactions = []
        for i in range(len(transactions)):
            t = transactions[i]
            exists = False
            for a in aggregated_transactions:
                if a["from"] == t["from"] and a["to"] == t["to"]:
                    exists = True
                    a["value"] = str(int(a["value"]) + int(t["value"]))
            if not exists:
                aggregated_transactions.append(t)
        return aggregated_transactions

    @staticmethod
    def _group_token_transactions_together(transactions):
        aggregated_transactions = []
        for i in range(len(transactions)):
            t = transactions[i]
            exists = False
            for a in aggregated_transactions:
                if a["from"] == t["from"] and a["to"] == t["to"] and a["tokenSymbol"] == t["tokenSymbol"]:
                    exists = True
                    a["value"] = str(int(a["value"]) + int(t["value"]))
            if not exists:
                aggregated_transactions.append(t)
        return aggregated_transactions

    @staticmethod
    def _remove_transactions_with_no_value(transactions, attacker):
        return [transaction for transaction in transactions if float(transaction["value"]) > 0 or transaction["from"] == attacker or transaction["to"] == attacker]

    @staticmethod
    def _filter_transactions_by_value(transactions, attacker, value):
        return [transaction for transaction in transactions if float(transaction["value"]) >= value]

    def store_normal_transactions(self, transactions, attacker, labeled_accounts, direction):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    transactions = Neo4J._remove_transactions_with_no_value(transactions, attacker)
                    transactions = Neo4J._group_transactions_together(transactions)
                    transactions = Neo4J._filter_transactions_by_value(transactions, attacker, settings.MIN_AMOUNT)
                    for transaction in transactions:
                        Neo4J._store_normal_transaction(tx, transaction, attacker, labeled_accounts, direction)
                except ClientError as e:
                    print(e)

    def store_internal_transactions(self, transactions, attacker, labeled_accounts, direction):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    transactions = Neo4J._remove_transactions_with_no_value(transactions, attacker)
                    transactions = Neo4J._group_transactions_together(transactions)
                    transactions = Neo4J._filter_transactions_by_value(transactions, attacker, settings.MIN_AMOUNT)
                    for transaction in transactions:
                        Neo4J._store_internal_transaction(tx, transaction, attacker, labeled_accounts, direction)
                except ClientError as e:
                    print(e)

    def store_token_transactions(self, transactions, attacker, labeled_accounts, direction):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    transactions = Neo4J._remove_transactions_with_no_value(transactions, attacker)
                    transactions = Neo4J._group_token_transactions_together(transactions)
                    for transaction in transactions:
                        Neo4J._store_token_transaction(tx, transaction, attacker, labeled_accounts, direction)
                except ClientError as e:
                    print(e)

    @staticmethod
    def _run_cypher_query(tx, query):
        return tx.run(query)

    def run_cypher_query(self, query):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    return Neo4J._run_cypher_query(tx, query)
                except ClientError as e:
                    print(e)
        return None
