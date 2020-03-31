#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
    plist -> numOfData = 0;
    plist -> curPosition = -1;
}

void LInsert(List *plist, LData data)
{
    if ((plist -> numOfData) > LIST_LEN)
    {
        printf("Array의 용량 초과!!! \n");
        return;
    }

    plist -> arr[plist -> numOfData] = data;
    (plist -> numOfData)++;

}

int LFirst(List *plist, LData *pdata)
{
    if ((plist -> numOfData) == 0)
        return FALSE;

    *pdata = (plist -> arr[0]);
    (plist -> curPosition) = 0;
    return TRUE;
}

int LNext(List *plist, LData *pdata)
{
    if (((plist -> curPosition) >= ((plist -> numOfData) - 1)) || ((plist -> numOfData) == 0))
        return FALSE;

    (plist -> curPosition)++;
    *pdata = plist -> arr[plist -> curPosition];
    return TRUE;
}

LData LRemove(List *plist)
{
    int remvPos = plist->curPosition;
    int lenData = plist->numOfData;
    LData remvData = plist->arr[remvPos];

    for (int i = remvPos; i < lenData - 1; i++)
    {
        plist -> arr[i] = plist -> arr[i+1];
    }

    (plist -> numOfData)--;
    (plist -> curPosition)--;

    return remvData;
}

int LCount(List *plist)
{
    return plist -> numOfData;
}
