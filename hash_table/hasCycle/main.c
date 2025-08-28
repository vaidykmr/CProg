#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

struct Node *hashTableToStoreAddresses[100];

struct Node *createNode(int val)
{
    struct Node *first = NULL;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->value = val;
    first->next = NULL;

    return first;
}

int hasCycle(struct Node *head)
{
    struct Node* currentNode = NULL;
    currentNode = head;
    int count = 0;
    int found = 0;

    while (currentNode != NULL && currentNode->next != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            if (currentNode == hashTableToStoreAddresses[i])
            {
                found = 1;
                return found;
            }
        }

        hashTableToStoreAddresses[count++] = currentNode;
        currentNode = currentNode->next;
    }

    return found;
}

int main()
{
    struct Node *head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    //head->next->next->next->next = head->next->next;  // Cycle

    for (int i = 0; i < 100; i++)
        hashTableToStoreAddresses[i] = NULL;

    int status = hasCycle(head);

    if (status)
        printf("Cycle detected");
    else
        printf("Cycle not detected");

    return 0;
}