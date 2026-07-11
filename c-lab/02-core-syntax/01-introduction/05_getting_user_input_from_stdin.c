/*
    ABOUT: Getting user input from stdin

*/

#include <stdio.h>

int main(void) {

    // This creates a variable to store the user's age
    // when the `scanf` function is used.
    unsigned int user_age = 0;

    puts("Enter your age: ");
    scanf("%i", &user_age);
    printf("Your age is: %i\n", user_age);
    // Your age is: 32

    return 0;
}
