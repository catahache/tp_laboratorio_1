#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "book.h"


int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook)
{
	int retorno = -1;//error
	Book* pBook;
	char id[200];
	char nameB[200];
	char author[200];
	char price[200];
	char year[200];
	int nextId = 0;

	if(pFile != NULL && pArrayListBook != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nameB, author, price, year);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nameB, author, price, year) == 5)
			{
				//imprime mientras fscanf devuelva 5
				pBook = book_newParametros(id, nameB, author, price, year);

				if(pBook != NULL)//osea si pudo cargar
				{
					ll_add(pArrayListBook, pBook);
					retorno = 0;//exito
				}
			}
			else
			{
				break;//salgo de do while
			}

		}while(feof(pFile) == 0); //lee todo el archivo
		retorno = nextId;//retorno el nextId como exito.
	}

    return retorno;
}


int parser_BookFromBinary(FILE* pFile , LinkedList* pArrayListBook)
{
	int retorno = -1;
	Book* pBook;

	if(pFile != NULL)
	{
		do
		{
			pBook = book_new(); //reservo lugar para un libro
			if(fread(pBook, sizeof(Book), 1, pFile) == 1) //leo datos binarios y valido si me leyo 1
			{
				ll_add(pArrayListBook, pBook);
				retorno = 0;//exito
			}
		}while(!feof(pFile));//mientras no sea el final del archivo
	}

    return retorno;
}
