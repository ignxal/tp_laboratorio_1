#include <stdio.h>
#include <string.h>

int menu(char mensaje[]) 
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    
    return opcion;
}

int getInt(char mensaje[])
{
    int numero;
    printf("%s", mensaje);
    scanf("%d", &numero);
        
    return numero;
}

float getFloat(char mensaje[])
{
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
        
    return numero;
}

void getString(char mensaje[], char dato[])
{
    int len;
    
    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%[^\n]", dato);
}

void operationConfirmation(int index)
{
    switch (index)
    {
        case -1:
        printf("\n###### Error al realizar la operación ######\n\n");
        break;
        case 0:
        printf("\n###### Operación realizada con éxito ######\n\n");
        break;
    }
}

int getIntVal(char message[], char messageError[], int min, int max)
{
    int value;
    
    printf("%s", message);
    scanf("%d", &value);
    while (value < min || value > max)
    {
        printf("%s", messageError);
        scanf("%d", &value);
    }
    
    return value;
}