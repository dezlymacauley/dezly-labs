/*
    ABOUT: Singly Linked List - Defining the `Linked List` data type

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

// Required for using the `malloc` function
#include <stdlib.h>

//_____________________________________________________________________________

// SECTION: 1 => Node definition

typedef struct Node {
    int data;
    struct Node* next_node;
} Node;

Node* create_new_node(int data) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node == nullptr) {
        return nullptr;
    }

    new_node->data = data;
    new_node->next_node = nullptr;

    return new_node;
}

//_____________________________________________________________________________

// SECTION: 2 => Linked List definition




//_____________________________________________________________________________

int main() {


    return 0;
}
