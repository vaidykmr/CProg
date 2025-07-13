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


void deleteNode(struct Node* current_node , int number)
{
    struct Node* prev = NULL;
    while(current_node->next != NULL && current_node->value != number)
    {
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
void delete(struct Node **head)
{
    while (*head != NULL)
    {
        *head = NULL;
    }
}


int main()
{
    struct Node *first = NULL;
    struct Node *tmp = NULL, *last = NULL;
    int arr[4] = {1 ,2, 3, 4};

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
    insertAtEnd(first, new_entry);
    printf("\n");
    printf("After insertion \n");
    display(first);
    printf("\n");
    printf("After deletion \n");
    deleteNode(first, 3);
    display(first);

    printf("\nDelete the entire node........ \n");
    delete(&first);
    if (first == NULL)
    {
        printf("Entire Node successfully deleted \n");
    }

    display(first);
}
