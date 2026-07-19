# ABOUT: Patterns

# _____________________________________________________________________________

# SECTION: Settings

# .SILENT:

.PHONY: build \
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

# _____________________________________________________________________________

# SECTION: Tasks

# `build` will be treated as strictly a task because it is listed in .PHONY
# `build` depends on `build/obj/lib.o` and `build/obj/main.o`
build: build/obj/lib.o build/obj/main.o
	mkdir -p build/bin/
	$(C_COMPILER_CALL) build/obj/main.o build/obj/lib.o -o build/bin/$(EXECUTABLE_NAME)

# `build/obj/lib.o` depends on `src/lib.c`.
# It will be rebuilt whenever `src/lib.c` is newer than `build/obj/lib.o`.
build/obj/lib.o: src/lib.c
	mkdir -p build/obj/
	$(C_COMPILER_CALL) -c src/lib.c -o build/obj/lib.o

# `build/obj/main.o` depends on `src/main.c`.
# It will be rebuilt whenever `src/main.c` is newer than `build/obj/main.o`.
build/obj/main.o: src/main.c
	mkdir -p build/obj/
	$(C_COMPILER_CALL) -c src/main.c -o build/obj/main.o

compile_commands.json:
	bear -- make build --silent

run: build
	./build/bin/main

clean:
	rm -rf .cache/
	rm -rf build/
	rm -f compile_commands.json

# _____________________________________________________________________________
