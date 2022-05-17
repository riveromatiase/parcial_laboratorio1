#include "Producto.h"



/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
static int Producto_idIncremental = 100;



void eProducto_Inicializar(eProducto array[], int TAM) {
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

int eProducto_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Producto_idIncremental += 1;
}

int eProducto_ObtenerIndexLibre(eProducto array[], int TAM) {
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

int eProducto_BuscarPorID(eProducto array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idProducto == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eProducto_MostrarUno(eProducto Producto) {
	//PRINTF DE UN SOLO Producto
	//printf("CATEGORIA     NOMBRE_PRODUCTO      PRECIO      STOCK      ID");
	printf("   %5d              %5s              %5.2f        %5d       %5d\n",Producto.categoria, Producto.nombreProducto, Producto.precio, Producto.stock, Producto.idProducto);
}

int eProducto_MostrarTodos(eProducto array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t>***LISTADO DE PRODUCTOS***");
	printf("CATEGORIA          NOMBRE_PRODUCTO         PRECIO          STOCK      ID\n");
	//printf("CATEGORIA%5d NOMBRE%5s PRECIO%5f STOCK%5d ID%5d",array->categoria, array->nombreProducto, array->precio, array->stock, array->idProducto); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				if(array[i].categoria>0 && array[i].categoria<5)
				{
					//MUESTRO UN SOLO Producto
					eProducto_MostrarUno(array[i]);
					//CONTADOR DE Producto
					cantidad++;
				}

			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Producto PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eProducto_MostrarDadosDeBaja(eProducto array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Producto\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Producto
				eProducto_MostrarUno(array[i]);
				//CONTADOR DE Producto
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Producto PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eProducto eProducto_CargarDatos(void) {
	eProducto auxiliar;

	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	get_name(auxiliar.nombreProducto, 25, "Nombre del Producto ", "Error, reintente\n", 3);
	get_numeroint(&auxiliar.stock, 10, "Ingrese el stock disponible ", "Error, reintente\n", 1, 1, 100000, 3, 0);
	get_float(&auxiliar.precio, 9, "Ingrese el precio del producto ", "Error, reintente\n", 1, 0, 999999999, 3, 0);



	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eProducto eProducto_ModificarUno(eProducto Producto) {
	eProducto auxiliar = Producto;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eProducto_Alta(eProducto array[], int TAM) {
	int rtn =-1;
	//eProducto auxProducto;

	//BUSCO ESPACIO EN ARRAY
	int index = eProducto_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		get_name(array[index].nombreProducto, 25, "Nombre del Producto ", "Error, reintente\n", 3);
		get_numeroint(&array[index].stock, 10, "Ingrese el stock disponible ", "Error, reintente\n", 1, 1, 100000, 3, 0);
		get_float(&array[index].precio, 9, "Ingrese el precio del producto ", "Error, reintente\n", 1, 0, 999999999, 3, 0);
		//PIDO DATOS - CARGO Producto AUXILIAR
		//auxProducto = eProducto_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		array[index].idProducto = eProducto_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		array[index].isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		//array[index] = auxProducto;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 0;
		puts("***PRODUCTO DADO DE ALTA CORRECTAMENTE***");
	}

	return rtn;
}

int eProducto_Baja(eProducto array[], int TAM) {
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Producto
	if (eProducto_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Producto PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idProducto);

		//BUSCO INDEX POR ID EN ARRAY
		while (eProducto_BuscarPorID(array, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");
			
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idProducto);
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A DAR DE BAJA
		index = eProducto_BuscarPorID(array, TAM, idProducto);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eProducto_Modificacion(eProducto array[], int TAM) {
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;
	eProducto auxiliar;

	//LISTO TODOS LOS Producto
	if (eProducto_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Producto PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idProducto);

		//BUSCO INDEX POR ID EN ARRAY
		while (eProducto_BuscarPorID(array, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");
			
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idProducto);
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A MODIFICAR
		index = eProducto_BuscarPorID(array, TAM, idProducto);

		//LLAMO A FUNCION QUE MODIFICA Producto
		auxiliar = eProducto_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eProducto_Sort(eProducto array[], int TAM, int criterio) {
	int rtn = -1;//no se pudo porque apunta a NULL
	int i;
	int j;
	eProducto aux;

	/** EJEMPLO DE SORT CON ID DE Producto
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
						if (array[i].categoria > array[j].categoria) {
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
						if (array[i].categoria < array[j].categoria) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 0; //todo ok
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 1;//1 mal ingresado el orden
			break;
		}
	}
	return rtn;
}


int eProducto_OrdenarPorDosCriterios(eProducto arrayProducto[], int TAM)
{
	int respuesta = -1;
	int banderaSwap;
	eProducto buffer;

	if(arrayProducto != NULL)
	{
		if(TAM > 0)
		{
			do
			{
				banderaSwap=0;
				for(int i=0;i<TAM;i++)
				{
					if(arrayProducto[i].isEmpty==OCUPADO)
					{
						if(arrayProducto[i].categoria >0 && arrayProducto[i].categoria <5)
						{
							if(arrayProducto[i].categoria > arrayProducto[i+1].categoria ||
									(strncmp(arrayProducto[i].nombreProducto, arrayProducto[i+1].nombreProducto, MAX_CHARS_CADENAS) ==0 && arrayProducto[i].categoria > arrayProducto[i+1].categoria))
							{
								banderaSwap=1;
								buffer = arrayProducto[i];
								arrayProducto[i]=arrayProducto[i+1];
								arrayProducto[i+1]=buffer;
								respuesta =0;
							}
						}
					}

				}
				TAM--;
			}while(banderaSwap);
		}
	}
	return respuesta;
}

int eProducto_OrdenarPorStock(eProducto array[], int TAM, int criterio) {
	int rtn = -1;//no se pudo porque apunta a NULL
	int i;
	int j;
	eProducto aux;

	/** EJEMPLO DE SORT CON ID DE Producto
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
						if (array[i].stock > array[j].stock) {
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
						if (array[i].categoria < array[j].categoria) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 0; //todo ok
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 1;//1 mal ingresado el orden
			break;
		}
	}
	return rtn;
}
