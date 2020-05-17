#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
    
}

int GetParentIdx(int idx)
{
    return idx/2;
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
        if(ph->comp(ph->HeapArr[GetLeftChildIdx(parentIdx)], ph->HeapArr[GetRightChildIdx(parentIdx)]) >= 0)
            return GetLeftChildIdx(parentIdx);
        else
            return GetRightChildIdx(parentIdx);
    }
    
}


void HInsert(Heap *ph, HData data)
{
    int idx = ph->numOfData + 1;
    
    while(idx != 1)
    {
        if (ph->comp(data, ph->HeapArr[GetParentIdx(idx)]) > 0)
        {
            ph->HeapArr[idx] = ph->HeapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        }
        else
        {
            break;
        }
    }
    ph->HeapArr[idx] = data;
    (ph->numOfData)++;
}

HData HDelete(Heap *ph)
{
    HData rmdata = ph->HeapArr[1];
    HData lastelem = ph->HeapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while(childIdx = GetHiPriChildIdx(ph, parentIdx))
    {
        if(ph->comp(lastelem, ph->HeapArr[childIdx]) >= 0)
            break;
        ph->HeapArr[parentIdx] = ph->HeapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->HeapArr[parentIdx] = lastelem;
    (ph->numOfData)--;
    return rmdata;

}