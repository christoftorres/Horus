scancel $(squeue -u cferreira | awk 'FNR > 1 {print $1}')
