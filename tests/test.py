#!/usr/bin/env python3.8
# -*- coding: utf-8 -*-

import os
import csv
import time
import shlex
import shutil
import subprocess

if __name__ == '__main__':
    print("")
    print("                Testing Horus")
    FNULL = open(os.devnull, 'w')
    start = time.time()
    print("=======================================================")

    print("Testing 'DAO'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x0ec3f2488a93839524add10ea229e773f6bc891b4eb4794c3337d4495263790b"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") != 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") != 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'SpankChain'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x21e9d20b57f6ae60dac23466c8395d47f42dc24628e5a31f224567a2b4effa88"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") != 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") != 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") != 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") != 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'SimpleDAO'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x0c2eb9a602a0b6493a67784534f066c20895fd5b8dc4ecd495520888ce4ff92e --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") != 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") != 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Cross-Function Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x73af82a5b067495a368a0c3e2b96936cc18680ca07fe11df41ea8a3865e08353 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") != 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Unconditional Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xebeabdcfbe897a78baba0d0720b7d208c2472d36f06669bdb5b319715bc0b7f5"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") != 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Delegated Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xeec548c6f235e191440954ac32d2d20c90c482271a76bdf2545d9513a3a46f83 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") != 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") != 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") != 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Create-Based Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x69feed59fadaedc67f1ba9d09f720ecc74470f77a0f89fa5f9842b32990034f0 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") != 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'NoLock + SameFunction Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x02593d40eb1b13ce35b3f43bd4af743fd75c041cafb70ac5e3c94e77e08b4591 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") != 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'NoLock + CrossFunction Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xaacf700ba687888f9796bb33ec3bf80380acae5941aa861d471444fecf766fc6 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") != 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'BuggyLock + SameFunction Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x63b07a8fc9aa635cc04b450497f9dcd76059b175b84f549a420a0374b0494e01 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'BuggyLock + CrossFunction Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x1aaaa0ee72ec14cf86ba4273a415e88498293dffe51b8883bf8ebd24e6066de0 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") != 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'SecureLock + SameFunction Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xcd03355bfdf1650c846c200741b94d1f7d0af1450ebf72c8e0156f5ee1aabf59 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'SecureLock + CrossFunction Reentrancy'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xa735288c921e987c6b3cf94cdef03d8c31284ace1583a16f6a887efab22c4f49 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'ERC777 Reentrancy Uniswap'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x9cb1d93d6859883361e8c2f9941f13d6156a1e8daa0ebe801b5d0b5a612723c1"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") != 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") != 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") != 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'ERC777 Reentrancy Lendf.Me'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xae7d664bdfcc54220df4f18d339005c6faf6e62c9ca79c56387bc0389274363b"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") != 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Parity Wallet Hack 1'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -c 0x91efffb9c6cd3a66474688d0a48aa6ecfe515aa5"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") != 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") != 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Parity Wallet Hack 2'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -c 0x863df6bfa4469f3ead0be8f9f2aae51c91a907b4"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") != 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Integer Overflow Multiplication'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xad89ff16fd1ebe3a0a7cf4ed282302c06626c1af33221ebe0d3a470aba4a660f"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") != 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Integer Overflow Addition 1'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x1abab4c8db9a30e703114528e31dee129a3a758f7f8abc3b6494aad3d304e43f"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") != 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Integer Overflow Addition 2'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xa850ce29dac8cefd0cf3250486a8080ca32b0a94308b9ac3ac6639140e601344"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") != 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Integer Underflow Subtraction'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xf1d416a865f152ce4680ca89c33cb84aeff38abcc0d6708b9e2a1b6029e57537"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") != 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Unchecked Send Bug'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x6d41b1d3e9b01efc0cc63b5c7ee162bccffe5af00fba3940850b09bfcbee0c9e"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") != 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'DoS with Unexpected Throw'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x90f1c2c5ff8188c27d1c5fe3cbf0472b7b0e30c415d5d37e02081b4fc150bd7b --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") != 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'DoS with Block Gas Limit'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x7536bd057e8de69f462af9922f5654f1c7e640d335a4ed7be9a4e0dfdeed75a5"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") != 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Transaction State Dependence'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x3e41b625a29b59957831426c3f175df45b2c692b08ec8d19a1d327d0a0fea93c --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") != 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Transaction Order Dependence'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -c 0xf90a54b20881ece27e3a8e31903e3e75009a0164"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") != 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Timestamp Dependence'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x0d80d67202bd9cb6773df8dd2020e7190a1b0793e8ec4fc105257e8128f0506b"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") != 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Block State Dependence'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0xc762c8699242e501100e1eafeee95347c686a6ee2a0e55c264e3588f8df966cc"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") != 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Short Address'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x06d83a7acf2b683323cc6900365e8515ee39e669d8c8f51d5183cc99a2382203 --port 8546"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") != 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Call Stack Depth'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x0c10fafe0cdbfff32abfe53d57ec861d09986cc1050c850481f79b1a862bb10a"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") != 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") != 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Unchecked Signature'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t 0x9008d8ca9a5993d060e0dc2ee7d281b7911d1b39ac3503ba3b8ec22f26d8e04f"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") == 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") != 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))
    print("-------------------------------------------------------")
    shutil.rmtree('facts')
    shutil.rmtree('results')

    print("Testing 'Block Stuffing'")
    extraction_start = time.time()
    p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -b 6391547"), stdout=subprocess.PIPE, stderr=FNULL)
    output = str(p.communicate()[0])
    extraction_end = time.time()
    if "Traceback" in output or "error" in output:
        print("\033[91m!!! FAILED !!!\033[0m")
    else:
        analysis_start = time.time()
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        analysis_end = time.time()
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! FAILED !!!\033[0m")
        else:
            if os.path.getsize("results/BalanceInvariant.csv") == 0 and \
               os.path.getsize("results/BlockStateDependence.csv") == 0 and \
               os.path.getsize("results/BlockStuffing.csv") != 0 and \
               os.path.getsize("results/CallStackDepth.csv") == 0 and \
               os.path.getsize("results/CreateBasedReentrancy.csv") == 0 and \
               os.path.getsize("results/CrossFunctionReentrancy.csv") == 0 and \
               os.path.getsize("results/DelegatedReentrancy.csv") == 0 and \
               os.path.getsize("results/DoSWithBlockGasLimit.csv") == 0 and \
               os.path.getsize("results/DoSWithUnexpectedThrow.csv") == 0 and \
               os.path.getsize("results/ERC777Reentrancy.csv") == 0 and \
               os.path.getsize("results/InsufficientGas.csv") == 0 and \
               os.path.getsize("results/IntegerOverflow.csv") == 0 and \
               os.path.getsize("results/IntegerUnderflow.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack1.csv") == 0 and \
               os.path.getsize("results/ParityWalletHack2.csv") == 0 and \
               os.path.getsize("results/Reentrancy.csv") == 0 and \
               os.path.getsize("results/ShortAddress.csv") == 0 and \
               os.path.getsize("results/TimestampDependence.csv") == 0 and \
               os.path.getsize("results/TransactionOrderDependency.csv") == 0 and \
               os.path.getsize("results/TransactionStateDependence.csv") == 0 and \
               os.path.getsize("results/UncheckedDelegatecall.csv") == 0 and \
               os.path.getsize("results/UncheckedSignature.csv") == 0 and \
               os.path.getsize("results/UncheckedSuicide.csv") == 0 and \
               os.path.getsize("results/UnhandledException.csv") == 0:
                print("\033[92mPASSED\033[0m")
            else:
                print("\033[91m!!! FAILED !!!\033[0m")
        print("Extraction time: "+str(extraction_end-extraction_start))
        print("Analysis time: "+str(analysis_end-analysis_start))

    print("=======================================================")
    end = time.time()
    shutil.rmtree('facts')
    shutil.rmtree('results')
    print("Finished testing.")
    print("Testing took "+str(end - start)+" seconds.")
