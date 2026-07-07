
package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
)

//_____________________________________________________________________________

// SECTION: 1 => Data structures

type Product struct {
	Id       string
	Name     string
	Quantity int
	Price    float64
}

// Creating a temporary database
var ListOfProducts []Product = []Product{
	{
		Id:       "1",
		Name:     "Chair",
		Quantity: 100,
		Price:    100.00,
	},
	{
		Id:       "2",
		Name:     "Desk",
		Quantity: 200,
		Price:    200.00,
	},
}

//_____________________________________________________________________________

// SECTION: 2 => Route Handler Functions

/*
   http.ResponseWriter:
   This is an interface that is used to create a response
   that is sent back to the client when they make a request to `/`

   http:Request
   This is a pointer to a struct that gives you read the information
   that was sent by the client.
*/

// This is a handler for GET requests that have been sent to `/`
func root(response http.ResponseWriter, request *http.Request) {

	// Checking if the response that was sent is a GET request.
	if request.Method != http.MethodGet {
		http.Error(
			response,
			"Method not allowed",
			http.StatusMethodNotAllowed,
		)

		// WARNING: Always remember to add the early return so that the
		// rest of the code in the handler does not run if a request that was
		// not a GET request was sent.
		return
	}

	log.Println("Endpoint hit: /")

	// Stands for `File Print Formatted`
	// Formats a string and writes it to the response writer.
	// Unlike `Println` which which prints to the terminal
	// `Fprintf` sent your meesage directly into the network socket
	// back to the client.

	// The response will be sent back in text form
	fmt.Fprintf(response, "Welcome to the Go API")
}

func products_get(response http.ResponseWriter, request *http.Request) {

	if request.Method != http.MethodGet {
		http.Error(
			response,
			"Method not allowed",
			http.StatusMethodNotAllowed,
		)

		return
	}

	log.Println("Endpoint hit: /products")
	json.NewEncoder(response).Encode(ListOfProducts)
}

// This is a handler for a dynamic route
func product_get_id(response http.ResponseWriter, request *http.Request) {

	if request.Method != http.MethodGet {
		http.Error(
			response,
			"Method not allowed",
			http.StatusMethodNotAllowed,
		)
		return
	}

    log.Println(request.URL.Path)
    // /product/1

    key := request.URL.Path[len("/product/"):]
    log.Println(key)
    // 1

    for _, value := range ListOfProducts {
        if string(value.Id) == key{
            json.NewEncoder(response).Encode(value)
        }
    }

}

func handleRequests() {

	http.HandleFunc("/", root)
	http.HandleFunc("/products", products_get)

    // This is for the dynamic route `/products[id]`
	http.HandleFunc("/product/", product_get_id)

    // TODO: Replace this with a handler function later

	// http.HandleFunc("/product", nil)

	// The server will listen for requests on port 3456,
	// of the network http:127.0.0.1
	// The `ListenAndServe` function accepts the format `ip-address:port`,
	// so leave out the network protocol (http://)
	var networkAddress string = "127.0.0.1:3456"

    fmt.Println()
    fmt.Println("Listening on:")
    fmt.Println("http://127.0.0.1:3456")
    fmt.Println()

	// WARNING: Always remember to wrap the `http.ListenAndServe()`
	// function inside `log.Fatal()`

	// There are two reason:
	// 1. You get notified in the terminal is the server fails to connect
	// to the network address.
	// 2. The program ends immediately,
	// which ensures that the rest of the code in the program only runs
	// if the server is working.

	// The second parameter is a handler
	// If nil is given as the second arguement, then "net/http" from the
	// Go standard library will be used.
	log.Fatal(http.ListenAndServe(networkAddress, nil))
}

//_____________________________________________________________________________

func main() {

	handleRequests()
}
