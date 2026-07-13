/*
    ABOUT: Creating a Linked List
*/

//_____________________________________________________________________________

// SECTION: Node definition

#[derive(Debug)]
struct Node {
    data: i32,
    next_node: Option<Box<Node>>,
}

impl Node {
    fn new(data: i32) -> Self {
        Self {
            data,
            next_node: None,
        }
    }
}

//_____________________________________________________________________________

// SECTION: Linked List definition

#[derive(Debug)]
struct LinkedList {
    number_of_elements: u32,
    start_of_list_pointer: Option<Box<Node>>,
    // end_of_list_pointer: Option<Box<Node>>,
}

impl LinkedList {
    fn new(data: i32) -> Self {

        // Create a new Node 
        let new_node = Node::new(data);

        Self {
            number_of_elements: 1,
            start_of_list_pointer: Some(Box::new(new_node)),
            // end_of_list_pointer: Some(Box::new(new_node)),
        }
    }
}

//_____________________________________________________________________________

fn main() {
    // How to create an instance of a Node
    let node_a = Node::new(10);

    println!("node_a.data = {}", node_a.data);
    println!("node_a.next_node = {:?}", node_a.next_node);
    // node_a.data = 10
    // node_a.next_node = None
}
