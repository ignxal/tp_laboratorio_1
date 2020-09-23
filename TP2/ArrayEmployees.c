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

void showEmployee(sEmployee list)
{
    printf ("%5d\t %7s\t %7s\t %7.2f\t %3d\n",      list.id,
                                                    list.name,
                                                    list.lastName,
                                                    list.salary,
                                                    list.sector);
    printf("--------------------------------------------------------------------------------------\n");
}

void showAllEmployees(sEmployee list[],int len)
{
    int i;
    
    printf("--------------------------------------------------------------------------------------\n");
    printf("   Id \t  Nombre \tApellido \t Salario \t Sector\n");
    printf("--------------------------------------------------------------------------------------\n");
    
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==FULL)
        {
            showEmployee(list[i]);
        }
    }
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
    // Comunico usuario confirmacion o error
    operationConfirmation(index);
}

int removeEmployee(sEmployee list[], int len)
{
    int i;
    int auxID;
    int index=-1;
    
    //pedir ingreso de id
    printf("Ingrese ID de empleado: ");
    scanf("%d", &auxID);
    
    //busco id en array
    for(i=0; i<len; i++)
    {
        if (list[i].isEmpty==FULL && auxID==list[i].id) // si encontro ID
        {
            list[i].isEmpty=EMPTY;
            index = 0;
            break;
        }
    }
    
    return index;
}

void removeEmployeeFunction(sEmployee list[])
{
    int index;
    
    // Muestro Empleados
    showAllEmployees(list, E);
    // Remuevo empleados
    index = removeEmployee(list, E);
    // Comunico usuario confirmacion o error
    operationConfirmation(index);
}