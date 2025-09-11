#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void *thread1(void *args)
{
    while (counter < 1000)
    {
        pthread_mutex_lock(&lock);
        if (counter >= 1000)
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
    while (counter < 1000)
    {
        pthread_mutex_lock(&lock);
        if (counter >= 1000)
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

    pthread_mutex_destroy(&lock);

    return 0;
}
