#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Competitor.h"
#include "parser.h"
#include "funciones.h"

int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    int returnValue=-1;

    strcat(path,".csv");

    pFile= fopen(path,"r");

    if(pFile!=NULL && pArrayList!=NULL)
    {
        ll_clear(pArrayList);
        returnValue=parser_CompetitorFromText(pFile, pArrayList);
    }

    fclose(pFile);

    return returnValue;
}

int controller_ListCompetitor(LinkedList* pArrayList, int flag)
{
    Competitor* aux;
    int i;
    int len;
    int returnValue=-1;

    if(pArrayList != NULL)
    {
        len = ll_len(pArrayList);
        if(len!=0)
        {
            switch(flag)
            {
            case 0:
                printf("______________________________________________________________________________________________\n"
                       "| NUMERO |NACIMIENTO|   NOMBRE    |   DNI    |   FECHA   |          TEMA           | PUNTAJE |\n"
                       "|________|__________|_____________|__________|___________|_________________________|_________|\n");
                for(i=0; i<len; i++)
                {
                    aux =(Competitor*)ll_get(pArrayList, i);
                    competitor_print(aux,flag);
                }
                printf("|________|__________|_____________|__________|___________|_________________________|_________|\n");
                break;
            case 1:
                printf("______________________________________________________________________________________________________________________\n"
                       "| NUMERO |NACIMIENTO|   NOMBRE    |   DNI    |   FECHA   |          TEMA           | PUNTAJE | PUNTAJE 2 | PROMEDIO |\n"
                       "|________|__________|_____________|__________|___________|_________________________|_________|___________|__________|\n");
                for(i=0; i<len; i++)
                {
                    aux =(Competitor*)ll_get(pArrayList, i);
                    competitor_print(aux,flag);
                }
                printf("|________|__________|_____________|__________|___________|_________________________|_________|___________|__________|\n");
                break;
            }
            returnValue=0;
        }
    }
    return returnValue;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    int returnValue=-1;
    char resultado[128];

    if(path!=NULL)
    {
        strcpy(resultado, "resultado");
        strcat(resultado, path);
        strcat(resultado, ".csv");

        if(pArrayList != NULL && ll_isEmpty(pArrayList)==0)
        {
            pFile=fopen(resultado, "w");
            if(pFile!= NULL)
            {
                returnValue=parser_CompetitorToText(pFile, pArrayList);
            }
            fclose(pFile);
        }
    }

    return returnValue;
}

int controller_generarSegundaNota(LinkedList* pArrayList)
{
    int returnValue=-1;
    if (pArrayList!=NULL)
    {
        returnValue=ll_map(pArrayList,competitor_generarSegundaNota);
        returnValue=ll_map(pArrayList,competitor_generarPromedio);
    }
    return returnValue;
}

int controller_contarPuntaje(LinkedList* pArrayList)
{
    int returnValue=-1;
    if (pArrayList!=NULL)
    {
        returnValue=ll_count(pArrayList,competitor_buscarPuntajeMenorADiez);
    }

    return returnValue;
}

void controller_mostrarContador(int cantidad)
{
    printf("La cantidad de puntajes menores a 10 es: %d\n", cantidad);
}

int controller_guardarDato(LinkedList* pArrayList, int (*pFunc)(void*))
{
    void* pElement;
    int i;
    int len;
    int returnValue=-1;

    if(pArrayList!=NULL && pFunc!=NULL)
    {
        len=ll_len(pArrayList);
        for(i=0;i<len;i++)
        {
            pElement=ll_get(pArrayList,i);

            // pFunc va a recibir el pElement y lo que haga la segunda funcion
            if(pFunc(pElement)==1)
            {
                returnValue=0;
            }
        }
    }

    return returnValue;
}

int controller_buscarSiEsMejorPromedio(Competitor* this, float mejorPromedio)
{
    int returnValue=0;
    float promedio;

    // Esta funcion da el criterio que se usa en ll_filter por lo tanto es la que se pasa por pFunc

    if(this!=NULL)
    {
        // Trae promedio
        competitor_getPromedio(this,&promedio);
        // Compara si el promedio traido es igual que el actual
        if(promedio==mejorPromedio)
        {
            returnValue=1;
        }
    }

    return returnValue;
}


LinkedList* controller_crearLLmejorPromedio(LinkedList* pArrayList)
{
    LinkedList* nueva;

    if(pArrayList!=NULL)
    {
        // Llamo LL filter, getmejorpromedio ya esta dentro
        nueva=ll_filter(pArrayList,controller_buscarSiEsMejorPromedio);
    }

    return nueva;
}

int controller_guardarMejoresPuntajesRondaUno(LinkedList* pArrayList)
{
    int len;
    int i;
    void* puntero;
    int returnValue=-1;

    if(pArrayList!=NULL)
    {
        len=ll_len(pArrayList);
        for(i=0;i<len;i++)
        {
            puntero=ll_get(pArrayList,i);
            returnValue=competitor_saveDNI(puntero);
        }
    }

    return returnValue;
}

LinkedList* controller_crearLLfinalistas(LinkedList* pArrayList)
{
    LinkedList* nueva;

    if(pArrayList!=NULL)
    {
        // Llamo LL filterv2
        nueva=ll_filterv2(pArrayList,competitor_compararPuntaje);
    }

    return nueva;
}
