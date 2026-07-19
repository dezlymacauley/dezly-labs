# ABOUT: Object files

# _____________________________________________________________________________

# SECTION: Settings

.SILENT:
.PHONY: build run

# _____________________________________________________________________________

# SECTION: Tasks

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
