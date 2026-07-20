# SECTION: 1 => Makefile Settings

# The default behavior of `make` is to create files and directories.
# `.PHONY:` is used to override this default behavior, 
# when you want to create custom commands.

# The lines bellow, tells `make` to treat 
# `make build`, `make run`, and `make clean`,
# as custom commands, rather than as files or directories that need to be 
# created.
.PHONY: build \
        run \
        clean

# _____________________________________________________________________________

# SECTION: 1 => Variables

# _____________________________________________________________________________

# SUB_SECTION: A => Compiler Settings 

COMPILER = clang
LANGUAGE_STANDARD_FLAG = -std=c23
HEADER_DIRECTORY_FLAG = -Iinclude
COMPILER_WARNING_FLAGS = -Wall -Wextra -Wpedantic

CREATE_BIN_COMMAND = $(COMPILER) \
			 $(LANGUAGE_STANDARD_FLAG) \
			 $(HEADER_DIRECTORY_FLAG) \
			 $(COMPILER_WARNING_FLAGS)

CREATE_OBJECT_COMMAND = $(CREATE_OBJECT_COMMAND) -c

#______________________________________________________________________________

# SUB_SECTION: B => Project Structure

SOURCE_FILE_DIRECTORY = src
SOURCE_FILES = $(wildcard $(SOURCE_FILE_DIRECTORY)/*.c)

OBJECT_FILE_DIRECTORY = build/obj
OBJECT_FILES = $(patsubst src/%.c, build/obj/%.o, $(SOURCE_FILES))

BIN_FILE_DIRECTORY = build/bin
BIN_FILE = $(BIN_FILE_DIRECTORY)/main

#______________________________________________________________________________

DEBUG = 1

ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
else
	CFLAGS += -O3
endif

# _____________________________________________________________________________

# SECTION: 3 => Makefile Targets (Files that need to be created or updated)


# _____________________________________________________________________________

# SECTION: 4 => Makefile Tasks (Custom Commands)

# build, run, clean



# SOURCE_FILE_DIRECTORY = src
# SOURCE_FILES = $(wildcard $(SOURCE_FILE_DIRECTORY)/*.c)
#
# OBJECT_FILE_DIRECTORY = build/obj
# OBJECT_FILES = $(patsubst src/%.c, build/obj/%.o, $(SOURCE_FILES))
#
# BIN_FILE_DIRECTORY = build/bin
# BIN_FILE = $(BIN_FILE_DIRECTORY)/main

run: build
	./build/bin/$(EXECUTABLE_NAME)

clean:
	rm -rf .cache/
	rm -rf build/
	rm -f compile_commands.json

# _____________________________________________________________________________


build: $(C_OBJECTS)
	mkdir -p build/bin/
	$(C_COMPILER_CALL) $(C_OBJECTS) -o build/bin/$(EXECUTABLE_NAME)

# build/obj/lib.o: src/lib.c
# 	mkdir -p build/obj/
# 	$(C_COMPILER_CALL) -c src/lib.c -o build/obj/lib.o

# build/obj/main.o: src/main.c
# 	mkdir -p build/obj/
# 	$(C_COMPILER_CALL) -c src/main.c -o build/obj/main.o

compile_commands.json:
	bear -- make build --silent

# _____________________________________________________________________________

# This means for every `.c` file in the `src/` directory, 
# create a `.o` file with the same name in the `build/obj` directory

build/obj/%.o: src/%.c
	mkdir -p build/obj/
	$(C_COMPILER_CALL) -c $< -o $@

# `$@` file name of the target
# $< name of first prequisite
# $^ the names of all prequisites

# _____________________________________________________________________________
# .SILENT:
