#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn.h"

#define NAME_LEN 30


/*
  	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
*/


Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = NULL;
	this = employee_new();

	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
	{
		//si estas estan mal(-1), no tiene que existir el empleado, por eso llamo a delete
		if(employee_setId(this, atoi(idStr)) == -1 ||
		   employee_setNombre(this, nombreStr) == -1 ||
		   employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) == -1 ||
		   employee_setSueldo(this, atoi(sueldoStr)) == -1)
		{
			employee_delete(this);
			this = NULL; //libero, el puntero queda apuntando a null
		}
	}
	return this;
}

int employee_delete(Employee* this)
{
	int retorno = -1;//error
	if(this != NULL)
	{
		free(this);
		retorno = 0;//exito
	}
	return retorno;
}

int employee_setId(Employee* this,int id)//numerico
{
	int retorno = -1;//error

	if(this != NULL && id >= 0)
	{
		this->id = id;//me guarda en el id de this el id que le paso por parametros
		retorno = 0;//exito
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;//error

	if(this != NULL && id != NULL)
	{
		*id = this->id;//me guarda en el puntero a id lo que hay en this id
		retorno = 0;//exito
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;//error

	if(this != NULL && nombre != NULL)
	{
		if(isValidName(nombre, NAME_LEN))//verifico que este bien con isValidName de utn.h
		{
			strncpy(this->nombre, nombre, NAME_LEN);
			retorno = 0;//exito
		}
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;//error

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, NAME_LEN);
		retorno = 0;//exito
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;//error

	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;//me guarda en horasTrabajadas de this las horas que le paso por parametros
		retorno = 0;//exito
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;//error

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;//me guarda en el puntero a horasTrabajadas lo que hay en this horasTrabajadas
		retorno = 0;//exito
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;//error

	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;//me guarda en sueldo de this el sueldo que le paso por parametros
		retorno = 0;//exito
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;//error

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;//me guarda en el puntero a sueldo lo que hay en this sueldo
		retorno = 0;//exito
	}
	return retorno;
}

int employee_SearchForId(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int idAux;
	Employee* pEmployee;

	for(int index = 0; index < ll_len(pArrayListEmployee); index++)
	{
		pEmployee = ll_get(pArrayListEmployee, index);

		if(employee_getId(pEmployee, &idAux) == 0 &&
		   idAux == id)
		{
			retorno = index;//devuelvo la posicion del empleado
		}
	}
	return retorno;
}

int employee_printEmployee(LinkedList* pArrayListEmployee, int index)
{
	int retorno = -1;
	Employee* pEmployee;
	int auxId, auxHours, auxSalary;
	char auxName[NAME_LEN];

	if(pArrayListEmployee != NULL && index >= 0)
	{
		pEmployee = ll_get(pArrayListEmployee, index);
		if(!employee_getId(pEmployee, &auxId) &&
		   !employee_getNombre(pEmployee, auxName) &&
		   !employee_getHorasTrabajadas(pEmployee, &auxHours) &&
		   !employee_getSueldo(pEmployee, &auxSalary))
		{
			printf("%10d    %10s    %10d    %10d\n", auxId, auxName, auxHours, auxSalary);
		}
		else
		{
			printf("Error\n");
		}

	}
	return retorno;

}
