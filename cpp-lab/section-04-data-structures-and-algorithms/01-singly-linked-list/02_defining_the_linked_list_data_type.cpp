/*
    ABOUT: Definining the `Linked List` data type

*/

struct Node {
    public:
    int node_data;
    Node* next_node;

    // This is a constructor
    Node(int value) {
        this->node_data = value;
        this->next_node = nullptr;
    }
};

struct LinkedList {
    private:
    Node* start_of_list;
    Node* end_of_list;
    int number_of_nodes;

    public:
    // This is a constructor
    LinkedList(int value) {
        Node* newNode = new Node(value);
        this->start_of_list = newNode;
        this->end_of_list = newNode;
        this->number_of_nodes = 1;
    }
};
