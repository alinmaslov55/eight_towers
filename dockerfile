# Base image
# Use an official Debian image with build tools
FROM debian:bullseye-slim

# Set the working directory in the container
WORKDIR /app

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    wget \
    cmake \
    libgl1-mesa-dev \
    libx11-dev \
    libxi-dev \
    libxcursor-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxext-dev \
    && rm -rf /var/lib/apt/lists/* \
    mesa-utils \
    libgl1-mesa-dri

# Download and build Raylib
RUN git clone https://github.com/raysan5/raylib.git /raylib \
    && cd /raylib/src \
    && make PLATFORM=PLATFORM_DESKTOP \
    && make install PLATFORM=PLATFORM_DESKTOP

# Copy the project files into the container
COPY . .

# Compile the project
RUN make

# Default command to run the program
CMD ["./main"]
