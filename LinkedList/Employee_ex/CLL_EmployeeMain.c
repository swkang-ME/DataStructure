#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

Employee * WhosNightDuty(List *plist, char *name, int day);
void ShowEmployeeInfo(Employee *plist);

int main()
{
    List WorkingTable;
    Employee *person1;
    int nodeNum;

    ListInit(&WorkingTable);

    person1 = addPerson("안철수", 11111);
    LInsert(&WorkingTable, person1);

    person1 = addPerson("홍준표", 22222);
    LInsert(&WorkingTable, person1);

    person1 = addPerson("유시민", 33333);
    LInsert(&WorkingTable, person1);

    person1 = addPerson("유승민", 44444);
    LInsert(&WorkingTable, person1);

    person1 = WhosNightDuty(&WorkingTable, "유시민", 4);
    ShowEmployeeInfo(person1);


    if(LFirst(&WorkingTable, &person1))
    {
        free(person1);
        for (int i = 0; i < LCount(&WorkingTable) - 1; i++)
        {
            if (LNext(&WorkingTable, &person1))
                free(person1);
        }
    }
}

Employee * WhosNightDuty(List *plist, char *name, int day)
{
    int i, num;
    Employee *ret;

    num = LCount(plist);

    LFirst(plist, &ret);

    if(strcmp(ret->name, name) != 0)
    {
        for (i = 0; i < num-1; i++)
        {
            LNext(plist, &ret);
            if(strcmp(ret->name, name) != 0)
                break;

        }
        if (i >= num-1)
            return NULL;
    }

    for (i = 0; i<day; i++)
        LNext(plist, &ret);

    return ret;
}

void ShowEmployeeInfo(Employee *emp)
{
    printf("Employee name: %s\n", emp->name);
    printf("Employee ID: %d\n",emp->ID);
}