#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "functions.h"

int main()
{
    LinkedList* myList;
    int option;
    int returnValue;
    //Employee* list;
    //int len;
    //int i;
   //Employee* aux;

    myList = ll_newLinkedList();


   do
    { // menu e ingreso de opcion de usuario
        printf("####################################################################################################################################\n");
        printf("---------------------------------------------  Bienvenido al sistema de empleados  -------------------------------------------------\n");
        printf("####################################################################################################################################\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf("10. Salir\n");
        option = getInt("Ingrese una opcion: ");
        switch (option)
        {
            case 1:
            returnValue=controller_loadFromText("data.csv", myList);
            operationConfirmation(returnValue);
            break;
            case 2:
            returnValue=controller_loadFromBinary("data.bin", myList);
            operationConfirmation(returnValue);
            break;
            case 3:
            returnValue=controller_addEmployee(myList);
            operationConfirmation(returnValue);
            break;
            case 4:

            break;
            case 5:
            returnValue=controller_removeEmployee(myList);
            operationConfirmation(returnValue);
            break;

            case 6:
            returnValue=controller_ListEmployee(myList);
            operationConfirmation(returnValue);
            break;

            case 7:

            break;
            case 8:
            returnValue=controller_saveAsText("data.csv", myList);
            operationConfirmation(returnValue);
            break;
            case 9:
            returnValue=controller_saveAsBinary("data.bin", myList);
            operationConfirmation(returnValue);
            break;
            case 10:
            printf("Ejecución finalizada. Hasta la próxima!\n");
            break;
            default:
            printf("Error. Opcion Inválida.\n");
            break;
        } // Fin switch
      system("pause");
      system("cls"); // limpiar interfaz
    } while (option!= 10);  // Fin iteración
    return 0;
}


    /*len = ll_len(miLista);
    printf("Cantidad de elementos: %d\n", len);

    list = employee_newParametros("100", "carlos", "40", "1500");
    ll_add(miLista, list);
    len=ll_len(miLista);
    printf("Cantidad de elementos: %d\n", len);
    if (list!=NULL)
    {
        mostrarEmpleado(list);
    }
    len=ll_clear(miLista);
    printf("Cantidad de elementos: %d\n", len);

    if (list!=NULL)
    {
        mostrarEmpleado(list);
    }

    list = employee_newParametros("101", "el pepe", "50", "2500");
    ll_add(miLista, list);

    len=ll_len(miLista);
    printf("Cantidad de elementos: %d\n", len);

    list = employee_newParametros("102", "ete sech", "60", "3500");
    ll_add(miLista, list);

    len=ll_len(miLista);
    printf("Cantidad de elementos: %d\n", len);

    for(i=0;i<len;i++)
    {
        aux=(Employee*) ll_get(miLista, i);
        printf("%d-", i+1);
        mostrarEmpleado(aux);
    }
     --------------------------------------------

    //int index;
    //index=1;

    //printf("Pa fore carlos\n");
    --------------POP---------------
    aux= ll_pop(miLista, 0);
    printf("Se borro: \n");
    mostrarEmpleado(aux);*/
    /*--------------POP---------------*/
    // Pop, a dif de remove, devuelve struct
    //ll_remove(miLista, index-1);
    /*printf("Quedo: \n");
    len=ll_len(miLista);
    for(i=0;i<len;i++)
    {
        aux=(Employee*) ll_get(miLista, i);
        printf("%d-", i+1);
        mostrarEmpleado(aux);
    }
    return 0;
}*/

/*void mostrarEmpleado(Employee* uno)
{
    printf("%d --- %s --- %d --- %d\n", uno->id, uno->nombre, uno->horasTrabajadas, uno->sueldo);
}*/
