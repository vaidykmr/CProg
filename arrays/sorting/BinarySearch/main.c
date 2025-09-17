// First perform quick sort and then do binary search

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int partition(int arr[], int low, int high)
{
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if(arr[j] < arr[high])
        {
            i = i+1;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return (i+1);

}


void quickSort(int nums[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);

        quickSort(nums, low, pi-1);
        quickSort(nums, pi+1, high);
    }
}

int binarySearch(int arr[], int target, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {5,3,7,4,8,1,2,10,6,9};
    int size = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, size-1);

    // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    int number = 7;
    int index = binarySearch(arr, number, 0, size-1);

    if (index != -1)
        printf("\n Found at index = %d", index);
    else
        printf("\n Not found.");

    return 0;

}