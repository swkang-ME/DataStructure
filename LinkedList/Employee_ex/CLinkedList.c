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

void LInsertFront(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL)
    {
        newNode->next = newNode;
        plist->tail = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    
    (plist->numOfData)++;
    
}

void LInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL)
    {
        newNode->next = newNode;
        plist->tail = newNode;
    }

    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }

    (plist->numOfData)++;
    
}

int LFirst(List *plist, LData *pdata)
{
    if (plist->tail == NULL)
        return FALSE;

    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData *pdata)
{
    if (plist->tail == NULL)
        return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist)
{
    Node *rmvNode = plist->cur;
    LData rmvData = rmvNode->data;

    if(plist->tail == rmvNode)
    {
        if(plist->tail == plist->tail->next)
        {
            plist->tail = NULL;
        }
        else
        {
            plist->tail = plist->before;
        }   
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rmvNode);
    (plist->numOfData)--;
    return rmvData;
}

int LCount(List *plist)
{
    return plist->numOfData;
}