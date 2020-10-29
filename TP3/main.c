#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). -
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). -
     3. Alta de empleado -
     4. Modificar datos de empleado -
     5. Baja de empleado -
     6. Listar empleados -
     7. Ordenar empleados -
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto). -
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario). -
    10. Salir -
*****************************************************/


int main()
{
    char respuesta;

    int flagCargado = 0;
    int cantidadEmpleados;

    LinkedList* lista;
    lista = ll_newLinkedList();

    do
    {
        cantidadEmpleados = ll_len(lista);

        switch(controller_mainMenu(flagCargado))
        {
            case 1:
                if(flagCargado == 0)
                {
                    if(controller_loadFromText("data.csv",lista) == 0)
                    {
                        flagCargado = 1;
                    }
                }
                else
                {
                    printf("\n\n Ya esta cargado el archivo.");
                }
            break;

            case 2:
                if(flagCargado == 0)
                {
                    if(controller_loadFromBinary("data.bin",lista) == 0)
                    {
                        flagCargado = 2;
                    }
                }
                else
                {
                    printf("\n\n Ya esta cargado el archivo.");
                }
            break;

            case 3:
                controller_addEmployee(lista);
            break;

            case 4:
                if(cantidadEmpleados > 0)
                {
                    controller_ListEmployee(lista);
                    controller_editEmployee(lista);
                }
                else
                {
                    printf("\n\n No hay empleados para modificar! Cargue un archivo o algun empleado primero.");
                }
            break;

            case 5:
                if(cantidadEmpleados > 0)
                {
                    controller_ListEmployee(lista);
                    controller_removeEmployee(lista);
                }
                else
                {
                  printf("\n\n No hay empleados para eliminar! Cargue un archivo o algun empleado primero.");
                }
            break;

            case 6:
                if(cantidadEmpleados > 0)
                {
                    controller_ListEmployee(lista);
                }
                else
                {
                  printf("\n\n No hay empleados en la lista! Cargue un archivo o algun empleado primero.");
                }
            break;

            case 7:
                if(cantidadEmpleados > 0)
                {
                    controller_sortEmployee(lista);
                }
                else
                {
                   printf("\n\n No hay empleados en la lista! Cargue un archivo o algun empleado primero.");
                }
            break;

            case 8:
                if(flagCargado == 0)
                {
                   printf("\n\n Aviso! No hay ninguna lista cargada, si guarda se sobreescribiran los empleados.\n\n");
                }

                controller_saveAsText("data.csv",lista);
            break;

            case 9:
                if(flagCargado == 0)
                {
                   printf("\n\n Aviso! No hay ninguna lista cargada, si guarda se sobreescribiran los empleados.\n\n");
                }

                controller_saveAsBinary("data.bin",lista);
            break;

            case 10:
                respuesta = confirmar();
            break;
        }

        printf("\n\n\n");
        system("pause");
        system("cls");

    }while(respuesta != 's');

    return 0;
}
