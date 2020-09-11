#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculos.h"

int main()
{
    //Declaracion e inicio de las variables
    int a = 0;
    int b = 0;
    int suma;
    int resta;
    float division = 0;
    int multiplicacion;
    int factorialUno;
    int factorialDos;
    char confirmar;
    //Flag para verificar que se realizaron los calculos
    int flagCalculos = 0;
    //Flags para mostrar los numeros ingresados en el menu y validar el ingreso durante el programa
    int flagOperandoUno = 0;
    int flagOperandoDos = 0;
    //Se inicia con un do-while
    do
    {
        switch(menu(a,b,flagOperandoUno,flagOperandoDos)) //Switch que empieza con la funcion menu
        {
            case 1: //Caso 1 pide el primer numero
                a = pedirOperando(a);
                flagOperandoUno = 1; //Flag del primer numero en 1
            break;

            case 2: //Caso 2 pide el segundo numero
                b = pedirOperando(b);
                flagOperandoDos = 1; //Flag del segundo numero en 2
            break;

            case 3: //Caso 3 se inician las funciones de calculo siempre y cuando cumpla lo requerido
                if(flagOperandoUno == 0 || flagOperandoDos == 0) //Verifica que se ingresaron los operandos
                {
                    errorOperando(); //Se muestra un error en el caso de que no se ingresen los operandos
                }
                else
                {
                    flagCalculos = 1;
                    suma = sumando(a,b); //Se llama a la funcion sumando y se asigna el resultado
                    resta = restando(a,b); //Se llama a la funcion restando y se asigna el resultado
                    multiplicacion = multiplicar(a,b); //Se llama a la funcion multiplicar y se asigna el resultado

                    if(b != 0) //En el caso que el segundo operando no sea 0
                    {
                        division = dividiendo(a,b); //Se llama a la funcion dividiendo y se asigna el resultado
                    }
                    else //Si es 0, se informa que no se pudo realizar
                    {
                        printf("\nNo se pudo calcular division.\n");
                    }

                    if(a > 12 || a < 0) //En el caso que el primer operando sea mayor a 12 o menor a 0
                    {
                        printf("\nNo se pudo calcular el factorial del primer operando.\n"); //Se informa que no se pudo realizar
                    }
                    else //Si no se cumple lo anterior, se llama a la funcion factorizar y se asigna el resultado
                    {
                        factorialUno = factorizar(a);
                    }

                    if(b > 12 || b < 0) //En el caso que el segundo operando sea mayor a 12 o menor a 0
                    {
                        printf("\nNo se pudo calcular el factorial del segundo operando.\n"); //Se informa que no se pudo realizar
                    }
                    else //Si no se cumple lo anterior, se llama a la funcion factorizar y se asigna el resultado
                    {
                        factorialDos = factorizar(b);
                    }

                    printf("\nFinalizado correctamente!\n\n"); //Se informa que se realizaron los calculos
                }
            break;

            case 4: //Caso 4 se muestran los resultados siempre y cuando se cumpla lo requerido
                if(flagOperandoUno == 0 || flagOperandoDos == 0) //Verifica que se ingresaron los operandos
                {
                    errorOperando(); //Se muestra un error en el caso de que no se ingresen los operandos
                }
                else if(flagCalculos == 0) //Verifica que se realizaron las operaciones primero
                {
                    printf("\nError! Realice los calculos primero (Opcion 3).\n\n"); //Se muestra un error en el caso que no
                }
                else //Si se ingresaron correctamente se muestran todos los resultados
                {
                    mostrarResultados(a,b,suma,resta,division,multiplicacion,factorialUno,factorialDos);
                }
            break;

            case 5: //Caso 5 se pregunta al usuario si quiere salir del programa
                printf("\nDesea salir? s/n: ");
                fflush(stdin);
                scanf("%c",&confirmar);
            break;
        }

        system("pause"); //Se pausa el programa
        system("cls"); //Se limpia la pantalla

    }while(confirmar != 's'); //El programa termina cuando el usuario escribe "s" en el caso 5

    return 0;
}

