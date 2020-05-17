#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SimpleHeap.h"

void HeapInit(Heap *ph)
{
    ph->numOfData = 0; 
}

int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

HeapElem* GenHeapElem(HData data, Priority pr)
{
    HeapElem *nelem = (HeapElem *) malloc(sizeof(HeapElem));

    nelem->data = data;
    nelem->pr = pr;

    return nelem;
}

int GetParentIdx(int idx)
{
    return idx/2;
}

void HInsert(Heap *ph, HeapElem *nelem)
{
    int idx = ph->numOfData + 1;
    Priority pr = nelem->pr;

    while(idx != 1)
    {
        if (pr < ph->heapArr[GetParentIdx(idx)]->pr)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        }
        else
            break;
    }

    ph->heapArr[idx] = nelem;
 //   memcpy(ph->heapArr[idx], nelem, sizeof(HeapElem));
    (ph->numOfData)++;

}

int GetLeftChildIdx(int idx)
{
    return idx*2;
}

int GetRightChildIdx(int idx)
{
    return idx*2 + 1;
}

int GetHiPriChildIdx(Heap *ph, int parentIdx)
{
    if(GetLeftChildIdx(parentIdx) > ph->numOfData)
        return 0;
    else if(GetLeftChildIdx(parentIdx) == ph->numOfData)
        return GetLeftChildIdx(parentIdx);
    else
    {
        if(ph->heapArr[GetLeftChildIdx(parentIdx)]->pr < ph->heapArr[GetRightChildIdx(parentIdx)]->pr)
            return GetLeftChildIdx(parentIdx);
        else
            return GetRightChildIdx(parentIdx);
    }
    
}

HData HDelete(Heap *ph)
{
    HeapElem *rmElem = (HeapElem *) malloc(sizeof(HeapElem)); 
    rmElem = ph->heapArr[1];
    HData rmdata = rmElem->data;
    HeapElem *lastelem = (HeapElem *) malloc(sizeof(HeapElem));
    lastelem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while(childIdx = GetHiPriChildIdx(ph, parentIdx))
    {
        if(lastelem->pr <= ph->heapArr[childIdx]->pr)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastelem;
    (ph->numOfData)--;
    free(rmElem);
    return rmdata;

}
