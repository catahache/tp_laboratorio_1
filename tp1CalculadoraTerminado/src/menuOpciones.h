/*
 * menuOpciones.h
 *
 *  Created on: Apr 10, 2020
 *      Author: catalina
 */

#ifndef MENUOPCIONES_H_
#define MENUOPCIONES_H_


/**
 * @brief  Pausa el printf anterior.
 *
 * @return void
 *
 */
void pause();

/**
 *@brief  Muestra un menu diferente depende de cuantas flags se activen.
 *
 *@param numero 1
 *@param numero 2
 *@param bandera de la opcion 1
 *@param bandera de la opcion 2
 *@param bandera de la opcion 3
 *@param bandera de la opcion 4
 *@param resultado de la suma
 *@param resultado de la resta
 *@param resultado de la multiplicacion
 *@param resultado de la division
 *@param resultado de la primera factorizacion
 *@param resultado de la segunda factorizacion
 *
 *@return void
 *
 */
void menu(int num1, int num2, int flag1, int flag2, int flag3, int flag4, int suma, int resta, int multi, float divi, long long int fact1, long long int fact2);


/**
 *@brief  Pide un numero y cambia flag1
 *
 *@param puntero a la bandera de la opcion1
 *@param puntero al numero 1
 *
 *@return 0 si la funcion se realiza con exito, o -1 si no lo hace
 *
 */
int opcion1(int* pFlag1, int* pNum1);

/**
 *@brief  Pide un numero y cambia flag2
 *
 *@param bandera opcion 1
 *@param puntero a la bandera de la opcion2
 *@param puntero al numero 2
 *
 *@return 0 si la funcion se realiza con exito, o -1 si no lo hace
 *
 */
int opcion2(int flag1, int* pFlag2, int* pNum2);

/**
 *@brief  Llama a las funciones de operaciones.h y cambia la flag3
 *
 *@param bandera opcion 1
 *@param badera opcion 2
 *@param puntero a la bandera de la opcion 3
 *@param numero 1
 *@param numero 2
 *@param puntero a la var suma
 *@param puntero a la var resta
 *@param puntero a la var multiplicacion
 *@param puntero a la var division
 *@param puntero a la var factorizacion del num 1
 *@param puntero a la var factorizacion del num 2
 *
 *@return 0 si la funcion se realiza con exito, o -1 si no lo hace
 *
 */
int opcion3(int flag1, int flag2, int* pFlag3, int numero1, int numero2, int* pSuma, int* pResta, int* pMulti, float* pDivi, long long int* pFact1, long long int* pFact2);

/**
 *@brief  Cambia la flag4 para que en el menu se muestren los resultados
 *
 *@param bandera opcion 1
 *@param bandera de la opcion2
 *@param bandera de la opcion2
 *@param puntero a la bandera de la opcion4
 *
 *@return 0 si la funcion se realiza con exito, o -1 si no lo hace
 *
 */
int opcion4(int flag1, int flag2, int flag3, int* pFlag4);


#endif /* MENUOPCIONES_H_ */
