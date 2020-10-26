#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;

    int retorno;
    int cuantos;
    char auxId[50];
    char auxNombre[50];
    char auxHoras[50];
    char auxSueldo[50];

    fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);

    do
    {
        cuantos = fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);

        if(cuantos == 4)
        {
            auxEmpleado = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);

            if(auxEmpleado != NULL)
            {
                retorno = ll_add(pArrayListEmployee,auxEmpleado);
            }
        }

    }while(!feof(pFile));

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;

    int retorno;

    do
    {
        auxEmpleado = employee_new();

        if(fread(auxEmpleado,sizeof(auxEmpleado),1,pFile) == 1)
        {
            retorno = ll_add(pArrayListEmployee,auxEmpleado);
        }

    }while(!feof(pFile));

    return retorno;
}
