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

ListNode* reverseBetween(ListNode* head, int left, int right) {

    ListNode dummy;
    dummy.next = head;
    ListNode *finalNode = &dummy;
    ListNode *currentNode = head, *next = NULL, *prev = NULL;
    int count = 0;
    while (currentNode != NULL)
    {
        count ++;

        if (count == left)
        {
            while (left <= right)
            {
                next = currentNode->next;
                currentNode->next = prev;
                prev = currentNode;
                currentNode = next;
                left ++;
            }
            finalNode->next = prev;
            currentNode = next;
            break;
        }
        else
        {
            currentNode = currentNode->next;
            finalNode = finalNode->next;
        }
    }

    finalNode = dummy.next;
    while (finalNode != NULL && finalNode->next != NULL)
    {
        finalNode = finalNode->next;
    }
    finalNode->next = next;

    return dummy.next;
}


int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    ListNode* head = NULL;
    head = (ListNode*)malloc(sizeof(ListNode));

    int left = 2;
    int right = 4;

    createNodes(&head, arr, size);

    display(head);

    printf("\n");

    ListNode *result = reverseBetween(head, left, right);
    display(result);


    return 0;

}