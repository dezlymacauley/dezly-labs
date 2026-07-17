
# This is how to declare a variable
USER_NAME = Dezly Macauley

# The C++ compiler
CXX = clang++

# This is the C++ standard that clang should use to compile the code
CXX_STANDARD = c++20

CXX_WARNINGS = -Wall -Wextra -Wpedantic

#______________________________________________________________________________

# This is how to use a variable
print_user_name:
	echo $(USER_NAME)


build: create-lib.o create-main.o
	clang++ main.o lib.o -std=c++20 -o main
	clang++ -std=c++20 main.o lib.o -o main

create-lib.o:
	clang++ -c lib.cc -o lib.o

create-main.o:
	clang++ -c main.cc -o main.o

execute:
	./main

clean:
	rm -f *.o
	rm -rf main
