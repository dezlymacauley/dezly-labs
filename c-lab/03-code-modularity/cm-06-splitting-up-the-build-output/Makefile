# ABOUT: Splitting up the build output

# _____________________________________________________________________________

# SECTION: Settings

.SILENT:

.PHONY: build \
        generate-lib-dot-o \
        generate-main-dot-o \
        generate-compile-commands \
        run \
        clean

# _____________________________________________________________________________

# SECTION: Tasks

# When you run the `make build`,
# make will first run `make generate-lib-dot-o`,
# then it will run `make generate-main-dot-o`,
# then it will create the directory `build/bin/`,
# and finally it will use the object files to create a binary executable
# called `main` inside the `build/bin/` directory.
build: generate-lib-dot-o generate-main-dot-o
	mkdir -p build/bin/
	clang build/obj/main.o build/obj/lib.o -o build/bin/main

# This will generate the `build/obj/lib.o` object file
generate-lib-dot-o:
	mkdir -p build/obj/
	clang -std=c23 -Iinclude -c src/lib.c -o build/obj/lib.o

# This will generate the `build/obj/main.o` object file
generate-main-dot-o:
	mkdir -p build/obj/
	clang -std=c23 -Iinclude -c src/main.c -o build/obj/main.o

generate-compile-commands:
	bear -- make build --silent build

run:
	./build/bin/main

clean:
	rm -rf .cache/
	rm -rf build/
	rm -f compile_commands.json

# _____________________________________________________________________________
