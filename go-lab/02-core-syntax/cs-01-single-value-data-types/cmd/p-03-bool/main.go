/*

   ABOUT: bool

   This is for boolean values.

*/

package main

import "fmt"

func main() {

    // This is how you declare a bool
	var isLoggedIn bool = true
	var hasAdminAcess bool = false

	// The format specifier for bool is `%t`
	fmt.Printf("isLoggedIn is %t\n", isLoggedIn)
	fmt.Printf("hasAdminAcess is %t\n", hasAdminAcess)

    // isLoggedIn is true
    // hasAdminAcess is false
}
