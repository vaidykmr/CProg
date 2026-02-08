// Practice creating a linked list.

#include <stdio.h>
#include <stdlib.h>


struct Node{
    int value;
    struct Node *next;
};


void *CreateNode(struct Node **first, int *arr, int size)
{

    struct Node *temp = NULL, *last = NULL;
    (*first) = (struct Node*)malloc(sizeof(struct Node));
    (*first)->value = arr[0];
    (*first)->next = NULL;

    last = (*first);

    for (int i = 1; i < size; i++)
    {
        temp = malloc(sizeof(struct Node));
        temp->value = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *head)
{

    while (head)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
}

int getDecimalValue(struct Node *head)
{
    int count = 0;
    int decimalValue = 0;
    struct Node* currentNode = head;

    while (currentNode)
    {
        count = count + 1;
        currentNode = currentNode->next;
    }
    currentNode = head;
    int index = count - 1;
    while (index >= 0 && currentNode != NULL)
    {
        decimalValue += ((1U << index)*currentNode->value);
        currentNode = currentNode->next;
        index = index - 1;
    }

    return decimalValue;

}


struct Node *reverseNodes(struct Node * head)
{
    struct Node *currentNode = head, *prev = NULL, *end = NULL;
    
    while (currentNode)
    {
        end = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = end;
    }
    
    return prev;

}

void deleteNode(struct Node **head, int index)
{
    struct Node *cursor = *head;
    int firstNodedeleted = 0;

    if (cursor->value == index)
    {
        cursor = cursor->next;
        *head = cursor;
        firstNodedeleted = 1;
    }

    if (!firstNodedeleted)
    {
        while (cursor)
        {
            if(cursor->next->value == index)
            {
                cursor->next = cursor->next->next;
                break;
            }
            cursor = cursor->next;

        }
    }

}

int main()
{
    struct Node *first = NULL;

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(int);

    CreateNode(&first, arr, size);
    display(first);

    /*printf("\n");
    struct Node *reverseNode = reverseNodes(first);

    display(reverseNode); */

    deleteNode(&first, 4);
    printf("\n");
    display(first);

    /* int decimalInteger = getDecimalValue(first);

    printf("\n The resultant decimal integer = %d \n", decimalInteger); */
    return 0;
}
