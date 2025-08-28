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


int hasCycle(struct listNode *head)
{
    int found = 0;
    struct listNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow->value;
        }
    }
    return -1;

}
int main()
{
    struct listNode *head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head->next->next->next->next = head->next->next;  // Cycle

    int meeting_value = hasCycle(head);
    printf("%d ", meeting_value);

    return 0;
}