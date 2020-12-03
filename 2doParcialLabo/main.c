#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Competitor.h"
#include "funciones.h"

int main()
{
    //declaracion variables
    LinkedList* myList;
    LinkedList* nuevaLL;
    LinkedList* nuevaLLdos;
    int option;
    int returnValue;
    int flag=0;
    char string[128];

    myList = ll_newLinkedList();

    do
    { // menu e ingreso de opcion de usuario
        printf("####################################################################################################################################\n");
        printf("---------------------------------------------  Bienvenido al sistema de empleados  -------------------------------------------------\n");
        printf("####################################################################################################################################\n");
        printf("1. Cargar archivos.\n");
        printf("2. Imprimir datos.\n");
        printf("3. Jurado evalua.\n");
        printf("4. Contar puntaje menor a 10.\n");
        printf("5. Guardar puntaje menor a 10.\n");
        printf("6. Buscar mejor promedio.\n");
        printf("7. Mejores puntajes primera ronda.\n");
        printf("8. Guardar puntajes primera ronda.\n");
        printf("10. Salir.\n");
        option = getInt("Ingrese una opcion: ");
        switch (option)
        {
            case 1:
                getString("1. buenosaires\n2. misiones\n3. neuquen\n4. 2doparcial\nIngrese archivo a cargar: ", string); // ingreso de archivo no debe estar validado por nombre
                returnValue=controller_loadFromText(string, myList);
                operationConfirmation(returnValue);
            break;
            case 2:
                returnValue=controller_ListCompetitor(myList, flag);
                operationConfirmation(returnValue);
            break;
            case 3:
                returnValue=controller_generarSegundaNota(myList);
                returnValue=controller_saveAsText(string,myList);
                operationConfirmation(returnValue);
                flag=1;
            break;
            case 4:
                returnValue=controller_contarPuntaje(myList);
                controller_mostrarContador(returnValue);

            break;
            case 5:
                returnValue=controller_guardarDato(myList,competitor_buscarPuntajeMenorADiez);
                operationConfirmation(returnValue);
            break;
            case 6:
                if(flag==1)
                {
                    nuevaLL=controller_crearLLmejorPromedio(myList);
                    controller_ListCompetitor(nuevaLL, flag);
                }
                else
                {
                    operationConfirmation(-2);
                }
                break;
            case 7:
                nuevaLLdos=controller_crearLLfinalistas(myList);
                controller_ListCompetitor(nuevaLLdos, flag);
                break;
            case 8:
                returnValue=controller_guardarMejoresPuntajesRondaUno(nuevaLLdos);
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
} // Fin Main
