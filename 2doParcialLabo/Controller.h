#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED
#include "Linkedlist.h"
#include "Competitor.h"
int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_ListCompetitor(LinkedList* pArrayList, int flag);
int controller_saveAsText(char* path , LinkedList* pArrayList);

int controller_generarSegundaNota(LinkedList* pArrayList);
int controller_generarPromedio(LinkedList* pArrayList);

int controller_contarPuntaje(LinkedList* pArrayList);
void controller_mostrarContador(int cantidad);
int controller_guardarDato(LinkedList* pArrayList, int (*pFunc)(void*));

int controller_buscarSiEsMejorPromedio(Competitor* this, float mejorPromedio);
LinkedList* controller_crearLLmejorPromedio(LinkedList* pArrayList);

int controller_guardarMejoresPuntajesRondaUno(LinkedList* pArrayList);
LinkedList* controller_crearLLfinalistas(LinkedList* pArrayList);

#endif // controller_H_INCLUDED
