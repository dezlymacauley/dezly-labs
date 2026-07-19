// Every Go program must start with a package declaration
// The syntax is:
// package packagename
// The naming convention for a package name is lowercase without any hyphens,
// or undercores
// `package main` means that this is an executable program
package main

// This imports the `fmt` package from Go's standard library
import "fmt"

// This is a function called `main`. 
// Go uses this to determine the entry point of the program.
// When you run a Go program, Go will call the main function.
func main() {

    // This is how to use Println from the fmt package
    fmt.Println("Program 01")
}

