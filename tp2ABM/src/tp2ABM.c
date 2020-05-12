/*
 ============================================================================
 Name        : tp2ABM.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "arrayEmployees.h"
#include "sector.h"
#define LEN 1000 //array empleados
#define LENSEC 5 //array sectores
//-------------------
#define CANTHARDCODE 7


int main(void) {

	Employee employeeList[LEN];
	eSector sectors[LENSEC] = { {1, "Sistemas"},
								{2, "RRHH"},
								{3, "Ventas"},
								{4, "Compras"},
								{5, "Contable"} };

	int nextId = 999; //arranca en el 1000
	char continueS = 's';
	char confirm;
	char continueR;
	int index;
	int cuant;
	int i = 0;

	//Variables a ser escritas por collectData y luego leidas por addEmployee:
	char auxName[51];
	char auxLastname[51];
	float auxSalary;
	int auxSector;
	int auxId;

	//Flag Alta:
	int flag1 = 0; //Ponerla en 1 para harcodear

	//-----------------------
	//int proximoId = 1000;

	initEmployees(employeeList, LEN);
	//-------------------
	//harcodearEmpleados(employeeList, CANTHARDCODE); //hardcodeo 5 empleados
	//proximoId += CANTHARDCODE;

	do
	{
		system("clear");
		switch(menuEmployees())
		{
			case 1:
				printf("\n***** Altas *****\n\n ");
				utn_getEntero(&cuant, 3, "Cuantos empleados desea ingresar?: ", "Error, la cantidad ingresada es superior a la capacidad establecida o inferior 0.\n", 1, 1000);
				do
				{
					if(collectData(employeeList, LEN, &nextId, auxName, auxLastname, &auxSalary, &auxSector, &index) == 0 && addEmployee(employeeList, LEN, nextId, auxName, auxLastname, auxSalary, auxSector, index) == 0)
					{
						flag1 = 1; //modifico el flag de alta si las dos funciones retornaron 0
					}
					i++;
				}while(i < cuant);
				break;

			case 2:
				if(flag1 == 1)
				{
					modifyEmployees(employeeList, LEN, sectors, LENSEC);
				}
				else
				{
					printf("Error. Primero debe cargar empleados.\n");
				}
				break;


			case 3:
				if(flag1 == 1)
				{
					printf("\n***** Bajas *****\n\n ");
					do
					{
						showEmployees(employeeList, LEN, sectors, LENSEC);
						if(utn_getEntero(&auxId, 300, "Ingrese ID del empleado a eliminar: ", "Error, no es un numero de ID.\n", 1000, 2000) == 0)
						{
							removeEmployee(employeeList, LEN, auxId, sectors, LENSEC);
						}
						printf("Desea continuar eliminando? s/n: ");
						fpurge(stdin);
						scanf("%c", &confirm);
						if(confirm == 's')
						{
							continueR = 'n';
						}
					}while(continueR == 's');
				}
				else
				{
					printf("Primero debe cargar empleados.\n");
				}

				break;

			case 4:
				if(flag1 == 1)
				{
					inform(employeeList, LEN, sectors, LENSEC);
				}
				else
				{
					printf("Primero debe cargar empleados.\n");
				}
				break;

			case 5:
				system("clear");
				printf("\n***** Salir *****\n\n ");
				printf("Confirma salida? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirm);
				if(confirm == 's')
				{
					continueS = 'n';
				}
				break;
			default:
				printf("No es una opcion valida.\n");
		}
		pause();


	}while(continueS == 's');


	return EXIT_SUCCESS;
}



