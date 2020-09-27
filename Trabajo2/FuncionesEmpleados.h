#ifndef FUNCIONESEMPLEADOS_H_INCLUDED
#define FUNCIONESEMPLEADOS_H_INCLUDED
#include "ArrayEmployees.h"
#include "utn.h"
#define VACIO 0
#define OCUPADO 1
#endif // FUNCIONESEMPLEADOS_H_INCLUDED

int menu();
char confirmar();
int crearId(Employee list[],int len);
int crearUnEmpleado(Employee list[],int len);
void salarios(Employee list[],int tam);
void informesEmpleados(Employee list[],int tam);
void modificarEmpleado(Employee list[], int tam, int id);
int pedirId(Employee list[], int tam);
int contarEmpleados(Employee list[],int len);

void hardCodearEmpleados(Employee list[], int tam);
