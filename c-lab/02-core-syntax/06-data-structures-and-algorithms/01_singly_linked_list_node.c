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

#include <stdlib.h>
#include <stdio.h>

// This whole struct is 16 bytes (128 bits) because I'm using 
// a 64 bit machine.
typedef struct Node {
    int data; // 4 bytes (32 bits)

    // 4 bytes of padding are automatically inserted here
    // so that the pointer begins at an address divisible by 8.

    struct Node* next_node; // 8 bytes (64 bits)

                            // On a 32 bit system, this would:
                            // 4 bytes (32 bits)
} Node;

// C does not have constructors. 
// You have to create one manually with a function that will create a new
// node in heap memory, and return the memory address of the Node that was
// created.

/*
    This function will return either *Node or nullptr 

    Node*       If the Node was created successfully

    nullptr     If the Node could not be created 
                due to a memory allocation failure 
                by the malloc function.
*/
Node* create_new_node(int data) {

    // Since this is heap allocation, 
    // you first have to use malloc to allocate enough memory on the heap
    // to store the Node.
    
    // In this case, malloc will allocate 16 bytes because the Node data type
    // is 16 bytes.
    Node* new_node = malloc(sizeof(Node));

    // Check if the memory was allocated successfully.
    if (new_node == nullptr) {
        return nullptr;
    }

    new_node->data = data;
    new_node->next_node = nullptr;

    return new_node;
}

int main() {

    printf("The size of each Node is %zu bytes\n", sizeof(Node));
    // The size of Node is 16 bytes

    return 0;
}
