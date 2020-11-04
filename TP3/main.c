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
            returnValue=controller_editEmployee(myList);
            operationConfirmation(returnValue);
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
            returnValue=controller_sortEmployee(myList);
            operationConfirmation(returnValue);
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
            printf("Ejecucion finalizada. Hasta la proxima!\n");
            break;
            default:
            printf("Error. Opcion Invalida.\n");
            break;
        } // Fin switch
      system("pause");
      system("cls"); // limpiar interfaz
    } while (option!= 10);  // Fin iteración
    return 0;
}
