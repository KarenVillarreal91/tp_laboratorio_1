#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../testing/inc/Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;

    int retorno = -1;
    int cuantos;
    char auxId[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxSueldo[50];
    char auxSector[50];

    do
    {
        cuantos = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^\n]\n",auxId,auxNombre,auxApellido,auxSueldo,auxSector); //Obtiene cada dato de la lista

        if(cuantos == 5)    //Si obtuvo los 4 datos continua
        {
            auxEmpleado = employee_newParametros(auxId,auxNombre,auxApellido,auxSueldo,auxSector);   //Setea, transforma a int los datos y los agrega a la estructura

            if(auxEmpleado != NULL) //Verifica que no sea NULL
            {
                retorno = ll_add(pArrayListEmployee,auxEmpleado);   //Agrega al empleado a la lista linkeada
            }
        }

    }while(!feof(pFile));   //Hasta que no termina la lista no deja de leer

    return retorno;
}
