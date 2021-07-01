/* PROGRAMA: Compras.c
	AUTOR(ES): 
	Fernández Ortiz Valeria Lizette
	Francisco Arellano Herdson Josue 
	López Alejaldre Daniela Viridiana
	Segura Ríos Brenda Stephanie
	Varas Dayren Sarahi
	EQUIPO: SkyNet
	OBJETIVO: Juntar las funciones para realizar las operaciones correspondientes con las compras.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ULTIMA ACTUALIZACIÓN:
*/

//Constantes
#define MAX_COMPRAS 300

//Tipos
typedef struct {
	int eDia, eMes, eAnio;
}TrFechaCom;

/*typedef enum {
	ALIMENTOS = 1, BOTICA, MEDICAMENTOS, PERFUMES  
}TeTipo; */

typedef char TaCadena [50];

typedef struct {	
	TaCadena cNombre; //Nombre del artículo de tipo cadena.
	int eIdCompra, eIdArticulo, eIdProveedor; 
	int ePzasCompradas; //Variables de piezas compradas. 
	TrFechaCom rFCompra; //Variable para almacenar fechas de compra. 
	TeTipo eTipo; //Variable para clasificar artículos según su tipo.
	float fCostoUnit; //Variables para almacenar el costo unitario de los artículos.		
}TrCompra;

typedef TrCompra TaCompras[MAX_COMPRAS]; //Declaración de un arreglo que contiene varios registros de artículos. 

//PROTOTIPOS
TrCompra LeerCompra();
void RegistrarCompra(TaCompras, int *, TrCompra);
int BuscarCompraPorId(TaCompras, int, int);
int GenerarIdCompra();
void ObtenerTipo(int, TaCadena);
int LeerIdCompra(TaCadena, int, int); 
void MostrarDatosCompra(TrCompra);//Revisar
void ConsultarCompraPorId(TaCompras, int, int);
//void CancelarCompra(TaCompras, int, int);
//void ListarArticulos();
void MenuCompras();

/* FUNCIÓN: MenúCompras.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 10 de junio del 2019 por: López A. Daniela Viridiana.
	OBJETIVO: Crear el diseño de la aplicación del sistema (sub-menú Compras).
	DE(PE): Ninguno.
	DS(PS): Número entero, positivo. 
	Retorna: Un número entero, positivo correspondiente al resultado de la opción seleccionada (eOpcionC)

*/

void MenuCompras() { 
    
    int eOpcionC, eOpcionV, eIdCompra, eIdVenta, eUltimoId, eTotal;//Variable que permitirá el manejo de la opción seleccionada dentro del sub-menú.
    TrCompra rCompra;
    TaCadena cNombre;
    static TaCompras aCompras;
    static TaArticulos aArticulos;
    
    system("cls"); //Limpiar la pantalla.
    dibujarMarco(); //Se invoca la función dibujarMarco.
    
	do{ 
    	moverCursor (2, 36); //Muestra línea en una posición
    	printf("%cBienvenid%c a la farmacia Ixoye.Submen%c Compras!", 173, 64, 163);
    	moverCursor (7, 45);
    	printf("\n%c 1. Registrar Compra", 175);
    	moverCursor (9, 45);     
    	printf("\n%c 2. Cancelar Compra", 175, 161);
    	moverCursor (11, 45);         
    	printf("\n%c 3. Consultar Compra", 175);
    	moverCursor (15, 45);
    	printf("\n%c 4. Listar Compras", 175);
    	moverCursor (17, 45);
    	printf("\n%c 5. M%cs listados", 175, 160);
    	moverCursor (19, 45);
    	printf("\n%c 6. Regresar a men%c principal", 175, 163);
    
		linea(22); //Dibujar línea en el renglón y columna indicados. 
		moverCursor (25, 32);
    	printf("\nIntroduzca el n%cmero de la operaci%cn que desea realizar: ", 163, 162);
    
    	moverCursor(25, 89); //Mismo renglón que escribir nombre para leerlo.
    	scanf("%d", &eOpcionC);
    
    	//return eOpcionC; //Regresa el valor de la selección dentro del menú. 

		system("cls");
		switch(eOpcionC){
	    
	    	case 1: rCompra = LeerCompra();	   //Invoca la función Leer articulo y guarda su retorno en la variable
					RegistrarCompra(aCompras, &eTotal, rCompra);	//Invoca la función registrar artículo para guardar los datos.
					break;
				
			case 2: system("cls");
					dibujarMarco();
				
					//Formato de pantalla
					eIdCompra = LeerIdCompra("\nCancelar", eTotal, aCompras[eTotal].eIdCompra);
					if (eIdVenta > -1){					
						//CancelarCompra(aCompras, eTotal, eIdCompra);	
					}
					break;
				
			case 3: system("cls");
					dibujarMarco();
	
					//Formato de pantalla
					eIdCompra = LeerIdCompra("\nConsultar", eTotal, aCompras[eTotal].eIdCompra);
										
					if (eIdCompra > -1){										
						ConsultarCompraPorId(aCompras, eTotal, eIdCompra);
					} 	
					break; 		
		
			case 4: system("cls");
					dibujarMarco(); 
	
					//Formato de pantalla
					//ListarArticulos(aArticulos, eTotal);
					break;			
		
			case 5: system("cls");
					dibujarMarco();
				
					//Formato de pantalla
				
			case 6: system("cls");
					dibujarMarco();
				
					//Formato de pantalla
					printf("\nPresione una tecla para volver al men%c principal: ", 163);
					getch();
					break;
				
			default: system("cls");
					 dibujarMarco();
			
					//Formato de pantalla			
					printf("Error en la selecci%cn", 162);
					exit (0); //Función para terminar el programa
					break;
		} 
		
		fflush(stdin);
		getchar();
				
	} while (eOpcionV != 6);			
}

/* PROCEDIMIENTO: LeerCompra
	AUTOR: Varas Dayren Sarahí.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 11 / 06 / 2019
	OBJETIVO: Crear el módulo que permitirá leer los datos de una compra. 
	DE(PE): Ninguno.
	DS(PS): Registro del artículo.
	Retorna: Una colección de datos heterogénea correspondiente a los datos del artículo (TrArticulo)
	
*/

TrCompra LeerCompra(){
	
	TrCompra rCompra; //Variable rArticulo de tipo registro de artículo.
	TaCadena cTipo; //Permitirá mostrar el tipo del artículo según el enumerado. 
	
	system("cls");
	dibujarMarco();
	
	moverCursor (2, 33);
	printf("\n%cBienvenid%c a la farmacia Ixoye - Registrar Compra", 173, 64);
	moverCursor (6, 39);
	printf("\nIngrese los siguientes datos de la compra: ");
	
	moverCursor (9, 45);
	printf("\n%c Nombre de art%cculo: ", 207, 161);
	fflush(stdin); //Limpia el buffer. 
	moverCursor (9, 56);
	gets(rCompra.cNombre); 
	
	moverCursor (10, 45);
	printf("\n%c Id de art%cculo: ", 207, 161);
	fflush(stdin);
	moverCursor (10, 62);
	scanf("%d", &rCompra.eIdArticulo);
	
	moverCursor (12, 45);
	printf("\n%c Fecha de compra: ", 207);
	moverCursor (13, 50);
	printf("Dia: ");
	fflush(stdin);
	moverCursor (13, 55);
	scanf("%d", &rCompra.rFCompra.eDia);
	moverCursor (14, 50);
	printf("Mes: ");
	fflush(stdin);
	moverCursor (14, 55);
	scanf("%d", &rCompra.rFCompra.eMes);
	moverCursor (15, 50);
	printf("A%co: ", 164);
	fflush(stdin);
	moverCursor (15, 55);
	scanf("%d", &rCompra.rFCompra.eAnio);
	moverCursor (17, 45);
	printf("\n%c Tipo de art%cculo: ", 207, 161);
	fflush(stdin);
	moverCursor (17, 65);
	scanf("%d", &rCompra.eTipo);
	ObtenerTipo(rCompra.eTipo, cTipo);
	moverCursor (18, 60);
	printf("%c %s %c", 62, cTipo, 60);
	moverCursor (18, 45);
	printf("\n%c Costo Unitario: ", 207);
	fflush(stdin);
	moverCursor (18, 59);
	scanf("%1.2f", &rCompra.fCostoUnit);
	
	moverCursor (19, 45);
	printf("\n%c Cantidad de piezas compradas: ", 207);
	fflush(stdin);
	moverCursor (19, 72);
	scanf("%d", &rCompra.ePzasCompradas); //Leer un entero dentro del registro rArtículo en el campo eExistenciaMax
	
	moverCursor (19, 45);
	printf("\nId de proveedor: ");
	fflush(stdin);
	scanf("%d", &rCompra.eIdProveedor);
	
	rCompra.eIdCompra = GenerarIdCompra(); //Invoco a la función que genera el ID de la compra. 
	
	return rCompra;

}//FinProcedimiento LeerCompra.

/* 	PROCEDIMIENTO: RegistrarCompra
	AUTOR: Varas Dayren Sarahi
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá registrar artículos. 
	DE(PE): 
	DS(PS): Número entero, positivo. 
	Retorna: Un número entero, positivo correspondiente al resultado de la opción seleccionada (eOpcionC)
*/
void RegistrarCompra(TaCompras aCompras, int *eTotal, TrCompra rCompra){ //Definición del procedimiento RegistrarCompra 
	
	int eRecorre; //Variable que permitirá recorrer el arreglo.
	
	if (*eTotal == MAX_COMPRAS - 1){ 
		
		moverCursor (28, 42);
		printf("\nNo se pueden registrar m%cs compras.", 160); 
		
	} else { 
		
		if (*eTotal == -1 || rCompra.eIdCompra > aCompras[*eTotal].eIdCompra){ 
			
			(*eTotal) ++; 
			
			aCompras[*eTotal] = rCompra; 
			moverCursor (28, 40);
			printf("\nCompra registrada correctamente."); 
			
		} else { 
			
			if (BuscarCompraPorId(aCompras, *eTotal, rCompra.eIdCompra) != -1 ){ 
				
				moverCursor (28, 54);
				printf("\nLa compra ya existe %d", rCompra.eIdCompra);
				
			} else { 
				
				eRecorre = *eTotal; //Asignar a eRecorre el valor de eTotal
				
				while (eRecorre >= 0 && aCompras[eRecorre].eIdCompra > rCompra.eIdCompra){ 
					
					aCompras[eRecorre + 1] = aCompras[eRecorre]; 
					eRecorre --; //Decrementar el valor de eRecorre en uno.
				}
				
				aCompras[eRecorre + 1] = rCompra; //Asignar al arreglo de artículos en la posición eRecorre + 1, el registro del artículo.
				(*eTotal) ++; //Incrementar el valor de total en uno.
				
				moverCursor (28, 40);
				printf("\nCompra registrada correctamente");
			}
		}
	}	
}//FinProcedimiento RegistrarCompra


/* FUNCIÓN: BuscarCompraPorId.
	AUTOR: Varas Dayren Sarahi.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá buscar una compra de acuerdo con su Id.
	DE(PE): Arreglo de compras (TaCompras aCompras), número entero, positivo, índice del arreglo (eTotal), número entero, positivo, que indica el Id de la compra(eIdCompra)
	DS(PS): Posición en la que se encuentra la compra, número entero, positivo.
	Retorna: Un número entero, positivo.
	
*/
int BuscarCompraPorId(TaCompras aCompras, int eTotal, int eIdCompra){ 
	
	int eMenor, eMayor, eMedio; //Declaro variables locales que me permitirán realizar una búsqueda binaria.
	
	if (eTotal == -1){ //Si total = -1 (arreglo vacío).
		
		return -1; //Regresar -1, en el caso de un arreglo que empieza desde 1, sería 0.
		
	} else {
		
		eMenor = 0; //Asignar a eMenor el valor de 0.
		eMayor = eTotal; //Asignar a eMayor el valor de eTotal.
		eMedio = (eMayor + eMenor) / 2; //Calcular eMedio = eMayor + eMenor / 2
		
		while (eMenor < eMayor && aCompras[eMedio].eIdCompra != eIdCompra){ 
		
			if (eIdCompra < aCompras[eMedio].eIdCompra){ 
			
				eMayor = eMedio - 1;  
				
			} else { 
				
				eMenor = eMedio + 1; //Hacer que eMenor tome el valor de eMedio + 1 (que busque de la mitad del arreglo hacia arriba).
			} 
			
			eMedio = (eMenor + eMayor) / 2; //Volver a calcular eMedio con los nuevos valores de eMenor, eMayor. 
		}
		
		if (eIdCompra == aCompras[eMedio].eIdCompra){
			
			return eMedio; 
			 
		} else{ 
			
			return -1; 
		
		}
	}
}//FinFunción BuscarCompraPorId.
 
 
/*FUNCIÓN: GenerarIdCompra.
	AUTOR: Varas Dayren Sarahi.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá generar el ID de una compra. 
	DE(PE): Ninguno.
	DS(PS): Número entero, positivo. 
	Retorna: Un número entero, positivo correspondiente al ID del artículo generado (eSiguiente)
*/
int GenerarIdCompra(){ 
	
	static int eSiguiente = 1; //Variable que generará los ID, empezando por uno.
	
	return (eSiguiente ++); 
}//FinFunción Generar ID Compra. 



/*PROCEDIMIENTO: ObtenerTipo----------(Ya se encuentra en el archivo de Articulos.c)
	AUTOR: López Alejaldre Daniela V.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá obtener el tipo de artículo de acuerdo a un enumerado.
	DE(PE): Número entero, positivo, correspondiente al enumerado TeTipo (eTipo), cadena de caracteres (TaCadena cTipo).
	DS(PS): Ninguno.
	Retorna: No regresa nada.
void ObtenerTipo(int eTipo, TaCadena cTipo){
	
	switch(eTipo){ 
		
		case ALIMENTOS: strcpy(cTipo, "\nAlimentos y bebidas"); 
						break; 
						
		case BOTICA: strcpy (cTipo, "\nBotica"); 
					 	break;
					 	
		case MEDICAMENTOS: strcpy(cTipo, "\nMedicamentos"); 
						break;
						
		case PERFUMES: strcpy(cTipo, "\nPerfumes"); 
					   break;
					   
		default: strcpy(cTipo, "\nIndefinido"); 
				 break; 
				 
	} 
}//FinProcedimiento ObtenerTipo.*/


/*	PROCEDIMIENTO: LeerIdCompra
	AUTOR: Varas Dayren Sarahi
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear una función que permita buscar una compra por Id.
	DE(PE): Cadena de caracteres que indica la operación que se desea realizar (cOperacion), índice del arreglo de compras (eTotal).
	DS(PS): Un número entero, positivo correspondiente al id de la compra (eIdCompra).
	Retorna: El Id de la compra
	
*/
int LeerIdCompra(TaCadena cOperacion, int eTotal, int eUltimoId){
	
	int eId, eIdCompra;
		
	if (eTotal == -1) {
		
		moverCursor (14, 42);
		printf ("\n-- No hay compras registradas. --", 161);
		fflush(stdin);
		getchar();
		return -1;
		
	} else {

		do {
			
			moverCursor (6, 38);
			printf("\nIngrese el ID de compra a %s: ", 161, cOperacion);
			fflush(stdin);
			moverCursor (6, 80);
			scanf("%d", &eIdCompra);
		
		} while (eIdCompra < 1 || eIdCompra > eUltimoId);
	
		return eIdCompra;
	} 
} //LeerIdCompra


/*	FUNCIÓN: MostrarDatosCompra
	AUTOR: Varas Dayren Sarahi
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite mostrar los datos guardados del Articulo.
	DE(PE): Registro de compra (rCompra).
	DS(PS): Ninguno.
	Retorna: Ningún valor. 

*/
void MostrarDatosCompra(TrCompra rCompra){
	
	int eNombre, eIdCompra;
	char cOtro;
	TaCadena cTipo; 
	
	moverCursor (9, 48); 
	printf("\nDatos de compra: [%d]", 161, rCompra.eIdCompra);
	
	moverCursor (12, 45); 
	printf("\n%c Nombre de art%cculo: %s", 207, 161, rCompra.cNombre);
	moverCursor (13, 45); 
	printf("\n%c Id de compra: %d", 207, rCompra.eIdCompra);
	moverCursor (14, 45); 
	printf("\n%c Fecha de compra: %02d/%02d/%02d", 207, rCompra.rFCompra.eDia, rCompra.rFCompra.eMes, rCompra.rFCompra.eAnio);
	ObtenerTipo(rCompra.eTipo, cTipo);
	moverCursor (15, 45); 
	printf("\n%c Tipo de art%cculo: %s", 207, 161, cTipo);
	moverCursor (19, 45); 
	printf("\n%c Costo unitario: %1.2f", 207, rCompra.fCostoUnit);
	moverCursor (20, 45); 
	printf("\n%c Cantidad de piezas Compradas: %d", 207, rCompra.ePzasCompradas);
	printf("\n%c Id de proveedor: %d", 207, rCompra.eIdProveedor);
	moverCursor (22, 45);
} //MostrarDatosCompra


/*	PROCEDIMIENTO: ConsultarCompraPorId
	AUTOR: Varas Dayren Sarahí.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear una funcipon que permita buscar el registro de un articulo ingresando su ID.
	DE(PE): Arreglo de compras (TaCompras), índice del arreglo (eTotal), número entero positivo correspondiente al Id de la compra (eIdCompra).
	DS(PS): Ninguno.
	Retorna: Ningún valor. 
*/

void ConsultarCompraPorId(TaCompras aCompras, int eTotal, int eIdCompra){

	int ePos;

	ePos = BuscarCompraPorId(aCompras, eTotal, eIdCompra);
	
	if (ePos > -1){
	
		MostrarDatosCompra(aCompras[ePos]);	
		printf("\n\n\tPresione una tecla para continuar...");
		
	} else {
		
		printf("\n\n\tNo se encontr%c el id %d", 162, eIdCompra);
	}
} //ConsultarCompraPorId


