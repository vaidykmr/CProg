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
    if (head == NULL)
        printf("NULL");
    while (head != NULL)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
}

ListNode *rotateList(ListNode *head)
{

    int k = 3;
    int i = 0;

    ListNode* currentNode = head;
    int count = 0;

    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        count = count + 1;
    }

    k = k % count;
    currentNode = head;
    ListNode dummy;
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *next = NULL;
    while (i < k)
    {
        while (currentNode != NULL && currentNode->next->next != NULL)
        {
            currentNode = currentNode->next;
        }

        next = currentNode->next;
        currentNode->next = NULL;
        prev->next = next;
        next->next = head;
        head = dummy.next;
        currentNode = head;
        i++;
    }


    return dummy.next;

}


int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    ListNode* head = NULL;
    head = (ListNode*)malloc(sizeof(ListNode));

    createNodes(&head, arr, size);

    display(head);

    printf("\n");

    ListNode *result = rotateList(head);
    display(result);


    return 0;

}