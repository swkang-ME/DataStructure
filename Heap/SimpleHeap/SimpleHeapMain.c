#include <stdio.h>
#include "SimpleHeap.h"

void main()
{
    Heap heap;
    HeapElem *elem;
    HeapInit(&heap);

    elem = GenHeapElem('A', 1);
    HInsert(&heap, elem);
    elem = GenHeapElem('B', 2);
    HInsert(&heap, elem);
    elem = GenHeapElem('C', 3);
    HInsert(&heap, elem);
    printf("%c \n", HDelete(&heap));

    elem = GenHeapElem('A', 1);
    HInsert(&heap, elem);
    elem = GenHeapElem('B', 2);
    HInsert(&heap, elem);
    elem = GenHeapElem('C', 3);
    HInsert(&heap, elem);
    printf("%c \n", HDelete(&heap));

    while(!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));

}