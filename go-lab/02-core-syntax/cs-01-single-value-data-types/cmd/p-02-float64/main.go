/*

   ABOUT: float64

   This is for floating point numbers

*/

package main

import "fmt"


func main() {
 
    // How to declare a float 64
    var accountBalance float64 = 321.52

    // The format specifier `%.2f` means that accountBalance is a float64,
    // and that only 2 decimals should be shown when it is printed 
    fmt.Printf("accountBalance is %.2f\n", accountBalance)

    // accountBalance is 321.52
}
