#!/usr/bin/env bash

nohup python3 ethereum-etl-1.3.0/ethereumetl.py export_blocks_and_transactions --start-block 0 --end-block 9500000 --provider-uri file:///home/cool/chain_data/geth/geth.ipc --blocks-output /home/cool/chain_data/blocks.csv --transactions-output /home/cool/chain_data/transactions.csv &> export.log&
