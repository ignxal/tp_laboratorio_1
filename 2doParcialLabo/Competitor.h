#ifndef competitor_H_INCLUDED
#define competitor_H_INCLUDED
#include "Linkedlist.h"

typedef struct
{
    int numeroConcursante;
    int anio;
    char nombre[100];
    char dni[100];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntaje;
    int puntajeSegundaRonda;
    float promedio;
}Competitor;

Competitor* competitor_new();
Competitor* competitor_newParametros(char* numeroConcursanteStr, char* anioStr, char* nombreStr, char* dniStr, char* fechaPresentacionStr, char* temaPresentacionStr, char* puntajeStr);

void competitor_print(Competitor* aCompetitor, int evaluoFlag);

int competitor_setNumeroConcursante(Competitor* this,int numeroConcursante);
int competitor_getNumeroConcursante(Competitor* this,int* numeroConcursante);

int competitor_setAnio(Competitor* this,int anio);
int competitor_getAnio(Competitor* this,int* anio);

int competitor_setNombre(Competitor* this,char* nombre);
int competitor_getNombre(Competitor* this,char* nombre);

int competitor_setDni(Competitor* this,char* dni);
int competitor_getDni(Competitor* this,char* dni);

int competitor_setFechaPresentacion(Competitor* this,char* fechaPresentacion);
int competitor_getFechaPresentacion(Competitor* this,char* fechaPresentacion);

int competitor_setTemaPresentacion(Competitor* this,char* temaPresentacion);
int competitor_getTemaPresentacion(Competitor* this,char* temaPresentacion);

int competitor_setPuntaje(Competitor* this,int puntaje);
int competitor_getPuntaje(Competitor* this,int* puntaje);

int competitor_setPuntajeSegundaRonda(Competitor* this, int puntajeSegundaRonda);
int competitor_getPuntajeSegundaRonda(Competitor* this, int* puntajeSegundaRonda);

int competitor_setPromedio(Competitor* this, float promedio);
int competitor_getPromedio(Competitor* this, float* promedio);

int competitor_generarSegundaNota(Competitor* this);
int competitor_generarPromedio(Competitor* this);

int competitor_saveDNI(Competitor* this);
int competitor_buscarPuntajeMenorADiez(Competitor* this);
float competitor_getMejorPromedio(LinkedList* pArrayList);

int competitor_compararPuntaje(Competitor* e1, int mejorPuntaje);
int competitor_getMejoresPuntajes(LinkedList* pArrayList);

#endif // competitor_H_INCLUDED
