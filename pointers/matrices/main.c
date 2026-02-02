#include <stdio.h>
#include <stdlib.h>


int main()
{
    int arr[4] = {10, 20, 30, 40};

    int (*p)[4] = &arr;

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", *(*(p)+i));
    }

    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", (*p)[i]);
    }

    printf("\n");
    printf("Printing 2D array \n");

    int arr_2d[3][4] = {
    { 1,  2,  3,  4},
    { 5,  6,  7,  8},
    { 9, 10, 11, 12}
    };

    int (*q)[4] = arr_2d;

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ",*(*(q+i) + j));
        }
        printf("\n");
    }


    int ar[5];
    int *pp = ar;
    printf("%ld\n", &pp[3] - &pp[1]);

    printf("\n");
    /*int x = 0x01020304;
    char *ppp = (char*)&x;
    printf("0x%x\n", *(int*)ppp);

    int xx = 10;
    float *f = (float *)&xx;
    *f = 3.14;
    printf("%d\n", xx);*/

    int x = 1;
    char *ppp = (char*)&x;
    *(int*)ppp = 2;
    printf("%d\n", x);
    return 0;
}