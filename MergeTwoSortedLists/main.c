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

void mergeTwoNodes (struct Node *Node1, struct Node *Node2, struct Node **finalNode)
{
    struct Node *last = NULL, *tmp = NULL;
    *finalNode = (struct Node*)malloc(sizeof(struct Node));
    (*finalNode)->value = Node1->value;
    (*finalNode)->next = NULL;
    last = (*finalNode);
    Node1 = Node1->next;

    while(Node1 != NULL)
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->value = Node1->value;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
        Node1 = Node1->next;
    }

    last->next = Node2;
}

void sortNode (struct Node *head)
{
    int swapped;
    struct Node *ptr1, *ptr2 = NULL;
    /*do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->value > ptr1->next->value) {
                // Swap values
                int temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1; // reduce loop range each pass
    } while (swapped);*/
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != ptr2)
        {
            if (ptr1->value > ptr1->next->value)
            {
                int temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
}

void delete(struct Node **head)
{
    while (*head != NULL)
    {
        *head = NULL;
    }
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
    //display(firstNode);  // sanity check
    sortNode(resultNode);
    printf("\n");
    display(resultNode);

    delete(&firstNode);
    delete(&secondNode);
    delete(&resultNode);

    if (!firstNode && !secondNode && !resultNode)
    {
        printf("\nSuccessfully deleted all the nodes");
    }
}