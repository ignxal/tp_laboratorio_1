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
        sueldo= getIntVal("Ingrese sueldo: ", "Error. Ingrese salario(0-500000): ", 0, 500000);

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

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int i;
    int len;
    int returnValue=-1;

    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len!=0)
        {
            printf("__________________________________________________________\n"
                   "|    ID    |       NOMBRE       |HORAS TRABAJO|  SALARIO |\n"
                   "|__________|____________________|_____________|__________|\n");
            for(i=0; i<len; i++)
            {
                aux =(Employee*)ll_get(pArrayListEmployee, i);
                employee_print(aux);
            }
                printf("|__________|____________________|_____________|__________|\n");
            returnValue=0;
        }
    }
    return returnValue;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    int isEmpty;
    int returnValue=-1;

    isEmpty=controller_ListEmployee(pArrayListEmployee);

    if (pArrayListEmployee!= NULL && isEmpty==0)
    {
        id=getInt("Ingrese ID de empleado: ");
        index=employee_lookForId(pArrayListEmployee, id);
        if (index!= -1)
        {
            returnValue=employee_edit(pArrayListEmployee, index);
        }
    }

    return returnValue;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int index;
    int id;
    int returnValue=-1;

    if(pArrayListEmployee != NULL && controller_ListEmployee(pArrayListEmployee)!=-1 )
    {
        id= getInt("Ingrese ID de empleado: ");
        index= employee_lookForId(pArrayListEmployee, id);
        if(index!=-1)
        {
            returnValue=employee_delete(pArrayListEmployee, index);
        }
    }

    return returnValue;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int isEmpty;
    int returnValue=-1;
    LinkedList* auxList;

    auxList=ll_clone(pArrayListEmployee);
    isEmpty=ll_isEmpty(auxList);

    if(pArrayListEmployee!= NULL && auxList != NULL && isEmpty==0)
    {
        do
        {
            system("cls");
            printf("-------------- Menu de ordenamientos --------------\n1. Ordenar por id\n2. Ordenar por nombre\n");
            printf("3. Ordenar por horas trabajadas\n4. Ordenar por salario\n5. Salir\n");
            option=getInt("Ingrese opcion: ");

            switch(option)
            {
                case 1:
                printf("\nOrdenando...\n");
                ll_sort(auxList, employee_CompareById, 1);
                break;
                case 2:
                printf("\nOrdenando...\n");
                ll_sort(auxList, employee_CompareByName, 1);
                break;
                case 3:
                printf("\nOrdenando...\n");
                ll_sort(auxList, employee_CompareByHoursWorked, 1);
                break;
                case 4:
                printf("\nOrdenando...\n");
                ll_sort(auxList, employee_CompareBySalary, 1);
                break;
                case 5:
                printf("Saliendo del menu de ordenamientos...\n");
                break;
                default:
                printf("Error. Opcion Invalida.\n");
                break;
            }
                if(option>0 && option<5)
                {
                    controller_ListEmployee(auxList);
                }
                system("pause");
                system("cls");
        } while(option!=5);
        returnValue=ll_deleteLinkedList(auxList);
    }

    return returnValue;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int returnValue=0;

    if(pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        pFile=fopen(path, "w");
        if(pFile!= NULL)
        {
            returnValue=parser_EmployeeToText(pFile, pArrayListEmployee);
        }
        fclose(pFile);
    }

    return returnValue;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int returnValue=0;

    if(path!=NULL && pArrayListEmployee!= NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        pFile=fopen(path, "wb");
        if(pFile!=NULL)
        {
            returnValue=parser_EmployeeToBinary(pFile, pArrayListEmployee);
        }
        fclose(pFile);
    }

    return returnValue;
}

