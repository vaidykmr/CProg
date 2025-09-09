#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void createNode(struct Node **head, int *arr, int size, int *count)
{
    struct Node *tmp = NULL, *last = NULL;

    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->value = arr[0];
    (*head)->next = NULL;

    last = *head;
    *count = *count + 1;

    for (int i = 1; i < size; i++)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value = arr[i];
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
        (*count)++;
    }
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
}

struct Node *middleNode(struct Node* head)
{
    int countNodes = 0;
    if (!head)
        return NULL;

    
    struct Node *currentNode = head;

    while (currentNode != NULL)
    {
        countNodes++;
        currentNode = currentNode->next;
    }
    /* debug
    printf("\n count = %d \n", countNodes);
    printf("head->value = %d", head->value); */

    int middleNode = (countNodes/2) + 1;
    struct Node *midNode = head;
    for (int i = 1; i < middleNode; i++)
    {
        midNode = midNode->next;
    }

    return midNode;
}

struct Node *deleteNode(struct Node* head)
{
    int countNodes = 0;
    if (!head)
        return NULL;

    
    struct Node *currentNode = head;

    while (currentNode != NULL)
    {
        countNodes++;
        currentNode = currentNode->next;
    }

    if(countNodes == 1)
    {
        return NULL;
    }

    int middleNode = (countNodes/2) + 1;
    struct Node *midNode = head;
    struct Node *prev = NULL;

    for (int i = 1; i < middleNode; i++)
    {
        prev = midNode;
        midNode = midNode->next;
    }

    prev->next = midNode->next;
    return head;
}

int main()
{
    //int arr[6] = {1, 2, 3, 4, 5, 6};
    int arr[1] = {1};
    int size = sizeof(arr)/sizeof(int);
    int count = 0;
    struct Node *nodeObj = NULL;
    int *arr_ptr = arr;

    createNode(&nodeObj, arr_ptr, size, &count);

    //display(nodeObj);

    //printf("\n count = %d", count);
    //struct Node *midNode = middleNode(nodeObj);

    //display(midNode);

    struct Node *refinedHead = deleteNode(nodeObj);
    display(refinedHead);
}
