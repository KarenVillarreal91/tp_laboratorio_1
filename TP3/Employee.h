#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Busca espacio en memoria dinamica con su respectivo tamanio
 *
 * \return Employee*  Empleado asignado a memoria dinamica
 *
 */
Employee* employee_new();

/** \brief Convierte los valores y los pasa a la lista
 *
 * \param idStr char*   ID en string
 * \param nombreStr char*   Nombre del empleado
 * \param horasTrabajadasStr char*  Horas en string
 * \param sueldoStr char*   Sueldo en string
 * \return Employee*    Empleado con todos los valores seteados y cambiados de string a int
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief Libera espacio de un empleado
 *
 * \param this Employee*   Lista de empleados
 * \return void
 *
 */
void employee_delete(Employee* this);



/** \brief Setea una ID a un empleado
 *
 * \param this Employee*    Lista de empleados
 * \param id int    ID a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Obtiene la ID de un empleado
 *
 * \param this Employee*    Lista de empleados
 * \param id int*   ID del empleado a buscar
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getId(Employee* this,int* id);



/** \brief Setea un Nombre a un empleado
 *
 * \param this Employee*    Lista de empleados
 * \param nombre char*    Nombre a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Obtiene el nombre de un empleado
 *
 * \param this Employee*    Lista de empleados
 * \param nombre char*  Nombre del empleado a buscar
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getNombre(Employee* this,char* nombre);



/** \brief Setea las Horas a un empleado
 *
 * \param this Employee*    Lista de empleados
 * \param horasTrabajadas int   Horas a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene las horas trabajadas de un empleado
 *
 * \param this Employee*    Lista de empleados
 * \param horasTrabajadas int*  Horas del empleado a buscar
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);



/** \brief Setea un sueldo a un empleado
 *
 * \param this Employee*   Lista de empleados
 * \param sueldo int    Sueldo a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo de un empleado
 *
 * \param this Employee*   Lista de empleados
 * \param sueldo int*   Sueldo del empleado a buscar
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);



/** \brief Compara 2 Nombres
 *
 * \param e1 void*  Primer Nombre
 * \param e2 void*  Segundo Nombre
 * \return int  Retorna 1 (Mayor) -1 (Mayor)
 *
 */
int employee_CompareByName(void* e1, void* e2);

/** \brief  Compara 2 ID
 *
 * \param e1 void*  Primera ID
 * \param e2 void*  Segunda ID
 * \return int  Retorna 1 (Mayor) -1 (Mayor)
 *
 */
int employee_CompareById(void* e1, void* e2);




/** \brief Muestra a un empleado
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \param ind int   Indice del empleado
 * \return void
 *
 */
void employee_print(LinkedList* pArrayListEmployee,int ind);

/** \brief Busca la ultima ID y la retorna
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Ultima ID de la lista
 *
 */
int employee_lastId(LinkedList* pArrayListEmployee);

/** \brief Busca a un empleado mediante su ID
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \param id int    ID ingresado
 * \return int  Indice del empleado
 *
 */
int employee_findById(LinkedList* pArrayListEmployee, int id);

/** \brief Cambia la ID de los empleados antiguos para incorporarlos en la lista cargada
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \param len int   Cantidad de empleados a cambiar
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_insertToList(LinkedList* pArrayListEmployee,int len);
#endif // employee_H_INCLUDED
