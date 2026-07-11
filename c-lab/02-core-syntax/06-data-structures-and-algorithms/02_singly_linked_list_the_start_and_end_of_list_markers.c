/*
    ABOUT: Singly Linked List - The `start` and `end` of list markers

    The first thing that needs to be created for a Linked List is the start
    of list marker. 

    This list stores the memory address of the first Node in the list,
    or it is set to `nullptr` if the list is empty.

    `nullptr` is short for null pointer. 
    It's a way of expressing that when the list is empty,
    the variable start_of_list does not contain any valid memory address.

    ___________________________________________________________________________
   
    Then you do the same thing for the end_of_list_marker.

    ___________________________________________________________________________
    
    The reason why you need these markers,
    is to keep track of where the list starts and where the list ends as
    Nodes are added and deleted from the list.

    E.g. If you add three Nodes and then delete the first Node,
    then the order of the list changes and `start_of_list` has to be updated
    to store the memory address of the new first Node.

    ___________________________________________________________________________

*/

typedef struct Node {
    int data;
    struct Node* next_node; 
} Node;

int main() {

    Node* start_of_list = nullptr;
    Node* end_of_list = nullptr;

    return 0;
}
