int menu (char mensaje[]);
/** \brief Permite el ingreso de opcion del menu
* 
* \param char [] mensaje de ingreso
* 
* \return int opcion elegida
*/

float getFloat (char mensaje[]);
/** \brief Permite el ingreso de un dato tipo flotante
* 
* \param char [] mensaje de ingreso
* 
* \return float el dato ingresado
*/

int getInt (char mensaje[]);
/** \brief Permite el ingreso de un dato tipo entero
* 
* \param char [] mensaje de ingreso
* 
* \return int el dato ingresado
*/

void getString(char mensaje[], char dato[]);
/** \brief Permite el ingreso de un dato tipo cadena
* 
* \param char [] mensaje de ingreso
* \param char [] dato ingresado
* \return void
*/

void operationConfirmation(int index);
/** \brief Confirms whether or not if operation was successful
* 
* \param int index value received
* 
*/