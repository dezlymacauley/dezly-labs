# ABOUT: Object files

# _____________________________________________________________________________

# SECTION: Settings

.SILENT:
.PHONY: build run

# _____________________________________________________________________________

# SECTION: Tasks

# -c means compile without linking.
# In simple terms, don't create an executable binary, 
# just create object files
build:
	mkdir -p build/bin/
	mkdir -p build/obj/
	clang -std=c23 -c src/main.c -o build/obj/main.o
	clang build/obj/main.o -o build/bin/main

run:
	./build/bin/main

clean:
	rm -rf build/

# _____________________________________________________________________________
