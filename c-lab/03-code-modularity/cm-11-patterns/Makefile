# ABOUT: Patterns

# _____________________________________________________________________________

# SECTION: Settings

# .SILENT:

.PHONY: build \
        run \
        clean

# _____________________________________________________________________________

# SECTION: Variables

CC = clang

C_STANDARD = c23

C_WARNINGS = -Wall -Wextra -Wpedantic

CFLAGS = -std=$(C_STANDARD) -Iinclude $(C_WARNINGS)

C_COMPILER_CALL = $(CC) $(CFLAGS)

# _____________________________________________________________________________

DEBUG = 1

ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
else
	CFLAGS += -O3
endif

# _____________________________________________________________________________

EXECUTABLE_NAME = main

C_OBJECTS = build/obj/lib.o build/obj/main.o

# _____________________________________________________________________________

# SECTION: Tasks

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

run: build
	./build/bin/main

clean:
	rm -rf .cache/
	rm -rf build/
	rm -f compile_commands.json

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
