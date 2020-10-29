
/** \brief Pasa y parsea los datos de un archivo .csv a la lista linkeada
 *
 * \param pFile FILE*   Archivo
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Pasa y parsea los datos de un archivo .bin a la lista linkeada
 *
 * \param pFile FILE*   Archivo
 * \param pArrayListEmployee LinkedList*    Lista linkeada
 * \return int  Retorna 1 (Mal) 0 (Bien)
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
