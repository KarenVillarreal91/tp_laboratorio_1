#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TAM 1000
#define VACIO 0
#define OCUPADO 1

/** \brief Para indicar que todas las posiciones del array
 * están vacías, esta función pone la bandera
 * (isEmpty) en TRUE en todas las posiciones del array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
    int i;
    int retorno = -1;

    for(i = 0; i < len; i++)
    {
        list[i].isEmpty = VACIO;

        retorno = 0;
    }

    return retorno;
}

/** \brief Agrega en un array de empleados existente los
 * valores recibidos como parámetro en la primer posición libre.
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    Employee auxEmpleado;

    int retorno = -1;
    char resp;

    resp = confirmar();

    if(resp == 's')
    {
        strcpy(auxEmpleado.name,name);
        strcpy(auxEmpleado.lastName,lastName);
        auxEmpleado.salary = salary;
        auxEmpleado.sector = sector;
        auxEmpleado.id = id;
        auxEmpleado.isEmpty = OCUPADO;

        list[id] = auxEmpleado;

        retorno = 0;
    }

    return retorno;
}

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id)
{
    int i;
    int retorno = -1;

    for(i = 0; i < len; i++)
    {
        if(list[i].id == id)
        {
            retorno = i;

            break;
        }
    }

    return retorno;
}

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee list[], int len, int id)
{
    int i;
    int retorno = -1;
    char respuesta;
    int indice = findEmployeeById(list,len,id);

    for(i = 0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == OCUPADO)
        {
            respuesta = confirmar();

            if(respuesta == 's')
            {
                list[indice].isEmpty = VACIO;
                retorno = 0;
                printf("\n\nEliminado correctamente.\n\n");
                break;
            }
            else
            {
                printf("\n\nNo se eliminara al empleado.\n\n");
            }
        }
    }

    return retorno;
}

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order)
{
    int i;
    int j;
    int retorno = -1;
    Employee auxEmpleado;

    for(i = 0; i < len-1; i++)
    {
        for(j = i+1; j < len; j++)
        {
            if(order == 1)
            {
                if(list[i].sector < list[j].sector)
                {
                   auxEmpleado = list[i];
                   list[i] = list[j];
                   list[j] = auxEmpleado;

                }
                else
                {
                    if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName) == 1)
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }

            }
            else
            {
                if(list[i].sector > list[j].sector)
                {
                   auxEmpleado = list[i];
                   list[i] = list[j];
                   list[j] = auxEmpleado;

                }
                else
                {
                    if(list[i].sector == list[j].sector && strcmp(list[j].lastName,list[i].lastName) == 1)
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }
            }

            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Imprime el array de empleados de forma encolumnada.
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee list[], int length)
{
    int i;

    printf("%56s\n","--------------- Datos de los empleados ---------------");
    printf("%7s %9s %13s %11s %10s\n","ID","Nombre","Apellido","Salario","Sector");
    printf("%57s\n","------------------------------------------------------");

    for(i = 0; i < length; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            printf("%6d     %-10s  %-8s %4c%.3f %6d\n", list[i].id, list[i].name, list[i].lastName,'$', list[i].salary, list[i].sector);
        }
    }

    return 0;
}

int menu()
{
    int op;

    printf(" ----------- Menu -----------\n");
    printf(" 1. Alta a un empleado.\n");
    printf(" 2. Modificar a un empleado.\n");
    printf(" 3. Baja a un empleado.\n");
    printf(" 4. Informes.\n");
    printf(" 5. Salir.\n");
    printf(" ----------------------------\n");
    utn_getEntero(&op,0,"\nIngrese la opcion: ","\nError! Opcion invalida.\n\n",1,5);

    system("cls");

    return op;
}

char confirmar()
{
    char resp;

    utn_getCaracter(&resp,"\nDesea continuar? s/n: ","\n\nError! Ingrese una respuesta valida (s/n).\n\n",'n','s',0);

    return resp;
}

int crearId(Employee list[],int len)
{
    int i;
    int id = -1;

    for(i = 1; i < len; i++)
    {
        if(list[i].isEmpty == VACIO)
        {
            id = i;
            break;
        }
    }

    return id;
}

int crearUnEmpleado(Employee list[],int len)
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int id;
    int retorno = -1;

    id = crearId(list,len);

    if(id != -1)
    {
        if(utn_getCadena(name,51,3,"Ingrese el nombre: ","\nError! Nombre invalido.\n") == 0)
        {
            if(utn_getCadena(lastName,51,3,"Ingrese el apellido: ","\nError! Apellido invalido.\n") == 0)
            {
                if(utn_getFlotante(&salary,3,"Ingrese el salario: ","\nError! Salario invalido.\n",0,999999999) == 0)
                {
                    if(utn_getEntero(&sector,3,"Ingrese el sector: ","\nError! Sector invalido (1 a 20).\n",1,20) == 0)
                    {
                        retorno = addEmployee(list,len,id,name,lastName,salary,sector);

                        if(retorno == 0)
                        {
                            printf("\nEmpleado agregado correctamente.\n\n");
                        }
                        else
                        {
                            printf("\nNo se registrara al empleado.\n\n");
                        }
                    }
                    else
                    {
                      printf("\nSuperaste la cantidad de intentos, intente de nuevo.\n\n");
                    }
                }
                else
                {
                   printf("\nSuperaste la cantidad de intentos, intente de nuevo.\n\n");
                }
            }
            else
            {
               printf("\nSuperaste la cantidad de intentos, intente de nuevo.\n\n");
            }
        }
        else
        {
           printf("\nSuperaste la cantidad de intentos, intente de nuevo.\n\n");
        }
    }
    else
    {
        printf("\nYa no hay espacios libres para agregar un nuevo empleado.\n\n");
    }

    return retorno;
}

void salarios(Employee list[],int tam)
{
    float acumuladorSalario = 0;
    int contadorEmpleados = 0;
    int contadorSuperanElPromedio = 0;
    float promedio;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            acumuladorSalario += list[i].salary;
            contadorEmpleados++;
        }
    }

    promedio = (float) acumuladorSalario / contadorEmpleados;

    for(i = 0; i < tam; i++)
    {
        if(list[i].isEmpty == OCUPADO && list[i].salary > promedio)
        {
            contadorSuperanElPromedio++;
        }
    }

    printf("\n\n\n%56s\n","--------------- Informes de Salarios ---------------");
    printf("%16s %14s %22s\n","Suma Total","Promedio","Superan el promedio");
    printf("%57s\n","------------------------------------------------------");

    printf("%6c%.3f %6c%.3f %11d\n\n\n\n",'$',acumuladorSalario,'$',promedio,contadorSuperanElPromedio);
}

void informesEmpleados(Employee list[],int tam)
{
    int order;
    int retornoOrdenado;
    char respuesta;

    if(utn_getEntero(&order,0,"\nComo desea ordenar el Apellido y Sector?\n 1. Desendente.\n 2. Ascendente.\n\nSu opcion: ","\nError! Opcion invalida.\n\n",1,2) == 0)
    {
        respuesta = confirmar();

        if(respuesta == 's')
        {
            retornoOrdenado = sortEmployees(list,tam,order);

            system("cls");

            if(retornoOrdenado == 0)
            {
                if(order == 1)
                {
                    printf("\n\n%44s\n\n","|Ordenado de forma Desendente|");
                }
                else
                {
                    if(order == 2)
                    {
                        printf("\n\n%44s\n\n","|Ordenado de forma Ascendente|");
                    }
                }

                printEmployees(list,tam);

                salarios(list,tam);
            }
            else
            {
                printf("\nOcurrio un error al ordenar!\n\n");
            }
        }
        else
        {
            printf("\nNo se ordernara ni se mostraran los empleados!\n\n");
        }
    }
}

int pedirId(Employee list[], int tam)
{
    int i;
    int id;
    int retorno = -1;

    printEmployees(list,tam);

    if(utn_getEntero(&id,1,"\n\nIngrese la ID del empleado: ","\n\nError! ID invalido.\n",1,tam) == 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == OCUPADO && list[i].id == id)
            {
                retorno = id;

                break;
            }
        }
    }

    return retorno;
}

void modificarEmpleado(Employee list[], int tam, int id)
{
    int indice = findEmployeeById(list,tam,id);
    int opcion;
    char respuesta;
    char respuestaSalir;

    Employee empleadoModificado;

    do
    {
        system("pause");
        system("cls");

        printf("%56s\n","----------------- Datos del empleado -----------------");
        printf("%7s %9s %13s %11s %10s\n","ID","Nombre","Apellido","Salario","Sector");
        printf("%57s\n","------------------------------------------------------");

        printf("%6d     %-10s  %-8s %4c%.3f %6d\n", list[indice].id, list[indice].name, list[indice].lastName,'$', list[indice].salary, list[indice].sector);

        if(utn_getEntero(&opcion,0,"\nQue desea modificar?\n 1. Nombre.\n 2. Apellido.\n 3. Salario.\n 4. Sector.\n 5. Salir.\n\nSu opcion: ","\n\nError! Opcion invalida.\n\n",1,5) == 0)
        {
            switch(opcion)
            {
                case 1:
                    if(utn_getCadena(empleadoModificado.name,51,0,"\nIngrese el nombre nuevo: ","\n\nError! Nombre invalido.\n\n") == 0)
                    {
                        respuesta = confirmar();

                        if(respuesta == 's')
                        {
                            strcpy(list[indice].name,empleadoModificado.name);

                            printf("\n\nSe guardaron los cambios.\n\n");
                        }
                        else
                        {
                            printf("\n\nNo se guardaran los cambios.\n\n");
                        }
                    }
                break;

                case 2:
                    if(utn_getCadena(empleadoModificado.lastName,51,0,"\nIngrese el apellido nuevo: ","\n\nError! Apellido invalido.\n\n") == 0)
                    {
                        respuesta = confirmar();

                        if(respuesta == 's')
                        {
                            strcpy(list[indice].lastName,empleadoModificado.lastName);

                            printf("\n\nSe guardaron los cambios.\n\n");
                        }
                        else
                        {
                            printf("\n\nNo se guardaran los cambios.\n\n");
                        }
                    }
                break;

                case 3:
                    if(utn_getFlotante(&empleadoModificado.salary,0,"\nIngrese el salario nuevo: ","\n\nError! Salario invalido.\n\n",0,999999999) == 0)
                    {
                        respuesta = confirmar();

                        if(respuesta == 's')
                        {
                            list[indice].salary = empleadoModificado.salary;

                            printf("\n\nSe guardaron los cambios.\n\n");
                        }
                        else
                        {
                            printf("\n\nNo se guardaran los cambios.\n\n");
                        }
                    }

                break;

                case 4:
                    if(utn_getEntero(&empleadoModificado.sector,0,"\nIngrese el sector nuevo: ","\n\nError! Sector invalido.\n\n",1,20) == 0)
                    {
                        respuesta = confirmar();

                        if(respuesta == 's')
                        {
                            list[indice].sector = empleadoModificado.sector;

                            printf("\n\nSe guardaron los cambios.\n\n");
                        }
                        else
                        {
                            printf("\n\nNo se guardaran los cambios.\n\n");
                        }
                    }
                break;

                case 5:
                    respuestaSalir = confirmar();
                break;
            }
        }

    }while(respuestaSalir != 's');

}

void hardCodearEmpleados(Employee list[], int tam)
{
    int arrayId[6] = {0,1,2,3,4,5};
    char arrayNombre[6][20] = {"Carlos","Jose","Juan","Marta", "Jorge","Norma"};
    char arrayApellido[6][20] = {"Gomez","Villalba","Sosa","Dermi", "Flores","Garcia"};
    float arraySalary[6] = {23000,44000,14000,65000,13500,35000};
    int arraySector[6] = {12,16,10,13,12,15};
    int arrayIsEmpty[6] = {1,1,1,1,1,1};
    int i;

    for(i = 0; i < tam; i++)
    {
        strcpy(list[i].name,arrayNombre[i]);
        strcpy(list[i].lastName,arrayApellido[i]);
        list[i].isEmpty = arrayIsEmpty[i];
        list[i].id = arrayId[i];
        list[i].sector = arraySector[i];
        list[i].salary = arraySalary[i];
    }
}
