#include <stdio.h>

void sliding_window(int *arr, int size, int window_length)
{
    int window_sum = 0;
    int count = 0;
    for (int i = 0; i < window_length; i ++)
    {
        window_sum += arr[i];
    }
    count = count + 1;
    printf("Window sum %d : %d", count, window_sum);
    window_sum = 0;
    for (int i = window_length - 1; i <= ((size - window_length) + 1); i++)
    {
        window_sum += arr[i] + arr[i+1] + arr[i-1];
        count ++;
        printf("Window sum %d : %d", count, window_sum);
        window_sum = 0;
    }
}


int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int *arr_ptr = arr;
    int length = sizeof(arr)/sizeof(int);

    int k = 3;

    sliding_window(arr_ptr, length, k);
}