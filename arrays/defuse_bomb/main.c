#include <stdio.h>
#include <stdlib.h>
int main()
{

    int arr[6] = {1 ,2 , 3, 4, 5, 6};
    int size = sizeof(arr)/sizeof(int);

    int *result_arr = NULL;
    result_arr = (int*)malloc(size * sizeof(int));
    int k = 3;
    int sum = 0;

    if (k > 0)
    {
        for (int i = 0; i < k; i++)
        {
            sum+= arr[i];
        }

        for (int i = 0; i < size; i++)
        {
            sum+= arr[(i+k)% size] - arr[i];
            result_arr[i] = sum;
        }

        for(int i = 0; i < size; i++)
        {
            printf("%d ", result_arr[i]);
        }
    }
    else if (k < 0)
    {
        for (int i = size + k; i < size; i++)
        {
            sum+= arr[i];
        }
        result_arr[0] = sum;

        for (int i = 1; i < size; i++)
        {
            sum += arr[i-1] - arr[((size+k) + (i-1))%size];
            result_arr[i] = sum;
        }

        for(int i = 0; i < size; i++)
        {
            printf("%d ", result_arr[i]);
        }
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            printf("%d ", result_arr[i]);
        }
    }
}