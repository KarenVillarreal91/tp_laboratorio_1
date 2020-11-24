/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "../../inc/LinkedList.h"
#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;
#endif // __EMPLOYEE

Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector);
int compareEmployee(void* pEmployeeA,void* pEmployeeB);
void printEmployee(Employee* p);

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nameStr,char* lastNameStr,char* salaryStr,char* sectorStr);
void employee_delete(Employee* this);
int employee_requestData(Employee* nuevoEmpleado);

int employee_readLastId();
int employee_saveLastId(LinkedList* pArrayListEmployee);

int employee_findById(LinkedList* pArrayListEmployee, int id);
int employee_CompareById(void* e1, void* e2);
int employee_CompareByLastName(void* e1, void* e2);

void guardarNombreDeArchivo(char* nombre,char* path);
int leerNombreDeArchivo(char* nombre,char* path);
int employee_escribirEnArchivo(Employee* this,FILE* pArchivo);
int employee_saveAll(LinkedList* pArrayListEmployee,FILE* pArchivo);
int employee_saveCopy(LinkedList* pArrayListEmployee);

int employee_insertToList(LinkedList* pArrayListEmployee,int len);



int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setLastName(Employee* this,char* lastName);
int employee_getLastName(Employee* this,char* lastName);

int employee_setSector(Employee* this,int sector);
int employee_getSector(Employee* this,int* sector);

int employee_setSueldo(Employee* this,float salary);
int employee_getSueldo(Employee* this,float* salary);
