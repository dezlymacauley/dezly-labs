# ABOUT: Additional Flags

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

build: generate-lib-dot-o generate-main-dot-o
	mkdir -p build/bin/
	clang -std=23 -Iinclude -Wall -Wextra -Wpedantic build/obj/main.o build/obj/lib.o -o build/bin/main

generate-lib-dot-o:
	mkdir -p build/obj/
	clang -std=c23 -Iinclude -Wall -Wextra -Wpedantic -c src/lib.c -o build/obj/lib.o

generate-main-dot-o:
	mkdir -p build/obj/
	clang -std=c23 -Iinclude -Wall -Wextra -Wpedantic -c src/main.c -o build/obj/main.o


generate-compile-commands:
	bear -- make build --silent build

run:
	./build/bin/main

clean:
	rm -rf .cache/
	rm -rf build/
	rm -f compile_commands.json

# _____________________________________________________________________________
