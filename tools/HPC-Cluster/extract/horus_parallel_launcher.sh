#!/bin/bash -l
#SBATCH --mail-type=end,fail
#SBATCH --mail-user=christof.torres@uni.lu
#SBATCH --time=0-08:00:00 # Execution time
#SBATCH --partition=bigmem # Use the batch partition reserved for passive jobs
#SBATCH --qos=qos-bigmem
#SBATCH -J Horus          # Set the job name
#SBATCH -n 28             # Number of tasks (cores)
#SBATCH -c 1              # 1 core per task

set -x
module load lang/Python/3.7.2-GCCcore-8.2.0
cd /home/users/cferreira/Horus/horus

parallel="parallel -j $SLURM_NTASKS --tmpdir /mnt/lscratch/users/cferreira/tmp"
cat $HOME/Horus/arguments/parallel_launcher_arguments | $parallel --colsep ' ' "python3 horus.py -e -c {1} -f {2} --compress"
