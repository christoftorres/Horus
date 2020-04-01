#!/usr/bin/env bash

#nohup python3 ethereum-etl-1.3.0/ethereumetl.py extract_csv_column --input /home/cool/chain_data/transactions.csv --column hash --output /home/cool/chain_data/transaction_hashes.txt &> extract_csv_column.log&

nohup python3 ethereum-etl-1.3.0/ethereumetl.py export_receipts_and_logs --batch-size 100000 --max-workers 20 --transaction-hashes /home/cool/chain_data/transaction_hashes.txt --provider-uri file:///home/cool/chain_data/geth/geth.ipc --receipts-output /home/cool/chain_data/receipts.csv &> export_receipts.log&
