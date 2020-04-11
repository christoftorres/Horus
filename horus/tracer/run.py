
import json
import argparse

from tqdm import tqdm
from graph.Neo4J import Neo4J
from ethereum.etherscan import Etherscan

parser = argparse.ArgumentParser(description='Import Etherscan transactions into Neo4J')
parser.add_argument('--neo-address', type=str, dest='address', default="bolt://localhost:7687",
                    help='Connections string for the Neo4J server')
parser.add_argument('--neo-user', type=str, dest='user', default='neo4j', help='Neo4J Username')
parser.add_argument('--neo-password', type=str, dest='password', default='ethereum', help='Neo4J Password')
args = parser.parse_args()

etherscan = Etherscan(api_key='VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU')
graph = Neo4J(uri=args.address, user=args.user, password=args.password)
graph.delete_graph()

#attacker = '0x04786aada9deea2150deab7b3b8911c309f5ed90'
#attacker = '0x6a164122d5cf7c840d26e829b46dcc4ed6c0ae48'
#attacker = '0x91efffb9c6cd3a66474688d0a48aa6ecfe515aa5'
attacker = '0x0e64779930d9a5165dd712c06d11632c58ff8a4d'
hops = 5

with open('labeled_accounts.json') as json_file:
    labeled_accounts = json.load(json_file)

# Normal transactions
accounts = [attacker]
with tqdm(total=hops, unit=" hop", leave=False, smoothing=0.1) as pbar:
    for i in range(hops):
        for account in accounts:
            transactions = etherscan.get_normal_transactions(account)
            transactions = [transaction for transaction in transactions if transaction["from"] == account]
            if len(transactions) <= 100:
                graph.save_normal_transactions(transactions, attacker, labeled_accounts)
            accounts = []
            for transaction in transactions:
                if transaction["to"] and transaction["to"] not in accounts:
                    accounts.append(transaction["to"])
            if len(accounts) > 100:
                accounts = []
        pbar.update(1)

# Internal transactions
accounts = [attacker]
with tqdm(total=hops, unit=" hop", leave=False, smoothing=0.1) as pbar:
    for i in range(hops):
        for account in accounts:
            transactions = etherscan.get_internal_transactions(account)
            transactions = [transaction for transaction in transactions if transaction["from"] == account]
            if len(transactions) <= 100:
                graph.save_internal_transactions(transactions, attacker, labeled_accounts)
            accounts = []
            for transaction in transactions:
                if transaction["to"] and transaction["to"] not in accounts:
                    accounts.append(transaction["to"])
            if len(accounts) > 100:
                accounts = []
        pbar.update(1)

# Token transactions
accounts = [attacker]
with tqdm(total=hops, unit=" hop", leave=False, smoothing=0.1) as pbar:
    for i in range(hops):
        for account in accounts:
            transactions = etherscan.get_token_transactions(account)
            #transactions = [transaction for transaction in transactions if transaction["from"] == account]
            if len(transactions) <= 100:
                graph.save_token_transactions(transactions, attacker, labeled_accounts)
            accounts = []
            for transaction in transactions:
                if transaction["to"] and transaction["to"] not in accounts:
                    accounts.append(transaction["to"])
            if len(accounts) > 100:
                accounts = []
        pbar.update(1)
