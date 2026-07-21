# SECTION: 1 => Makefile Settings

.PHONY: help \
		settings \
        run \
        clean \
		setup

#______________________________________________________________________________

# SECTION: 2 => Compiler Settings

COMPILER = clang
LANGUAGE_STANDARD_FLAG = -std=c23
HEADER_DIRECTORY_FLAGS = -Iinclude
COMPILER_WARNING_FLAGS = -Wall -Wextra -Wpedantic

#______________________________________________________________________________

# SECTION: 3 => Project Structure

SOURCE_FILE_DIRECTORY = src
SOURCE_FILES = $(wildcard $(SOURCE_FILE_DIRECTORY)/*.c)

BIN_FILE_DIRECTORY = build/bin
BIN_FILE_NAME = main
BIN_FILE_PATH = $(BIN_FILE_DIRECTORY)/$(BIN_FILE_NAME)

RUN_COMMAND = ./$(BIN_FILE_PATH)

CLEAN_COMMAND = rm -rf .cache/ build/ compile_commands.json
SETUP_COMMAND= ninja -t compdb cc > compile_commands.json

#______________________________________________________________________________

# SECTION: 4 => Makefile Targets (Files that need to be created or updated)

setup:
	@$(SETUP_COMMAND)
#______________________________________________________________________________

# SECTION: 5 => Makefile Tasks (Custom Commands)

help:
	@echo ""
	@echo "Available Commands"
	@echo "================================================="
	@echo ""
	@echo "🔨 make build"
	@echo "    Incrementally builds the project via Ninja."
	@echo ""
	@echo "✅ make run"
	@echo "    Builds the project if necessary and runs it."
	@echo ""
	@echo "🧼 make clean"
	@echo "    Removes all build artifacts."
	@echo ""
	@echo "🔁 make setup"
	@echo "    Regenerates compile_commands.json for clangd via Ninja."
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
	@echo "================================================="
	@echo ""
	@echo "Project Structure"
	@echo "================================================="
	@echo ""
	@echo "Source File Directory: $(SOURCE_FILE_DIRECTORY)"
	@echo ""
	@echo "Source Files: $(SOURCE_FILES)"
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

run: build
	@$(RUN_COMMAND)

clean:
	@$(CLEAN_COMMAND)

lsp-sync:
	@$(LSP_SYNC_COMMAND)
