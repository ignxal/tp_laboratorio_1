#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "functions.h"

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
    Employee* pEmployee;
    char nombre[100];
    int id;
    int horasTrabajadas;
    int sueldo;
    int returnValue;


    pEmployee=employee_new();

    if ((pEmployee!=NULL) & (pArrayListEmployee !=NULL))
    {
        id=employee_nextId(pArrayListEmployee);
        getString("Ingrese nombre: ", "Error. Ingrese nombre(A-Z): ", nombre);
        horasTrabajadas= getIntVal("Ingrese horas trabajadas: ", "Error. Ingrese horas trabajadas (0-744): ", 0, 744);
        sueldo= getIntVal("Ingrese sueldo: ", "Error. Ingrese salario(0-100000): ", 0, 100000);

        if(employee_setId(pEmployee, id)==1 &&
            employee_setNombre(pEmployee, nombre)==1 &&
            employee_setHorasTrabajadas(pEmployee, horasTrabajadas)==1 &&
            employee_setSueldo(pEmployee, sueldo)==1)
        {
            returnValue=ll_add(pArrayListEmployee, pEmployee);
        }
    }

    return returnValue;
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

