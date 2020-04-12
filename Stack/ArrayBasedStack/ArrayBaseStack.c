#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
    
}

void SPush(Stack *pstack, Data data)
{
    pstack->topIndex++;
    pstack->stackArr[pstack->topIndex] = data;
}
Data SPop(Stack *pstack)
{
    int rIdx;
    if (SIsEmpty(pstack))
    {
        printf("저장된 데이터가 없습니다!!!!\n");
        exit(-1);
    }
    else
    {
        rIdx = pstack->topIndex;
        pstack->topIndex--;
        return pstack->stackArr[rIdx];
    }
    
}

Data SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
    {
        printf("저장된 데이터가 없습니다!!!!\n");
        exit(-1);
    }
    else
    {
        return pstack->stackArr[pstack->topIndex];
    }
    
}