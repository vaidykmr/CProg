#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int index = -1;

void push(int number)
{
    if (index == MAX_SIZE - 1)
    {
        printf("Overflow");
    }
    else
    {
        index++;
        stack[index] = number;
    }
}

void pop()
{
    index--;
}

void display()
{
    if (index == -1)
        printf("No elements in the stack");
    else
    {
        for (int i = 0; i <= index; i++)
        {
            printf("%d ", stack[i]);
        }   
    }
    printf("\n");
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    display();
    pop();
    pop();

    display();

    push(80);
    push(90);
    push(100);


    display();

    return 0;
}