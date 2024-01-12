Exercise 1 - Theory questions
-----------------------------

### Concepts

What is the difference between *concurrency* and *parallelism*?
Parallelism means different actions happen at the same time, on different cores of the processor.
Concurrency means multiple tasks are executed in overlapping time intervals, but not necessarily at the same time. The system switches between different tasks giving the illusion of parallelism.

What is the difference between a *race condition* and a *data race*? 
A race condition means the outcome of a program depends the relative timing of events.
A data race is a specific type of race condition where two or more threads are trying to access the same variable, and atleast one of the threads are trying write. This may lead to undefined behavior.
 
*Very* roughly - what does a *scheduler* do, and how does it do it?
A scheduler in an operating system decides which task or process runs on the CPU at any given moment.


### Engineering

Why would we use multiple threads? What kinds of problems do threads solve?
We can execute more tasks in a shorter span of time.

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they, and why would we rather use them over threads?


Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
> *Your answer here*

What do you think is best - *shared variables* or *message passing*?
> *Your answer here*
