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

//variables:
//int opcion;
int num1;
int num2;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
int resulSuma;
int resulResta;
int resulMultiplicacion;
float resulDivision;
long long int factorizacion1;
long long int factorizacion2;

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

//Funcion que muestra un menu diferente depende de como esten las banderas cambiadas por cada opcion
void menu()//
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
		printf("	a) El resultado de %d+%d es: %d \n", num1, num2, resulSuma);
		printf("	b) El resultado de %d-%d es: %d \n", num1, num2, resulResta);
		//validar division
		if(num2 == 0)
		{
			printf("	d) El resultado de %d/%d es: No se puede dividir por 0 \n", num1, num2);
		}
		else
		{
			printf("	d) El resultado de %d/%d es: %.2f \n", num1, num2, resulDivision);
		}

		printf("	d) El resultado de %d*%d es: %d \n", num1, num2, resulMultiplicacion);
		printf("	e) El factorial de %d es: %lld y El factorial de %d es: %lld \n", num1, factorizacion1, num2, factorizacion2);
		printf("5. Salir \n\n");
	}


}

//Funciones para cada opcion elegida:
void opcion1()
{
	//FALTA VALIDAR QUE NO INGRESE LETRAS
	printf("Ingrese el primer operando: ");
	scanf("%d", &num1);
	flag1 = 1; //ingreso el 1

}

void opcion2()
{
	//FALTA VALIDAR QUE NO INGRESE LETRAS
	if(flag1 == 0)
	{
		printf("Error. Falta ingresar el primer operando. \n");
		pause();
	}
	else
	{
		printf("Ingrese el segundo operando: ");
		scanf("%d", &num2);
		flag2 = 1; // ingreso el 2
	}

}

void opcion3()
{
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
	else if(flag1 == 1 && flag2 == 1)
	{
		flag3 = 1;
		resulSuma = suma(num1, num2);
		resulResta = resta(num1, num2);
		resulDivision = division(num1, num2);
		resulMultiplicacion = multiplicacion(num1, num2);
		factorizacion1 = factorizacion(num1);
		factorizacion2 = factorizacion(num2);
		printf("Calculando...");
		pause();
	}

}

void opcion4()
{

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
	else if(flag3 == 1)
	{
		flag4 = 1;
		printf("Enter para ver los resultados: \n");
		pause();
	}
}
