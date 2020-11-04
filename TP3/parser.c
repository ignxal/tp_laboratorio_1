#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	char idStr[100];
	char nombreStr[100];
	char horasTrabajadasStr[100];
	char sueldoStr[100];
    int returnValue = -1;
	int howMany;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
	    howMany= fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr); // header
		while(!feof(pFile))
		{
		    howMany= fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
			if(howMany == 4)
			{
				pEmployee = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

				if(pEmployee != NULL)//si cargo
				{
					returnValue=ll_add(pArrayListEmployee, pEmployee);
				}
			}
        }
	}

    return returnValue;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int returnValue=-1;
    int itsOk;
	Employee* pEmployee;

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			pEmployee = employee_new();
			itsOk=fread(pEmployee, sizeof(Employee), 1, pFile);
			if(itsOk == 1)
			{
				returnValue=ll_add(pArrayListEmployee, pEmployee);
			}
		}
	}

    return returnValue;
}

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int i;
    int id;
    char nombre[100];
    int horasTrabajadas;
    int sueldo;
    int len;
    int returnValue=-1;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
        len=ll_len(pArrayListEmployee);
        for (i=0; i<len; i++)
        {
            pEmployee=(Employee*)ll_get(pArrayListEmployee, i);

            if(employee_getId(pEmployee, &id)==1 && employee_getHorasTrabajadas(pEmployee, &horasTrabajadas)==1 &&
               employee_getNombre(pEmployee, nombre)==1 && employee_getSueldo(pEmployee, &sueldo)==1)
            {
                fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
                returnValue=0;
            }
        }
        fclose(pFile);
    }
    return returnValue;
}

int parser_EmployeeToBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int i;
	int len;
    int returnValue=-1;

	if(pFile != NULL && pArrayListEmployee!= NULL)
	{
		len=ll_len(pArrayListEmployee);

		for(i=0; i<len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			fwrite(pEmployee, sizeof(Employee),1,pFile);
		}
		fclose(pFile);
		returnValue=0;
	}

    return returnValue;
}
