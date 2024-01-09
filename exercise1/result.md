# Results
## Task 3
Both in C and in Go the magic number at the end of the program varies a lot. One would expect the result to be 0, but this is not the case.  
As both threads increment and decrement at the same time, and they also shared the variable they are incrementing/decrementing, the result will vary depending on factors like processor speed (i think, i dont actually know what factors impact the result) and stuff. This is because they might read the value of i at the same time, and the function which writes the incremented/decremented value last will "decide" the resulting value.
The solution to this is either by introducing a bottleneck, which will remove the concurrency in our program (BAD!!) or by making the threads unable to share resources.

## Task 4
### C
Semaphores are variables that can be accessed by multiple threads at the same time. Mutex is a specific kind of binary semaphore which provides a locking mechanism to the semaphore. This means that the value of the mutex is locked while a thread is accessing it, leading to other threads having to wait their turn until they can access the data.
I believe using a mutex will be a good solution for the problem at hand. (After further research i believe the semaphore will work just as well.)
