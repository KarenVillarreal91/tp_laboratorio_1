#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    system("cls");

    int respuesta;

    printf("------ Menu ------\n");
    printf("1. Ingresar primer operador.\n");
    printf("2. Ingresar segundo operador.\n");
    printf("3. Calcular todas las operaciones.\n");
    printf("4. Informar resultado.\n");
    printf("5. Salir.\n");
    printf("\nIngrese una opcion: ");
    scanf("%d",&respuesta);


    return respuesta;
}
