#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

int main()
{
    Stack stack;
    StackInit(&stack);

    SPush(&stack, 5);
    SPush(&stack, 4);
    SPush(&stack, 3);
    SPush(&stack, 2);
    SPush(&stack, 1);

    while(!SIsEmpty(&stack))
        printf("%d\n", SPop(&stack));
    
    return 0;
}