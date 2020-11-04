#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "Linkedlist.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);


/** \brief Remueve un empleado del linkedList
 *
 * \param pArrayListEmployee LinkedList* Linked list
 * \param index int posicion de puntero empleado en linkedList
 *  
 * \return int Return (-1) si error, (0) si exito.
 */
int employee_delete(LinkedList* this, int index);

/** \brief Imprime por pantalla al empleado apuntado por puntero
 *
 * \param Employee* anEmployee
 *  
 */
void employee_print(Employee* anEmployee);

/** \brief Busca la id maxima utlizada en linkedlist y le suma 1 
 *
 * \param LinkedList* this
 *  
 * \return int Return id a ser utilizada
 */
int employee_nextId(LinkedList* this);

/** \brief busca en la linkedlist una id que coincida con la ingresada por el usuario
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 *
 * \return int Return (-1) si error o la id de empleado encontrada
 */
int employee_lookForId(LinkedList* pArrayListEmployee, int id);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_edit(LinkedList* pArrayListEmployee, int index);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);
int employee_CompareByHoursWorked(void* e1, void* e2);
int employee_CompareBySalary(void* e1, void* e2);

#endif // employee_H_INCLUDED
