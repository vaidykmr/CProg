#include <stdio.h>
#include <stdlib.h>

struct listNode{
    int value;
    struct listNode* next;   
};

struct listNode *createNode(int val)
{
    struct listNode *first = NULL;
    first = (struct listNode*)malloc(sizeof(struct listNode));
    first->value = val;
    first->next = NULL;
    return first;
}

struct listNode *detectCycle(struct listNode *head) {

    if (head == NULL)
        return NULL;
    
    if (head->next == NULL)
        return head;

    struct listNode *slow = head, *fast = head;
    int cyclePos = -1;
    int count = 0;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            slow = head;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
                count++;
            }
            printf("Meeting pos = %d \n", count);
            return slow;
        }

    }

    return NULL;    
}


int main()
{
    struct listNode *head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(0);
    head->next->next->next = createNode(-4);
    head->next->next->next->next = createNode(5);

    head->next->next->next->next = head->next->next;  // Cycle

    struct listNode *entry = detectCycle(head);
    printf("%d \n", entry->value);

    return 0;
}