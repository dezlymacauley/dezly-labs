# This creates an alias called `build` for the command below
# This will compile the program into an object file,
# then use the object file to create an executable file.
build:
	clang++ -c main.cc -o main.o
	clang++ main.o -o main

# This creates an alias called `execute` for the command below
# To run this command, just use the command `make`
execute:
	./main

# This will remove any file that starts with a .o extension,
# and the binary executable
clean:
	rm -f *.o
	rm -rf main
