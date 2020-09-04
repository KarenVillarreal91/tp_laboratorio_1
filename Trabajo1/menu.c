#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(int x, int y, int flagUno, int flagDos)
{
    system("cls");

    int respuesta;

    printf("------ Menu ------\n");

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
    printf("\nIngrese una opcion: ");
    scanf("%d",&respuesta);


    return respuesta;
}
