#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import shlex
import subprocess
import multiprocessing

NUMBER_OF_JOBS = multiprocessing.cpu_count()

def run_analyzer(arguments):
    facts = arguments[0]
    results = arguments[1]
    proc = subprocess.Popen(shlex.split('python3 /media/external/horus/horus/horus.py -a -f '+facts+' -r '+results+' --compress'), stdout=subprocess.PIPE)
    proc.communicate()
    print("Analyzed facts for: "+contract.split('/')[-1].split('.')[0])

if __name__ == '__main__':
    arguments = []
    with open('arguments.txt', 'r') as arguments_file:
        lines = arguments_file.readlines()
        for line in lines:
            arguments.append(line.strip().split(' '))
    print(len(arguments))
    with multiprocessing.Pool(NUMBER_OF_JOBS) as j:
        j.map(run_extractor, arguments)
