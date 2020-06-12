/*
 * menu.c
 *
 *  Created on: Jun 12, 2020
 *      Author: catalina
 */

#include "menu.h"

//menu editar
int menuEdit()
{
	int option;

	system("clear");

	printf("***** M O D I F I C A R *****\n\n");
	printf("  1. Nombre\n");
	printf("  2. Horas trabajadas\n");
	printf("  3. Sueldo\n");
	printf("  4. SALIR\n\n");

	utn_getEntero(&option, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 4);

	return option;
}
