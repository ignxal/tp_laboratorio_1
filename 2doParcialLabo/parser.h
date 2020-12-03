/** \brief parsea un archivo de texto y lo agrega al linkedlist
 *
 * \param pFile FILE*
 * \param pArrayListCompetitor LinkedList*
 *
 * \return int: Return (-1) si NULL o (0) si 0k
 */
int parser_CompetitorFromText(FILE* pFile , LinkedList* pArrayListCompetitor);

/** \brief escribe contenido de linked list en archivo de texto
 *
 * \param pFile FILE*
 * \param pArrayListCompetitor LinkedList*
 *
 * \return int: Return (-1) si NULL o (0) si 0k
 */
int parser_CompetitorToText(FILE* pFile , LinkedList* pArrayListCompetitor);

int parser_aCompetitorToText(FILE* pFile, Competitor* pCompetitor);
