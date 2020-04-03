#!/bin/bash -l
#SBATCH --mail-type=end,fail
#SBATCH --mail-user=christof.torres@uni.lu
#SBATCH --time=0-01:00:00 # Execution time
#SBATCH --partition=batch # Use the batch partition reserved for passive jobs
#SBATCH --qos=qos-batch
#SBATCH -J Horus_1          # Set the job name
#SBATCH -N 1              # Number of nodes
#SBATCH -n 10             # Number of tasks (cores)
#SBATCH -c 1              # 1 core per task

set -x
module load lang/Python/3.7.2-GCCcore-8.2.0
cd /home/users/cferreira/Horus/horus

parallel="parallel -j $SLURM_NTASKS"
cat $HOME/Horus/analyze/arguments/parallel_launcher_arguments_1 | $parallel --colsep ' ' "python3 horus.py -a -f {1} -r {2}"