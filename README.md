Horus
======

![](https://img.icons8.com/color/200/bastet.png)

An analysis tool to detect attacks and trace stolen assets across Ethereum.  Our paper can be found [here](https://orbilu.uni.lu/retrieve/77779/85581/FC_21_Horus_Torres.pdf).

## Quick Start

A container with the dependencies set up can be found [here](https://hub.docker.com/r/christoftorres/horus/).

To open the container, install docker and run:

```
docker pull christoftorres/horus && docker run -i -t christoftorres/horus
```

To evaluate a transaction inside the container, run:

```
python3 aegis/aegis.py -t 0x0ec3f2488a93839524add10ea229e773f6bc891b4eb4794c3337d4495263790b --host <RPC_HOST> --port <RPC_PORT>
```

and you are done!

## Custom Docker image build

```
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
pip install -r requirements.txt
```

### 3. Install Neo4j

Download and install Neo4j from [neo4j.com](https://neo4j.com/download-center).

## Running Instructions

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

3. Run the <b>tracer</b> on the Datalog results:

``` shell
cd horus
python3 horus.py -t
```

Run ```python3 horus.py --help``` for a complete list of options.
