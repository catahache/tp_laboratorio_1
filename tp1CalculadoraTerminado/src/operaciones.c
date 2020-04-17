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


unsigned long long factorial (int num)
{
	unsigned fact = 0;

	if(num >= 0)//retorna 1 si es 0
	{
		if (num == 1 || num == 0)// fact de 0 es 1 segun algunos
		{
			fact = 1;
		}
		else
		{
			fact = num * factorial(num - 1);//se llama a si misma
		}
	}

	return fact;
}
