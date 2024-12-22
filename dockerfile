# Use a base image with GCC for building Raylib projects
FROM debian:bullseye

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libasound2-dev \
    libgl1-mesa-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libxcursor-dev \
    libxinerama-dev \
    libxext-dev \
    && apt-get clean

# Clone and build Raylib
RUN git clone https://github.com/raysan5/raylib.git /raylib && \
    cd /raylib && mkdir build && cd build && \
    cmake .. && make && make install && \
    cd / && rm -rf /raylib

# Set working directory for the project
WORKDIR /usr/src/app

# Copy the project files into the container
COPY . .

# Set the entrypoint to compile and run the project
ENTRYPOINT ["make", "run"]
