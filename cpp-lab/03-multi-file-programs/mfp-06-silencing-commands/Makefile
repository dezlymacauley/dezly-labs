# ABOUT: Silencing the command output

# Method 1 - Fine-grained control

# Just place an `@` sign before each line

# clean:
# 	@rm -f $(BINARY_EXECUTABLE_NAME)
# 	@rm -f $(OBJECT_FILES_LIST)

#______________________________________________________________________________

# Method 2 - To silence the entire file,
# Make sure that the line below is the first uncommented line in the Makefile
# `.SILENT:`

#______________________________________________________________________________

# SECTION: 1 => Makefile Settings

.SILENT:

#______________________________________________________________________________

# SECTION: 2 => Variables

# The C++ compiler
COMPILER = clang++

# The C++ standard
STANDARD = -std=c++20

# Compiler Warnings for catching common errors
WARNINGS = -Wall -Wextra -Wpedantic

# This can either be set to `DEBUG` or `RELEASE`
BUILD_MODE = DEBUG 

# These setting will be applied when `BUILD_MODE = DEBUG`
DEBUG_MODE_FLAGS = -g -O0

# These setting will be applied when `BUILD_MODE = RELEASE`
RELEASE_MODE_FLAGS = -O2

# This is how you declare a variable as an empty string.
# This variable will be set by the if statement below
BUILD_SETTINGS = 

ifeq ($(BUILD_MODE), DEBUG)
	BUILD_SETTINGS = $(DEBUG_MODE_FLAGS)
else
	BUILD_SETTINGS = $(RELEASE_MODE_FLAGS)
endif

COMPILER_CALL = $(COMPILER) \
				$(STANDARD) \
				$(WARNINGS) \
				$(BUILD_SETTINGS)

# `wildcard` is a built-in function in `make`
# When used like this, 
# it will create a space-separated list of all the files in the directory 
# that end with .cc
# Here's an example of how the list will look:
# lib.cc main.cc
SOURCE_FILES_LIST = $(wildcard *.cc)

# `patsubst` is a built-in function in `make`
# When used like this, 
# it will create a new list based on the SOURCE_FILES_LIST
# Every .cc will be replaced with .o
# The syntax is: $(patsubst %pattern, %replacement, list)
# Here's an example of how the list will look:
# lib.o main.o
OBJECT_FILES_LIST = $(patsubst %.cc, %.o, $(SOURCE_FILES_LIST))

BINARY_EXECUTABLE_NAME = main

#______________________________________________________________________________

# SECTION: 3 => Commands

print-build-mode:
	echo $(BUILD_MODE)

list-source-files:
	echo $(SOURCE_FILES_LIST)

list-object-files:
	echo $(OBJECT_FILES_LIST)

# Creates the `lib.o` and `main.o` object files,
# and then uses both object files to create a binary executable called `main`
build: create-lib.o create-main.o
	$(COMPILER_CALL) $(OBJECT_FILES_LIST) -o $(BINARY_EXECUTABLE_NAME)

# Creates the `lib.o` object file
create-lib.o:
	$(COMPILER_CALL) -c lib.cc -o lib.o

# Creates the `main.o` object file
create-main.o:
	$(COMPILER_CALL) -c main.cc -o main.o

# Runs the binary executable
run:
	./$(BINARY_EXECUTABLE_NAME)

# Deletes the binary executable and all object files
clean:
	rm -f $(BINARY_EXECUTABLE_NAME)
	rm -f $(OBJECT_FILES_LIST)
