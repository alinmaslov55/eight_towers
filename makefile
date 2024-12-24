# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++20 -I/raylib/src -Iinclude

# Linker flags
LDFLAGS = -L/raylib/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Output binary
TARGET = main

# Rules
all: $(TARGET)

# Link all object files to create the final binary
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

## Compiler and Flags
#CXX = g++
#CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
#LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
#
## Directories
#SRCDIR = src
#BUILDDIR = build
#TARGET = main
#
## Source Files
#SRC = $(wildcard $(SRCDIR)/*.cpp)
#OBJ = $(SRC:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
#
## Default Target
#all: $(TARGET)
#
## Build Target
#$(TARGET): $(OBJ)
#	$(CXX) $(OBJ) -o $@ $(LDFLAGS)
#
## Build Object Files
#$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
#	$(CXX) $(CXXFLAGS) -c $< -o $@
#
## Create Build Directory
#$(BUILDDIR):
#	mkdir -p $(BUILDDIR)
#
## Clean Build Files
#clean:
#	rm -rf $(BUILDDIR) $(TARGET)
#
## Run the Program
#run: all
#	./$(TARGET)
#
#.PHONY: all clean run
####