#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void createNode(struct Node **head, int *arr, int size, int *count)
{
    struct Node *tmp = NULL, *last = NULL;

    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->value = arr[0];
    (*head)->next = NULL;

    last = *head;
    *count = *count + 1;

    for (int i = 1; i < size; i++)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value = arr[i];
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
        (*count)++;
    }
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
}

//Using this method, space complexity is O(N)
struct Node *copyLinkedList(struct Node *head)
{
    struct Node *copyNode = NULL, *tmp = NULL;
    struct Node *originalNode = head;
    struct Node *last = NULL;

    copyNode = (struct Node*)malloc(sizeof(struct Node));
    copyNode->value = originalNode->value;
    copyNode->next = NULL;
    last = copyNode;
    originalNode = originalNode->next;

    while(originalNode != NULL)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value = originalNode->value;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;

        originalNode = originalNode->next;
    }

    return copyNode;
}

struct Node* reverseLinkedNodes(struct Node *head)
{
    struct Node *prev = NULL, *next = NULL;

    struct Node *current = head;
    struct Node *reverseNode = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    reverseNode = prev;
    return reverseNode;

}

int isPalindrome(struct Node *head)
{
    int palindrome = 1;
    int count_nodes = 0;
    int i = 0;
    struct Node *prev = NULL;
    struct Node *currentNode = head;

    while(currentNode != NULL)
    {
        count_nodes++;
        currentNode = currentNode->next;
    }

    if (count_nodes == 1)
    {
        return palindrome;
    }

    int middleNode = count_nodes / 2;

    struct Node *midNode = head;
    
    for (int j = 0; j < middleNode; j++)
    {
        prev = midNode;
        midNode = midNode->next;
    }

    prev->next = NULL;
    struct Node *firstNode = head;
    struct Node *reverseNode = reverseLinkedNodes(midNode);

    while (firstNode != NULL && i <= middleNode)
    {
        if (firstNode->value == reverseNode->value)
        {
            i++;
            firstNode = firstNode->next;
            reverseNode = reverseNode->next;
        }
        else
        {
            palindrome = 0;
            break;
        }
    }

    return palindrome;
}

int main()
{
    int arr[6] = {1, 2, 3, 3, 2, 1};
    //int arr[4] = {1, 2, 2, 1};
    //int arr[2] = {1,2};
    int size = sizeof(arr)/sizeof(int);
    int count = 0;
    struct Node *nodeObj = NULL;
    int *arr_ptr = arr;

    createNode(&nodeObj, arr_ptr, size, &count);
    //display(nodeObj);

    int palindrome = isPalindrome(nodeObj);
    printf("\n isPalindrome = %d ", palindrome);

    return 0;
}

