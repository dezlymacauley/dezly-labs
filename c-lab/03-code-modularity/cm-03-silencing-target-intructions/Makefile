# ABOUT: Silencing target instructions

# mkdir -p build
# clang src/main.c -o build/main

# ./build/main
# Hello world!

# _____________________________________________________________________________

# Method 1 - Fine-grained control

# Just place an `@` sign before each line

# clean:
# 	@rm -f $(BINARY_EXECUTABLE_NAME)
# 	@rm -f $(OBJECT_FILES_LIST)

#______________________________________________________________________________

# Method 2 - To silence the entire file,
# Make sure that the line below is the first uncommented line in the Makefile
# `.SILENT:`

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
