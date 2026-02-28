FROM ubuntu:22.04

# Cài đặt g++-11 và wget
RUN apt-get update && \
    apt-get install -y g++-11 gcc-11 gdb wget && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 100 && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 100

# Set working directory
WORKDIR /workspace

# Dọn dẹp
RUN apt-get clean && rm -rf /var/lib/apt/lists/*