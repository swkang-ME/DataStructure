#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PostCalculator.h"
#include "ListBaseStack.h"

int EvalRPNExp(char *exp)
{
    Stack stack;
    int explen = strlen(exp);
    char tok, op1, op2;

    StackInit(&stack);

    for (int i=0; i < explen; i++)
    {
        tok = exp[i];
        if (isdigit(tok))
        {   
            SPush(&stack, tok - '0');
        }
        else
        {
            op2 = SPop(&stack);
            op1 = SPop(&stack);
        }
        
        switch(tok)
        {
            case '+':
                SPush(&stack, op1 + op2);
                break;
            case '-':
                SPush(&stack, op1 - op2);
                break;
            case '*':
                SPush(&stack, op1 * op2);
                break;
            case '/':
                SPush(&stack, op1/op2);
                break;
        }
    }

    return SPop(&stack);
}
