
import os
import pathlib
import zipfile
import tempfile

from web3 import Web3

w3 = Web3(Web3.HTTPProvider("http://pf.uni.lux:8545"))

def updateZip(zipname, filename):
    # generate a temp file
    tmpfd, tmpname = tempfile.mkstemp(dir=os.path.dirname(zipname))
    os.close(tmpfd)

    transaction_facts = ""
    # create a temp copy of the archive without filename
    with zipfile.ZipFile(zipname, 'r') as zin:
        with zipfile.ZipFile(tmpname, 'w') as zout:
            zout.comment = zin.comment # preserve the comment
            for item in zin.infolist():
                if not item.filename.endswith(filename):
                    zout.writestr(item, zin.read(item.filename))
                else:
                    filename = item.filename
                    file = zin.open(item.filename)
                    for line in file:
                        transaction = line.decode("utf-8").rstrip().split("\t")
                        if len(transaction) == 6:
                            transaction.insert(4, str(w3.eth.getTransaction(transaction[0])["gas"]))
                            transaction.insert(4, str(w3.eth.getTransactionReceipt(transaction[0])["gasUsed"]))
                            transaction_facts += '\t'.join(transaction)+'\r\n'
                        else:
                            file.seek(0)
                            zout.writestr(item, file.read())

    # replace with the temp archive
    os.remove(zipname)
    os.rename(tmpname, zipname)

    # now add filename with its new data
    if transaction_facts:
        with zipfile.ZipFile(zipname, mode='a', compression=zipfile.ZIP_DEFLATED) as zf:
            zf.writestr(filename, transaction_facts)

pathlist = pathlib.Path('/Users/Christof/Downloads/facts').glob('**/*.zip')
for path in pathlist:
     path_in_str = str(path)
     print(path_in_str)
     updateZip(path_in_str, 'transaction.facts')
     break
