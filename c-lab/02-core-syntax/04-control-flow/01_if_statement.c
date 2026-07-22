/*
    ABOUT: if statement

    This is best for handling 1 to 3 potential outcomes


    == equal
    != not equal

    > greater than
    >= greater than or equal

    <= less than or equal




*/

#include <stdio.h>
int main() {

    unsigned int num_apples= 25;

    if (num_apples > 10) {
        printf("\nThere are more than than 10 apples\n\n");
    } else if (num_apples == 10) {
        printf("\nThere are exactly 10 apples\n\n");
    } else {
        printf("\nThere are less than 10 apples\n\n");
    }

    return 0;
}
