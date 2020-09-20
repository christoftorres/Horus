
from datetime import datetime

from neo4j.exceptions import ClientError
#from neo4j.v1 import GraphDatabase
from neo4j import GraphDatabase

from web3 import Web3

class Neo4J:
    def __init__(self, uri, user, password):
        self._driver = GraphDatabase.driver(uri, auth=(user, password), encrypted=False)

    def close(self):
        self._driver.close()

    @staticmethod
    def _save_normal_transaction(tx, transaction, attacker, labeled_accounts, direction):
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
    def _save_internal_transaction(tx, transaction, attacker, labeled_accounts):
        if transaction["from"] == attacker:
            if transaction["from"] in labeled_accounts:
                tx.run("""MERGE (t:Internal_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                          MERGE (a:Attacker {address:$from_address})
                            SET a.label=$label
                            SET a.category=$category
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"],
                       value=int(transaction["value"], 16) / 1e18,
                       block=transaction["blockNumber"],
                       timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       from_address=transaction["from"],
                       label=labeled_accounts[transaction["from"]]["labels"][0],
                       category=labeled_accounts[transaction["from"]]["category"])
            else:
                tx.run("""MERGE (t:Internal_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                          MERGE (a:Attacker {address:$from_address})
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"],
                       value=int(transaction["value"], 16) / 1e18,
                       block=transaction["blockNumber"],
                       timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       from_address=transaction["from"])
        else:
            if transaction["from"] in labeled_accounts:
                tx.run("""MERGE (t:Internal_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                          MERGE (a:Labeled_Account {address:$from_address})
                            SET a.label=$label
                            SET a.category=$category
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"],
                       value=int(transaction["value"], 16) / 1e18,
                       block=transaction["blockNumber"],
                       timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       from_address=transaction["from"],
                       label=labeled_accounts[transaction["from"]]["labels"][0],
                       category=labeled_accounts[transaction["from"]]["category"])
            else:
                tx.run("""MERGE (t:Internal_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                          MERGE (a:Account {address:$from_address})
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"],
                       value=int(transaction["value"], 16) / 1e18,
                       block=transaction["blockNumber"],
                       timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       from_address=transaction["from"])
        if transaction["to"]:
            if transaction["to"] in labeled_accounts:
                tx.run("""
                        MATCH (t:Internal_Transaction {hash:$hash})
                        MERGE (a:Labeled_Account {address:$to_address})
                          SET a.label=$label
                          SET a.category=$category
                        MERGE (a)<-[:TO]-(t)
                        """,
                       hash=transaction["hash"],
                       to_address=transaction["to"],
                       label=labeled_accounts[transaction["to"]]["labels"][0],
                       category=labeled_accounts[transaction["to"]]["category"])
            else:
                tx.run("""
                        MATCH (t:Internal_Transaction {hash:$hash})
                        MERGE (a:Account {address:$to_address})
                        MERGE (a)<-[:TO]-(t)
                        """,
                       hash=transaction["hash"],
                       to_address=transaction["to"])

    @staticmethod
    def _save_token_transaction(tx, transaction, attacker, labeled_accounts):
        if transaction["from"] == attacker:
            if transaction["from"] in labeled_accounts:
                tx.run("""MERGE (t:Token_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                            SET t.token_name=$token_name
                            SET t.token_symbol=$token_symbol
                            SET t.token_decimal=$token_decimal
                          MERGE (a:Attacker {address:$from_address})
                            SET a.label=$label
                            SET a.category=$category
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"],
                       value=str(int(transaction["value"], 16) / int(10)**int(transaction["tokenDecimal"])),
                       block=transaction["blockNumber"],
                       timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       token_name=transaction["tokenName"],
                       token_symbol=transaction["tokenSymbol"],
                       token_decimal=transaction["tokenDecimal"],
                       from_address=transaction["from"],
                       label=labeled_accounts[transaction["from"]]["labels"][0],
                       category=labeled_accounts[transaction["from"]]["category"])
            else:
                tx.run("""MERGE (t:Token_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                            SET t.token_name=$token_name
                            SET t.token_symbol=$token_symbol
                            SET t.token_decimal=$token_decimal
                          MERGE (a:Attacker {address:$from_address})
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"],
                       value=str(int(transaction["value"], 16) / int(10)**int(transaction["tokenDecimal"])),
                       block=transaction["blockNumber"],
                       timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       token_name=transaction["tokenName"],
                       token_symbol=transaction["tokenSymbol"], token_decimal=transaction["tokenDecimal"],
                       from_address=transaction["from"])
        else:
            if transaction["from"] in labeled_accounts:
                tx.run("""MERGE (t:Token_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                            SET t.token_name=$token_name
                            SET t.token_symbol=$token_symbol
                            SET t.token_decimal=$token_decimal
                          MERGE (a:Labeled_Account {address:$from_address})
                            SET a.label=$label
                            SET a.category=$category
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"],
                       value=str(int(transaction["value"], 16) / int(10)**int(transaction["tokenDecimal"])),
                       block=transaction["blockNumber"],
                       timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       token_name=transaction["tokenName"],
                       token_symbol=transaction["tokenSymbol"],
                       token_decimal=transaction["tokenDecimal"],
                       from_address=transaction["from"],
                       label=labeled_accounts[transaction["from"]]["labels"][0],
                       category=labeled_accounts[transaction["from"]]["category"])
            else:
                tx.run("""MERGE (t:Token_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                            SET t.token_name=$token_name
                            SET t.token_symbol=$token_symbol
                            SET t.token_decimal=$token_decimal
                          MERGE (a:Account {address:$from_address})
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"],
                       value=str(int(transaction["value"], 16) / int(10)**int(transaction["tokenDecimal"])),
                       block=transaction["blockNumber"],
                       timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       token_name=transaction["tokenName"],
                       token_symbol=transaction["tokenSymbol"],
                       token_decimal=transaction["tokenDecimal"],
                       from_address=transaction["from"])
        if transaction["to"]:
            if transaction["to"] == attacker:
                if transaction["to"] in labeled_accounts:
                    tx.run("""
                            MATCH (t:Token_Transaction {hash:$hash})
                            MERGE (a:Attacker {address:$to_address})
                              SET a.label=$label
                              SET a.category=$category
                            MERGE (a)<-[:TO]-(t)
                            """,
                           hash=transaction["hash"],
                           to_address=transaction["to"],
                           label=labeled_accounts[transaction["to"]]["labels"][0],
                           category=labeled_accounts[transaction["to"]]["category"])
                else:
                    tx.run("""
                            MATCH (t:Token_Transaction {hash:$hash})
                            MERGE (a:Attacker {address:$to_address})
                            MERGE (a)<-[:TO]-(t)
                            """,
                           hash=transaction["hash"],
                           to_address=transaction["to"])
            else:
                if transaction["to"] in labeled_accounts:
                    tx.run("""
                            MATCH (t:Token_Transaction {hash:$hash})
                            MERGE (a:Labeled_Account {address:$to_address})
                              SET a.label=$label
                              SET a.category=$category
                            MERGE (a)<-[:TO]-(t)
                            """,
                           hash=transaction["hash"],
                           to_address=transaction["to"],
                           label=labeled_accounts[transaction["to"]]["labels"][0],
                           category=labeled_accounts[transaction["to"]]["category"])
                else:
                    tx.run("""
                            MATCH (t:Token_Transaction {hash:$hash})
                            MERGE (a:Account {address:$to_address})
                            MERGE (a)<-[:TO]-(t)
                            """,
                           hash=transaction["hash"],
                           to_address=transaction["to"])

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
    def _group_transactions_with_same_destination_together(transactions):
        aggregated_transactions = []
        to_addresses = []
        for i in range(len(transactions)):
            t1 = transactions[i]
            if t1["to"] not in to_addresses:
                for j in range(i, len(transactions)):
                    t2 = transactions[j]
                    if t1["from"] == t2["from"] and t1["to"] == t2["to"]:
                        t1["value"] = str(int(t1["value"]) + int(t2["value"]))
                aggregated_transactions.append(t1)
                to_addresses.append(t1["to"])
        return aggregated_transactions

    @staticmethod
    def _group_transactions_with_same_origin_together(transactions):
        aggregated_transactions = []
        to_addresses = []
        for i in range(len(transactions)):
            t1 = transactions[i]
            if t1["to"] not in to_addresses:
                for j in range(i, len(transactions)):
                    t2 = transactions[j]
                    if t1["from"] == t2["from"] and t1["to"] == t2["to"]:
                        t1["value"] = str(float(t1["value"]) + float(t2["value"]))
                aggregated_transactions.append(t1)
                to_addresses.append(t1["to"])
        return aggregated_transactions

    @staticmethod
    def _group_similar_tokens_together(transactions):
        aggregated_transactions = []
        to_addresses = []
        tokens = []
        for i in range(len(transactions)):
            t1 = transactions[i]
            if t1["to"] not in to_addresses or t1["tokenSymbol"] not in tokens:
                for j in range(i, len(transactions)):
                    t2 = transactions[j]
                    if t1["from"] == t2["from"] and t1["to"] == t2["to"] and t1["tokenSymbol"] == t2["tokenSymbol"]:
                        t1["value"] = str(int(t1["value"]) + int(t2["value"]))
                aggregated_transactions.append(t1)
                to_addresses.append(t1["to"])
                tokens.append(t1["tokenSymbol"])
        return aggregated_transactions

    @staticmethod
    def _remove_transactions_with_no_value(transactions, attacker):
        return [transaction for transaction in transactions if float(transaction["value"]) > 0 or transaction["from"] == attacker or transaction["to"] == attacker]

    @staticmethod
    def _filter_transactions_by_value(transactions, attacker, value):
        return [transaction for transaction in transactions if float(transaction["value"]) >= value]

    def _keep_only_token_transactions(transactions, token):
        return [transaction for transaction in transactions if transaction["tokenSymbol"] == token]

    def save_normal_transactions(self, transactions, attacker, labeled_accounts, direction):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    #print(len(transactions))
                    transactions = Neo4J._remove_transactions_with_no_value(transactions, attacker)
                    #transactions = Neo4J._group_transactions_with_same_destination_together(transactions)
                    transactions = Neo4J._group_transactions_together(transactions)
                    if direction == "forwards":
                        transactions = Neo4J._filter_transactions_by_value(transactions, attacker, 10000000000000000000) # 10ETH
                    for transaction in transactions:
                        Neo4J._save_normal_transaction(tx, transaction, attacker, labeled_accounts, direction)
                except ClientError as e:
                    print(e)

    def save_internal_transactions(self, transactions, attacker, labeled_accounts):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    transactions = Neo4J._remove_transactions_with_no_value(transactions)
                    transactions = Neo4J._group_transactions_with_same_destination_together(transactions)
                    for transaction in transactions:
                        Neo4J._save_internal_transaction(tx, transaction, attacker, labeled_accounts)
                except ClientError as e:
                    print(e)

    def save_token_transactions(self, transactions, attacker, labeled_accounts, token):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    transactions = Neo4J._remove_transactions_with_no_value(transactions)
                    transactions = Neo4J._group_similar_tokens_together(transactions)
                    transactions = Neo4J._keep_only_token_transactions(transactions, token)
                    for transaction in transactions:
                        Neo4J._save_token_transaction(tx, transaction, attacker, labeled_accounts)
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
