/*
    ABOUT: Printing message to stdout

*/



// The line `#include <stdio.h>` is called a preprocessor directive.
// Preprocessor directives start with the symbol `#`.

// The purpose of the preprocessor is to read the text in a file 
// that contains a preprocessor directive and then modify that text before
// the program is compiled. It's important to not that these changes are not
// saved to the file.

// This is a header file. Header files start with `.h` 
// It allows you to use functions from the C standard library 
// like `puts` and `printf`
#include <stdio.h>

// Every executable C program must have a function called `main`.
// or your code won't compile.
int main(void) {

    // Use the `puts` function when you want to print simple messages
    // that don't have any variables.
    // `puts` automatically prints to stdout.
    // `puts` automatically adds a `newline character

    // This is called the function invocation.
    // The syntax:
    // function-name(required arguments);
    // Each instruction must end with a semicolon.
    // The function name `puts`, is short for `Put String`
    puts("Message A");
    puts("Message B");
  
    // This is how you declare a variable in C
    // The syntax is:
    // data_type name = value;
    int cakes_available = 2;
    
    // Use the `printf` when you want to print a message 
    // that needs to display the value of a variable.
    // Unlike `puts`, `printf` requires you to manually 
    // add the newline character. `\n`
    printf("The value of cakes_available is: %i\n", cakes_available);

    return 0;
}
