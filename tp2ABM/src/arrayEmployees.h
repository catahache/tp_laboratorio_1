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

int menuEmployees();

int initEmployees(Employee list[], int len);

int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector, int index);

int lookForEmpty(Employee list[], int len);

int findEmployeeById(Employee list[], int len, int id);

int removeEmployee(Employee list[], int len, int id, eSector sectors[], int lenSec);

int collectData(Employee list[], int len, int* nextId, char auxName[], char auxLastname[], float* auxSalary, int* auxSector, int* index);

void showEmployee(Employee auxEmployee, eSector sectors[], int lenSec);

void showEmployees(Employee list[], int len, eSector sectors[], int lenSec);

int modifyEmployees(Employee list[], int len, eSector sectors[], int lenSec);

int sortEmployees(Employee* list, int len, int order);

int totalAndPromedySalaries(Employee* list, int len);

//Informes:

int menuInform();

int inform(Employee list[], int len, eSector sectors[], int lenSec);

//-------------------------
void harcodearEmpleados(Employee vec[], int cant);

#endif /* ARRAYEMPLOYEES_H_ */
