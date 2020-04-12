#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->top = NULL;
}
int SIsEmpty(Stack *pstack)
{
    if (pstack->top == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->top;
    pstack->top = newNode;
}

Data SPop(Stack *pstack)
{
    Data rData;
    Node *rmNode = (Node *)malloc(sizeof(Node));

    if (SIsEmpty(pstack))
    {
        printf("Stack에 저장된 데이터가 없습니다!!!\n");
        exit(-1);
    }
    else
    {
        rmNode = pstack->top;
        rData = rmNode->data;
        pstack->top = rmNode->next;
        free(rmNode);
        return rData;
    }
}

Data SPeek(Stack *pstack)
{
    if (pstack->top == NULL)
    {
        printf("Stack에 저장된 데이터가 없습니다!!!\n");
        exit(-1);
    }
    else
    {
        return pstack->top->data;
    }
}