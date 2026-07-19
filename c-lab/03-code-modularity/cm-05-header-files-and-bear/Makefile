# ABOUT: Header files and `bear`

# _____________________________________________________________________________

# SECTION: Settings

.SILENT:
.PHONY: build generate-compile-commands run clean

# _____________________________________________________________________________

# SECTION: Tasks

build:
	mkdir -p build/bin/
	mkdir -p build/obj/
	clang -std=c23 -Iinclude -c src/main.c -o build/obj/main.o
	clang -std=c23 -Iinclude -c src/lib.c -o build/obj/lib.o
	clang build/obj/main.o build/obj/lib.o -o build/bin/main

# Run this command anytime you add a new `.h` file to the `include` directory
# This command will generate a `compile_commands.json` file that will help
# clangd understand the project so that you get suggestions when importing
# header files from the `include` directory.
#
# `-- make build`
# bear will use the task `make build` to generate 
# the `compile_commands.json` file.
#
# `--silent build`
# This will hide the build output from being displayed in the terminal
generate-compile-commands:
	bear -- make build --silent build

run:
	./build/bin/main

clean:
	rm -rf .cache/
	rm -rf build/
	rm -f compile_commands.json

# _____________________________________________________________________________
