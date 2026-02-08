#ifndef  __H__SLL__
#define __H__SLL__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>   // for ptrdiff_t
// Implementing memory copy operation instead of builtin api memcpy()
void *my_memcpy(void *dst, void *src, size_t src_size);
int init(char *data);
int add (char *data);
int add_at_the_end(char *data);
int data_exists_in_list(char *data);
void delete_data_in_list(char *data);
void insert_to_the_list(int key, char *data);
void display(void);
void traverse(void);
void reverse_traverse(void);
void reverse(void);

#endif