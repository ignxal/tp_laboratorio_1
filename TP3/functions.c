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

int isAlphabetic(char array[])
{
    int i;
    int flag=0;

    for(i=0; array[i]!='\0'; i++)
    {
        if((array[i]<'a' || array[i]>'z') && (array[i]<'A' || array[i]>'Z'))
        {
            flag=1;
            break;
        }
    }

    return flag;
}

void getString(char message[], char errorMessage[], char array[])
{

    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", array);

    while(isAlphabetic(array)==1)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%[^\n]", array);
    }
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

char getChar(char message[], char errorMessage[], char a, char b)
{
    char character;

        printf("%s", message);
        fflush(stdin);
        scanf("%c", &character);

        while (character!= a && character!= b)
        {
            printf("%s", errorMessage);
            fflush(stdin);
            scanf("%c", &character);
        }

    return character;
}

