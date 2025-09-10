#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem1, sem2;

void *print_odd(void *args)
{
    for(int i = 1; i < 10; i+=2)
    {
        sem_wait(&sem1);
        printf("%d \n", i);
        sem_post(&sem2);
        sleep(1);
    }
    return NULL;

}

void *print_even(void *args)
{
    for (int i = 2; i <= 10; i+=2)
    {
        sem_wait(&sem2);
        printf("%d \n", i);
        sem_post(&sem1);
        sleep(1);
    }
    return NULL;
    
}

int main()
{
    pthread_t t1, t2;

    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);

    pthread_create(&t1, NULL, print_odd, NULL);
    pthread_create(&t2, NULL, print_even, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;

}