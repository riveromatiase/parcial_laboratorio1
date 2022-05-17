/*
 * validations.h
 *
 *  Created on: 11 may. 2022
 *      Author: flor_
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_


int val_isValidInt(char* numero, int flagSigned);
int val_isValidFloat(char* numero, int flagSigned);
int val_isValidName(char* nombre);
int val_isValidDni(char* dni);
int val_isValidCuit(char* cuit);
int val_cantidadDigitos(char* arrayParaVerificar);
int val_cuitDigitoVerificador(char* cuit);
int val_isValidEmail(char* email);
int val_isValidTarjeta(char* tarjeta);
int val_isValidTelefono(char* telefono);




#endif /* VALIDATIONS_H_ */
