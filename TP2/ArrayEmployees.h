#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define E 1000
#define FULL 1
#define EMPTY 0
#define DELETED -1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all position of the array
 * \param sEmployee list[]
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(sEmployee list[], int len);

/** \brief Shows info from an employee
* 
* \param sEmployee list[]
*/ 
void printAnEmployee (sEmployee list);

 
/** \brief print the content of employees array
 *
 * \param sEmployee list[]
 * \param len int
 * \return int
 *
 */
int printEmployees (sEmployee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position - This functions calls the ones involved
 * \param sEmployee list
 */
void addEmployeeMain(sEmployee list[]);

/** \brief Generates an automatic ID for Employees
* 
* \param sEmployee list[]
* \param len int Array length
* 
* \return int the ID generated
*/
int generateId(sEmployee list[], int len);

/** \brief Search for space in the array
* 
* \param sEmployee list[]
* \param len int Array length
* 
* \return int Return (-1) if Error [Couldn't find space] - (Value) If found space
*/
int lookForSpace(sEmployee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param sEmployee list
 * \param len int
 * \param index int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(sEmployee list[], int len, int index);


/** \brief Modify an Employee by Id - This functions calls the ones involved
 *
 * \param sEmployee list[]
 */ 
void modifyEmployeeMain(sEmployee list[]);

/** \brief Modify an Employee by Id - This functions calls the ones involved
 *
 * \param sEmployee list[]
 * \param len int
 * \param auxID int
 * 
 * \return int confirmacion (-1) If error - (0) If Ok
 */ 
int validateID(sEmployee list[], int len, int auxID);

/** \brief Modify an Employee by Id - This functions calls the ones involved
 *
 * \param sEmployee list[]
 * \param len int
 * \param option int
 * \param auxID int
 * 
 * \return int confirmacion (-1) If error - (0) If Ok
 */ 
int modifyEmployee(sEmployee list[], int len, int option, int auxID);

/** \brief Remove an Employee by Id (put isEmpty Flag in 1) - This functions calls the ones involved
 *
 * \param sEmployee list[]
 */ 
void removeEmployeeMain(sEmployee list[]);

/** \brief Remove an Employee by Id (put isEmpty Flag in 1)
 *
 * \param sEmployee list[]
 * \param len int Array length
 * 
 * \return int Return (-1) if Error [Invalid length or if can't find a pet] - (1) if Ok
 */
int removeEmployee (sEmployee list[], int len);

/** \brief Print available info - This functions gives the option to choose between both options
 *
 * param sEmployee list[]
 */
void aboutEmployees(sEmployee list[]);

/** \brief Sort the elements in the array of employees - This functions calls the ones involved
 *
 * param sEmployee list[]
 */
void sortEmployeesMain(sEmployee list[]);

/** \brief Sort the elements in the array of employees
 *
 * \param sEmployee list[]
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(sEmployee list[], int len, int order);

/** \brief Calculates average salary between employees - This functions calls the ones involved
 *
 * param sEmployee list[]
 */
void averageSalary(sEmployee list[]);

/** \brief Does sum operation
* 
* \param sEmployee array[]
* \param int len array length
* 
* \return float result
*/
float doSum(sEmployee list[],int len);

/** \brief Search for not empty space in the array and sum them
* 
* \param sEmployee list[]
* \param len int Array length
* 
* \return int Return result
*/
int sumFullSpaces(sEmployee list[], int len);

/** \brief Does average operation
* 
* \param sEmployee array[]
* 
* \return float average
*/
float doAverage (sEmployee list[]);

/** \brief Calculates how many employees are above the average salary 
* 
* \param sEmployee list[]
* \param len int Array length
* \param average float
* 
* \return int Return amount of employees above average
*/
int aboveAverage (sEmployee list[], int len, float average);