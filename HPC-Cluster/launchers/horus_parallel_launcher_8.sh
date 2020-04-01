#!/bin/bash -l
#SBATCH --mail-type=end,fail
#SBATCH --mail-user=christof.torres@uni.lu
#SBATCH --time=0-08:00:00 # 8 hours
#SBATCH --partition=batch # Use the batch partition reserved for passive jobs
#SBATCH --qos=qos-batch
#SBATCH -J Horus_8        # Set the job name
#SBATCH -N 1              # Number of nodes
#SBATCH -n 28             # Number of tasks (cores)
#SBATCH -c 1              # 1 core per task

set -x
module load lang/Python/3.6.4-intel-2018a-bare
cd /home/users/cferreira/Horus/horus

parallel="parallel -j $SLURM_NTASKS --joblog runtask_$SLURM_JOBID.log --resume"
cat $HOME/Horus/arguments/parallel_launcher_arguments_8 | $parallel "python3 horus.py -c {} -l /work/projects/horus/contracts/{}.json -r ../new_results"
