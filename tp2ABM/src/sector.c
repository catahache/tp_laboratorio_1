/*
 * sector.c
 *
 *  Created on: May 6, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sector.h"

int loadSectorDescription(char descrip[], int id, eSector sectors[], int len)
{
	int isOk = 0;

	for(int i = 0; i < len; i++)
	{
		if(sectors[i].id == id) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
		{
			strcpy(descrip, sectors[i].description); //copio a descripcion la descripcion que tengo en ese sector
			isOk = 1; //exito
			break;
		}
	}

	return isOk;
}

int showSectors(eSector sectors[], int len)
{
	int isOk = 0;
	if(sectors != NULL)
	{
		isOk = 1;
		printf("***** Sectores *****\n");
		printf("  ID    Descripcion\n\n");

		for(int i = 0; i < len; i++)
		{
			printf("%d   %10s \n", sectors[i].id, sectors[i].description);
		}
	}
	return isOk;
}
