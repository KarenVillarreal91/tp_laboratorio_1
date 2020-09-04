#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int sumando(int x, int y)
{
    int resultado;

    resultado = x + y;

    return resultado;
}

int restando(int x, int y)
{
    int resultado;

    resultado = x - y;

    return resultado;
}

float dividiendo(int x, int y)
{
    float resultado;

    resultado = (float) x / y;

    return resultado;
}

int multiplicar(int x, int y)
{
    int resultado;

    resultado = x * y;

    return resultado;
}

int factorizar(int x)
{
    int resultado;

    if(x == 1 || x == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = x * factorizar(x - 1);
    }

    return resultado;
}

int pedirOperando(int x)
{
    printf("\nIngrese el operando: ");
    scanf("%d",&x);

    return x;
}

void errorOperando()
{
    printf("\nError! Ingrese los operandos primero.\n");
}

void mostrarResultados(int x,int y, int suma, int resta, float division, int multiplicacion, int factorialUno, int factorialDos)
{
    printf("\nLa suma de %d y %d es: %d\n",x,y,suma);
    printf("La resta de %d y %d es: %d\n",x,y,resta);

    if(y == 0)
    {
        printf("Error! No se puede dividir entre 0, ingrese otro operando para obtener un resultado.\n");
    }
    else
    {
        printf("La division de %d y %d es: %.2f\n",x,y,division);
    }

    printf("La multiplicacion de %d y %d es: %d\n",x,y,multiplicacion);
    printf("El factorial de %d es: %d\n",x,factorialUno);
    printf("El factorial de %d es: %d\n",y,factorialDos);
}
