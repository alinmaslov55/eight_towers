CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++20

TARGET := main

SRCS := $(wildcard *.cpp)
OBJECTS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean