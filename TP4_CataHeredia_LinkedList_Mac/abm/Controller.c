#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

#include "book.h"
#include "menu.h"

#define NAMEB_LEN 200
#define NAME_LEN 128


int controller_loadFromText(char* path , LinkedList* pArrayListBook)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		if(parser_BookFromText(pFile, pArrayListBook) == 0)
		{
			printf("Archivo de texto cargado con exito\n");
			retorno = 0;
		}
		else
		{
			printf("Error id\n");
		}
	}
	else
	{
		printf("Error null\n");
	}

	fclose(pFile);
    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListBook)
{
	int retorno = -1;//error
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(!parser_BookFromBinary(pFile, pArrayListBook))
		{
			retorno = 0; //exito
			printf("Archivo de texto cargado con exito\n");
		}
		else
		{
			printf("Error\n");
		}
	}
	else
	{
		printf("Error\n");
	}
	fclose(pFile);
    return retorno;
}



int controller_addBook(LinkedList* pArrayListBook)
{
	int retorno = -1;//exit
	char auxNameB[NAMEB_LEN];
	char auxAuthor[NAME_LEN];
	float auxPrice;
	int auxYear;
	int nextId;

	Book* pBook = book_new(); //malloc



	if(pArrayListBook != NULL && pBook != NULL)
	{
		if(!utn_getCadena(auxNameB, NAMEB_LEN, 2, "Ingrese nombre del libro: ", "Error, nombre invalido.\n\n") &&
		   !utn_getCadena(auxAuthor, NAME_LEN, 2, "Ingrese autor del libro: ", "Error, autor invalido.\n\n") &&
		   !utn_getFlotante(&auxPrice, 2, "Ingrese el precio de 100 a 1500: ", "Error, precio invalido.\n\n", 100, 1500) &&
		   !utn_getEntero(&auxYear, 2, "Ingrese el anio de publicacion: ", "Error, anio invalido\n\n", 1900, 2020) )
		{
			normalizeStr(auxAuthor);//normalizo nombre del autor

			obtenerId(&nextId);


			//nextId = book_lastId(pArrayListBook) + 1; //lo que retorne la funcion + 1

			if(!book_setId(pBook, nextId) &&
			   !book_setNameB(pBook, auxNameB) &&
			   !book_setAuthor(pBook, auxAuthor) &&
			   !book_setPrice(pBook, auxPrice) &&
			   !book_setYear(pBook, auxYear))
			{
				if(ll_add(pArrayListBook, pBook) == 0)
				{
					printf("Alta exitosa\n");
					actualizarId(nextId);//incremento en 1
				}

			}//if setters
			else
			{
				free(pBook);
			}
		}//if utn
		else
		{
			free(pBook);//libero el espacio
		}
	}//if null
    return retorno;
}


int controller_editBook(LinkedList* pArrayListBook)
{
	Book* pBook;
	int auxId;
	int lastId;
	int retorno = -1;
	int index;
	int confirmOut = 0;

	if(pArrayListBook != NULL)
	{
		controller_ListBook(pArrayListBook);//listo los libros

		for(int i = 0; i < ll_len(pArrayListBook); i++)
		{
			pBook = ll_get(pArrayListBook, i);

			book_getId(pBook, &auxId);
			if(auxId >= lastId)
			{
				lastId = auxId;//el ultimo id va a ser el mas grande
			}
		}

		if(!utn_getEntero(&auxId, 2, "Ingrese ID del libro a modificar.\n", "Error, ID invalido", 0, lastId))
		{
			index = book_SearchForId(pArrayListBook, auxId);
			if(index > -1)
			{
				//mostrar el libro
				printf("\n    ID                                 Libro                       Autor         Precio   Anio\n\n");
				book_printBook(pArrayListBook, index);//imprimo el libro elegido

				do
				{
					switch(menuEdit())
					{
						case 1:
							//Nombre del libro
							if(changeNameB(pArrayListBook, index) == 0)
							{
								printf("Nombre del libro modificado con exito.\n");
								book_printBook(pArrayListBook, index);
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 2:
							//Autor
							if(changeAuthor(pArrayListBook, index) == 0)
							{
								printf("Autor actualizado con exito.\n");
								book_printBook(pArrayListBook, index);
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 3:
							//Precio
							if(changePrice(pArrayListBook, index) == 0)
							{
								printf("Precio modificado con exito.\n");
								book_printBook(pArrayListBook, index);
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 4:
							//Anio
							if(changeYear(pArrayListBook, index) == 0)
							{
								printf("Anio modificado con exito.\n");
								book_printBook(pArrayListBook, index);
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 5:
							confirmOut = 1;
							break;

					}//switch

				}while(confirmOut == 0);
			}//if index
		}//if utn
	}//if null
	return retorno;
}


int controller_removeBook( LinkedList* pArrayListBook)
{
	int retorno = -1;
	int auxId;
	int lastId;
	Book* pBook;
	int index;
	char confirmDelete;

	if(pArrayListBook != NULL)
	{
		controller_ListBook(pArrayListBook);//listo los libros

		lastId = book_lastId(pArrayListBook);//me devuelve el id mas alto

		if(!utn_getEntero(&auxId, 2, "Ingrese ID del libro a eliminar del sistema: ", "Error, ID invalido", 0, lastId))
		{
			index = book_SearchForId(pArrayListBook, auxId);
			if(index > -1)
			{
				pBook = ll_get(pArrayListBook, index);
				//mostrar el libro
				printf("\n    ID                                 Libro                       Autor         Precio   Anio\n\n");
				book_printBook(pArrayListBook, index);//imprimo el libro elegido

				printf("Confirma la eliminacion del libro? y/n: ");
				fpurge(stdin);
				scanf("%c", &confirmDelete);
				if(confirmDelete == 'y')
				{
					ll_remove(pArrayListBook, index);//elimino el libro en ese index
					if(book_delete(pBook) == 0) //elimino el punt aux que me cree
					{
						printf("Baja realizada con exito\n");
						retorno = 0;
					}
				}
			}
		}
	}
    return retorno;
}


int controller_ListBook(LinkedList* pArrayListBook)
{
	int retorno = -1;
	if(pArrayListBook != NULL)
	{
		printf("\n  ID      Libro                                       Autor                      Precio   Anio\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < ll_len(pArrayListBook); i++)
		{
			book_printBook(pArrayListBook, i);
		}
	}
	else
	{
		printf("No hay libros cargados en la lista.\n");
	}

    return retorno;
}


int controller_sortBook(LinkedList* pArrayListBook)
{
	int retorno = -1;

	if(pArrayListBook != NULL)
	{
		if(book_sort(pArrayListBook) == 0)
		{
			printf("Libros ordenados exitosamente.\n");
		}
	}
	else
	{
		printf("Error\n");
	}

    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListBook)
{
	int retorno = -1;

	FILE* pFile;
	int auxId;
	char auxNameB[NAMEB_LEN];
	char auxAuthor[NAME_LEN];
	float auxPrice;
	int auxYear;
	Book* pBook;

	if(pArrayListBook != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i = 1; i < ll_len(pArrayListBook); i++)//por cada elemento del array lo escribo en el archivo, desde la pos 1
			{
				pBook = ll_get(pArrayListBook, i);
				//utilizo los getter para traerme la info
				if(!book_getId(pBook, &auxId) &&
				   !book_getNameB(pBook, auxNameB) &&
				   !book_getAuthor(pBook, auxAuthor) &&
				   !book_getPrice(pBook, &auxPrice) &&
				   !book_getYear(pBook, &auxYear))
				{
					fprintf(pFile, "%d,%s,%s,%f,%d\n", auxId, auxNameB, auxAuthor, auxPrice, auxYear);
				}
			}
			fclose(pFile);
			printf("Archivo guardado!\n");
		}//if fpArchivo NULL
	}//if NULL

    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListBook)
{
	int retorno = -1;//error
	FILE* pFile;
	Book* pBook;

	if(pArrayListBook != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 1; i < ll_len(pArrayListBook); i++)//desde la pos 1
		{
			pBook = (Book*) ll_get(pArrayListBook, i);
			fwrite(pBook, sizeof(Book), 1, pFile);
		}
		printf("Archivo guardado!\n");
		fclose(pFile);
		retorno = 0;//exito
	}

    return retorno;
}



int obtenerId(int* id)
{
	int error = 1;
	*id = 1001;//proximo

	FILE* f;
	f = fopen("proximoId.bin", "rb");
	if(f != NULL)
	{
		fread(id, sizeof(int), 1, f);
		fclose(f);
		error = 0;
	}

	return error;
}

int actualizarId(int id)
{
	int error = 1;
	id++;

	FILE* f = fopen("proximoId.bin", "wb");
	if(f != NULL)
	{
		fwrite(&id, sizeof(int), 1, f);
		fclose(f);
		error = 0;
	}

	return error;
}

int controller_SecuritySave(char* path, LinkedList* pArrayListBook)
{
	int retorno = -1;
	FILE* pFile;
	LinkedList* cloneArray = NULL;
	Book* pBook;

	if(pArrayListBook != NULL)
	{
		cloneArray = ll_clone(pArrayListBook);

		if(cloneArray != NULL && ll_containsAll(pArrayListBook, cloneArray))
		{
			pFile = fopen(path, "wb");//binario
			for(int i = 1; i < ll_len(cloneArray); i++)//desde la pos 1
			{
				pBook = (Book*) ll_get(cloneArray, i);
				fwrite(pBook, sizeof(Book), 1, pFile);
			}
			fclose(pFile);
			printf("Archivo guardado!\n");
			retorno = 0;
		}
		else
		{
		 printf("error");
		}
	}
	return retorno;
}

int controller_relocate(LinkedList* pArrayListBook)
{
	int retorno = -1;
	int id;
	int nextId;
	int index;
	Book* pBook;
	int id2;
	int index2;
	char confirm;

	if(pArrayListBook != NULL)
	{
		controller_ListBook(pArrayListBook);
		obtenerId(&nextId);
		utn_getEntero(&id, 2, "Ingrese ID del libro a reubicar: ", "Error, ID incorrecto.\n\n", 1, nextId - 1);//el maximo es el ultimo id

		index = book_SearchForId(pArrayListBook, id);
		if(index > -1)
		{
			printf("\n    ID                                 Libro                       Autor         Precio   Anio\n\n");
			book_printBook(pArrayListBook, index);

			printf("Confirma la reubicacion del elemento? y/n: ");
			fpurge(stdin);
			scanf("%c", &confirm);
			if(confirm == 'y')
			{
				pBook = (Book*) ll_pop(pArrayListBook, index);//me devuelve un puntero al elemento en el indice pasado por parametros
				controller_ListBook(pArrayListBook);

				if(utn_getEntero(&id2, 2, "Luego de que libro quiere insertarlo? Ingresar ID: ", "Error, ID incorrecto.\n\n", 1, nextId - 1)==0)
				{
					index2 = book_SearchForId(pArrayListBook, id2);
					if(index2 > -1)
					{
						ll_push(pArrayListBook, index2+1, pBook);
					}
					else
					{
						printf("Error, ID inexistente.\n\n");
						//hacer que si sale mal, devuelva el libro a la posicion original:
						ll_push(pArrayListBook, index, pBook);
					}
				}
				else
				{
					ll_push(pArrayListBook, index, pBook);;
				}
			}
		}
		else
		{
			printf("Error, ID inexistente.\n\n");
		}
	}

	return retorno;
}
