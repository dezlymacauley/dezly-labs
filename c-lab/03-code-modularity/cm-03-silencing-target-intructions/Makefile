# ABOUT: Silencing target instructions

# _____________________________________________________________________________

# SECTION: Settings

.SILENT:
.PHONY: build run

# _____________________________________________________________________________

# SECTION: Tasks

# When you run `make` build,
# It will display each command used in a task. 
# To silence this output, just put an `@` symbol before each command

# If you want a quicker way to apply this to the entire file,
# just add `.SILENT:` to the very top of the file

build:
	mkdir -p build
	clang src/main.c -o build/main

run:
	./build/main

# _____________________________________________________________________________
