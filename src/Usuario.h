#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "validations.h"



#ifndef EUsuario_H_
#define EUsuario_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 25
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define ADMIN 1
#define USUARIO 2

//*** ESTRUCTURA
typedef struct {
	int idUsuario;
	short int isEmpty;
	short int tipo;
	char correo[MAX_CHARS_CADENAS];
	char password[10];
	char direccion[50];
	int codPostal;
} eUsuario;
//***

/** INICIO CABECERAS DE FUNCION*/
void eUsuario_Inicializar(eUsuario array[], int TAM);
int eUsuario_ObtenerID(void);
int eUsuario_ObtenerIndexLibre(eUsuario array[], int TAM);
int eUsuario_BuscarPorID(eUsuario array[], int TAM, int ID);
void eUsuario_MostrarUno(eUsuario Usuario);
int eUsuario_MostrarTodos(eUsuario array[], int TAM);
int eUsuario_MostrarDadosDeBaja(eUsuario array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eUsuario_Sort(eUsuario array[], int TAM, int criterio);

//ABM
eUsuario eUsuario_CargarDatos(void);
eUsuario eUsuario_ModificarUno(eUsuario Usuario);
int eUsuario_Alta(eUsuario array[], int TAM);
int eUsuario_Baja(eUsuario array[], int TAM);
int eUsuario_Modificacion(eUsuario array[], int TAM);

int eUsuario_verificarEmail(eUsuario array[], int TAM, char *emailIngresado);
int eUsuario_verificarContrasena(eUsuario array[], int TAM, char *contrasenaIngresado);

/** FIN CABECERAS DE FUNCION*/
#endif
