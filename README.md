Horus
======

![](https://img.icons8.com/color/200/bastet.png)

An analysis tool to detect attacks in Ethereum transactions.

# Installation Instructions

## 1. Install Soufflé

#### MacOS

``` shell
brew install souffle-lang/souffle/souffle
```

Follow the installation instructions on [souffle-lang.github.io](https://souffle-lang.github.io/install) for other operating systems.

## 2. Install Python Dependencies

``` shell
cd horus
pip install -r requirements.txt
```

# Running Instructions

1. Run the <b>extractor</b> on a transaction (```-t```), block (```-b```) or contract (```-c```):

``` shell
cd horus
python3 horus.py -e -t 0x0ec3f2488a93839524add10ea229e773f6bc891b4eb4794c3337d4495263790b
```

2. Run the <b>analyzer</b> on the extracted Datalog facts:

``` shell
cd horus
python3 horus.py -a
```

Run ```python3 horus.py --help``` for a complete list of options.
