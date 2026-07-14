/*

   ABOUT: pointer

*/

package main

import "fmt"

func main() {

	//_________________________________________________________________________

	// EXAMPLE: 1 => Printing the memory address of a variable

	var cakesAvailable int = 15

    // The format specifier for printing a memory address is `%p`
    // The ampersand symbol `&`, means memory address of.
    // So &cakesAvailable means `memory address of cakesAvailable`
	fmt.Printf("The value of cakesAvailable is stored at the address:\n")
	fmt.Printf("%p\n", &cakesAvailable)
    fmt.Printf("\n")

	//_________________________________________________________________________

	// EXAMPLE: 2 => Creating a pointer to an existing variable

    // The data type `*int` means `pointer to an int`
    // A pointer is a variable that stores the memory address of where 
    // a value is stored in memory.

	var pointerToCakesAvailable *int = &cakesAvailable

    // Since a pointer is a variable that stores a memory address,
    // you use the format specifier `%p` to print the memory address.
    fmt.Printf("pointerToCakesAvailable stores the memory address:\n")
    fmt.Printf("%p\n", pointerToCakesAvailable)

	//_________________________________________________________________________

}
