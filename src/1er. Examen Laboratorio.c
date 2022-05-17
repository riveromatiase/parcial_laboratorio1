#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "gets.h"
#include "Relaciones.h"
#include "matematicas.h"
#include "Tracking.h"

#define ADMIN 1
#define USUARIO 2

#define CANT_PROD 10000
#define CANT_USU 2000
#define CANT_ENVIOS 4500

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define ELECTRODOMESTICOS 1
#define MODA 2
#define TECNOLOGIA 3
#define CONSTRUCCION 4

#define EN_VIAJE 5
#define ENTREGADO 6
#define CANCELADO 7

int main(void) {
	setbuf(stdout, NULL);

	eProducto producto[CANT_PROD];
	eUsuario usuario[CANT_USU];
	eTracking envio[CANT_ENVIOS];

uRelaciones_CargaForzada(usuario, CANT_USU, producto, CANT_PROD, envio, CANT_ENVIOS);


	char auxiliarEmail[25];
	char auxiliarcpassword[10];
	int opcionMenuPrincipal;
    int opcionMenuUsuario;
    char opcionMenuAdmin;
    int opcionMenuCategoriaProductos;
    int idProductoAComprar;
    int cantidadProductoAComprar;
    float precioAPagar;
    int indexUsuarioLogueado;
    int indexProductoSeleccionado;
    char auxiliarEstadoDeVentas;


	do{
		menuPrincipal();
		get_numeroint(&opcionMenuPrincipal, 2, "Elija una opcion ", "Error, no es un opcion valida\n", 1, 0, 2, 3, 0);

		switch(opcionMenuPrincipal){
		case 1:
			puts("\t***** INICIO DE SESION *****");
			get_email(auxiliarEmail, "Ingrese el email resgistrado", "Error, vuelva a intertarlo", 2);
			if(eUsuario_verificarEmail(usuario, CANT_USU, auxiliarEmail)==0)
			{
				puts("El usuario ingresado es correcto");
				utn_getCadena(auxiliarcpassword, 10, "Ingrese su contraseña", "Error vuelva a intentarlo", 2);
				if(eUsuario_verificarContrasena(usuario, CANT_USU, auxiliarcpassword)==0)
				{
					puts("Contraseña correcta!!!");
					for(int i=0;i<=CANT_USU;i++)
					{
						if((strcmp(usuario[i].correo, auxiliarEmail)==0) && (strcmp(usuario[i].password, auxiliarcpassword)==0)){
							indexUsuarioLogueado=i;
							printf("index usuario %d", indexUsuarioLogueado);
						}
					}

					if(usuario[indexUsuarioLogueado].tipo==ADMIN){
						menuAdmin();
						utn_getChar(&opcionMenuAdmin, "Elija una opcion", "Error, elija opcion valida\n", 'a', 'e', 1);
						switch(opcionMenuAdmin)
						{
						case 'a':
							uRelaciones_EstadoUsuarios(usuario, CANT_USU);
						break;
						case 'b':
							uRelaciones_ProductosPorCategoria(producto, CANT_PROD);
						break;
						case 'c':
							uRelaciones_ProductosParaDarDeBaja(producto, CANT_PROD);

						break;
						case 'd':
							uRelaciones_UsuariosParaDarDeBaja(usuario, CANT_USU);
						break;
						case 'e':
							uRelaciones_TrackingGlobal(usuario, CANT_USU, producto, CANT_PROD, envio, CANT_ENVIOS);
						break;
						}//fin switch opcion MENU ADMIN
					}else{
						menuUsuario();
						get_numeroint(&opcionMenuUsuario, 2, "Elija una opcion", "Error, elija opcion valida\n", 1, 0, 4, 3, 0);

						switch(opcionMenuUsuario)
						{
						case 1://COMPRAR -mostrar la lista de todos los productos por categoria
							eProducto_Sort(producto, CANT_PROD, 1);
							eProducto_MostrarTodos(producto, CANT_PROD);// LISTAR PRODUCTOS AY DESPUES PIDE EL ID
							get_numeroint(&idProductoAComprar, 4, "Ingrese el numero de ID del Producto que desea comprar", "Error, ingrese un ID de la lista", 1, 100, 120, 3, 0);


							for (int i = 0; i<=CANT_PROD; i++){
								while(producto[i].idProducto == idProductoAComprar){
									indexProductoSeleccionado=i;
									break;
								}
							}
							get_numeroint(&cantidadProductoAComprar, 4, "Ingrese la cantidad de unidades que desea comprar", "Cantidad invalidad", 1, 1, producto->stock, 3, 0);

							if(producto[indexProductoSeleccionado].stock-cantidadProductoAComprar>=0)
							{
								puts("Hay stock suficiente para que pueda realizar la compra");
							}
							else{
								puts("\n  -.- lo sentimos! La cantidad que desea adquidir no la poseemos en stock   -.-\n");
								printf("\nEn stock tenemos %d unidades del producto seleccionado", producto[indexProductoSeleccionado].stock);
								get_numeroint(&cantidadProductoAComprar, 4, "Ingrese la cantidad de unidades que desea comprar", "Cantidad invalidad", 1, 1, producto->stock, 3, 0);
							}
							if(producto[indexProductoSeleccionado].stock - cantidadProductoAComprar>=0){

								precioAPagar = producto[indexProductoSeleccionado].precio * cantidadProductoAComprar;
								printf("\nDebera abonar $%.2f por los productos comprados\n\n",precioAPagar);

								puts("*** Vamos a generar el pedido de envio ***");
								producto[indexProductoSeleccionado].stock=producto[indexProductoSeleccionado].stock - cantidadProductoAComprar;
									if(eTracking_Alta(envio, CANT_ENVIOS,cantidadProductoAComprar, precioAPagar, usuario->idUsuario, producto->idProducto, usuario->codPostal)==1){
										//puts("*** EL ENVIO FUE PROGRAMADO CON EXITO ***\n");
										//printf("el envio llegar %ld\n\n",envio->horaLlegada);
									}else{
										puts("*** NO SE PUDO CARGAR LA COMPRA. LO SENTIMOS\n");

									}
							}

							break;
						case 2://vender alta producto
							menu_CategoriasProductos();
							get_numeroint(&opcionMenuCategoriaProductos, 2, "Elija una opcion de categoria del producto", "Error, no es un opcion valida\n", 1, 0, 4, 3, 0);
							eProducto_Alta(producto, CANT_PROD);
							puts("*** EL PRODUCTO FUE DADO DE ALTA, YA SE ENCUENTRA DISPONIBLE ***\n");

							break;
						case 3:
							uRelaciones_informarEstadoDeEnvios(usuario, CANT_USU, producto, CANT_PROD, envio, CANT_ENVIOS, indexUsuarioLogueado);
							break;
						case 4:
							menu_EstadoDeVentas();
							utn_getChar(&auxiliarEstadoDeVentas, "Elija una opcion", "Error, elija opcion valida\n", 'a', 'b', 2);
							switch (auxiliarEstadoDeVentas)
							{
							case 'a':
								uRelaciones_informarEstadoDeVentas(usuario, CANT_USU, producto, CANT_PROD, envio, CANT_ENVIOS, indexUsuarioLogueado);
								break;
							case 'b':
								uRelaciones_VerTodosLosProductos(usuario, CANT_USU, producto, CANT_PROD, envio, CANT_ENVIOS, indexUsuarioLogueado);
								break;
							}//fin switch estado de ventas case 4
							break;
						}//fin switch menu usuario
					}

//MOSTAR EL MENU DEPENDIENDO SI ES USUARIO O ADMINISTRADOR
				}else{
					puts("Contraseña invalida\n");
			}
			}else{
				puts("el correo ingresado es invalido\n");
			}

			break;
		case 2:
			puts("\t***** ALTA DE USUARIO *****");
			if(eUsuario_Alta(usuario, CANT_USU)==0)
			{
				puts("Usuario dado de alta correctamente!\n");
			}
            //break;
		}


	}while(opcionMenuPrincipal!=0);//fin DoWhile principal

	return EXIT_SUCCESS;
}
