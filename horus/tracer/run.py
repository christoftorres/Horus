
import csv
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

#attacker = '0x04786aada9deea2150deab7b3b8911c309f5ed90'
#attacker = '0x6a164122d5cf7c840d26e829b46dcc4ed6c0ae48'
#attacker = '0xda12f365ec4b2a8d19b8b46b63a54c8fc60915b5'
#attacker = '0xd6a09bdb29e1eafa92a30373c44b09e2e2e0651e'
#attacker = '0x0e64779930d9a5165dd712c06d11632c58ff8a4d'
#attacker = '0xb4d30cac5124b46c2df0cf3e3e1be05f42119033'
#attacker = '0x0e823ffe018727585eaf5bc769fa80472f76c3d7'

#attacker = '0xbd2250d713bf98b7e00c26e2907370ad30f0891a'
attacker = '0x60f3fdb85b2f7faaa888ca7afc382c57f6415a81'

block_number = 9892565

hops = 6
#token = "RMC"
#token = "SMT"
#token = "mesh"
#token = "BEC"
max_transactions = 10000

labeled_accounts = etherscan.get_labels()
offset = 10000

# Normal transactions
def load_normal_transactions(account, hops, hop=1, start_block=0, visited_accounts=[], direction="forwards"):
    if hop <= hops and account not in visited_accounts:
        visited_accounts.append(account)
        transactions = etherscan.get_normal_transactions(account, start_block=start_block, offset=offset)
        spaces = ""
        for _ in range(hop-1):
            spaces += "  "
        print("-> "+spaces+account+" "+str(hop)+" hops "+str(len(transactions))+" transactions")
        if   direction == "forwards":
            transactions = [transaction for transaction in transactions if transaction["from"] == account and transaction["to"] != "" and float(transaction["value"]) >= 10000000000000000000 and int(transaction["blockNumber"]) >= block_number]
        elif direction == "backwards":
            transactions = [transaction for transaction in transactions if transaction["to"] == account and int(transaction["blockNumber"]) <= block_number]
        if len(transactions) <= max_transactions:
            graph.save_normal_transactions(transactions, attacker, labeled_accounts, direction)
            for transaction in transactions:
                if direction == "forwards":
                    load_normal_transactions(transaction["to"], hops, hop+1, start_block, visited_accounts, direction)
                elif direction == "backwards":
                    load_normal_transactions(transaction["from"], hops, hop+1, start_block, visited_accounts, direction)

# Internal transactions
"""def load_internal_transactions(account, hops, hop=1, visited_accounts=[]):
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
def load_token_transactions(account, hops, hop=1, start_block=0, visited_accounts=[], direction="forwards"):
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
            load_token_transactions(account, hops, hop+1, start_block, visited_accounts, direction)"""

count = 0
start = time.time()
"""with open('/Users/christof.torres/Git/Horus/tools/attackers.csv') as csv_file:
    csv_file.readline()
    reader = csv.reader(csv_file, delimiter=',')
    for row in reader:
        attacker = row[0]
        start_block = etherscan.get_block_number_by_timestamp(row[1], closest="after")
        load_normal_transactions(attacker, hops, start_block=start_block, direction="forwards")
        count += 1
        if count == 10:
            break"""
#print("Analyzing normal transactions backwards...")
#load_normal_transactions(attacker, 5, visited_accounts=[], direction="backwards")

print("Analyzing normal transactions forwards...")
load_normal_transactions(attacker, 5, visited_accounts=[], direction="forwards")

"""print("Analyzing internal transactions...")
load_internal_transactions(attacker, hops)"""
#print("Analyzing token transactions...")
#load_token_transactions(attacker, hops, direction="backwards")
end = time.time()
print("Execution time: "+str(end - start))

result = graph.run_cypher_query("MATCH p=shortestPath((attacker:Attacker)-[:NORMAL_TRANSACTION*]-(exchange:Labeled_Account {category:'Exchange'})) RETURN *")
print(result)
for record in result:
    print(record)
    #print(record["attacker"]["address"])
    #print(record["exchange"]["address"])
    #print(record["exchange"]["category"])
    #print(record["exchange"]["label"])
