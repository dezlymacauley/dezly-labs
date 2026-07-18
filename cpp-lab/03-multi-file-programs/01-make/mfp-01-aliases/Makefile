# Targets (Just another term for an alias)

# This will compile main.cc and lib.cc into object files.
# and then it will use both of the object files to generate 
# an executable binary
build:
	clang++ -c main.cc -o main.o
	clang++ -c lib.cc -o lib.o
	clang++ main.o lib.o -o main

execute:
	./main

clean:
	rm -f *.o
	rm -rf main
