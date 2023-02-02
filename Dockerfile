FROM ubuntu:18.04

# Setting port for this OS
EXPOSE 3000

# Copty sourse to image
COPY * /mnt/

# Running command
RUN apt-get update -y && apt-get install -y build-essential cmake apt-utils
RUN cd /mnt/ && mkdir build && cd build/ && cmake .. && make
