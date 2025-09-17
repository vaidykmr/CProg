#include <stdio.h>
#include <string.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr)/sizeof(int);

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


    int l = 2, r = 4;

    int sumOfElements = prefixSum[r] - prefixSum[l-1];
    printf("\n The sum of elements between index %d and index %d is %d", l, r, sumOfElements);

    return 0;
}