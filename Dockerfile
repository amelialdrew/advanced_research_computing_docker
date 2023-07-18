# Get the base Ubuntu image from Docker Hub
FROM ubuntu:latest

# Update apps on the base image
RUN apt-get -y update && apt-get install -y

# Install Python
RUN apt-get -y install python3-pip

# Install iPython
RUN pip3 install ipython

# Install the Clang compiler
RUN apt-get -y install clang

# Install the g++ compiler
RUN apt-get -y install g++

# Install emacs
RUN apt-get -y install emacs

# Install gdb
RUN apt-get -y install gdb

# Install Valgrind
RUN apt-get -y install valgrind

# Install gprof
RUN apt-get -y install binutils

# Install MPI
RUN apt-get -y install mpich

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . /usr/src/dockertest1

# Specify the working directory
WORKDIR /usr/src/dockertest1