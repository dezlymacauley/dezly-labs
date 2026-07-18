# SECTION: 1 => Build Settings 

# Build Settings
COMPILER = clang++
STANDARD = -std=c++20
WARNINGS = -Wall -Wextra -Wpedantic
BUILD_MODE = DEBUG
COMPILER_CALL = $(COMPILER) $(STANDARD) $(WARNINGS)


# Debug Settings
DEBUG_MODE = true

# This is how you declare a variable as an empty string
DEBUG_MODE_STATUS_MESSAGE = 

#______________________________________________________________________________

# SECTION: 2 => If Statements

ifeq ($(DEBUG_MODE), true)
	DEBUG_MODE_STATUS_MESSAGE = Debug mode is enabled

else
	DEBUG_MODE_STATUS_MESSAGE = Debug mode is disabled 
endif

#______________________________________________________________________________

# SECTION: 3 => Makefile Commands

# print-debug-mode-status-message:
# 	echo $(DEBUG_MODE_STATUS_MESSAGE)
#
# print-build-mode:
# 	@echo $(BUILD_MODE_STATUS_MESSAGE)

# Creates the `lib.o` and `main.o` object files,
# and then uses both object files to create a binary executable called `main`
build: create-lib.o create-main.o
	$(COMPILER_CALL) main.o lib.o -o main

# Creates the `lib.o` object file
create-lib.o:
	$(COMPILER_CALL) -c lib.cc -o lib.o

# Creates the `main.o` object file
create-main.o:
	$(COMPILER_CALL) -c main.cc -o main.o

# Runs the binary executable
run:
	./main

# Deletes the binary executable and all object files
clean:
	rm -f main
	rm -f *.o
