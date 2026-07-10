/*
    ABOUT: Structs
*/

#include <stdio.h>

struct Person {
    int age;
    float height;
};

int main(void) {

    struct Person alice = {
        .age = 25,
        .height = 1.72f,
    };

    printf("alice.age = %i\n", alice.age);
    printf("alice.height = %.2f\n", alice.height);
}
