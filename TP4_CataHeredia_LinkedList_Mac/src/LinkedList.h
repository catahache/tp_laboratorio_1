/*
 * LinkedList.h
 *
 *  Created on: 17 jun. 2020
 *      Author: facu
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_

/**
 * @brief 		crea un nuevo LinkedList en memoria de manera dinamica.
 * @return		LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void);

/**
 * @brief 		Retorna la cantidad de elementos de la lista
 * @param 	this LinkedList* Puntero a la lista.
 * @return		Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista.
 */
int ll_len(LinkedList *this);

/** @brief 		Elimina todos los elementos de la lista
 * @param 	this LinkedList* Puntero a la lista
 * @return 		int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                      ( 0) Si funciono correctamente
 */
int ll_clear(LinkedList *this);

/**
 * @brief 		Elimina todos los elementos de la lista y la lista
 * @param 	this LinkedList* Puntero a la lista
 * @return 		int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                      ( 0) Si funciono correctamente
 */
int ll_deleteLinkedList(LinkedList *this);

/** \brief  		Determina si la lista contiene o no el elemento pasado como parametro
 * @param 	this LinkedList* Puntero a la lista
 * @param	 	pElement void* Puntero del elemento a verificar
 *@return 		int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                        ( 1) Si contiene el elemento
 *                       ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement);

#endif /* SRC_LINKEDLIST_H_ */
