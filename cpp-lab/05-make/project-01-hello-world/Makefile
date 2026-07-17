# TARGETS

# How to run commands in a Makefile
# To run the first alias listed in the Makefile, just use the command `make` 

# To run a specific command, the syntax is:
# make `name-of-command`

#______________________________________________________________________________

# This creates an alias called `build` for the command below
# This will compile the program into an object file,
# then use the object file to create an executable file.
build:
	clang++ -c main.cpp -o main.o
	clang++ main.o -o main

#______________________________________________________________________________

# This creates an alias called `build2` for the command below
# This will create an object file
build2:
	clang++ -c main.cpp -o main.o

#______________________________________________________________________________

# This creates an alias called `build3` for the command below
# This will compile the program without creating an object file
build3:
	clang++ main.cpp -o main

#______________________________________________________________________________

# This creates an alias called `execute` for the command below
# To run this command, just use the command `make`
execute:
	./main

# This will remove any file that starts with a .o extension
clean:
	rm -f *.o
	rm -rf main
