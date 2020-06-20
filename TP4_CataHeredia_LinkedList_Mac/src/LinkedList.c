#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void) //la inicializo en 0
{
    LinkedList* this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));

	if (this != NULL)
	{
		this->size = 0;
		this->pFirstNode = NULL;
	}

    return this;
}

int ll_len(LinkedList *this)
{
	int isOk = -1;

	if (this != NULL)
	{
		isOk = this->size;
	}
	return isOk;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodeAux = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		//inicializo mi puntero a nodo y lo igualo al primer nodo de this
		pNodeAux = this->pFirstNode; //0

		for(int i = 0; i < nodeIndex; i++)
		{
			pNodeAux = pNodeAux->pNextNode;
		}
	}
    return pNodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int isOk = -1;

    Node* newNode;
    Node* prevNode;

    //si el index es = a 0 que el nuevo nodo.nextNode = this.primernodo
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	newNode = (Node*) malloc(sizeof(Node));

    	newNode->pElement = pElement;
    	newNode->pNextNode = NULL;

    	if(nodeIndex == 0)
    	{
    		newNode->pNextNode = this->pFirstNode;//le paso la dir de memo del 1er elemento
    		this->pFirstNode = newNode;//el nuevo first node sera el que cree
    	}
    	else
    	{
    		prevNode = getNode(this, nodeIndex - 1);//consigo la ubicacion del nodo previo al que creo
    		newNode->pNextNode = NULL;//prevNode->pNextNode;//el siguiente sera al que apuntaba el ultimo
    		prevNode->pNextNode = newNode;//le paso al nodo previo la dir del nuevo nodo, al que apuntara
    	}

    	this->size++; //le incremento el campo size a la lista
    	isOk = 0;
    }


    return isOk;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int isOk = -1;

    if(this != NULL)
    {
    	isOk = addNode(this, ll_len(this), pElement);
    }

    return isOk;
}

/** \brief Retorna un puntero al elemento que se encuentra en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* pElement = NULL;
    Node* pNodeAux;

    if(this != NULL && index < ll_len(this) && index >= 0)
    {
    	pNodeAux = getNode(this, index);
    	pElement = pNodeAux->pElement;
    }
    else
    {
    	pElement = NULL;
    }
    return pElement;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int isOk = -1;
    Node* pNodeAux;

    if(this != NULL && index < ll_len(this) && index >= 0)
    {
    	pNodeAux = getNode(this, index);

    	if(pNodeAux != NULL)
    	{
    		pNodeAux->pElement = pElement;
    		isOk = 0;
    	}
    }

    return isOk;
}


/** \brief Elimina un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int isOk = -1;
    Node* pNodeAux;
    Node* pPrevNode;
    Node* pNextNode;

    if(this != NULL && index < ll_len(this) && index >= 0)
    {
    	pNodeAux = getNode(this, index); //dir memo
    	pNextNode = getNode(this, index + 1); //dir memo nodo siguiente al actual

    	if(index == 0)
    	{
    		this->pFirstNode = pNextNode; //nodo siguiente al actual
    	}
    	else
    	{
    		pPrevNode = getNode(this, index - 1);
    		pPrevNode->pNextNode = pNextNode;
    	}

    	free(pNodeAux);
    	this->size--;
    	isOk = 0;
    }

    return isOk;
}

/** \brief Borra todos los elementos de LinkedList.
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_clear(LinkedList *this)
{
	int isOk = -1;

	if(this != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			ll_remove(this, i);
		}

		if(ll_len(this) == 0)
		{
			isOk = 0;
		}
	}
	return isOk;
}

/** \brief Elimina el LinkedList.
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this)
{
    int isOk = -1;

	if (this != NULL && ll_clear(this) == 0)
	{
		free(this);
		isOk = 0;
	}
    return isOk;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int indexNode = -1;

    if(this != NULL)
    {
    	for(int i = 0; i < ll_len(this); i++)
    	{

    	}
    }

    return indexNode;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


int ll_contains(LinkedList *this, void *pElement) {
    int returnAux = -1;

	if (this != NULL) {
		if (ll_indexOf(this, pElement) != -1) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

