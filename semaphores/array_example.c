#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;
#define MAX_SIZE 10
int index = 0;
int arr[MAX_SIZE];

void *thread1(void *args)
{
    while(1)
    {
        sem_wait(&sem);
        if (index >= MAX_SIZE)
        {
            sem_post(&sem);
            break;
        }

        arr[index] = 1;
        printf("Printing from thread 1 with index = %d and printing %d \n", index, arr[index]);
        index = index + 1;

        sem_post(&sem);
        sleep(1);
    }

    return NULL;
}


void *thread2(void *args)
{
    while(1)
    {
        sem_wait(&sem);
        if (index >= MAX_SIZE)
        {
            sem_post(&sem);
            break;
        }
        arr[index] = 2;
        printf("Printing from thread 2 with index = %d and printing %d \n", index, arr[index]);
        index = index + 1;
        sem_post(&sem);
        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&sem, 0, 1);

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);

    return 0;

}