#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}

int main()
{
    struct Node *first = NULL;
    struct Node *tmp = NULL, *last = NULL;
    int arr[4] = {1 ,2, 3, 4};

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
    free(first);
    free(tmp);
}
