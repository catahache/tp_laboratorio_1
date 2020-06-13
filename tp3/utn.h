/*
 * utn.h
 *
 *  Created on: May 3, 2020
 *      Author: catalina
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * @brief Pausa hasta que el user ingrese un enter (\n)
 * @return Sin retorno
 */
void pause();

/**
 * @brief Valida que el user ingrese una cadena de caracteres.
 * @param Puntero a variable char en la que cargar la cadena validada.
 * @param Limite de caracteres a ingresar
 * @param Numero de reintentos
 * @param Mensaje a mostrar
 * @param Mensaje de error
 * @return 0 si tuvo exito, y -1 si no.
 */
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

/**
 * @brief Toma la cadena ingresada y le quita el '\n' al fgets.
 * @param Puntero a variable char en la que cargar la cadena validada.
 * @return 0 si tuvo exito, y -1 si no.
 */
int getCadena(char* pAux, int limit);

/**
 * @brief Valida que cada posicion de la cadena sea letra.
 * @param Cadena a analizar
 * @return 0 si todas las posiciones son letras, y -1 si no.
 */
int isChar(char str[]);

/**
 * @brief Valida que lo ingresado sea un numero flotante
 * @param Puntero a la variable float a cargar el numero validado.
 * @param Numero de reintentos
 * @param Mensaje
 * @param Mensaje de error
 * @param Minimo numero a ingresar
 * @param Maximo numero a ingresar
 * @return 0 si tuvo exito, y -1 si no.
 */
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

/**
 * @brief Obtiene una cadena mediante getCadena y valida mediante isFLoat. Pasa la cadena validada a flotante.
 * @param Puntero a flotante donde escribir el resultado de la validacion.
 * @return Retorna 0 si tuvo exito, -1 si no.
 */
int getFloat(float*pAux);

/**
 * @brief Valida que lo ingresado sea un numero flotante. Cuenta los puntos (que sea solo uno) y valida todas las posiciones de la cadena.
 * @param Cadena a cargar el numero flotante resultando de la validacion.
 * @return Retorna 0 si la cadena es de numeros y un solo punto (o sin punto), -1 si no.
 */
int isFloat(char* pAux);

/**
 * @brief Valida que lo ingresado sea un numero entero.
 * @param Puntero a entero donde cargar lo validado.
 * @param Cantidad de reintentos
 * @param Mensaje
 * @param Mensaje de error
 * @param Minimo numero a ingresar
 * @param Maximo numero a ingresar
 * @return
 */
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

/**
 * @brief Llama a getInt y a isCadena para validar que lo ingresado es un numero entero y pasa la cadena a integer.
 * @param Puntero a variable a cargar el numero validado.
 * @return Retorna 0 si logra validar, o -1 si no.
 */
int getInt(int* pAux);

/**
 * @brief Recorre la cadena validando que cada posicion sea un numero (0 - 9)
 * @param Cadena a cargar el numero validado
 * @return Retorna 0 si logra validar, o -1 si no.
 */
int isInt(char *pAux);

/**
 * @brief Pasa la cadena ingresada a minuscula recorriendola y en cada posicion llamando a tolower.
 * @param Cadena a cargar el string en minuscula
 * @return Retorna 0 si pasa la cadena con exito, o -1 si no.
 */
int strLwr(char* str);

/**
 * @brief "Normaliza" la cadena que le pasemos.
 * @param Cadena a cargar el string "normalizado"
 * @return Retorna 0 si normaliza la cadena con exito, o -1 si no.
 */
int normalizeStr(char* str);

//int isCuit(char str[]);

/**
 * @brief Valida la cadena que le pasemos como nombre.
 * @param Cadena a cargar el string validado
 * @return Retorna 1 si valida la cadena con exito, o 0 si no.
 */
int isValidName(char* cadena, int longitud);

/**
 * @brief Valida la cadena que le pasemos como numerica.
 * @param Cadena a cargar el string validado
 * @return Retorna 0 si valida la cadena con exito, o -1 si no.
 */
int isNumeric(char* cadena, int longitud);


#endif /* UTN_H_ */
