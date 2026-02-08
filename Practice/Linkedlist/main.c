#include <stdio.h>
#include "sll.h"
int main()
{
    init("hello");
    // add("hi");  // FIFO method  O(1)
    add_at_the_end("hi");    // O(N)
    add_at_the_end("hej");
    add_at_the_end("hola");
    add_at_the_end("eyy");
    // display();
    traverse();

    /* int exitsData = data_exists_in_list("bro");

    printf("\n Data exists = %d",exitsData); */

    // delete_data_in_list("hello");
    insert_to_the_list(3, "Bro");
    insert_to_the_list(1, "Brother");

    printf("\n");
    traverse();

    // reverse();
    // printf("\n");
    // reverse_traverse();

    return 0;
}