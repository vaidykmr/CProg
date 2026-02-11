#include <stdio.h>
#include <stdlib.h>


// Peforming stack operations in LL
// Stack operations - LIFO

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *__head = NULL;

void init(int data)
{
    __head = malloc(sizeof(Node));

    __head->value = data;
    __head->next = NULL;
}

void push(int data)
{
    Node *newNode = NULL;
    newNode = malloc(sizeof(Node));

    newNode->value = data;
    newNode->next = __head;
    __head = newNode;
}

void traverse()
{
    Node *cursor = __head;

    while (cursor)
    {
        printf("%d -> ", cursor->value);
        cursor = cursor->next;
    }

}

void pop()
{
    // int data = __head->value;

    Node *popNode = __head;
    __head = __head->next;

    free(popNode);

    // return data;

}

int peek()
{
    int data = __head->value;
    return data;
}


int main()
{
    init(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    traverse();
    printf("\n");
    pop();
    pop();
    pop();
    int topMostData = peek();
    printf("Top of the stack is : %d \n", topMostData);
    traverse();

    return 0;
}
