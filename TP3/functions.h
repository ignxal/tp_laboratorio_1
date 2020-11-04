/** \brief Permite el ingreso de un dato tipo flotante
*
* \param char [] mensaje de ingreso
*
* \return float el dato ingresado
*/
float getFloat (char message[]);

/** \brief Permite el ingreso de un dato tipo entero
*
* \param char [] mensaje de ingreso
*
* \return int el dato ingresado
*/
int getInt (char message[]);

/** \brief valida que todo los caracteres sean letras
 *
 * \param charArray[] char
 * \return int return (1) si 0k o 0 si ERROR
 *
 */
int isAlphabetic(char array[]);

/** \brief Permite el ingreso de un dato tipo cadena
*
* \param char [] mensaje de ingreso
+ \param char [] mensaje de error
* \param char [] dato ingresado
* \return void
*/
void getString(char message[], char errorMessage[], char array[]);

/** \brief Confirms whether or not if operation was successful
*
* \param int index value received
*
*/
void operationConfirmation(int index);

/** \brief Permite el ingreso de un dato tipo entero
*
* \param char [] message
* \param char [] messageError
* \param int min
* \param int max
*
* \return int el dato ingresado
*/
int getIntVal(char message[], char errorMessage[], int min, int max);

/** \brief Permite el ingreso de un caracter
*
* \param char [] message
* \param char [] messageError
* \param int a (validacion)
* \param int b (validacion)
*
* \return int el dato ingresado
*/
char getChar(char message[], char errorMessage[], char a, char b);
