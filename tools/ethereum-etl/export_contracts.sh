#!/usr/bin/env bash

#nohup python3 ethereum-etl-1.3.0/ethereumetl.py extract_csv_column --input /home/cool/chain_data/receipts.csv --column contract_address --output /home/cool/chain_data/contract_addresses.txt &> export_contracts.log&

nohup python3 ethereum-etl-1.3.0/ethereumetl.py export_contracts --contract-addresses /home/cool/chain_data/horus/contract_addresses.txt --provider-uri file:///home/cool/chain_data/geth/geth.ipc --output /home/cool/chain_data/horus/contracts.csv &> export_contracts.log&
