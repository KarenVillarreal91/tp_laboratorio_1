#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../testing/inc/Employee.h"
#include "../inc/parser.h"
#include "../inc/utn.h"

int controller_mainMenu(int flagCargado)
{
    int op;

    printf("---------------------- Menu ----------------------\n");

    if(flagCargado == 0)
    {
        printf(" 1. Cargar los datos de los empleados desde un archivo.\n");
    }
    else
    {
        printf(" 1. Cargar los datos de los empleados desde un archivo. [Cargado]\n");
    }

    printf(" 2. Alta de empleado.\n");
    printf(" 3. Reemplazar a un empleado.\n");
    printf(" 4. Modificar datos de un empleado.\n");
    printf(" 5. Baja de empleado.\n");
    printf(" 6. Listar empleados.\n");
    printf(" 7. Ordenar empleados.\n");
    printf(" 8. Borrar todos los empleados de la lista.\n");
    printf(" 9. Crear una copia de la lista en un archivo nuevo.\n");
    printf(" 10. Guardar la lista en el archivo actual.\n");
    printf(" 11. Salir.\n");
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
    printf(" 2. Apellido.\n");
    printf(" 3. Sueldo.\n");
    printf(" 4. Sector.\n");
    printf(" 5. Salir.\n");

    utn_getEntero(&op,0,"\n Ingrese una opcion: ","\n Error! Opcion invalida.\n\n",1,5);

    return op;
}

char confirmar()
{
    char resp;
                            //Verifica que el usario desea continuar
    utn_getCaracter(&resp,"\n Desea continuar? s/n: ","\n\n Error! Ingrese una respuesta valida (s/n).\n\n",'n','s',0);

    return resp;
}

void employee_print(Employee* this)
{
    int auxId;
    char auxNombre[51];
    char auxApellido[51];
    float auxSueldo;
    int auxSector;

    if(employee_getId(this,&auxId) == 0 &&
        employee_getName(this,auxNombre) == 0 &&
        employee_getLastName(this,auxApellido) == 0 &&
        employee_getSueldo(this,&auxSueldo) == 0 &&
        employee_getSector(this,&auxSector) == 0)   //Obtiene los datos y los pasa a los auxiliares
    {
        printf("%19d    %-12s %-12s %-12.2f %-d\n",auxId,auxApellido,auxNombre,auxSueldo,auxSector);
    }
}


int controller_loadFile(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int len = ll_len(pArrayListEmployee);

    FILE* pArchivo = fopen(path,"r");   //Abre el archivo en modo lectura de texto

    if(pArchivo != NULL)
    {
        if(parser_EmployeeFromText(pArchivo,pArrayListEmployee) == 0)     //Llama a funcion parser y verifica que esta todo correcto
        {
            employee_saveLastId(pArrayListEmployee);
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

int controller_requestFile(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char nombre[50];

    if(utn_getCadena(nombre,50,1,"\n Ingrese el nombre del archivo con su extension: ","\n Error! Nombre invalido.\n\n") == 0)
    {
        if((retorno = controller_loadFile(nombre,pArrayListEmployee)) == 0) //Carga todos los empleados del archivo
        {
            guardarNombreDeArchivo(nombre,"nombreDelArchivo.txt");  //Guarda el nombre del archivo en un txt
        }
        else
        {
            printf("\n\n Error! No se pudo cargar el archivo.\n");
        }
    }

    return retorno;
}

void controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char respuesta;

    Employee* nuevoEmpleado = employee_new();

    if(employee_requestData(nuevoEmpleado) == 0)    //Pide los datos del empleado a agregar
    {
        respuesta = confirmar();

        if(respuesta == 's')
        {
            if(ll_add(pArrayListEmployee,nuevoEmpleado) == 0)   //Agrega el empleado cargado a la linkedlist
            {
                employee_saveLastId(pArrayListEmployee);
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
    else
    {
        printf("\n\n No se pudo crear al empleado.\n\n");
    }
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int estadoModificado;
    char respuesta;
    char respuestaSalida = ' ';
    int idIngresado;
    char auxNombre[51];
    char auxApellido[51];
    int auxSueldo;
    int auxSector;
    int ultimaId = employee_readLastId();     //Busca la ultima ID de la lista
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

                printf("\n\n%67s \n","---------------- Datos del empleado ----------------");   //Muestra al empleado encontrado
                printf("%19s %11s %10s %13s %9s\n","ID","Apellido","Nombre","Sueldo","Sector");
                printf("%67s \n","----------------------------------------------------");

                employee_print(empleadoModificado);

                switch(controller_editMenu())   //Muestra un menu de opciones
                {
                    case 1:     // Edita el nombre
                        if(utn_getCadena(auxNombre,51,0,"\n Ingrese el nuevo nombre del empleado: ","\n Error! Nombre invalido.\n") == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setName(empleadoModificado,auxNombre);
                            }
                        }
                    break;

                    case 2:     // Edita el Apellido
                        if(utn_getCadena(auxApellido,51,0,"\n Ingrese el nuevo apellido del empleado: ","\n Error! Apellido invalido.\n") == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setLastName(empleadoModificado,auxApellido);
                            }
                        }
                    break;

                    case 3:     // Edita el sueldo
                        if(utn_getEntero(&auxSueldo,0,"\n Ingrese el nuevo sueldo del empleado: ","\n Error! Sueldo invalido.\n",0,500000) == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setSueldo(empleadoModificado,auxSueldo);
                            }
                        }
                    break;

                    case 4:     // Edita las horas
                        if(utn_getEntero(&auxSector,0,"\n Ingrese el nuevo sector: ","\n Error! Sector invalida (1-5).\n",1,5) == 0)
                        {
                            respuesta = confirmar();

                            if(respuesta == 's')
                            {
                                estadoModificado = employee_setSector(empleadoModificado,auxSector);
                            }
                        }
                    break;

                    case 5:    // Salida
                        respuestaSalida = confirmar();
                        estadoModificado = 2;
                    break;
                }

                ll_set(pArrayListEmployee,indice,empleadoModificado); //Setea todos los cambios en la linkedlist

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

void controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmpleado = employee_new();

    int idIngresado;
    int indice;
    char respuesta;
    int ultimaId = employee_readLastId();     //Busca la ultima ID actual

    //Pide el ingreso del ID a eliminar
    if(utn_getEntero(&idIngresado,0,"\n\n Ingrese la ID del empleado que desea borrar: ","\n\n Error! ID invalida.\n\n",1,ultimaId) == 0)
    {
        indice = employee_findById(pArrayListEmployee,idIngresado);     //Busca el indice del empleado mediante la ID

        if(indice > -1)     //Si encontro el indice continua
        {
            pAuxEmpleado = ll_get(pArrayListEmployee,indice);   //Obtiene los datos del empleado apartir del indice

            system("pause");
            system("cls");

            printf("\n\n%67s \n","---------------- Datos del empleado ----------------");   //Muestra al empleado encontrado
            printf("%19s %11s %10s %13s %9s\n","ID","Apellido","Nombre","Sueldo","Sector");
            printf("%67s \n","----------------------------------------------------");

            employee_print(pAuxEmpleado);

            printf("\n\n Confirme para eliminar! \n");

            respuesta = confirmar();

            if(respuesta == 's')    //Si confirma continua
            {
                if(ll_remove(pArrayListEmployee,indice) == 0)   //Elimina al empleado
                {
                    employee_delete(pAuxEmpleado);     //Libera espacio
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
}

void controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int len = ll_len(pArrayListEmployee);   //Obtiene la cantidad de empleados
    int i;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\n%67s \n","--------------- Listado de Empleados ---------------");
        printf("%19s %11s %10s %13s %9s\n","ID","Apellido","Nombre","Sueldo","Sector");
        printf("%67s \n","----------------------------------------------------");

        for(i = 0; i < len; i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);     //Obtiene los datos de un empleado mediante el indice
            employee_print(pEmpleado);    //Recorre la lista mostrando cada empleado por el indice
        }
    }
}

void controller_saveCopyList(LinkedList* pArrayListEmployee)
{
    if(confirmar() == 's' && pArrayListEmployee != NULL)
    {
        if(employee_saveCopy(pArrayListEmployee) == 0)  //Guarda la lista en un archivo nuevo
        {
            printf("\n Se guardaron los resultados en un nuevo archivo!\n");
        }
    }
}

void controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ordenIngresado;
    int modoIngresado;

    LinkedList* subLista = ll_clone(pArrayListEmployee);    //Copia la lista

    if(ll_containsAll(pArrayListEmployee,subLista) == 1) //Verifica que se copio correctamente
    {
        //Pregunta por Orden
        if(utn_getEntero(&ordenIngresado,1,"\n Orden disponible: \n 1. Apellido.\n 2. ID.\n\n Ingrese la opcion: ","\n\nError! Orden invalido (1 o 2).\n\n",1,3) == 0)
        {
            system("cls");

            if(ordenIngresado == 1) //Si selecciona Apellido entra
            {
                //Pregunta el modo para ordenar
                if(utn_getEntero(&modoIngresado,1,"\n Modos para ordenar los Apellidos: \n 0. Descendente.\n 1. Ascendente.\n\n Ingrese la opcion: ","\n\nError! Modo invalido (0 o 1).\n\n",0,1) == 0)
                {
                    printf("\n\n Ordenando, espere unos segundos...");

                    if(ll_sort(subLista,employee_CompareByLastName,modoIngresado) == 0)   //Ordena la lista entera por Apellido e informa
                    {
                        printf("\n\n Se ordeno correctamente por Apellido, seleccione la opcion de listar empleados para ver los resultados.");

                        system("pause");
                        system("cls");
                        printf("\n Confirme si desea guardar una copia de la lista ordenada.\n");
                        controller_saveCopyList(subLista);  //Pregunta si quiere guardar una copia de la lista
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

                    if(ll_sort(subLista,employee_CompareById,modoIngresado) == 0)     //Ordena la lista entera por ID e informa
                    {
                        printf("\n\n Se ordeno correctamente por ID, seleccione la opcion de listar empleados para ver los resultados.");

                        system("pause");
                        system("cls");
                        printf("\n Confirme si desea guardar una copia de la lista ordenada.\n");
                        controller_saveCopyList(subLista);  //Pregunta si quiere guardar una copia de la lista
                    }
                    else
                    {
                        printf("\n\n Error! No se pudo ordenar la lista!");
                    }
                }
            }
        }
    }
}

int controller_removeAllEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char respuesta;

    printf("\n Confirme para eliminar a todos los empleados.\n");
    respuesta = confirmar();

    if(respuesta == 's')
    {
        if(ll_clear(pArrayListEmployee) == 0)   //Borra todos los empleados de la lista
        {
            retorno = 0;
            printf("\n Se eliminaron correctamente todos los empleados de la lista actual!\n");
        }
        else
        {
            printf("\n No se eliminaran a los empleados.\n");
        }
    }
    return retorno;
}

void controller_saveList(LinkedList* pArrayListEmployee)
{
    char nombre[50];
    FILE* pArchivo;

    if(leerNombreDeArchivo(nombre,"nombreDelArchivo.txt") == 0) //Obtiene el nombre del archivo ingresado
    {
        pArchivo = fopen(nombre,"w");

        printf("\n Aviso! Se sobreescribira el archivo cargado.\n");

        if(confirmar() == 's' && pArrayListEmployee != NULL)
        {
            if(employee_saveAll(pArrayListEmployee,pArchivo) == 0)  //Guarda toda la lista en el archivo
            {
                printf("\n Se actualizo la lista correctamente!\n");
            }
        }

        fclose(pArchivo);
    }
}

void controller_replace(LinkedList* pArrayListEmployee)
{
    int idIngresado;
    int indice;
    int ultimaId = employee_readLastId();

    Employee* pEmpleado;

    //Pide la ID del empleado a reemplazar
    if(utn_getEntero(&idIngresado,0,"\n\nIngrese la ID del empleado a reemplazar: ","\n\nError! ID invalida.\n\n",1,ultimaId) == 0)
    {
        indice = employee_findById(pArrayListEmployee,idIngresado);     //Busca el indice del empleado apartir de la ID ingresada

        if(indice > -1)     //Si lo encuentra continua
        {
            pEmpleado = ll_pop(pArrayListEmployee,indice);     //Obtiene los datos del empleado apartir del indice y lo borra
            system("cls");

            //Pide los nuevos datos, lo inserta en el indice del empleado seleccionado y verifica que se inserto en el indice correcto
            if(employee_requestData(pEmpleado) == 0 &&
               ll_push(pArrayListEmployee,indice,pEmpleado) == 0 &&
               ll_indexOf(pArrayListEmployee,pEmpleado) == indice)
            {
                printf("\n Se reemplazo al empleado correctamente.\n");
            }
            else
            {
                printf("\n No se pudo reemplazar al empleado.\n");
            }
        }
    }
}
