#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*
 * \brief Pide memoria con malloc
 * \param
 * \return Retorna un puntero a empleado
 */
Employee* employee_new();

/*
 * \brief Llama a los setters que cargan los campos del empleado
 * \param idStr id del empleado como string, nombreStr nombre del empleado como string, horasTrabajadasStr cantidad de hs trabajadas como string, sueldoStr sueldo del empleado como string
 * \return Retorna un puntero a empleado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/*
 * \brief Elimina un empleado
 * \param this: puntero a empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_delete(Employee* this);

/*
 * \brief Valida y carga el id en el campo del empleado
 * \param this: puntero a empleado, id: id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_setId(Employee* this,int id);

/*
 * \brief Carga el id del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, id: puntero a la variable en la que la funcion cargara el id
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_getId(Employee* this,int* id);

/*
 * \brief Valida y carga el nombre en el campo del empleado
 * \param this: puntero a empleado, nombre: nombre a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_setNombre(Employee* this,char* nombre);

/*
 * \brief Carga el nombre del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, nombre: cadena de caracteres en la que la funcion cargara el nombre
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_getNombre(Employee* this,char* nombre);

/*
 * \brief Valida y carga las horas trabajadas en el campo del empleado
 * \param this: puntero a empleado, horasTrabajadas: horas a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/*
 * \brief Carga las horas trabajadas del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, horasTrabajadas: puntero a la variable en la que la funcion cargara las horas trabajadas
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/*
 * \brief Valida y carga el sueldo en el campo del empleado
 * \param this: puntero a empleado, sueldo: sueldo a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_setSueldo(Employee* this,int sueldo);

/*
 * \brief Carga el sueldo del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, sueldo: puntero a la variable en la que la funcion cargara el sueldo
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_getSueldo(Employee* this,int* sueldo);

/*
 * \brief Busca un empleado por id
 * \param pArrayListEmployee: LinkedList, id: id a buscar en la lista
 * \return -1 en caso de error, o el index del empleado en caso de exito
 */
int employee_SearchForId(LinkedList* pArrayListEmployee, int id);

/*
 * \brief Imprime un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_printEmployee(LinkedList* pArrayListEmployee, int index);

//Editar:

/*
 * \brief Cambia el nombre de un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changeName(LinkedList* pArrayListEmployee, int index);

/*
 * \brief Actualiza las horas trabajadas de un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changeHours(LinkedList* pArrayListEmployee, int index);

/*
 * \brief Cambia el salario de un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changeSalary(LinkedList* pArrayListEmployee, int index);


/*
 * \brief Devuelve el id mas alto de la lista
 * \param pArrayListEmployee: LinkedList
 * \return -1 en caso de error, o el id mas alto en caso de exito
 */
int employee_lastId(LinkedList* pArrayListEmployee);

/*
 * \brief Switchea entre los cases de ordenamiento
 * \param pArrayListEmployee: LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int employee_sort(LinkedList* pArrayListEmployee);

/*
 * \brief Compara los ids de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el id del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int employee_sortById(void* firstEmployee, void* secondEmployee);

/*
 * \brief Compara los nombres de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el nombre del primer empleado esta antes en el alfabeto, -1 si esta despues y 0 si son iguales
 */
int employee_sortByName(void* firstEmployee, void* secondEmployee);

/*
 * \brief Compara las horas trabajadas de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si las horas trabajadas del primer empleado son mas, -1 si son menos y 0 si son iguales
 */
int employee_sortByHours(void* firstEmployee, void* secondEmployee);

/*
 * \brief Compara los sueldos de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el sueldo del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int employee_sortBySalary(void* firstEmployee, void* secondEmployee);


#endif // employee_H_INCLUDED
