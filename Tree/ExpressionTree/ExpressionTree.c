#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "ListBaseStack.h"
#include "ExpressionTree.h"

void ShowNodeData(int data);

BTreeNode *MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode *pnode;

    int explen = strlen(exp);
    StackInit(&stack);

    for (int i=0; i < explen; i++)
    {
        pnode = MakeTreeNode();

        if(isdigit(exp[i]))
        {
            SetData(pnode, exp[i] - '0');
        }
        else
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }

        SPush(&stack, pnode);
  
    }

    return SPop(&stack);

}

int EvaluateExpTree(BTreeNode *bt)
{
    if ((GetLeftSubTree(bt) == NULL) && (GetRightSubTree(bt) == NULL))
        return GetData(bt);

    int op1 = EvaluateExpTree(GetLeftSubTree(bt));
    int op2 = EvaluateExpTree(GetRightSubTree(bt));

    switch(GetData(bt))
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }

    return 0;
}

void ShowPreficTypeExp(BTreeNode *bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode *bt)
{
    InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode *bt)
{
    PostorderTraverse(bt, ShowNodeData);
}

void ShowNodeData(int data)
{
    if(0 <= data && data <= 9)
        printf("%d ", data);
    else
        printf("%c ", data);
}