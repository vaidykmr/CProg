/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/


#include <stdio.h>
#include <malloc.h>

void main()
{

    int *array_ptr = (int*)malloc(5*sizeof(int));
    for(int i =0; i < 5; i++)
    {
        array_ptr[i] = 5 - i;
    }

    for (int i = 0; i< 5; i++)
    {
        printf("%d \n", array_ptr[i]);
    }

    free(array_ptr);
}