# SECTION: 1 => Environment Variables

# Compiler Settings
COMPILER = clang++
STANDARD = -std=c++20
WARNINGS = -Wall -Wextra -Wpedantic
COMPILER_CALL = $(COMPILER) $(STANDARD) $(WARNINGS)

#______________________________________________________________________________

# SECTION: 2 => If Statements


#______________________________________________________________________________

# SECTION: 3 => Make Commands

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
