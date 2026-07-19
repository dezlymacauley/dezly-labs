but Make sees generate-main-dot-o as a target that produces 
a file called generate-main-dot-o. 
Since no such file exists, it will run the recipe every time.

### New mindshift.

Make is actually a file creator (and directory creator since everything
is technically a file on Linux) 

target:
    instructions for creating target

E.g. 

main.o:
    instructions for creating main.o

When you run `make main.o`, make checks if that file or directory exists.

If it exists, then make checks if it needs to be updated.

so .PHONY is for things that you want to behave strictly as tasks so disable this behavior
