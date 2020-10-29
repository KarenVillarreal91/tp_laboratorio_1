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

    do
    {
        cuantos = fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo); //Obtiene cada dato de la lista

        if(cuantos == 4)    //Si obtuvo los 4 datos continua
        {
            auxEmpleado = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);   //Setea, transforma a int los datos y los agrega a la estructura

            if(auxEmpleado != NULL) //Verifica que no sea NULL
            {
                retorno = ll_add(pArrayListEmployee,auxEmpleado);   //Agrega al empleado a la lista linkeada
            }
        }

    }while(!feof(pFile));   //Hasta que no termina la lista no deja de leer

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;

    Employee* auxEmpleado;

    if(pFile != NULL)   //Verifica que no sea NULL
    {
        do
        {
            auxEmpleado = employee_new();   //Busca espacio en malloc

            if(fread(auxEmpleado,sizeof(Employee),1,pFile) == 1)    //Lee la lista para todos datos a la estructura
            {
                retorno = ll_add(pArrayListEmployee,auxEmpleado);   //Agrega el empleado a la lista linkeada
            }

        }while(!feof(pFile));   //Hasta que no termina la lista no deja de leer
    }

    return retorno;
}
