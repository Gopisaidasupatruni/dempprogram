# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra 

# Paths and source files
SRC_DIR = src
TEST_DIR = test
UNITY_DIR = unity

# Source files

TEST_SRC_FILES = $(TEST_DIR)/Testcalc.c
UNITY_SRC_FILES = $(UNITY_DIR)/unity.c

# Targets
all: calc

# Compile the main calculator program
calc:  $(SRC_DIR)/main.c  $(SRC_DIR)/task1.h
	$(CC) $(CFLAGS) -o calc  $(SRC_DIR)/main.c

# Compile the test runner (testrunner) and link with Unity framework
testrunner: $(TEST_SRC_FILES)  $(UNITY_SRC_FILES)  $(SRC_DIR)/task1.h
	$(CC) $(CFLAGS) -o testrunner $(TEST_SRC_FILES)  $(UNITY_SRC_FILES)

# Run tests by invoking testrunner
test: testrunner
	./testrunner

# Clean up by removing binaries
clean:
	rm -f calc testrunner

