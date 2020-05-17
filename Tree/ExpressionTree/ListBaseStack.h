#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#include "BinaryTree.h"
#define TRUE    1
#define FALSE   0

typedef BTreeNode* SData;

typedef struct __node
{
    SData data;
    struct __node *next;
} Node;

typedef struct __listStack
{
    Node *top;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, SData data);
SData SPop(Stack *pstack);
SData SPeek(Stack *pstack);

#endif