#include <stdio.h>
#include <string.h>

float getFloat(char mensaje[])
{
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);

    return numero;
}

int getInt(char mensaje[])
{
    int numero;
    printf("%s", mensaje);
    scanf("%d", &numero);

    return numero;
}

void getString(char mensaje[], char dato[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", dato);
}

void operationConfirmation(int index)
{
    switch (index)
    {
        case -1:
        printf("\n###### Error al realizar la operacion ######\n\n");
        break;
        case 0:
        printf("\n###### Operacion realizada con exito ######\n\n");
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

