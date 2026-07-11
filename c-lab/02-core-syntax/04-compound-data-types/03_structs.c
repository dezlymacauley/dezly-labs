/*
    ABOUT: Structs

*/

#include <stdio.h>

// A struct is declared outside a function
typedef struct Person {
    int age; // 4 bytes (32 bits)
    float height; // 4 bytes (32 bits)
} Person;

// typedef creates an alias for `struct Person`,
// so that you can just use `Person` as a data type.

int main(void) {

    //_________________________________________________________________________
    
    // EXAMPLE: 1 => Printing the size of a struct in bytes

    printf("The size of person_one is %zu bytes\n", sizeof(Person));
    // The size of person_one is 8 bytes

    //_________________________________________________________________________
    
    // EXAMPLE: 2 => Creating an instance of a struct

    Person person_one = {
        .age = 25,
        .height = 1.72f,
    };

    printf("person_one.age = %i\n", person_one.age);
    printf("person_one.height = %.2f\n", person_one.height);

    //_________________________________________________________________________

    // EXAMPLE: 3 => Creating a pointer to a struct.

    // The variable memory_address_of_person_one stores the memory address
    // of where the variable person_one is stored in memory.

    // A variable that stores the memory address of another variable
    // is called a pointer.
    //
    // The data type of memory_address_of_person_one,
    // is `struct Person*`. This means "a pointer to a Person struct"
    // `&person_one` is how you tell C that you want to store
    // the memory address of person_one, and not its value.
    Person* memory_address_of_person_one = &person_one;

    //_________________________________________________________________________

    // EXAMPLE: 4 => Printing the memory address of a struct.

    printf(
        "memory_address_of_person_one: %p\n",
        (void*)memory_address_of_person_one
    );
    // memory_address_of_person_one: 0x7ffdb7d8ecc8

    //_________________________________________________________________________

    // EXAMPLE: 5 => Printing the value of a struct using a pointer

    printf("person_one.age: %i\n", memory_address_of_person_one->age);
    printf("person_one.height: %.2f\n", memory_address_of_person_one->height);
    // person_one.age: 25
    // person_one.height: 1.72

    //_________________________________________________________________________
}
