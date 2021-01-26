### Tests

###### Reentrancy

```
DAO

python3 horus.py -e -tx 0x0ec3f2488a93839524add10ea229e773f6bc891b4eb4794c3337d4495263790b
```

```
SpankChain 

python3 horus.py -e -tx 0x21e9d20b57f6ae60dac23466c8395d47f42dc24628e5a31f224567a2b4effa88
```

```
Unconditional Reentrancy

python3 horus.py -e -tx 0xebeabdcfbe897a78baba0d0720b7d208c2472d36f06669bdb5b319715bc0b7f5
```

```
Uniswap

python3 horus.py -e -tx 0x9437dde6c06a20f6d56f69b07f43d5fb918e6c57c97e1fc25a4162c693f578aa
```

```
Lendf.Me

python3 horus.py -e -tx 0xe49304cd3edccf32069dcbbb5df7ac3b8678daad34d0ad1927aa725a8966d52a
```

###### Parity Wallet Hacks

```
Parity Wallet Hack 1 (19.07.2017)

python3 horus.py -e -c 0x91efffb9c6cd3a66474688d0a48aa6ecfe515aa5

python3 horus.py -e -c 0xbec591de75b8699a3ba52f073428822d0bfc0d7e
```

```
Parity Wallet Hack 2 (06.11.2017)

python3 horus.py -e -c 0x863df6bfa4469f3ead0be8f9f2aae51c91a907b4
```

###### Integer Overflows

```
Multiplication

python3 horus.py -e -tx 0xad89ff16fd1ebe3a0a7cf4ed282302c06626c1af33221ebe0d3a470aba4a660f
```

```
Addition

python3 horus.py -e -tx 0x1abab4c8db9a30e703114528e31dee129a3a758f7f8abc3b6494aad3d304e43f

python3 horus.py -e -tx 0xa850ce29dac8cefd0cf3250486a8080ca32b0a94308b9ac3ac6639140e601344
```

```
Subtraction

python3 horus.py -e -tx 0xf1d416a865f152ce4680ca89c33cb84aeff38abcc0d6708b9e2a1b6029e57537
```

###### Unhandled Exception

```
King of the Ether

python3 horus.py -e -tx 0x6d41b1d3e9b01efc0cc63b5c7ee162bccffe5af00fba3940850b09bfcbee0c9e
```

###### Short Address

```
Short Address

python3 horus.py -e -tx 0x7c3fc0b33196a57a0b145054e9a34237b27a615348cd1904d0b7fe78772b3913
```
