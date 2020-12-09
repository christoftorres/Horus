#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import shlex
import subprocess
import multiprocessing

NUMBER_OF_JOBS = multiprocessing.cpu_count()

def run_analyzer(argument):
    block_number = argument
    proc = subprocess.Popen(shlex.split('python3 ../../horus/horus.py -a -d ../../horus/analyzer/datalog/attacks.dl -f ../../horus/facts/facts_'+str(block_number)+'.zip -r ../../horus/results/results_'+str(block_number)+' --compress'), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    proc.communicate()
    print("Analyzed facts for: "+str(block_number))

if __name__ == '__main__':
    #arguments = range(9500001, 10000001)
    arguments = [9894248, 9894249, 9894250, 9899737, 9899738, 9899739]
    with multiprocessing.Pool(NUMBER_OF_JOBS) as pool:
        pool.map(run_analyzer, arguments)
