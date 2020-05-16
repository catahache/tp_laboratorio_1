/*
 * arrayEmployees.c
 *
 *  Created on: May 6, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "sector.h"
#include "utn.h"
//------------------
#include "dataWarehouse.h"



int menuEmployees()
{
	int option;

	system("clear");

	printf("***** M E N U *****\n\n");
	printf("  1. ALTAS\n");
	printf("  2. MODIFICAR\n");
	printf("  3. BAJA\n");
	printf("  4. INFORMAR\n");
	printf("  5. SALIR\n\n");

	utn_getEntero(&option, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 5);
	//printf("Ingresar opcion elegida: ");
	//scanf("%d", &opcion);

	return option;
}

int initEmployees(Employee list[], int len)
{
	if(list != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

void showEmployee(Employee auxEmployee, eSector sectors[], int lenSec)
{
	char descripSector[20];

	loadSectorDescription(descripSector, auxEmployee.idSector, sectors, lenSec); //carga la descripcion del sector

	printf("%d   %10s   %10s    %.2f    %10s\n", auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, descripSector);
}

void showEmployees(Employee list[], int len, eSector sectors[], int lenSec)
{
	printf(" ID       Nombre       Apellido    Salario       Sector\n\n");
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			showEmployee(list[i], sectors, lenSec);
		}
	}
}


int findEmployeeById(Employee list[], int len, int id)
{
	int exists = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(id == list[i].id)
			{
				exists = i; //devuelve el indice donde esta ese legajo cargado
				break;
			}
		}
	}
	return exists;
}

//------------------------------------------------------------------------------------------------------------------------------
//ALTA:

int lookForEmpty(Employee list[], int len)
{
	int index = -1; //retorna -1 si no hay lugares vacios

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 1)
		{
			index = i; //retorna el primer subindice vacio
			break;
		}
	}
	return index;
}

int collectData(Employee list[], int len, int* nextId, char auxName[], char auxLastname[], float* auxSalary, int* auxSector, int* index)
{
	int id = *nextId;
	int newId = id + 1;
	int isOk = -1;

	if(list != NULL && len > 0 && nextId != NULL && auxName != NULL && auxLastname != NULL && auxSalary != NULL && auxSector != NULL)
	{
		*index = lookForEmpty(list, len);

		if(index < 0) //porque lookForEmpty devolvio -1
		{
			printf("El sistema esta completo.\n");
		}
		else
		{
			utn_getCadena(auxName, 50, 3, "\nIngrese nombre: ", "El nombre ingresado es invalido.\n");
			utn_getCadena(auxLastname, 50, 3, "Ingrese apellido: ", "El apellido ingresado es invalido.\n");
			utn_getFlotante(auxSalary, 3, "Ingrese salario: ", "El salario ingresado no es valido.\n", 12000.00, 300000.00);
			utn_getEntero(auxSector, 3, "Ingrese sector: ", "El sector ingresado no es valido.\n", 1, 5);

			*nextId = newId;
			isOk = 0;
		}
	}
	return isOk;
}

int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector, int index)
{
	int isOk = -1;

	if(list != NULL && name != NULL && lastName != NULL && len > 0)
	{
		normalizeStr(name);
		normalizeStr(lastName);

		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].salary = salary;
		list[index].idSector = sector;
		list[index].isEmpty = 0;
		isOk = 0;
	}
	return isOk;
}


//------------------------------------------------------------------------------------------------------------------------------
//BAJA:

int removeEmployee(Employee list[], int len, int id, eSector sectors[], int lenSec)
{
	int index;
	char confirm;
	int isOk = -1;

	if(list != NULL && len > 0)
	{
		index = findEmployeeById(list, len, id);

		if(index < 0)
		{
			printf("\nError. El id ingresado no corresponde a un empleado.\n");
		}
		else
		{
			printf("\nEl id %d corresponde al empleado: \n", id);
			showEmployee(list[index], sectors, lenSec);
			printf("\nEsta seguro de que desea eliminarlo? s/n: ");
			fpurge(stdin);
			scanf("%c", &confirm);

			if(confirm == 's')
			{
				printf("El empleado ha sido eliminado exitosamente.\n");
				list[index].isEmpty = 1;
				isOk = 0;
			}
			else if (confirm == 'n')
			{
				printf("No se han realizado cambios.\n");
				isOk = 0;
			}
			else
			{
				printf("La opcion ingresada no es valida.\n");
			}
		}
	}

	return isOk;
}



//------------------------------------------------------------------------------------------------------------------------------
//MODIFICACION:

int modifyEmployees(Employee list[], int len, eSector sectors[], int lenSec)
{
	int isOk = -1;
	int auxId;
	int option;
	char confirm;
	char continueM;
	int index;
	char newName[51];
	char newLastname[51];
	float newSalary;
	int newSector;

	system("clear");
	printf("***** Modificaciones *****\n\n");
	showEmployees(list, len, sectors, lenSec);
	if(list != NULL && len > 0 && utn_getEntero(&auxId, 3, "\nIngrese ID de la persona a modificar: ", "Error. No es un ID.\n", 1000, 2000) == 0 )
	{
		index = findEmployeeById(list, len, auxId); //encuentra al empleado a modificar

		if(index == -1)
		{
			printf("No existe ese ID en el sistema.\n");
		}
		else
		{
			printf("El ID %d pertenece al siguiente empleado:\n", auxId);
			printf(" ID       Nombre       Apellido    Salario       Sector\n\n");
			showEmployee(list[index], sectors, lenSec);
			utn_getCadena(&confirm, 2, 3, "Desea modificarla? s/n: ", "Error. No es una opcion valida.");

			if(confirm == 's')
			{
				do
				{
					printf("    1. Modificar nombre\n");
					printf("    2. Modificar apellido\n");
					printf("    3. Modificar salario\n");
					printf("    4. Modificar sector\n\n");
					utn_getEntero(&option, 3, "Ingrese opcion a modificar: ", "Error, no es una opcion valida", 1, 4);

					switch(option) //copio los nuevos valores al empleado
					{
						case 1:
							utn_getCadena(newName, 51, 5, "Ingrese nuevo nombre: ", "Error, nombre invalido.\n");
							normalizeStr(newName);
							strcpy(list[index].name, newName);
							break;
						case 2:
							utn_getCadena(newLastname, 51, 5, "Ingrese nuevo apellido: ", "Error, apellido invalido.\n");
							normalizeStr(newName);
							strcpy(list[index].lastName, newLastname);
							break;
						case 3:
							utn_getFlotante(&newSalary, 5, "Ingrese nuevo salario: ", "Error, salario invalido.\n", 12000, 300000);
							list[index].salary = newSalary;
							break;
						case 4:
							utn_getEntero(&newSector, 5, "Ingrese nuevo sector: ", "Error, sector invalido.\n", 1, 5);
							list[index].idSector = newSector;
							break;
						default:
							printf("No es una opcion valida.\n\n");
					}
					printf("Se han modificado los datos correctamente. \n");
					printf("ID         Nombre     Apellido    Salario        Sector\n");
					showEmployee(list[index], sectors, lenSec); //muestro el empleado con los datos modificados
					printf("Desea seguir modificando? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueM = 'n';
					}
				}while(continueM == 's');
			}
			else if(confirm == 'n')
			{
				printf("No se han registrado modificaciones.\n");
			}
		}
		isOk = 0;
	}
	return isOk;
}



//------------------------------------------------------------------------------------------------------------------------------
//INFORMES:

int menuInform()
{
	int opcion;

	system("clear");
	printf("\n***** Informes *****\n\n");

	printf("1. Listar empleados ordenados alfabeticamente por Apellido y agrupados por Sector\n");
	printf("2. Total y promedio de los salarios\n");
	printf("3. Salir\n\n");

	utn_getEntero(&opcion, 300, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 3);

	return opcion;
}

int inform(Employee list[], int len, eSector sectors[], int lenSec)
{
	int isOk = -1;
	char continueI = 's';
	char confirm;
	int ascDes;

	if(list != NULL && sectors != NULL)
	{

		do
		{
			switch(menuInform()) //retorna la opcion
			{
				case 1:
					utn_getEntero(&ascDes, 300, "\nIngrese 1 para listar de manera ascendente o 0 para descendente: ", "Error. No es un ordenamiento posible.\n", 0, 1);
					printf("\n");
					sortEmployees(list, len, ascDes);
					showEmployees(list, len, sectors, lenSec);
					pause();
					isOk = 0;//exito
					break;
				case 2:
					totalAndPromedySalaries(list, len);
					isOk = 0;//exito
					break;
				case 3:
					printf("Confirma salida? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueI = 'n';
					}
					isOk = 0;//exito
					break;
				default:
					printf("No es una opcionn valida.\n\n");
			}
		}while(continueI == 's');
	}
	return isOk;
}

int sortEmployees(Employee* list, int len, int order)
{
	//agrupar por sector y ordenar por apellido
	int isOk = -1;
	Employee auxEmployee;

	if(list != NULL)
	{
		for(int i = 0; i < len -1; i++)
		{
			for(int j = i + 1; j < len; j ++)
			{
				isOk = 0;

				if(list[i].isEmpty == 0 && list[j].isEmpty == 0) //solo hace el burbujeo si no estan vacias las posiciones
				{

					switch(order)
					{
						case 0:
							if(list[i].idSector < list[j].idSector || (list[i].idSector == list[j].idSector && (strcmp(list[i].lastName, list[j].lastName)) < 0)) //de mayor a menor sector (agrupa) y apellido (ordena)
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
							}
							break;
						case 1:
							if(list[i].idSector > list[j].idSector || (list[i].idSector == list[j].idSector && (strcmp(list[i].lastName, list[j].lastName)) > 0)) //de menor a mayor sector (agrupa) y apellido (ordena)
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
							}
							break;
						default:
							printf("No es un orden valido.\n");
					}
				}//if isEmpty
			}//for
		}//for
	}//if list != NULL
	return isOk;
}

int totalAndPromedySalaries(Employee* list, int len)
{
	int isOk = -1;
	float accumSalaries = 0;
	int countEmployees = 0;
	float promedy;
	int countEmployeesHigher = 0; //cuenta cuantos empleados superan el salario promedio

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				accumSalaries += list[i].salary;
				countEmployees++;
			}
		}

		promedy = (float) accumSalaries / countEmployees;

		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > promedy)
			{
				countEmployeesHigher++;
			}

		}
		isOk = 0;

		printf("\nEl total de los salarios de los %d empleados en sistema es de: $ %.2f\n", countEmployees, accumSalaries);
		printf("El promedio de todos los salarios es de: $ %.2f\n", promedy);
		if(countEmployeesHigher == 1)
		{
			printf("Hay %d empleado que supera el salario promedio.\n\n", countEmployeesHigher);
		}
		else if(countEmployeesHigher < 1)
		{
			printf("No hay empleados que superen el salario promedio.\n\n");
		}
		else
		{
			printf("Hay %d empleados que superan el salario promedio.\n\n", countEmployeesHigher);
		}
		pause();

	}


	return isOk;
}


//---------------------------

void harcodearEmpleados(Employee vec[], int cant)
{
	for(int i = 0; i < cant; i++)
	{
		vec[i].id = ids[i]; //uso los datos pregarcados de la libreria dataWarehouse
		strcpy(vec[i].name, nombres[i]);
		strcpy(vec[i].lastName, apellidos[i]);
		vec[i].salary = sueldos[i];
		vec[i].idSector = idsSector[i];
		vec[i].isEmpty = 0;
	}
}
