<<<<<<< HEAD
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#endif // ARRAYEMPLOYEES_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

int initEmployees(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee list[], int len,int id);
int removeEmployee(Employee list[], int len, int id);
int sortEmployees(Employee list[], int len, int order);
int printEmployees(Employee list[], int length);


=======
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#endif // ARRAYEMPLOYEES_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

int initEmployees(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee list[], int len,int id);
int removeEmployee(Employee list[], int len, int id);
int sortEmployees(Employee list[], int len, int order);
int printEmployees(Employee list[], int length);

int menu();
char confirmar();
int crearId(Employee list[],int len);
int crearUnEmpleado(Employee list[],int len);
void salarios(Employee list[],int tam);
void informesEmpleados(Employee list[],int tam);
void modificarEmpleado(Employee list[], int tam, int id);
int pedirId(Employee list[], int tam);

void hardCodearEmpleados(Employee list[], int tam);
>>>>>>> 2d7afa1f5a55dfed84b5443a63dff32baa0582a0
