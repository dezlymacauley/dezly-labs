/*
    ABOUT: pointers

    A pointer is a variable that stores the memory address of a value
    or an element.

*/

#include <stdio.h>
int main() {

    unsigned int cakes_available = 32;
    unsigned int* cakes_available_ptr = &cakes_available;
    printf("Value: %u\n", cakes_available);
    printf("Address: %p\n", (void *)cakes_available_ptr);
    printf("Dereferenced: %u\n", *cakes_available_ptr);

    return 0;
}
