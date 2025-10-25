#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void createLinkedList(struct ListNode **head, int arr[], int size)
{
    struct ListNode *first = NULL, *last = NULL, *tmp = NULL;
    first = (struct ListNode *)malloc(sizeof(struct ListNode));
    first->val = arr[0];
    first->next = NULL;

    *head = first;
    last = first;

    for(int i = 1; i < size; i++)
    {
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = arr[i];
        tmp->next = NULL;
        last->next = tmp;

        last = tmp;
    }
}

void display(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
}

struct ListNode *copyNodes(struct ListNode *head)
{
    struct ListNode *copiedNodes = NULL, *current = head;
    struct ListNode *last = NULL, *tmp = NULL;
    copiedNodes = (struct ListNode*)malloc(sizeof(struct ListNode));
    copiedNodes->val = current->val;
    copiedNodes->next = NULL;

    last = copiedNodes;
    current = current->next;
    while (current != NULL)
    {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = current->val;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
        current = current->next;
    }

    return copiedNodes;

}

struct ListNode *reverseLL(struct ListNode *head)
{
    struct ListNode *prev = NULL, *current = head, *second = NULL;
    while (current != NULL)
    {
        second = current->next;
        current->next = prev;
        prev = current;
        current = second;
    }

    return prev;
}

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *current = head, *second = NULL;
    struct ListNode dummyNode;
    dummyNode.next = current;
    int found = 0;
    while (current->next != NULL)
    {
        second = current->next;

        while (current->val == second->val)
        {
            found = 1;
            second = second->next;
        }

        if (found)
            current->next = second;

        current = current->next;
    }

    return dummyNode.next;
}

struct ListNode *deleteDuplicatesAlternative(struct ListNode *head)
{
    if (!head)
        return NULL;
    if (head->next == NULL)
        return head;
    
    struct ListNode *current = head, *second = NULL, *prev = NULL;
    struct ListNode dummyNode;
    prev = &dummyNode;
    dummyNode.next = current;
    prev->next = current;
    int found = 0;
    while (current->next != NULL)
    {
        second = current->next;

        while (current->val == second->val)
        {
            found = 1;
            second = second->next;
        }

        if (found)
        {
            prev->next = second;
            current = second;
            found = 0;
        }
        else
        {
            prev = prev->next;
            current = current->next;
        }
    }

    return dummyNode.next;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int size = sizeof(arr) / sizeof(int);

    struct ListNode *head = malloc(sizeof(struct ListNode));

    createLinkedList(&head, arr, size);

    display(head);

    struct ListNode *copiedNodes = copyNodes(head);
    //printf("\n");
    //display(copiedNodes);

    //struct ListNode *result = reverseLL(head);
    //printf("\n");

    //display(result);
    struct ListNode *resultDuplicateNodes = deleteDuplicates(copiedNodes);
    printf("\n");
    display(resultDuplicateNodes);
    return 0;

}