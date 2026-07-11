/*
    ABOUT: Singly Linked List - Node

    What's the difference between an array an a linked list?
    1. An array is statically allocated. This means that they have a fixed
    size at compile time.

    Memory for the whole data structure is allocated once at compile time.

    2. A linked list is dynamically allocated. This means that the size
    of the array can vary at run time.

    Memory for the data structure is allocated during run time as nodes
    are added.

    ___________________________________________________________________________

    A single linked list is the simplest form of a linked list.

    A Single Linked list is made up of nodes.

    Each node contains this:
    - Some data
    - The memory address of the next node in the chain.

    The last node contains this:
    - Some data
    - ??

    ___________________________________________________________________________

*/

#include <stdio.h>

// This whole struct is 16 bytes (128 bits) because I'm using 
// a 64 bit machine.
struct Node {
    int data; // 4 bytes (32 bits)

    // 4 bytes of padding are automatically inserted here
    // so that the pointer begins at an address divisible by 8.

    struct Node* next_node; // 8 bytes (64 bits)

                            // On a 32 bit system, this would:
                            // 4 bytes (32 bits)
};

int main() {

    printf("The size of Node is %zu bytes\n", sizeof(struct Node));
    // The size of Node is 16 bytes

    return 0;
}
