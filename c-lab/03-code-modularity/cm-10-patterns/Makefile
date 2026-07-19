# ABOUT: Patterns

# _____________________________________________________________________________

# SECTION: Settings

# .SILENT:

.PHONY: build \
        generate-lib-dot-o \
        generate-main-dot-o \
        generate-compile-commands \
        run \
        clean

# _____________________________________________________________________________

# SECTION: Variables

# The naming convention for declaring variables in a Makefile is:
# VARIABLE_NAME = value

# The variable name should be in all caps, 
# with underscores to separate words.

# CC stands for C compiler
# This is the name of the C compiler that you want to use to compile 
# the C program
CC = clang

C_STANDARD = c23

C_WARNINGS = -Wall -Wextra -Wpedantic

# CFLAGS stands for Compiler flags
# These are additional flags given to the C compiler to modify its behavior
# when compiling the program.
CFLAGS = -std=$(C_STANDARD) -Iinclude $(C_WARNINGS)

# To use the value of variable use the syntax `$(VARIABLE_NAME)`
C_COMPILER_CALL = $(CC) $(CFLAGS)

# _____________________________________________________________________________

# You can toggle this by running the command like this.
# make build DEBUG=0
DEBUG = 1

# `-g -O0` means generate debug symbols and don't optimize the code.
# `-O3` means highest optimization levels
ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
else
	CFLAGS += -O3
endif

# _____________________________________________________________________________

EXECUTABLE_NAME = main

C_OBJECTS = lib.o main.o

# _____________________________________________________________________________

# SECTION: Tasks

build: generate-lib-dot-o generate-main-dot-o
	mkdir -p build/bin/
	$(C_COMPILER_CALL) build/obj/main.o build/obj/lib.o -o build/bin/$(EXECUTABLE_NAME)

generate-lib-dot-o:
	mkdir -p build/obj/
	$(C_COMPILER_CALL) -c src/lib.c -o build/obj/lib.o

generate-main-dot-o:
	mkdir -p build/obj/
	$(C_COMPILER_CALL) -c src/main.c -o build/obj/main.o

generate-compile-commands:
	bear -- make build --silent

run:
	./build/bin/main

clean:
	rm -rf .cache/
	rm -rf build/
	rm -f compile_commands.json

my_file.md:
	touch my_file.md

my-directory:
	mkdir my-directory

another-directory:
	echo "Bananas are blue."

# _____________________________________________________________________________

# Patterns

# For every C file that exists in the current directory,
# this will generate a `.o` file with the same name.

# `$<` means the name of the source file.
%.o: %.c
	$(C_COMPILER_CALL) -c $< -o $<@

# _____________________________________________________________________________
