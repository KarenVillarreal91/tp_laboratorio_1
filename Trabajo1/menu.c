#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(int x, int y, int flagUno, int flagDos)
{
    int respuesta;

    printf("------------ Menu ------------\n");

    if(flagUno == 0)
    {
        printf("1. Ingresar primer operando.\n");
    }
    else
    {
        printf("1. Ingresar primer operando. Actual: %d\n",x);
    }

    if(flagDos == 0)
    {
        printf("2. Ingresar segundo operando.\n");
    }
    else
    {
        printf("2. Ingresar segundo operando. Actual: %d\n",y);

    }
    printf("3. Calcular todas las operaciones.\n");
    printf("4. Informar resultado.\n");
    printf("5. Salir.\n");
    printf("------------------------------\n");
    printf("\nIngrese una opcion: ");
    scanf("%d",&respuesta);

    return respuesta;
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

    if(x > 12 || x < 0)
    {
        printf("Error! El numero a factorizar es mayor a 12 o es menor a 0, ingrese otro operando para obtener un resultado.\n");
    }
    else
    {
        printf("El factorial de %d es: %d\n",x,factorialUno);

    }

    if(y > 12 || y < 0)
    {
        printf("Error! El numero a factorizar es mayor a 12 o es menor a 0, ingrese otro operando para obtener un resultado.\n");
    }
    else
    {
        printf("El factorial de %d es: %d\n",y,factorialDos);
    }
}
