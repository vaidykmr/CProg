#include <stdio.h>

/*#define MAX_HEAP_SIZE 100
char heap[MAX_HEAP_SIZE];

void *head = (void*)heap;
void *tail = (void*)heap;

void *next = NULL;

int count = 0;
void push(unsigned char data)
{
    if (!count)
    {
        heap[count] = data;
        head = (void*)&heap[count];
        tail = (void*)&heap[count];

        next = (void*)&heap[++count];
        tail = next;
        return;
    }

    heap[count] = data;
    next = (void*)&heap[++count];
    tail = next;

    if (count == MAX_HEAP_SIZE - 1)
    {
        next = head;
        tail = next;

        printf("Buffer empty \n");
        return;
    }

    return;
}

char pop()
{
    char *head_ptr = (char*)head;
    unsigned char returnData = *(unsigned char *)head_ptr;
    head = head + 1;
    count = count - 1;

    if (count == 0)
    {
        head = tail = next = NULL;
    }
    return returnData;
}

int main()
{
    push('C');
    push('D');
    unsigned char popData = pop();
    printf("%c", popData);
    printf("\n%d\n", count);

    popData = pop();
    printf("%c", popData);
    printf("\n%d", count);
    return 0;
}*/

// Implementing queue in array
// This is basis of circular buffer implementation

#define MAX_HEAP_SIZE 10
char heap[MAX_HEAP_SIZE];

int count = 0;

int head = 0, tail = 0;

void push(char a)
{

    if (head == tail && count == MAX_HEAP_SIZE)
    {
        printf("Buffer full \n");
        return;
    }

    // Filling for the first time
    if(!tail && count == 0)
    {
        heap[tail] = a;
        head = tail;
        count ++;

        tail = (tail + 1) % (MAX_HEAP_SIZE);
        return;
    }

    heap[tail] = a;
    tail = (tail + 1) % (MAX_HEAP_SIZE);
    count ++;

    return;
}

char pop()
{
    if (count == 0)
    {
        printf("Nothing to pop \n");
        return;
    }
    char popData = heap[head];
    head = (head + 1)%MAX_HEAP_SIZE;
    count --;
    return popData;
}

// TODO
// Need to refactor the traverse code to print all the scenarios
void traverse()
{
    if (head == tail && count == 0)
    {
        printf("All elements popped out \n");
        return;
    }
    if (head < tail)
    {
        for(int i = head; i < tail; i++)
        {
            printf("\t %c", heap[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        printf("\t %c", heap[i]);   
    }
    printf("\n");
}

int main()
{
    push('A');
    push('B');
    push('C');
    push('D');

    traverse();
    printf("Position of head : %d \n", head);
    printf("Position of tail : %d \n", tail);
    pop();
    pop();

    traverse();
    printf("Position of head : %d \n", head);
    printf("Position of tail : %d \n", tail);

    printf("Total Nodes : %d \n", count);

    push('A');
    push('B');
    push('E');
    push('F');
    push('G');
    push('H');
    push('I');
    push('J');

    traverse();
    printf("Position of head : %d \n", head);
    printf("Position of tail : %d \n", tail);

    printf("Total Nodes : %d \n", count);

    push('K');
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    traverse();


    pop();

    return 0;

}




