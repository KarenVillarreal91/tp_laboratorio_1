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
        printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    }
    else
    {
        if(flagCargado == 1)
        {
            printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). [Cargado]\n");
            printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        }
        else
        {
            printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
            printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). [Cargado]\n");
        }
    }

    printf(" 3. Alta de empleado.\n");
    printf(" 4. Modificar datos de empleado.\n");
    printf(" 5. Baja de empleado.\n");
    printf(" 6. Listar empleados.\n");
    printf(" 7. Ordenar empleados.\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
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

void employee_print(LinkedList* pArrayListEmployee,int ind)
{
    Employee* pEmpleado;

    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    if(pArrayListEmployee != NULL && ind > -1)
    {
        pEmpleado = ll_get(pArrayListEmployee,ind);     //Obtiene los datos de un empleado mediante el indice

        if(employee_getId(pEmpleado,&auxId) == 0 &&
           employee_getNombre(pEmpleado,auxNombre) == 0 &&
           employee_getHorasTrabajadas(pEmpleado,&auxHoras) == 0 &&
           employee_getSueldo(pEmpleado,&auxSueldo) == 0)   //Obtiene los datos y los pasa a los auxiliares
        {
            printf("%19d     %-16s %-14d %-d\n",auxId,auxNombre,auxHoras,auxSueldo);
        }
    }
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int len = ll_len(pArrayListEmployee);

    FILE* pArchivo = fopen(path,"r");   //Abre el archivo en modo lectura de texto

    if(pArchivo != NULL)
    {
        if(!(parser_EmployeeFromText(pArchivo,pArrayListEmployee)))     //Llama a funcion parser y verifica que esta todo correcto
        {
            printf("\n\n Archivo cargado exitosamente.\n");
            retorno = 0;

            if(len > 0)     //Verifica si ya habia empleados cargados anteriormente
            {
                if(employee_insertToList(pArrayListEmployee,len) == 0)  //Incorpora los empleados antiguos a la nueva lista cargada e informa
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

    fclose(pArchivo);

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int len = ll_len(pArrayListEmployee);

    FILE* pArchivo = fopen(path, "rb");     //Abre el archivo en modo lectura de binario

    if(pArchivo != NULL)
    {
        if(!parser_EmployeeFromBinary(pArchivo, pArrayListEmployee))     //Llama a funcion parse y verifica que esta todo bien
        {
            printf("\n\n Archivo cargado exitosamente.\n");
            retorno = 0;

            if(len > 0)     //Verifica si ya habia empleados cargados anteriormente
            {
                if(employee_insertToList(pArrayListEmployee,len) == 0)  //Incorpora los empleados antiguos a la lista cargada e informa
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

    fclose(pArchivo);

    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    int ultimaId;
    char respuesta;

    Employee* nuevoEmpleado = employee_new();       //Busca espacio en malloc
    //Ingreso de datos
    if(utn_getCadena(nuevoEmpleado->nombre,128,2,"\n\n Ingrese el nombre del empleado: ","\n Error! Nombre invalido.\n\n") == 0)
    {
        if(utn_getEntero(&nuevoEmpleado->horasTrabajadas,2,"\n Ingrese la cantidad de horas trabajadas: ","\n Error! Cantidad invalida.\n\n",0,530000) == 0)
        {
            if(utn_getEntero(&nuevoEmpleado->sueldo,2,"\n Ingrese el sueldo del empleado: ","\n Error! Sueldo invalido.\n\n",0,500000) == 0)
            {
                ultimaId = employee_lastId(pArrayListEmployee);     //Busca la ultima ID de la lista

                employee_setId(nuevoEmpleado,ultimaId+1);       //Setea la ID apartir de la ultima ID encontrada y le suma 1

                respuesta = confirmar();

                if(respuesta == 's')
                {
                    if((retorno = ll_add(pArrayListEmployee,nuevoEmpleado)) == 0)   //Agrega el empleado cargado a la linkedlist
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
    char respuestaSalida = ' ';
    int idIngresado;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    int ultimaId = employee_lastId(pArrayListEmployee);     //Busca la ultima ID de la lista
    int indice;

    Employee* empleadoModificado = employee_new();      //Busca espacio en el malloc

    //Pide la ID del empleado a modificar
    if(utn_getEntero(&idIngresado,0,"\n\nIngrese la ID del empleado a modificar: ","\n\nError! ID invalida.\n\n",1,ultimaId) == 0)
    {
        indice = employee_findById(pArrayListEmployee,idIngresado);     //Busca el indice del empleado apartir de la ID ingresada

        if(indice > -1)     //Si lo encuentra continua
        {
            empleadoModificado = ll_get(pArrayListEmployee,indice);     //Obtiene los datos del empleado apartir del indice

            do
            {
                system("pause");
                system("cls");

                printf("\n\n%63s \n","-------------- Datos del empleado --------------");   //Muestra al empleado encontrado
                printf("%19s %10s %20s %10s\n","ID","Nombre","Horas Trabajadas","Sueldo");
                printf("%63s \n","------------------------------------------------");

                employee_print(pArrayListEmployee,indice);

                switch(controller_editMenu())   //Muestra un menu de opciones
                {
                    case 1:     //1. Edita el nombre
                        if(utn_getCadena(auxNombre,128,0,"\n Ingrese el nuevo nombre del empleado: ","\n Error! Nombre invalido.\n\n") == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setNombre(empleadoModificado,auxNombre);
                            }
                        }
                    break;

                    case 2:     //2. Edita las horas
                        if(utn_getEntero(&auxHoras,0,"\n Ingrese la nueva cantidad de horas trabajadas: ","\n Error! Cantidad invalida.\n\n",0,530000) == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setHorasTrabajadas(empleadoModificado,auxHoras);
                            }
                        }
                    break;

                    case 3:     //3. Edita el sueldo
                        if(utn_getEntero(&auxSueldo,0,"\n Ingrese el nuevo sueldo del empleado: ","\n Error! Sueldo invalido.\n\n",0,500000) == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setSueldo(empleadoModificado,auxSueldo);
                            }
                        }
                    break;

                    case 4:    //4. Salida
                        respuestaSalida = confirmar();
                        estadoModificado = 2;
                    break;
                }

                if(estadoModificado == 0)   //Verifica que modifico algo o no 0 (Bien), 1 (Mal), 2 u otro (No informa)
                {
                    printf("\n Modificado correctamente.\n\n");
                    retorno = 0;
                }
                else
                {
                    if(estadoModificado == 1)
                    {
                        printf("\n No se pudo modificar al empleado.\n\n");
                    }
                }

            }while(respuestaSalida != 's');
        }
        else
        {
            printf("\n No se encontro a un empleado con esa ID.\n\n");
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
    int ultimaId = employee_lastId(pArrayListEmployee);     //Busca la ultima ID actual

    //Pide el ingreso del ID a eliminar
    if(utn_getEntero(&idIngresado,0,"\n\n Ingrese la ID del empleado que desea borrar: ","\n\n Error! ID invalida.\n\n",1,ultimaId) == 0)
    {
        indice = employee_findById(pArrayListEmployee,idIngresado);     //Busca el indice del empleado mediante la ID

        if(indice > -1)     //Si encontro el indice continua
        {
            pAuxEmpleado = ll_get(pArrayListEmployee,indice);   //Obtiene los datos del empleado apartir del indice

            system("pause");
            system("cls");

            printf("\n\n%63s \n","-------------- Datos del empleado --------------");   //Informa el empleado encontrado
            printf("%19s %10s %20s %10s\n","ID","Nombre","Horas Trabajadas","Sueldo");
            printf("%63s \n","------------------------------------------------");

            employee_print(pArrayListEmployee,indice);

            printf("\n\n Confirme para eliminar! \n");

            respuesta = confirmar();

            if(respuesta == 's')    //Si confirma continua
            {
                if(ll_remove(pArrayListEmployee,indice) == 0)   //Elimina al empleado
                {
                    employee_delete(pAuxEmpleado);     //Libera espacio
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
            printf("\n No se encontro a un empleado con esa ID.\n\n");
        }
    }

    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int len = ll_len(pArrayListEmployee);   //Obtiene la cantidad de empleados
    int i;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\n%65s \n","-------------- Listado de Empleados --------------");
        printf("%19s %10s %20s %10s\n","ID","Nombre","Horas Trabajadas","Sueldo");
        printf("%65s \n","--------------------------------------------------");

        for(i = 0; i < len; i++)
        {
           employee_print(pArrayListEmployee,i);    //Recorre la lista mostrando cada empleado por el indice
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

    //Pregunta por Orden
    if(utn_getEntero(&ordenIngresado,1,"\n Orden disponible: \n 1. Nombre.\n 2. ID.\n\n Ingrese la opcion: ","\n\nError! Orden invalido (1 o 2).\n\n",1,3) == 0)
    {
        system("cls");

        if(ordenIngresado == 1) //Si selecciona Nombre entra
        {
            //Pregunta el modo para ordenar
            if(utn_getEntero(&modoIngresado,1,"\n Modos para ordenar los Nombres: \n 0. Descendente.\n 1. Ascendente.\n\n Ingrese la opcion: ","\n\nError! Modo invalido (0 o 1).\n\n",0,1) == 0)
            {
                printf("\n\n Ordenando, espere unos segundos...");

                if(ll_sort(pArrayListEmployee,employee_CompareByName,modoIngresado) == 0)   //Ordena la lista entera por Nombre e informa
                {
                    printf("\n\n Se ordeno correctamente por Nombre, seleccione la opcion de listar empleados para ver los resultados.");
                    retorno = 0;
                }
                else
                {
                    printf("\n\n Error! No se pudo ordenar la lista!");
                }
            }
        }
        else
        {
            //Pide el modo a ordenar
            if(utn_getEntero(&modoIngresado,1,"\n Modos para ordenar las ID: \n 0. Descendente.\n 1. Ascendente.\n\n Ingrese la opcion: ","\n\nError! Modo invalido (0 o 1).\n\n",0,1) == 0)
            {
                printf("\n\n Ordenando, espere unos segundos...");

                if(ll_sort(pArrayListEmployee,employee_CompareById,modoIngresado) == 0)     //Ordena la lista entera por ID e informa
                {
                    printf("\n\n Se ordeno correctamente por ID, seleccione la opcion de listar empleados para ver los resultados.");
                    retorno = 0;
                }
                else
                {
                    printf("\n\n Error! No se pudo ordenar la lista!");
                }
            }
        }
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    FILE* pArchivo;

    int retorno = 1;
    int i;
    int auxId;
    char auxNombre[50];
    int auxHoras;
    int auxSueldo;
    int len = ll_len(pArrayListEmployee);   //Busca la cantidad de empleados en la lista

    printf("\n Confirme su eleccion!\n\n");

    if(confirmar() == 's')
    {
        pArchivo = fopen(path,"w");   //Abre el archivo en modo escritura de texto

        if(pArchivo != NULL)
        {
            for(i = 0; i < len; i++)
            {
                auxEmpleado = ll_get(pArrayListEmployee,i);     //Obtiene cada empleado segun su indice

                if(employee_getId(auxEmpleado,&auxId) == 0 &&
                    employee_getNombre(auxEmpleado,auxNombre) == 0 &&
                    employee_getHorasTrabajadas(auxEmpleado,&auxHoras) == 0 &&
                    employee_getSueldo(auxEmpleado,&auxSueldo) == 0)    //Obtiene cada dato del empleado
                {
                    fprintf(pArchivo,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);   //Escribe en el archivo
                }
            }

            printf("\n\n Archivo guardado correctamente en %s!",path);  //Informa
            retorno = 0;
        }
        else
        {
            printf("\n\n Archivo no encontrado.");
        }

        fclose(pArchivo);
    }
    else
    {
        printf("\n\n No se guardara la lista.");
    }


    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    FILE* pArchivo;

    int retorno = 1;
    int i;
    int len = ll_len(pArrayListEmployee);   //Buscar la cantidad de empleados en la lista

    printf("\n Confirme su eleccion!\n\n");

    if(confirmar() == 's')
    {
        pArchivo = fopen(path,"wb");     //Abre el archivo en modo escritura de binario

        if(pArchivo != NULL)
        {
            for(i = 0; i < len; i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);     //Obtiene cada empleados segun su indice
                fwrite(auxEmpleado,sizeof(Employee),1,pArchivo);        //Escribe los datos del empleado en el archivo
            }

            printf("\n\n Archivo guardado correctamente en %s!",path);  //Informa
            retorno = 0;
        }
        else
        {
            printf("\n\n Archivo no encontrado.");
        }

        fclose(pArchivo);
    }
    else
    {
        printf("\n\n No se guardara la lista.");
    }

    return retorno;
}

