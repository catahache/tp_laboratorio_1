/*
 * menuOpciones.c
 *
 *  Created on: Apr 10, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include "menuOpciones.h"
#include "operaciones.h"

//Funcion para pausar:
void pause()
{

	char tmp;
	fpurge(stdin);

	do{
		tmp = getchar();
	} while( tmp != '\n' && tmp != EOF);

	return;
}

void menu(int num1, int num2, int flag1, int flag2, int flag3, int flag4, int suma, int resta, int multi, float divi, long long int fact1, long long int fact2)
{

	if(flag1 == 1 && flag2 == 1 && flag3 ==0 && flag4 == 0)
	{
		printf("...MENU DE OPCIONES...\n\n");
		printf("1. Ingresar 1er operando (A=%d) \n", num1);
		printf("2. Ingresar 2do operando (B=%d) \n", num2);
		printf("3. Calcular todas las operaciones \n");
		printf("	a) Calcular la suma (%d+%d) \n", num1, num2);
		printf("	b) Calcular la resta (%d-%d) \n", num1, num2);
		printf("	c) Calcular la division(%d/%d) \n", num1, num2);
		printf("	d) Calcular la multiplicacion (%d*%d) \n", num1, num2);
		printf("	e) Calcular el factorial (%d!) y (%d!) \n", num1, num2);
		printf("4. Informar resultados \n");
		printf("	a) El resultado de %d+%d es: r \n", num1, num2);
		printf("	b) El resultado de %d-%d es: r \n", num1, num2);
		printf("	d) El resultado de %d/%d es: r \n", num1, num2);
		printf("	d) El resultado de %d*%d es: r \n", num1, num2);
		printf("	e) El factorial de %d es: r y El factorial de %d es: r \n", num1, num2);
		printf("5. Salir \n\n");

	}
	else if(flag1 == 1 && flag2==0)//Se ha cargado solo el 1er op
	{
		printf("...MENU DE OPCIONES...\n\n");
		printf("1. Ingresar 1er operando (A=%d) \n", num1);
		printf("2. Ingresar 2do operando (B=Y) \n");
		printf("3. Calcular todas las operaciones \n");
		printf("	a) Calcular la suma (%d+B) \n", num1);
		printf("	b) Calcular la resta (%d-B) \n", num1);
		printf("	c) Calcular la division(%d/B) \n", num1);
		printf("	d) Calcular la multiplicacion (%d*B) \n", num1);
		printf("	e) Calcular el factorial (%d!) y (B!) \n", num1);
		printf("4. Informar resultados \n");
		printf("	a) El resultado de %d+B es: r \n", num1);
		printf("	b) El resultado de %d-B es: r \n", num1);
		printf("	d) El resultado de %d/B es: r \n", num1);
		printf("	d) El resultado de %d*B es: r \n", num1);
		printf("	e) El factorial de %d es: r y El factorial de B es: r \n", num1);
		printf("5. Salir \n\n");
	}
	else if(flag1 == 0 && flag2 == 0)//El primero que aparece
	{
		printf("...MENU DE OPCIONES...\n\n");
		printf("1. Ingresar 1er operando (A=X) \n");
		printf("2. Ingresar 2do operando (B=Y) \n");
		printf("3. Calcular todas las operaciones \n");
		printf("	a) Calcular la suma (A+B) \n");
		printf("	b) Calcular la resta (A-B) \n");
		printf("	c) Calcular la division(A/B) \n");
		printf("	d) Calcular la multiplicacion (A*B) \n");
		printf("	e) Calcular el factorial (A!) y (B!) \n");
		printf("4. Informar resultados \n");
		printf("	a) El resultado de A+B es: r \n");
		printf("	b) El resultado de A-B es: r \n");
		printf("	d) El resultado de A/B es: r \n");
		printf("	d) El resultado de A*B es: r \n");
		printf("	e) El factorial de A es: r y El factorial de B es: r \n");
		printf("5. Salir \n\n");

	}
	else if(flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 0)
	{
		printf("...MENU DE OPCIONES...\n\n");
		printf("1. Ingresar 1er operando (A=%d) \n", num1);
		printf("2. Ingresar 2do operando (B=%d) \n", num2);
		printf("3. Calcular todas las operaciones \n");
		printf("	a) Calcular la suma (%d+%d) \n", num1, num2);
		printf("	b) Calcular la resta (%d-%d) \n", num1, num2);
		printf("	c) Calcular la division(%d/%d) \n", num1, num2);
		printf("	d) Calcular la multiplicacion (%d*%d) \n", num1, num2);
		printf("	e) Calcular el factorial (%d!) y (%d!) \n", num1, num2);
		printf("4. Informar resultados \n");
		printf("	a) El resultado de %d+%d es: r \n", num1, num2);
		printf("	b) El resultado de %d-%d es: r \n", num1, num2);
		printf("	d) El resultado de %d/%d es: r \n", num1, num2);
		printf("	d) El resultado de %d*%d es: r \n", num1, num2);
		printf("	e) El factorial de %d es: r y El factorial de %d es: r \n", num1, num2);
		printf("5. Salir \n\n");
	}
	else if(flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 1)
	{
		printf("FUNCA BIEN SOLO CAMBIAR LOS RESULTADOS\n\n");
		printf("...MENU DE OPCIONES...\n\n");
		printf("1. Ingresar 1er operando (A=%d) \n", num1);
		printf("2. Ingresar 2do operando (B=%d) \n", num2);
		printf("3. Calcular todas las operaciones \n");
		printf("	a) Calcular la suma (%d+%d) \n", num1, num2);
		printf("	b) Calcular la resta (%d-%d) \n", num1, num2);
		printf("	c) Calcular la division(%d/%d) \n", num1, num2);
		printf("	d) Calcular la multiplicacion (%d*%d) \n", num1, num2);
		printf("	e) Calcular el factorial (%d!) y (%d!) \n", num1, num2);
		printf("4. Informar resultados \n");
		printf("	a) El resultado de %d+%d es: %d \n", num1, num2, suma);
		printf("	b) El resultado de %d-%d es: %d \n", num1, num2, resta);
		//validar division
		if(num2 == 0)
		{
			printf("	d) El resultado de %d/%d es: No se puede dividir por 0 \n", num1, num2);
		}
		else
		{
			printf("	d) El resultado de %d/%d es: %.2f \n", num1, num2, divi);
		}

		printf("	d) El resultado de %d*%d es: %d \n", num1, num2, multi);
		printf("	e) El factorial de %d es: %lld y El factorial de %d es: %lld \n", num1, fact1, num2, fact2);
		printf("5. Salir \n\n");
	}

}

int opcion1(int* pFlag1, int* pNum1)
{
	int numero1;
	int flag1;
	int retorno = -1;

	if(pFlag1 != NULL && pNum1 != NULL)
	{
		printf("Ingrese el primer operando: ");
		scanf("%d", &numero1);

		*pNum1 = numero1; //le paso el valor del numero ingresado
		flag1 = 1;
		*pFlag1 = flag1; //le paso el valor de la bandera cambiada
		retorno = 0; //exito
	}
	return retorno;

}

int opcion2(int flag1, int* pFlag2, int* pNum2)
{
	int numero2;
	int flag2;
	int retorno = -1;

	if(pFlag2 != NULL && pNum2 != NULL)
	{
		if(flag1 == 0)
		{
			printf("Error. Falta ingresar el primer operando. \n");
			pause();
		}
		else
		{
			printf("Ingrese el segundo operando: ");
			scanf("%d", &numero2);
			*pNum2 = numero2;
			flag2 = 1; // ingreso el 2
			*pFlag2 = flag2;
			retorno = 0; //exito
		}
	}

	return retorno;

}

int opcion3(int flag1, int flag2, int* pFlag3, int numero1, int numero2, int* pSuma, int* pResta, int* pMulti, float* pDivi, long long int* pFact1, long long int* pFact2)
{
	int flag3;
	int retorno = -1;
	int resultadoSuma; //en esta var se cargara el valor que le otorgue la funcion sumar
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	long long int resultadoFact1;
	long long int resultadoFact2;


	if(flag1 == 0)
	{
		printf("Error. Falta ingresar los operandos. \n");
		pause();
	}
	else if(flag1 == 1 && flag2 == 0)
	{
		printf("Error. Falta ingresar el segundo operando. \n");
		pause();
	}
	else if(flag1 == 1 && flag2 == 1 && pFlag3 != NULL)
	{
		flag3 = 1;
		*pFlag3 = flag3; //le paso al puntero el valor de flag3

		//llamar a todas las operaciones pero no mostrar resultados:
		sumar(numero1, numero2, &resultadoSuma);
		*pSuma = resultadoSuma;

		restar(numero1, numero2, &resultadoResta);
		*pResta = resultadoResta;

		dividir(numero1, numero2, &resultadoDivision);
		*pDivi = resultadoDivision;

		multiplicar(numero1, numero2, &resultadoMultiplicacion);
		*pMulti = resultadoMultiplicacion;

		factorizar(numero1, &resultadoFact1);
		*pFact1 = resultadoFact1;

		factorizar(numero2, &resultadoFact2);
		*pFact2 = resultadoFact2;

		printf("Calculando...");
		pause();

		retorno = 0; //exito
	}
	return retorno;
}

int opcion4(int flag1, int flag2, int flag3, int* pFlag4)
{
	int flag4;
	int retorno = -1;

	if(flag1 == 0)
	{
		printf("Error. Falta ingresar los operandos. \n");
		pause();
	}
	else if(flag1 == 1 && flag2 == 0)
	{
		printf("Error. Falta ingresar el segundo operando. \n");
		pause();
	}
	else if(flag3 == 0)
	{
		printf("Error. Falta calcular primero.");
		pause();
	}
	else if(flag3 == 1 && pFlag4 != NULL)
	{
		flag4 = 1;
		*pFlag4 = flag4;
		printf("Enter para ver los resultados: \n");
		pause();
		retorno = 0; //exito
	}

	return retorno;
}
