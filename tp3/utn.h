/*
 * utn.h
 *
 *  Created on: May 3, 2020
 *      Author: catalina
 */

#ifndef UTN_H_
#define UTN_H_

void pause();

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

int getCadena(char* pAux, int limit);

int isChar(char str[]);

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

int getFloat(float*pAux);

int isFloat(char* pAux);

int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

int getInt(int* pAux);

int isInt(char *pAux);

int strLwr(char* str);

int normalizeStr(char* str);

//int isCuit(char str[]);

//estaticas
int isValidName(char* cadena, int longitud);
int isNumeric(char* cadena, int longitud);


#endif /* UTN_H_ */
