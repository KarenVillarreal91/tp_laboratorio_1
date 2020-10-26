#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char respuesta = 'n';

    LinkedList* lista;
    lista = ll_newLinkedList();

    do
    {
        switch(controller_menu())
        {
            case 1:
                controller_loadFromText("data.csv",lista);
            break;

            case 2:
                controller_loadFromBinary("data.csv",lista);
            break;

            case 3:
                controller_addEmployee(lista);
            break;

            case 4:

            break;

            case 5:
                employee_createId(lista);
            break;

            case 6:
                controller_ListEmployee(lista);
            break;

            case 7:

            break;

            case 8:

            break;

            case 9:

            break;

            case 10:

            break;
        }

        printf("\n\n\n");
        system("pause");
        system("cls");

    }while(respuesta != 's');

    return 0;
}
