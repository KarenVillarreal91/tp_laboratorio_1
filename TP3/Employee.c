#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* pEmpleado;

    pEmpleado = (Employee*) malloc(sizeof(Employee));       //Busca espacio con el tamaño de la estructura

    return pEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado = employee_new();
                                            //Verfica que ningun dato sea NULL
    if((pEmpleado != NULL) && (idStr != NULL) && (nombreStr != NULL) && (horasTrabajadasStr != NULL) && (sueldoStr != NULL))
    {
        if((employee_setId(pEmpleado,atoi(idStr))) ||
            (employee_setNombre(pEmpleado,nombreStr)) ||
            (employee_setHorasTrabajadas(pEmpleado,atoi(horasTrabajadasStr))) ||
            (employee_setSueldo(pEmpleado,atoi(sueldoStr))))    //Convierte los valores a int y los pasa a la lista
        {
            employee_delete(pEmpleado);  //Si alguna de las funciones retorna error, borra al empleado para que no se cargue y evitar inconvenientes.
            pEmpleado = NULL;
        }
    }

    return pEmpleado;
}

void employee_delete(Employee* this)
{
    free(this);     //Libera espacio
}

int employee_lastId(LinkedList* pArrayListEmployee)
{
    int i;
    int ultimaId = 0;
    int len = ll_len(pArrayListEmployee);

    if(len != 0)
    {
        Employee* auxEmpleado = employee_new();
        Employee* auxEmpleadoDos = employee_new();

        auxEmpleado = ll_get(pArrayListEmployee,0);     //Recorre la lista hasta el final
        employee_getId(auxEmpleado,&ultimaId);

        for(i = 0; i < len; i++)
        {
            auxEmpleadoDos = ll_get(pArrayListEmployee,i);

            if(employee_CompareById(auxEmpleadoDos,auxEmpleado) == 1)
            {
                if(ultimaId < auxEmpleadoDos->id)
                {
                    employee_getId(auxEmpleadoDos,&ultimaId);
                }
            }
        }
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
        pAuxEmpleado = ll_get(pArrayListEmployee,i);    //Recorre la lista obtiendo cada empleado

        if(employee_getId(pAuxEmpleado,&auxId) == 0)    //Obtiene la ID del empleado
        {
            if(auxId == id)     //Si coinciden las ID retorna el Indice
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
    int idNueva;
    int i;

    Employee* pEmpleado = employee_new();

    ultimaId = employee_lastId(pArrayListEmployee);     //Obtiene la ultima ID de la lista cargada

    for(i = 0; i < len; i++)
    {
        pEmpleado = ll_get(pArrayListEmployee,i);      //Recorre la lista obteniendo cada empleado

        idNueva = ultimaId + (len-i);   //Calcula la ID nueva apartir de la ultima ID y la cantidad de empleados antiguos

        employee_setId(pEmpleado,idNueva);      //Cambia las ID de los empleados existentes a las ultimas ID

        retorno = 0;
    }

    ll_sort(pArrayListEmployee,employee_CompareById,1);     //Ordena por ID para que los empleados antiguos se muevan al final

    return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
    int retorno;
    int idUno;
    int idDos;

    employee_getId(e1,&idUno);      //Obtiene la primera ID
    employee_getId(e2,&idDos);      //Obtiene la segunda ID

    if(idUno > idDos)     //Retorna si es mayor o menor 1 (mayor) -1 (menor)
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

    employee_getNombre(e1,nombreUno);      //Obtiene el primer Nombre
    employee_getNombre(e2,nombreDos);      //Obtiene el segundo Nombre

    if(strcmpi(nombreUno,nombreDos) > 0)    //Retorna si es mayor o menor 1 (mayor) -1 (menor)
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
