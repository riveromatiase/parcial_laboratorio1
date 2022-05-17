#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Producto.h"
#include "Usuario.h"


#ifndef ETracking_H_
#define ETracking_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 25
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define EN_VIAJE 5
#define ENTREGADO 6
#define CANCELADO 7

//*** ESTRUCTURA
typedef struct {
	int idTracking;
	short int isEmpty;
	int cantidad;
	int distanciaKM;
	long int horaLlegada;
	float precioAPagar;

	int fk_idUsuarioComprador;
	//int fk_idUsuarioVendedor;
	int fk_idProducto;//PRODUCTO
	int fk_CodPostal;

} eTracking;
//***

/** INICIO CABECERAS DE FUNCION*/
void eTracking_Inicializar(eTracking array[], int TAM);
int eTracking_ObtenerID(void);
int eTracking_ObtenerIndexLibre(eTracking array[], int TAM);
int eTracking_BuscarPorID(eTracking array[], int TAM, int ID);
void eTracking_MostrarUno(eTracking Tracking);
int eTracking_MostrarTodos(eTracking array[], int TAM);
int eTracking_MostrarDadosDeBaja(eTracking array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eTracking_Sort(eTracking array[], int TAM, int criterio);

//ABM
eTracking eTracking_CargarDatos(eTracking array[]);
eTracking eTracking_ModificarUno(eTracking Tracking);
int eTracking_Alta(eTracking array[], int TAM, int cantidadProductoAComprar, float precioAPagar, int idComprador, int idProducto, int CodPostal);
int eTracking_Baja(eTracking array[], int TAM);
int eTracking_Modificacion(eTracking array[], int TAM);

long int eTracking_time_Current();
long int eTracking_time_Add(double secondsAdd);
/** FIN CABECERAS DE FUNCION*/
#endif
