#include <stdio.h>
#include <stdlib.h>
#include "Competitor.h"
#include "parser.h"
#include "funciones.h"
#include <string.h>

Competitor* competitor_new()
{
    Competitor* pointer;

    pointer = (Competitor*) malloc(sizeof(Competitor));

    if (pointer!=NULL)
    {
        competitor_setNumeroConcursante(pointer, 0);
        competitor_setAnio(pointer, 0);
        competitor_setNombre(pointer, "\0");
        competitor_setDni(pointer, "\0");
        competitor_setFechaPresentacion(pointer, "\0");
        competitor_setTemaPresentacion(pointer, "\0");
        competitor_setPuntaje(pointer, 0);
    }

    return pointer;
}

Competitor* competitor_newParametros(char* numeroConcursanteStr, char* anioStr, char* nombreStr, char* dniStr, char* fechaPresentacionStr, char* temaPresentacionStr, char* puntajeStr)
{
    Competitor* pointer;
    int numeroConcursante;
    int anio;
    char nombre[100];
    char dni[100];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntaje;
    int numeroConcursanteFlag;
    int anioFlag;
    int nombreFlag;
    int dniFlag;
    int fechaPresentacionFlag;
    int temaPresentacionFlag;
    int puntajeFlag;

    pointer=competitor_new();

    if(pointer!=NULL && numeroConcursanteStr!=NULL && anioStr!=NULL && nombreStr!=NULL && dniStr!=NULL && fechaPresentacionStr!=NULL && temaPresentacionStr!=NULL && puntajeStr!=NULL)
    {

        numeroConcursante = atoi(numeroConcursanteStr);
        numeroConcursanteFlag= competitor_setNumeroConcursante(pointer, numeroConcursante);

        if(numeroConcursanteFlag==1)
        {
            anio=atoi(anioStr);
            anioFlag=competitor_setAnio(pointer,anio);
            if(anioFlag==1)
            {
                strcpy(nombre, nombreStr);
                nombreFlag=competitor_setNombre(pointer, nombre);
                if(nombreFlag==1)
                {
                    strcpy(dni, dniStr);
                    dniFlag=competitor_setDni(pointer, dni);
                    if(dniFlag==1)
                    {
                        strcpy(fechaPresentacion,fechaPresentacionStr);
                        fechaPresentacionFlag=competitor_setFechaPresentacion(pointer,fechaPresentacion);
                        if(fechaPresentacionFlag==1)
                        {
                            strcpy(temaPresentacion, temaPresentacionStr);
                            temaPresentacionFlag=competitor_setTemaPresentacion(pointer,temaPresentacion);
                            if(temaPresentacionFlag==1)
                            {
                                puntaje=atoi(puntajeStr);
                                puntajeFlag=competitor_setPuntaje(pointer, puntaje);
                            }
                        }
                    }
                }
            }
        }
    }

    if(puntajeFlag!=1)
    {
        free(pointer);
        pointer=NULL;
        printf("Error en setters\n");
    }

    return pointer;
}

void competitor_print(Competitor* aCompetitor, int evaluoFlag)
{
    int numeroConcursante;
    int anio;
    char nombre[100];
    char dni[100];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntaje;
    int puntajeDos;
    float promedio;
    int numeroConcursanteFlag;
    int anioFlag;
    int nombreFlag;
    int dniFlag;
    int fechaPresentacionFlag;
    int temaPresentacionFlag;
    int puntajeFlag;
    int puntajeDosFlag=0;
    int promedioFlag=0;

    numeroConcursanteFlag=competitor_getNumeroConcursante(aCompetitor, &numeroConcursante);
    anioFlag=competitor_getAnio(aCompetitor, &anio);
    nombreFlag=competitor_getNombre(aCompetitor, nombre);
    dniFlag=competitor_getDni(aCompetitor, dni);
    fechaPresentacionFlag=competitor_getFechaPresentacion(aCompetitor, fechaPresentacion);
    temaPresentacionFlag=competitor_getTemaPresentacion(aCompetitor, temaPresentacion);
    puntajeFlag=competitor_getPuntaje(aCompetitor, &puntaje);

    if(evaluoFlag==0)
    {
        if ((numeroConcursanteFlag==1)&& (anioFlag==1) && (nombreFlag==1) && (dniFlag==1) && (fechaPresentacionFlag==1) && (temaPresentacionFlag==1) && (puntajeFlag==1))
        {
            printf("|%8d|%10d|%13s|%10s|%11s|%25s|%9d|\n", numeroConcursante, anio, nombre, dni, fechaPresentacion, temaPresentacion, puntaje);
        }
    }
    else
    {
        puntajeDosFlag=competitor_getPuntajeSegundaRonda(aCompetitor, &puntajeDos);
        promedioFlag=competitor_getPromedio(aCompetitor, &promedio);

        if(puntajeDosFlag==1 && promedioFlag==1)
        {
            printf("|%8d|%10d|%13s|%10s|%11s|%25s|%9d|%11d|%10.2f|\n", numeroConcursante, anio, nombre, dni, fechaPresentacion, temaPresentacion, puntaje, puntajeDos, promedio);
        }
    }
}

// SETTERS Y GETTERS

int competitor_setNumeroConcursante(Competitor* this,int numeroConcursante)
{
    int retorno=0;
    if(numeroConcursante>0 && this!=NULL)
    {
        this->numeroConcursante=numeroConcursante;
        retorno=1;
    }
    return retorno;
}
int competitor_getNumeroConcursante(Competitor* this,int* numeroConcursante)
{
    int retorno=0;
    if(numeroConcursante!=NULL && this!=NULL)
    {
        *numeroConcursante=this->numeroConcursante;
        retorno=1;
    }
    return retorno;

}

int competitor_setAnio(Competitor* this,int anio)
{
    int retorno=0;
    if(anio>0 && this != NULL)
    {
        this->anio=anio;
        retorno=1;
    }
    return retorno;
}
int competitor_getAnio(Competitor* this,int* anio)
{
    int retorno=0;
    if(anio!=NULL && this != NULL)
    {
        *anio=this->anio;
        retorno=1;
    }
    return retorno;
}

int competitor_setNombre(Competitor* this,char* nombre)
{
    int retorno=0;
    if(nombre!=NULL && this!=NULL)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int competitor_getNombre(Competitor* this,char* nombre)
{
    int retorno=0;
    if(nombre!=NULL && this!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=1;
    }
    return retorno;
}

int competitor_setDni(Competitor* this,char* dni)
{
    int retorno=0;
    if(dni!=NULL && this!=NULL)
    {
        strcpy(this->dni, dni);
        retorno=1;
    }
    return retorno;
}
int competitor_getDni(Competitor* this,char* dni)
{
    int retorno=0;
    if(dni!=NULL && this!=NULL)
    {
        strcpy(dni, this->dni);
        retorno=1;
    }
    return retorno;
}

int competitor_setFechaPresentacion(Competitor* this,char* fechaPresentacion)
{
    int retorno=0;
    if(fechaPresentacion!=NULL && this!=NULL)
    {
        strcpy(this->fechaPresentacion,fechaPresentacion);
        retorno=1;
    }
    return retorno;
}
int competitor_getFechaPresentacion(Competitor* this,char* fechaPresentacion)
{
    int retorno=0;
    if(fechaPresentacion!=NULL && this!=NULL)
    {
        strcpy(fechaPresentacion, this->fechaPresentacion);
        retorno=1;
    }
    return retorno;
}

int competitor_setTemaPresentacion(Competitor* this,char* temaPresentacion)
{
    int retorno=0;
    if(temaPresentacion!=NULL && this!=NULL)
    {
        strcpy(this->temaPresentacion, temaPresentacion);
        retorno=1;
    }
    return retorno;
}

int competitor_getTemaPresentacion(Competitor* this,char* temaPresentacion)
{
    int retorno=0;
    if(temaPresentacion!=NULL && this!=NULL)
    {
        strcpy(temaPresentacion, this->temaPresentacion);
        retorno=1;
    }
    return retorno;
}

int competitor_setPuntaje(Competitor* this,int puntaje)
{
    int retorno=0;
    if(puntaje>=0 && this!=NULL)
    {
        this->puntaje=puntaje;
        retorno=1;
    }
    return retorno;
}

int competitor_getPuntaje(Competitor* this,int* puntaje)
{
    int retorno=0;
    if(puntaje!=NULL && this!=NULL)
    {
        *puntaje=this->puntaje;
        retorno=1;
    }
    return retorno;
}

int competitor_setPuntajeSegundaRonda(Competitor* this, int puntajeSegundaRonda)
{
    int retorno=0;
    if(puntajeSegundaRonda>=0 && this!=NULL)
    {
        this->puntajeSegundaRonda=puntajeSegundaRonda;
        retorno=1;
    }
    return retorno;
}

int competitor_getPuntajeSegundaRonda(Competitor* this, int* puntajeSegundaRonda)
{
    int retorno=0;
    if(puntajeSegundaRonda!=NULL && this!=NULL)
    {
        *puntajeSegundaRonda=this->puntajeSegundaRonda;
        retorno=1;
    }
    return retorno;
}
int competitor_setPromedio(Competitor* this, float promedio)
{
    int retorno=0;
    if(promedio>0 && this!=NULL)
    {
        this->promedio=promedio;
        retorno=1;
    }
    return retorno;
}

int competitor_getPromedio(Competitor* this, float* promedio)
{
    int retorno=0;
    if(promedio>0 && this!=NULL)
    {
        *promedio=this->promedio;
        retorno=1;
    }
    return retorno;
}

int competitor_generarSegundaNota(Competitor* this)
{
    int retorno=0;
    int numAl;

    if(this!=NULL)
    {
        numAl=getNumAl(1,100,0);
        retorno=competitor_setPuntajeSegundaRonda(this, numAl);
    }

    return retorno;
}

int competitor_generarPromedio(Competitor* this)
{
    int retorno=0;
    int puntaje;
    int puntajeDos;
    int puntajeFlag;
    int puntajeDosFlag;
    float promedio;

    if(this!=NULL)
    {
        puntajeFlag=competitor_getPuntaje(this, &puntaje);
        puntajeDosFlag=competitor_getPuntajeSegundaRonda(this, &puntajeDos);
        if(puntajeFlag==1 && puntajeDosFlag==1)
        {
            promedio=(float)(puntaje+puntajeDos)/2;
            retorno=competitor_setPromedio(this, promedio);
        }
    }

    return retorno;
}

int competitor_saveDNI(Competitor* this)
{
    FILE* pFile;
    int returnValue=-1;
    char dni[128];

    if(this!=NULL)
    {
        competitor_getDni(this,dni);
        // concateno .csv para crear archivo
        strcat(dni, ".csv");

        pFile=fopen(dni, "w");
        if(pFile!= NULL)
        {
            returnValue=parser_aCompetitorToText(pFile, this);
        }
        fclose(pFile);
    }

    return returnValue;
}

int competitor_buscarPuntajeMenorADiez(Competitor* this)
{
    int puntaje;
    int puntajeFlag;
    int retorno=0;

    if(this!=NULL)
    {
        puntajeFlag=competitor_getPuntaje(this, &puntaje);
        if (puntajeFlag==1 && puntaje<10)
        {
            retorno=1;
            competitor_saveDNI(this);
        }
    }

    return retorno;
}

float competitor_getMejorPromedio(LinkedList* pArrayList)
{
    Competitor* aux;
    int i;
    int len;
    float mejorPromedio;
    float nuevoPromedio;

    if(pArrayList!=NULL)
    {
        len=ll_len(pArrayList);
        for(i=0;i<len;i++)
        {
            aux=(Competitor*)ll_get(pArrayList,i);
            // si es la primera iteracion, carga a ese promedio como el mejor
            if(i==0)
            {
                competitor_getPromedio(aux,&mejorPromedio);
            }
            else
            {
                competitor_getPromedio(aux,&nuevoPromedio);
                if(nuevoPromedio>mejorPromedio)
                {
                    mejorPromedio=nuevoPromedio;
                }
            }
        }

    }

    return mejorPromedio;
}

int competitor_compararPuntaje(Competitor* e1, int mejorPuntaje)
{
    int puntaje1;
    int returnValue=0;

    // Tenia un error que era que comparaba por mayor o menor en vez de igualar

    if(e1!=NULL)
    {
        competitor_getPuntaje(e1, &puntaje1);

       if(puntaje1 == mejorPuntaje)
        {
            returnValue=1;
        }
    }

    return returnValue;
}

int competitor_getMejoresPuntajes(LinkedList* pArrayList)
{
    Competitor* aux;
    int i;
    int len;
    int puntaje;
    int puntajeNuevo;


    if(pArrayList!=NULL)
    {
        len=ll_len(pArrayList);
        for(i=0;i<len;i++)
        {
            aux=(Competitor*)ll_get(pArrayList,i);
            // si es la primera iteracion, carga a ese promedio como el mejor
            if(i==0)
            {
                competitor_getPuntaje(aux,&puntaje);
            }
            else
            {
                competitor_getPuntaje(aux,&puntajeNuevo);
                if(puntajeNuevo>puntaje)
                {
                    puntaje=puntajeNuevo;
                }
            }
        }
    }

    return puntaje;
}

// Primero fue crear un sublist, ordenarlo, devolver esa estructura y de ahi printearlo el tema es que no utilazaria el ll_filterv2 no cumple la consigna
// En vez de usar 3 for, tendria que haber llamado una funcion que lo haga pero no me daba el tiempo(recibe puntero pFunc para criterio y el len)
