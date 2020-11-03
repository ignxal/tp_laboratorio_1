#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int returnValue=-1;

    pFile= fopen(path,"r");

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        returnValue=parser_EmployeeFromText(pFile, pArrayListEmployee);
    }

    fclose(pFile);

    return returnValue;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int returnValue=-1;

    pFile= fopen(path,"rb");

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        returnValue=parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }

    fclose(pFile);

    return returnValue;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

