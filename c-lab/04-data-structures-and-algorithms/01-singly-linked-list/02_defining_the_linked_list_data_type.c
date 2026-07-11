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

typedef struct LinkedList {
    Node* start_of_list;
    Node* end_of_list;
    int number_of_nodes;
} LinkedList;

// Create list function
LinkedList create_linked_list(int data) {

    LinkedList list;

    Node* new_node = create_new_node(data);

    if (new_node == nullptr) {
        list.start_of_list = nullptr;
        list.end_of_list = nullptr;
        list.number_of_nodes = 0;

        return list;
    }

    list.start_of_list = new_node;
    list.end_of_list = new_node;
    list.number_of_nodes = 1;

    return list;
}

//_____________________________________________________________________________

int main() {

    return 0;
}
