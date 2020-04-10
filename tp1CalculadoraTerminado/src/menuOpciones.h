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
 * @brief  Muestra un menu diferente depende de cuantas flags se activen. Llama a las funciones de la libreria operaciones.h
 *
 * @return void
 *
 */
void menu();

/**
 * @brief  Pide un numero y cambia flag1
 *
 * @return void
 *
 */
void opcion1();

/**
 * @brief  Pide un numero y cambia flag2 o muestra error
 *
 * @return void
 *
 */
void opcion2();

/**
 * @brief  Valida que flag1 y flag2 sean 1. Muestra mensaje. Activa flag3.
 *
 * @return void
 *
 */
void opcion3();

/**
 * @brief  Valida que flag1, flag2 y flag3 sean 1. Activa flag4 y cambia el menu.
 *
 * @return void
 *
 */
void opcion4();


#endif /* MENUOPCIONES_H_ */
