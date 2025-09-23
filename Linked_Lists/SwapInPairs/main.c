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


ListNode *swapPairs(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }
    ListNode dummyNode;
    dummyNode.next = head;
    ListNode *prev = &dummyNode;
    ListNode *current = NULL, *second = NULL;

    while (head != NULL && head->next != NULL)
    {
        current = head;
        second = head->next;
        current->next = second->next;
        second->next = current;
        prev->next = second;

        prev = current;
        head = current->next;
    }

    return dummyNode.next;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    ListNode* head = NULL;
    head = (ListNode*)malloc(sizeof(ListNode));

    createNodes(&head, arr, size);

    //display(head);

    ListNode *result = swapPairs(head);

    display(result);

    return 0;

}