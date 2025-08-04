#include <stdio.h>


int findLHS(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    
    for(int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize - 1 ; j++)
        {
            if (nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }

    int start = 0; 
    int end = 0;

    int window_len = 0;

    for (int end = 0; end < numsSize; end++)
    {
        while(nums[end] - nums[start] > 1)
        {
            start++;
        }

        if (nums[end] - nums[start] == 1)
        {
            int len = end - start + 1;
            if (len > window_len)
            {
                window_len = len;
            }
        }
    }

    return window_len;

}

int main()
{
    //int arr[8] = {1,3,2,2,5,2,3,7};
    int arr[4] = {1,21,1,1};
    int size = sizeof(arr)/sizeof(int);
    
    int window_size = findLHS(arr,size);

    printf("Window Size = %d", window_size);
}