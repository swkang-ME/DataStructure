#include <stdio.h>
#include "ArrayList.h"
// #include "ArrayList.c"

int main()
{
    // define variables and initialize the list
    List list;
    int data;
    ListInit(&list);

    // insert data into the list
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    // print all data of the list
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    // search and remove the data "22"
    if (LFirst(&list, &data))
    {
        if (data == 22)
            LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list);
        }
    }

    // print all remained data of the list
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    return 0;
    
}