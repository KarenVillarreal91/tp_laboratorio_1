#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculos.h"

int main()
{
    int a = 0;
    int b = 0;
    int suma;
    int resta;
    float division = 0;
    int multiplicacion;
    int factorialUno;
    int factorialDos;
    int flagOperandoUno = 0;
    int flagOperandoDos = 0;
    char confirmar;

    do
    {
        switch(menu(a,b,flagOperandoUno,flagOperandoDos))
        {
            case 1:
                a = pedirOperando(a);
                flagOperandoUno = 1;
            break;

            case 2:
                b = pedirOperando(b);
                flagOperandoDos = 1;
            break;

            case 3:
                if(flagOperandoUno == 0 || flagOperandoDos == 0)
                {
                    errorOperando();

                }
                else
                {
                    suma = sumando(a,b);
                    resta = restando(a,b);
                    multiplicacion = multiplicar(a,b);
                    factorialUno = factorizar(a);
                    factorialDos = factorizar(b);

                    if(b == 0)
                    {
                        printf("\nCalculos completados menos division.\n");
                    }
                    else
                    {
                        division = dividiendo(a,b);
                        printf("\nCalculos completados.\n");
                    }
                }
            break;

            case 4:
                if(flagOperandoUno == 0 || flagOperandoDos == 0)
                {
                    errorOperando();
                }
                else
                {
                    mostrarResultados(a,b,suma,resta,division,multiplicacion,factorialUno,factorialDos);
                }
            break;

            case 5:
                printf("\nDesea salir? s/n: ");
                fflush(stdin);
                scanf("%c",&confirmar);
            break;
        }

        system("pause");
        system("cls");

    }while(confirmar != 's');

    return 0;
}

