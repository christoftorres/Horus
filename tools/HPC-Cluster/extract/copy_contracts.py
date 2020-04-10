
import zipfile

contracts = {}
with open("arguments/parallel_launcher_arguments_1") as file:
    lines = file.readlines()
    for line in lines:
        contract = line.strip().split(' ')[0].split('/')[-1]
        contracts[contract] = True

with zipfile.ZipFile("/Users/Christof/Git/Horus/tools/HPC-Cluster/extract/contracts.zip", 'r') as zip_file:
   files = zip_file.namelist()
   for file_name in files:
       #print(file_name)
       if file_name.endswith('.csv') and file_name.split('/')[-1] in contracts:
           with zip_file.open(file_name) as file1:
               with open('./'+file_name, 'w') as file2:
                   file2.write(file1.read().decode('utf-8'))
