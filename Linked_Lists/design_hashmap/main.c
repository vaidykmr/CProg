#include <stdio.h>
#include <stdlib.h>

typedef struct MyHashMap{
    int key;
    int value;
    struct MyHashMap *next;
}MyHashMap;

MyHashMap *myhashMapCreate(){
    MyHashMap *newObj = NULL;
    newObj = (MyHashMap*)malloc(sizeof(MyHashMap));
    newObj->key = -1;
    newObj->value = -1;
    newObj->next = NULL;
    return newObj;
}

void myHashMapPut(MyHashMap *obj, int key, int value)
{
    MyHashMap *newObj = NULL;
    newObj = (MyHashMap*)malloc(sizeof(MyHashMap));
    newObj->key = key;
    newObj->value = value;
    newObj->next = NULL;
    MyHashMap *currentObj = obj;
    int firstNode = 0;
    int foundKey = 0;
    if (currentObj->key == -1)
    {
        // First node
        currentObj->key = newObj->key;
        currentObj->value = newObj->value;
        firstNode = 1;
        free(newObj);
    }
    
    while (currentObj != NULL && currentObj->next != NULL)
    {
        if (currentObj->key == newObj->key)
        {
            currentObj->value = newObj->value;
            foundKey = 1;
            free(newObj);
            break;
        }
        else
            currentObj = currentObj->next;
    }

    if(!firstNode && !foundKey)
    {
        currentObj->next = newObj;
    }

}

void display(MyHashMap *head)
{
    while (head != NULL)
    {
        printf("%d ->",head->value);
        head = head->next;
    }

}

int myHashMapGet(MyHashMap* obj, int key) {
    MyHashMap *currentObj = obj;
    while (currentObj != NULL)
    {
        if (currentObj->key == key)
            return currentObj->value;
        
        currentObj = currentObj->next;
    }
    
    return -1;
}

void myHashMapRemove(MyHashMap *obj, int key)
{
    MyHashMap *prev = NULL;
    MyHashMap *currentObj = obj;

    while (currentObj != NULL)
    {
        if (currentObj->key == key)
        {
            prev->next = currentObj->next;
            break;
        }
        else
        {
            prev = currentObj;
            currentObj = currentObj->next;
        }
    }
}


int main()
{
    MyHashMap *obj = myhashMapCreate();

    int arr[5] = {3, 2, 6, 8, 9};
    int size = sizeof(arr)/sizeof(int);

    for (int i = 0; i < size; i++)
    {
        myHashMapPut(obj, i+1, arr[i]);
    }
    display(obj);
    myHashMapPut(obj, 2, 4);
    printf("\n");
    display(obj);

    int key = 3;
    
    int value = myHashMapGet(obj, key);
    printf("Value = %d", value);
    myHashMapRemove(obj,3);
    printf("\n");
    display(obj);
}