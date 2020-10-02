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
            modifyEmployeeMain(list);
            break;
            case 3:
            removeEmployeeMain(list);
            break;
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
