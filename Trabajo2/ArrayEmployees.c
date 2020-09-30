#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesEmpleados.h"

int initEmployees(Employee list[], int len)
{
    int i;
    int retorno = -1;

    for(i = 0; i < len; i++)        //Recorre el cupo de empleados seteado en VACIO
    {
        list[i].isEmpty = VACIO;

        retorno = 0;
    }

    return retorno;
}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno = -1;
    char resp;
    int indice = buscarLibre(list,len);

    if(indice != -1)
    {
        resp = confirmar();         //Confirma que el usario esta seguro de agregar al empleado

        if(resp == 's')         //Si reponde "s" continua y asigna los valores ingresados
        {
            strcpy(list[indice].name,name);
            strcpy(list[indice].lastName,lastName);
            list[indice].salary = salary;
            list[indice].sector = sector;
            list[indice].id = id;
            list[indice].isEmpty = OCUPADO;

            retorno = 0;
        }
    }
    else
    {
        printf("\nYa no hay espacios libres para agregar un nuevo empleado.\n\n");
    }

    return retorno;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int i;
    int retorno = -1;

    for(i = 0; i < len; i++)    //Recorre el cupo buscando el ID para obtener el indice
    {
        if(list[i].id == id && list[i].isEmpty == OCUPADO)    //Si lo encuentra asigna el retorno
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int removeEmployee(Employee list[], int len, int id)
{
    int retorno = -1;
    char respuesta;
    int indice = findEmployeeById(list,len,id);     //Busca el indice mediante la ID

    if(indice != -1)        //Si la funcion encuentra el indice continua
    {
        respuesta = confirmar();        //Confirma que el usario esta seguro de eliminar

        if(respuesta == 's')        //Si responde "s" lo asigna a VACIO
        {
            list[indice].isEmpty = VACIO;
            retorno = 0;
            printf("\n\nEliminado correctamente.\n\n");
        }
        else
        {
            printf("\n\nNo se eliminara al empleado.\n\n");
        }
    }
    else
    {
        printf("\nNo se encontro a un empleado con esa ID.\n\n");
    }

    return retorno;
}

int sortEmployees(Employee list[], int len, int order)
{
    int i;
    int j;
    int retorno = -1;
    Employee auxEmpleado;

    for(i = 0; i < len-1; i++)      //Ordenamiendo mediante burbujeo, comparando un empleado con el que sigue
    {
        for(j = i+1; j < len; j++)
        {
            if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)    //Valida que se ordenen solo los empleados ingresados
            {
                if(order == 1)         //Para orden 1 (Desendente) compara y cambia valores
                {
                    if(list[i].sector < list[j].sector)     //Compara por sector
                    {
                       auxEmpleado = list[i];
                       list[i] = list[j];
                       list[j] = auxEmpleado;

                    }
                    else    //Si los sectores son iguales, compara por apellido
                    {
                        if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName) == 1)
                        {
                            auxEmpleado = list[i];
                            list[i] = list[j];
                            list[j] = auxEmpleado;
                        }
                    }

                }
                else        //Para orden 2 (Ascendente) compara y cambia valores
                {
                    if(list[i].sector > list[j].sector)         //Por sector
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;

                    }
                    else        //Por apellido
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
    }

    return retorno;
}

int printEmployees(Employee list[], int length)
{
    int i;

    printf("%68s\n","--------------------- Datos de los empleados ---------------------");
    printf("%7s %10s %15s %18s %12s\n","ID","Nombre","Apellido","Salario","Sector");
    printf("%68s\n","------------------------------------------------------------------");

    for(i = 0; i < length; i++)         //Recorre el cupo buscando los espacios ocupados e imprime
    {
        if(list[i].isEmpty == OCUPADO)
        {
            printf("%7d     %-12s  %-12s %6c%.3f   %6d\n", list[i].id, list[i].name, list[i].lastName,'$', list[i].salary, list[i].sector);
        }
    }

    return 0;
}
