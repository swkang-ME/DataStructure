#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct __node
{
    LData data;
    struct __node *next;
} Node;

typedef struct __CLL
{
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;

} CList;

typedef CList List;

void ListInit(List *plist);

void LInsert(List *plist, LData data);

void LInsertFront(List *plist, LData data);

int LFirst(List *plist, LData *pdata);

int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);

int LCount(List *plist);

#endif