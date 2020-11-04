#include <stdio.h>
#include <string.h>

float getFloat(char message[])
{
    float number;
    printf("%s", message);
    scanf("%f", &number);

    return number;
}

int getInt(char message[])
{
    int number;
    printf("%s", message);
    scanf("%d", &number);

    return number;
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

int getIntVal(char message[], char errorMessage[], int min, int max)
{
    int value;

    printf("%s", message);
    scanf("%d", &value);
    while (value < min || value > max)
    {
        printf("%s", errorMessage);
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
