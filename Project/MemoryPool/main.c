#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define POOL_SIZE 800


typedef struct FreeNode{
    struct FreeNode *next;
}FreeNode;

typedef struct memPool {
    uint8_t *base;
    size_t blockSize;
    size_t numOfBlocks;
    FreeNode *head;
}memPool;

void pool_init(memPool *pool, void *memory, size_t blockSize, size_t numOfBlocks)
{
    int i = 0;
    pool->base = (uint8_t*)memory;
    pool->blockSize = blockSize;
    pool->numOfBlocks = numOfBlocks;

    while (i < (numOfBlocks - 1))
    {
        // The first bytes of currentBlock is interpreted as FreeNode when free
        FreeNode *currentBlock = (FreeNode*)(pool->base + (i*blockSize));  // The starting address of pool->base should be interpreted as FreeNode
        FreeNode *nextBlock = (FreeNode*)(pool->base + (i+1)*blockSize);
        currentBlock->next = nextBlock;
        i = i + 1;
    }

    FreeNode *lastBlock = (FreeNode*)(pool->base + ((numOfBlocks - 1)*blockSize));
    lastBlock->next = NULL;

    pool->head = (FreeNode*)pool->base;
    return;

}

void *pop(memPool *pool)
{
    FreeNode* popNode = pool->head;
    pool->head = popNode->next;
    return (void*)popNode;
}

void push(void *ptr_address, memPool *pool)
{
    FreeNode *pushNode = (FreeNode*)ptr_address;
    pushNode->next = pool->head;
    pool->head = pushNode;
    return;
}

int main()
{
    memPool pool;
    uint8_t memory[128];
    size_t nrOfBlocks = 10;
    size_t blockSize = POOL_SIZE / nrOfBlocks;

    uint8_t word[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0'};
    pool_init(&pool, memory, blockSize, nrOfBlocks);

    void *newAddress = pop(&pool);

    printf("Received address from the pool : %p \n", newAddress);

    uint8_t *c = (uint8_t*)newAddress;

    for (uint16_t i = 0; i < 8; i++)
    {
        *(c+i) = word[i]; 
    }


    for (uint16_t i = 0; i < 8; i++)
    {
        printf("%c", c[i]);
    }

    memset(c, 0, pool.blockSize);
    push((void*)c, &pool);
    c = NULL;

    return 0;
}

