#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesEmpleados.h"

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

    if(indice != -1)
    {
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
    }
    else
    {
        printf("\nNo se encontro a un empleado con esa ID.\n\n");
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
