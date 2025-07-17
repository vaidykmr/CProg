#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void createNode(struct Node** head, int *arr)
{
    struct Node *last = NULL, *tmp = NULL;
    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->value = arr[0];
    (*head)->next = NULL;

    last = *head;

    for (int i = 1; i < 4; i++)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value = arr[i];
        tmp->next = NULL;
        last->next = tmp;

        last = tmp;
    }

}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ",head->value);
        head = head->next;
    }
    printf("NULL");
}


void count_nodes(struct Node *head, int *count)
{
    while (head != NULL)
    {
        (*count)++;
        head = head->next;
    }
}

void mergeTwoNodes (struct Node *Node1, struct Node *Node2, struct Node **finalNode)
{
    *finalNode = Node1;
    struct Node *final = *finalNode;
    while (final->next != NULL)
    {
        final = final->next;
    }
    final->next = Node2;
}

int main()
{
    struct Node *firstNode = NULL, *secondNode = NULL, *resultNode = NULL;
    int a[4] = {1 ,3, 5, 7};
    int b[4] = {2, 4, 6, 8};
    int *a_ptr = a;
    int *b_ptr = b;
    createNode(&firstNode,a_ptr);
    createNode(&secondNode, b_ptr);

    display(firstNode);
    printf("\n");
    display(secondNode);
    mergeTwoNodes(firstNode, secondNode, &resultNode);

    printf("\n");
    display(resultNode);
}