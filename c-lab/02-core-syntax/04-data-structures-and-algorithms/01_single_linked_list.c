/*
    ABOUT: Single Linked List

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

struct node {
    int data;
    struct node* next_node;
};

int main() {
    return 0;
}
