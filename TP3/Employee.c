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
    int idFlag;
    int nombreFlag;
    int horasFlag;
    int sueldoFlag;

    puntero = employee_new();

    if(puntero!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        id = atoi(idStr);
        idFlag= employee_setId(puntero, id);

        if (idFlag==1)
        {
            strcpy(nombre, nombreStr);
            nombreFlag=employee_setNombre(puntero, nombre);
            if (nombreFlag==1)
            {
                horasTrabajadas=atoi(horasTrabajadasStr);
                horasFlag=employee_setHorasTrabajadas(puntero, horasTrabajadas);
                if (horasFlag==1)
                {
                    sueldo=atoi(sueldoStr);
                    sueldoFlag=employee_setSueldo(puntero, sueldo);
                }
            }
        }
    }

    if(sueldoFlag!=1)
    {
        free(puntero);
        puntero=NULL;
        printf("Error en setters\n");
    }

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

int employee_edit(LinkedList* pArrayListEmployee, int index)
{
    Employee* pEmployee;
    int option;
    char name[100];
    int hoursWorked;
    int salary;
    int flag=0;
    char confirmation;
    int returnValue=-1;


    if(pArrayListEmployee != NULL)
    {
        pEmployee=(Employee*)ll_get(pArrayListEmployee, index);
        if(pEmployee!=NULL)
        {
            employee_getHorasTrabajadas(pEmployee, &hoursWorked);
            employee_getSueldo(pEmployee, &salary);
            employee_getNombre(pEmployee, name);

            do{
                system("cls");
                printf("-------------- Menu de modificaciones --------------\n1. Modificar nombre\n");
                printf("2. Modificar horas trabajadas\n3. Modificar salario\n4. Salir\n");
                option=getInt("Ingrese opcion: ");

                switch(option)
                {
                    case 1:
                    getString("Ingrese nuevo nombre: ","Error. Ingrese nuevo nombre: ", name);
                    flag=1;
                    break;
                    case 2:
                    hoursWorked=getIntVal("Ingrese nuevas horas trabajadas: ","Error. Ingrese nuevas horas trabajadas del empleado: ",0, 744);
                    flag=1;
                    break;
                    case 3:
                    salary=getIntVal("Ingrese nuevo salario del empleado: ","Error. Ingrese nuevo salario del empleado (0-500000): ",0, 500000);
                    flag=1;
                    break;
                    case 4:
                    if(flag==1)
                    {
                        confirmation=getChar("Desea guardar los cambios? (s/n): ", "Error. Desea guardar los cambios? (s/n):", 's', 'n');
                        if (confirmation=='s')
                        {
                            if (employee_setNombre(pEmployee, name)==1 && employee_setHorasTrabajadas(pEmployee, hoursWorked)==1 && employee_setSueldo(pEmployee, salary)==1)
                            {
                                returnValue=0;
                            }
                        }
                    }
                    printf("\nSaliendo...\n");
                    break;
                    default:
                    printf("Error. Opcion invalida");
                    break;
                }
                system("pause");
                system("cls");
            }while(option != 4);
        }
    }
    return returnValue;
}

int employee_CompareById(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    int id1;
    int id2;
    int returnValue=0;

    if(e1!=NULL && e2 != NULL)
    {
        aux1=(Employee*)e1;
        aux2=(Employee*)e2;

        employee_getId(aux1, &id1);
        employee_getId(aux2, &id2);

       if(id1 > id2)
        {
            returnValue=1;
        }
        else
        {
            if (id1 < id2)
            {
                returnValue=-1;
            }
        }
    }

    return returnValue;
}

int employee_CompareByName(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    char name1[100];
    char name2[100];
    int returnValue=0;

    if(e1 !=NULL && e2 != NULL)
    {
        aux1=(Employee*)e1;
        aux2=(Employee*)e2;

        employee_getNombre(aux1, name1);
        employee_getNombre(aux2, name2);

        returnValue= strcmp(name1, name2);
    }

    return returnValue;
}

int employee_CompareByHoursWorked(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    int hours1;
    int hours2;
    int returnValue=0;

    if(e1!=NULL && e2 != NULL)
    {
        aux1=(Employee*)e1;
        aux2=(Employee*)e2;

        employee_getHorasTrabajadas(aux1, &hours1);
        employee_getHorasTrabajadas(aux2, &hours2);

       if(hours1 > hours2)
        {
            returnValue=1;
        }
        else
        {
            if (hours1 < hours2)
            {
                returnValue=-1;
            }
        }
    }

    return returnValue;
}

int employee_CompareBySalary(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    int salary1;
    int salary2;
    int returnValue=0;

    if(e1!=NULL && e2 != NULL)
    {
        aux1=(Employee*)e1;
        aux2=(Employee*)e2;

        employee_getSueldo(aux1, &salary1);
        employee_getSueldo(aux2, &salary2);

       if(salary1 > salary2)
        {
            returnValue=1;
        }
        else
        {
            if (salary1 < salary2)
            {
                returnValue=-1;
            }
        }
    }

    return returnValue;
}
