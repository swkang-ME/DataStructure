#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct __employee
{
    char name[10];
    int ID;
} Employee;

Employee* addPerson(char *name, int ID);

#endif