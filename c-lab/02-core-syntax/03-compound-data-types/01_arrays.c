/*
    ABOUT: arrays

    An array stores multiple elements contiguously in memory.
    All of the elements of an array must be of the same data type.

*/

#include <stdio.h>
int main() {

    int player_scores[5] = {10, 20, 30};
    
    printf("The first element is %i\n", player_scores[0]);
    printf("The second element is %i\n", player_scores[1]);
    printf("The third element is %i\n", player_scores[2]);
    // The first element is 10
    // The second element is 20
    // The third element is 30
}
