#include "Relaciones.h"



int uRelaciones_informarEstadoDeEnvios(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking, int indexUsuarioLogueado){
	int retorno =-1;
	long int auxHoraActual;
	double diferenciaEntreHoras;
	int j=0;
	int auxid;
	char opcion;
		for(j=0;j<TAM_usuario;j++)
		{
			if(arrayUsuario!=NULL && arrayProducto != NULL && arrayTracking != NULL){
					if(arrayUsuario[indexUsuarioLogueado].idUsuario == arrayTracking[j].fk_idUsuarioComprador){
						printf("Hora de tracking %ld \n", arrayTracking[j].horaLlegada);
						auxHoraActual=eTracking_time_Current();

						diferenciaEntreHoras= difftime(auxHoraActual, arrayTracking[j].horaLlegada);
						printf("diferencia hora de llegada %f\n",diferenciaEntreHoras);
						if( diferenciaEntreHoras >=0){
							puts("\n*** LISTADO ACTUALIZADO DE LOS PRODUCTOS COMPRADOS");
							//eTracking_Modificacion(arrayTracking, TAM_tracking);
							arrayTracking[j].isEmpty=ENTREGADO;
							printf("PRODUCTO      CANTIDAD      VENDEDOR     ESTADO DE ENVIO    ID_ENVIO   HORA DE LLEGADA\n");
							printf("%s             %d             %d             %d                %d         %ld\n",arrayProducto->nombreProducto, arrayTracking->cantidad, arrayTracking->fk_idUsuarioComprador, arrayTracking->isEmpty,arrayTracking->idTracking ,arrayTracking->horaLlegada);
					}else{
						puts("\n*** LISTADO ACTUALIZADO DE LOS PRODUCTOS COMPRADOS");
						printf("PRODUCTO      CANTIDAD      VENDEDOR     ESTADO DE ENVIO    ID_ENVIO   HORA DE LLEGADA\n");
						printf("%s             %d             %d             %d                  %d       %ld\n",arrayProducto->nombreProducto, arrayTracking->cantidad, arrayTracking->fk_idUsuarioComprador, arrayTracking->isEmpty, arrayTracking->idTracking , arrayTracking->horaLlegada);
					puts("Si desea puede cancelar un pedido que su ESTADO DE ENVIO sea 5");
					if(utn_getNumero(&auxid, "Ingrese el id que desea CANCELAR\n", "Error, reintente\n", 100, 110, 30)==0){
						if(auxid == arrayTracking->idTracking){
							if(utn_getChar(&opcion, "Para confirmar la cancelacion del envio ingrese 'S' \n", "Opcion invalida, para confirmar ingrese 'S'\n", 's', 's', 2)==0){
								arrayTracking->isEmpty=CANCELADO;
								puts("*** LA CANCELACION DEL ENVIO SE REALIZO CON EXITO ***\n");
							}

						}
					}else{
						puts("** NO SE REALIZO LA CANCELACION DEL ENVIO **");
					}

					}

			}
		}
		}



return retorno;
}


/**
 * printf("PRODUCTO      CANTIDAD      VENDEDOR     ESTADO DE ENVIO       HORA DE LLEGADA\n");
   printf("%s             %d             %d             %d                     %ld",arrayProducto->nombreProducto, arrayTracking->cantidad, arrayTracking->fk_idUsuarioComprador, arrayTracking->isEmpty, arrayTracking->horaLlegada);

 *
 */


int uRelaciones_informarEstadoDeVentas(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking, int indexUsuarioLogueado){
	int retorno =-1;
	for(int j=0;j<TAM_usuario;j++)
	{
		for(int i=0; i<TAM_tracking;i++){
			if(arrayUsuario!=NULL && arrayProducto != NULL && arrayTracking != NULL){
				if(arrayTracking[j].isEmpty ==5 || arrayTracking[j].isEmpty ==6 || arrayTracking[j].isEmpty ==7){
					uRelaciones_DiferenciaEntreHoras(arrayTracking[j].horaLlegada);
				}
			}
		}
	}


	for(int j=0;j<TAM_usuario;j++)
	{
		if(arrayUsuario!=NULL && arrayProducto != NULL && arrayTracking != NULL){
			if(arrayUsuario[indexUsuarioLogueado].idUsuario == arrayProducto[j].Fk_idUsuarioVendedor){
				if(arrayProducto[j].isEmpty ==6 || arrayProducto[j].isEmpty == 7){
					puts("\n*** LISTADO ACTUALIZADO ESTADO DE VENTAS ***\n");
					printf("PRODUCTO      CANTIDAD      ESTADO DE ENVIO    ID_ENVIO   HORA DE LLEGADA\n");
					printf("  %s             %d          -*  %d  *-            %d         %ld\n",arrayProducto->nombreProducto, arrayTracking->cantidad, arrayTracking->isEmpty, arrayTracking->idTracking , arrayTracking->horaLlegada);
				retorno=0;
				}

			}
		}
	}
	if(retorno==-1){
		puts("\n*** EL USUARIO NO TIENE PRODUCTO EN VENTA - FINALIZADOS ***\n");
	}
	return retorno;
}


double uRelaciones_DiferenciaEntreHoras(long int horallegada)
{
	double diferenciaEntreHoras=-1;
	long int auxHoraActual=eTracking_time_Current();

	diferenciaEntreHoras=difftime(auxHoraActual, horallegada);

	return diferenciaEntreHoras;
}




int uRelaciones_VerTodosLosProductos(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking, int indexUsuarioLogueado){
	int retorno =-1;

	for(int i=0; i<=TAM_producto;i++){
		if(arrayUsuario[indexUsuarioLogueado].idUsuario == arrayProducto[i].Fk_idUsuarioVendedor){
			if(arrayProducto[i].stock>0){
				puts("\n*** LISTADO PRODUCTOS A LA VENTA ***\n");
				printf("PRODUCTO      CANTIDAD         VENDEDOR\n");
				printf("  %s             %d               %d\n",arrayProducto->nombreProducto, arrayTracking->cantidad, arrayUsuario[indexUsuarioLogueado].idUsuario);
				retorno =0;
			}
		}
	}
	if(retorno==-1){
		puts("\n*** EL USUARIO NO TIENE PRODUCTO A LA VENTA  ***\n");
	}

	return retorno;
}










int uRelaciones_CargaForzada(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking){
	int retorno= -1;
	long int horaLlegadaPedido;
	// INDEX 0
	arrayUsuario[0].idUsuario=eUsuario_ObtenerID();
	strcpy(arrayUsuario[0].correo, "mati@gmail.com");
	strcpy(arrayUsuario[0].password, "0902");
	strcpy(arrayUsuario[0].direccion, "San juan 2139");
	arrayUsuario[0].codPostal=10;
	arrayUsuario[0].tipo=USUARIO;
	arrayUsuario[0].isEmpty=OCUPADO;
	//INDEX 1
	arrayUsuario[1].idUsuario=eUsuario_ObtenerID();
	strcpy(arrayUsuario[1].correo, "flor@gmail.com");
	strcpy(arrayUsuario[1].password, "2504");
	strcpy(arrayUsuario[1].direccion, "Humberto 500");
	arrayUsuario[1].codPostal=1240;
	arrayUsuario[1].tipo=USUARIO;
	arrayUsuario[1].isEmpty=OCUPADO;
	//INDEX 2 USUARIO
	arrayUsuario[2].idUsuario=eUsuario_ObtenerID();
	strcpy(arrayUsuario[2].correo, "martu@gmail.com");
	strcpy(arrayUsuario[2].password, "2005");
	strcpy(arrayUsuario[2].direccion, "chile 566");
	arrayUsuario[2].codPostal=3600;
	arrayUsuario[2].tipo=1;
	arrayUsuario[2].isEmpty=OCUPADO;
	//INDEX 3 USUARIO
	arrayUsuario[3].idUsuario=eUsuario_ObtenerID();
	strcpy(arrayUsuario[3].correo, "jose@gmail.com");
	strcpy(arrayUsuario[3].password, "0310");
	strcpy(arrayUsuario[3].direccion, "La rioja 520");
	arrayUsuario[3].codPostal=1221;
	arrayUsuario[3].tipo=USUARIO;
	arrayUsuario[3].isEmpty=OCUPADO;
	//INDEX 4 USUARIO
	arrayUsuario[4].idUsuario=eUsuario_ObtenerID();
	strcpy(arrayUsuario[4].correo, "carmen@gmail.com");
	strcpy(arrayUsuario[4].password, "1607");
	strcpy(arrayUsuario[4].direccion, "Venezuela 2890");
	arrayUsuario[0].codPostal=4900;
	arrayUsuario[4].tipo=ADMIN;
	arrayUsuario[4].isEmpty=OCUPADO;


	//PRODUCTO
	arrayProducto[0].idProducto=eProducto_ObtenerID();
	strcpy(arrayProducto[0].nombreProducto, "Celular");
	arrayProducto[0].precio=899.90;
	arrayProducto[0].categoria=TECNOLOGIA;
	arrayProducto[0].Fk_idUsuarioVendedor=1;
	arrayProducto[0].isEmpty=OCUPADO;
	arrayProducto[0].stock=10;
	//PRODUCTO
	arrayProducto[1].idProducto=eProducto_ObtenerID();
	strcpy(arrayProducto[1].nombreProducto, "Campera");
	arrayProducto[1].precio=750;
	arrayProducto[1].categoria=MODA;
	arrayProducto[1].Fk_idUsuarioVendedor=1;
	arrayProducto[1].isEmpty=OCUPADO;
	arrayProducto[1].stock=3;
	//PRODUCTO
	arrayProducto[2].idProducto=eProducto_ObtenerID();
	strcpy(arrayProducto[2].nombreProducto, "Termo");
	arrayProducto[2].precio=500;
	arrayProducto[2].categoria=ELECTRODOMESTICOS;
	arrayProducto[2].Fk_idUsuarioVendedor=3;
	arrayProducto[2].isEmpty=OCUPADO;
	arrayProducto[2].stock=5;
	//PRODUCTO
	arrayProducto[3].idProducto=eProducto_ObtenerID();
	strcpy(arrayProducto[3].nombreProducto, "Batidora");
	arrayProducto[3].precio=1299.99;
	arrayProducto[3].categoria=ELECTRODOMESTICOS;
	arrayProducto[3].Fk_idUsuarioVendedor=4;
	arrayProducto[3].isEmpty=OCUPADO;
	arrayProducto[3].stock=6;


//TRACKING
	arrayTracking[0].idTracking=eTracking_ObtenerID();
	arrayTracking[0].fk_idProducto=100;
	arrayTracking[0].fk_idUsuarioComprador=3;
	arrayTracking[0].cantidad=1;//ESTA CANTIDAD SE TIENE QUE RESTAR AL STOCK DE PRODUCTO
	arrayTracking[0].precioAPagar=899.90;
	arrayTracking[0].fk_CodPostal=3600;
	arrayTracking[0].isEmpty=EN_VIAJE;
	arrayTracking[0].distanciaKM=30;
	horaLlegadaPedido=eTracking_time_Add(60);
	arrayTracking[0].horaLlegada=horaLlegadaPedido;
//TRACKING
	arrayTracking[1].idTracking=eTracking_ObtenerID();
	arrayTracking[1].fk_idProducto=104;
	arrayTracking[1].fk_idUsuarioComprador=2;
	arrayTracking[1].fk_CodPostal=1240;
	arrayTracking[1].cantidad=1;
	arrayTracking[1].precioAPagar=1299.99;
	arrayTracking[1].isEmpty=EN_VIAJE;
	arrayTracking[1].distanciaKM=20;
	horaLlegadaPedido=eTracking_time_Add(40);
	arrayTracking[1].horaLlegada=horaLlegadaPedido;
	//TRACKING
	arrayTracking[2].idTracking=eTracking_ObtenerID();
	arrayTracking[2].fk_idProducto=102;
	arrayTracking[2].fk_idUsuarioComprador=5;
	arrayTracking[2].fk_CodPostal=4900;
	arrayTracking[2].cantidad=2;
	arrayTracking[1].precioAPagar=1000;
	arrayTracking[2].isEmpty=EN_VIAJE;
	arrayTracking[2].distanciaKM=50;
	horaLlegadaPedido=eTracking_time_Add(100);
	arrayTracking[2].horaLlegada=horaLlegadaPedido;

	puts("\t*** El harcodeo de datos inicial se realizo con exito! ***\n\n");
	retorno =0;
	return retorno;
}


int uRelaciones_EstadoUsuarios(eUsuario arrayUsuario[], int TAM_usuario){
	int retorno=-1;
	eUsuario_MostrarTodos(arrayUsuario, TAM_usuario);

	return retorno;
}



int uRelaciones_ProductosPorCategoria(eProducto arrayProducto[], int TAM_producto){
int retorno=-1;
puts("\n*** LISTADO PRODUCTOS POR CATEGORIA ***\n");
printf("CATEGORIA      NOMBRE         VENDEDOR\n");
if(arrayProducto!=NULL && TAM_producto>0)
{
	eProducto_OrdenarPorDosCriterios(arrayProducto, TAM_producto);
	for(int i=0;i<=TAM_producto; i++){
		if(arrayProducto[i].stock>0 && arrayProducto[i].isEmpty==1){
			if(arrayProducto[i].categoria >0 && arrayProducto[i].categoria <5)
			{

				printf("  %d             %s               %d\n",arrayProducto[i].categoria, arrayProducto[i].nombreProducto, arrayProducto[i].Fk_idUsuarioVendedor);
				retorno =0;
			}
		}

	}
}


return retorno;
}




int uRelaciones_ProductosParaDarDeBaja(eProducto arrayProducto[], int TAM_producto){
int retorno=-1;
int opcionIDBaja;
int indexProductoBaja;
char opcionConfirmacion;
puts("\n*** LISTADO PRODUCTOS ACTIVOS ***\n");
printf("CATEGORIA      NOMBRE        ID\n");
if(arrayProducto!=NULL && TAM_producto>0)
{
	eProducto_OrdenarPorDosCriterios(arrayProducto, TAM_producto);
	for(int i=0;i<=TAM_producto; i++){
		if(arrayProducto[i].stock>0 && arrayProducto[i].isEmpty==1){
			if(arrayProducto[i].categoria >0 && arrayProducto[i].categoria <5)
			{

				printf("  %d             %s               %d\n",arrayProducto[i].categoria, arrayProducto[i].nombreProducto, arrayProducto[i].idProducto);
				retorno =0;
			}
		}

	}
}
if(retorno==0){
	utn_getNumero(&opcionIDBaja, "De los ID mostrados en pantalla seleccione cual quiere dear de baja\n", "Error, ID ingresado inexistente\n", 100, 120, 2);
//	get_numeroint(&opcionIDBaja, 3, "De los ID mostrados en pantalla seleccione cual quiere dear de baja\n", "Error, ID ingresado inexistente\n", 0, 100, 120, 3, 0);
		if((indexProductoBaja=eProducto_BuscarPorID(arrayProducto, TAM_producto, opcionIDBaja)) >=0){
			utn_getChar(&opcionConfirmacion, "Seleccione 'S' para confirmar la baja del ID", "Error, la opcion ingresada no es valida", 's', 's', 3);
			if(opcionConfirmacion=='s' || opcionConfirmacion=='S'){
				arrayProducto[indexProductoBaja].isEmpty=-1;
				puts("*** EL ID FUE DADO DE BAJA ***");
			}
		}


}
return retorno;
}




int uRelaciones_UsuariosParaDarDeBaja(eUsuario arrayUsuario[], int TAM_usuario){
int retorno=-1;
int opcionIDBaja;
int indexUsuarioBaja;
char opcionConfirmacion;
puts("\n*** LISTADO USUARIOS ACTIVOS ***\n");
printf("CATEGORIA      CORREO                      ID\n");
if(arrayUsuario!=NULL && TAM_usuario>0)
{
	for(int i=0;i<=TAM_usuario; i++){
		if(arrayUsuario[i].isEmpty==1){

			printf("  %d             %s             %d\n",arrayUsuario[i].tipo, arrayUsuario[i].correo, arrayUsuario[i].idUsuario);
			retorno =0;

		}

	}
}
if(retorno==0){
	utn_getNumero(&opcionIDBaja, "De los ID mostrados en pantalla seleccione cual quiere dear de baja\n", "Error, ID ingresado inexistente\n", 0, 20, 2);
//	get_numeroint(&opcionIDBaja, 3, "De los ID mostrados en pantalla seleccione cual quiere dear de baja\n", "Error, ID ingresado inexistente\n", 0, 100, 120, 3, 0);
		if((indexUsuarioBaja=eUsuario_BuscarPorID(arrayUsuario, TAM_usuario, opcionIDBaja))==0)
				{
			utn_getChar(&opcionConfirmacion, "Seleccione 'S' para confirmar la baja del ID", "Error, la opcion ingresada no es valida", 's', 's', 3);

			if(opcionConfirmacion=='s' || opcionConfirmacion=='S'){
				arrayUsuario[indexUsuarioBaja].isEmpty=-1;
				puts("*** EL ID FUE DADO DE BAJA ***");
			}
		}
		}

return retorno;
}


int uRelaciones_TrackingGlobal(eUsuario arrayUsuario[], int TAM_usuario, eProducto arrayProducto[], int TAM_producto, eTracking arrayTracking[], int TAM_tracking){
	int retorno=-1;
	int j=0;
	int i=0;
	int a=0;
	puts("\t\n*** TRACKING GLOBAL ***\n");
	printf("ID tracking      Estado de envio         ID COMPRADOR       ID VENDEDOR\n");

	//printf("%   1d                %1d                    %1d                  %1d\n",arrayTracking[j].idTracking, arrayTracking[j].isEmpty, arrayTracking[j].fk_idUsuarioComprador, arrayProducto[i].Fk_idUsuarioVendedor);

	for(j=0;j<=TAM_tracking;j++){

		for(i=0;i<=TAM_producto;i++){

			while((arrayTracking[j].fk_idProducto - arrayProducto[i].idProducto)==0 &&a==0){
			printf("%i                   %d                    %i                  %i\n",arrayTracking[j].idTracking, arrayTracking[j].isEmpty, arrayTracking[j].fk_idUsuarioComprador, arrayProducto[i].Fk_idUsuarioVendedor);
			a++;
			}
		}
		}


	return retorno;
}
