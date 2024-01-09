// Use `go run foo.go` to run your program

package main

import (
    . "fmt"
    "runtime"
    //"time"
)

var i = 0
var sel = ""
var incdone_ch, decdone_ch, quit chan bool
var action_ch chan string

func init(){
	incdone_ch = make(chan bool)
	decdone_ch = make(chan bool)

	action_ch = make(chan string)
	quit = make(chan bool)
}

func incrementing() {
    //TODO: increment i 1000000 times
	for n := 0; n < 1000000; n++ {
		action_ch <- "inc"
	}
	incdone_ch <- true
}

func decrementing() {
    //TODO: decrement i 1000000 times
	for n := 0; n < 1000000; n++ {
		action_ch <- "dec"
	}
	decdone_ch <- true
}

func server(){
	for {
		select {
		case sel := <- action_ch:
				if sel == "inc"{
					i++
				} else if sel == "dec"{
					i--
				}
			case <- quit:
				break
		}
	}
}

func main() {
    // What does GOMAXPROCS do? What happens if you set it to 1?
    runtime.GOMAXPROCS(2)    
	
    // TODO: Spawn both functions as goroutines
	go incrementing()
	go decrementing()
	go server()
	<- incdone_ch
	<- decdone_ch
	quit <- true

	
    // We have no direct way to wait for the completion of a goroutine (without additional synchronization of some sort)
    // We will do it properly with channels soon. For now: Sleep.
    //time.Sleep(500*time.Millisecond)
    Println("The magic number is:", i)
}
