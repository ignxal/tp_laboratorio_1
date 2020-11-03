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
    int returnValue = 0;
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
	int returnValue=0;
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
