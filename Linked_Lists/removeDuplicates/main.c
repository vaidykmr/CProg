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

ListNode *deleteDuplicates(ListNode *head)
{

    int totalNodes = 0;
    ListNode *curr = head;

    while (curr != NULL)
    {
        totalNodes++;
        curr = curr->next;
    }
    
    int duplicatesFound = 0;
    ListNode dummyNode;
    dummyNode.next = head;
    ListNode *currentNode = head, *secondNode = NULL, *tmp = NULL;
    secondNode = head->next;
    int found = 0;
    while (currentNode != NULL && currentNode->next != NULL && secondNode != NULL)
    {
        if (currentNode->value != secondNode->value)
        {
            tmp = currentNode;
            currentNode = currentNode->next;
            secondNode = secondNode->next;
        }
        else
        {
            found = 1;
            while (found == 1)
            {
                duplicatesFound++;
                secondNode = secondNode->next;

                if (duplicatesFound == totalNodes - 1)
                {
                    dummyNode.next = NULL;
                    break;
                }
                
                if (secondNode == NULL)
                {
                    if (tmp != NULL)
                        tmp->next = secondNode;
                    else
                        dummyNode.next = secondNode;

                    break;
                }
                
                if (secondNode->value != currentNode->value)
                {
                    found = 0;
                    currentNode = secondNode;
                    secondNode = secondNode->next;

                    if (tmp != NULL)
                        tmp->next = currentNode;
                    else
                        dummyNode.next = currentNode;
                }

            }
        }
    }

    return dummyNode.next;
}


int main()
{
    int arr[] = {1,1,2,2};
    //int arr[] = {1, 1};
    int size = sizeof(arr)/sizeof(int);
    ListNode* head = NULL;
    head = (ListNode*)malloc(sizeof(ListNode));

    createNodes(&head, arr, size);

    display(head);

    printf("\n");

    ListNode *result = deleteDuplicates(head);
    display(result);
    return 0;

}