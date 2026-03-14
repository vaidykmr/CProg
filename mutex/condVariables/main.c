#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


/*
A simple experiment to understand the concept of condition variable and mutex
Created two threads, main and worker under single process.
*/

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int ready = 0;  //global variable, shared among all the threads

void *worker(void *arg)
{
    pthread_mutex_lock(&mutex);

    while(!ready)
    {
        printf("Not ready, Worker thread going to sleep \n");
        pthread_cond_wait(&cond, &mutex);
        printf("Worker thread woke up and check the shared variable again\n");
    }
    
    pthread_mutex_unlock(&mutex);   // Release the lock since the condition satisfied

    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL,worker,NULL);
    
    sleep(2);

    pthread_mutex_lock(&mutex);
    ready = 1;

    printf("Set ready, wake up the worker thread \n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    pthread_join(tid, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
