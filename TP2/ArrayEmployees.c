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

void printAnEmployee(sEmployee list)
{
    printf ("%5d\t %7s\t %7s\t %7.2f\t %3d\n",      list.id,
                                                    list.name,
                                                    list.lastName,
                                                    list.salary,
                                                    list.sector);
    printf("--------------------------------------------------------------------------------------\n");
}

int printEmployees(sEmployee list[],int len)
{
    int i;
    
    printf("--------------------------------------------------------------------------------------\n");
    printf("   Id \t  Nombre \tApellido \t Salario \t Sector\n");
    printf("--------------------------------------------------------------------------------------\n");
    
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==FULL)
        {
            printAnEmployee(list[i]);
        }
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
    getString("Ingrese nombre: ", list[index].name);
    getString("Ingrese apellido: ", list[index].lastName);
    list[index].salary=getFloat("Ingrese salario: ");
    list[index].sector=getInt("Ingrese sector: ");
    list[index].id=generateId(list, len);
    list[index].isEmpty=FULL;

    return index;
}

void addEmployeeMain(sEmployee list[])
{
    int index;
    // Busco espacio en array   
    index = lookForSpace(list, E);
    // Cargo datos
    if(index!=-1)//si encontro lugar
    {
        addEmployee(list, E, index);
        index= 0;
    }
    // Comunico usuario confirmacion o error
    operationConfirmation(index);
}

void removeEmployeeMain(sEmployee list[])
{
    int index;
    
    // Muestro Empleados
    printEmployees(list, E);
    // Remuevo empleados
    index = removeEmployee(list, E);
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

void aboutEmployees(sEmployee list[])
{
    int option;
    
    option = getIntVal("\n1) Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n2)Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\nIndique opcion deseada:  ", "Error. Ingrese opcion (1-2): ", 1, 2);
    
    switch (option)
    {
        case 1:
        sortEmployeesMain(list);
        break;
        case 2:
        averageSalary(list);
        break;
    }
}

void sortEmployeesMain(sEmployee list[])
{
    int validation=-1;
    int order;
    
    // Pregunto por tipo de orden
    order = getIntVal("\n0) Z-A\n1) A-Z\nIndique tipo de ordenamiento: ", "Error. Ingrese opcion (0-1): ", 0, 1);
    // Ordeno empleados por apellido - sector
    validation = sortEmployees(list, E, order);
    // Confirmo ordenamiento exitoso o no
    operationConfirmation(validation); 
    // Muestro clientes con su cantidad de mascotas
    if (validation==0) // si ordeno
    {
        printEmployees(list, E);
    }
}

int sortEmployees(sEmployee list[], int len, int order)
{
    int i;
    int j;
    int validation=-1;
    sEmployee aux;
    
    for(i=0; i<len-1; i++)
    {
        if (list[i].isEmpty != FULL)
        {
            continue;
        }
        
        for(j=i+1; j<len; j++)
        {
            if (list[j].isEmpty != FULL)
            {
                continue;
            }
            
            switch (order)
            {
                case 0: // De Z-A

                if(strcmp(list[i].lastName,list[j].lastName)<0) // Ordeno por apellido
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else
                {
                    if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector < list[j].sector) // Ordeno por sector ante igualdad
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
                validation = 0;
                break;
                
                case 1: // De A-Z
                if(strcmp(list[i].lastName,list[j].lastName)>0) // Ordeno por apellido
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else
                {
                    if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector > list[j].sector) // Ordeno por sector ante igualdad
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
                validation = 0;

                break;
            }
        }
    }
    
    return validation;
}

void averageSalary(sEmployee list[])
{
    int i;
    float totalSalary;
    float aveSalary;
    int aboveAverageSalary;

    // Saco salario total
    totalSalary= doSum(list, E);
    
    if (totalSalary != 0)
    {
        printf("\nEl total de salarios es: %.2f", totalSalary);
    // Saco salario promedio
        aveSalary= doAverage(list);
        printf("\nEl salario promedio es: %.2f", aveSalary);
    // Saco cantidad por encima del promedio
        aboveAverageSalary= aboveAverage(list, E, aveSalary);
        printf("\nHay %d empleado/s que superan el salario promedio\n", aboveAverageSalary);
    }
    
    else 
    {
        totalSalary=-1;
        operationConfirmation(totalSalary);
    }
}

float doSum(sEmployee list[], int len)
{
    int i;
    float sumReturn=0;
     
    for(i=0;i<len;i++)
    {
        if (list[i].isEmpty!= FULL)
        {
            continue;
        }
        
        sumReturn=sumReturn+list[i].salary;
    }
    
    return sumReturn;
}   

int sumFullSpaces(sEmployee list[], int len)
{
    int i;
    int counter=0;
     
    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty!=FULL)
        {
            continue;
        }
        
        counter++;
    }

    return counter;
}

float doAverage (sEmployee list[])
{
    float average;
    float acc;
    int counter;
    
    acc = doSum(list, E);
    counter = sumFullSpaces(list, E);
    average = acc / counter;
    
    return average;
}

int aboveAverage (sEmployee list[], int len, float average)
{
    int i;
    int above=0;
     
    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty!=FULL)
        {
            continue;
        }
        
        if (list[i].salary > average)
        {
            above++;
        }
    }
    
    return above;
}