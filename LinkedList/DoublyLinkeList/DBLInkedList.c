#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->tail = (Node *)malloc(sizeof(Node));

    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->tail;
    newNode->prev = plist->tail->prev;

    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;

    (plist->numOfData)++;
}

void LInsertFront(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head->next;
    newNode->prev = plist->head;

    plist->head->next->prev = newNode;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
    if (plist->head->next == plist->tail)
        return FALSE;
    else
    {
        plist->cur = plist->head->next;
        *pdata = plist->cur->data;
        return TRUE;   
    }
}

int LNext(List *plist, LData *pdata)
{
    if (plist->cur->next == plist->tail)
        return FALSE;
    else
    {
        plist->cur = plist->cur->next;
        *pdata = plist->cur->data;
        return TRUE;
    }
    
}

int LPrevious(List *plist, LData *pdata)
{
    if (plist->cur->prev == plist->head)
        return FALSE;
    else
    {
        plist->cur = plist->cur->prev;
        *pdata = plist->cur->data;
        return TRUE;
    }
}

int LCount(List *plist)
{
    return plist->numOfData;
}

LData LRemove(List *plist)
{
    Node *rmvNode = (Node *)malloc(sizeof(Node));
    if (plist->cur == NULL)
    {
        return rmvNode->data;
        printf("삭제할 노드를 찾지 못했습니다!!!\n");
    }
    else
    {
        rmvNode = plist->cur;
        rmvNode->prev->next = rmvNode->next;
        rmvNode->next->prev = rmvNode->prev;
        plist->cur = rmvNode->prev;
        return rmvNode->data;

        free(rmvNode);
    }
    
}