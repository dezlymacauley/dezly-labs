# Declaring Variables

# This is how to declare a variable
# You don't need to add quotation marks because the value is always treated
# as a string.
USER_NAME = Dezly Macauley
USER_ID = 83232

# The C++ compiler
COMPILER = clang++

# I'm using the C++ 20 standard because that is what Google recommends 
# in their style guide
STANDARD = -std=c++20

WARNINGS = -Wall -Wextra -Wpedantic

# How to create a variable that uses other variables
COMPILER_CALL = $(COMPILER) $(STANDARD) $(WARNINGS)

#______________________________________________________________________________

print-compiler-call:
	echo $(COMPILER_CALL)

# This is how to use a variable
print-user-name:
	echo $(USER_NAME)

print-user-id:
	echo ${USER_ID}

build: create-lib.o create-main.o
	$(COMPILER_CALL) main.o lib.o -o main
	$(COMPILER_CALL) main.o lib.o -o main

create-lib.o:
	$(COMPILER_CALL) -c lib.cc -o lib.o

create-main.o:
	$(COMPILER_CALL) -c main.cc -o main.o

execute:
	./main

clean:
	rm -f *.o
	rm -rf main
