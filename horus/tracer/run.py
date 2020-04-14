
import json
import time
import argparse

from graph.Neo4J import Neo4J
from ethereum.etherscan import Etherscan

parser = argparse.ArgumentParser(description='Import Etherscan transactions into Neo4J')
parser.add_argument('--neo-address', type=str, dest='address', default="bolt://localhost:7687",
                    help='Connections string for the Neo4J server')
parser.add_argument('--neo-user', type=str, dest='user', default='neo4j', help='Neo4J Username')
parser.add_argument('--neo-password', type=str, dest='password', default='ethereum', help='Neo4J Password')
args = parser.parse_args()

etherscan = Etherscan(api_key='VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU', session_cookie='3zd0i5lcokvpjl20bpkon3rk')

graph = Neo4J(uri=args.address, user=args.user, password=args.password)
graph.delete_graph()

attacker = '0x04786aada9deea2150deab7b3b8911c309f5ed90'
#attacker = '0x6a164122d5cf7c840d26e829b46dcc4ed6c0ae48'
attacker = '0xda12f365ec4b2a8d19b8b46b63a54c8fc60915b5'
#attacker = '0xd6a09bdb29e1eafa92a30373c44b09e2e2e0651e'
#attacker = '0x0e64779930d9a5165dd712c06d11632c58ff8a4d'
#attacker = '0xb4d30cac5124b46c2df0cf3e3e1be05f42119033'
#attacker = '0x0e823ffe018727585eaf5bc769fa80472f76c3d7'

hops = 4
token = "RMC"
#token = "SMT"
#token = "mesh"
#token = "BEC"

labeled_accounts = etherscan.get_labels()

# Normal transactions
def load_normal_transactions(account, hops, hop=1, visited_accounts=[], direction="forwards"):
    if hop <= hops and account not in visited_accounts:
        visited_accounts.append(account)
        transactions = etherscan.get_normal_transactions(account)
        print(account+" "+str(hop)+" "+str(len(transactions)))
        if   direction == "forwards":
            transactions = [transaction for transaction in transactions if transaction["from"] == account]
        elif direction == "backwards":
            transactions = [transaction for transaction in transactions if transaction["to"] == account]
        if len(transactions) <= 100:
            graph.save_normal_transactions(transactions, attacker, labeled_accounts)
        accounts = []
        for transaction in transactions:
            if direction == "forwards":
                if transaction["to"] and transaction["to"] not in accounts:
                    accounts.append(transaction["to"])
            elif direction == "backwards":
                if transaction["from"] and transaction["from"] not in accounts:
                    accounts.append(transaction["from"])
        if len(accounts) > 100:
            accounts = []
        for to_account in accounts:
            load_normal_transactions(to_account, hops, hop+1, visited_accounts, direction)

# Internal transactions
def load_internal_transactions(account, hops, hop=1, visited_accounts=[]):
    if hop <= hops and account not in visited_accounts:
        visited_accounts.append(account)
        transactions = etherscan.get_internal_transactions(account)
        print(account+" "+str(hop)+" "+str(len(transactions)))
        transactions = [transaction for transaction in transactions if transaction["from"] == account]
        if len(transactions) <= 100:
            graph.save_internal_transactions(transactions, attacker, labeled_accounts)
        accounts = []
        for transaction in transactions:
            if transaction["to"] and transaction["to"] not in accounts:
                accounts.append(transaction["to"])
        if len(accounts) > 100:
            accounts = []
        for account in accounts:
            load_internal_transactions(account, hops, hop+1, visited_accounts)

# Token transactions
def load_token_transactions(account, hops, hop=1, visited_accounts=[], direction="forwards"):
    if hop <= hops and account not in visited_accounts:
        visited_accounts.append(account)
        transactions = etherscan.get_token_transactions(account)
        print(account+" "+str(hop)+" "+str(len(transactions)))
        if   direction == "forwards":
            transactions = [transaction for transaction in transactions if transaction["from"] == account]
        elif direction == "backwards":
            transactions = [transaction for transaction in transactions if transaction["to"] == account]
        if len(transactions) <= 100:
            graph.save_token_transactions(transactions, attacker, labeled_accounts, token)
        accounts = []
        for transaction in transactions:
            if   direction == "forwards":
                if transaction["to"] and transaction["to"] not in accounts and transaction["tokenSymbol"] == token:
                    accounts.append(transaction["to"])
            elif direction == "backwards":
                if transaction["from"] and transaction["from"] not in accounts and transaction["tokenSymbol"] == token:
                    accounts.append(transaction["from"])
        if len(accounts) > 100:
            accounts = []
        for account in accounts:
            load_token_transactions(account, hops, hop+1, visited_accounts, direction)

start = time.time()
print("Analyzing normal transactions...")
load_normal_transactions(attacker, hops, direction="backwards")
"""print("Analyzing internal transactions...")
load_internal_transactions(attacker, hops)"""
print("Analyzing token transactions...")
load_token_transactions(attacker, hops, direction="backwards")
end = time.time()
print("Execution time: "+str(end - start))
