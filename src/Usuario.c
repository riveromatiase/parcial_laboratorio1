#include "Usuario.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
static int Usuario_idIncremental = 0;


void eUsuario_Inicializar(eUsuario array[], int TAM) {
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

int eUsuario_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Usuario_idIncremental += 1;
}

int eUsuario_ObtenerIndexLibre(eUsuario array[], int TAM) {
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

int eUsuario_BuscarPorID(eUsuario array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idUsuario == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eUsuario_MostrarUno(eUsuario Usuario) {
	//PRINTF DE UN SOLO Usuario
	puts("\n------ USUARIO CARGADOS EN EL SISTEMA ------");
	printf(" ID    CORREO       ESTADO");
	printf("%5d      %5s           %5d\n", Usuario.idUsuario, Usuario.correo, Usuario.isEmpty);
}

int eUsuario_MostrarTodos(eUsuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA

	puts("\n------ USUARIO CARGADOS EN EL SISTEMA ------");
	printf("   ID       CORREO          ESTADO\n");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO || array[i].isEmpty == BAJA) {

				printf("%5d        %5s                  %d\n", array[i].idUsuario, array[i].correo, array[i].isEmpty);
				//MUESTRO UN SOLO Usuario
				//eUsuario_MostrarUno(array[i]);
				//CONTADOR DE Usuario
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Usuario PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eUsuario_MostrarDadosDeBaja(eUsuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Usuario\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Usuario
				eUsuario_MostrarUno(array[i]);
				//CONTADOR DE Usuario
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Usuario PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eUsuario eUsuario_CargarDatos(void) {
	eUsuario auxiliar;
	int auxcodPos;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	if(get_email(auxiliar.correo, "Ingrese el correo con el que quiere registrarse ", "Error, reintente\n", 3)==0){
		if(utn_getCadena(auxiliar.password, 11, "Ingrese una contraseña, la misma no podra ser de mas de 10 digitos ", "Error, reintente\n", 3)==0){
			if(utn_getCadena(auxiliar.direccion, 50, "Ingrese su direccion ", "Error, reintente\n", 3)==0){
				if(utn_getNumero(&auxiliar.codPostal, "Ingrese el Codigo Postal ", "Error, reintente \n", 0, 5000, 3)==0){
					if(get_numeroint(&auxcodPos, 2, "Elija la opcion que corresponda a su categoria\n1)ADMIN\n2)USUARIO\n", "Error, ingrese una opcion valdia\nOpcion: ", 1, 1, 2, 3, 0)==1){
						auxiliar.tipo=auxcodPos;
						puts("La carga de datos fue correcta\n");
					}else{
						puts("Error, no eligio ninguna categoria valida\n");
					}
				}else{
					puts("Error al ingresar el codigo postal\n");
				}
			}else{
				puts("Error al ingresar la direccion\n");
			}
		}else{
			puts("Error al ingresar la contraseña\n");
		}
	}else{
		puts("Error al ingresar el correo electronico\n");
	}

	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */

	return auxiliar;
}

eUsuario eUsuario_ModificarUno(eUsuario Usuario) {
	eUsuario auxiliar = Usuario;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eUsuario_Alta(eUsuario array[], int TAM) {
	int rtn = -1;
	eUsuario auxUsuario;

	//BUSCO ESPACIO EN ARRAY
	int index = eUsuario_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Usuario AUXILIAR
		auxUsuario = eUsuario_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxUsuario.idUsuario = eUsuario_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"-1-
		auxUsuario.isEmpty = 1;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxUsuario;

		//RETORNO 0 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 0;
	}

	return rtn;
}

int eUsuario_Baja(eUsuario array[], int TAM) {
	int rtn = 0;
	int idUsuario;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Usuario
	if (eUsuario_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Usuario DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Usuario PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idUsuario);

		//BUSCO INDEX POR ID EN ARRAY
		while (eUsuario_BuscarPorID(array, TAM, idUsuario) == -1) {
			puts("NO EXISTE ID.");
			
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idUsuario);
		}

		//OBTENGO INDEX DEL ARRAY DE Usuario A DAR DE BAJA
		index = eUsuario_BuscarPorID(array, TAM, idUsuario);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eUsuario_Modificacion(eUsuario array[], int TAM) {
	int rtn = 0;
	int idUsuario;
	int index;
	int flag = 0;
	eUsuario auxiliar;

	//LISTO TODOS LOS Usuario
	if (eUsuario_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Usuario DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Usuario PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idUsuario);

		//BUSCO INDEX POR ID EN ARRAY
		while (eUsuario_BuscarPorID(array, TAM, idUsuario) == -1) {
			puts("NO EXISTE ID.");
			
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idUsuario);
		}

		//OBTENGO INDEX DEL ARRAY DE Usuario A MODIFICAR
		index = eUsuario_BuscarPorID(array, TAM, idUsuario);

		//LLAMO A FUNCION QUE MODIFICA Usuario
		auxiliar = eUsuario_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eUsuario_Sort(eUsuario array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eUsuario aux;

	/** EJEMPLO DE SORT CON ID DE Usuario
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
						if (array[i].idUsuario > array[j].idUsuario) {
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
						if (array[i].idUsuario < array[j].idUsuario) {
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

int eUsuario_verificarEmail(eUsuario array[], int TAM, char *emailIngresado) {
	int rtn = -1;
	int i;


	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL email QUE ESTOY BUSCANDO
			if (array[i].isEmpty == OCUPADO && (strcmp(array[i].correo,emailIngresado)==0))
				{

					rtn=0;
					break;
					}
			}
		}
	return rtn;
}

int eUsuario_verificarContrasena(eUsuario array[], int TAM, char *contrasenaIngresado) {
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY

		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL email QUE ESTOY BUSCANDO

			if (array[i].isEmpty == 1 && strcmp(array[i].password,contrasenaIngresado)==0){
					rtn=0;
					break;
			}
		}
		}
	return rtn;
}

