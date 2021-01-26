#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import time
import json
import shlex
import shutil
import zipfile
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

    def analyze_facts(self, nr_of_threads, profile, facts_folder, results_folder, datalog_file, compress, tmp_folder):
        # Create parallel C++ executable if not available or out-dated
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
        if tmp_folder:
            results = tmp_folder+"/"+results_folder.split("/")[-1]
        else:
            results = results_folder
        if os.path.isdir(results):
            shutil.rmtree(results)
        if not os.path.isdir(results):
            os.mkdir(results)

        if facts_folder.endswith(".zip"):
            if tmp_folder:
                with zipfile.ZipFile(facts_folder, 'r') as zf:
                    zf.extractall(tmp_folder)
                facts = tmp_folder+os.path.splitext(facts_folder)[0]
            else:
                facts = os.path.splitext(facts_folder)[0]
                if not os.path.isdir(facts):
                    os.mkdir(facts)
                with zipfile.ZipFile(facts_folder, 'r') as zip_file:
                    for member in zip_file.namelist():
                        filename = os.path.basename(member)
                        if not filename:
                            continue
                        source = zip_file.open(member)
                        target = open(os.path.join(facts, filename), "wb")
                        with source, target:
                            shutil.copyfileobj(source, target)
        else:
            facts = facts_folder

        souffle_error = False
        if os.path.isfile(execution_path+"/analyzer/executable/analyzer"):
            proc = subprocess.Popen(shlex.split(execution_path+"/analyzer/executable/analyzer"+j+p+" -D "+results+" -F "+facts), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            out, err = proc.communicate()
            if out:
                print("Souffle: "+out.decode('utf-8'))
            if err:
                print("Souffle: "+err.decode('utf-8'))
            analysis_end = time.time()
            analysis_delta = analysis_end - analysis_begin
            souffle_error = out or err
            print("Analyzing facts took %.2f second(s)." % (analysis_delta))
        if not souffle_error:
            if analysis_delta:
                with open(results+"/stats.json", "w") as jsonfile:
                    json.dump(analysis_delta, jsonfile)
            if facts_folder.endswith(".zip"):
                shutil.rmtree(facts)
            if compress:
                shutil.make_archive(results_folder, 'zip', results)
                shutil.rmtree(results)
        else:
            if os.path.isdir(results):
                shutil.rmtree(results)
