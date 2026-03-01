#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#define MAX_ARRAY_SIZE 5

typedef struct{
    uint8_t id;
    uint16_t value;
}StructDataS;


typedef struct {
    StructDataS buffer[MAX_ARRAY_SIZE];
    int head;
    int tail;
    int count;
}RingBuffer;

// initialise head, tail, count
void init_buffer(RingBuffer *metadata)
{
    metadata->head = 0;
    metadata->tail = 0;
    metadata->count = 0;
}


void push_item(RingBuffer *metadata, StructDataS data)
{
    if (metadata->count == MAX_ARRAY_SIZE && metadata->head == metadata->tail)
    {
        printf("All slots are occupied \n");
        return;
    }

    metadata->buffer[metadata->tail].id = data.id;
    metadata->buffer[metadata->tail].value = data.value;
    metadata->tail = (metadata->tail + 1) % MAX_ARRAY_SIZE;
    metadata->count = metadata->count + 1;
    return;
}

StructDataS pop_item(RingBuffer *metadata)
{
    if (metadata->count == 0)
    {
        printf("Nothing to pop out \n");
        return;
    }
    StructDataS popData;
    popData.id = metadata->buffer[metadata->head].id;
    popData.value = metadata->buffer[metadata->head].value;
    metadata->head = (metadata->head + 1) % MAX_ARRAY_SIZE;
    metadata->count = metadata->count - 1;
    return popData;
}

int main()
{
    RingBuffer metaData;
    init_buffer(&metaData);

    StructDataS data = {1, 10};
    push_item(&metaData, data);
    data.id = 2;
    data.value = 20;
    push_item(&metaData, data);
    data.id = 3;
    data.value = 30;
    push_item(&metaData, data);
    data.id = 4;
    data.value = 40;
    push_item(&metaData, data);
    /*data.id = 5;
    data.value = 50;
    push_item(&metaData, data);*/
    printf("head : %d \n", metaData.head);
    printf("tail : %d \n", metaData.tail);
    printf("Count : %d \n", metaData.count);

    data = pop_item(&metaData);
    printf("head : %d \n", metaData.head);
    printf("tail : %d \n", metaData.tail);
    printf("Count : %d \n", metaData.count);

    for (int i = metaData.head; i < metaData.tail; i++)
    {
        printf("%d ", metaData.buffer[i].id);
    }
    printf("\n");
    return 0;
}
