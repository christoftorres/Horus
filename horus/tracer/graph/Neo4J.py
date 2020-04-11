
from datetime import datetime

from neo4j.exceptions import ClientError
from neo4j.v1 import GraphDatabase

class Neo4J:
    def __init__(self, uri, user, password):
        self._driver = GraphDatabase.driver(uri, auth=(user, password), max_retry_time=1, encrypted=False)

    def close(self):
        self._driver.close()

    @staticmethod
    def _save_transaction(tx, transaction, attacker, labeled_accounts):
        if transaction["from"] == attacker:
            if transaction["from"] in labeled_accounts:
                tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                          MERGE (a:Attacker {address:$from_address})
                            SET a.label=$label
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"], value=int(transaction["value"], 16) / 1e18,
                       block=transaction["blockNumber"], timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       from_address=transaction["from"], label=labeled_accounts[transaction["from"]][0])
            else:
                tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                          MERGE (a:Attacker {address:$from_address})
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"], value=int(transaction["value"], 16) / 1e18,
                       block=transaction["blockNumber"], timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       from_address=transaction["from"])
        else:
            if transaction["from"] in labeled_accounts:
                tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                          MERGE (a:Labeled_Account {address:$from_address})
                            SET a.label=$label
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"], value=int(transaction["value"], 16) / 1e18,
                       block=transaction["blockNumber"], timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       from_address=transaction["from"], label=labeled_accounts[transaction["from"]][0])
            else:
                tx.run("""MERGE (t:Normal_Transaction {hash:$hash})
                            SET t.value=$value
                            SET t.block=$block
                            SET t.timestamp=$timestamp
                          MERGE (a:Account {address:$from_address})
                          MERGE (a)-[:FROM]->(t)""",
                       hash=transaction["hash"], value=int(transaction["value"], 16) / 1e18,
                       block=transaction["blockNumber"], timestamp=datetime.fromtimestamp(int(transaction["timeStamp"])),
                       from_address=transaction["from"])
        if transaction["to"]:
            if transaction["to"] in labeled_accounts:
                tx.run("""
                        MATCH (t:Normal_Transaction {hash:$hash})
                        MERGE (a:Labeled_Account {address:$to_address})
                          SET a.label=$label
                        MERGE (a)<-[:TO]-(t)
                        """,
                       hash=transaction["hash"], to_address=transaction["to"], label=labeled_accounts[transaction["to"]][0])
            else:
                tx.run("""
                        MATCH (t:Normal_Transaction {hash:$hash})
                        MERGE (a:Account {address:$to_address})
                        MERGE (a)<-[:TO]-(t)
                        """,
                       hash=transaction["hash"], to_address=transaction["to"])

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

    def save_transactions(self, transactions, attacker, labeled_accounts):
        with self._driver.session() as session:
            with session.begin_transaction() as tx:
                try:
                    for transaction in transactions:
                        Neo4J._save_transaction(tx, transaction, attacker, labeled_accounts)
                except ClientError as e:
                    print(e)
