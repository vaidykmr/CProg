#include <stdio.h>
#include <limits.h>
#include <string.h>

int main()
{
    int arr[] = {-2, 2, -3, 1};
    int size = sizeof(arr)/sizeof(int);

    int l = 2, r = 3;

    int prefixSum[size+1];
    memset(prefixSum, 0, sizeof(prefixSum));
    prefixSum[0] = 0;
    for(int i = 1; i <= size; i++)
    {
        prefixSum[i] = arr[i-1] + prefixSum[i-1];
    }

    for(int i = 0; i <size+1; i++)
    {
        printf("%d ",prefixSum[i]);
    }

    int current_sum = INT_MAX;
    int i = l;
    while(i <= size && l <= r)
    {
        int latest_sum = prefixSum[i] - prefixSum[i-l];
        if (latest_sum > 0 && latest_sum < current_sum)
        {
            current_sum = latest_sum;
        }
        
        if (i == size)
        {
            if (l == r)
            {
                break;
            }
            else
            {
                l = l + 1;
                i = l;
            }
        }
        else
            i++;
    }
    if (current_sum > 0 && current_sum != INT_MAX)
        printf("\n Output = %d", current_sum);
    else
    {
        current_sum = -1;
        printf("\n Output = %d", current_sum);
    }

    return 0;
}