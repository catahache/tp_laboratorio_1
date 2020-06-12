#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

#define NAME_LEN 30


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int nextId;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		nextId = parser_EmployeeFromText(pFile, pArrayListEmployee);
		if(nextId >= 0)//porque devuelve el prox id si la ejecucion es exitosa
		{
			retorno = nextId; //exito
			printf("Archivo de texto cargado con exito\n");
		}
		else
		{
			printf("Error\n");
		}
		fclose(pFile);
	}
	else
	{
		printf("Error\n");
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;//error
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			retorno = 0; //exito
			printf("Archivo de texto cargado con exito\n");
		}
		else
		{
			printf("Error\n");
		}
	}
	else
	{
		printf("Error\n");
	}
	fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;//exit
	char auxName[NAME_LEN];
	int auxHours;
	int auxSalary;
	int nextId;
	Employee* pEmployee = employee_new();//malloc

	if(pArrayListEmployee != NULL && pEmployee != NULL)
	{
		if(!utn_getCadena(auxName, NAME_LEN, 2, "Ingrese nombre: ", "Error, nombre invalido") &&
		   !utn_getEntero(&auxHours, 2, "Ingrese cantidad de horas trabajadas: ", "Error, antidad invalida\n", 0, 100000) &&
		   !utn_getEntero(&auxSalary, 2, "Ingrese salario de 18000 a 30000: ", "Error, salario invalido\n", 18000, 300000))
		{
			normalizeStr(auxName);//normalizo nombre
			//leo el archivo
			nextId = controller_loadFromText(path, pArrayListEmployee);//me devuelve (si todo esta bien) el id mas alto
			if(nextId >= 0)
			{
				nextId += 1;//porque el proximo es el mas alto + 1

				if(!employee_setId(pEmployee, nextId) &&
				   !employee_setNombre(pEmployee, auxName) &&
				   !employee_setHorasTrabajadas(pEmployee, auxHours) &&
				   !employee_setSueldo(pEmployee, auxSalary))
				{
					ll_add(pArrayListEmployee, pEmployee);
					printf("Alta exitosa\n");
					printf("%d", nextId);
				}//if setters
				else
				{
					free(pEmployee);
				}
			}//if nextId
		}//if utn
		else
		{
			free(pEmployee);//libero el espacio
		}
	}//if null
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int auxId;
	int lastId;
	int retorno = -1;
	int index;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);//listo los empleados

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);

			employee_getId(pEmployee, &auxId);
			if(auxId >= lastId)
			{
				lastId = auxId;//el ultimo id va a ser el mas grande
			}
		}

		if(!utn_getEntero(&auxId, 2, "Ingrese ID de empleado a modificar.\n", "Error, ID invalido", 0, lastId))
		{
			index = employee_SearchForId(pArrayListEmployee, auxId);
			if(index > -1)
			{
				//mostrar el empleado
				printf("\n ID    Nombre   Horas Trabajadas   Sueldo\n\n");
				employee_printEmployee(pArrayListEmployee, index);//imprimo el empleado elegido
				//menu editar
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee( LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int lastId = 1;
	Employee* pEmployee;
	int index;
	char confirmDelete;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);//listo los empleados

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);

			employee_getId(pEmployee, &auxId);
			if(auxId >= lastId)
			{
				lastId = auxId;//el ultimo id va a ser el mas grande
			}
		}

		if(!utn_getEntero(&auxId, 2, "Ingrese ID de empleado a eliminar del sistema.\n", "Error, ID invalido", 0, lastId))
		{
			index = employee_SearchForId(pArrayListEmployee, auxId);
			if(index > -1)
			{
				//mostrar el empleado
				printf("\n ID    Nombre   Horas Trabajadas   Sueldo\n\n");
				employee_printEmployee(pArrayListEmployee, index);//imprimo el empleado elegido

				printf("Confirma la baja del empleado? y/n: ");
				scanf("%c", &confirmDelete);
				if(confirmDelete == 'y')
				{
					ll_remove(pArrayListEmployee, index);//elimino el empleado en ese index
					employee_delete(pEmployee);//elimino el punt aux que me cree
					printf("Baja realizada con exito\n");
					retorno = 0;
				}
			}
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	//int auxId;
	//char auxName[NAME_LEN];
	//int auxHours;
	//int auxSalary;
	//Employee* pEmployee;


	if(pArrayListEmployee != NULL)
	{
		printf("\n ID    Nombre   Horas Trabajadas   Sueldo\n\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{

			employee_printEmployee(pArrayListEmployee, i);
			/*
			pEmployee = ll_get(pArrayListEmployee, i);//traigo un puntero a empleado de la lista
			if(employee_getId(pEmployee, &auxId) == 0 &&
			   employee_getNombre(pEmployee, auxName) == 0&&
			   employee_getHorasTrabajadas(pEmployee, &auxHours) == 0 &&
			   employee_getSueldo(pEmployee, &auxSalary) == 0)
			{
				printf("%10d    %10s    %10d    %10d\n", auxId, auxName, auxHours, auxSalary);
			}
			else
			{
				printf("Error\n");
			}
			*/

		}
	}
	else
	{
		printf("No hay empleados cargados en la lista.\n");
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	FILE* pFile;
	int auxId;
	char auxName[NAME_LEN];
	int auxHours;
	int auxSalary;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)//por cada elemento del array lo escribo en el archivo
			{
				pEmployee = ll_get(pArrayListEmployee, i);
				//utilizo los getter para traerme la info
				if(!employee_getId(pEmployee, &auxId) &&
				   !employee_getNombre(pEmployee, auxName) &&
				   !employee_getHorasTrabajadas(pEmployee, &auxHours) &&
				   !employee_getSueldo(pEmployee, &auxSalary))
				{
					fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxName, auxHours, auxSalary);
				}
			}
			fclose(pFile);
			printf("Archivo guardado!\n");
		}//if fpArchivo NULL
	}//if NULL

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;//error
	FILE* pFile;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
		}
		fclose(pFile);
		retorno = 0;//exito
	}

    return retorno;
}

