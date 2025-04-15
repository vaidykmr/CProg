// Simple code to implement passing by reference

#include <stdio.h>

void swap(int *p, int *q)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

int main()
{
    int a,b;
    a = 15;
    b = 10;

    printf("Before swap \n");
    printf("a = %d\n", a);
    printf("b =  %d\n", b);

    swap(&a, &b);

    printf("After swap \n");
    printf("a = %d\n", a);
    printf("b =  %d\n", b);

}