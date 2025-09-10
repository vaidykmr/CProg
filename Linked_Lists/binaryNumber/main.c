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

int getDecimalValue(struct Node* head)
{
    int decimalValue = 0;

    int count = 0;
    struct Node *currentNode = head;

    while (currentNode != NULL)
    {
        count++;
        currentNode= currentNode->next;
    }

    int index = count - 1;

    currentNode = head;

    while(currentNode != NULL)
    {
        decimalValue += (1 << index) * (currentNode->value);
        index = index - 1;
        currentNode = currentNode->next;
    }

    return decimalValue;
}

int main()
{
    int arr[3] = {1, 0, 1};
    int size = sizeof(arr)/sizeof(int);
    int count = 0;
    struct Node *nodeObj = NULL;
    int *arr_ptr = arr;

    createNode(&nodeObj, arr_ptr, size, &count);
    display(nodeObj);

    int decimalValue = getDecimalValue(nodeObj);

    printf("\n Decimal Value = %d", decimalValue);
}