# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++20 -Iinclude -I/raylib/src -fPIE

# Linker flags
LDFLAGS = -L/raylib/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -pie

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)   # All source files in src/
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))  # Object files in build/

# Output binary
TARGET = main

# Default target: build the project
all: $(TARGET)

# Link object files into the final binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# PHONY targets
.PHONY: all clean