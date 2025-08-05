#include <stdio.h>

int sliding_window(int *arr, int size, int window_length)
{
    float window_sum = 0.00;
    float previous_window_average = 0.00;
    float current_window_average = 0.00;
    for (int i = 0; i < window_length; i ++)
    {
        window_sum += arr[i];
    }
    previous_window_average = window_sum / window_length; 
    /* window_sum = 0;
    for (int i = window_length - 1; i <= ((size - window_length) + 1); i++)
    {
        window_sum += arr[i] + arr[i+1] + arr[i-1];
        count ++;
        printf("Window sum %d : %d", count, window_sum);
        window_sum = 0;
    }*/

    // alternate solution
    for (int i = window_length; i < size; i++)
    {
        window_sum += arr[i] - arr[i - window_length];
        current_window_average = window_sum / window_length;
        
        if (current_window_average > previous_window_average)
        {
            previous_window_average = current_window_average;
        }
    }

    return previous_window_average;
}


int main()
{
    int arr[7] = {3,5,2,6,4,1,7};
    int *arr_ptr = arr;
    int length = sizeof(arr)/sizeof(int);

    int k = 3;

    float window_avg_max = sliding_window(arr_ptr, length, k);
    printf("%f ", window_avg_max);
}