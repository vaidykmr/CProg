#include <stdio.h>
#include <stddef.h>
#include <string.h>


void *mem_cpy(void *dst, void *src, size_t n)
{
    unsigned char *d = (unsigned char*)dst;
    const unsigned char *s = (const unsigned char*)src;

    while (n--)
    {
        *d++ = *s++;
    }

    return dst;
}



void *returnNthINdex(void* base_ptr, int element_size, int index)
{
    char* char_base_ptr = (char*)base_ptr;

    int offset = element_size*index;

    char_base_ptr = char_base_ptr + offset;

    return (void*)char_base_ptr;
}


int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int size = sizeof(arr)/sizeof(int);
    int *result_ptr = NULL;

    result_ptr = (int*)returnNthINdex(arr, sizeof(int), 3);


    char src[] = "Hello, memcpy!";
    int dst[5];

    mem_cpy(dst, arr, sizeof(arr));

    printf("Destination = ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dst[i]);
    }


    printf("\n %d ", *result_ptr);

}