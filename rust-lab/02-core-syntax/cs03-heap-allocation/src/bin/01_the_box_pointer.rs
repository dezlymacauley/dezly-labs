/*
    ABOUT: The `Box` pointer

    This is used when you want to store a value in heap memory.
*/

fn main() {

    // The data type of `pointer_to_number` is Box<i32>.

    // `Box` is a pointer. This means that is stores the memory address
    // of where an element is located on the heap.
    
    // `Box<i32>` means that the element that is stored on the heap is an
    // i32 number.

    // So to be clear, The `Box` is stored on the stack because pointers have
    // a fixed sized, and the contents of the Box are stored on the heap.
    let pointer_to_number: Box<i32> = Box::new(18);

    println!("The content of the Box is:");
    println!("{}", *pointer_to_number);
    // The content of the Box is:
    // 18

    println!("The memory address stored by the Box is:");
    println!("{:p}\n", &*pointer_to_number);
    // The memory address stored by the Box is:
    // 0x556297fb8d50

}
