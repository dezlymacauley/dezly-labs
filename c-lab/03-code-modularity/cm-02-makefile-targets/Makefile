# EXAMPLE: How to compile a C file into a binary executable

# The syntax is:
# c-compiler file_name.c -o binary_name

# Here's how to compile the `main.c` file in this project into 
# a binary executable called `main`

# clang src/main.c -o build/main

# To run the binary executable, run this command:
# ./build/main

# _____________________________________________________________________________

# ABOUT: Tasks (Makefile Targets)

# A Target is simply another term for an alias, or a script, or a task.
# For the rest of this guide, I'll just refer to Makefile Targets as tasks.

# The syntax is:
# name-of-target:
# 	the action you want to perform
# 	another action you want to perform

# You run `make name-of-target` and it will run some tasks that you define.

build:
	mkdir -p build
	clang src/main.c -o build/main

# Now `make build` is the same as running `clang src/main.c -o build/main`

# Also note that if you just run `make` without specifying a task,
# it will run the first task listed in the Makefile.

# _____________________________________________________________________________

execute:
	./build/main

# _____________________________________________________________________________
