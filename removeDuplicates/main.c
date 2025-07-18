#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};


void createNode(struct Node** head, int *arr)
{
    struct Node *last = NULL, *tmp = NULL;
    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->value = arr[0];
    (*head)->next = NULL;

    last = *head;

    for (int i = 1; i < 5; i++)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value = arr[i];
        tmp->next = NULL;
        last->next = tmp;

        last = tmp;
    }

}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ",head->value);
        head = head->next;
    }
    printf("NULL");
}

void removeDuplicates(struct Node *head)
{
    struct Node *ptr_1 = head;
    while (ptr_1->next != NULL)
    {
        if (ptr_1->value == ptr_1->next->value)
        {
            ptr_1->next = ptr_1->next->next;
        }
        ptr_1 = ptr_1->next;
    }
}
int main()
{
    int arr[5] = {1 ,2, 2, 3, 4};
    struct Node *list = NULL;
    int *arr_ptr = arr;
    createNode(&list, arr_ptr);
    display(list);
    removeDuplicates(list);
    printf("\n");
    display(list);
}