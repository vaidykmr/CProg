#include <stdio.h>
#include <stdlib.h>

struct listNode{
    int value;
    struct listNode* next;   
};


struct create_arr{
    int struct_arr[5];
    int arr_size;
};

void createNode(struct listNode **head, void* args)
{
    struct create_arr *array_ptr = (struct create_arr*)args;
    struct listNode *last = NULL, *tmp = NULL;
    *head = (struct listNode*)malloc(sizeof(struct listNode));
    (*head)->value = array_ptr->struct_arr[0];
    (*head)->next = NULL;

    last = *head;

    for (int i = 1; i < array_ptr->arr_size; i++)
    {
        tmp = (struct listNode*)malloc(sizeof(struct listNode));
        tmp->value = array_ptr->struct_arr[i];
        tmp->next = NULL;
        last->next = tmp;

        last = tmp;
    }
}

void display(struct listNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ",head->value);
        head = head->next;
    }
    printf("NULL");
}


int main()
{
    struct create_arr *arr_obj = NULL;
    struct listNode *head;
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(int);

    arr_obj = (struct create_arr*)malloc(sizeof(struct create_arr));
    for (int i = 0; i < size; i++)
    {
        arr_obj->struct_arr[i] = arr[i];
    }
    arr_obj->arr_size = size;

    createNode(&head, (void*)arr_obj);
    display(head);
}

