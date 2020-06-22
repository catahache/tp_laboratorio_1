#ifndef book_H_INCLUDED
#define book_H_INCLUDED

#include "../inc/LinkedList.h"

#define NAMEB_LEN 200
#define NAME_LEN 128

typedef struct
{
    int id;
    char nameB[NAMEB_LEN];
    char author[NAME_LEN];
    float price;
    int year;
}Book;

/*
 * \brief Pide memoria con malloc
 * \param
 * \return Retorna un puntero a Book
 */
Book* book_new();

/*
 * \brief Llama a los setters que cargan los campos del libro
 * \param IdStr, cadena de caracteres de id del libro
 * \param nameB, cadena de caracteres de nombre del libro
 * \param author, cadena de caracteres de autor del libro
 * \param price, cadena de caracteres de precio del libro
 * \param year, cadena de caracteres de anio de publicacion del libro
 * \return Retorna un puntero a Book
 */
Book* book_newParametros(char* idStr,char* nameB,char* author, char* price, char* year);

/*
 * \brief Elimina un libro
 * \param this, puntero a lirbo
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_delete(Book* this);

/*
 * \brief Valida y carga el id en el campo del libro
 * \param this, puntero a libro
 * \param id, id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setId(Book* this,int id);

/*
 * \brief Carga el id del libro en el puntero que se pase por parametros
 * \param this, puntero a libro
 * \param id, puntero a la variable en la que la funcion cargara el id
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getId(Book* this,int* id);

/*
 * \brief Valida y carga el nombre en el campo nameB del libro
 * \param this, puntero a libro
 * \param nameB, cadena de caracteres de nombre del libro a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setNameB(Book* this,char* nameB);

/*
 * \brief Carga el nombre del libro en el puntero que pasemos por parametros
 * \param this, puntero al libro
 * \param nameB, cadena de caracteres en la que la funcion cargara el nombre del libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getNameB(Book* this,char* nameB);

/*
 * \brief Valida y carga el nombre del autor en el campo author del libro
 * \param this, puntero a libro
 * \param author, cadena de caracteres de nombre del autor a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setAuthor(Book* this,char* author);

/*
 * \brief Carga el nombre del autor en el puntero que pasemos por parametros
 * \param this, puntero al libro
 * \param author, cadena de caracteres en la que la funcion cargara el nombre del autor del libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getAuthor(Book* this,char* author);

/*
 * \brief Valida y carga el precio en el campo price del libro
 * \param this, puntero al libro horasTrabajadas
 * \param price, float de precio a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setPrice(Book* this,float price);

/*
 * \brief Carga las horas trabajadas del empleado en el puntero que pasemos por parametros
 * \param this, puntero al libro
 * \param price, puntero a la variable en la que la funcion cargara el precio del libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getPrice(Book* this,float* price);

/*
 * \brief Valida y carga el anio de publicacion del libro en el campo year del libro
 * \param this, puntero al libro
 * \param year, int del anio de publicacion a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setYear(Book* this,int year);

/*
 * \brief Carga el anio de publicacion del libro en el puntero que pasemos por parametros
 * \param this, puntero al libro
 * \param year, puntero a la variable en la que la funcion cargara el anio
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getYear(Book* this,int* year);

/*
 * \brief Busca un libro por id
 * \param pArrayListBook, LinkedList
 * \param id, id a buscar en la lista
 * \return -1 en caso de error, o el index del empleado en caso de exito
 */
int book_SearchForId(LinkedList* pArrayListBook, int id);

/*
 * \brief Imprime un libro
 * \param pArrayListBook, LinkedList
 * \param index, indice donde se encuentra el libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_printBook(LinkedList* pArrayListBook, int index);


/*
 * \brief Cambia el titulo de un libro
 * \param pArrayListBook, LinkedList
 * \param index, indice donde se encuentra el libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changeNameB(LinkedList* pArrayListBook, int index);


/*
 * \brief Cambia el autor de un libro
 * \param pArrayListBook, LinkedList
 * \param index, indice donde se encuentra el libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changeAuthor(LinkedList* pArrayListBook, int index);

/*
 * \brief Cambia el precio de un libro
 * \param pArrayListBook, LinkedList
 * \param index, indice donde se encuentra el libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changePrice(LinkedList* pArrayListBook, int index);

/*
 * \brief Cambia el anio de publicacion de un libro
 * \param pArrayListBook, LinkedList
 * \param index, indice donde se encuentra el libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changeYear(LinkedList* pArrayListBook, int index);


/*
 * \brief Devuelve el id mas alto de la lista
 * \param pArrayListBook, LinkedList
 * \return -1 en caso de error, o el id mas alto en caso de exito
 */
int book_lastId(LinkedList* pArrayListBook);

/*
 * \brief Switchea entre los cases de ordenamiento
 * \param pArrayListBook, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_sort(LinkedList* pArrayListBook);

/*
 * \brief Compara los ids de dos libros
 * \param firstBook, puntero a primer libro a comparar
 * \param secondBook, puntero a segundo libro a comparar
 * \return 1 si el id del primer libro es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int book_sortById(void* firstBook, void* secondBook);

/*
 * \brief Compara los titulos de dos libros
 * param firstBook, puntero a primer libro a comparar
 * \param secondBook, puntero a segundo libro a comparar
 * \return 1 si el titulo del primer libro esta antes en el alfabeto, -1 si esta despues y 0 si son iguales
 */
int book_sortByNameB(void* firstBook, void* secondBook);

/*
 * \brief Compara los nombres de los autores de dos libros
 * param firstBook, puntero a primer libro a comparar
 * \param secondBook, puntero a segundo libro a comparar
 * \return 1 si el nombre del autor del primer libro esta antes en el alfabeto, -1 si esta despues y 0 si son iguales
 */
int book_sortByAuthor(void* firstBook, void* secondBook);

/*
 * \brief Compara los precios de dos libros
 * \param firstBook, puntero a primer libro a comparar
 * \param secondBook, puntero a segundo libro a comparar
 * \return 1 si el precio del primer libro es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int book_sortByPrice(void* firstBook, void* secondBook);

/*
 * \brief Compara los anios de publicacion de dos libros
 * \param firstBook, puntero a primer libro a comparar
 * \param secondBook, puntero a segundo libro a comparar
 * \return 1 si el anio de publicacion del primer libro es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int book_sortByYear(void* firstBook, void* secondBook);


#endif // book_H_INCLUDED
