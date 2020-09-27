#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(int x, int y, int flagUno, int flagDos)
{
    int respuesta;

    printf("------------ Menu ------------\n");

    if(flagUno == 0) //En el caso que no se ingreso el primer operando
    {
        printf("1. Ingresar primer operando.\n");
    }
    else //Si se ingreso muestra el operando ingresado
    {
        printf("1. Ingresar primer operando. Actual: %d\n",x);
    }

    if(flagDos == 0) //En el caso que no se ingreso el segundo operando
    {
        printf("2. Ingresar segundo operando.\n");
    }
    else //Si se ingreso muestra el operando ingresado
    {
        printf("2. Ingresar segundo operando. Actual: %d\n",y);

    }
    printf("3. Calcular todas las operaciones.\n");
    printf("4. Informar resultado.\n");
    printf("5. Salir.\n");
    printf("------------------------------\n");
    printf("\nIngrese una opcion: "); //Se pide el ingreso de una opcion y se guarda
    scanf("%d",&respuesta);

    return respuesta;
}

int pedirOperando(int x)
{
    printf("\nIngrese el operando: "); //Se pide un operando y se guarda
    scanf("%d",&x);

    while(x > 514748360 || x < -514748360) //Se limita la capacidad del operando
    {
        printf("\nError!! El operando supera las capacidades, ingreselo de nuevo: ");
        scanf("%d",&x);
    }

    return x;
}

void errorOperando()
{
    printf("\nError! Ingrese los operandos primero.\n\n");
}

void mostrarResultados(int x,int y, int suma, int resta, float division, int multiplicacion, int factorialUno, int factorialDos)
{
    printf("\nLa suma de %d y %d es: %d\n",x,y,suma); //Se muestra el resultado de la suma
    printf("La resta de %d y %d es: %d\n",x,y,resta); //Se muestra el resultado de la resta

    if(y == 0) //En el caso que el segundo operando sea 0 se muestra el error
    {
        printf("Error! No se puede dividir entre 0, ingrese otro operando para obtener un resultado.\n");
    }
    else //Si no, se muestra el resultado de la division
    {
        printf("La division de %d y %d es: %.2f\n",x,y,division);
    }

    printf("La multiplicacion de %d y %d es: %d\n",x,y,multiplicacion); //Se muestra el resultado de la multiplicacion

    if(x > 12 || x < 0) //En el caso que el primer operando sea mayor a 12 o menor a 0 se muestra el error
    {
        printf("Error! El primer numero a factorizar es mayor a 12 o es menor a 0, ingrese otro operando para obtener un resultado.\n");
    }
    else
    {
        printf("El factorial de %d es: %d\n",x,factorialUno);

    }

    if(y > 12 || y < 0) //En el caso que el segundo operando sea mayor a 12 o menor a 0 se muestra el error
    {
        printf("Error! El segundo numero a factorizar es mayor a 12 o es menor a 0, ingrese otro operando para obtener un resultado.\n");
    }
    else //Si no, se muestra el resultado del segundo operando
    {
        printf("El factorial de %d es: %d\n",y,factorialDos);
    }
}
