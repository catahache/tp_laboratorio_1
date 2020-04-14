/*
 * operaciones.c
 *
 *  Created on: Apr 10, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int sumar(int num1, int num2, int* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = num1 + num2;
		retorno = 0;
	}


	return retorno;

}

int restar(int num1, int num2, int* pResultado)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = num1 - num2;
		retorno = 0;
	}

	return retorno;
}

float dividir(int num1, int num2, float* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = (float) num1 / num2;
		retorno = 0;
	}

	return retorno;
}

int multiplicar(int num1, int num2, int* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = num1 * num2;
		retorno = 0;
	}

	return retorno;
}

long long int factorizar(int num, long long int* pResultado) //ver si funciona...
{
	int retorno = -1;
	unsigned long long resultado = 0;

	if(pResultado != NULL)
	{
		if(num >= 0)//retorna 1 si es 0
		{
			if (num == 1 || num == 0)//suponiendo que fact de 0 es 1
			{
				resultado = 1;
				*pResultado = resultado;
			}
			else
			{
				resultado = num * factorizar(num - 1, &resultado);//se llama a si misma
				*pResultado = resultado;
			}
		}
		retorno = 0; //exito
	}



		return retorno;

}
