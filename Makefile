# Makefile
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17
SRC_DIR := src
BUILD_DIR := build

# Find all .cpp files recursively in src directory
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
# Generate object file paths in build directory
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
# Create list of directories needed for object files
OBJ_DIRS := $(sort $(dir $(OBJS)))

# Final executable name
TARGET := $(BUILD_DIR)/program

.PHONY: all clean

all: $(TARGET)

# Rule to create build directories
$(OBJ_DIRS):
	mkdir -p $@

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)