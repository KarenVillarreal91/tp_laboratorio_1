#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_mainMenu(int flagCargado)
{
    int op;

    printf("---------------------- Menu ----------------------\n");

    if(flagCargado == 0)
    {
        printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    }
    else
    {
        if(flagCargado == 1)
        {
            printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). [Cargado]\n");
            printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        }
        else
        {
            printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
            printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). [Cargado]\n");
        }
    }

    printf(" 3. Alta de empleado.\n");
    printf(" 4. Modificar datos de empleado.\n");
    printf(" 5. Baja de empleado.\n");
    printf(" 6. Listar empleados.\n");
    printf(" 7. Ordenar empleados.\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf(" 10. Salir.\n");
    printf("--------------------------------------------------\n\n");

    utn_getEntero(&op,2,"Ingrese un opcion: ","\nError! Opcion invalida.\n\n",1,10);

    system("cls");

    return op;
}

int controller_editMenu()
{
    int op;
    printf("\n\n Que desea modificar?\n");
    printf(" 1. Nombre.\n");
    printf(" 2. Horas trabajadas.\n");
    printf(" 3. Sueldo.\n");
    printf(" 4. Salir.\n");

    utn_getEntero(&op,0,"\n Ingrese una opcion: ","\n Error! Opcion invalida.\n\n",1,4);

    return op;
}

char confirmar()
{
    char resp;
                            //Verifica que el usario desea continuar
    utn_getCaracter(&resp,"\n Desea continuar? s/n: ","\n\n Error! Ingrese una respuesta valida (s/n).\n\n",'n','s',0);

    return resp;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int len = ll_len(pArrayListEmployee);

    FILE* pArchivo = fopen(path,"r");

    if(pArchivo != NULL)
    {
        if(!(parser_EmployeeFromText(pArchivo,pArrayListEmployee)))
        {
            printf("\n\n Archivo cargado exitosamente.\n");
            retorno = 0;

            if(len > 0)
            {
                if(employee_insertToList(pArrayListEmployee,len) == 0)
                {
                    printf("\n\n Se incorporaron los empleados existentes a la lista cargada.\n\n");
                }
            }
        }
    }
    else
    {
        printf("\n\n Archivo no encontrado.\n");
    }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int len = ll_len(pArrayListEmployee);

    FILE* pArchivo = fopen(path,"rb");

    if(pArchivo != NULL)
    {
        if(!(parser_EmployeeFromBinary(pArchivo,pArrayListEmployee)))
        {
            printf("\n\n Archivo cargado exitosamente.\n");
            retorno = 0;

            if(len > 0)
            {
                if(employee_insertToList(pArrayListEmployee,len) == 0)
                {
                    printf("\n\n Se incorporaron los empleados existentes a la lista cargada.\n\n");
                }
            }
        }
    }
    else
    {
        printf("\n\n Archivo no encontrado.\n");
    }

    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    int ultimaId;
    char respuesta;

    Employee* nuevoEmpleado = employee_new();

    if(utn_getCadena(nuevoEmpleado->nombre,128,2,"\n\n Ingrese el nombre del empleado: ","\n Error! Nombre invalido.\n\n") == 0)
    {
        if(utn_getEntero(&nuevoEmpleado->horasTrabajadas,2,"\n Ingrese la cantidad de horas trabajadas: ","\n Error! Cantidad invalida.\n\n",0,530000) == 0)
        {
            if(utn_getEntero(&nuevoEmpleado->sueldo,2,"\n Ingrese el sueldo del empleado: ","\n Error! Sueldo invalido.\n\n",0,500000) == 0)
            {
                ultimaId = employee_lastId(pArrayListEmployee);

                nuevoEmpleado->id = ultimaId + 1;

                respuesta = confirmar();

                if(respuesta == 's')
                {
                    if((retorno = ll_add(pArrayListEmployee,nuevoEmpleado)) == 0)
                    {
                        printf("\n\n Empleado creado correctamente.\n\n");
                    }
                    else
                    {
                        printf("\n\n No se pudo crear al empleado.\n\n");
                    }
                }
                else
                {
                    printf("\n\n No se guardaran los datos del empleado.\n\n");
                }
            }
        }
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int estadoModificado;
    char respuesta;
    char respuestaSalida;
    int idIngresado;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    int ultimaId = employee_lastId(pArrayListEmployee);
    int indice;

    Employee* empleadoModificado = employee_new();

    if(utn_getEntero(&idIngresado,0,"\n\nIngrese la ID del empleado a modificar: ","\n\nError! ID invalida.\n\n",1,ultimaId) == 0)
    {
        indice = employee_findById(pArrayListEmployee,idIngresado);

        if(indice > -1)
        {
            empleadoModificado = ll_get(pArrayListEmployee,indice);

            do
            {
                system("pause");
                system("cls");

                printf("\n\n%63s \n","-------------- Datos del empleado --------------");
                printf("%19s %10s %20s %10s\n","ID","Nombre","Horas Trabajadas","Sueldo");
                printf("%63s \n","------------------------------------------------");

                employee_print(pArrayListEmployee,indice);

                switch(controller_editMenu())
                {
                    case 1:
                        if(utn_getCadena(auxNombre,128,0,"Ingrese el nuevo nombre del empleado: ","\nError! Nombre invalido.\n\n") == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setNombre(empleadoModificado,auxNombre);
                            }
                        }
                    break;

                    case 2:
                        if(utn_getEntero(&auxHoras,0,"Ingrese la nueva cantidad de horas trabajadas: ","\nError! Cantidad invalida.\n\n",0,530000) == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setHorasTrabajadas(empleadoModificado,auxHoras);
                            }
                        }
                    break;

                    case 3:
                        if(utn_getEntero(&auxSueldo,0,"Ingrese el nuevo sueldo del empleado: ","\nError! Sueldo invalido.\n\n",0,500000) == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setSueldo(empleadoModificado,auxSueldo);
                            }
                        }
                    break;

                    case 4:
                        respuestaSalida = confirmar();
                    break;
                }

                if(respuestaSalida != 's' && respuestaSalida != 'n')
                {
                    if(estadoModificado == 0)
                    {
                        printf("\nModificado correctamente.\n\n");
                        retorno = 0;
                    }
                    else
                    {
                        printf("\nNo se pudo modificar al empleado.\n\n");
                    }
                }

            }while(respuestaSalida != 's');
        }
        else
        {
            printf("\nNo se encontro a un empleado con esa ID.\n\n");
        }
    }

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmpleado = employee_new();

    int retorno = 1;
    int idIngresado;
    int indice;
    char respuesta;
    int ultimaId = employee_lastId(pArrayListEmployee);

    if(utn_getEntero(&idIngresado,0,"\n\n Ingrese la ID del empleado que desea borrar: ","\n\n Error! ID invalida.\n\n",1,ultimaId) == 0)
    {
        indice = employee_findById(pArrayListEmployee,idIngresado);

        if(indice > -1)
        {
            pAuxEmpleado = ll_get(pArrayListEmployee,indice);

            system("pause");
            system("cls");

            printf("\n\n%63s \n","-------------- Datos del empleado --------------");
            printf("%19s %10s %20s %10s\n","ID","Nombre","Horas Trabajadas","Sueldo");
            printf("%63s \n","------------------------------------------------");

            employee_print(pArrayListEmployee,indice);

            printf("\n\n Confirme para eliminar! \n");

            respuesta = confirmar();

            if(respuesta == 's')
            {
                if(ll_remove(pArrayListEmployee,indice) == 0)
                {
                    employee_delete(pAuxEmpleado);
                    retorno = 0;
                    printf("\n\n Eliminado correctamente.\n\n");
                }
                else
                {
                    printf("\n\n Error! No se pudo eliminar al empleado.\n\n");
                }
            }
            else
            {
                printf("\n\n No se eliminara al empleado.\n\n");
            }
        }
        else
        {
            printf("\nNo se encontro a un empleado con esa ID.\n\n");
        }
    }

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int len = ll_len(pArrayListEmployee);
    int i;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\n%65s \n","-------------- Listado de Empleados --------------");
        printf("%19s %10s %20s %10s\n","ID","Nombre","Horas Trabajadas","Sueldo");
        printf("%65s \n","--------------------------------------------------");

        for(i = 0; i < len; i++)
        {
           employee_print(pArrayListEmployee,i);
        }

        retorno = 0;
    }

    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int ordenIngresado;
    int modoIngresado;

    if(utn_getEntero(&ordenIngresado,1,"\n Orden disponible: \n 1. Nombre.\n 2. ID.\n\n Ingrese la opcion: ","\n\nError! Orden invalido (1 o 2).\n\n",1,3) == 0)
    {
        system("cls");

        if(ordenIngresado == 1)
        {
            if(utn_getEntero(&modoIngresado,1,"\n Modos para ordenar los Nombres: \n 0. Ascendente.\n 1. Descendente.\n\n Ingrese la opcion: ","\n\nError! Modo invalido (0 o 1).\n\n",0,1) == 0)
            {
                printf("\n\n Ordenando, espere unos segundos...");

                if(ll_sort(pArrayListEmployee,employee_CompareByName,modoIngresado) == 0)
                {
                    printf("\n\n Se ordeno correctamente por Nombre, seleccione la opcion de listar empleados para ver los resultados.\n\n");
                    retorno = 0;
                }
            }
        }
        else
        {
            if(utn_getEntero(&modoIngresado,1,"\n Modos para ordenar las ID: \n 0. Ascendente.\n 1. Descendente.\n\n Ingrese la opcion: ","\n\nError! Modo invalido (0 o 1).\n\n",0,1) == 0)
            {
                printf("\n\n Ordenando, espere unos segundos...");

                if(ll_sort(pArrayListEmployee,employee_CompareById,modoIngresado) == 0)
                {
                    printf("\n\n Se ordeno correctamente por ID, seleccione la opcion de listar empleados para ver los resultados.\n\n");
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

