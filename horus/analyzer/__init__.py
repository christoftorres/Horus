#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import time
import shlex
import subprocess

class Analyzer:
    def compile_datalog_file(self, atalog_file):
        execution_path = os.path.dirname(sys.argv[0]) if os.path.dirname(sys.argv[0]) else "."
        if os.path.isdir(execution_path+"/analyzer/executable"):
            shutil.rmtree(execution_path+"/analyzer/executable")
            os.mkdir(execution_path+"/analyzer/executable")
        else:
            os.mkdir(execution_path+"/analyzer/executable")
        print("Compiling datalog rules and queries into a parallel C++ executable...")
        compilation_begin = time.time()
        p = subprocess.Popen(shlex.split("souffle -o "+execution_path+"/analyzer/executable/analyzer "+datalog_file), stdout=subprocess.PIPE)
        p.communicate()
        compilation_end = time.time()
        print("Compilation took %.2f second(s).\n" % (compilation_end - compilation_begin))

    def analyze_facts(self, facts_folder, results_folder, datalog_file):
        # Create parallel C++ executable if not available or is out-dated
        execution_path = os.path.dirname(sys.argv[0]) if os.path.dirname(sys.argv[0]) else "."
        if not os.path.isdir(execution_path+"/analyzer/executable"):
            compile_datalog_file(datalog_file)
        elif not os.path.isfile(execution_path+"/analyzer/executable/analyzer"):
            compile_datalog_file(datalog_file)
        elif os.stat(datalog_file)[8] > os.stat(execution_path+"/analyzer/executable/analyzer")[8]:
            compile_datalog_file(datalog_file)
        # Run datalog analysis through executable
        analysis_begin = time.time()
        p = subprocess.Popen(shlex.split(execution_path+"/analyzer/executable/analyzer -D "+results_folder+" -F "+facts_folder), stdout=subprocess.PIPE)
        p.communicate()
        analysis_end = time.time()
        print("Analyzing facts took %.2f second(s)." % (analysis_end - analysis_begin))
