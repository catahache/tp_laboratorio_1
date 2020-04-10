/*
 * operaciones.c
 *
 *  Created on: Apr 10, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int suma(int num1, int num2)
{
	int resultadoSuma = num1 + num2;

	return resultadoSuma;

}

int resta(int num1, int num2)
{
	int resultadoResta = num1 - num2;

	return resultadoResta;

}

float division(int num1, int num2)
{

	float resultadoDivision = (float) num1 / num2;

	return resultadoDivision;
}

int multiplicacion(int num1, int num2)
{
	int resultadoMultiplicacion = num1 * num2;

	return resultadoMultiplicacion;
}

long long int factorizacion(int num)
{
	unsigned long long resultadoFact = 0;

		if(num >= 0)//retorna 1 si es 0
		{
			if (num == 1 || num == 0)//suponiendo que fact de 0 es 1
			{
				resultadoFact = 1;
			}
			else
			{
				resultadoFact = num * factorizacion(num - 1);//se llama a si misma
			}
		}


		return resultadoFact;

}
