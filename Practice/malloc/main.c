#include <stdio.h>
#include <stddef.h>

// Performing basic version of malloc()


#define MAX_HEAP_SIZE 1024 * 1024  // 1 MB heap

static char heap[MAX_HEAP_SIZE];
// static size_t heap_offset = 0;


/* void *basic_malloc(size_t size)
{
    if (heap_offset + size > MAX_HEAP_SIZE)
        return NULL;
    
    void *ptr = &heap[heap_offset];
    heap_offset+= size;

    return ptr;
} */

// Implementing along with the header metadata

typedef struct block {
    size_t size;
    int free;
    struct block *next;
}block_t;

static block_t *free_list = (block_t*)heap;  // The compiler interprets this as starting bytes of heap contains data of type block_t

// Let's initialise the free_list

void init_heap()
{
    free_list->size = MAX_HEAP_SIZE - sizeof(block_t);
    free_list->free = 1;
    free_list->next = NULL;
}

block_t *find_free_list(size_t size)
{
    block_t *curr = free_list;
    while(curr)
    {
        if (curr->free && curr->size >= size)
            return curr;
        curr = curr->next;
    }

    return NULL;
}

void split_block(block_t *block,  size_t size)
{
    block_t *new_block = (block_t*)((char*)block + sizeof(block_t) + size);
    new_block->size = block->size - size - sizeof(block_t);
    new_block->free = 1;
    new_block->next = block->next;

    block->size = size;
    block->next = new_block;
}


void *my_malloc(size_t size)
{
    block_t *block = find_free_list(size);

    if (!block)
        return NULL;
    
    if (block->size > (size + sizeof(block_t)))
        split_block(block, size);
    
    block->free = 0;

    return((char*)block + sizeof(block_t));
}


void *my_free(void *ptr)
{

    if (!ptr)
        return NULL;
    
    block_t *block = (block_t*)((char*)ptr - sizeof(block_t));
    block->free = 1;
}




