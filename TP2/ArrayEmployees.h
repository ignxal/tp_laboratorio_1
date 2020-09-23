#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define E 100
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

void addEmployeeFunction(sEmployee list[]);
