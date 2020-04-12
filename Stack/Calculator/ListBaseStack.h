#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct __node
{
    Data data;
    struct __node *next;
} Node;

typedef struct __listStack
{
    Node *top;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif