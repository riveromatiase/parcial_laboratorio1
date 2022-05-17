/*
 * gets.c
 *
 *  Created on: 11 may. 2022
 *      Author: flor_
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gets.h"
#include "validations.h"
#include "menu.h"


#define LEN_DNI 9
#define LEN_CUIT 12
#define LEN_EMAIL 25
#define LEN_TELEFONO 14
#define LEN_TARJETA 20

/*_| |____________________________________________| |__
(__   ____________________________________________   __)
   | |                                            | |
   | |              FUNCION PRINCIPAL             | |
 __| |____________________________________________| |__
(__   ____________________________________________   __)
   | |                                            | |*/
/*
 * \brief Recibe una cadena con fgets, le remueve el enter del final y devuelve el resultado por referencia
 * \param string Puntero a la direccion de memoria del string
 * \param len Tamaño del array. Limite de caracteres/digitos
 * \return -1 si hubo error de validacion, 1 si no hubo errores.
 * */
int get_myGets(char* pResultado, int len)
{
	int returnFunction = -1;
	fflush(stdin);
	if(pResultado != NULL && len > 0 && fgets(pResultado,len,stdin)==pResultado)
	{
		fflush(stdin);
		if(pResultado[strlen(pResultado)-1]== '\n')
		{
			pResultado[strlen(pResultado)-1]='\0';
		}
		returnFunction = 1;
	}
	return returnFunction;
}

/*_| |____________________________________________| |__
(__   ____________________________________________   __)
   | |                                            | |
   | |          FUNCIONES DE OBTENCION            | |
 __| |____________________________________________| |__
(__   ____________________________________________   __)
   | |                                            | |*/

/*
 * \brief Pide un numero entero
 * \param int* pResultado Puntero a la dirección de memoria donde guardar el valor obtenido y validado
 * \param int len Tamaño del array indica el maximo de digitos del numero (hay que descontar el EOF y el signo menos, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int flagMaximoMinimo: Indica si acepta valores maximos y minimos (1) o no (0)
 * \param int minimo Valor minimo a recibir
 * \param int maximo Valor maximo a recibir
 * \param int reintentos Cantidad de reintentos
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return Devuelve 1 si pudo obtener un entero, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
//
//int get_char(char* caracter,char* listaBlanca,int lenListaBlanca)
//{
//	int returnFunction = -1;
//	char buffer;
//	returnFunction = 0;
//	int reintentos=3;
//	while(reintentos >= 0)
//	{
//		printf("%s","si o no: ");
//		if(get_myGets(buffer,1) && val_isValidInt(buffer,flagSigned)==1)
//		{
//			buffer=atoi(buffer);
//			if(flagMaximoMinimo == 1)
//			{
//				if(bufferInt <= maximo && bufferInt >= minimo)
//				{
//					*pResultado = bufferInt;
//					returnFunction = 1;
//					break;
//				}
//			}
//		}
//		printf("%s","error. ");
//		reintentos--;
//	}
//	return returnFunction;
//}

int get_numeroint(int* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned)
{
	int returnFunction = -1;
	char buffer[len];
	int bufferInt;
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,len) && val_isValidInt(buffer,flagSigned)==1)
			{
				bufferInt=atoi(buffer);
				if(flagMaximoMinimo == 1)
				{
					if(bufferInt <= maximo && bufferInt >= minimo)
					{
						*pResultado = bufferInt;
						returnFunction = 1;
						break;
					}
				}
				else
				{
					*pResultado = bufferInt;
					returnFunction = 1;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

int utn_getNumero(int *pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getInt(&bufferInt)==0)
			{
				if(bufferInt >= minimo && bufferInt<= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}

	}
	return retorno;
}

/*
 * \brief Pide un numero flotante
 * \param float* pResultado Puntero a la dirección de memoria donde guardar el valor obtenido y validado
 * \param int len Tamaño del array indica el maximo de digitos del numero (hay que descontar el EOF y el signo menos, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int flagMaximoMinimo: Indica si acepta valores maximos y minimos (1) o no (0)
 * \param int minimo Valor minimo a recibir
 * \param int maximo Valor maximo a recibir
 * \param int reintentos Cantidad de reintentos
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return Devuelve 1 si pudo obtener un flotante, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_float(float* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned)
{
	int returnFunction = -1;
	char buffer[len];
	float bufferFloat;
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,len) && val_isValidFloat(buffer,flagSigned)==1)
			{
				bufferFloat=atof(buffer);
				if(flagMaximoMinimo == 1)
				{
					if(bufferFloat <= maximo && bufferFloat >= minimo)
					{
						*pResultado = bufferFloat;
						returnFunction = 1;
						break;
					}
				}
				else
				{
					*pResultado = bufferFloat;
					returnFunction = 1;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un nombre
 * \param int* pResultado Puntero a la dirección de memoria donde guardar el dato obtenido y validado
 * \param int len Tamaño del array indica el maximo de caracteres del nombre (hay que descontar el EOF y espacios, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un nombre, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_name(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, len) && val_isValidName(buffer))
			{
				strcpy(pResultado,buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un texto no vacio
 * \param char* pResultado Puntero a la dirección de memoria donde guardar el texto obtenido
 * \param int len Tamaño del array indica el maximo de caracteres del texto (hay que descontar el EOF)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un texto, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_text(char* pResultado,int len,char* mensaje,char* mensajeError, int reintentos)
{
	int returnFunction = -1;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL)
	{
		returnFunction = 1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, len) && buffer[0] != 0)
			{
				strcpy(pResultado,buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un dni
 * \param char* pResultado Dirección de memoria del array de caracteres donde almacenar el dni
 * \param int len Tamaño máximo del dni
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un dni, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_dni(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[LEN_DNI];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, LEN_DNI) && val_isValidDni(buffer))
			{
				strcpy(pResultado,buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un cuit
 * \param char* pResultado Dirección de memoria del array de caracteres donde almacenar el cuit
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un cuit, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_cuit(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[LEN_CUIT];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, LEN_CUIT) && val_isValidCuit(buffer)==1)
			{
				strcpy(pResultado,buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

int get_email(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -1;
	char buffer[LEN_EMAIL];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if((get_myGets(buffer, LEN_EMAIL)==1))
			{
				if(val_isValidEmail(buffer)==0){
					strcpy(pResultado,buffer);
					returnFunction = 0;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

int get_tarjeta(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -2;
	char buffer[LEN_TARJETA];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,LEN_TARJETA) && val_isValidTarjeta(buffer))
			{
				strncpy(pResultado,buffer,LEN_TARJETA);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}
int get_telefono(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -2;
	char buffer[LEN_TELEFONO];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,LEN_TELEFONO) && val_isValidTelefono(buffer))
			{
				strncpy(pResultado,buffer,LEN_TELEFONO);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[longitud];
	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}

	}
	return retorno;
}


int esNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getCadena(char *cadena, int tamano, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferCadena [tamano];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje);
			if (fgets(bufferCadena, sizeof bufferCadena, stdin) != NULL)
			{
				bufferCadena[strcspn(bufferCadena, "\n")] = 0;
				strcpy(cadena,bufferCadena);
				retorno = 0;
				break; //como salio todo bien rompo el do-while
			}
				printf("%s",mensajeError);
			    reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}


char utn_getChar(char *pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char buffer[2];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje); //se pone %s porque recibe una cadena
			fflush(stdin);
			fgets(buffer,2,stdin);
			strlwr(buffer);
			if (buffer[0]>=minimo && buffer[0]<=maximo)
			{
				*pResultado = buffer[0];
				retorno = 0;
				break; //como salio todo bien rompo el do-while
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}

