#include <stdio.h>

void displaya(int *b)
{
    printf("%d \n", *b);
}
int main()
{
    int a = 10;
    displaya(&a);
    return 0;
}