#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{ 
    //declaracion variables
    float A=0;
    float B=0;
    int opcion;
    int ingresoA= 0;
    int ingresoB= 0;
    int flag= 0;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    long long int factorialA;
    long long int factorialB;
    
    do 
    { // menu e ingreso de opcion de usuario
        printf("--- Seleccione una opción ---\n1. Ingresar 1er operando (A=%.2f)\n2. Ingresar 2do operando (B=%.2f)\n3. Calcular todas las operaciones\n  a) Calcular la suma (A+B)\n  b) Calcular la resta (A-B)\n  c) Calcular la division (A/B)\n  d) Calcular la multiplicacion (A*B)\n  e) Calcular el factorial (A!)\n4. Informar resultados\n5. Salir\n",A,B);
        opcion = menu("Ingrese una opcion: ");
        switch (opcion)
        {
            case 1:
            A = getFloat("Ingrese Operador A: ");
            ingresoA= 1;
            break;
            case 2:
            B = getFloat("Ingrese Operador B: ");
            ingresoB= 1;
            break;
            case 3:
            if (ingresoA==1 && ingresoB == 1) //validacion de ingreso de operadores previamente 
            {
                suma = doSum(A,B); //llamado a funciones para cada operacion
                resta = doSub(A,B);
                multiplicacion = doMul(A,B);
                division = doDiv (A,B);
                factorialA = doFact(A);
                factorialB = doFact(B);
                flag = 1; //validacion de realizacion de operaciones para mostrar resultados
            }
            else 
            {
            printf("Error. Ingrese operadores.");
            }
            break;
            case 4:
            showResults(suma, resta, multiplicacion, division, flag, factorialA, factorialB);
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
    } while (opcion!= 5);  // Fin iteración
    return 0;
} // Fin Main