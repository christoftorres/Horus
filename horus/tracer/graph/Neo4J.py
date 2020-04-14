
from datetime import datetime

from neo4j.exceptions import ClientError
from neo4j.v1 import GraphDatabase

class Neo4J:
    def __init__(self, uri, user, password):
        self._driver = GraphDatabase.driver(uri, auth=(user, password), max_retry_time=1, encrypted=False)

    def close(self):
        self._driver.close()

    @staticmethod
    def _save_normal_transaction(tx, transaction, attacker, labeled_accounts):
        if transaction["from"] == attacker:
            if transaction["from"] in labeled_accounts:
                tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
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
                tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
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
                tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
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
                tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
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
                if transaction["to"] == attacker:
                    tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
                              MERGE (a:Attacker {address:$to_address})
                                SET a.label=$label
                                SET a.category=$category
                              MERGE (a)<-[:TO]-(t)""",
                           hash=transaction["hash"],
                           to_address=transaction["to"],
                           label=labeled_accounts[transaction["to"]]["labels"][0],
                           category=labeled_accounts[transaction["to"]]["category"])
                else:
                    tx.run("""
                            MATCH (t:Normal_Transaction {hash:$hash})
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
                        MATCH (t:Normal_Transaction {hash:$hash})
                        MERGE (a:Account {address:$to_address})
                        MERGE (a)<-[:TO]-(t)
                        """,
                       hash=transaction["hash"],
                       to_address=transaction["to"])

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
                        t1["value"] = str(int(t1["value"]) + int(t2["value"]))
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
    def _remove_transactions_with_no_value(transactions):
        return [transaction for transaction in transactions if int(transaction["value"]) > 0]

    def _keep_only_token_transactions(transactions, token):
        return [transaction for transaction in transactions if transaction["tokenSymbol"] == token]

    def save_normal_transactions(self, transactions, attacker, labeled_accounts):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    print(len(transactions))
                    transactions = Neo4J._remove_transactions_with_no_value(transactions)
                    print(len(transactions))
                    #transactions = Neo4J._group_transactions_with_same_destination_together(transactions)
                    print(len(transactions))
                    for transaction in transactions:
                        Neo4J._save_normal_transaction(tx, transaction, attacker, labeled_accounts)
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
