
import csv
import glob

from zipfile import ZipFile
from io import TextIOWrapper

reentrancy_file = open('reentrancy_results.csv', mode='w')
reentrancy_writer = csv.writer(reentrancy_file, delimiter=',')

parity_wallet_hack_1_file = open('parity_wallet_hack_1_results.csv', mode='w')
parity_wallet_hack_1_writer = csv.writer(parity_wallet_hack_1_file, delimiter=',')

parity_wallet_hack_2_file = open('parity_wallet_hack_2_results.csv', mode='w')
parity_wallet_hack_2_writer = csv.writer(parity_wallet_hack_2_file, delimiter=',')

integer_overflow_file = open('integer_overflow_results.csv', mode='w')
integer_overflow_writer = csv.writer(integer_overflow_file, delimiter=',')

unhandled_exception_file = open('unhandled_exception_results.csv', mode='w')
unhandled_exception_writer = csv.writer(unhandled_exception_file, delimiter=',')

short_address_file = open('short_address_results.csv', mode='w')
short_address_writer = csv.writer(short_address_file, delimiter=',')

count = 0
for filename in glob.glob("results/*.zip"):
    print(filename)
    with ZipFile(filename, "r") as archive:
        with archive.open('Reentrancy.csv', 'r') as content:
            reader = csv.reader(TextIOWrapper(content, 'utf-8'), delimiter='\t')
            for row in reader:
                reentrancy_writer.writerow(row)
        with archive.open('ParityWalletHack1.csv', 'r') as content:
            reader = csv.reader(TextIOWrapper(content, 'utf-8'), delimiter='\t')
            for row in reader:
                parity_wallet_hack_1_writer.writerow(row)
        with archive.open('ParityWalletHack2.csv', 'r') as content:
            reader = csv.reader(TextIOWrapper(content, 'utf-8'), delimiter='\t')
            for row in reader:
                parity_wallet_hack_2_writer.writerow(row)
        with archive.open('IntegerOverflow.csv', 'r') as content:
            reader = csv.reader(TextIOWrapper(content, 'utf-8'), delimiter='\t')
            for row in reader:
                integer_overflow_writer.writerow(row)
        with archive.open('UnhandledException.csv', 'r') as content:
            reader = csv.reader(TextIOWrapper(content, 'utf-8'), delimiter='\t')
            for row in reader:
                unhandled_exception_writer.writerow(row)
        with archive.open('ShortAddress.csv', 'r') as content:
            reader = csv.reader(TextIOWrapper(content, 'utf-8'), delimiter='\t')
            for row in reader:
                short_address_writer.writerow(row)
    count += 1

reentrancy_file.close()
parity_wallet_hack_1_file.close()
parity_wallet_hack_2_file.close()
integer_overflow_file.close()
unhandled_exception_file.close()
short_address_file.close()

print("Number of processed results: "+str(count))
