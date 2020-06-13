#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;//error
	Employee *pEmployee;
	char id[200];
	char nombre[200];
	char horasTrabajadas[200];
	char sueldo[200];
	int nextId = 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4)
			{
				//imprime mientras fscanf devuelva 4
				//printf("%s - %s - %s\n", a, b, c);
				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(pEmployee != NULL)//osea si pudo cargar
				{
					ll_add(pArrayListEmployee, pEmployee);
					retorno = 0;//exito
				}
			}
			else
			{
				break;//salgo de do while
			}

		}while(feof(pFile) == 0); //lee todo el archivo
		retorno = nextId;//retorno el nextId como exito.
	}

    return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmployee;

	if(pFile != NULL)
	{
		do
		{
			pEmployee = employee_new(); //reservo lugar para un empleado
			//lectura fantasma
			//fread(pEmployee, sizeof(Employee), 1, pFile);//primera linea
			if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1) //leo datos binarios y valido si me leyo 1
			{
				ll_add(pArrayListEmployee, pEmployee);
				retorno = 0;//exito
			}
		}while(!feof(pFile));//mientras no sea el final del archivo
	}

    return retorno;
}
