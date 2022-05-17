#include "Tracking.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
static int Tracking_idIncremental = 1000;

void eTracking_Inicializar(eTracking array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eTracking_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Tracking_idIncremental += 1;
}

int eTracking_ObtenerIndexLibre(eTracking array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eTracking_BuscarPorID(eTracking array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idTracking == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eTracking_MostrarUno(eTracking Tracking) {
	//PRINTF DE UN SOLO Tracking
	printf("%5d\n", Tracking.idTracking);
}

int eTracking_MostrarTodos(eTracking array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Tracking");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Tracking
				eTracking_MostrarUno(array[i]);
				//CONTADOR DE Tracking
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Tracking PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eTracking_MostrarDadosDeBaja(eTracking array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Tracking\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Tracking
				eTracking_MostrarUno(array[i]);
				//CONTADOR DE Tracking
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Tracking PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}




eTracking eTracking_ModificarUno(eTracking Tracking) {
	eTracking auxiliar = Tracking;
	Tracking.isEmpty=ENTREGADO;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eTracking_Alta(eTracking array[], int TAM, int cantidadProductoAComprar, float precioAPagar, int idComprador, int idProducto, int CodPostal) {
	int rtn = 0;
	//eTracking auxTracking;

	//BUSCO ESPACIO EN ARRAY
	int index = eTracking_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {

		//PIDO DATOS - CARGO Tracking AUXILIAR
		array[index].cantidad = cantidadProductoAComprar;
		array[index].precioAPagar=precioAPagar;
		array[index].fk_idUsuarioComprador=idComprador;
		array[index].fk_idProducto=idProducto;
		array[index].fk_CodPostal=CodPostal;
		if(array[index].fk_CodPostal>8000)
		{
			array[index].distanciaKM=150;
			array[index].horaLlegada=eTracking_time_Add(300);
		}else{
			if(array[index].fk_CodPostal>5000){
				array[index].distanciaKM=80;
				array[index].horaLlegada=eTracking_time_Add(160);
			}else{
				if(array[index].fk_CodPostal>3000){
					array[index].distanciaKM=50;
					array[index].horaLlegada=eTracking_time_Add(100);
				}else{
					if(array[index].fk_CodPostal>1000){
						array[index].distanciaKM=30;
						array[index].horaLlegada=eTracking_time_Add(60);
					}else{
						array[index].distanciaKM=20;
						array[index].horaLlegada=eTracking_time_Add(40);

					}
				}
			}
		}

		//auxTracking = eTracking_CargarDatos(array);
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		array[index].idTracking = eTracking_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		array[index].isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		//array[index] = auxTracking;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eTracking_Baja(eTracking array[], int TAM) {
	int rtn = 0;
	int idTracking;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Tracking
	if (eTracking_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Tracking DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Tracking PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idTracking);

		//BUSCO INDEX POR ID EN ARRAY
		while (eTracking_BuscarPorID(array, TAM, idTracking) == -1) {
			puts("NO EXISTE ID.");
			
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idTracking);
		}

		//OBTENGO INDEX DEL ARRAY DE Tracking A DAR DE BAJA
		index = eTracking_BuscarPorID(array, TAM, idTracking);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eTracking_Modificacion(eTracking array[], int TAM) {
	int rtn = 0;
	int idTracking;
	int index;
	int flag = 0;
	eTracking auxiliar;

	//LISTO TODOS LOS Tracking
	if (eTracking_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Tracking DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Tracking PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idTracking);

		//BUSCO INDEX POR ID EN ARRAY
		while (eTracking_BuscarPorID(array, TAM, idTracking) == -1) {
			puts("NO EXISTE ID.");
			
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idTracking);
		}

		//OBTENGO INDEX DEL ARRAY DE Tracking A MODIFICAR
		index = eTracking_BuscarPorID(array, TAM, idTracking);

		//LLAMO A FUNCION QUE MODIFICA Tracking
		auxiliar = eTracking_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eTracking_Sort(eTracking array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eTracking aux;

	/** EJEMPLO DE SORT CON ID DE Tracking
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO 
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idTracking > array[j].idTracking) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idTracking < array[j].idTracking) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}


long int eTracking_time_Current(){
	return time(NULL);
}
long int eTracking_time_Add(double secondsAdd){
		return secondsAdd + eTracking_time_Current();
	}
