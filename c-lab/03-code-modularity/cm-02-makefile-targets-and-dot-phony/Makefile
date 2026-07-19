# ABOUT: Makefile Targets and .PHONY

# A Makefile is a task runner.
# A task is a command that will execute one or multiple commands.

# The correct term in a task in a Makefile, is a `target` because Makefile
# was designed to target files and directories.

# For the rest of this guide, I'll just refer to Makefile targets 
# as Makefile tasks. 

# _____________________________________________________________________________

# The first thing you want to do is to create a safegaurd by using `.PHONY:`, 
# to list all the tasks in your Makefile so that Makefile doesn't confuse
# these tasks with files and directories that have the same name.
# E.g. This project has a task called `build` and a directory called `build` 
.PHONY: build run

# _____________________________________________________________________________

# The syntax is:
# name-of-task:
# 	An action you want to perform
# 	Another action you want to perform

# You run `make name-of-target` and it will run some tasks that you define.

# _____________________________________________________________________________

build:
	mkdir -p build
	clang src/main.c -o build/main

# Now `make build` is the same as running `clang src/main.c -o build/main`

# _____________________________________________________________________________

# Now `make run` is the same as running `./build/main`

run:
	./build/main

# _____________________________________________________________________________
