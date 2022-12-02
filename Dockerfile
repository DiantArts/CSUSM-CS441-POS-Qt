FROM ubuntu:22.04

COPY . /code
WORKDIR /code

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y python3-pip moreutils cmake llvm g++ && rm -rf /var/lib/apt/lists/*
RUN pip install conan ninja

CMD [ "./.toolchain/compile" ]
