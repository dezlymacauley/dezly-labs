# SECTION: 1 => Makefile Settings

# The default behaviour of `make`, is to create files and directories,
# if they don't exist, and update those files and directories when something
# they depend on changes.
# If a file or directory already exists, and is up to date. 
# Make won't do anything

# E.g. If the `build` directory exists and is already up to date,
# you'll get this message when you run `make build`
# make: Nothing to be done for 'build'.

# E.g. If the file `build/obj/main.o` exists and is already up to date,
# you'll get this message when you run `make build/obj/main.o`
# make: 'build/obj/main.o' is up to date.

# The benefit of this is that it makes compiling your project idempotent.
# In simple terms, you won't have to waste time recompiling files 
# that haven't changed.

# To create custom commands, that always run you need to override 
# the default behavior of `make` by using `.PHONY:` and listing the names
# of custom commands that should always perform an action when you use them.
# E.g. `make help`, `make settings`, `make run`, 
# `make clean`, and `make lsp-sync`
.PHONY: help \
		settings \
        run \
        clean \
		lsp-sync

#______________________________________________________________________________

# SECTION: 2 => Compiler Settings

COMPILER = clang
LANGUAGE_STANDARD_FLAG = -std=c23
HEADER_DIRECTORY_FLAGS = -Iinclude
COMPILER_WARNING_FLAGS = -Wall -Wextra -Wpedantic

CREATE_BIN_COMMAND = $(COMPILER) \
			 $(LANGUAGE_STANDARD_FLAG) \
			 $(HEADER_DIRECTORY_FLAGS) \
			 $(COMPILER_WARNING_FLAGS)

# The `-c` flag tells the compiler to only compile the C code to an object
# file instead of creating a binary executable.
CREATE_OBJECT_COMMAND = $(CREATE_BIN_COMMAND) -c

#______________________________________________________________________________

# SECTION: 3 => Project Structure

SOURCE_FILE_DIRECTORY = src
SOURCE_FILES = $(wildcard $(SOURCE_FILE_DIRECTORY)/*.c)

OBJECT_FILE_DIRECTORY = build/obj
OBJECT_FILES = $(patsubst \
	$(SOURCE_FILE_DIRECTORY)/%.c, \
	$(OBJECT_FILE_DIRECTORY)/%.o, \
	$(SOURCE_FILES))

BIN_FILE_DIRECTORY = build/bin
BIN_FILE_NAME = main
BIN_FILE_PATH = $(BIN_FILE_DIRECTORY)/$(BIN_FILE_NAME)

RUN_COMMAND = ./$(BIN_FILE_PATH)
CLEAN_COMMAND = rm -rf .cache/ build/ compile_commands.json

# This command requires bear to be installed.
# It runs the clean command, so that `make build` will rebuild 
# the `build directory`.
#
# `-- make build` means that when the command `make build` is being run,
# bear is watching the output and using it to create 
# a `compile_commands.json` file. This file is then used by the language
# server `clangd` to provide better language support that understands the
# project structure. Without this, 
# you will get errors when trying to import `.h` (header files) in your
# C code.
LSP_SYNC_COMMAND = $(CLEAN_COMMAND) && bear -- make build --silent

#______________________________________________________________________________

# SECTION: 4 => Makefile Targets (Files that need to be created or updated)

# Manual instructions to create an object file for each source file.
# I prefer this style because it is explicit and readable.
# The trade off is that you have to repeat this for each file in the
# SOURCE_FILE_DIRECTORY. 

# There are only files in this project, `src/main.c` and `src/lib.c`
# so this is fine for now.

build/obj/lib.o: $(SOURCE_FILE_DIRECTORY)/lib.c
	@mkdir -p $(OBJECT_FILE_DIRECTORY)
	@$(CREATE_OBJECT_COMMAND) \
		$(SOURCE_FILE_DIRECTORY)/lib.c -o $(OBJECT_FILE_DIRECTORY)/lib.o

build/obj/main.o: $(SOURCE_FILE_DIRECTORY)/main.c
	@mkdir -p $(OBJECT_FILE_DIRECTORY)
	@$(CREATE_OBJECT_COMMAND) \
		$(SOURCE_FILE_DIRECTORY)/main.c -o $(OBJECT_FILE_DIRECTORY)/main.o
#______________________________________________________________________________

build: $(BIN_FILE_PATH)

$(BIN_FILE_PATH): $(OBJECT_FILES)
	@mkdir -p $(BIN_FILE_DIRECTORY)
	@$(CREATE_BIN_COMMAND) \
		$(OBJECT_FILES) -o $(BIN_FILE_PATH)

#______________________________________________________________________________

# SECTION: 5 => Makefile Tasks (Custom Commands)

help:
	@echo ""
	@echo "Available Commands"
	@echo "================================================="
	@echo ""
	@echo "🔨 make build"
	@echo "    Incrementally builds the project."
	@echo ""
	@echo "✅ make run"
	@echo "    Builds the project if necessary and runs it."
	@echo ""
	@echo "🧼 make clean"
	@echo "    Removes all build artifacts."
	@echo ""
	@echo "🔁 make lsp-sync"
	@echo "    Regenerates compile_commands.json for clangd."
	@echo ""
	@echo "📜 make settings"
	@echo "    Displays the current Makefile settings."
	@echo ""
	@echo "================================================="
	@echo ""

settings:
	@echo ""
	@echo "Compiler Settings"
	@echo "================================================="
	@echo ""
	@echo "Compiler: $(COMPILER)"
	@echo ""
	@echo "Language Standard Flag: $(LANGUAGE_STANDARD_FLAG)"
	@echo ""
	@echo "Header Directory Flags: $(HEADER_DIRECTORY_FLAGS)"
	@echo ""
	@echo "Compiler Warning Flags: $(COMPILER_WARNING_FLAGS)"
	@echo ""
	@echo "Create Bin Command: $(CREATE_BIN_COMMAND)"
	@echo ""
	@echo "Create Object Command: $(CREATE_OBJECT_COMMAND)"
	@echo ""
	@echo "================================================="
	@echo ""
	@echo "Project Structure"
	@echo "================================================="
	@echo ""
	@echo "Source File Directory: $(SOURCE_FILE_DIRECTORY)"
	@echo ""
	@echo "Source Files: $(SOURCE_FILES)"
	@echo ""
	@echo "OBJECT_FILE_DIRECTORY: $(OBJECT_FILE_DIRECTORY)"
	@echo ""
	@echo "OBJECT_FILES: $(OBJECT_FILES)"
	@echo ""
	@echo "BIN_FILE_DIRECTORY: $(BIN_FILE_DIRECTORY)"
	@echo ""
	@echo "BIN_FILE_NAME: $(BIN_FILE_NAME)"
	@echo ""
	@echo "BIN_FILE_PATH: $(BIN_FILE_PATH)"
	@echo ""
	@echo "RUN_COMMAND: $(RUN_COMMAND)"
	@echo ""
	@echo "CLEAN_COMMAND: $(CLEAN_COMMAND)"
	@echo ""
	@echo "LSP_SYNC_COMMAND: $(LSP_SYNC_COMMAND)"
	@echo ""
	@echo "================================================="
	@echo ""

# make will run the command `make build`,
# and then run the command `make run`
# If the `build` directory already exists and is up to date then `make`
# will skip to executing the `RUN_COMMAND`
run: build
	@$(RUN_COMMAND)

clean:
	@$(CLEAN_COMMAND)

lsp-sync:
	@$(LSP_SYNC_COMMAND)

#______________________________________________________________________________
