### Tests

###### Reentrancy

```
DAO (Mainnet)

python3 horus.py -e -t 0x0ec3f2488a93839524add10ea229e773f6bc891b4eb4794c3337d4495263790b
```

```
SpankChain (Mainnet)

python3 horus.py -e -t 0x21e9d20b57f6ae60dac23466c8395d47f42dc24628e5a31f224567a2b4effa88
```

```
SimpleDAO (Ropsten)

python3 horus.py -e -t 0x0c2eb9a602a0b6493a67784534f066c20895fd5b8dc4ecd495520888ce4ff92e
```

```
Cross-Function Reentrancy (Ropsten)

python3 horus.py -e -t 0x73af82a5b067495a368a0c3e2b96936cc18680ca07fe11df41ea8a3865e08353
```

```
Unconditional Reentrancy (Mainnet)

python3 horus.py -e -t 0xebeabdcfbe897a78baba0d0720b7d208c2472d36f06669bdb5b319715bc0b7f5
```

```
Delegated Reentrancy (Ropsten)

python3 horus.py -e -t 0xeec548c6f235e191440954ac32d2d20c90c482271a76bdf2545d9513a3a46f83
```

```
Create-Based Reentrancy (Ropsten)

python3 horus.py -e -t 0x69feed59fadaedc67f1ba9d09f720ecc74470f77a0f89fa5f9842b32990034f0
```

```
NoLock + SameFunction Reentrancy  (Ropsten)

python3 horus.py -e -t 0x02593d40eb1b13ce35b3f43bd4af743fd75c041cafb70ac5e3c94e77e08b4591
```

```
NoLock + CrossFunction Reentrancy (Ropsten)

python3 horus.py -e -t 0xaacf700ba687888f9796bb33ec3bf80380acae5941aa861d471444fecf766fc6
```

```
BuggyLock + SameFunction Reentrancy (Ropsten)

python3 horus.py -e -t 0x63b07a8fc9aa635cc04b450497f9dcd76059b175b84f549a420a0374b0494e01
```

```
BuggyLock + CrossFunction Reentrancy (Ropsten)

python3 horus.py -e -t 0x1aaaa0ee72ec14cf86ba4273a415e88498293dffe51b8883bf8ebd24e6066de0
```

```
SecureLock + SameFunction Reentrancy (Ropsten)

python3 horus.py -e -t  0xcd03355bfdf1650c846c200741b94d1f7d0af1450ebf72c8e0156f5ee1aabf59
```

```
SecureLock + CrossFunction Reentrancy (Ropsten)

python3 horus.py -e -t 0xa735288c921e987c6b3cf94cdef03d8c31284ace1583a16f6a887efab22c4f49
```

###### Unchecked Delegatecall (Parity Wallet Hack 1 - 19.07.2017)

```
ParityWallet (Mainnet)

python3 horus.py  -e -c 0x91efffb9c6cd3a66474688d0a48aa6ecfe515aa5

python3 horus.py  -e -c 0xbec591de75b8699a3ba52f073428822d0bfc0d7e
```
###### Unchecked Suicide (Parity Wallet Hack 2 - 06.11.2017)

```
ParityWallet (Mainnet)

python3 horus.py -e -c 0x863df6bfa4469f3ead0be8f9f2aae51c91a907b4
```

###### Integer Overflows

```
Multiplication (Mainnet)

python3 horus.py -e -t 0xad89ff16fd1ebe3a0a7cf4ed282302c06626c1af33221ebe0d3a470aba4a660f
```

```
Addition (Mainnet)

python3 horus.py -e -t 0x1abab4c8db9a30e703114528e31dee129a3a758f7f8abc3b6494aad3d304e43f

python3 horus.py -e -t 0xa850ce29dac8cefd0cf3250486a8080ca32b0a94308b9ac3ac6639140e601344
```

###### Integer Underflows

```
Subtraction (Mainnet)

python3 horus.py -e -t 0xf1d416a865f152ce4680ca89c33cb84aeff38abcc0d6708b9e2a1b6029e57537
```

###### Unchecked Send Bug

```
King of the Ether (Mainnet)

python3 horus.py -e -t 0x6d41b1d3e9b01efc0cc63b5c7ee162bccffe5af00fba3940850b09bfcbee0c9e
```

###### DoS with Unexpected Throw

```
PresidentOfTheEther (Ropsten)

python3 horus.py -e -t 0x90f1c2c5ff8188c27d1c5fe3cbf0472b7b0e30c415d5d37e02081b4fc150bd7b
```

###### DoS with Block Gas Limit

```
GovernMental (Mainnet)

python3 horus.py -e -t 0x7536bd057e8de69f462af9922f5654f1c7e640d335a4ed7be9a4e0dfdeed75a5
```

###### Transaction State Dependence

```
TxUserWallet (Ropsten)

python3 horus.py -e -t 0x3e41b625a29b59957831426c3f175df45b2c692b08ec8d19a1d327d0a0fea93c
```

###### Transaction Order Dependence (TOD)

```
Bancor (Mainnet)

python3 horus.py -e -c 0xf90a54b20881ece27e3a8e31903e3e75009a0164
```

###### Timestamp Dependence

```
GovernMental (Mainnet)

python3 horus.py -e -t 0x8995a4334fc1e811afcfe257b82a4eae329bda7347d09fff6b7873a7e2a63036
```

###### Short Address

```
Short Address (Ropsten)

python3 horus.py -e -t 0x06d83a7acf2b683323cc6900365e8515ee39e669d8c8f51d5183cc99a2382203
```

###### Call Stack Depth

```
Call Stack Depth (Mainnet)

python3 horus.py -e -t 0x0c10fafe0cdbfff32abfe53d57ec861d09986cc1050c850481f79b1a862bb10a
```

###### Unchecked Signature

```
Call Stack Depth (Mainnet)

python3 horus.py -e -t 0x9008d8ca9a5993d060e0dc2ee7d281b7911d1b39ac3503ba3b8ec22f26d8e04f
```
