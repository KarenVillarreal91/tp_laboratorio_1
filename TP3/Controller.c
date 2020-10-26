#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_menu()
{
    int op;

    printf("---------------------- Menu ----------------------\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado.\n");
    printf(" 4. Modificar datos de empleado.\n");
    printf(" 5. Baja de empleado.\n");
    printf(" 6. Listar empleados.\n");
    printf(" 7. Ordenar empleados.\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf(" 10. Salir.\n");
    printf("--------------------------------------------------\n\n");

    utn_getEntero(&op,2,"Ingrese un opcion: ","\nError! Opcion invalida.\n\n",1,10);

    return op;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    FILE* pArchivo = fopen(path,"r");

    if(pArchivo != NULL)
    {
        if(!(parser_EmployeeFromText(pArchivo,pArrayListEmployee)))
        {
            printf("Archivo cargado exitosamente.\n");
            retorno = 0;
        }
    }
    else
    {
        printf("Archivo no encontrado.\n");
    }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    FILE* pArchivo = fopen(path,"rb");

    if(pArchivo != NULL)
    {
        if(!(parser_EmployeeFromBinary(pArchivo,pArrayListEmployee)))
        {
            printf("Archivo cargado exitosamente.\n");
            retorno = 0;
        }
    }
    else
    {
        printf("Archivo no encontrado.\n");
    }

    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;

    Employee* nuevoEmpleado = employee_new();

    if(utn_getCadena(nuevoEmpleado->nombre,128,2,"Ingrese el nombre del empleado: ","\nError! Nombre invalido.\n\n") == 0)
    {
        if(utn_getEntero(&nuevoEmpleado->horasTrabajadas,2,"Ingrese la cantidad de horas trabajadas: ","\nError! Cantidad invalida.\n\n",0,530000) == 0)
        {
            if(utn_getEntero(&nuevoEmpleado->sueldo,2,"Ingrese el sueldo del empleado: ","\nError! Sueldo invalido.\n\n",0,500000) == 0)
            {
                nuevoEmpleado->id = employee_createId(pArrayListEmployee);

                retorno = ll_add(pArrayListEmployee,nuevoEmpleado);
            }
        }
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len = ll_len(pArrayListEmployee);
    int i;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\n%65s \n","-------------- Listado de Empleados --------------");
        printf("%19s %10s %20s %10s\n","ID","Nombre","Horas Trabajadas","Sueldo");
        printf("%65s \n","--------------------------------------------------");

        for(i = 0; i < len; i++)
        {
           employee_print(pArrayListEmployee,i);
        }

    }
    else
    {
        printf("\n\nNo hay empleados en la lista.\n\n");
    }

    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

