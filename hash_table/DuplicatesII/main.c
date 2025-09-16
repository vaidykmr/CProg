#include <stdio.h>
#include <stdlib.h>


#define TABLE_SIZE 10
struct Node{
    int value;
    struct Node *next;
};


struct Node *hashTable[TABLE_SIZE];

int hash_function(int key)
{
    return abs(key) % TABLE_SIZE;
}

void insert(int value)
{
    int key = hash_function(value); 
    struct Node *currentNode = (struct Node*)malloc(sizeof(struct Node));
    currentNode->value = value;
    currentNode->next = NULL;
    currentNode->next = hashTable[key];
    hashTable[key] = currentNode;
}

int search(int value)
{
    int found = 0;
    int key = hash_function(value);
    struct Node *head = hashTable[key];

    while (head != NULL)
    {
        if (head->value == value)
        {
            found = 1;
            break;
        }
        head = head->next;
    }

    return found;
}


int containDuplicates(int *nums, int numSize)
{
    int duplicateValueFound = 0;

    for (int i = 0; i < numSize; i++)
    {
        int foundValue = search(nums[i]);
        if (!foundValue)
        {
            insert(nums[i]);
        }
        else
        {
            duplicateValueFound = 1;
        }
    }

    return duplicateValueFound;
}

int main()
{
    //int arr[4] = {1, 2, 3, 4};
    int arr[] = {1,1,1,3,3,4,3,2,4,2};
    int size = sizeof(arr)/sizeof(int);
    int found = containDuplicates(arr, size);

    printf("Duplicates found = %d \n", found);
    return 0;
}