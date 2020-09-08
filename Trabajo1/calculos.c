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
    int resultado = 1;
    int i;

    for(i = x; i > 0; i--)
    {
        resultado = resultado * i;
    }

    return resultado;
}
