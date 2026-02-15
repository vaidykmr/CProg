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
char doc[200] = "";

void init(char *data)
{
    __headUndoStack = malloc(sizeof(Stack));
    memcpy(__headUndoStack->data, data, strlen(data)+1);
    __headUndoStack->next = NULL;
    strcat(doc, data);
    return;
}

int type(char *data)
{
    if (!__headUndoStack)
    {
        init(data);
        return 0;
    }

    if (strlen(doc) + strlen(data) >= sizeof(doc))
        return -1;
    
    strcat(doc, data);

    Stack *newNode = malloc(sizeof(Stack));
    memcpy(newNode->data, data, strlen(data)+1);
    newNode->next = __headUndoStack;
    __headUndoStack = newNode;

    if (__headRedoStack)
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

    doc[strlen(doc) - strlen(popNode->data)] = '\0';

    popNode->next = __headRedoStack;
    __headRedoStack = popNode;
    return 0;
    
}

int redo()
{
    Stack *cursor = __headRedoStack;

    if (!cursor)
    {
        printf("Redo empty \n");
        return -1;
    }

    Stack *popNode = cursor;
    __headRedoStack = cursor->next;
    popNode->next = NULL;

    strcat(doc, popNode->data);
    
    popNode->next = __headUndoStack;
    __headUndoStack = popNode;

    return 0;
    
}

void traverseDoc()
{
    if (doc[0] == '\0')
    {
        printf("Doc empty \n");
        return;
    }
    for(int i = 0; doc[i] != '\0'; i++)
        printf("%c", doc[i]);
    
    printf("\n");
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

void freeNodesAndEmptyDoc()
{
    Stack *cursor = __headRedoStack;
    while (cursor)
    {
        Stack *next = cursor->next;
        free(cursor);
        cursor = next;
    }
    __headRedoStack = NULL;

    cursor = __headUndoStack;
    while (cursor)
    {
        Stack *next = cursor->next;
        free(cursor);
        cursor = next;
    }
    __headUndoStack = NULL;

    doc[0] = '\0';
}

int main()
{
    type("Hello ");
    type("World ");
    type("Hi");
    traverseDoc();
    traverseUndo();
    traverseRedo();
    //traverseUndo();
    undo();
    undo();
    undo();

    redo();

    //type("Hola");

    //undo();
    traverseDoc();
    traverseUndo();
    traverseRedo();

    type("Hola");
    traverseDoc();
    traverseUndo();
    traverseRedo();
    freeNodesAndEmptyDoc();

    traverseDoc();
}