/*
 * arrayEmployees.h
 *
 *  Created on: May 6, 2020
 *      Author: catalina
 */

#include "sector.h"
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int idSector;
	int isEmpty;

} Employee;

/**
 * @brief Muestra el menu principal
 * @return Retorna la opcion elegida por el user.
 */
int menuEmployees();

/**
 * @brief Inicializa el campo isEmpy del vector de empleados en 1
 * @param Estructura eEmployee: lista de empleados
 * @return 0 si pudo inicializar con exito, y -1 si no.
 */
int initEmployees(Employee list[], int len);

/**
 * @brief Aniade empleados al vector de empleados.
 * @param Lista de empleados
 * @param Tamanio de la lista
 * @param Id del empleado
 * @param Nombre del empleado
 * @param Apellido del empleado
 * @param Salario
 * @param Sector
 * @param Indice en el cual cargarlo.
 * @return 0 si pudo cargar al empleado con exito, y -1 si no.
 */
int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector, int index);

/**
 * @brief Busca un lugar vacio (isEmpty = 0) en el vector de empleados
 * @param Lista de empleados
 * @param Tamanio de la lista.
 * @return 0 si pudo encontrar lugar vacio con exito, y -1 si no.
 */
int lookForEmpty(Employee list[], int len);

/**
 * @brief Encuentra un empleado en la lista con un id.
 * @param Lista de empleados
 * @param Largo de la lista
 * @param Id del empleado a buscar.
 * @return El indice del empleado si lo encuentra, sino -1.
 */
int findEmployeeById(Employee list[], int len, int id);

/**
 * @brief Da de baja a un empleado del sistema.
 * @param Lista de empleados
 * @param Tamanio de la lista
 * @param Id del empleado
 * @param Vector de sectores
 * @param Tamanio del vector de sectores.
 * @return 0 si pudo eliminar con exito, y -1 si no.
 */
int removeEmployee(Employee list[], int len, int id, eSector sectors[], int lenSec);

/**
 * @brief Colecta la informacion del empleado a pasarle a addEmployee
 * @param Lista de empleados
 * @param Tamanio de la lista
 * @param Puntero a proximo ID
 * @param Vector nombre auxiliar
 * @param Vector apellido auxiliar
 * @param Puntero a salario auxiliar
 * @param Puntero a sector auxiliar
 * @param Puntero a indice
 * @return 0 si pudo colectar la informacion con exito, y -1 si no.
 */
int collectData(Employee list[], int len, int* nextId, char auxName[], char auxLastname[], float* auxSalary, int* auxSector, int* index);

/**
 * @brief Muestra un empleado.
 * @param Empleado auxiliar
 * @param Vector de sectores
 * @param Vamanio del vector.
 * @return Sin retorno
 */
void showEmployee(Employee auxEmployee, eSector sectors[], int lenSec);

/**
 * @brief Muestra todos los empleados en sistema.
 * @param Lista de empleados
 * @param Tamanio del vector de empleados
 * @param Vector de sectores
 * @param Tamanio del vector de sectores.
 * @return Sin retorno
 */
void showEmployees(Employee list[], int len, eSector sectors[], int lenSec);

/**
 * @brief Modifica un campo especifico a elegir de un empleado
 * @param Lista de empleados
 * @param Tamanio del vector de empleados
 * @param Vector de sectores
 * @param Tamanio del vector de sectores.
 * @return 0 si pudo modificar con exito, y -1 si no.
 */
int modifyEmployees(Employee list[], int len, eSector sectors[], int lenSec);


//Informes:

/**
 * @brief Menu de informes.
 * @return Retorna la opcion elegida por el user.
 */
int menuInform();

/**
 * @brief Switchea entre las opciones que retorna menuInform
 * @param Lista de empleados
 * @param Tamanio del vector de empleados
 * @param Vector de sectores
 * @param Tamanio del vector de sectores
 * @return Retorna 0 si es una opcion valida, -1 si no
 */
int inform(Employee list[], int len, eSector sectors[], int lenSec);

/**
 * @brief Agrupa los empleados por sector (del 1 al 5) y los ordena por apellido de manera ascendente o descendente.
 * @param Lista de empleados
 * @param Tamanio del vector de empleados
 * @param Orden (1 para ascendente y 0 para descendente)
 * @return 0 si pudo ordenar con exito, y -1 si no.
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * @brief Hace el total y el promedio de los salarios de los empleados.
 * @param Lista de empleados
 * @param Tamanio del vector de empleados.
 * @return 0 si pudo calcular con exito, y -1 si no.
 */
int totalAndPromedySalaries(Employee* list, int len);


//-------------------------
void harcodearEmpleados(Employee vec[], int cant);

#endif /* ARRAYEMPLOYEES_H_ */
