

#ifndef RELACIONES_H_
#define RELACIONES_H_
#include "Usuario.h"
#include "Producto.h"
#include "Tracking.h"
#include "Menu.h"
#include <time.h>
#include <string.h>


int uRelaciones_AltaProducto(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking);

int uRelaciones_CargaForzada(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking);
int uRelaciones_informarEstadoDeEnvios(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking, int indexUsuarioLogueado);
int uRelaciones_informarEstadoDeVentas(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking, int indexUsuarioLogueado);
int uRelaciones_VerTodosLosProductos(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking, int indexUsuarioLogueado);
double uRelaciones_DiferenciaEntreHoras(long int horallegada);

void menu_ReposicionProductos(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, int indexUsuarioLogueado);
void menu_RelacionesBuscarPorNombre(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, char nombreProducto);

int uRelaciones_EstadoUsuarios(eUsuario arrayUsuario[], int TAM_usuario);
int uRelaciones_ProductosPorCategoria(eProducto arrayProducto[], int TAM_producto);
int uRelaciones_ProductosParaDarDeBaja(eProducto arrayProducto[], int TAM_producto);
int uRelaciones_UsuariosParaDarDeBaja(eUsuario arrayUsuario[], int TAM_usuario);
int uRelaciones_TrackingGlobal(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking);
#endif /* RELACIONES_H_ */
