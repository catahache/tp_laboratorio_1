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
 * @return la suma entre num1 y num1
 *
 */
int suma(int num1, int num2);

/**
 * @brief  resta dos numeros enteros
 *
 * @param  num1 primer numero a restar
 * @param  num1 segundo numero a restar
 * @return la resta entre a y b
 *
 */
int resta(int num1, int num2);

/**
 * @brief  divide dos numeros enteros
 *
 * @param  num1 primer numero a dividir
 * @param  num2 segundo numero a dividir
 * @return la division entre a y b
 *
 */
float division(int num1, int num2);

/**
 * @brief  multiplica dos numeros enteros
 *
 * @param  num1 primer numero a multiplicar
 * @param  num2 segundo numero a multiplicar
 * @return la multiplicacion entre a y b
 *
 */
int multiplicacion(int num1, int num2);

/**
 * @brief  Realiza el factorial de un numero
 *
 * @param  num es el numero a factorizar
 *
 * @return el factorial de num
 *
 */
long long int factorizacion(int num);

#endif /* OPERACIONES_H_ */
