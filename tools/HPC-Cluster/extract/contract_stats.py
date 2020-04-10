
import sys
import csv
import glob
import numpy
import zipfile

from scipy import stats

csv.field_size_limit(sys.maxsize)

transactions = []

b10        = 0
b100       = 0
b1000      = 0
b10000     = 0
b100000    = 0
b1000000   = 0
b10000000  = 0
b100000000 = 0

"""for contract in glob.glob("contracts/*.csv"):
    with open(contract) as file:
        reader = csv.reader(file, delimiter='\t')
        count = sum(1 for row in reader)
        print(contract+" "+str(count))
        transactions.append(count)
        if count <= 10:
            b10 += 1
        elif count <= 100:
            b100 += 1
        elif count <= 1000:
            b1000 += 1
        elif count <= 10000:
            b10000 += 1
        elif count <= 100000:
            b100000 += 1"""

with zipfile.ZipFile("contracts.zip", 'r') as zip_file:
    files = zip_file.namelist()
    for file_name in files:
        if file_name.endswith('.csv'):
            with zip_file.open(file_name) as file:
                lines = file.readlines()
                count = sum(1 for line in lines)
                print(file_name+" "+str(count))
                transactions.append(count)
                if   count <= 10:
                    b10 += 1
                elif count <= 100:
                    b100 += 1
                elif count <= 1000:
                    b1000 += 1
                elif count <= 10000:
                    b10000 += 1
                elif count <= 100000:
                    b100000 += 1
                elif count <= 1000000:
                    b1000000 += 1
                elif count <= 10000000:
                    b10000000 += 1
                elif count <= 100000000:
                    b100000000 += 1
print()
print(len(transactions))
print(max(transactions))
print(min(transactions))
print(numpy.mean(transactions))
print(numpy.median(transactions))
print(stats.mode(transactions))
print()
print(b10)
print(b100)
print(b1000)
print(b10000)
print(b100000)
print(b1000000)
print(b10000000)
print(b100000000)
print(b10+b100+b1000+b10000+b100000+b1000000+b10000000+b100000000)
