/** \brief parsea un archivo de texto de empleado y lo agrega al linkedlist
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 *
 * \return int: Return (-1) si NULL o (0) si 0k
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief parsea un archivo binario de empleado y lo agrega al linkedlist
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 *
 * \return int: Return (-1) si NULL o (0) si 0k
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief escribe contenido de linked list en archivo de texto
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 *
 * \return int: Return (-1) si NULL o (0) si 0k
 */
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief escribe contenido de linked list en archivo binario
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 *
 * \return int: Return (-1) si NULL o (0) si 0k
 */
int parser_EmployeeToBinary(FILE* pFile, LinkedList* pArrayListEmployee);
