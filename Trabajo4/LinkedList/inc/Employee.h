#include "../inc/LinkedList.h"
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


/** \brief Busca y asigna espacio a un empleado nuevo
 *
 * \return Employee*    Empleado con el espacio asignado
 *
 */
Employee* employee_new();

/** \brief Parsea los datos necesarios y los setea a un nuevo empleado
 *
 * \param idStr char*   ID pasado como char
 * \param nameStr char* Nombre del empleado
 * \param lastNameStr char* Apellido del empleado
 * \param salaryStr char*   Sueldo pasado como char
 * \param sectorStr char*   Sector pasado como char
 * \return Employee*  Empleado con todos sus datos seteados
 *
 */
Employee* employee_newParametros(char* idStr,char* nameStr,char* lastNameStr,char* salaryStr,char* sectorStr);

/** \brief Libera espacio de un empleado
 *
 * \param this Employee*    Empleado a eliminar
 * \return void
 *
 */
void employee_delete(Employee* this);

/** \brief Pide todos los datos necesarios y los setea a un nuevo empleado
 *
 * \param nuevoEmpleado Employee*   Empleado a setear los datos
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_requestData(Employee* nuevoEmpleado);

/** \brief Permite elegir que editar del empleado
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \param this Employee*    Empleado a modificar
 * \param estadoModificado int* Flag para indicar si se modifico o no correctamente
 * \return char Respuesta del usuario para salir o no del menu de modificacion
 *
 */
char employee_edit(LinkedList* pArrayListEmployee,Employee* this,int* estadoModificado);




/** \brief Lee la ultima ID creada desde un archivo txt
 *
 * \return int  Ultima ID
 *
 */
int employee_readLastId();

/** \brief Gurada la ultima ID creada en un archivo txt
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return void
 *
 */
void employee_saveLastId(LinkedList* pArrayListEmployee);



/** \brief Busca el indice de un empleado por su ID
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \param id int    ID a buscar
 * \return int  Indice del empleado
 *
 */
int employee_findById(LinkedList* pArrayListEmployee, int id);

/** \brief Compara la ID del primer empleado con el segundo e indica si es mayor, menos o igual
 *
 * \param e1 void*  Primer empleado a comparar
 * \param e2 void*  Segundo empleado a comparar
 * \return int  Retorna 1 (mayor) -1 (menor) 0 (iguales)
 *
 */
int employee_CompareById(void* e1, void* e2);

/** \brief Compara los apellidos del primer empleado con el segundo e indice si es mayor, menos o igual
 *
 * \param e1 void*  Primer empleado a comparar
 * \param e2 void*  Segundo empleado a comparar
 * \return int  Retorna 1 (mayor) -1 (menor) 0 (iguales)
 *
 */
int employee_CompareByLastName(void* e1, void* e2);



/** \brief Guarda el nombre del ultimo archivo cargado
 *
 * \param nombre char*  Nombre del archivo a guardar
 * \param path char*    Archivo en donde se guardara
 * \return void
 *
 */
void guardarNombreDeArchivo(char* nombre,char* path);

/** \brief Lee el nombre del ultimo archivo cargado
 *
 * \param nombre char*  Nombre del ultimo archivo cargado
 * \param path char*    Archivo en donde se guardo el ultimo nombre
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int leerNombreDeArchivo(char* nombre,char* path);

/** \brief Obtiene los datos de un empleado y los escribe en un archivo
 *
 * \param this Employee*    Empleado a escribir en el archivo
 * \param pArchivo FILE*    Archivo a escribir el empleado
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_escribirEnArchivo(Employee* this,FILE* pArchivo);

/** \brief Guarda todos los datos de todos los empleados en un archivo
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \param pArchivo FILE*    Archivo a guardar todos los empleados
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_saveAll(LinkedList* pArrayListEmployee,FILE* pArchivo);

/** \brief Guarda una copia de la lista en un archivo nuevo
 *  Si no se cargo un archivo antes pide al usuario que ingrese que nombre quiere ponerle al archivo
 *  Si se cargo un archivo antes se crea un archivo nuevo llamado "Copy_of_(nombre del archivo cargado)"
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_saveCopy(LinkedList* pArrayListEmployee);



/** \brief Inserta empleados ya cargado anteriormente a la lista nueva cargada desde un archivo
 * Asinadoles un ID nuevo acorde a los ID de la nueva lista
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \param len int   Cantidad de empleados a insertar
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_insertToList(LinkedList* pArrayListEmployee,int len);




/** \brief Setea la ID al empleado pasados como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param id int    ID a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Obtiene la ID del empleado parado como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param id int*   ID a obtener
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief Setea el nombre al empleado pasados como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param name char*    Nombre a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setName(Employee* this,char* name);

/** \brief Obtiene el nombre del empleado parado como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param name char*    Nombre a obtener
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getName(Employee* this,char* name);


/** \brief Setea el apellido al empleado pasados como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param lastName char*    Apellido a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setLastName(Employee* this,char* lastName);

/** \brief Obtiene el apellido del empleado parado como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param lastName char*    Apellido a obtener
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getLastName(Employee* this,char* lastName);


/** \brief Setea el sector al empleado pasados como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param sector int    Sector a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setSector(Employee* this,int sector);

/** \brief Obtiene el sector del empleado parado como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param sector int*   Sector a obtener
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getSector(Employee* this,int* sector);


/** \brief Setea el sueldo al empleado pasados como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param salary float  Salario a setear
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_setSueldo(Employee* this,float salary);

/** \brief Obtiene el sueldo del empleado parado como parametro
 *
 * \param this Employee*    Puntero al empleado
 * \param salary float*    Sueldo a obtener
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int employee_getSueldo(Employee* this,float* salary);

