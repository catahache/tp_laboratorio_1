/*
 ============================================================================
 Name        : tp1CalculadoraTerminado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 */
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

	int num1;
	int num2;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	int flag4 = 0;
	int opcion;
	int resulSuma;
	int resulResta;
	int resulMultiplicacion;
	float resulDivision;
	unsigned long long resulFact1;
	unsigned long long resulFact2;



	do{
		system("clear");

		menu(num1, num2, flag1, flag2, flag3, flag4, resulSuma, resulResta, resulMultiplicacion, resulDivision, resulFact1, resulFact2); //llamo al menu y luego pido al user que elija una opcion:

		printf("Elija una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)//depende la opcion que elija, va a alguno de los cases
		{
			case 1:
				opcion1(&flag1, &num1);
				break;

			case 2:
				opcion2(flag1, &flag2, &num2);
				break;

			case 3:
				opcion3(flag1, flag2, &flag3, num1, num2, &resulSuma, &resulResta, &resulMultiplicacion, &resulDivision, &resulFact1, &resulFact2);
				break;

			case 4:
				opcion4(flag1, flag2, flag3, &flag4);
				break;

			case 5:
				printf("Adios! \n\n");
				break;
			default:
				printf("No es una opcino valida. \n");
				break;

		}//switch de opciones


	}while(opcion != 5);//se repite hasta que el user quiera salir con la opcion 5


	return 0;
}
