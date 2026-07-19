# ABOUT: Makefile variables

# _____________________________________________________________________________

# SECTION: Settings

.SILENT:

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

# CFLAGS stands for Compiler flags
# These are additional flags given to the C compiler to modify its behavior
# when compiling the program.
CFLAGS = -std=c23 -Include -Wall -Wextra -Wpedantic

# To use the value of variable use the syntax `$(VARIABLE_NAME)`
COMPILER_CALL = $(CC) $(CFLAGS)

# NOTE: None of the variable names above are special keywords.
# You can name your variables as you wish.

# _____________________________________________________________________________

# SECTION: Tasks

build: generate-lib-dot-o generate-main-dot-o
	mkdir -p build/bin/
	clang -std=c23 -Iinclude -Wall -Wextra -Wpedantic build/obj/main.o build/obj/lib.o -o build/bin/main

generate-lib-dot-o:
	mkdir -p build/obj/
	clang -std=c23 -Iinclude -Wall -Wextra -Wpedantic -c src/lib.c -o build/obj/lib.o

generate-main-dot-o:
	mkdir -p build/obj/
	clang -std=c23 -Iinclude -Wall -Wextra -Wpedantic -c src/main.c -o build/obj/main.o

generate-compile-commands:
	bear -- make build --silent

run:
	./build/bin/main

clean:
	rm -rf .cache/
	rm -rf build/
	rm -f compile_commands.json

# _____________________________________________________________________________
