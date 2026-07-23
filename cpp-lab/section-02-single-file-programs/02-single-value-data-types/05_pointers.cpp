/*

    ABOUT: pointers

    This is for storing the memory address of a variable.

*/

#include <print>
using std::println;

int main() {

    //_________________________________________________________________________

    // EXAMPLE: 1 => Printing a memory address of a variable stored
    // on the stack

    // The variable player_score is stored on the stack
    int player_score = 18;
    println("Player score is located at the memory address:");
    println("{}", static_cast<const void*>(&player_score));

    //_________________________________________________________________________

    // EXAMPLE: 2 => Creating a pointer to a variable stored
    // on the stack

    int* pointer_to_player_score = &player_score;
    println("The memory address stored by pointer_to_player_score is:");
    println("{}", static_cast<const void*>(pointer_to_player_score));

    //_________________________________________________________________________

    // EXAMPLE: 3 => Storing a variable on the heap

    // In this example I want to store an int value of 42 on the heap.

    int* pointer_to_number_on_heap = new int(42);

    println("The memory address stored by pointer_to_number_on_heap is:");
    println("{}", static_cast<const void*>(pointer_to_number_on_heap));

    println(
        "The value at the memory address is {}", *pointer_to_number_on_heap
    );
    
    // The value at the memory address is 42

    //_________________________________________________________________________

    return 0;
}
