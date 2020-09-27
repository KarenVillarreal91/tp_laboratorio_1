#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000
#define VACIO 0
#define OCUPADO 1

int main()
{
    int respuesta;
    int retorno;
    int idIngresado;

    Employee listaEmpleados[TAM];

    //hardCodearEmpleados(listaEmpleados,TAM);

    retorno = initEmployees(listaEmpleados,TAM);

    /*for(int i = 0; i < 6; i++)
    {
        listaEmpleados[i].isEmpty = OCUPADO;
    }*/

    if(retorno == 0)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    crearUnEmpleado(listaEmpleados,TAM);
                break;

                case 2:
                    if(contarEmpleados(listaEmpleados,TAM) > 0)
                    {
                        idIngresado = pedirId(listaEmpleados,TAM);
                        modificarEmpleado(listaEmpleados,TAM,idIngresado);
                    }
                    else
                    {
                        printf("\nError! No hay empleados ingresados.\n\n");
                    }
                break;

                case 3:
                    if(contarEmpleados(listaEmpleados,TAM) > 0)
                    {
                        idIngresado = pedirId(listaEmpleados,TAM);
                        removeEmployee(listaEmpleados,TAM,idIngresado);
                    }
                    else
                    {
                        printf("\nError! No hay empleados ingresados.\n\n");
                    }
                break;

                case 4:
                    if(contarEmpleados(listaEmpleados,TAM) > 0)
                    {
                        informesEmpleados(listaEmpleados,TAM);
                    }
                    else
                    {
                        printf("\nError! No hay empleados ingresados.\n\n");
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
