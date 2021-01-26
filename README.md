Horus
======

![](https://img.icons8.com/color/200/bastet.png)

A framework to detect attacks and trace stolen assets across Ethereum.  Our paper can be found [here](https://orbilu.uni.lu/retrieve/77779/85581/FC_21_Horus_Torres.pdf).

## Quick Start

A container with the dependencies set up can be found [here](https://hub.docker.com/r/christoftorres/horus/).

To open the container, install docker and run:

``` shell
docker pull christoftorres/horus && docker run -i -t christoftorres/horus
```

To evaluate a transaction inside the container, run:

``` shell
cd horus
python3 horus.py -e -tx 0x0ec3f2488a93839524add10ea229e773f6bc891b4eb4794c3337d4495263790b --host <RPC_HOST> --port <RPC_PORT>
python3 horus.py -a
```

and you are done!

## Custom Docker image build

``` shell
docker build -t horus .
docker run -it horus:latest
```

## Installation Instructions

### 1. Install Soufflé

##### MacOS

``` shell
brew install souffle-lang/souffle/souffle
```

For other operating systems follow the installation instructions on [souffle-lang.github.io](https://souffle-lang.github.io/install).

### 2. Install Python Dependencies

``` shell
cd horus
pip3 install -r requirements.txt
```

### 3. Install Neo4j

Download and install Neo4j from [neo4j.com](https://neo4j.com/download-center).

## Running Instructions

:warning: **Horus requires a connection to a fully synced Go-Ethereum (Geth) archive node.**

More information on how to run an archive node can be found [here](https://docs.ethhub.io/using-ethereum/running-an-ethereum-node/#archive-nodes).

1. Run the <b>extractor</b> on a transaction (```-tx```), block (```-b```) or contract (```-c```):

``` shell
cd horus
python3 horus.py -e -tx 0x0ec3f2488a93839524add10ea229e773f6bc891b4eb4794c3337d4495263790b --host <RPC_HOST> --port <RPC_PORT> -f <FACTS_FOLDER>
```

2. Run the <b>analyzer</b> on the extracted Datalog facts:

``` shell
cd horus
python3 horus.py -a -f <FACTS_FOLDER> -r <RESULTS_FOLDER> -d <DATALOG_FILE>
```

3. Run the <b>tracer</b> on the Datalog results:

``` shell
cd horus
python3 horus.py -t -r <RESULTS_FOLDER> --type <TYPE> --direction <DIRECTION> --hops <HOPS> --neo4j-connection <NEO4J_CONNECTION> --neo4j-user <NEO4J_USER> --neo4j-password <NEO4J_PASSWORD>
```

Run ```python3 horus.py --help``` for a complete list of options.
