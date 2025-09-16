#include <stdio.h>
#include <string.h>

struct list{
    int value;
    int countValue;
};

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
        if (arr[j] < arr[high])
        {
            i = i + 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
void CountTheDuplicatesoccurrences(int *num, int numSize)
{
    struct list store[numSize];
    memset(store, 0, sizeof(store));

    int i = 0;
    int start = 0;
    int count = 0;
    for (int end = 0; end < numSize; end++)
    {
        while(num[end] != num[start] && start != numSize)
        {
            if (count > 0)
            {
                store[i].value = num[start];
                store[i].countValue = count;
                //printf("Value: %d --> %d \n",store[i].value, store[i].countValue);
                i = i + 1;
            }
            start = start + 1;
            count = 0;
        }

        if (num[start] == num[end])
        {
            count = count + 1;
        }
    }

    if (count > 0)
    {
        store[i].value = num[start];
        store[i].countValue = count;
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("Value: %d --> %d \n",store[j].value, store[j].countValue);
    }
}
int main()
{
    int arr[] = {1, 2, 1, 2, 1, 3, 4, 3, 4, 3};
    //int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, size - 1);
    printf("Sorted array \n");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    CountTheDuplicatesoccurrences(arr, size);

    return 0;
}