#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};


void insertAtEnd(struct Node *current_node, int number)
{
    struct Node *new_entry = NULL;
    new_entry = (struct Node*)malloc(sizeof(struct Node));
    new_entry->value = number;
    new_entry->next = NULL;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_entry;
}


void deleteNode(struct Node** current_node , int number)
{
    struct Node* prev = NULL;
    struct Node *current = *current_node;

    if (current->value == number)
    {
        *current_node = current->next;
        free(current);
    }
    else
    {
        while(current->next != NULL && current->value != number)
        {
            prev = current;
            // printf("Hello %d \n", prev->value);
            current = current->next;
            // printf("Next Hello %d \n", (*current_node)->value);

        }
        prev->next = current->next;
        current = prev;
    }

}


void deleteFromEnd(struct Node* current_node , int index_from_end, int total_count)
{
    int count = 0;
    int index_to_delete_node = total_count - index_from_end;
    struct Node* prev = NULL;
    while(current_node->next != NULL && count < index_to_delete_node)
    {
        count ++;
        prev = current_node;
        current_node = current_node->next;
    }

    prev->next = current_node->next;
    current_node = prev;


}

void display(struct Node *head)
{

    if (head == NULL)
    {
        printf("Node empty\n");
    }
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}

void countNoOfNodes(struct Node *head, int *count)
{
    while (head != NULL)
    {
        (*count)++;
        head = head->next;
    }
}
void delete(struct Node **head)
{
    while (*head != NULL)
    {
        *head = NULL;
    }
}

void reverseNodes(struct Node **head, int count)
{
    int *arr;
    arr = (int*)malloc(count*sizeof(int));
    int i = 0;
    struct Node *dummy = NULL;
    dummy = *head;
    while (dummy != NULL)
    {
        arr[i] = dummy->value;
        dummy = dummy->next;
        i++;
    }

    struct Node *reverseHead = NULL;
    struct Node *last = NULL, *tmp = NULL;
    reverseHead = (struct Node*)malloc(sizeof(struct Node));
    reverseHead->value = arr[count-1];
    reverseHead->next = NULL;
    last = reverseHead;

    for (int j = count - 2; j >= 0; j--)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value = arr[j];
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }

    *head = reverseHead;
}


int main()
{
    struct Node *first = NULL;
    struct Node *tmp = NULL, *last = NULL;
    int arr[4] = {1 ,2, 3, 4};
    int count = 0;

    int new_entry = 5;

    first = (struct Node*)malloc(sizeof(struct Node));
    first->value = arr[0];
    first->next = NULL;

    last = first;

    for (int i = 1; i < 4; i++)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value = arr[i];
        tmp->next = NULL;
        last->next = tmp;

        if(first->next != NULL)  // Not needed this check. Just for debugging
        {
            last = tmp;
        }

    }

    display(first);
    countNoOfNodes(first, &count);
    printf("\nThe total number of nodes \t");
    printf("%d ", count);
    printf("\n***********************************************************\n");
    reverseNodes(&first, count);
    display(first);
    printf("\nDelete from end \n");
    deleteFromEnd(first, 2, count);
    display(first);

    insertAtEnd(first, new_entry);
    printf("\n");
    printf("After insertion \n");
    display(first);
    printf("\n");
    printf("After deletion \n");
    deleteNode(&first, 1);
    display(first);

    printf("\nDelete the entire node........ \n");
    delete(&first);
    if (first == NULL)
    {
        printf("Entire Node successfully deleted \n");
    }

    display(first);
}
