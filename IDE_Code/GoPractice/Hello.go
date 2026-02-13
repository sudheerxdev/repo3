package main

import (
    "fmt"
    "time"
)

// This function will run as a separate goroutine
func worker(id int, jobs <-chan int, results chan<- int) {
    for j := range jobs {
        fmt.Println("worker", id, "started job", j)
        time.Sleep(time.Second) // Simulate some work
        fmt.Println("worker", id, "finished job", j)
        results <- j * 2 // Send the result back to the results channel
    }
}

func main() {
    // Create channels for jobs and results
    jobs := make(chan int, 100)
    results := make(chan int, 100)

    // Start 3 worker goroutines
    for w := 1; w <= 3; w++ {
        go worker(w, jobs, results)
    }

    // Send 5 jobs to the jobs channel
    for j := 1; j <= 5; j++ {
        jobs <- j
    }
    close(jobs) // Close the jobs channel to signal no more jobs are coming

    // Collect all the results from the results channel
    for a := 1; a <= 5; a++ {
        <-results
    }
    // All results collected, main function can exit
}
