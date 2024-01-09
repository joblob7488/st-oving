// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>

int i = 0;


void* incrementingThreadFunction(){
    for (int n = 0; n < 1000000; n++){++i;}
    return NULL;
}

void* decrementingThreadFunction(){
    for (int n = 0; n < 1000000; n++){--i;}
    return NULL;
}


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    pthread_t thread1;
    pthread_t thread2;
    
    pthread_create(&thread1, NULL, incrementingThreadFunction, NULL);
    pthread_create(&thread2, NULL, decrementingThreadFunction, NULL);

    // TODO:
    // wait for the two threads to be done before printing the final result
    // Hint: Use `pthread_join`    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}