/*
    ABOUT: Defining the `Node` data type

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

int main(void) {

    return 0;
}
