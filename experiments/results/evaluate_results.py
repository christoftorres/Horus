#!/usr/bin/python
# -*- coding: utf-8 -*-

import json

if __name__ == '__main__':

    total_contracts = dict()
    total_transactions = dict()

    contracts = dict()
    transactions = dict()
    with open('reentrancy.json', 'r') as fp:
        results = json.load(fp)
        for contract in results:
            for transaction in results[contract]:
                transactions[transaction] = True
                total_transactions[transaction] = True
            contracts[contract] = True
            total_contracts[contract] = True
    print("Reentrancy contracts: "+str(len(contracts)))
    print("Reentrancy transactions: "+str(len(transactions)))
    print()

    parity_contracts = dict()
    parity_transactions = dict()

    contracts = 0
    transactions = 0
    with open('parity_wallet_hack_1.json', 'r') as fp:
        results = json.load(fp)
        for contract in results:
            contracts += 1
            for transaction in results[contract]:
                transactions += 1
                total_transactions[transaction] = True
                parity_transactions[transaction] = True
            total_contracts[contract] = True
            parity_contracts[contract] = True
    print("Parity_wallet_hack_1 contracts: "+str(contracts))
    print("Parity_wallet_hack_1 transactions: "+str(transactions))

    contracts = 0
    transactions = 0
    with open('parity_wallet_hack_2.json', 'r') as fp:
        results = json.load(fp)
        for contract in results:
            contracts += 1
            for transaction in results[contract]:
                transactions += 1
                total_transactions[transaction] = True
                parity_transactions[transaction] = True
            total_contracts[contract] = True
            parity_contracts[contract] = True
    print("Parity wallet hack 2 contracts: "+str(contracts))
    print("Parity wallet hack 2 transactions: "+str(transactions))

    print("Parity wallet hack contracts: "+str(len(parity_contracts)))
    print("Parity wallet hack transactions: "+str(len(parity_transactions)))
    print()

    contracts = dict()
    transactions = dict()
    with open('integer_overflow.json', 'r') as fp:
        results = json.load(fp)
        for contract in results:
            for transaction in results[contract]:
                transactions[transaction] = True
                total_transactions[transaction] = True
            contracts[contract] = True
            total_contracts[contract] = True
    print("Integer overflow contracts: "+str(len(contracts)))
    print("Integer overflow transactions: "+str(len(transactions)))
    print()

    contracts = 0
    transactions = 0
    with open('unhandled_exception.json', 'r') as fp:
        results = json.load(fp)
        for contract in results:
            contracts += 1
            for transaction in results[contract]:
                transactions += 1
                total_transactions[transaction] = True
            total_contracts[contract] = True
    print("Unhandled exception contracts: "+str(contracts))
    print("Unhandled exception transactions: "+str(transactions))
    print()

    contracts = 0
    transactions = 0
    with open('short_address.json', 'r') as fp:
        results = json.load(fp)
        for contract in results:
            contracts += 1
            for transaction in results[contract]:
                transactions += 1
                total_transactions[transaction] = True
            total_contracts[contract] = True
    print("Short address contracts: "+str(contracts))
    print("Short address transactions: "+str(transactions))
    print()

    print("Total unique contracts: "+str(len(total_contracts)))
    print("Total unique transactions: "+str(len(total_transactions)))
