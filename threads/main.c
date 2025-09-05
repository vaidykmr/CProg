#include <stdio.h>
#include <pthread.h>

// Thread function for addition
void* add(void* args) {
    int *nums = (int*)args;
    int result = nums[0] + nums[1];
    printf("Addition: %d\n", result);
    return NULL;
}

// Thread function for subtraction
void* sub(void* args) {
    int *nums = (int*)args;
    int result = nums[0] - nums[1];
    printf("Subtraction: %d\n", result);
    return NULL;
}

int main() {
    pthread_t t1, t2;  // thread identifiers
    int nums[2] = {10, 5};

    // create threads
    pthread_create(&t1, NULL, add, (void*)nums);
    pthread_create(&t2, NULL, sub, (void*)nums);

    // wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
