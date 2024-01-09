// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int i = 0;
pthread_mutex_t mut; //mutex
sem_t sem;


void* incrementingThreadFunction(){
    for (int n = 0; n < 1000000; n++){
        // mutex solution
        // pthread_mutex_lock(&mut);
        // ++i;
        // pthread_mutex_unlock(&mut);

        //semaphore solution
        sem_wait(&sem);
        ++i;
        sem_post(&sem);
        }
    return NULL;
}

void* decrementingThreadFunction(){
    for (int n = 0; n < 1000000; n++){
        //mutex solution
        // pthread_mutex_lock(&mut);
        // --i;
        // pthread_mutex_unlock(&mut);

        //semaphore solution
        sem_wait(&sem);
        --i;
        sem_post(&sem);
        }
    return NULL;
}


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    sem_init(&sem, 0, 1);
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