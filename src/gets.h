/*
 * gets.h
 *
 *  Created on: 11 may. 2022
 *      Author: flor_
 */

#ifndef GETS_H_
#define GETS_H_

int get_myGets(char* pResultado, int len);
char utn_getChar(char *pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int utn_getCadena(char *cadena, int tamano, char* mensaje, char* mensajeError, int reintentos);
int esNumerica(char* cadena);
int myGets(char* cadena, int longitud);
int get_numeroint(int* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned);
int getInt(int* pResultado);
int get_float(float* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned);
int get_name(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
int utn_getNumero(int *pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int get_text(char* pResultado,int len,char* mensaje,char* mensajeError, int reintentos);
int get_dni(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_cuit(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_email(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_tarjeta(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_telefono(char* pResultado,char* mensaje,char* mensajeError,int reintentos);

#endif /* GETS_H_ */
