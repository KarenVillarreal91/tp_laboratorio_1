#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* pEmpleado;

    pEmpleado = (Employee*) malloc(sizeof(Employee));

    return pEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado = employee_new();

    if((pEmpleado != NULL) && (idStr != NULL) && (nombreStr != NULL) && (horasTrabajadasStr != NULL) && (sueldoStr != NULL))
    {
        if((employee_setId(pEmpleado,atoi(idStr))) ||
            (employee_setNombre(pEmpleado,nombreStr)) ||
            (employee_setHorasTrabajadas(pEmpleado,atoi(horasTrabajadasStr))) ||
            (employee_setSueldo(pEmpleado,atoi(sueldoStr))))
        {
            employee_delete(pEmpleado);  //Si alguna de las funciones retorna error, borra al empleado para que no se cargue y evitar inconvenientes.
            pEmpleado = NULL;
        }
    }

    return pEmpleado;
}

void employee_delete(Employee* this)
{
    free(this);
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
        pEmpleado = ll_get(pArrayListEmployee,ind);

        if(employee_getId(pEmpleado,&auxId) == 0 &&
           employee_getNombre(pEmpleado,auxNombre) == 0 &&
           employee_getHorasTrabajadas(pEmpleado,&auxHoras) == 0 &&
           employee_getSueldo(pEmpleado,&auxSueldo) == 0)
        {
            printf("%19d     %-16s %-14d %-d\n",auxId,auxNombre,auxHoras,auxSueldo);
        }
    }
}

int employee_lastId(LinkedList* pArrayListEmployee)
{
    int i;
    int ultimaId = 0;
    int len = ll_len(pArrayListEmployee);

    Employee* auxEmpleado = employee_new();

    for(i = 0; i < len; i++)
    {
        auxEmpleado = ll_get(pArrayListEmployee,i);
    }

    if(len != 0)
    {
        ultimaId = auxEmpleado->id;
    }

    return ultimaId;
}

int employee_findById(LinkedList* pArrayListEmployee, int id)
{
    int len = ll_len(pArrayListEmployee);
    int indice = -1;
    int auxId = 0;
    int i;

    Employee* pAuxEmpleado = employee_new();

    for(i = 0; i < len; i++)
    {
        pAuxEmpleado = ll_get(pArrayListEmployee,i);

        if(employee_getId(pAuxEmpleado,&auxId) == 0)
        {
            if(auxId == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int employee_insertToList(LinkedList* pArrayListEmployee,int len)
{
    int retorno = 1;
    int ultimaId;
    int i;

    Employee* pEmpleado = employee_new();

    for(i = 0; i < len; i++)
    {
        pEmpleado = ll_get(pArrayListEmployee,i);

        ultimaId = employee_lastId(pArrayListEmployee);

        pEmpleado->id = ultimaId + (len-i);

        retorno = 0;
    }

    ll_sort(pArrayListEmployee,employee_CompareById,1);

    return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
    int retorno;
    int idUno;
    int idDos;

    employee_getId(e1,&idUno);
    employee_getId(e2,&idDos);

    if(idUno > idDos)
    {
        retorno = 1;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}

int employee_CompareByName(void* e1, void* e2)
{
    int retorno;
    char nombreUno[128];
    char nombreDos[128];

    employee_getNombre(e1,nombreUno);
    employee_getNombre(e2,nombreDos);

    if(strcmpi(nombreUno,nombreDos) > 0)
    {
        retorno = 1;
    }
    else
    {
        if(strcmpi(nombreUno,nombreDos) < 0)
        {
            retorno = -1;
        }
    }

    return retorno;
}

// Setters.

int employee_setId(Employee* this,int id)
{
    int retorno = 1;

    if(id > 0)
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 1;

    if(nombre != NULL && strlen(nombre) > 1 && strlen(nombre) < 25)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 1;

    if(horasTrabajadas > -1)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 1;

    if(sueldo > -1)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}

// Getters.

int employee_getId(Employee* this,int* id)
{
    int retorno = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }

    return retorno;
}
