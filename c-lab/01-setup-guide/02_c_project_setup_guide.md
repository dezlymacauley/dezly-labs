# C project setup guide
_______________________________________________________________________________

Create the directory

```bash
mkdir c-project
```
_______________________________________________________________________________

Enter the directory

```bash
cd c-project
```
_______________________________________________________________________________

Create a `mise.toml` file

```bash
touch mise.toml
```
_______________________________________________________________________________

Give mise permission to read the `mise.toml` file

```bash
trust mise.toml
```
_______________________________________________________________________________

Use mise to install the latest version of clang, a compiler for C and C++

```bash
mise use clang@latest
```
_______________________________________________________________________________

Use mise to install the latest version of clang-format, 
a code formatter for C and C++ projects

```bash
mise use clang-format@latest
```
_______________________________________________________________________________

Use mise to install the latest version of `make` to build the project

```bash
mise use make@latest
```
_______________________________________________________________________________

Create the project structure

```bash
mkdir -p src
touch src/main.c
touch .clang-format
touch .clangd
touch .gitignore
touch Makefile
```
_______________________________________________________________________________

Add this to the `.clang-format` file

```yaml
# Tell clang-format that the sytnax in the file is C code
Language: C

# 4 space indentation
IndentWidth: 4

# Lines longer than 80 characters will be wrapped
ColumnLimit: 80

AccessModifierOffset: -4
PointerAlignment: Left
AllowShortFunctionsOnASingleLine: false

# When parameters don't fit on one line, break them all onto the next line
# and place the closing parenthesis on its own line
AlignAfterOpenBracket: BlockIndent
```
_______________________________________________________________________________

Add this to the `.clangd` file

```yaml
CompileFlags:
  Add: [-std=c23, -Iinclude, -Wconversion, -Wunused-variable ]
```

`-std=c23` tells the `clangd` language server to interpret the code using 
the C23 standard.

`-Iinclude` tells the `clangd` language server that the header files of your
project can be found in the directory called `include`.

The two settings above will ensure that you don't get false warnings from
the `clangd` language server.

_______________________________________________________________________________

Add this to the `.gitignore` file

```gitignore
# Build output
bin/
```
_______________________________________________________________________________

Add this ot the Makefile

```bash
NAME := main
VERSION := 0.1.0

CC := clang
CFLAGS := -std=c23 -Wconversion -Wunused-variable

BIN_DIR := bin
TARGET := $(BIN_DIR)/$(NAME)
SRC := src/main.c

.PHONY: all run clean format

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: all
	./$(TARGET)

clean:
	rm -rf $(BIN_DIR)

format:
	clang-format -i src/*.c
```

_______________________________________________________________________________

Add this to the `src/main.c` file

```c
#include <stdio.h>

int main() {
    printf("\nC Project\n\n");
}
```
_______________________________________________________________________________
