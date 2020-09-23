#include "ArrayEmployees.h"
#include "functions.h"

int initEmployees(sEmployee list[], int len)
{
    int i;
    
    for (i=0; i<len; i++)
    {
        list[i].isEmpty= EMPTY;
    }
    
    return 0;
}

int generateId(sEmployee list[], int len)
{
    int i;
    int aux;
    
    for(i=0;i<len;i++)
    {
        if(i==0 || list[i].id>aux && list[i].isEmpty!=EMPTY)
        {
            aux=list[i].id;
        }
    }

    return aux+1;
}

int lookForSpace(sEmployee list[], int len)
{
    int i;
    int index = -1;
     
    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty==EMPTY)
        {
            index = i;
            break;
        }
    }
    
    return index;
}

int addEmployee(sEmployee list[], int len, int index)
{
    if(index!=-1)//si encontro lugar
    {
        getString("Ingrese nombre: ", list[index].name);
        getString("Ingrese apellido: ", list[index].lastName);
        list[index].salary=getFloat("Ingrese salario: ");
        list[index].sector=getInt("Ingrese sector: ");
        list[index].id=generateId(list, len);
        list[index].isEmpty=FULL;
        index= 0;
    }

    return index;
}

void addEmployeeFunction(sEmployee list[])
{
    int index;
    // Busco espacio en array   
    index = lookForSpace(list, E);
    // Cargo datos
    index = addEmployee(list, E, index);
    // Comunico usuario carga o error
    operationConfirmation(index);
}