/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
/**
 * \brief Crea y retorna un nuevo LinkedList.
 * \return Puntero a LinkedList
 */
LinkedList* ll_newLinkedList(void);

/**
 * \brief Retorna el tamaño del LinkedList.
 * \param this: Puntero a la LinkedList
 * \return Si la verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.
 */
int ll_len(LinkedList* this);

/**
 * \brief Retorna un puntero al nodo que se encuentra en el índice especificado.
 * \param this: Puntero a la LinkedList
 * \param nodeIndex: indice.
 * \return Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el puntero al nodo.
 */
Node* test_getNode(LinkedList* this, int nodeIndex);


int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/**
 * \brief Agrega un elemento al final de LinkedList.
 * \param this: Puntero a la LinkedList
 * \param pElement: puntero al elemento
 * \return Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 */
int ll_add(LinkedList* this, void* pElement);

/**
 * \brief Retorna un puntero al elemento que se encuentra en el índice especificado.
 * \param this: Puntero a la LinkedList
 * \param index: indice
 * \return Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 */
void* ll_get(LinkedList* this, int index);//me devuelve un puntero a la dir de memo de un empleado si casteo

/**
 * \brief Inserta un elemento en el LinkedList, en el índice especificado.
 * \param this: Puntero a la LinkedList
 * \param index: indice
 * \param pElement: puntero al elemento
 * \return Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 */
int ll_set(LinkedList* this, int index,void* pElement);

/**
 * \brief Elimina un elemento del LinkedList, en el índice especificado.
 * \param this: Puntero a la LinkedList
 * \param index: indice
 * \return Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 */
int ll_remove(LinkedList* this,int index);

/**
 * \brief Borra todos los elementos de LinkedList.
 * \param this: Puntero a la LinkedList
 * \return Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 */
int ll_clear(LinkedList* this);

/**
 * \brief Elimina el LinkedList.
 * \param this: Puntero a la LinkedList
 * \return Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).
 */
int ll_deleteLinkedList(LinkedList* this);

/**
 * \brief Retorna el índice de la primera aparición de un elemento (element) en el LinkedList.
 * \param this: Puntero a la LinkedList
 * \param pElement: puntero al elemento
 * \return Si la verificación falla o no encuentra el elemento la función retorna (-1) y si encuentra el elemento retorna su índice.
 */
int ll_indexOf(LinkedList* this, void* pElement);

/**
 * \brief Retorna cero si contiene elementos y uno si no los tiene.
 * \param this: Puntero a la LinkedList
 * \return Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).
 */
int ll_isEmpty(LinkedList* this);

/**
 * \brief Desplaza los elementos e inserta en la posición index.
 * \param this: Puntero a la LinkedList
 * \param index: indice
 * \param pElement: puntero al elemento
 * \return Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 */
int ll_push(LinkedList* this, int index, void* pElement);

/**
 * \brief Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina de la lista.
 * \param this: Puntero a la LinkedList
 * \param index: indice
 * \return Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 */
void* ll_pop(LinkedList* this,int index);

/**
 * \brief Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el puntero this sea distintos de NULL.
 * \param this: Puntero a la LinkedList
 * \param pElement: puntero al elemento
 * \return Si la verificación falla la función retorna (-1) , si encuentra el elemento (1) y si no lo encuentra (0).
 */
int ll_contains(LinkedList* this, void* pElement);

/**
 * \brief Comprueba si los elementos pasados son contenidos por el LinkedList.
 * \param this: Primer elemento
 * \param this2: Segundo elemento
 * \return Si la verificación falla o no encuentra el elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna (1).
 */
int ll_containsAll(LinkedList* this,LinkedList* this2);

/**
 * \brief Retorna un nuevo LinkedList con el subconjunto de elementos.
 * \param this: Primer elemento
 * \param from: desde donde
 * \param to: hasta donde
 * \return Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo array.
 */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/**
 * \brief Retorna un nuevo LinkedList copia del LinkedList original.
 * \param this: Puntero a la LinkedList
 * \return Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo array.
 */
LinkedList* ll_clone(LinkedList* this);

/**
 * \brief Ordena los elementos del array
 * \param this: Puntero a la LinkedList
 * \param (*pFunc): función que sera la encargada de determinar que elemento es mas grande que otro
 * \param orden: 1 asencente, 0 descendente
 * \return Verificando que tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
