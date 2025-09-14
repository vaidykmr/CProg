#include <stdio.h>
#include <stdlib.h>


#define TABLE_SIZE 10
struct Node 
{
    int value;
    int index;
    struct Node *next;
};

struct Node *hashTable[TABLE_SIZE];

int hash_function(int key)
{
    return (key % TABLE_SIZE);
}

void insert(int value, int index)
{
    int key = hash_function(value);
    struct Node *createNode = (struct Node*)malloc(sizeof(struct Node));
    createNode->value = value;
    createNode->index = index;
    createNode->next = NULL;
    struct Node *head = hashTable[key];
    if (head == NULL)
    {
        head = createNode;
        hashTable[key] = head;
    }
    else
    {
        while (head != NULL && head->next != NULL)
        {
            head = head->next;
        }
        head->next = createNode;
    }
}


void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Node *head = hashTable[i];
        if (head == NULL)
        {
            printf(" At index %d == NULL \n",i);
        }
        else
        {
            printf(" At index %d : ", i);
            while (head != NULL)
            {
                printf("%d -> ", head->value);
                head = head->next;
            }
            printf("NULL \n");
        }
    }
}

int search (int value)
{
    int pos = -1;
    int key = hash_function(value);
    struct Node *head = hashTable[key];
    while (head != NULL)
    {
        if (head->value == value)
        {
            pos = head->index;
        }
        head = head->next;
    }

    return pos;
}

int containNearbyDuplicates(int *nums, int numSize, int k)
{
    int found = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    for (int i = 0; i < numSize; i++)
    {
        int pos = search(nums[i]);
        printf("pos = %d \n", pos);
        if (pos > -1 && abs(i-pos) <= k)
        {
            found = 1;
            return found;
        }
        else{
            insert(nums[i], i);
        }
        
    }

    return found;
}
int main()
{
    int arr[6] = {1, 2, 3, 1, 2, 3};
    //int arr[5] = {1, 0, 2, 1,1};
    int size = sizeof(arr)/sizeof(int);
    int k = 2;
    int found = containNearbyDuplicates(arr, size, k);
    display();
    printf("Found = %d", found);
}


