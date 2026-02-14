#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    char data[40];
    struct Stack *next;
}Stack;


// For stack, we need to remember it is LIFO

Stack *__headUndoStack = NULL;
Stack *__headRedoStack = NULL;

void init(char *data)
{
    __headUndoStack = malloc(sizeof(Stack));
    memcpy(__headUndoStack->data, data, strlen(data)+1);
    __headUndoStack->next = NULL;
    return;
}

int type(char *data)
{
    if (!__headUndoStack)
    {
        init(data);
        return 0;
    }

    Stack *newNode = malloc(sizeof(Stack));
    memcpy(newNode->data, data, strlen(data)+1);
    newNode->next = __headUndoStack;
    __headUndoStack = newNode;

    if (__headRedoStack && (strcmp(__headRedoStack->data, newNode->data) != 1))
    {
        Stack* cursor = __headRedoStack;
        while (cursor)
        {
            Stack *next = cursor->next;
            free(cursor);
            cursor = next;
        }
        __headRedoStack = NULL;
    }

    return 0;
}

int undo()
{
    Stack *cursor = __headUndoStack;

    if (!cursor)
    {
        printf("Undo empty \n");
        return -1;
    }

    Stack *popNode = cursor;
    __headUndoStack = cursor->next;
    popNode->next = NULL;

    if (!__headRedoStack)
    {
        popNode->next = __headRedoStack;
        __headRedoStack = popNode;

    }
    else
    {
        Stack *newNode = malloc(sizeof(Stack));
        memcpy(newNode->data, popNode->data, strlen(popNode->data)+1);
        newNode->next = __headRedoStack;
        __headRedoStack = newNode;
        free(popNode);
    }
    return 0;
    
}

int redo()
{
    Stack *cursor = __headRedoStack;
    int isLastNode = 0;

    if (!cursor)
    {
        printf("Redo empty \n");
        return -1;
    }

    Stack *popNode = cursor;
    __headRedoStack = cursor->next;
    popNode->next = NULL;
    if (!__headUndoStack)
    {
        popNode->next = __headUndoStack;
        __headUndoStack = popNode;
    }
    else
    {
        Stack *newNode = malloc(sizeof(Stack));
        memcpy(newNode->data, popNode->data, strlen(popNode->data)+1);
        newNode->next = __headUndoStack;
        __headUndoStack = newNode;
        free(popNode);
    }
    
    return 0;
    
}

void traverseUndo()
{
    Stack *cursor = __headUndoStack;
    if (!cursor)
    {
        printf("Undo empty \n");
        return;
    }

    while(cursor)
    {
        printf("%s ", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

void traverseRedo()
{
    Stack *cursor = __headRedoStack;
    if (!cursor)
    {
        printf("Redo empty \n");
        return;
    }

    while(cursor)
    {
        printf("%s ", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

int main()
{
    type("Hello");
    type("World");
    type("Hi");
    traverseUndo();
    traverseRedo();
    //traverseUndo();
    undo();
    undo();

    type("Hola");

    //undo();
    traverseUndo();
    traverseRedo();

}