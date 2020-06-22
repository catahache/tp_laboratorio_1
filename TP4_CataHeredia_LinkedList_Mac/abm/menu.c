/*
 * menu.c
 *
 *  Created on: Jun 12, 2020
 *      Author: catalina
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

//menu opciones principal
int menu()
{
	int option;

	system("clear");

	printf("***** M E N U *****\n\n");
	printf("  1. Cargar los datos de los libros desde el archivo data.csv (modo texto).\n");
	printf("  2. Cargar los datos de los libros desde el archivo data.csv (modo binario).\n");
	printf("  3. Alta de libros\n");
	printf("  4. Modificar datos de libros\n");
	printf("  5. Baja de libros\n");
	printf("  6. Listar libros\n");
	printf("  7. Ordenar libros\n");
	printf("  8. Guardar los datos de los libros en el archivo data.csv (modo texto).\n");
	printf("  9. Guardar los datos de los libros en el archivo data.csv (modo binario).\n");
	printf("  10. Salir\n\n");

	utn_getEntero(&option, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 10);
	return option;
}


//menu editar
int menuEdit()
{
	int option;

	system("clear");

	printf("***** M O D I F I C A R *****\n\n");
	printf("  1. Nombre del libro\n");
	printf("  2. Autor\n");
	printf("  3. Precio\n");
	printf("  4. Anio de publicacion\n");
	printf("  5. Salir\n\n");

	utn_getEntero(&option, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 5);

	return option;
}

//sortMenu()
int menuSort()
{
	int option;

	system("clear");

	printf("***** O R D E N A R *****\n\n");
	printf("  1. Por ID\n");
	printf("  2. Por Nombre del libro\n");
	printf("  3. Por Autor\n");
	printf("  4. Por Precio\n\n");
	printf("  5. Por anio de publicacion\n");
	printf("  6. Salir\n\n");

	utn_getEntero(&option, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 6);

	return option;

}
