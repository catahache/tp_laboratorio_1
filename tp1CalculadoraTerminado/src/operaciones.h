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
 * @return la suma entre num1 y num1
 *
 */
int sumar(int num1, int num2, int* pResultado);

/**
 * @brief  resta dos numeros enteros
 *
 * @param  num1 primer numero a restar
 * @param  num1 segundo numero a restar
 * @param  puntero al resultado
 * @return la resta entre a y b
 *
 */
int restar(int num1, int num2, int* pResultado);

/**
 * @brief  divide dos numeros enteros
 *
 * @param  num1 primer numero a dividir
 * @param  num2 segundo numero a dividir
 * @param  puntero al resultado
 * @return la division entre a y b
 *
 */
float dividir(int num1, int num2, float* pResultado);

/**
 * @brief  multiplica dos numeros enteros
 *
 * @param  num1 primer numero a multiplicar
 * @param  num2 segundo numero a multiplicar
 * @param  puntero al resultado
 * @return la multiplicacion entre a y b
 *
 */
int multiplicar(int num1, int num2, int* pResultado);

/**
 * @brief  Realiza el factorial de un numero
 *
 * @param  num es el numero a factorizar
 * @param  puntero al resultado
 * @return el factorial de num
 *
 */
long long int factorizar(int num, long long int* pResultado);

#endif /* OPERACIONES_H_ */
