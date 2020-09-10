#include <stdio.h>

int menu(char mensaje[]) 
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    
    return opcion;
}

float getFloat(char mensaje[])
{
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
        
    return numero;
}

float doSum (float A, float B)
{
    float resultado;
    resultado = A+B;
    
    return resultado;
}

float doSub (float A, float B)
{
    float resultado;
    resultado = A-B;
    
    return resultado;
}

float doMul (float A, float B)
{
    float resultado;
    resultado = A*B;
    
    return resultado;
}

float doDiv (float A, float B)
{
    float resultado;
    
    if (B!=0)
    {
        resultado = A/B;
    }
    
    else
    {
        resultado = 0;
    }
    
    return resultado;
}

long long int doFact (float A)
{
    long long int factorial = 1; 
    
    if (A == (int) A && A >= 0) //valida si el operador es entero y no negativo.
    {
        for (int i = 1; i <= A; i++)
        {
            factorial *= i;
        }
        return factorial;
    }
    
    else if (A < 0)
    {
        factorial = -2; //indicacion de operador negativo
    }
    
    else 
    { 
        factorial = -1; //indicacion de operador no entero
    }
    
    return factorial;
}

void showResults (float suma, float resta, float multiplicacion, float division, int flag, long long int factorialA, long long int factorialB)
{
    if (flag==1) //valida si los calculos se realizaron previamente
    {
        printf("La suma es: %.2f\n", suma);
        printf("La resta es: %.2f\n", resta);
        printf("La multiplicacion es: %.2f\n", multiplicacion);
    if (division!=0) 
    {
        printf("La division es %.2f\n", division);
    }
    else 
    {
        printf("No se puede dividir por 0.\n");
    }
    
    if (factorialA== -2) 
    {
        printf("Error. El numero es negativo\n");
    }
    else if (factorialA == -1) 
    {
        printf("Error. El numero no es entero\n");
    }
    else 
    {
        printf("El factorial de A es %lli\n", factorialA);
    }
    
    if (factorialB== -2) 
    {
        printf("Error. El numero es negativo\n");
    }
    else if (factorialB == -1) 
    {
        printf("Error. El numero no es entero\n");
    }
    else 
    {
        printf("El factorial de B es %lli\n", factorialB);
    }
    
    }
    else 
    {
        printf("Error. Calcule las operaciones primero.\n");
    }
}