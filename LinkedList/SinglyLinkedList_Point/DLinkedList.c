#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->comp == NULL)
    {
        newNode->next = plist->head->next;
        plist->head->next = newNode;
    }

    else
    {
        Node *pred = plist->head;

        while( (pred->next != 0) && (plist->comp(newNode->data, pred->next->data) != 0) )
        {
            pred = pred->next;
        }

        newNode->next = pred->next;
        pred->next = newNode;
    }

    (plist->numOfData)++;

}

int LFirst(List *plist, LData *pdata)
{
    if (plist->head->next == NULL)
        return FALSE;
    else
    {
        plist->before = plist->head;
        plist->cur = plist->head->next;

        *pdata = plist->cur->data;
        return TRUE;
    }
    
}

int LNext(List *plist, LData *pdata)
{
    if (plist->cur->next == NULL)
        return FALSE;
    else
    {
        plist->before = plist->cur;
        plist->cur = plist->cur->next;

        *pdata = plist->cur->data;
        return TRUE;
    }
   
}

LData LRemove(List *plist)
{   
    Node *rmvNode = plist->cur;
    LData rmvData = rmvNode->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;   

    free(rmvNode);
    return rmvData;
    (plist->numOfData)--;
}

int LCount(List *plist)
{
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}