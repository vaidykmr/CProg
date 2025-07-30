#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

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

int search(int key)
{
    int index = hash_function(key);
    int pos = 0;
    struct Node* temp = hashTable[index];
    while (temp!= NULL)
    {
        if(temp->value == key)
        {
            pos = temp->index;
            return pos;
        }
        temp = temp->next;
    }
    return -1;
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

 int findDuplicates(int arr[], int size) {
    int diff = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
    for (int i = 0; i < size; i++) {
        int j = search(arr[i]);
        if (j != -1 && (abs(i - j) <=1)) {
            printf("Duplicate found for number : %d\n", arr[i]);
            diff = 1;
        } else {
            insert(arr[i], i);
        }
    }
    return diff;
}

void display()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* current = hashTable[i];
        while (current) {
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int arr[4] = {-1 ,0, -1, 1};
    int status = findDuplicates(arr, 4);

    printf("Status = %d", status);
    display();
}