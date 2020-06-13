#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "menu.h"

#define NAME_LEN 30


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path, "r");


	if(pFile != NULL)
	{
		if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
		{
			printf("Archivo de texto cargado con exito\n");
			retorno = 0;
		}
		else
		{
			printf("Error id\n");
		}
	}
	else
	{
		printf("Error null\n");
	}
	fclose(pFile);
    return retorno;
}


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



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;//exit
	char auxName[NAME_LEN];
	int auxHours;
	int auxSalary;
	int nextId;
	Employee* pEmployee = employee_new();//malloc
	//int auxId;
	//int lastId = 1;

	if(pArrayListEmployee != NULL && pEmployee != NULL)
	{
		if(!utn_getCadena(auxName, NAME_LEN, 2, "Ingrese nombre: ", "Error, nombre invalido") &&
		   !utn_getEntero(&auxHours, 2, "Ingrese cantidad de horas trabajadas: ", "Error, cantidad invalida\n", 0, 100000) &&
		   !utn_getEntero(&auxSalary, 2, "Ingrese salario de 18000 a 30000: ", "Error, salario invalido\n", 18000, 300000))
		{
			normalizeStr(auxName);//normalizo nombre

				nextId = employee_lastId(pArrayListEmployee) + 1;//lo que retorne la funcion + 1

				if(!employee_setId(pEmployee, nextId) &&
				   !employee_setNombre(pEmployee, auxName) &&
				   !employee_setHorasTrabajadas(pEmployee, auxHours) &&
				   !employee_setSueldo(pEmployee, auxSalary))
				{
					ll_add(pArrayListEmployee, pEmployee);
					printf("Alta exitosa\n");
					//printf("%d", nextId);
				}//if setters
				else
				{
					free(pEmployee);
				}
			//}//if nextId
		}//if utn
		else
		{
			free(pEmployee);//libero el espacio
		}
	}//if null
    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int auxId;
	int lastId;
	int retorno = -1;
	int index;
	int confirmOut = 0;

	if(pArrayListEmployee != NULL)
	{
		//funcion choose employee?
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
				printf("\n    ID       Nombre     Horas Trabajadas  Sueldo\n\n");
				employee_printEmployee(pArrayListEmployee, index);//imprimo el empleado elegido

				do
				{
					switch(menuEdit())
					{
						case 1:
							//nombre
							if(changeName(pArrayListEmployee, index) == 0)
							{
								printf("Nombre modificado con exito.\n");
								employee_printEmployee(pArrayListEmployee, index);
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 2:
							//horas
							if(changeHours(pArrayListEmployee, index) == 0)
							{
								printf("Horas trabajadas actualizadas con exito.\n");
								employee_printEmployee(pArrayListEmployee, index);
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 3:
							//Sueldo
							if(changeSalary(pArrayListEmployee, index) == 0)
							{
								printf("Sueldo modificado con exito.\n");
								employee_printEmployee(pArrayListEmployee, index);
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 4:
							confirmOut = 1;
							break;

					}//switch

				}while(confirmOut == 0);
			}//if index
		}//if utn
	}//if null
	return retorno;
}


int controller_removeEmployee( LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int lastId;
	Employee* pEmployee;
	int index;
	char confirmDelete;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);//listo los empleados

		lastId = employee_lastId(pArrayListEmployee);//me devuelve el id mas alto

		if(!utn_getEntero(&auxId, 2, "Ingrese ID de empleado a eliminar del sistema.\n", "Error, ID invalido", 0, lastId))
		{
			index = employee_SearchForId(pArrayListEmployee, auxId);
			if(index > -1)
			{
				pEmployee = ll_get(pArrayListEmployee, index);
				//mostrar el empleado
				printf("\n ID    Nombre   Horas Trabajadas   Sueldo\n\n");
				employee_printEmployee(pArrayListEmployee, index);//imprimo el empleado elegido

				printf("Confirma la baja del empleado? y/n: ");
				scanf("%c", &confirmDelete);
				if(confirmDelete == 'y')
				{
					ll_remove(pArrayListEmployee, index);//elimino el empleado en ese index
					if(employee_delete(pEmployee) == 0) //elimino el punt aux que me cree
					{
						printf("Baja realizada con exito\n");
						retorno = 0;
					}
				}
			}
		}
	}
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		printf("\n    ID       Nombre     Horas Trabajadas  Sueldo\n\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			employee_printEmployee(pArrayListEmployee, i);
		}
	}
	else
	{
		printf("No hay empleados cargados en la lista.\n");
	}

    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		if(employee_sort(pArrayListEmployee) == 0)
		{
			printf("Empleados ordenados exitosamente.\n");
		}
	}
	else
	{
		printf("Error\n");
	}

    return retorno;
}


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
			for(int i = 1; i < ll_len(pArrayListEmployee); i++)//por cada elemento del array lo escribo en el archivo, desde la pos 1
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


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;//error
	FILE* pFile;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 1; i < ll_len(pArrayListEmployee); i++)//desde la pos 1
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
		}
		printf("Archivo guardado!\n");
		fclose(pFile);
		retorno = 0;//exito
	}

    return retorno;
}

