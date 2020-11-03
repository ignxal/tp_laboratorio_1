#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "functions.h"
#include <string.h>

Employee* employee_new()
{
    Employee* puntero;

    puntero = (Employee*) malloc(sizeof(Employee));

    if (puntero!=NULL)
    {
        employee_setId(puntero, 0);
        employee_setNombre(puntero, "\0");
        employee_setHorasTrabajadas(puntero, 0);
        employee_setSueldo(puntero, 0);
    }

    return puntero;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* puntero;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;

    puntero = employee_new();

    if(puntero!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        id = atoi(idStr);
        employee_setId(puntero, id);

        strcpy(nombre, nombreStr);
        employee_setNombre(puntero, nombre);

        horasTrabajadas=atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(puntero, horasTrabajadas);

        sueldo=atoi(sueldoStr);
        employee_setSueldo(puntero, sueldo);
    }

    /*if (employee_setId(puntero, id) == 0 || employee_setNombre(puntero, nombre) == 0 || employee_setHorasTrabajadas(puntero, horasTrabajadas) == 0 || employee_setSueldo(puntero, sueldo) == 0)
    {
        free(puntero);
        puntero=NULL;
    }
    else
    {
       printf("Error en parte de set");
    }*/

    return puntero;
}

int employee_delete(LinkedList* pArrayListEmployee, int index)
{
    Employee* pEmployee;
    char confirmation;
    int returnValue=-1;


    if(pArrayListEmployee != NULL)
    {
        confirmation=getChar("Confirma baja de empleado? (s/n): ","Error. Confirma baja de empleado? (s/n): ", 's', 'n');

        if (confirmation=='s')
        {
            pEmployee=ll_pop(pArrayListEmployee, index);
            printf("Se elimino: \n");
            employee_print(pEmployee);
            returnValue=0;
        }
    }

    return returnValue;
}

void employee_print(Employee* anEmployee)
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    int idFlag;
    int nombreFlag;
    int horasTrabajadasFlag;
    int sueldoFlag;

    idFlag=employee_getId(anEmployee, &id);
    nombreFlag=employee_getNombre(anEmployee, nombre);
    horasTrabajadasFlag=employee_getHorasTrabajadas(anEmployee, &horasTrabajadas);
    sueldoFlag=employee_getSueldo(anEmployee, &sueldo);


    if ((idFlag==1)&& (nombreFlag==1) && (horasTrabajadasFlag==1) && (sueldoFlag==1))
    {
        printf("|%10d|%20s|%13d|%10d|\n", id, nombre, horasTrabajadas, sueldo);
    }

}

int employee_nextId(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int aux;
	int lastId = 0;

	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee,i);
			employee_getId(pEmployee, &aux);

			if(aux > lastId || i==0)
			{
				lastId = aux;
			}
		}
	}
	return lastId+1;
}

int employee_lookForId(LinkedList* pArrayListEmployee, int id)
{
    Employee* pEmployee;
    int i;
    int aux;
    int len;
    int index=-1;

    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            pEmployee=(Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &aux);

            if(id == aux)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int employee_setId(Employee* this,int id)
{
	int retorno=0;
	if(id>0 && this!=NULL)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno=0;
	if(id!=NULL && this!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=0;
	if(nombre!=NULL && this!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno=1;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=0;
	if(nombre!=NULL && this!=NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=0;
	if(horasTrabajadas>0 && this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;
	if(horasTrabajadas!=NULL && this!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;
	if(sueldo>0 && this!=NULL)
	{
		this->sueldo=sueldo;
		retorno=1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;
	if(sueldo!=NULL && this!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}

int employee_CompareByName(Employee* e1, Employee* e2)
{
    return strcmp(e1->nombre,e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int comp=0;

    if(e1->id > e2->id)
    {
        comp=1;
    }
    else
    {
        if (e1->id < e2-> id)
        {
            comp=-1;
        }
    }

    return comp;
}
