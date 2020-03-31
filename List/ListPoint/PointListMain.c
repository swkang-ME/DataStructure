#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "point.h"

int main()
{
    List list;
    Point compPos;
    Point *ppos;

    ListInit(&list);

    // save the point data
    ppos = malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, *ppos);

    ppos = malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, *ppos);

    ppos = malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, *ppos);

    ppos = malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, *ppos);

    // print the data
     printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, ppos))
            ShowPointPos(ppos);
    }
    printf("\n\n");

    // delete all data that xpos = 2
    compPos.xpos = 2;
    compPos.ypos = 0;

    if (LFirst(&list, ppos))
    {
        if(PointComp(ppos, &compPos) == 1)
        {
            *ppos = LRemove(&list);
            free(ppos);
        }

        while(LNext(&list, ppos))
        {
            if(PointComp(ppos, &compPos) == 1)
            {
            *ppos = LRemove(&list);
            free(ppos);
            }
        }
    }
    // print all remained data after removing
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, ppos))
            ShowPointPos(ppos);
    }
    printf("\n\n");

}