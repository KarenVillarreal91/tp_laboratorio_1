/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"

int main()
{
    char respuesta;
    int flagCargado = 0;

    LinkedList* lista;
    lista = ll_newLinkedList(); //Se crea una nueva lista

    do
    {
        switch(controller_mainMenu(flagCargado))    //El menu obtiene un flag para mostrar si esta cargado o no un archivo
        {
            case 1:
                if(controller_requestFile(lista) == 0)
                {
                    flagCargado = 1;
                }
            break;

            case 2:
                controller_addEmployee(lista);
            break;

            case 3:
                if(ll_isEmpty(lista) == 0)
                {
                    controller_ListEmployee(lista);
                    controller_replace(lista);
                }
                else
                {
                    printf("\n La lista esta vacia, cargue algun empleado primero.\n");
                }
            break;

            case 4:
                if(ll_isEmpty(lista) == 0)
                {
                    controller_ListEmployee(lista);
                    controller_editEmployee(lista);
                }
                else
                {
                    printf("\n La lista esta vacia, cargue algun empleado primero.\n");
                }
            break;

            case 5:
                if(ll_isEmpty(lista) == 0)
                {
                    controller_ListEmployee(lista);
                    controller_removeEmployee(lista);
                }
                else
                {
                    printf("\n La lista esta vacia, cargue algun empleado primero.\n");
                }
            break;

            case 6:
                if(ll_isEmpty(lista) == 0)
                {
                    controller_ListEmployee(lista);
                }
                else
                {
                    printf("\n La lista esta vacia, cargue algun empleado primero.\n");
                }
            break;

            case 7:
                if(ll_isEmpty(lista) == 0)
                {
                    controller_sortEmployee(lista);
                }
                else
                {
                    printf("\n La lista esta vacia, cargue algun empleado primero.\n");
                }
            break;

            case 8:
                if(ll_isEmpty(lista) == 0)
                {
                   if(controller_removeAllEmployee(lista) == 0)
                   {
                       flagCargado = 0;
                   }
                }
                else
                {
                    printf("\n La lista esta vacia, cargue algun empleado primero.\n");
                }
            break;

            case 9:
                if(ll_isEmpty(lista) == 0)
                {
                    controller_saveCopyList(lista);
                }
                else
                {
                    printf("\n La lista esta vacia, cargue algun empleado primero.\n");
                }
            break;

            case 10:
                if(flagCargado == 1)
                {
                    controller_saveList(lista);
                }
                else
                {
                    printf("\n No hay ningun archivo cargado, cargue uno primero.\n");
                }
            break;

            case 11:
                respuesta = confirmar();
            break;
        }

        printf("\n\n\n");
        system("pause");
        system("cls");

    }while(respuesta != 's');

    ll_deleteLinkedList(lista);

    return 0;
}


/*int main(void)
{
        startTesting(1);  // ll_newLinkedList  -
        startTesting(2);  // ll_len              -
        startTesting(3);  // getNode / test_getNode
        startTesting(4);  // addNode / test_addNode
        startTesting(5);  // ll_add              -
        startTesting(6);  // ll_get              -
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove           -
        startTesting(9);  // ll_clear            -
        startTesting(10); // ll_deleteLinkedList -
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList         -
        startTesting(18); // ll_clone           -
        startTesting(19); // ll_sort            -

    return 0;
}*/

































