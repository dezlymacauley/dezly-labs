# SECTION: 1 => Makefile Settings

.PHONY: build \
        run \
        clean
# _____________________________________________________________________________

# SECTION: 2 => Compiler Settings

COMPILER = clang
LANGUAGE_STANDARD_FLAG = -std=c23
HEADER_DIRECTORY_FLAG = -Iinclude
COMPILER_WARNING_FLAGS = -Wall -Wextra -Wpedantic

CREATE_BIN_COMMAND = $(COMPILER) \
			 $(LANGUAGE_STANDARD_FLAG) \
			 $(HEADER_DIRECTORY_FLAG) \
			 $(COMPILER_WARNING_FLAGS)

CREATE_OBJECT_COMMAND = $(CREATE_OBJECT_COMMAND) -c

# _____________________________________________________________________________

# SECTION: 3 => Project Structure

SOURCE_FILE_DIRECTORY = src
SOURCE_FILES = $(wildcard $(SOURCE_FILE_DIRECTORY)/*.c)

OBJECT_FILE_DIRECTORY = build/obj
OBJECT_FILES = $(patsubst src/%.c, build/obj/%.o, $(SOURCE_FILES))

BIN_FILE_DIRECTORY = build/bin
BIN_FILE_NAME = $(BIN_FILE_DIRECTORY)/main

RUN_COMMAND = ./$(BIN_FILE_DIRECTORY)/$(BIN_FILE_NAME)
CLEAN_COMMAND = rm -rf .cache/ build/ compile_commands.json

#______________________________________________________________________________

# SECTION: 3 => Makefile Tasks (Custom Commands)

build: $(OBJECT_FILES)
	mkdir -p $(BIN_FILE_DIRECTORY)
	$(CREATE_BIN_COMMAND) $(OBJECT_FILES) \
		-o $(BIN_FILE_DIRECTORY)/$(BIN_FILE_NAME)

run: build
	$(RUN_COMMAND)

clean:
	$(CLEAN_COMMAND)
# _____________________________________________________________________________

# SECTION: 4 => Makefile Targets (Files that need to be created or updated)

# This means for every `.c` file in the `src/` directory, 
# create a `.o` file with the same name in the `build/obj` directory

# $(OBJECT_FILE_DIRECTORY)/%.o: $(SOURCE_FILES)
# 	mkdir -p $(OBJECT_FILE_DIRECTORY)
# 	$(CREATE_OBJECT_COMMAND) $< -o $@

# `$@` file name of the target
# $< name of first prequisite
# $^ the names of all prequisites

# _____________________________________________________________________________

# build/obj/lib.o: src/lib.c
# 	mkdir -p build/obj/
# 	$(C_COMPILER_CALL) -c src/lib.c -o build/obj/lib.o

# build/obj/main.o: src/main.c
# 	mkdir -p build/obj/
# 	$(C_COMPILER_CALL) -c src/main.c -o build/obj/main.o

compile_commands.json:
	bear -- make build --silent

# _____________________________________________________________________________
