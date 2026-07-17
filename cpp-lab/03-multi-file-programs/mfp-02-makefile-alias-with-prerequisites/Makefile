# This means that the the the instruction `clang++ main.o lib.o -o main`,
# should only be run after `create-lib.o` and `create-main.o` have been run.
build: create-lib.o create-main.o
	clang++ main.o lib.o -o main

# This will compile lib.cc into an object file
create-lib.o:
	clang++ -c lib.cc -o lib.o

# This will compile main.cc into an object file
create-main.o:
	clang++ -c main.cc -o main.o

execute:
	./main

clean:
	rm -f *.o
	rm -rf main
