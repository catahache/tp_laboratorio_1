/*
 * operaciones.h
 *
 *  Created on: Apr 10, 2020
 *      Author: catalina
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/**
 * @brief  suma dos numeros enteros
 *
 * @param  num1 primer numero a sumar
 * @param  num2 segundo numero a sumar
 * @param  puntero al resultado
 * @return 0 si la funcion se concreto con exito, de lo contrario -1
 *
 */
int sumar(int num1, int num2, int* pResultado);

/**
 * @brief  resta dos numeros enteros
 *
 * @param  num1 primer numero a restar
 * @param  num1 segundo numero a restar
 * @param  puntero al resultado
 * @return 0 si la funcion se concreto con exito, de lo contrario -1
 *
 */
int restar(int num1, int num2, int* pResultado);

/**
 * @brief  divide dos numeros enteros
 *
 * @param  num1 primer numero a dividir
 * @param  num2 segundo numero a dividir
 * @param  puntero al resultado
 * @return 0 si la funcion se concreto con exito, de lo contrario -1
 *
 */
float dividir(int num1, int num2, float* pResultado);

/**
 * @brief  multiplica dos numeros enteros
 *
 * @param  num1 primer numero a multiplicar
 * @param  num2 segundo numero a multiplicar
 * @param  puntero al resultado
 * @return 0 si la funcion se concreto con exito, de lo contrario -1
 *
 */
int multiplicar(int num1, int num2, int* pResultado);

/**
 * @brief  Realiza el factorial de un numero
 *
 * @param  num es el numero a factorizar
 * @param  puntero al resultado
 * @return 0 si la funcion se concreto con exito, de lo contrario -1
 *
 */
long long int factorizar(int num, long long int* pResultado);

#endif /* OPERACIONES_H_ */
