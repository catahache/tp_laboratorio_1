/*
 * sector.h
 *
 *  Created on: May 6, 2020
 *      Author: catalina
 */

#ifndef SECTOR_H_
#define SECTOR_H_

typedef struct{

	int id;
	char description[20];

}eSector;


/*
 * param cadena a la que quiero que se le copie el nombre del sec
 * id es nombre del sec que quiero copiar
 * vec para busqueda
 * tam del vector
 */
int loadSectorDescription(char descrip[], int id, eSector sectors[], int len);

int showSectors(eSector sectors[], int len);

#endif /* SECTOR_H_ */
