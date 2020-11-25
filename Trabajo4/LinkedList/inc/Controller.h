#include "../testing/inc/Employee.h"


/** \brief Muestra el menu principal y pide una opcion
 *
 * \param flagCargado int   Flag para mostrar si esta cargado o no un archivo
 * \return int  Opcion elegida
 *
 */
int controller_mainMenu(int flagCargado);

/** \brief Meustra el menu de editor y pide una opcion
 *
 * \return int Opcion elegida
 *
 */
int controller_editMenu();

/** \brief Pregunta al usuario si desea continuar
 *
 * \return char Respuesta elegida
 *
 */
char confirmar();

/** \brief Muestra los datos de un empleado
 *
 * \param this Employee*    Empleado a mostrar
 * \return void
 *
 */
void employee_print(Employee* this);



/** \brief Llama a funciones necesarias para cargar un archivo a eleccion
 *
 * \param path char*    Nombre del archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_loadFile(char* path, LinkedList* pArrayListEmployee);

/** \brief Permite el ingreso del nombre de un archivo a cargar
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_requestFile(LinkedList* pArrayListEmployee);

/** \brief Llama a funciones necesarias para cargar un empleado
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return void
 *
 */
void controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Llama a funciones necesarias para editar a un empleado a eleccion
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Muestra a todos los datos de todos los empleados
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return void
 *
 */
void controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Llama a funciones necesarias para eliminar a un empleado a eleccion
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return void
 *
 */
void controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Llama a funciones necesarias para hacer una copia de la lista
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return void
 *
 */
void controller_saveCopyList(LinkedList* pArrayListEmployee);

/** \brief Llama a funciones necesarias para ordenar la lista (Por ID o Apellido)
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return void
 *
 */
void controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Llama a funciones necesarias para eliminar a todos los empleados de a lista
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_removeAllEmployee(LinkedList* pArrayListEmployee);

/** \brief Llama a funciones necesarias para guardar la lista en un archivo cargado anteriormente
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return void
 *
 */
void controller_saveList(LinkedList* pArrayListEmployee);

/** \brief Llama a funciones necesarias para reemplazar a un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la LinkedList
 * \return void
 *
 */
void controller_replace(LinkedList* pArrayListEmployee);


