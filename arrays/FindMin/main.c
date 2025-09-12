#include <stdio.h>


int findMaxdifference(int arr[], int size)
{
    if (!size)
        return 0;
    
    
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }

        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int maxDiff = max - min;

    return maxDiff;
}

int findLowestDifference(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    int secondMax = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (secondMax < arr[i] && secondMax != max && arr[i] != max)
        {
            secondMax = arr[i];
        }
    }

    int minDiff = max - secondMax;
}
int main()
{
    //int arr[6] = {4, 23, 6, 1, 2, 8};
    int arr[10] = {3, 4, 2, 6, 5, 9, 8, 1, 7, 10};
    int size = sizeof(arr)/sizeof(int);

    int maxDiff = findMaxdifference(arr, size);
    int minDiff = findLowestDifference(arr, size);

    printf("The Max difference in the array = %d \n", maxDiff);
    printf("The Min difference in the array = %d", minDiff);
}