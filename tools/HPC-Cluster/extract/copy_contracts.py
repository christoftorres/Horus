
import zipfile

MIN_TRANSACTIONS = 101
MAX_TRANSACTIONS = 1000
START = 0
NUMBER_OF_CONTRACTS = 50000

SOURCE = '/Users/Christof/Downloads/contracts.zip'
DESTINATION = '/Users/Christof/Downloads/'

count = 0
with zipfile.ZipFile(SOURCE, 'r') as zip_file:
    files = zip_file.namelist()
    for file_name in files:
        if file_name.endswith('.csv'):
            with zip_file.open(file_name) as file1:
                transactions = len(file1.readlines())
                if MIN_TRANSACTIONS <= transactions and transactions <= MAX_TRANSACTIONS:
                    count += 1
                    if count > START:
                        file1.seek(0)
                        print(file_name+" "+str(transactions))
                        with open(DESTINATION+file_name, 'w') as file2:
                            file2.write(file1.read().decode('utf-8'))
        if count == START+NUMBER_OF_CONTRACTS:
            break
