#include <stdio.h>
#include <pthread.h>

/*
Mutex is needed when we want only one thread to access the shared variable.
This is done because the data stored in heap and global variables are shared
among all the threads. So in order to avoid race condition, we use mutex.

We need mutex when only when there are only two threads and only is allowed to access the shared variable.
But if there is a case where there are multiple threads and we want to protect the shared variable such that
only one thread acces it, then we need semaphores.
*/

int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread1(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        if (counter >= 10)
        {
            pthread_mutex_unlock(&lock);
            break;
        }
        printf("Printing the value of counter %d from thread 1 \n", counter);
        counter ++;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void *thread2(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        if (counter >= 10)
        {
            pthread_mutex_unlock(&lock);
            break;
        }
        printf("Printing the value of counter %d from thread 2 \n", counter);
        counter ++;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Hello world \n");
    pthread_mutex_destroy(&lock);

    return 0;
}
