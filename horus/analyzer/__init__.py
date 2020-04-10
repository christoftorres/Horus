#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import time
import json
import shlex
import shutil
import subprocess

class Analyzer:
    def compile_datalog_file(self, profile, datalog_file):
        execution_path = os.path.dirname(sys.argv[0]) if os.path.dirname(sys.argv[0]) else "."
        if os.path.isdir(execution_path+"/analyzer/executable"):
            shutil.rmtree(execution_path+"/analyzer/executable")
            os.mkdir(execution_path+"/analyzer/executable")
        else:
            os.mkdir(execution_path+"/analyzer/executable")
        print("Compiling datalog rules and queries into a parallel C++ executable...")
        compilation_begin = time.time()
        p = ""
        if profile:
            p = " -p profile.log"
        proc = subprocess.Popen(shlex.split("souffle"+p+" -o "+execution_path+"/analyzer/executable/analyzer "+datalog_file), stdout=subprocess.PIPE)
        proc.communicate()
        compilation_end = time.time()
        print("Compilation took %.2f second(s).\n" % (compilation_end - compilation_begin))

    def analyze_facts(self, nr_of_threads, profile, facts_folder, results_folder, datalog_file):
        # Create parallel C++ executable if not available or is out-dated
        execution_path = os.path.dirname(sys.argv[0]) if os.path.dirname(sys.argv[0]) else "."
        if not os.path.isdir(execution_path+"/analyzer/executable"):
            self.compile_datalog_file(profile,  datalog_file)
        elif not os.path.isfile(execution_path+"/analyzer/executable/analyzer"):
            self.compile_datalog_file(profile, datalog_file)
        elif os.stat(datalog_file)[8] > os.stat(execution_path+"/analyzer/executable/analyzer")[8]:
            self.compile_datalog_file(profile, datalog_file)
        # Run datalog analysis through executable
        analysis_begin = time.time()
        j = ""
        if nr_of_threads:
            j = " -j "+str(nr_of_threads)
        p = ""
        if profile:
            p = " -p profile.log"
        if os.path.isfile(execution_path+"/analyzer/executable/analyzer"):
            proc = subprocess.Popen(shlex.split(execution_path+"/analyzer/executable/analyzer"+j+p+" -D "+results_folder+" -F "+facts_folder), stdout=subprocess.PIPE)
            proc.communicate()
            analysis_end = time.time()
            analysis_delta = analysis_end - analysis_begin
            print("Analyzing facts took %.2f second(s)." % (analysis_delta))
        with open(results_folder+"/stats.json", "w") as jsonfile:
            json.dump(analysis_delta, jsonfile)
