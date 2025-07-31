#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

struct Node{
    int value;
    int index;
    struct Node *next;
};

struct Node *hashTable[TABLE_SIZE];

int hash_function(int key)
{
    return abs(key) % TABLE_SIZE;
}

void insert(int key, int pos)
{
    int index = hash_function(key);
    struct Node *new_node = NULL;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = key;
    new_node->index = pos;
    new_node->next = hashTable[index];
    hashTable[index] = new_node;
}


// Time complexity : O(n^2)
/* int* twoSum(int *nums, int array_size, int target, int *returnSize)
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

}*/

/* This search function has time complexity of the order O(TABLE_SIZE).
    So, we have to refactor this function to the time complexity of order O(1).
int search(int key)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Node *current = hashTable[i];
        while (current != NULL)
        {
            if (current->value == key)
            {
                return current->index;
            }
            current = current->next;
        }
    }
    return -1;
} */
// Still this function's time complexity will increase if there is collisions
int search(int key)
{
    int index = hash_function(key);
    while (hashTable[index])
    {
        struct Node *current = hashTable[index];
        while (current)                 // This check is added if collission happens.
        {
            if (current->value == key)
            {
                return current->index;
            }
            current = current->next;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

// Time complexity: O(n)
int* twoSum(int *nums, int array_size, int target, int *returnSize)
{
    int difference = 0;
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < array_size; i++)
    {
        insert(nums[i], i);
    }

    for (int i = 0; i < array_size; i++)
    {
        difference = target - nums[i];
        int returnpos = search(difference);
        if (returnpos != -1 && returnpos != i)
        {
            count ++;
            if (count == 1)
            {
                returnSize[0] = i;
                returnSize[1] = returnpos;
                break;   
            }
        }
    }

    return returnSize;
}

int main()
{
    int arr[4] = {3, 2, 4, 1};
    int *xptr;

    xptr = arr;
    int array_size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int *returnArraySize;
    returnArraySize = (int*)malloc(2*sizeof(int));
    returnArraySize = twoSum(xptr, array_size, target, returnArraySize);
    for (int i = 0; i < 2; i ++)
    {
        printf("%d \n", returnArraySize[i]);
    }

    free(returnArraySize);
}