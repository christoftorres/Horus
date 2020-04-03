#!/bin/bash -l
#SBATCH --mail-type=end,fail
#SBATCH --mail-user=christof.torres@uni.lu
#SBATCH --time=0-24:00:00 # 24 hours
#SBATCH --partition=bigmem # Use the batch partition reserved for passive jobs
#SBATCH --qos=qos-bigmem
#SBATCH -n 1              # Number of tasks (cores)
#SBATCH -c 1              # 1 core per task

set -x
module load lang/Python/3.7.2-GCCcore-8.2.0
cd /home/users/cferreira/Horus

parallel="parallel -j $SLURM_NTASKS"
cat $HOME/Horus/arguments.txt | $parallel --colsep ' ' "python3 create_extractor_files.py"
