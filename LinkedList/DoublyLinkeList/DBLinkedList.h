#ifndef __DBLINKEDLIST_H__
#define __DBLINKEDLIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct __node
{
    LData data;
    struct __node *next;
    struct __node *prev;
} Node;

typedef struct __dlinkedlist
{
    Node *head;
    Node *cur;
    Node *tail;
    int numOfData;

} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist);

void LInsert(List *plist, LData data);

void LInsertFront(List *plist, LData data);

int LFirst(List *plist, LData *pdata);

int LNext(List *plist, LData *pdata);

int LPrevious(List *plist, LData *pdata);

int LCount(List *plist);

LData LRemove(List *plist);

#endif