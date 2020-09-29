//      Karen Villarreal 1B
//      Trabajo Practico N°2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesEmpleados.h"

int main()
{
    int respuesta;
    int retorno;
    int idIngresado;
    int crearId = 99;   //Se inicializa un contador en 99 para crear las ID

    Employee listaEmpleados[TAM];

    retorno = initEmployees(listaEmpleados,TAM);         //Inicializa todos los cupos en VACIO

    if(retorno == 0)       //Si se inicializo correctamente se inicia el programa
    {
        do
        {
            switch(menu())      //Menu que devuelve la opcion elegida
            {
                case 1: //1. Llama a la funcion para crear un empleado
                    crearId++;      //Se suma 1 cada vez que ingrese a la opcion 1

                    if(crearUnEmpleado(listaEmpleados,TAM,crearId) != 0)    //Comprueba que se creo correctamente
                    {
                        crearId--;      //Si no se completo el ingreso se resta 1
                    }
                break;

                case 2: //2. Llama a las funciones para modificar un empleado
                    if(contarEmpleados(listaEmpleados,TAM) > 0)        //Si el contador devuelve 0 no deja continuar
                    {
                        idIngresado = pedirId(listaEmpleados,TAM,crearId);          //Pide el ID, verifica y devuelve
                        modificarEmpleado(listaEmpleados,TAM,idIngresado);  //Funcion para modificar al empleado
                    }
                    else
                    {
                        printf("\nError! No hay empleados ingresados.\n\n");
                    }
                break;

                case 3: //3. Llama a las funciones para borrar un empleado
                    if(contarEmpleados(listaEmpleados,TAM) > 0)         //Si el contador devuelve 0 no deja continuar
                    {
                        idIngresado = pedirId(listaEmpleados,TAM,crearId);          //Pide el ID, verifica y devulve
                        removeEmployee(listaEmpleados,TAM,idIngresado);     //Funcion para borrar un empleado
                    }
                    else
                    {
                        printf("\nError! No hay empleados ingresados.\n\n");
                    }
                break;

                case 4: //4. Llama a la funcion para mostrar a los empleados ordenados y el informe sobre los salarios
                    if(contarEmpleados(listaEmpleados,TAM) > 0)         //Si el contador devuelve 0 no deja continuar
                    {
                        informesEmpleados(listaEmpleados,TAM);
                    }
                    else
                    {
                        printf("\nError! No hay empleados ingresados.\n\n");
                    }
                break;

                case 5: //5. Salida, confirma que el usario quiere salir del programa
                    respuesta = confirmar();
                break;
            }

            system("pause");
            system("cls");
        }while(respuesta != 's');       //Mientras el usario no responda "s" continua el programa
    }
    else
    {
        printf("\nHubo un error en cargar el programa.\n\n");
    }

    return 0;
}
