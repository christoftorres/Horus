#!/usr/bin/env python3
import json


def load_json(filepath):
    with open(filepath, "r") as f:
        return json.load(f)


def main():
    attempted_txs = load_json("attempted_txs.json")
    confirmed_ct_txs = load_json("confirmed_ct_txs.json")
    zero_day_cts = load_json("zero-day-cts.json")

    print("Statistic of Attempted Adversarial Transactions:")
    for attack_type, txs in attempted_txs.items():
        print("\t%s: %d transactions" % (attack_type, len(txs)))

    list_of_all_txs = set()

    print("Statistic of Confirmed Adversarial Transactions:")
    for attack_type, ct_txs in confirmed_ct_txs.items():
        all_txs = set()
        for ct, txs in ct_txs.items():
            all_txs.update(txs)
            if attack_type == "integer-overflow":
                print(txs)
        if attack_type == "call-injection" or attack_type == "reentrancy" or attack_type == "call-after-destruct" or attack_type == "integer-overflow":
            for ct, txs in ct_txs.items():
                list_of_all_txs.update(txs)
        print("\t%s: %d contracts with %d transactions" % (attack_type, len(ct_txs), len(all_txs)))

    print(len(list_of_all_txs))
    
    print("Statistic of 0-day Contracts:")
    for attack_type, cts in zero_day_cts.items():
        print("\t%s: %d contracts" % (attack_type, len(cts)))


if __name__ == "__main__":
    main()
