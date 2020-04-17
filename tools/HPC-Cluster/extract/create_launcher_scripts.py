#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import glob
import shutil

CONTRACTS      = "/Users/Christof/Downloads/contracts/"
ARGUMENTS      = "arguments"
LAUNCHERS      = "launchers"
MAX_ARGUMENTS  = 50000
WALLTIME       = "0-24:00:00"
CORES          = 100
CORES_PER_TASK = 1

if __name__ == "__main__":
    count = len(glob.glob1(CONTRACTS, "*.csv"))
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
        s = s.replace('#SBATCH -n 28',             '#SBATCH -n '+str(CORES))
        s = s.replace('#SBATCH -c 1',              '#SBATCH -c '+str(CORES_PER_TASK))
        s = s.replace('#SBATCH --time=0-08:00:00', '#SBATCH --time='+WALLTIME)
        s = s.replace('#SBATCH -J Horus',          '#SBATCH -J Horus_'+str(file_counter))
        s = s.replace('cat $HOME/Horus/arguments/parallel_launcher_arguments', 'cat $HOME/Horus/extract/'+ARGUMENTS+'/parallel_launcher_arguments_'+str(file_counter))
        f = open(os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh"), 'w')
        f.write(s)
        f.close()
        launcher_script.write('sbatch ./'+os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh")+'\n')

        for contract in glob.glob(CONTRACTS+"*.csv"):
            arguments_counter += 1
            if arguments_counter > MAX_ARGUMENTS:
                arguments_file.close()
                file_counter += 1
                arguments_counter = 1
                arguments_file = open(ARGUMENTS+"/parallel_launcher_arguments_"+str(file_counter), "w")
                shutil.copy("horus_parallel_launcher.sh", os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh"))
                s = open(os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh")).read()
                s = s.replace('#SBATCH -n 28',             '#SBATCH -n '+str(CORES))
                s = s.replace('#SBATCH -c 1',              '#SBATCH -c '+str(CORES_PER_TASK))
                s = s.replace('#SBATCH --time=0-08:00:00', '#SBATCH --time='+WALLTIME)
                s = s.replace('#SBATCH -J Horus',          '#SBATCH -J Horus_'+str(file_counter))
                s = s.replace('cat $HOME/Horus/arguments/parallel_launcher_arguments', 'cat $HOME/Horus/extract/'+ARGUMENTS+'/parallel_launcher_arguments_'+str(file_counter))
                f = open(os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh"), 'w')
                f.write(s)
                f.close()
                launcher_script.write('sbatch ./'+os.path.join(LAUNCHERS, "horus_parallel_launcher_"+str(file_counter)+".sh")+'\n')
            arguments_file.write('/home/users/cferreira/Horus/contracts/'+os.path.basename(contract)+" "+'/work/projects/horus/facts/'+os.path.splitext(os.path.basename(contract))[0]+"\n")
            print(os.path.splitext(os.path.basename(contract))[0])
        arguments_file.close()

        launcher_script.close()
