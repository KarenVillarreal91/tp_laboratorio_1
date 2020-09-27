#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TAM 1000
#define VACIO 0
#define OCUPADO 1

int main()
{
    int respuesta;
    int retorno;
    int idIngresado;
    int flagIngresado = 0;

    Employee listaEmpleados[TAM];

    hardCodearEmpleados(listaEmpleados,TAM);

    retorno = initEmployees(listaEmpleados,TAM);

    for(int i = 0; i < 6; i++)
    {
        listaEmpleados[i].isEmpty = OCUPADO;
    }

    if(retorno == 0)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    if(crearUnEmpleado(listaEmpleados,TAM) == 0)
                    {
                       flagIngresado = 1;
                    }
                break;

                case 2:
                    if(flagIngresado == 1)
                    {
                        idIngresado = pedirId(listaEmpleados,TAM);
                        modificarEmpleado(listaEmpleados,TAM,idIngresado);
                    }
                    else
                    {
                        printf("\nError! Ingrese los empleados primero.\n\n");
                    }
                break;

                case 3:
                    if(flagIngresado == 1)
                    {
                        idIngresado = pedirId(listaEmpleados,TAM);
                        removeEmployee(listaEmpleados,TAM,idIngresado);
                    }
                    else
                    {
                        printf("\nError! Ingrese los empleados primero.\n\n");
                    }
                break;

                case 4:
                    if(flagIngresado == 1)
                    {
                        informesEmpleados(listaEmpleados,TAM);
                    }
                    else
                    {
                        printf("\nError! Ingrese los empleados primero.\n\n");
                    }
                break;

                case 5:
                    respuesta = confirmar();
                break;
            }
            system("pause");
            system("cls");
        }while(respuesta != 's');
    }
    else
    {
        printf("\nHubo un error en cargar el programa.\n\n");
    }

    return 0;
}
