# SECTION: 1 => Variables

# The C++ compiler
COMPILER = clang++

# The C++ standard
STANDARD = -std=c++20

# Compiler Warnings for catching common errors
WARNINGS = -Wall -Wextra -Wpedantic

# This can either be set to `DEBUG` or `RELEASE`
BUILD_MODE = DEBUG 

# These setting will be applied when `BUILD_MODE = DEBUG`
DEBUG_MODE_FLAGS = -g O0

# These setting will be applied when `BUILD_MODE = RELEASE`
RELEASE_MODE_FLAGS = -02

# This is how you declare a variable as an empty string.
# This variable will be set by the if statement below
BUILD_SETTINGS = 

ifeq ($(BUILD_MODE), DEBUG)
	BUILD_SETTINGS = $(DEBUG_FLAGS)
else
	BUILD_SETTINGS = $(RELEASE_FLAGS)
endif

COMPILER_CALL = $(COMPILER) \
				$(STANDARD) \
				$(WARNINGS) \
				$(BUILD_SETTINGS)

#______________________________________________________________________________

# SECTION: 2 => Commands

print-build-mode:
	echo $(BUILD_MODE)

# Creates the `lib.o` and `main.o` object files,
# and then uses both object files to create a binary executable called `main`
build: create-lib.o create-main.o
	$(COMPILER_CALL) main.o lib.o -o main

# Creates the `lib.o` object file
create-lib.o:
	$(COMPILER_CALL) -c lib.cc -o lib.o

# Creates the `main.o` object file
create-main.o:
	$(COMPILER_CALL) -c main.cc -o main.o

# Runs the binary executable
run:
	./main

# Deletes the binary executable and all object files
clean:
	rm -f main
	rm -f *.o
