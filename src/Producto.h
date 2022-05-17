#ifndef EProducto_H_
#define EProducto_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Usuario.h"
#include "gets.h"
#include "validations.h"

//*** DEFINE
#define MAX_CHARS_CADENAS 25
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define MODA 2
#define TECNOLOGIA 3
#define CONSTRUCCION 4
#define ELECTRODOMESTICOS 1

//*** ESTRUCTURA
typedef struct {
	int idProducto;
	short int isEmpty;
	int Fk_idUsuarioVendedor;
	char nombreProducto[MAX_CHARS_CADENAS];
	float precio;
	short int categoria;
	int stock;

} eProducto;
//***

/** INICIO CABECERAS DE FUNCION*/
void eProducto_Inicializar(eProducto array[], int TAM);
int eProducto_ObtenerID(void);
int eProducto_ObtenerIndexLibre(eProducto array[], int TAM);
int eProducto_BuscarPorID(eProducto array[], int TAM, int ID);
void eProducto_MostrarUno(eProducto Producto);
int eProducto_MostrarTodos(eProducto array[], int TAM);
int eProducto_MostrarDadosDeBaja(eProducto array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eProducto_Sort(eProducto array[], int TAM, int criterio);
int eProducto_OrdenarPorDosCriterios(eProducto arrayProducto[], int TAM);
//ABM
eProducto eProducto_CargarDatos(void);
eProducto eProducto_ModificarUno(eProducto Producto);
int eProducto_Alta(eProducto array[], int TAM);
int eProducto_Baja(eProducto array[], int TAM);
int eProducto_Modificacion(eProducto array[], int TAM);
int eProducto_OrdenarPorStock(eProducto array[], int TAM, int criterio);

/** FIN CABECERAS DE FUNCION*/
#endif
