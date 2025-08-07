# Makefile for sort project
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files in current directory (excluding test files)
SRC := $(wildcard *.c)
# Exclude test files (files ending with _test.c)
SRC := $(filter-out %_test.c, $(SRC))
# Generate object files
OBJ := $(SRC:.c=.o)

# Test source files
TEST_SRC := $(wildcard *_test.c)
# Test executables (remove .c extension)
TESTS := $(TEST_SRC:.c=)

# Default target
all: $(TESTS)

# Generic rule to build each test
%: %.c $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

# Or, more efficient: use .o files
# Uncomment the following for separate compilation
#
# %: %.o $(OBJ)
#	$(CC) $(CFLAGS) $^ -o $@
#
# %.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

# Run all tests
test: $(TESTS)
	@echo "Running all tests..."
	@for test in $(TESTS); do \
		echo "------ Running $$test ------"; \
		./$$test; \
	done

# Clean build files
clean:
	rm -f $(OBJ) $(TESTS)

# Clean all (including object files and tests)
clean-all: clean
	rm -f *.o *~ *.out

# Show what will be built
.PHONY: all test clean clean-all
