#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Competitor.h"

int parser_CompetitorFromText(FILE* pFile , LinkedList* pArrayListCompetitor)
{
	Competitor* pCompetitor;
	char numeroConcursanteStr[100];
	char anioStr[100];
	char nombreStr[100];
	char dniStr[100];
	char fechaPresentacionStr[100];
	char temaPresentacionStr[100];
	char puntajeStr[100];
    int returnValue = -1;
	int howMany;

	if(pFile != NULL && pArrayListCompetitor != NULL)
	{
	    howMany= fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", numeroConcursanteStr, anioStr, nombreStr, dniStr, fechaPresentacionStr, temaPresentacionStr, puntajeStr); // header
		while(!feof(pFile))
		{
		    howMany= fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", numeroConcursanteStr, anioStr, nombreStr, dniStr, fechaPresentacionStr, temaPresentacionStr, puntajeStr);
			if(howMany == 7)
			{
				pCompetitor = competitor_newParametros(numeroConcursanteStr, anioStr, nombreStr, dniStr, fechaPresentacionStr, temaPresentacionStr, puntajeStr);

				if(pCompetitor != NULL)//si cargo
				{
					returnValue=ll_add(pArrayListCompetitor, pCompetitor);
				}
			}
        }
	}

    return returnValue;
}

int parser_aCompetitorToText(FILE* pFile, Competitor* pCompetitor)
{
    int returnValue=-1;
    int numeroConcursante;
    int anio;
    char nombre[100];
    char dni[100];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntaje;
    int puntajeSegundaRonda;
    float promedio;

    if(competitor_getNumeroConcursante(pCompetitor, &numeroConcursante)==1 && competitor_getAnio(pCompetitor, &anio)==1 &&
        competitor_getNombre(pCompetitor, nombre)==1 && competitor_getDni(pCompetitor, dni)==1 && competitor_getFechaPresentacion(pCompetitor, fechaPresentacion)==1 &&
        competitor_getTemaPresentacion(pCompetitor, temaPresentacion)==1 && competitor_getPuntaje(pCompetitor, &puntaje)==1 && competitor_getPuntajeSegundaRonda(pCompetitor, &puntajeSegundaRonda)==1
        && competitor_getPromedio(pCompetitor, &promedio)==1)
        {
            fprintf(pFile, "%d,%d,%s,%s,%s,%s,%d,%d,%.2f\n", numeroConcursante, anio, nombre, dni, fechaPresentacion, temaPresentacion, puntaje, puntajeSegundaRonda, promedio);
            returnValue=0;
        }

    return returnValue;
}

int parser_CompetitorToText(FILE* pFile , LinkedList* pArrayListCompetitor)
{
    Competitor* pCompetitor;
    int i;
    int len;
    int returnValue=-1;

    if(pFile != NULL && pArrayListCompetitor != NULL)
    {
        fprintf(pFile, "numeroConcursante,anio,nombre,dni,fechaPresentacion,temaPresentacion,puntaje,puntajeSegundaRonda,promedio\n");
        len=ll_len(pArrayListCompetitor);
        for (i=0; i<len; i++)
        {
            // Trae competidor
            pCompetitor=(Competitor*)ll_get(pArrayListCompetitor,i);
            // Competidor pasa a parser
            returnValue=parser_aCompetitorToText(pFile, pCompetitor);
        }
    }
    return returnValue;
}
