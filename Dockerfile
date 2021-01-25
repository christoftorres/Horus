FROM ubuntu:18.04

MAINTAINER Christof Torres (christof.torres@uni.lu)

SHELL ["/bin/bash", "-c"]
RUN apt-get update -q && \
    apt-get install -y \
    wget tar unzip pandoc python-setuptools python-pip python-dev python-virtualenv git build-essential software-properties-common python3-pip iputils-ping && \
    apt-get clean -q && rm -rf /var/lib/apt/lists/*

WORKDIR /root
COPY horus horus

# Install Soufflé
RUN echo "deb https://dl.bintray.com/souffle-lang/deb-unstable bionic main" | tee -a /etc/apt/sources.list
RUN apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 379CE192D401AB61
RUN apt-get update -q && \
    apt-get install -y souffle && \
    apt-get clean -q && rm -rf /var/lib/apt/lists/*

# Install Python Dependencies
RUN cd horus && pip3 install -r requirements.txt
