#include <stdio.h>

int add_func(int x, int y)
{
    return x+y;
}

int sub_func(int x, int y)
{
    return x-y;
}

int mul_func(int x, int y)
{
    return x*y;
}

void main()
{
    typedef int (*func_ptr)(int , int);   // function pointer declaration
    int a = 10;
    int b = 20;
    func_ptr fp[3] = {add_func, sub_func, mul_func};

    for (int i = 0; i < 3; i++)
    {
        int c = fp[i](a,b);          // dereferencing a function pointer
        printf("Result = %d\n", c);
    }
}