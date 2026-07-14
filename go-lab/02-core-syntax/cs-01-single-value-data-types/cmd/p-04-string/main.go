/*

   ABOUT: string

   This is for string values.

*/

package main

import "fmt"

func main() {

	// This is how you declare a string in Go
	var userName string = "dezlymacauley"
	var displayName string = "Dezly Macauley"

	// The format specifier for a string is `%s`
	fmt.Printf("userName is %s\n", userName)
	fmt.Printf("displayName is %s\n", displayName)

	// userName is dezlymacauley
	// displayName is Dezly Macauley
}
