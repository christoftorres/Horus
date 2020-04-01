#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import glob
import shutil

ARGUMENTS     = "arguments"
LAUNCHERS     = "launchers"
MAX_ARGUMENTS = 10000
WALLTIME      = "0-08:00:00"
CORES         = 100

if __name__ == "__main__":
    count = len(glob.glob1("../datasets/contracts_to_check", "*.json"))
    print("Number of smart contracts: "+str(count))

    if count > 0:
        if os.path.exists(ARGUMENTS):
            shutil.rmtree(ARGUMENTS)
        os.makedirs(ARGUMENTS)

        if os.path.exists(LAUNCHERS):
            shutil.rmtree(LAUNCHERS)
        os.makedirs(LAUNCHERS)

        if os.path.exists("launch.sh"):
            os.remove("launch.sh")

        launcher_script = open("launch.sh", "w+")

        file_counter = 1
        arguments_counter = 0
        arguments_file = open(ARGUMENTS+"/parallel_launcher_arguments_"+str(file_counter), "w")
        shutil.copy("horus_parallel_launcher.sh", os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh"))
        s = open(os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh")).read()
        #s = s.replace('#SBATCH -N 1',              '#SBATCH -N '+str(NODES))
        #s = s.replace('#SBATCH -n 28',             '#SBATCH -n '+str(CORES))
        s = s.replace('#SBATCH --time=0-08:00:00', '#SBATCH --time='+WALLTIME)
        s = s.replace('#SBATCH -J Horus',          '#SBATCH -J Horus_'+str(file_counter))
        s = s.replace('cat $HOME/Horus/arguments/parallel_launcher_arguments', 'cat $HOME/Horus/'+ARGUMENTS+'/parallel_launcher_arguments_'+str(file_counter))
        f = open(os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh"), 'w')
        f.write(s)
        f.close()
        launcher_script.write('sbatch ./'+os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh")+'\n')

        for contract in glob.glob("../datasets/contracts_to_check/*.json"):
            arguments_counter += 1
            if arguments_counter > MAX_ARGUMENTS:
                arguments_file.close()
                file_counter += 1
                arguments_counter = 1
                arguments_file = open(ARGUMENTS+"/parallel_launcher_arguments_"+str(file_counter), "w")
                shutil.copy("horus_parallel_launcher.sh", os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh"))
                s = open(os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh")).read()
                #s = s.replace('#SBATCH -N 1',              '#SBATCH -N '+str(NODES))
                #s = s.replace('#SBATCH -n 28',             '#SBATCH -n '+str(CORES))
                s = s.replace('#SBATCH --time=0-08:00:00', '#SBATCH --time='+WALLTIME)
                s = s.replace('#SBATCH -J Horus',          '#SBATCH -J Horus_'+str(file_counter))
                s = s.replace('cat $HOME/Horus/arguments/parallel_launcher_arguments', 'cat $HOME/Horus/'+ARGUMENTS+'/parallel_launcher_arguments_'+str(file_counter))
                f = open(os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh"), 'w')
                f.write(s)
                f.close()
                launcher_script.write('sbatch ./'+os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh")+'\n')
            arguments_file.write(os.path.splitext(os.path.basename(contract))[0]+"\n")
            print(os.path.splitext(os.path.basename(contract))[0])
        arguments_file.close()

        launcher_script.close()
