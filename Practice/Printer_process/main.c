#include <stdio.h>
#include <stdlib.h>

// Implement as queue and should follow FIFO
#define THRESHOLD 5

typedef struct PrintQueue{
    int jobId;
    int pageCount;
    int priority;
    struct PrintQueue *next;
}PrintQueue;

PrintQueue *__head = NULL;
PrintQueue *__tail = NULL;


void init(int jobId, int pageCount, int priority)
{
    __head = malloc(sizeof(PrintQueue));
    __head->jobId = jobId;
    __head->pageCount = pageCount;
    __head->priority = priority;

    __head->next = NULL;

    __tail = __head;

    return;
}

void addJob(int jobId, int pageCount, int priority)
{
    if (!__head)
    {
        init(jobId, pageCount, priority);
        return;
    }

    else
    {
        PrintQueue *newJobQueue = malloc(sizeof(PrintQueue));
        newJobQueue->jobId = jobId;
        newJobQueue->pageCount = pageCount;
        newJobQueue->priority = priority;
        newJobQueue->next = NULL;

        if (priority < THRESHOLD)
        {
            __tail->next = newJobQueue;
            __tail = newJobQueue;
        }
        else
        {
            newJobQueue->next = __head;
            __head = newJobQueue;
        }

        return;

    }
}

void processJob()
{
    PrintQueue *cursor = __head;
    if (!cursor)
    {
        __head = NULL;
        __tail = NULL;
        printf("Jobs empty \n");
        return;
    }
    __head = cursor->next;
    free(cursor);

    if(__head == NULL)
        __tail = NULL;
}

void cancelJob(int jobId)
{
    PrintQueue *cursor = __head;

    if (cursor->jobId == jobId)
    {
        PrintQueue *tmpJob = cursor;
        __head = cursor->next;
        free(tmpJob);
        return;
    }
    while(cursor && cursor->next)
    {
        if(cursor->next->jobId == jobId)
        {
            PrintQueue *tmpJob = cursor->next;
            cursor->next = cursor->next->next;
            free(tmpJob);
        }
        else
        {
            cursor = cursor->next;
        }
    }
    __tail = cursor;
}



void traverse()
{
    PrintQueue *cursor = __head;
    if (!cursor)
    {
        printf("Jobs Empty \n");
        return;

    }
    while (cursor)
    {
        printf("%d -> ", cursor->jobId);
        cursor = cursor->next;
    }

    printf("\n");
}

int main()
{
    addJob(1, 2, 2);
    addJob(2, 2, 4);
    addJob(3, 2, 6);
    addJob(4, 2, 8);

    traverse();

    cancelJob(2);
    traverse();
    addJob(5, 2, 2);
    traverse();
}