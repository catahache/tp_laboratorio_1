/*
 ============================================================================
 Name        : tp1CalculadoraTerminado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menuOpciones.h"

int main(void) {

	int opcion;

	do{
		system("clear");

		menu(); //llamo al menu y luego pido al user que elija una opcion:

		printf("Elija una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)//depende la opcion que elija, va a alguno de los cases
		{
			case 1:
				opcion1();
				break;
			case 2:
				opcion2();
				break;
			case 3:
				opcion3();
				break;
			case 4:
				opcion4();
				break;
			case 5:
				printf("Adios!");
				break;
			default:
				printf("No es una opcino valida. \n");
				break;

		}//switch de opciones


	}while(opcion != 5);//se repite hasta que el user quiera salir con la opcion 5


	return 0;
}
