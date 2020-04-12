#include <stdio.h>
#include <string.h>
#include "PostCalculator.h"
#include "InfixToPostfix.h"

int main()
{
    char exp1[] = "1+2*3";
    char exp2[] = "1+2*3+4";
    char exp3[] = "((1-2)+3)*(5-2)";

    char Infix_exp1[100];
    char Infix_exp2[100];
    char Infix_exp3[100];

    strcpy(Infix_exp1, exp1);
    strcpy(Infix_exp2, exp2);
    strcpy(Infix_exp3, exp3);

    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);

    int result1 = EvalRPNExp(exp1);
    int result2 = EvalRPNExp(exp2);
    int result3 = EvalRPNExp(exp3);

    printf("%s = %d\n", Infix_exp1, result1);
    printf("%s = %d\n", Infix_exp2, result2);
    printf("%s = %d\n", Infix_exp3, result3);

    return 0;
}