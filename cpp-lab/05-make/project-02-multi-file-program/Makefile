# This will compile main.cpp and lib.cpp into object files.
# and then it will use boh of the object files to generate 
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
