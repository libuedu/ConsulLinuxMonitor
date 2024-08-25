FROM  ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Shanghai

SHELL ["/bin/bash", "-c"]

RUN apt-get clean && \
    apt-get autoclean

RUN apt-get update  && apt-get upgrade -y  && \
    apt-get install -y \
    htop \
    apt-utils \
    curl \
    git \
    openssh-server \
    build-essential \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    libboost-all-dev \
    net-tools \
    vim \
    stress \
    nlohmann-json3-dev \
    libcurl4-openssl-dev \
    libssl-dev \ 
    unzip \
    libgoogle-glog-dev

RUN apt-get install -y libc-ares-dev  libssl-dev gcc g++ make    

RUN apt-get install -y  \
    libx11-xcb1 \
    libfreetype6 \
    libdbus-1-3 \
    libfontconfig1 \
    libxkbcommon0   \
    libxkbcommon-x11-0

RUN apt-get install -y python-dev \
    python3-dev \
    python3-pip \
    python3-all-dev

COPY install/cmake /tmp/install/cmake
RUN /tmp/install/cmake/install_cmake.sh

COPY install/protobuf /tmp/install/protobuf
RUN /tmp/install/protobuf/install_protobuf.sh

COPY install/abseil /tmp/install/abseil
RUN /tmp/install/abseil/install_abseil.sh

COPY install/grpc /tmp/install/grpc
RUN /tmp/install/grpc/install_grpc.sh

COPY install/cpr /tmp/install/cpr
RUN /tmp/install/cpr/install_cpr.sh

COPY install/consul /tmp/install/consul
RUN /tmp/install/consul/install_consul.sh

WORKDIR /work
