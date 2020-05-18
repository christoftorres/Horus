#!/usr/bin/env python3.8
# -*- coding: utf-8 -*-

import os
import csv
import time
import shlex
import shutil
import subprocess

true_positives = [
    '0x8d8404d056607815c04dd286858da123c6e6aea29a1197e21a803fa67ebedd7c',
    '0x737599144d090bb3057d5d73f13e82e9362d6efbba9f8490045977df39f8abdb',
    '0x516e11f52cadd4820a782a548952836bd993f34d0171ec8ffdd3b51903eb6062',
    '0x68df8d40b3638c31b735cc036781a311652d78303d455e7347e13ec7f24414f1',
    '0xd158e796f55065301ee855a9ead0f5b4a60ba6a64e62a664789bbadd8141a114',
    '0x2c3415e93b2ef80870326cbfe1b17ddd1e6a16b23fe541ada38f1fad27352ef2',
    '0x244363223a6957bf47efae2d58a48024b0dc82a5a75ddff44bed2754682f7f4d',
    '0x3478eae9345fefc48ff81a2674810afc2b6eb4912984b130751bef1609cfe4bb',
    '0x596b07b4ede7201e251c0cbf1a856f65419a3f8762ab3c9e9f7c712b08174fd9',
    '0xf07786df4ef348a56feaa636761557c54851aeab04e6554b2a62d4e070d7d48c',
    '0x9d19c476aba9eaae6628d8619b122d85a294ff47d9486a765e64a6488db599a0',
    '0x824a41795204620f88951b45a2d7367b94f7db37a7aa2b3fd00a77d7e553b4c1',
    '0xa1b8079b3bea1d7601db02f32cabc9610696125462558a9a30b56e0bd1c445fb',
    '0xa127058f0f0bc0c1bf398f9ed54a189e8590447b0991de8f253431ab802c14fd',
    '0xcaf0535736357c49cfa990b7ded415a6f24f10802ca652df040866e219671c2a',
    '0xebeabdcfbe897a78baba0d0720b7d208c2472d36f06669bdb5b319715bc0b7f5',
    '0x6bc3f389a11dfe6bc6d4d0548a8f8770242a30c23c46fedfadf3bbfe37468691',
    '0x80665fb64e1027b5dd04ffeb3aa1bb5931dcee177f5062d9fdcdcdd52edf2aff',
    '0x448b49f72d23ecdb281bf1a92d94ab63ef3efc58937d80f51fa2dadd02591bdb',
    '0xb5c10dbb51b00199d4d817488490f129e80832a4fd6dbf209277c11d42873cca',
    '0x8e177bbe4f3e53c4701a1f6bd74db1173548f1d754601f55ddbb780649949d86',
    '0x8385a4d86eef605941b6289631544c23f858c781d12b69b54ed7579699a9e152',
    '0xdd24a4e107d5037a7a4596c5b6457645680457631e3349e005224149bda3f332',
    '0xd0e87d37ea373b246169ee5885ac8523baa499e32d707dc7e119e9428e38f6fc',
    '0x3f03f98aa3a23135741aca782650aa55c705ed78c0dbcbf0f923ff5aee93be6e',
    '0x0ec3f2488a93839524add10ea229e773f6bc891b4eb4794c3337d4495263790b'
]

false_positives = [
    '0x5dc6940e315460f44c70f14f06ec4703c7638d84af9e8956a52bc9c0f5181ed7',
    '0x448b49f72d23ecdb281bf1a92d94ab63ef3efc58937d80f51fa2dadd02591bdb',
    '0x10c3d3cb758e179071920e8a1ecec8ab8e934ff2168ec86632bf87b4750468ae',
    '0xe0ff4c18eb1a2431eaa4ad6968c3c91ace0aabee931ede7b0caa81744ab5d1b6',
    '0x39325ff0aba63e43af8ff405aea163f800c6bf9a20f5a71adab97f57a19b5ec6'
]

if __name__ == '__main__':
    FNULL = open(os.devnull, 'w')
    start = time.time()

    print("Testing for true positives...")

    for transaction in true_positives:
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t "+str(transaction)), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! ERROR !!!\033[0m")
            print("Could not extract facts for transaction: "+str(transaction))
        else:
            p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
            output = str(p.communicate()[0])
            if "Traceback" in output or "error" in output:
                print("\033[91m!!! ERROR !!!\033[0m")
                print("Could not analyze facts for transaction: "+str(transaction))
            else:
                if os.path.getsize("results/Reentrancy.csv") != 0:
                    print("\033[92mPASSED\033[0m")
                    print("Horus correctly identifies "+str(transaction)+" as a true positive!")
                else:
                    print("\033[91m!!! FAILED !!!\033[0m")
                    print("Horus does not correctly identify "+str(transaction)+" as a true positive!")
        shutil.rmtree('facts')
        shutil.rmtree('results')

    print("")
    print("Testing for true negatives...")

    for transaction in false_positives:
        p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -e -t "+str(transaction)), stdout=subprocess.PIPE, stderr=FNULL)
        output = str(p.communicate()[0])
        if "Traceback" in output or "error" in output:
            print("\033[91m!!! ERROR !!!\033[0m")
            print("Could not extract facts for transaction: "+str(transaction))
        else:
            p = subprocess.Popen(shlex.split("python3.8 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl"), stdout=subprocess.PIPE, stderr=FNULL)
            output = str(p.communicate()[0])
            if "Traceback" in output or "error" in output:
                print("\033[91m!!! ERROR !!!\033[0m")
                print("Could not analyze facts for transaction: "+str(transaction))
            else:
                if os.path.getsize("results/Reentrancy.csv") == 0:
                    print("\033[92mPASSED\033[0m")
                    print("Horus correctly identifies "+str(transaction)+" as a true negative!")
                else:
                    print("\033[91m!!! FAILED !!!\033[0m")
                    print("Horus does not correctly identify "+str(transaction)+" as a true negative!")
        shutil.rmtree('facts')
        shutil.rmtree('results')
