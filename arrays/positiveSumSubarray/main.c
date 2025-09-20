#include <stdio.h>
#include <limits.h>
#include <string.h>

int main()
{
    int arr[] = {17,-24,5,-10,4,2,4,14};
    int size = sizeof(arr)/sizeof(int);

    int l = 7, r = 8;

    int prefixSum[size];
    memset(prefixSum, 0, sizeof(prefixSum));
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum+= arr[i];
        prefixSum[i] = sum;
    }

    for(int i = 0; i <size; i++)
    {
        printf("%d ",prefixSum[i]);
    }

    int current_sum = prefixSum[l-1];
    int i = l;
    while(i < size && l <= r)
    {
        int latest_sum = prefixSum[i] - prefixSum[i-l];
        if (latest_sum > 0)
        {
            if (latest_sum < current_sum)
                current_sum = latest_sum;
            else if(current_sum <= 0)
                current_sum = latest_sum;
        }
        
        if (i == size - 1)
        {
            if (l == r)
            {
                break;
            }
            else
            {
                l = l + 1;
                int new_sum = prefixSum[l-1];
                i = l;
                if (new_sum > 0 && new_sum < current_sum)
                {
                    current_sum = new_sum;
                }
                else if(current_sum < 0)
                    current_sum = new_sum;
            }
        }
        else 
        {
            i = i + 1;
        }
    }
    if (current_sum > 0)
        printf("\n Output = %d", current_sum);
    else
    {
        current_sum = -1;
        printf("\n Output = %d", current_sum);
    }

    return 0;
}