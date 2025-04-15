// Array and pointers similarity and difference

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void main()
{
    char *name_ptr = "BALAJI";
    char name_array[]= "balaji";

    printf("name_ptr = %s \n", name_ptr);
    printf("name_array = %s \n", name_array);
    printf("name_ptr = %p \n", name_ptr);
    printf("name_array = %p \n", name_array);
    printf("*name_ptr = %c \n", *name_ptr);
    printf("*name_array = %c \n", *name_array);


    printf("Before pointer increment string \n");
    printf("*name_ptr = %c \n", *name_ptr);
    name_ptr++;
    printf("After pointer increment string \n");
    printf("*name_ptr = %c \n", *name_ptr);


    // Difference between pointer and array in terms of memory usage (size)
    // arrays cannot be reassigned but pointers can be
    printf("sizeof(name_ptr) = %lu \n", sizeof(name_ptr));
    printf("sizeof(name_array) = %lu \n", sizeof(name_array));

    int x[] = {10, 20, 30}; // 12 bytes

    int *xptr = x; // 8 bytes as address is 8 byte long in this machine(depends on the compiler)

    printf("sizeof(x) = %lu \n", sizeof(x));
    printf("sizeof(xptr) = %lu \n", sizeof(xptr));

    // Address of these ( x and xptr) both should be same
    printf("xptr = %p \n", xptr);
    printf("x = %p \n", x);

    printf("Before pointer increment \n");
    printf("*xptr = %d \n", *xptr);
    xptr++;
    printf("After pointer increment \n");
    printf("*xptr = %d \n", *xptr);


    // Array of pointers

    int a [10] = {1,2,3,4,5,6,7,8,9,10};
    int *a_ptr[10];

    memset(a_ptr, 0, sizeof(a_ptr[10]));

    for (int i = 0; i < 10; i++)
    {
        a_ptr[i] = &a[i];
        printf("a_ptr[%d] = %p \t" , i, a_ptr[i]);
        printf("%lu \n", sizeof(a_ptr[i]));
    }

    printf("\n");


    // malloc() method
    int *b_ptr[10];

    memset(b_ptr, 0, sizeof(b_ptr[10]));

    for (int i = 0; i < 10; i++)
    {
        b_ptr[i] = (int*)malloc(sizeof(int)); // allocated in the heap
        *b_ptr[i] = (10 - i);
        printf("b_ptr[%d] = %p \n" , i, b_ptr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("*b_ptr[%d] = %d \n", i, *b_ptr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        free(b_ptr[i]);  // freed from heap
    }



    int *p = NULL;
    printf("%p \n", p);
    // printf("%d \n", *p);  deferencing a NULL pointer leads to crash (segmentation fault)
}