#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Employee.h"
#include "../inc/Controller.h"
#include "../inc/utn.h"

Employee* employee_new()
{
    Employee* pEmpleado;

    pEmpleado = (Employee*) malloc(sizeof(Employee));       //Busca espacio con el tamaño de la estructura

    return pEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nameStr,char* lastNameStr,char* salaryStr,char* sectorStr)
{
    Employee* pEmpleado = employee_new();
                                            //Verfica que ningun dato sea NULL
    if((pEmpleado != NULL) && (idStr != NULL) && (nameStr != NULL )&& (nameStr != NULL) && (sectorStr != NULL) && (salaryStr != NULL))
    {
        if((employee_setId(pEmpleado,atoi(idStr))) ||
            (employee_setName(pEmpleado,nameStr)) ||
            (employee_setLastName(pEmpleado,lastNameStr)) ||
            (employee_setSueldo(pEmpleado,atof(salaryStr))) ||    //Convierte los valores a int/float y los pasa a la lista
            (employee_setSector(pEmpleado,atoi(sectorStr))))
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

int employee_requestData(Employee* nuevoEmpleado)
{
    int retorno = -1;
    int auxId;
    char auxNombre[51];
    char auxApellido[51];
    float auxSueldo;
    int auxSector;

    //Ingreso de datos
    if(utn_getCadena(auxNombre,51,2,"\n Ingrese el nombre del empleado: ","\n Error! Nombre invalido.\n\n") == 0)
    {
        if(utn_getCadena(auxApellido,51,2,"\n Ingrese el apellido del empleado: ","\n Error! Apellido invalido.\n\n") == 0)
        {
            if(utn_getFlotante(&auxSueldo,2,"\n Ingrese el sueldo del empleado: ","\n Error! Sueldo invalido.\n\n",0,500000) == 0)
            {
                if(utn_getEntero(&auxSector,2,"\n Ingrese el sector del empleado: ","\n Error! Sector invalido (1-5).\n\n",1,5) == 0)
                {
                    auxId = employee_readLastId();     //Busca la ultima ID de la lista

                    if(employee_setId(nuevoEmpleado,auxId+1) == 0 &&
                    employee_setName(nuevoEmpleado,auxNombre) == 0 &&
                    employee_setLastName(nuevoEmpleado,auxApellido) == 0 &&
                    employee_setSueldo(nuevoEmpleado,auxSueldo) == 0 &&
                    employee_setSector(nuevoEmpleado,auxSector) == 0)   //Setea todos los valores ingresados
                    {
                        retorno = 0;
                    }
                }
            }
        }
    }

    return retorno;
}

char employee_edit(LinkedList* pArrayListEmployee,Employee* this,int* estadoModificado)
{
    char respuestaSalida;
    char auxNombre[51];
    char auxApellido[51];
    int auxSueldo;
    int auxSector;
    int indice = ll_indexOf(pArrayListEmployee,this);

    switch(controller_editMenu())   //Muestra un menu de opciones
    {
        case 1:     // Edita el nombre
            if(utn_getCadena(auxNombre,51,0,"\n Ingrese el nuevo nombre del empleado: ","\n Error! Nombre invalido.\n") == 0)
            {
                if(confirmar() == 's')
                {
                    employee_setName(this,auxNombre);
                }
            }
        break;

        case 2:     // Edita el Apellido
            if(utn_getCadena(auxApellido,51,0,"\n Ingrese el nuevo apellido del empleado: ","\n Error! Apellido invalido.\n") == 0)
            {
                if(confirmar() == 's')
                {
                   employee_setLastName(this,auxApellido);
                }
            }
        break;

        case 3:     // Edita el sueldo
            if(utn_getEntero(&auxSueldo,0,"\n Ingrese el nuevo sueldo del empleado: ","\n Error! Sueldo invalido.\n",0,500000) == 0)
            {
                if(confirmar() == 's')
                {
                    employee_setSueldo(this,auxSueldo);
                }
            }
        break;

        case 4:     // Edita las horas
            if(utn_getEntero(&auxSector,0,"\n Ingrese el nuevo sector: ","\n Error! Sector invalida (1-5).\n",1,5) == 0)
            {
                if(confirmar() == 's')
                {
                    employee_setSector(this,auxSector);
                }
            }
        break;

        case 5:    // Salida
            respuestaSalida = confirmar();
        break;
    }

    *estadoModificado = ll_set(pArrayListEmployee,indice,this); //Setea todos los cambios en la linkedlist

    return respuestaSalida;
}

int employee_readLastId()
{
    FILE* pUltimaId = fopen("ultimaid.txt","r");

    int auxUltimaId = 0;

    if(pUltimaId != NULL)
    {
        fscanf(pUltimaId,"%d",&auxUltimaId);
    }

    fclose(pUltimaId);

    return auxUltimaId;
}

void employee_saveLastId(LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;

    int i;
    int auxId;
    int ultimaId = 0;
    int len = ll_len(pArrayListEmployee);

    pArchivo = fopen("ultimaid.txt","w");

    if(pArchivo != NULL)
    {
        if(len != 0)
        {
            Employee* auxEmpleado = employee_new(); //Crea espacio para dos empleados
            Employee* auxEmpleadoDos = employee_new();

            auxEmpleado = ll_get(pArrayListEmployee,0); //Obtiene los datos del primer empleado
            employee_getId(auxEmpleado,&ultimaId);  //Obtiene su ID

            for(i = 0; i < len; i++)    //Recorre la lista
            {
                auxEmpleadoDos = ll_get(pArrayListEmployee,i);  //Obtiene los datos del segundo empleado

                if(employee_CompareById(auxEmpleadoDos,auxEmpleado) == 1)    //Compara los emplados por id
                {
                    employee_getId(auxEmpleadoDos,&auxId);

                    if(ultimaId < auxId)    //Compara con la ultima id
                    {
                        ultimaId = auxId;   //Si es menor a la id del segundo empleado toma el valor
                    }
                }
            }
        }
    }

    fprintf(pArchivo,"%d",ultimaId);
    fclose(pArchivo);
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

int employee_CompareById(void* e1, void* e2)
{
    int retorno = 0;
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
        if(idUno < idDos)
        {
            retorno = -1;
        }
    }

    return retorno;
}

int employee_CompareByLastName(void* e1, void* e2)
{
    int retorno;
    char apellidoUno[51];
    char apellidoDos[51];

    employee_getLastName(e1,apellidoUno);      //Obtiene el primer Nombre
    employee_getLastName(e2,apellidoDos);      //Obtiene el segundo Nombre

    retorno = strcmpi(apellidoUno,apellidoDos);  //Retorna si es mayor o menor 1 (mayor) -1 (menor)

    return retorno;
}

void guardarNombreDeArchivo(char* nombre,char* path)
{
    FILE* pArchivo;

    pArchivo = fopen(path,"w");

    fprintf(pArchivo,"%s",nombre);

    fclose(pArchivo);
}

int leerNombreDeArchivo(char* nombre,char* path)
{
    int retorno = -1;
    FILE* pArchivo;

    pArchivo = fopen(path,"r");

    if(fscanf(pArchivo,"%s",nombre) == 1)
    {
        retorno = 0;
    }

    fclose(pArchivo);

    return retorno;
}

int employee_escribirEnArchivo(Employee* this,FILE* pArchivo)
{
    int retorno = -1;
    int auxId;
    char auxNombre[51];
    char auxApellido[51];
    float auxSueldo;
    int auxSector;

    if((employee_getId(this,&auxId)) == 0 &&
        (employee_getName(this,auxNombre)) == 0 &&
        (employee_getLastName(this,auxApellido)) == 0 &&
        (employee_getSueldo(this,&auxSueldo)) == 0 &&
        (employee_getSector(this,&auxSector)) == 0)
    {
        fprintf(pArchivo,"%d,%s,%s,%f,%d\n",auxId,auxNombre,auxApellido,auxSueldo,auxSector);
        retorno = 0;
    }

    return retorno;
}

int employee_saveAll(LinkedList* pArrayListEmployee,FILE* pArchivo)
{
    int retorno = -1;
    int i;

    Employee* pEmployee;

    if(pArrayListEmployee != NULL && pArchivo != NULL)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++) //Recorre toda la lista
        {
            pEmployee = ll_get(pArrayListEmployee,i);   //Obtiene cada empleado

            retorno = employee_escribirEnArchivo(pEmployee,pArchivo);   //Lo escribe en el archivo
        }
    }

    return retorno;
}

int employee_saveCopy(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char nombre[50];
    char nombreFinal[50] = "Copy_of_";

    FILE* pArchivo;

    if(leerNombreDeArchivo(nombre,"nombreDelArchivo.txt") == 0) //Obtiene el nombre el archivo
    {
        strcat(nombreFinal,nombre); //Concatena el nombre del archivo al "Copy_of_"
    }
    else
    {
        if(utn_getCadena(nombre,50,1,"\n Se creara un archivo nuevo, ingrese el nombre que quiere ponerle con su extension: ","\n Error! Nombre invalido.\n") == 0)
        {
            strcpy(nombreFinal,nombre);
        }
    }

    pArchivo = fopen(nombreFinal,"w");

    retorno = employee_saveAll(pArrayListEmployee,pArchivo);    //Guarda todos los empleados en el archivo

    fclose(pArchivo);

    return retorno;
}

int employee_insertToList(LinkedList* pArrayListEmployee,int len)
{
    int retorno = 1;
    int ultimaId;
    int idNueva;
    int i;

    Employee* pEmpleado = employee_new();

    ultimaId = employee_readLastId();     //Obtiene la ultima ID de la lista cargada

    for(i = 0; i < len; i++)
    {
        pEmpleado = ll_pop(pArrayListEmployee,0); //Borra al empleado y lo obtiene

        if(ll_contains(pArrayListEmployee,pEmpleado) == 0)   //Verifica que el empleado este en la lista
        {
            idNueva = ultimaId + (len-i);   //Calcula la ID nueva apartir de la ultima ID y la cantidad de empleados antiguos

            employee_setId(pEmpleado,idNueva);      //Cambia las ID de los empleados existentes a las ultimas ID

            retorno = ll_add(pArrayListEmployee,pEmpleado); //Agrega al empleado al final de la lista
        }
    }

    ll_sort(pArrayListEmployee,employee_CompareById,1);
    employee_saveLastId(pArrayListEmployee);

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

int employee_setName(Employee* this,char* name)
{
    int retorno = 1;

    if(name != NULL && strlen(name) > 1 && strlen(name) < 51)
    {
        strcpy(this->name,name);
        retorno = 0;
    }

    return retorno;
}

int employee_setLastName(Employee* this,char* lastName)
{
    int retorno = 1;

    if(lastName != NULL && strlen(lastName) > 1 && strlen(lastName) < 51)
    {
        strcpy(this->lastName,lastName);
        retorno = 0;
    }

    return retorno;
}

int employee_setSector(Employee* this,int sector)
{
    int retorno = 1;

    if(sector > -1)
    {
        this->sector = sector;
        retorno = 0;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,float salary)
{
    int retorno = 1;

    if(salary > -1)
    {
        this->salary = salary;
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

int employee_getName(Employee* this,char* name)
{
    int retorno = 1;

    if(this != NULL && name != NULL)
    {
        strcpy(name,this->name);
        retorno = 0;
    }

    return retorno;
}

int employee_getLastName(Employee* this,char* lastName)
{
    int retorno = 1;

    if(this != NULL && lastName != NULL)
    {
        strcpy(lastName,this->lastName);
        retorno = 0;
    }

    return retorno;
}

int employee_getSector(Employee* this,int* sector)
{
    int retorno = 1;

    if(this != NULL && sector != NULL)
    {
        *sector = this->sector;
        retorno = 0;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,float* salary)
{
    int retorno = 1;

    if(this != NULL && salary != NULL)
    {
        *salary = this->salary;
        retorno = 0;
    }

    return retorno;
}
