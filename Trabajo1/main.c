#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculos.h"

int main()
{
    int a;
    int b;
    int suma;
    char confirmar;

    do
    {
        switch(menu())
        {
            case 1:
                printf("\nIngrese el primer numero: ");
                scanf("%d",&a);
            break;

            case 2:
                printf("\nIngrese el segundo numero: ");
                scanf("%d",&b);
            break;

            case 3:
                suma = sumando(a,b);
            break;

            case 4:
                printf("%d\n",suma);
            break;

            case 5:
                printf("\nDesea salir? s/n: \n\n");
                scanf("%c",&confirmar);
            break;
        }

        system("pause");
        system("cls");

    }while(confirmar != 's');

    return 0;
}

