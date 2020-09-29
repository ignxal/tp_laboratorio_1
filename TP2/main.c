/******************************************************************************

1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. 

*******************************************************************************/
#include "ArrayEmployees.h"
#include "functions.h"

int main()
{
    //estructura
    sEmployee list[E];
    
    //funcion
    initEmployees(list, E);
    
    //variable
    int option;
    
    do 
    { // menu e ingreso de opcion de usuario
        printf("####################################################################################################################################\n");
        printf("---------------------------------------------------  Bienvenido al menu  -----------------------------------------------------------\n");
        printf("####################################################################################################################################\n");
        printf("1. Ingresar Empleado\n2. Modificar Empleado\n3. Eliminar empleado\n4. Informar sobre Empleados\n");
        option = menu("Ingrese una opcion: ");
        switch (option)
        {
            case 1:
            addEmployeeMain(list);
            break;
            case 2:

            break;
            case 3:
            removeEmployeeMain(list);
            case 4:
            aboutEmployees(list);
            break;
            case 5:
            printf("Ejecución finalizada. Hasta la próxima!\n");
            break;
            default: 
            printf("Error. Opcion Inválida.\n");
            break;
        } // Fin switch
      system("pause");
      system("cls"); // limpiar interfaz
    } while (option!= 5);  // Fin iteración
    return 0;
}
