#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE    1
#define FALSE   0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct __node
{
    Priority pr;
    HData data;
} HeapElem;

typedef struct __heap
{
    int numOfData;
    HeapElem *heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph);
HeapElem* GenHeapElem(HData data, Priority pr);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HeapElem *nelem);
HData HDelete(Heap *ph);

#endif