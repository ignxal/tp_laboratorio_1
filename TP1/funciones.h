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
float doSum (float A, float B);
/** \brief Realiza la operacion suma
* 
* \param float A operador A ingresado
* \param float B operador B ingresado
* 
* \return float resultado operacion
*/
float doSub (float A, float B);
/** \brief Realiza la operacion resta
* 
* \param float B operador B ingresado
* \param float A operador A ingresado
* 
* \return float resultado operacion
*/
float doMul (float A, float B);
/** \brief Realiza la operacion multiplicacion
* 
* \param float A operador A ingresado
* \param float B operador B ingresado
* 
* \return float resultado operacion
*/
float doDiv (float A, float B);
/** \brief Si el operador B no es igual a 0, realiza la operacion division.
* 
* \param float A operador A ingresado
* \param float B operador B ingresado
* \return float resultado operacion validado
* 
*/
long long int doFact (float A);
/** \brief Se encarga de validar si con el dato ingresado es posible hacer factorial y, si lo es, realizará la operación.
*          Si no se puede realizar devolverá -1 (si no es entero) o -2 (si es negativo).
* 
* \param float A operador (A o B) ingresado
* 
* \return long long int resultado operacion
*/
void showResults (float suma, float resta, float multiplicacion, float division, int flag, long long int factorialA, long long int factorialB);
/** \brief Se encargará de imprimir por pantalla los resultados de cada operacion realizada, si es que previamente se realizaron.
* 
* \param float suma resultado suma
* \param float resta resultado resta
* \param float multiplicacion resultado multiplicacion
* \param float division resultado division
* \param int flag valida si los calculos se realizaron previamente
* \param long long int factorialA resultado del factorial del operador A
* \param long long int factorialB resultado del factorial del operador B
* 
*/