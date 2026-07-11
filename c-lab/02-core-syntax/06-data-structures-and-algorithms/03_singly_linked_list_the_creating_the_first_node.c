/*
    ABOUT: Singly Linked List - Creating the first Node in the list

    ___________________________________________________________________________

*/

#include <stdlib.h>

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

int main() {

    Node* start_of_list = nullptr;
    Node* end_of_list = nullptr;

    return 0;
}
