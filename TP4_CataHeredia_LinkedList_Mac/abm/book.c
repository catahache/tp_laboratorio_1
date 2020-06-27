#include "book.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "menu.h"
#include "Controller.h"

#define NAMEB_LEN 200 //libro
#define NAME_LEN 128 //autor
#define MIN_PRICE 100
#define MIN_YEAR 1900


Book* book_new()
{
	return (Book*) malloc(sizeof(Book));
}

Book* book_newParametros(char* idStr,char* nameB,char* author, char* price, char* year)
{
	Book* this = NULL;
	this = book_new();

	if(this != NULL && idStr != NULL && nameB != NULL && author != NULL && price != NULL && year != NULL)
	{
		//si estas dan error(-1), no tiene que existir el libro, por eso llamo a delete
		if(book_setId(this, atoi(idStr)) == -1 ||
		   book_setNameB(this, nameB) == -1 ||
		   book_setAuthor(this, author) == -1 ||
		   book_setPrice(this, atof(price)) == -1 ||
		   book_setYear(this, atoi(year)) == -1)
		{
			book_delete(this);
			this = NULL; //libero, el puntero queda apuntando a null
		}
	}
	return this;
}

int book_delete(Book* this)
{
	int retorno = -1;//error
	if(this != NULL)
	{
		free(this);
		this = NULL;
		retorno = 0;//exito
	}
	return retorno;
}


//*****************************************
//************GETTERS Y SETTERS************
//*****************************************


int book_setId(Book* this,int id)//numerico
{
	int retorno = -1;//error

	if(this != NULL && id >= 0)
	{
		this->id = id;//me guarda en el id de this el id que le paso por parametros
		retorno = 0;//exito
	}
	return retorno;
}

int book_getId(Book* this,int* id)
{
	int retorno = -1;//error

	if(this != NULL && id != NULL)
	{
		*id = this->id;//me guarda en el puntero a id lo que hay en this id
		retorno = 0;//exito
	}
	return retorno;
}

int book_setNameB(Book* this,char* nameB)
{
	int retorno = -1;//error

	if(this != NULL && nameB != NULL)
	{
		strncpy(this->nameB, nameB, NAMEB_LEN);
		retorno = 0;//exito
	}
	return retorno;
}

int book_getNameB(Book* this,char* nameB)
{
	int retorno = -1;//error

	if(this != NULL && nameB != NULL)
	{
		strncpy(nameB, this->nameB, NAMEB_LEN);
		retorno = 0;//exito
	}
	return retorno;
}

int book_setAuthor(Book* this,char* author)
{
	int retorno = -1;//error

	if(isValidName(author, NAME_LEN))
	{
		if(this != NULL && author != NULL)
		{
			strncpy(this->author, author, NAME_LEN);
			retorno = 0;//exito
		}
	}

	return retorno;
}

int book_getAuthor(Book* this,char* author)
{
	int retorno = -1;//error

	if(this != NULL && author != NULL)
	{
		strncpy(author, this->author, NAME_LEN);
		retorno = 0;//exito
	}
	return retorno;
}

int book_setPrice(Book* this,float price)
{
	int retorno = -1;//error

	if(this != NULL && price >= MIN_PRICE)
	{
		this->price = price;//guarda en price de this el precio que le paso por parametros
		retorno = 0;//exito
	}
	return retorno;
}

int book_getPrice(Book* this,float* price)
{
	int retorno = -1;//error

	if(this != NULL && price != NULL)
	{
		*price = this->price;//me guarda en el puntero a horasTrabajadas lo que hay en this horasTrabajadas
		retorno = 0;//exito
	}
	return retorno;
}

int book_setYear(Book* this,int year)
{
	int retorno = -1;//error

	if(this != NULL && year >= MIN_YEAR)
	{
		this->year = year;//me guarda en year de this el anio que le paso por parametros
		retorno = 0;//exito
	}
	return retorno;
}

int book_getYear(Book* this,int* year)
{
	int retorno = -1;//error

	if(this != NULL && year != NULL)
	{
		*year = this->year;//me guarda en el puntero a sueldo lo que hay en this sueldo
		retorno = 0;//exito
	}
	return retorno;
}

//*****************************************
//*****************************************
//*****************************************

int book_SearchForId(LinkedList* pArrayListBook, int id)
{
	int retorno = -1;
	int idAux;
	Book* pBook;

	for(int index = 0; index < ll_len(pArrayListBook); index++)
	{
		pBook = ll_get(pArrayListBook, index);

		if(book_getId(pBook, &idAux) == 0 && idAux == id)
		{
			retorno = index;//devuelvo la posicion del libro
		}
	}
	return retorno;
}

int book_printBook(LinkedList* pArrayListBook, int index)
{
	int retorno = -1;
	Book* pBook;
	int auxId, auxYear;
	char auxNameB[NAMEB_LEN];
	char auxAuthor[NAME_LEN];
	float auxPrice;

	if(pArrayListBook != NULL && index >= 0)
	{
		pBook = ll_get(pArrayListBook, index);
		if(book_getId(pBook, &auxId)== 0 &&
		   book_getNameB(pBook, auxNameB) == 0 &&
		   book_getAuthor(pBook, auxAuthor) == 0 &&
		   book_getPrice(pBook, &auxPrice) == 0 &&
		   book_getYear(pBook, &auxYear) == 0)
		{
			printf("%5d    %40s    %20s    %10.2f   %4d\n", auxId, auxNameB, auxAuthor, auxPrice, auxYear);
		}
		else
		{
			printf("Error\n");
		}

	}
	return retorno;
}


//*****************************************
//**************** MODIFY *****************
//*****************************************

int changeNameB(LinkedList* pArrayListBook, int index)
{
	int retorno = -1;
	char newNameB[NAMEB_LEN];
	Book* pBook;

	pBook = ll_get(pArrayListBook, index);

	if(utn_getCadena(newNameB, NAME_LEN, 2, "Ingrese nuevo nombre del libro: ","Error, nombre invalido.\n") == 0)
	{
		book_setNameB(pBook, newNameB);
		retorno = 0;
	}

	return retorno;
}

int changeAuthor(LinkedList* pArrayListBook, int index)
{
	int retorno = -1;
	char newAuthor[NAME_LEN];
	Book* pBook;

	pBook = ll_get(pArrayListBook, index);

	if(utn_getCadena(newAuthor, NAME_LEN, 2, "Ingrese nuevo autor: ","Error, nombre invalido.\n") == 0)
	{
		normalizeStr(newAuthor);
		book_setAuthor(pBook, newAuthor);
		retorno = 0;
	}

	return retorno;
}

int changePrice(LinkedList* pArrayListBook, int index)
{
	int retorno = -1;
	float newPrice;
	Book* pBook;

	pBook = ll_get(pArrayListBook, index);

	if(utn_getFlotante(&newPrice, 2, "Ingrese nuevo precio de 100 a 1500: ", "Error, precio invalido.\n", 100, 1500) == 0)
	{
		book_setPrice(pBook, newPrice);
		retorno = 0;
	}

	return retorno;
}

int changeYear(LinkedList* pArrayListBook, int index)
{
	int retorno = -1;
	int newYear;
	Book* pBook;

	pBook = ll_get(pArrayListBook, index);

	if(utn_getEntero(&newYear, 2, "Ingrese nuevo anio de publicacion de 1900 aa 2020: ", "Error, anio invalido.\n", 1900, 2020) == 0)
	{
		book_setYear(pBook, newYear);
		retorno = 0;
	}

	return retorno;
}

//*****************************************
//*****************************************
//*****************************************



int book_lastId(LinkedList* pArrayListBook)
{
	Book* pBook;
	int len = ll_len(pArrayListBook);
	int auxId;
	int lastId = 0;
	int flag = 0;

	if(pArrayListBook != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			pBook = (Book*) ll_get(pArrayListBook,i);
			book_getId(pBook, &auxId);

			if(auxId > lastId || flag == 0)
			{
				lastId = auxId;
				flag = 1;
			}
		}
	}
	return lastId;
}


int book_sort(LinkedList* pArrayListBook)
{
	int retorno = -1;
	int orden;

	if(pArrayListBook != NULL && ll_isEmpty(pArrayListBook) == 0)
	{
		switch(menuSort())
		{
			case 1:
				//Id
				utn_getEntero(&orden, 2, "1 ascendente o 0 descendente: ", "Error\n", 0, 1);
				printf("Espere unos segundos, por favor.\n");
				ll_sort(pArrayListBook, book_sortById, orden);
				controller_ListBook(pArrayListBook);
				retorno = 0;
				break;
			case 2:
				//NameB
				utn_getEntero(&orden, 2, "1 ascendente o 0 descendente: ", "Error\n", 0, 1);
				printf("Espere unos segundos, por favor.\n");
				ll_sort(pArrayListBook, book_sortByNameB, orden);
				controller_ListBook(pArrayListBook);
				retorno = 0;
				break;
			case 3:
				//Author
				utn_getEntero(&orden, 2, "1 ascendente o 0 descendente: ", "Error\n", 0, 1);
				printf("Espere unos segundos, por favor.\n");
				ll_sort(pArrayListBook, book_sortByAuthor, orden);
				controller_ListBook(pArrayListBook);
				retorno = 0;
				break;
			case 4:
				//Price
				utn_getEntero(&orden, 2, "1 ascendente o 0 descendente: ", "Error\n", 0, 1);
				printf("Espere unos segundos, por favor.\n");
				ll_sort(pArrayListBook, book_sortByPrice, orden);
				controller_ListBook(pArrayListBook);
				retorno = 0;
				break;
			case 5:
				//Year
				utn_getEntero(&orden, 2, "1 ascendente o 0 descendente: ", "Error\n", 0, 1);
				printf("Espere unos segundos, por favor.\n");
				ll_sort(pArrayListBook, book_sortByYear, orden);
				controller_ListBook(pArrayListBook);
				retorno = 0;
				break;
			case 6:
				break;
			default:
				printf("No es una opcion valida\n");
				break;
		}
	}
	return retorno;
}

int book_sortById(void* firstBook, void* secondBook)
{
	int retorno = 0;//si son iguales
	int firstId;
	int secondId;

	book_getId(firstBook, &firstId);
	book_getId(secondBook, &secondId);

	if(firstId > secondId)
	{
		retorno = 1;
	}
	else if(firstId < secondId)
	{
		retorno = -1;
	}

	return retorno;
}

int book_sortByNameB(void* firstBook, void* secondBook)
{
	int retorno = 0;//si son iguales
	char firstNameB[NAMEB_LEN];
	char secondNameB[NAMEB_LEN];

	book_getNameB(firstBook, firstNameB);
	book_getNameB(secondBook, secondNameB);

	if(strcmp(firstNameB, secondNameB) > 0)//el primero es mayor
	{
		retorno = 1;
	}
	else if(strcmp(firstNameB, secondNameB) < 0)// el primero es menor
	{
		retorno = -1;
	}

	return retorno;
}

int book_sortByAuthor(void* firstBook, void* secondBook)
{
	int retorno = 0;//si son iguales
	char firstAuthor[NAME_LEN];
	char secondAuthor[NAME_LEN];

	book_getAuthor(firstBook, firstAuthor);
	book_getAuthor(secondBook, secondAuthor);

	if(strcmp(firstAuthor, secondAuthor) > 0)//el primero es mayor
	{
		retorno = 1;
	}
	else if(strcmp(firstAuthor, secondAuthor) < 0)// el primero es menor
	{
		retorno = -1;
	}

	return retorno;
}

int book_sortByPrice(void* firstBook, void* secondBook)
{
	int retorno = 0;//si son iguales
	float firstPrice;
	float secondPrice;

	book_getPrice(firstBook, &firstPrice);
	book_getPrice(secondBook, &secondPrice);

	if(firstPrice > secondPrice)
	{
		retorno = 1;
	}
	else if(firstPrice < secondPrice)
	{
		retorno = -1;
	}

	return retorno;
}

int book_sortByYear(void* firstBook, void* secondBook)
{
	int retorno = 0;//si son iguales
	int firstYear;
	int secondYear;

	book_getYear(firstBook, &firstYear);
	book_getYear(secondBook, &secondYear);

	if(firstYear > secondYear)
	{
		retorno = 1;
	}
	else if(firstYear < secondYear)
	{
		retorno = -1;
	}

	return retorno;
}
