/*
    ABOUT: Singly Linked List - The `start of list` marker

    The first thing that needs to be created for a Linked List is the start
    of list marker. 

    This list stores the memory address of the first Node in the list,
    or it is set to `nullptr` if the list is empty.

    `nullptr` is short for null pointer. 
    It's a way of expressing that when the list is empty,
    the variable start_of_list does not contain any valid memory address.

    ___________________________________________________________________________

*/

struct Node {
    int data;
    struct Node* next_node;
};

int main() {

    struct Node* start_of_list = nullptr;

    return 0;
}
