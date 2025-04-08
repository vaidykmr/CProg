#include <stdio.h>

void swap(int *p, int *q)
{
    printf("Before swap \n");
    printf("*p = %d\n", *p);
    printf("*q =  %d\n", *q);
    int *tmp;
    tmp = p;
    p = q;
    q = tmp;
    printf("After swap \n");
    printf("*p = %d\n", *p);
    printf("*q =  %d\n", *q);
}

int main()
{
    int a,b;
    a = 15;
    b = 10;

    swap(&a, &b);

}