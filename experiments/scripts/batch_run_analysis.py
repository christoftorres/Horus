#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import shlex
import subprocess
import multiprocessing

NUMBER_OF_JOBS = multiprocessing.cpu_count()

def run_analyzer(argument):
    block_number = argument
    if not os.path.exists("../results/results_"+str(block_number)+".zip"):
        cmd = 'python3 ../horus/horus.py -a -d ../horus/analyzer/datalog/attacks.dl -f ../facts/facts_'+str(block_number)+'.zip -r ../results/results_'+str(block_number)+' --compress'
        print(cmd)
        proc = subprocess.Popen(shlex.split(cmd), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = proc.communicate()
        if os.path.exists("../results/results_"+str(block_number)+".zip"):
            print("Analyzed facts for: "+str(block_number))
        else:
            print("Could not extract facts for block: "+str(block_number))
            print(out)
            print(err)
    else:
        print("Facts for block "+str(block_number)+" have already been analyzed!")

if __name__ == '__main__':
    arguments = range(1, 10000001)
    with multiprocessing.Pool(NUMBER_OF_JOBS) as pool:
        pool.map(run_analyzer, arguments)
