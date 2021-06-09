package main

import (
	"fmt"
	"rsc.io/quote"
	"example.com/greetings"
)

func main() {
	fmt.Println("hi there!")
	fmt.Println(quote.Go())
	var message string
	message = greetings.Hello("Gladys")
	fmt.Println(message)
}
