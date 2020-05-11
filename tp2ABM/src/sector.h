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


/**
 * @brief Carga la descripcion del sector.
 * @param Cadena a la que quiero que se le copie la descripcion del sec
 * @param Id del sector que quiero copiar
 * @param Vector de sectores
 * @param Tamanio del vector de sectores
 * @return 1 si cargo la descripcion con exito, o 0 si no.
 */
int loadSectorDescription(char descrip[], int id, eSector sectors[], int len);

/**
 * @brief Muestra la lista de sectores.
 * @param Lista de sectores
 * @param Tamanio del vector de sectores.
 * @return 1 si logra mostrar los sectores con exito, o 0 si no.
 */
int showSectors(eSector sectors[], int len);

#endif /* SECTOR_H_ */
