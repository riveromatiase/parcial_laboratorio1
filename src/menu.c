/*
 * menu.c
 *
 *  Created on: 13 may. 2022
 *      Author: flor_
 */

#include "menu.h"


void menuPrincipal(void){
	puts("\t\t ***************************");
	puts("\t\t*** 1er EXAMEN LAB I- 1 H ***");
	puts("\t\t*****************************");

	puts("1) INGRESAR");
	puts("2) REGISTRARSE\n");
	puts("0) SALIR");
	//get_numeroint(&opcionMenuPrincipal, 2, "Elija una opcion ", "Error, no es un opcion valida\n", 1, 0, 2, 3, 0);
}

void menuUsuario(void){
	puts("\t\t*****************************");
	puts("\t\t*** 1er EXAMEN LAB I- 1 H ***");
	puts("\t\t********** USUARIO **********");
	puts("\t\t*****************************");

	puts("1) COMPRAR");
	puts("2) VENDER");
	puts("3) ESTADO DE COMPRAS");
	puts("4) ESTADO DE VENTAS\n");
	puts("0) SALIR");
//	get_numeroint(&opcionMenuUsuario, 2, "Elija una opcion", "Error, elija opcion valida\n", 1, 0, 4, 3, 0);

}

void menuAdmin(void){
	puts("\t\t*****************************");
	puts("\t\t*** 1er EXAMEN LAB I- 1 H ***");
	puts("\t\t*********** ADMIN ***********");
	puts("\t\t*****************************");

	puts("A) LISTAR ESTADO DE TODOS LOS USUARIOS");
	puts("B) LISTAR TODOS LOS PRODUCTOS POR CATEGORIA");
	puts("C) BAJA DE UN PRODUCTO");
	puts("D) BAJA DE UN USUARIO");
	puts("E) VER TRACKING GLOBAL\n");
	puts("0) SALIR");
//	utn_getChar(&opcionMenuAdmin, "Elija una opcion", "Error, elija opcion valida\n", 'a', 'e', 1);

}


void menu_CategoriasProductos(void){//MENU USUARIO opcion 2) para VENDER
	puts("\t\t*** ELIJA LA CATEGORIA DE SU PRODUCTO ***");
	puts("1) ELECTRODOMESTICOS");
	puts("2) MODA");
	puts("3) TECNOLOGIA");
	puts("4) CONSTRUCCION\n");
	puts("\nopcion ");
//	get_numeroint(&opcionMenuCategoriaProductos, 2, "Elija una opcion de categoria del producto", "Error, no es un opcion valida\n", 1, 0, 4, 3, 0);
}


void menu_EstadoDeVentas(void){

	puts("\t\t*** ESTADOS DE VENTA ***");
	puts("A) LISTADO DE VENTAS FINALIZADAS");
	puts("B) VER PRODUCTOS");

	puts("0) SALIR");
//	utn_getChar(&auxiliarEstadoDeVentas, "Elija una opcion", "Error, elija opcion valida\n", 'a', 'b', 2);

}


void menu_AltaReposicionProductos(void){//MENU USUARIO opcion 2) para VENDER
	puts("\t\t*** ALTA-REPOSICION DE PRODUCTOS ***");
	puts("1) ALTA");
	puts("2) REPOSICION");
	puts("\nopcion ");
//	utn_getNumero(&opcionAltaReponer, mensaje, "Error ingrese una opcion valida", 1, 2, 3);
}

