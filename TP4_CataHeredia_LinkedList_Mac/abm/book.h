#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

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
 * \return Retorna un puntero a empleado
 */
Book* book_new();

/*
 * \brief Llama a los setters que cargan los campos del empleado
 * \param idStr id del empleado como string, nombreStr nombre del empleado como string, horasTrabajadasStr cantidad de hs trabajadas como string, sueldoStr sueldo del empleado como string
 * \return Retorna un puntero a empleado
 */
Book* book_newParametros(char* idStr,char* nameB,char* author, char* price, char* year);

/*
 * \brief Elimina un empleado
 * \param this: puntero a empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_delete(Book* this);

/*
 * \brief Valida y carga el id en el campo del empleado
 * \param this: puntero a empleado, id: id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setId(Book* this,int id);

/*
 * \brief Carga el id del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, id: puntero a la variable en la que la funcion cargara el id
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getId(Book* this,int* id);

/*
 * \brief Valida y carga el nombre en el campo del empleado
 * \param this: puntero a empleado, nombre: nombre a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setNameB(Book* this,char* nombre);

/*
 * \brief Carga el nombre del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, nombre: cadena de caracteres en la que la funcion cargara el nombre
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getNameB(Book* this,char* nombre);

int book_setAuthor(Book* this,char* author);
int book_getAuthor(Book* this,char* author);

/*
 * \brief Valida y carga las horas trabajadas en el campo del empleado
 * \param this: puntero a empleado, horasTrabajadas: horas a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setPrice(Book* this,float price);

/*
 * \brief Carga las horas trabajadas del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, horasTrabajadas: puntero a la variable en la que la funcion cargara las horas trabajadas
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getPrice(Book* this,float* price);

/*
 * \brief Valida y carga el sueldo en el campo del empleado
 * \param this: puntero a empleado, sueldo: sueldo a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_setYear(Book* this,int year);

/*
 * \brief Carga el sueldo del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, sueldo: puntero a la variable en la que la funcion cargara el sueldo
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_getYear(Book* this,int* year);

/*
 * \brief Busca un empleado por id
 * \param pArrayListEmployee: LinkedList, id: id a buscar en la lista
 * \return -1 en caso de error, o el index del empleado en caso de exito
 */
int book_SearchForId(LinkedList* pArrayListBook, int id);

/*
 * \brief Imprime un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_printBook(LinkedList* pArrayListBook, int index);

//Editar:

/*
 * \brief Cambia el nombre de un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changeNameB(LinkedList* pArrayListBook, int index);

int changeAuthor(LinkedList* pArrayListBook, int index);

/*
 * \brief Actualiza las horas trabajadas de un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changePrice(LinkedList* pArrayListBook, int index);

/*
 * \brief Cambia el salario de un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int changeYear(LinkedList* pArrayListBook, int index);


/*
 * \brief Devuelve el id mas alto de la lista
 * \param pArrayListEmployee: LinkedList
 * \return -1 en caso de error, o el id mas alto en caso de exito
 */
int book_lastId(LinkedList* pArrayListBook);

/*
 * \brief Switchea entre los cases de ordenamiento
 * \param pArrayListEmployee: LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int book_sort(LinkedList* pArrayListBook);

/*
 * \brief Compara los ids de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el id del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int book_sortById(void* firstBook, void* secondBook);

/*
 * \brief Compara los nombres de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el nombre del primer empleado esta antes en el alfabeto, -1 si esta despues y 0 si son iguales
 */
int book_sortByNameB(void* firstBook, void* secondBook);

/*
 * \brief Compara las horas trabajadas de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si las horas trabajadas del primer empleado son mas, -1 si son menos y 0 si son iguales
 */
int book_sortByAuthor(void* firstBook, void* secondBook);

/*
 * \brief Compara los sueldos de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el sueldo del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int book_sortByPrice(void* firstBook, void* secondBook);

int book_sortByYear(void* firstBook, void* secondBook);


#endif // employee_H_INCLUDED
