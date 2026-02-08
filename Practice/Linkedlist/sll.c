#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>   // for ptrdiff_t
#include "sll.h"
// Performing linked list on strings

typedef struct Node{
    char data[40];
    struct Node *next_node;
} Node;

static Node *__head = NULL;

static Node *__reverseNode = NULL;

// Implementing memory copy operation instead of builtin api memcpy()
void *my_memcpy(void *dst, void *src, size_t src_size)
{
    const unsigned char *src_str = (const unsigned char*)src;
    unsigned char *dst_str = (unsigned char*)dst;

    while (src_size--)
    {
        *dst_str++ = *src_str++;
    }

    return dst;
    
}


int init(char *data)
{
    __head = malloc(sizeof(Node));
    if (!__head)
    {
        printf("\n Memory allocation failed \n");
        return -1;
    }

    memcpy(__head->data, data, strlen(data));
    __head->next_node = NULL;

    // Only for printing purpose to verify the output
    /* printf("data : %s \n", __head->data);
    printf("Address of the starting node : %p \n", (void*)__head);
    printf("Address of the Next node : %p \n", (void*)&__head->next_node); 

    ptrdiff_t diff = (char*)&__head->next_node - (char*)__head;

    printf("The difference between the head and next is : %td \n", diff); */
    return 0;
}



int add (char *data)
{
    if (!data)
    {
        printf("\n Data invalid \n");
        return -2;
    }

    Node *n = malloc(sizeof(Node));

    if (!n)
    {
        printf("\n Memory allocation failed \n");
        return -1;
    }


    // my_memcpy(n->data, data, strlen(data) + 1);
    
    memcpy(n->data, data, strlen(data));
    n->next_node = NULL;

    n->next_node = __head;
    __head = n;
    return 0;
}


int add_at_the_end(char *data)
{
    if (!data)
    {
        printf("\n Data invalid \n");
        return -2;
    }

    Node *n = malloc(sizeof(Node));

    if (!n)
    {
        printf("\n Memory allocation failed \n");
        return -1;
    }

    size_t nodeSize = strlen(data);
    memcpy(n->data, data, nodeSize + 1);
    n->next_node = NULL;

    Node *temp = __head;

    while (temp->next_node)
        temp = temp->next_node;
    
    temp->next_node = n;
    return 0;

}

int data_exists_in_list(char *data)
{
    int found = 0;

    Node* cursor = __head;

    while (cursor)
    {
        if(strcmp(cursor->data, data) == 0)
        {
            found = 1;
            return found;
        }

        cursor = cursor->next_node;
    }

    return found;
}


void delete_data_in_list(char *data)
{
    Node *cursor = __head;
    int firstNodedeleted = 0;

    if (strcmp(cursor->data, data) == 0)
    {
        Node *tmp_Node = cursor;
        cursor = cursor->next_node;
        __head = cursor;
        firstNodedeleted = 1;
        free (tmp_Node);
    }

    if (!firstNodedeleted)
    {
        while (cursor)
        {
            if(strcmp(cursor->next_node->data, data) == 0)
            {
                Node *temp_Node = cursor->next_node;
                cursor->next_node = cursor->next_node->next_node;
                // we need to free that deleted Node's memory so that it is available for others to use
                free(temp_Node);
                break;
            }
            cursor = cursor->next_node;

        }
    }

}


void insert_to_the_list(int key, char *data)
{
    Node *cursor = __head;
    int count = 1;
    while(cursor)
    {
        if (count == key)
        {
            Node* tmp;
            tmp = malloc(sizeof(Node));
            memcpy(tmp->data, data, strlen(data)+1);
            tmp->next_node = cursor->next_node;
            cursor->next_node = tmp;
            break;
        }

        count = count + 1;
        cursor = cursor->next_node;
    }

}


void display(void) {
    while (__head)
    {
        printf("%s -> ", __head->data);
        __head = __head->next_node;
    }
}


void traverse(void) {
    for (Node * cursor = __head; cursor != NULL; cursor = cursor->next_node)
    {
        printf("%s -> ", cursor->data);
    }

}

void reverse_traverse(void)
{
    for (Node * cursor = __reverseNode; cursor != NULL; cursor = cursor->next_node)
    {
        printf("%s -> ", cursor->data);
    }
}


void reverse(void)
{
    Node *currentNode = __head, *prev = NULL, *last = NULL;

    while (currentNode)
    {
        last = currentNode->next_node;
        currentNode->next_node = prev;
        prev = currentNode;
        currentNode = last;
    }
    __reverseNode = prev;
}