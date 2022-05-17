/*
 * validations.c
 *
 *  Created on: 11 may. 2022
 *      Author: flor_
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "gets.h"
#include "validations.h"
#include "usuario.h"

#define LEN_EMAIL 30

/*
 * \brief Indica si un string es un numero entero
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto numero
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return -1 error de validacion, 0 no es un numero entero, 1 sí es un numero entero.
 * */
int val_isValidInt(char* numero, int flagSigned)
{
	int returnFunction = -1;
	int i;
	if(numero != NULL)
	{
		returnFunction = 1;
		if((numero[0] < '0' || numero[0] > '9') && numero[0] !='-')
		{
			returnFunction = 0;
		}
		else
		{
			i = 1;
			while(numero[i] != 0) // busco el final
			{
				if(numero[i]<'0' || numero[i]>'9')
				{
					returnFunction = 0;
					break;
				}
				i++;
			}
		}
	}
	return returnFunction;
}

/*
 * \brief Indica si un string es un numero flotante
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto numero
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return -1 error de validacion, 0 no es un numero flotante, 1 sí es un numero flotante.
 * */
int val_isValidFloat(char* numero, int flagSigned)
{
	int returnFunction = -1;
	int i;
	if(numero != NULL)
	{
		returnFunction = 1;
		if(flagSigned)
		{
			if((numero[0]<'0' || numero[0]>'9') && numero[0] != '.' && numero[0] != '-')
			{
				returnFunction = 0;
			}
			else
			{
				i = 1;
				while(numero[i] != 0) // busco el final
				{
					if((numero[i]<'0' || numero[i]>'9') && numero[i] != '.')
					{
						returnFunction = 0;
						break;
					}
					i++;
				}
			}
		}
		else
		{
			i = 0;
			while(numero[i] != 0) // busco el final
			{
				if((numero[i]<'0' || numero[i]>'9') && numero[i] != '.')
				{
					returnFunction = 0;
					break;
				}
				i++;
			}
		}
	}
	return returnFunction;
}

/*
 * \brief Indica si un string es un nombre valido
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto nombre
 * \return -1 error de validacion, 0 no es un nombre, 1 sí es un nombre.
 * */
int val_isValidName(char* nombre)
{
	int i=0;
	int returnFunction = -1;
	if(nombre != NULL)
	{
		returnFunction = 1;
		while(nombre[i] != 0) // busco el final
		{
			if(!((nombre[i]>='a' && nombre[i]<='z') || (nombre[i]>='A' && nombre[i]<='Z') || nombre[i]==' '))
			{
				returnFunction = 0;
				break;
			}
			i++;
		}
	}
	return returnFunction;
}

/*
 * \brief Indica si un string es un dni valido
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto dni
 * \return -1 error de validacion, 0 no es un dni valido, 1 sí es un dni valido.
 * */
int val_isValidDni(char* dni)
{
	int i=0;
	int returnFunction = -1;
	if(dni != NULL)
	{
		returnFunction = 1;
		if(val_cantidadDigitos(dni)>6)
		{
			while(dni[i] != 0) // busco el final
			{
				if(dni[i]<'0' || dni[i]>'9')
				{
					returnFunction = 0;
					break;
				}
				i++;
			}
		}
		else
		{
			returnFunction = 0;
		}
	}
	return returnFunction;
}

/*
 * \brief Indica si un string de un cuit es valido
 * \param char* numero Puntero a la dirección de memoria del string del cut
 * \return -1 error de validacion, 0 no es un cuit valido, 1 sí es un cuit valido.
 * */
int val_isValidCuit(char* cuit)
{
	int i=0;
	int returnFunction = -1;
	if(cuit != NULL)
	{
		returnFunction = 1;
		if(val_cantidadDigitos(cuit)>9 && val_cuitDigitoVerificador(cuit))
		{
			while(cuit[i] != 0) // busco el final
			{
				if(cuit[i]<'0' || cuit[i]>'9')
				{
					returnFunction = 0;
					break;
				}
				i++;
			}
		}
		else
		{
			returnFunction = 0;
		}
	}
	return returnFunction;
}


int val_cantidadDigitos(char* arrayParaVerificar)
{
	int contadorDigitos=-1;
	if(arrayParaVerificar != NULL)
	{
		for(contadorDigitos=0;;contadorDigitos++)
		{
			if(arrayParaVerificar[contadorDigitos]==0)
				break;
		}
	}
	return contadorDigitos;
}


int val_cuitDigitoVerificador(char* cuit)
{
	int returnFunction = -1;
	int auxiliares[10]={5,4,3,2,7,6,5,4,3,2};
	int auxCuitInt[11];
	int acumulador=0;
	int digitoVerificador;
	float promedio;
	int i;
	if(cuit != NULL)
	{
		for(i=0;i<11;i++)
		{
			switch(cuit[i])
			{
				case '0':
					auxCuitInt[i] = 0;
					break;
				case '1':
					auxCuitInt[i] = 1;
					break;
				case '2':
					auxCuitInt[i] = 2;
					break;
				case '3':
					auxCuitInt[i] = 3;
					break;
				case '4':
					auxCuitInt[i] = 4;
					break;
				case '5':
					auxCuitInt[i] = 5;
					break;
				case '6':
					auxCuitInt[i] = 6;
					break;
				case '7':
					auxCuitInt[i] = 7;
					break;
				case '8':
					auxCuitInt[i] = 8;
					break;
				case '9':
					auxCuitInt[i] = 9;
					break;
			}
		}
		for(i=0;i<10;i++)
		{
			acumulador += auxCuitInt[i]*auxiliares[i];
		}
		promedio=acumulador/11.0;
		digitoVerificador=11-round((promedio-(int)promedio)*10);
		if(digitoVerificador==auxCuitInt[10])
		{
			returnFunction = 1;
		}
		else
		{
			returnFunction = 0;
		}
	}
	return returnFunction;
}

int val_isValidEmail(char* email)
{
	int i=0;
	int returnFunction = -1;
	int contadorPuntos = 0;
	int contadorArroba = 0;
	if(email != NULL)
	{
			while(email[i] != 0) // busco el final
			{
				if((email[i]>='a' && email[i]<='z') || (email[i]>='A' && email[i]<='Z') || (email[i]>='0' || email[i]<='9') ||
						email[i]=='@' || email[i]=='-' || email[i]=='_' || email[i]=='.')
				{

					if(email[i]=='.')
					{
						contadorPuntos++;
					}
					if(email[i]=='@'){
						contadorArroba++;
					}
					if(contadorArroba == 1 && contadorPuntos>0)
					{
						returnFunction = 0;
					}
				}
				i++;
			}
	}

	return returnFunction;
}

int val_isValidTelefono(char* telefono)
{
	int i=0;
	int retorno = -1;
	int contadorGuiones=0;
	if(telefono != NULL)
	{
		retorno = 1;
		if(val_cantidadDigitos(telefono)>7)
		{
			for(i=0;i!=0;i++)
			{
				if(telefono[i]<'0' || telefono[i]>'9' || telefono[i]!='-')
				{
					retorno = 0;
					break;

				}
				if(telefono[i]=='-')
				{
					contadorGuiones++;
					continue;
				}

			}
				if(contadorGuiones > 2)
				{
					retorno=0;
				}
		}
		else
		{
			retorno = 0;
		}
	}

	return retorno;
}



int val_isValidTarjeta(char* tarjeta)
{
    int retorno = 0;
    int i;
    int contadorGuiones = 0;

    if (tarjeta != NULL)
    {
        if (tarjeta[4] == '-' && tarjeta[9]== '-' && tarjeta [14] == '-')
        {
            retorno = 1;
            for (i=0;tarjeta [i] != '\0'; i++)
            {
                if ((tarjeta[i] >= '0' || tarjeta[i] <= '9') && (tarjeta [i]== '-'))
                {
                    retorno = 1;
                    contadorGuiones++;
                }
            }
            if (contadorGuiones>4)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

