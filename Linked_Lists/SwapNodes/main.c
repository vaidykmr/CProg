#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
}ListNode;

void createNodes(ListNode **head, int *arr, int size)
{
    ListNode *last = NULL, *temp = NULL;
    ListNode *currentNode = *head;
    currentNode->value = arr[0];
    currentNode->next = NULL;

    last = currentNode;

    for(int i = 1; i < size; i++)
    {
        temp = (ListNode*)malloc(sizeof(ListNode));
        temp->value = arr[i];
        temp->next = NULL;

        last->next = temp;
        last = temp;
    }
}

void display(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
}

ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *current = head;
    int count = 0;
    while (current != NULL)
    {
        count = count + 1;
        current = current->next;
    }

    if (count == 0)
        return NULL;

    if (count == 1)
    {
        return head;
    }
    
    current = head;
    int index = 0;
    int valBegin, valEnd;

    while (current != NULL)
    {
        index = index + 1;
        if (index == k)
            valBegin = current->value;
        else if(index == count - k + 1)
            valEnd = current->value;
        current = current->next;
    }

    current = head;
    index = 0;
    
    while (current != NULL)
    {
        index = index + 1;
        if (index == k)
        {
            current->value = valEnd;
        }
        else if(index == count - k + 1)
        {
            current->value = valBegin;
        }
        current = current->next;
    }

    return head;

}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    ListNode* head = NULL;
    head = (ListNode*)malloc(sizeof(ListNode));

    int k = 2;

    createNodes(&head, arr, size);

    //display(head);
    ListNode *result = swapNodes(head, k);

    display(result);

    return 0;

}