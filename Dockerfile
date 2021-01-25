FROM ubuntu:18.04

MAINTAINER Christof Torres (christof.torres@uni.lu)

SHELL ["/bin/bash", "-c"]
RUN apt-get update -q && \
    apt-get install -y \
    wget tar unzip pandoc python-setuptools python-pip python-dev python-virtualenv git build-essential software-properties-common python3-pip iputils-ping && \
    apt-get clean -q && rm -rf /var/lib/apt/lists/*

#WORKDIR /root
#COPY horus horus

# Install Python Dependencies
#RUN cd horus && pip3 install -r requirements.txt
