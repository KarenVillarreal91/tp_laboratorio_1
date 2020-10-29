
/** \brief Muestra el menu principal
 *
 * \param flagCargado int   Flag para mostrar si cargo o no un archivo
 * \return int  Opcion seleccionada por el usuario
 *
 */
int controller_mainMenu(int flagCargado);

/** \brief Muestra el menu para editar un empleado
 *
 * \return int  Opcion seleccionada por el usuario
 *
 */
int controller_editMenu();

/** \brief Imprime los datos de un empleado segun su indice
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \param ind int   Indice del empleado a mostrar
 * \return void
 *
 */
void employee_print(LinkedList* pArrayListEmployee,int ind);

/** \brief Confirma si el usuario quiere continuar o no en lo que esta haciendo
 *
 * \return char Respueta del usuario
 *
 */
char confirmar();



/** \brief  Carga una lista desde un archivo .csv
 *
 * \param path char*    Nombre del archivo
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief  Carga una lista desde un archivo .bin
 *
 * \param path char*    Nombre del archivo
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Pide los datos necesarios para crear un empleado en la lista
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Pide los datos necesarios para editar los datos de un empleado a eleccion
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Elimina los datos de un empleado a eleccion de la lista
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Muestra la lista completa de empleados
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief  Ordena la lista de empleados a eleccion (por ID o Nombre)
 *
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda la lista actual en un archivo .csv
 *
 * \param path char*    Nombre del archivo
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda la lista actual en un archivo .bin
 *
 * \param path char*    Nombre del archivo
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


