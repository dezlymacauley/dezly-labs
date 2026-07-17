# This means that the the the instruction `clang++ main.o lib.o -o main`,
# should only be run after `create_lib.o` and `create_main.o` have been run.
build: create_lib.o create_main.o
	clang++ main.o lib.o -o main

# This will compile lib.cc into an object file
create_lib.o:
	clang++ -c lib.cc -o lib.o

# This will compile main.cc into an object file
create_main.o:
	clang++ -c main.cc -o main.o

execute:
	./main

clean:
	rm -f *.o
	rm -rf main
