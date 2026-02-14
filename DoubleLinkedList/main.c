#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *__head = NULL;
Node *__tail = NULL;

void init(int data)
{
    __head = malloc(sizeof(Node));
    if (!__head)
        printf("Memory allocation failed");
    
    __head->data = data;
    __head->next = NULL;
    __head->prev = NULL;

    __tail = __head;
    
    return;
}

void add(int data)
{
    // Adding the nodes at the end
    Node *newNode = malloc(sizeof(Node));

    if (!newNode)
        printf("Memory allocation failed");

    newNode->data = data;
    newNode->prev = __tail;
    newNode->next = NULL;

    // remember the tail so that can be traversed from backwards
    __tail->next = newNode;
    __tail = newNode;

    return;
}

void traverse()
{
    Node *cursor = __head;
    while (cursor)
    {
        printf("<- %d -> ", cursor->data);
        cursor = cursor->next;
    }

}

void traverse_from_end()
{
    Node *cursor = __tail;
    while (cursor)
    {
        printf("-> %d <- ", cursor->data);
        cursor = cursor->prev;
    }
}

void deleteNode(int value)
{

    // Assuming there are only nodes with distinct values
    // The problem is that this only works for middle nodes.
    Node *cursor = __head;
    while (cursor)
    {
        if(cursor->data == value)
        {
            cursor->prev->next = cursor->next;
            cursor->next->prev = cursor->prev;
            break;
        }

        cursor = cursor->next;
    }

}

int main()
{
    init(1);
    add(2);
    add(3);
    add(4);
    traverse();
    printf("\n");

    deleteNode(3);
    traverse();

    return 0;
}