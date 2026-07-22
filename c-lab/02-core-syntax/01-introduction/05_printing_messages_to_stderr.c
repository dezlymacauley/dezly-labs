/*
    ABOUT: Printing message to stderr

*/

// This is a header file
// It allows you to use functions from the C standard library 
#include <stdio.h>

int main(void) {

    puts("Message A");
    puts("Message B");

    // The `fprintf` function allows you to print to stderr
    fprintf(stderr, "Failed to start server\n");
    fprintf(stderr, "Failed to connect to the database\n");

    return 0;
}
