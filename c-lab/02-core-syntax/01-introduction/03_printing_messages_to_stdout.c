/*
    ABOUT: Printing message to stdout

*/

// This is a header file
// It allows you to use functions from the C standard library 
// like `puts` and `printf`
#include <stdio.h>

int main(void) {

    // Use the `puts` function when you want to print simple messages
    // that don't have any variables.
    // `puts` automatically prints to stdout.
    // `puts` automatically adds a `newline character
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
