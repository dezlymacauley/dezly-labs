# SECTION: 1 => Makefile Settings

.PHONY: settings \
        run \
        clean 
# _____________________________________________________________________________

# SECTION: 2 => Compiler Settings

COMPILER = clang
LANGUAGE_STANDARD_FLAG = -std=c23
HEADER_DIRECTORY_FLAGS = -Iinclude
COMPILER_WARNING_FLAGS = -Wall -Wextra -Wpedantic

CREATE_BIN_COMMAND = $(COMPILER) \
			 $(LANGUAGE_STANDARD_FLAG) \
			 $(HEADER_DIRECTORY_FLAGS) \
			 $(COMPILER_WARNING_FLAGS)

CREATE_OBJECT_COMMAND = $(CREATE_BIN_COMMAND) -c

# _____________________________________________________________________________

# SECTION: 3 => Project Structure

SOURCE_FILE_DIRECTORY = src
SOURCE_FILES = $(wildcard $(SOURCE_FILE_DIRECTORY)/*.c)

OBJECT_FILE_DIRECTORY = build/obj
OBJECT_FILES = $(patsubst $(SOURCE_FILE_DIRECTORY)/%.c, $(OBJECT_FILE_DIRECTORY)/%.o, $(SOURCE_FILES))

BIN_FILE_DIRECTORY = build/bin
BIN_FILE_NAME = main
BIN_FILE_PATH = $(BIN_FILE_DIRECTORY)/$(BIN_FILE_NAME)

RUN_COMMAND = ./$(BIN_FILE_PATH)
CLEAN_COMMAND = rm -rf .cache/ build/ compile_commands.json

#______________________________________________________________________________

# SECTION: 3 => Makefile Targets (Files that need to be created or updated)

build/obj/lib.o: $(SOURCE_FILE_DIRECTORY)/lib.c
	mkdir -p $(OBJECT_FILE_DIRECTORY)
	$(CREATE_OBJECT_COMMAND) \
		$(SOURCE_FILE_DIRECTORY)/lib.c -o $(OBJECT_FILE_DIRECTORY)/lib.o

build/obj/main.o: $(SOURCE_FILE_DIRECTORY)/main.c
	mkdir -p $(OBJECT_FILE_DIRECTORY)
	$(CREATE_OBJECT_COMMAND) \
		$(SOURCE_FILE_DIRECTORY)/main.c -o $(OBJECT_FILE_DIRECTORY)/main.o

build: $(BIN_FILE_PATH)

$(BIN_FILE_PATH): $(OBJECT_FILES)
	mkdir -p $(BIN_FILE_DIRECTORY)
	$(CREATE_BIN_COMMAND) \
		$(OBJECT_FILES) -o $(BIN_FILE_PATH)

compile_commands.json:
	bear -- make build --silent

# _____________________________________________________________________________

# SECTION: 4 => Makefile Tasks (Custom Commands)

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
	@echo "================================================="
	@echo ""

run: build
	$(RUN_COMMAND)

clean:
	$(CLEAN_COMMAND)
# _____________________________________________________________________________
