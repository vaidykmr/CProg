#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem, lock;
#define MAX_SIZE 10
int index = 0;
int arr[MAX_SIZE];

void *thread1(void *args)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        sem_wait(&lock);
        if (index < MAX_SIZE)
        {
            index = index + 1;
            arr[index] = 10*index;
            printf("Write the value %d at index %d \n", arr[index], index);
        }
        sem_post(&sem);
        sem_post(&lock);
        sleep(1);
    }

    return NULL;
}


void *thread2(void *args)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        sem_wait(&sem);
        sem_wait(&lock);
        if (index < MAX_SIZE)
        {
            int val = arr[index];
            printf("Read the value %d at index %d \n", val, index);
            index = index - 1;
        }

        sem_post(&lock);
        sleep(2);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&sem, 0, 0);
    sem_init(&lock, 0, 1);

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);
    sem_destroy(&lock);

    return 0;

}