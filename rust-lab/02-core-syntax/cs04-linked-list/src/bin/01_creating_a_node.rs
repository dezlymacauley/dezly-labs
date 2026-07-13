/*
    ABOUT: Creating a Node
*/

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

fn main() {
    // How to create an instance of a Node
    let node_a = Node::new(10);

    println!("node_a.data = {}", node_a.data);
    println!("node_a.next_node = {:?}", node_a.next_node);
    // node_a.data = 10
    // node_a.next_node = None
}
