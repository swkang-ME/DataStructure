#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->before = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    
}