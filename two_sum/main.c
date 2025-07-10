#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// O(n^2)
int* twoSum(int *nums, int array_size, int target, int *returnSize)
{
    int count = 0;
    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size; j++)
        {
            if (i != j)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    count++;
                    if (count == 1)
                    {
                        returnSize[0] = i;
                        returnSize[1] = j;
                        break;
                    }
                }
            }
        }
    }
    return returnSize;

}

int main()
{
    int arr[4] = {4,6,5,7};
    int *xptr;

    xptr = arr;
    int array_size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int *returnArraySize;
    returnArraySize = (int*)malloc(2*sizeof(int));
    returnArraySize = twoSum(xptr, array_size, target, returnArraySize);
    for (int i = 0; i < 2; i ++)
    {
        printf("%d \n", returnArraySize[i]);
    }

    free(returnArraySize);
}