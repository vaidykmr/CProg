#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void createTwoNodes(struct Node **firstNode, struct Node **secondNode, int *arr1, int *arr2)
{
    struct Node *last1 = NULL, *last2= NULL;
    struct Node *tmp1 = NULL, *tmp2 = NULL;

    *firstNode = (struct Node*)malloc(sizeof(struct Node));
    (*firstNode)->value = arr1[0];
    (*firstNode)->next = NULL;
    last1 = *firstNode;

    for (int i = 1; i < 3; i++)
    {
        tmp1 = (struct Node*)malloc(sizeof(struct Node));
        tmp1->value = arr1[i];
        tmp1->next = NULL;
        last1->next = tmp1;

        if((*firstNode)->next != NULL)  // Not needed this check. Just for debugging
        {
            last1 = tmp1;
        }

    }

    *secondNode = (struct Node*)malloc(sizeof(struct Node));
    (*secondNode)->value = arr2[0];
    (*secondNode)->next = NULL;
    last2 = *secondNode;

    for (int i = 1; i < 5; i++)
    {
        tmp2 = (struct Node*)malloc(sizeof(struct Node));
        tmp2->value = arr2[i];
        tmp2->next = NULL;
        last2->next = tmp2;

        if((*secondNode)->next != NULL)  // Not needed this check. Just for debugging
        {
            last2 = tmp2;
        }
    }
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}

void sum_of_two_nodes(struct Node *firstNode, struct Node *secondNode, struct Node **resultNode)
{
    struct Node *last = NULL, *tmp = NULL;
    *resultNode = (struct Node*)malloc(sizeof(struct Node));
    int carry_over = 0;
    if (firstNode != NULL && secondNode != NULL)
    {
        (*resultNode)->value = firstNode->value + secondNode->value;
        (*resultNode)->next = NULL;

        if ((*resultNode)->value > 9)
        {
            carry_over = (*resultNode)->value / 10;
            (*resultNode)->value = (*resultNode)->value % 10;
        }

        last = *resultNode;
        firstNode = firstNode->next;
        secondNode = secondNode->next;
        while (firstNode != NULL && secondNode != NULL)
        {
            tmp = (struct Node*)malloc(sizeof(struct Node));
            tmp->value = firstNode->value + secondNode->value + carry_over;
            if (tmp->value > 9)
            {
                carry_over = tmp->value / 10;
                tmp->value = tmp->value % 10;
            }
            else
            {
                carry_over = 0;
            }
            tmp->next = NULL;
            last->next = tmp;

            if ((*resultNode)->next != NULL)
            {
                last = tmp;
            }

            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }
    }
}

void checkSizeOfTwoNodes(struct Node *firstNode, struct Node *secondNode, int *count_firstNode, int *count_secondNode)
{
    while (firstNode != NULL)
    {
        (*count_firstNode)++;
        firstNode = firstNode->next;
    
    }

    while (secondNode != NULL)
    {
        (*count_secondNode)++;
        secondNode = secondNode->next;
    }
    
}

void appendZeros(struct Node *firstNode, struct Node *secondNode, int count_firstNode, int count_secondNode)
{
    struct Node *last = NULL, *tmp = NULL;
    int countNoOfZerosToAdd = 0;
    countNoOfZerosToAdd = count_firstNode - count_secondNode;
    while (secondNode->next != NULL)
    {
        secondNode = secondNode->next;
    }
    last = secondNode;
    while (countNoOfZerosToAdd != 0)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value = 0;
        tmp->next = NULL;
        last->next = tmp;

        last = tmp;

        countNoOfZerosToAdd--;
    }
}

int main()
{
    int arr_1[3] = {9 ,9, 9};
    int arr_2[5] = {9 ,9, 9, 9, 9};

    int *arr1_ptr = arr_1;
    int *arr2_ptr = arr_2;

    struct Node *node_1=NULL, *node_2=NULL, *node_result = NULL;
    int countNode1 = 0, countNode2 = 0;
    createTwoNodes(&node_1, &node_2, arr1_ptr, arr2_ptr);
    printf("First Node: \t");
    display(node_1);
    printf("\nSecond Node: \t");
    display(node_2);

    printf("\n");
    checkSizeOfTwoNodes(node_1, node_2, &countNode1, &countNode2);

    if (countNode1 > countNode2)
    {
        appendZeros(node_1, node_2, countNode1, countNode2);
        printf("\n Second Node after appending zeros\n");
        display(node_2);
    }

    if (countNode1 < countNode2)
    {
        appendZeros(node_2, node_1, countNode2, countNode1);
        printf("\n First Node after appending zeros\n");
        display(node_1);
    }
    printf("\n");
    printf("\n Sum of two nodes:");
    sum_of_two_nodes(node_1, node_2, &node_result);
    display(node_result);
    return 0;

}