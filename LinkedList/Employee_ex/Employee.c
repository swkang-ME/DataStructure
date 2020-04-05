#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* addPerson(char *name, int ID)
{
    Employee *person = (Employee*)malloc(sizeof(Employee));
    
    strcpy(person->name, name);
    person->ID = ID;

    return person;
}