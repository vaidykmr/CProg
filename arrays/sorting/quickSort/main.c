// Took guidance from chatGPT

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = high;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < arr[high])
        {
            i++;
            swap(&arr[j], &arr[i]);

        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;

}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        /*  The reason why it's (pi - 1) for sorting the left half and 
            (pi +1) for sorting the right half is because number at position pi is already sorted */
        
        // recursive operation
        quickSort(arr, low, pi-1); 
        quickSort(arr, pi+1, high);
    }
}
int main()
{
    int arr[6] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr)/sizeof(int);

    quickSort(arr,0,size-1);
    // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}