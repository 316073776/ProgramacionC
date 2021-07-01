/* **********************************************************************
	PROGRAMA: Ventas.c
	AUTOR(ES): 
				Fernández Ortiz Valeria Lizette
				Francisco Arellano Herdson Josue
				López Alejaldre Daniela Viridiana
				Segura Ríos Brenda Stephanie
				Varas Dayren Sarahi
	EQUIPO: SkyNet
	OBJETIVO: Juntar las funciones que para realizar operaciones con las ventas.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ULTIMA ACTUALIZACIÓN:
********************************************************************** */

//CONSTANTES.
#define MAX_VENTAS 100

//TIPOS.
typedef struct {
	int eDia, eMes, eAnio;
}TrFechaV; //Declaración de registro TrFechaV, que permitirá manejar una variable de este tipo con los campos: día, mes, año.

typedef char TaCadena [50]; //Declaración de tipo de dato cadena. 

typedef struct {	
	TaCadena cNombre; //Nombre del artículo de tipo cadena.
	int eIdVenta, eIdArticulo; //Variables que contendrán los ID.
	int ePzasVend; //Variables de piezas vendidas. 
	TrFechaV rFVenta; //Variable para almacenar fechas de registro. 
	float fPrecioUnit; //Variables para almacenar precio de artículos.		
}TrVenta; //Registro de una venta.

typedef TrVenta TaVentas[MAX_VENTAS]; //Declaración de un arreglo que contiene varios registros de ventas. 


//PROTOTIPOS
TrVenta LeerVenta();
void RegistrarVenta(TaVentas, int* , TrVenta);
int BuscarVentaPorId(TaVentas, int, int);
int BuscarVentaPorFechaV(TaVentas, int, int, int, int);
int GenerarIdVenta();
int LeerIdVenta(int, int);
int LeerFVenta(int, int, int, int);
void MostrarDatosVenta(TrVenta);//Revisar
void ConsultarVentaPorId(TaVentas, int, int);
void ListarVentasPorId(TaVentas, int);
void ListarVentasPorFV(TaVentas, int);
void OrdenarPorIdV(TaVentas, int);
void OrdenarPorFVenta(TaVentas, int);
void MenuVentas();


//FUNCIONES
/* **********************************************************************
	FUNCIÓN: MenúVentas
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 17 de abril del 2019.
	FECHA DE ÚLIMA ACTUALIZACIÓN: 11/06/2019
	OBJETIVO: Crear el diseño de la aplicación del sistema (sub-menú Ventas).
	DE(PE): Ninguno.
	DS(PS): Número entero, positivo.
	Retorna: Un número entero, positivo correspondiente al resultado de la opción seleccionada (eOpcionV).
********************************************************************** */
void MenuVentas() { 
    
    static int eTotal = -1;
    int eOpcionV, eIdVenta, eDiaFV, eMesFV, eAnioFV, eOpcionCV, eOpcionLV, eIdA, ePos;
    TrVenta rVenta;
	TaCadena cNombre;
	static TaVentas aVentas;
	 
    do{//Repetir...
	
	    system("cls");
	    dibujarMarco(); //Invocar al procedimiento dibujarMarco
		
		moverCursor (2, 36); //Se invoca a la función moverCursor y se le mandan los parámetros de renglón y columna donde deseamos que se posicione el cursor.
	    printf("%cBienvenid%c a la farmacia Ixoye - Submen%c Ventas!", 173, 64, 163);
	    moverCursor (6, 45); 
	    printf("%c 1. Registrar venta", 175);
	    moverCursor (8, 45);        
	    printf("%c 2. Consultar venta", 175);
	    moverCursor (12, 45);
	    printf("%c 3. Listar ventas", 175);
	    moverCursor (14, 45);
	    printf("%c 4. Regresar a men%c principal", 175, 163);
	    
		linea(18); //Se dibuja una línea en el renglón indicado.
		moverCursor (20, 32);
	    printf("Introduzca el n%cmero de la operaci%cn que desea realizar: ", 163, 162);
	    
	    moverCursor (20, 89);
	    scanf("%d", &eOpcionV); //Leer el valor de la variable ingresada por el usuario.
	    
	    system("cls");
	    switch(eOpcionV){ //En caso del valor de lavariable eOpcionV hacer...
			
			case 1: rVenta = LeerVenta();	   //Invoca la función LeerVenta y guarda su retorno en la variable
					RegistrarVenta (aVentas, &eTotal, rVenta);	//Invoca la función registrar venta para guardar los datos.
				   	break;
		  			
			case 2:system("cls"); 
					dibujarMarco();
					
					moverCursor (2, 34);
					printf("%cBienvenid%c a la farmacia Ixoye - Consultar Venta!", 173, 64, 161);
					moverCursor (10, 45);
					printf("1. Consultar por ID");
					moverCursor (13, 45);
					printf("2. Consultar por fecha de venta");
					moverCursor (16, 45);
					printf("3. Regresar a sub-men%c Ventas", 163);
					
					linea (22);
					moverCursor (25, 35);
					printf("Ingresa el n%cmero de la consulta que deseas realizar: ", 163);
					moverCursor (25, 89);
					scanf("%d", &eOpcionCV);
					
					system("cls");
					switch (eOpcionCV){
						
						case 1: rVenta = LeerIdVenta(); //Asignar a eIdVenta el valor de LeeridVenta
										
								if (eIdVenta > -1){	//Si el IdVenta es mayor a -1 (si el artículo existe)									
								ConsultarVentaPorId(aVentas, &eTotal, eIdVenta); //Mandar a llamar al procedimiento consultar venta.
								} 
								
								break;
								
						case 2:	if (eTotal == -1) {
		
								moverCursor (14, 42);
								printf ("-- No hay ventas registradas. --", 161);
								fflush(stdin);
								getchar();
							} else {
								moverCursor (6, 38);
								printf("Ingrese la fecha de venta: ");
								printf("\nD%ca: ", 161);
								fflush(stdin);
								moverCursor (9, 45);
								scanf("%d", &eDiaFV);
								printf("\nMes: ");
								fflush(stdin);
								moverCursor (12, 45);
								scanf("%d", &eMesFV);
								printf("\nA%co: ", 65);
								fflush(stdin);
								moverCursor (15, 45);
								scanf("%d", &eAnioFV);
								
								ePos = 	BuscarVentaPorFVenta(aVentas, eTotal, eDiaFV, eMesFV, eAnioFV);
								
								if (ePos > -1){ //Si ePos es mayor a -1 (sí se encontró la venta).
								
									MostrarDatosVenta(aVentas[ePos]);
									
								} else {
									
									printf("\nNo se encontr%c el art%cculo %s", 162, 161, cNombre);
								}						
								break;
								
						case 3: MenuVentas();
								break;
								
						default:fflush(stdin);
						moverCursor (8, 38);
						printf("\nError en la selecci%cn", 162);
								 break;	
					}
			case 3:system("cls"); 
					dibujarMarco();
					
					moverCursor (2, 34);
					printf("%cBienvenid%c a la farmacia Ixoye - Listar Ventas!", 173, 64, 161);
					moverCursor (10, 45);
					printf("1. Listar por ID");
					moverCursor (13, 45);
					printf("2. Listar por fecha de venta");
					moverCursor (16, 45);
					printf("3. Regresar a sub-men%c Ventas", 163);
					
					linea (22);
					moverCursor (25, 35);
					printf("Ingresa el n%cmero de la consulta que deseas realizar: ", 163);
					moverCursor (25, 89);
					scanf("%d", &eOpcionLV);
					
					system("cls");
					switch (eOpcionLV){
						
						case 1:ListarVentasPorId(aVentas, eTotal);
								
								break;
								
						case 2:ListarVentasPorFV(aVentas, eTotal);				
								break;
								
						case 3: MenuVentas();
								break;
								
						default:fflush(stdin);
						moverCursor (8, 38);
						printf("\nError en la selecci%cn", 162);
								 break;	
					}
			case 4:main (); //Ejecutar menú principal.
					break;
			default: moverCursor (8, 38);
					printf("Error en la selecci%cn", 162);
					break;
		} 
		
		fflush(stdin);
		getchar();
	    
	} while (eOpcionV != 4);//Mientras la opción sea diferente de 4.
    
    //return 0; //Regresar el valor del número de la opción. 
} // Fin submenú ventas.

/* **********************************************************************
	PROCEDIMIENTO: LeerVenta
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 11 / 06 / 2019
	OBJETIVO: Crear el módulo que permitirá leer los datos de una venta.
	DE(PE): Ninguno.
	DS(PS): Registro de la venta.
	Retorna: Una colección de datos heterogénea correspondiente a los datos de la venta (TrVenta)
********************************************************************** */
TrVenta LeerVenta(){ 
	
	TrVenta rVenta; //Variable rVenta de tipo registro de la venta. 

	system("cls");
	dibujarMarco();
	
	moverCursor (2, 33);
	printf("%cBienvenid%c a la farmacia Ixoye - Registrar Venta!", 173, 64);
	moverCursor (6, 39);
	printf("Ingrese los siguientes datos de la venta: ");
	
	moverCursor (9, 45);
	printf("%c Ingrese Id de Art%cculo: ", 207, 161);
	fflush(stdin); //Limpia el buffer. 
	moverCursor (9, 65);
	scanf("%d", &rVenta.eIdVenta);	

	moverCursor (12, 45);
	printf("%c Ingrese Id de Art%cculo: ", 207, 161);
	fflush(stdin); //Limpia el buffer. 
	moverCursor (12, 65);
	scanf("%d", &rVenta.eIdVenta);	

	moverCursor (15, 45);
	printf("%c Fecha de venta: ", 207);
	moverCursor (16, 50);
	printf("Dia: ");
	fflush(stdin);
	moverCursor (16, 55);
	scanf("%d", &rVenta.rFVenta.eDia);
	moverCursor (17, 50);
	printf("Mes: ");
	fflush(stdin);
	moverCursor (17, 55);
	scanf("%d", &rVenta.rFVenta.eMes);
	moverCursor (18, 50);
	printf("A%co: ", 164);
	fflush(stdin);
	moverCursor (18, 55);
	scanf("%d", &rVenta.rFVenta.eAnio);
	
	moverCursor (21, 45);
	printf("%c Precio Unitario: ", 207);
	fflush(stdin);
	moverCursor (21, 59);
	scanf("%.2f", &rVenta.fPrecioUnit);
	
	moverCursor (23, 45);
	printf("%c Cantidad de piezas vendidas: ", 207);
	fflush(stdin);
	moverCursor (23, 72);
	scanf("%d", &rVenta.ePzasVend);
	
	rVenta.eIdVenta = GenerarIdVenta(); //Invoco a la función que genera el ID de la venta. 
	
	return rVenta;

}//Fin Función LeerVenta. 


/* **********************************************************************
	PROCEDIMIENTO: RegistrarVenta
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá registrar ventas. 
	DE(PE): El arrelgo de las ventas (aVentas), el índice (eTotal) y el registro de la venta (rVenta).
	DS(PS): Ninguno. 
	Retorna: Ningún valor.
********************************************************************** */
void RegistrarVenta(TaVentas aVentas, int *eTotal, TrVenta rVenta){ //Definición del procedimiento RegistrarVenta. 
	
	int eRecorre; //Variable que permitirá recorrer el arreglo.
	
	if (*eTotal == MAX_VENTAS - 1){ //Si el total del arreglo es igual al número máximo de ventas posibles de registrar, entonces...
		
		moverCursor (28, 42);
		printf("No se pueden agregar m%cs ventas.", 160); //Mostrar que no se pueden ingresar más ventas.
		
	} else { //de lo contrario...
		
		if (*eTotal == -1 || rVenta.eIdVenta > aVentas[*eTotal].eIdVenta){ /*Si el índice del arreglo de ventas está en 0 o si el registro de la venta en el campo eIdVenta es mayor al arreglo de ventas en la posición eTotal en el campo IdVenta, entonces...*/
			
			(*eTotal) ++; //Incrementar el valor de eTotal en uno.
			
			aVentas[*eTotal] = rVenta; //Asignar al arreglo ventas en la posición eTotal el registro de la venta.
			moverCursor (28, 40);
			printf("Venta registrada correctamente."); //Mostrar que la venta ha sido registrado de forma exitosa.
			
		} else { //De lo contrario...
			
			if (BuscarVentaPorId(aVentas, *eTotal, rVenta.eIdVenta) != -1 ){ //Si buscar venta por ID es diferente de 0...
				
				moverCursor (28, 54);
				printf("Ya existe %d", rVenta.eIdVenta); //Mostrar que ya existe la venta.
				
			} else { //De lo contrario...
				
				eRecorre = *eTotal; //Asignar a eRecorre el valor de eTotal
				
				while (eRecorre >= 0 && aVentas[eRecorre].eIdVenta > rVenta.eIdVenta){ /*Mientras eRecorre sea mayor a 0 y el arreglo de ventas 
				en la posición eRecorre en el campo IdVenta sea mayor que el registro de artículos en la posición IdVenta hacer... */
					
					aVentas[eRecorre + 1] = aVentas[eRecorre]; //Asignar al arreglo en la posición eRecorre + 1 el registro de la venta en la posición eRecorre.
					eRecorre --; //Decrementar el valor de eRecorre en uno.
				}
				aVentas[eRecorre + 1] = rVenta; //Asignar al arreglo de ventas en la posición eRecorre + 1, el registro de la venta.
				(*eTotal) ++; //Incrementar el valor de total en uno.
				
				moverCursor (28, 40);
				printf("Venta registrada correctamente"); //Mostrar que el registro de ventas se realizó adecuadamente. 
			}
		}
	}	
}//Fin Procedimiento RegistrarVenta


/* **********************************************************************
	FUNCIÓN: BuscarVentaPorId.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá buscar una venta de acuerdo con su Id.
	DE(PE): Arreglo de artículos (TaVentas aVentas), número entero, positivo, índice del arreglo (eTotal), número entero, positivo, que indica el Id de la venta (eIdVenta)
	DS(PS): Registro de la venta.
	Retorna: Un número entero, positivo correspondiente a la posición de la venta buscada, si no se encuentra regresa 0, la posisición contiene una colección de datos heterogénea correspondiente a los datos de la venta (TrVenta)
********************************************************************** */
int BuscarVentaPorId(TaVentas aVentas, int eTotal, int eIdVenta){ 
	
	int eMenor, eMayor, eMedio; //Declaro variables locales que me permitirán realizar una búsqueda binaria.
	
	if (eTotal == -1){ //Si total = -1 (arreglo vacío).
		
		return -1; //Regresar -1, en el caso de un arreglo que empieza desde 1, sería 0.
		
	} else {
		
		eMenor = 0; //Asignar a eMenor el valor de 0.
		eMayor = eTotal; //Asignar a eMayor el valor de eTotal.
		eMedio = (eMayor + eMenor) / 2; //Calcular eMedio = eMayor + eMenor / 2
		
		while (eMenor < eMayor && aVentas[eMedio].eIdVenta != eIdVenta){ /*Mientras eMenor sea menor a eMayor Y el arreglo de ventas en la posición
		de eMedio en el campo eIdVenta sea diferente de eIdVenta (mientras no exista el id)
		*/
			if (eIdVenta < aVentas[eMedio].eIdVenta){ /*Si el id de la venta es menor al arreglo de ventas en la posición eMedio en el campo eidVenta 
			(se encuentra de la mitad del arreglo para abajo)*/
			
				eMayor = eMedio - 1; //Hacer que eMayor tome el valor de eMedio - 1 (que busque de la mitad del arreglo hacia abajo). 
				
			} else { //De lo contrario (se encuentra de la mitad del arreglo para arriba).
				
				eMenor = eMedio + 1; //Hacer que eMenor tome el valor de eMedio + 1 (que busque de la mitad del arreglo hacia arriba).
			} 
			
			eMedio = (eMenor + eMayor) / 2; //Volver a calcular eMedio con los nuevos valores de eMenor, eMayor. 
		}
		
		if (eIdVenta == aVentas[eMedio].eIdVenta){//Si el id de la venta es igual al arreglo en la posición del centro en el campo eIdVenta
			
			return eMedio; //Regresar el valor de eMedio (posición del arreglo en donde se encuentra el ID de la venta).
			 
		} else{ //De lo contrario...
			
			return -1; //Indica que no se encontró.
		
		}
	}
}//Fin Función BuscarVentaPorId.


/* **********************************************************************
	FUNCIÓN: BuscarVentaPorFechaV.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá enconrtrar una venta por su fecha de venta. 
	DE(PE): Arreglo de artículos (TaVentas aVentas), número entero, positivo, índice del arreglo (eTotal), un conjunto de números enteros, positivos, que indica la fecha de venta de la venta (Fecha de venta).
	DS(PS): Número entero, positivo. 
	Retorna: Un número entero, positivo correspondiente a la posición de la venta buscada, si no se encuentra regresa 0, la posisición contiene una colección de datos heterogénea correspondiente a los datos de la venta (TrVenta).
********************************************************************** */
int BuscarVentaPorFechaV(TaVentas aVentas, int eTotal, int eDiaFV, int eMesFV, int eAnioFV){ 
	
	int eMenor, eMayor, eMedio; //Declaro variables locales que me permitirán realizar una búsqueda binaria.
	
	if (eTotal == -1){ //Si total = -1 (arreglo vacío).
		
		return -1; //Regresar -1, en el caso de un arreglo que empieza desde 1, sería 0.
		
	} else {
		
		eMenor = 0; //Asignar a eMenor el valor de 0.
		eMayor = eTotal; //Asignar a eMayor el valor de eTotal.
		eMedio = (eMayor + eMenor) / 2; //Calcular eMedio = eMayor + eMenor / 2
		
		while (eMenor < eMayor && aVentas[eMedio].rFVenta.eDia != eDiaFV && aVentas[eMedio].rFVenta.eMes != eMesFV && 	aVentas[eMedio].rFVenta.eAnio != eAnioFV){ //Se compara cada campo de rFVenta con los datos obtendidos de LeerFVenta
			if (eDiaFV < aVentas[eMedio].rFVenta.eDia || eMesFV < aVentas[eMedio].rFVenta.eMes || eAnioFV < aVentas[eMedio].rFVenta.eAnio){
			
				eMayor = eMedio - 1; //Hacer que eMayor tome el valor de eMedio - 1 (que busque de la mitad del arreglo hacia abajo). 
				
			} else { //De lo contrario (se encuentra de la mitad del arreglo para arriba).
				
				eMenor = eMedio + 1; //Hacer que eMenor tome el valor de eMedio + 1 (que busque de la mitad del arreglo hacia arriba).
			} 
			
			eMedio = (eMenor + eMayor) / 2; //Volver a calcular eMedio con los nuevos valores de eMenor, eMayor. 
		}
		
		if (eDiaFV == aVentas[eMedio].rFVenta.eDia && eMesFV == aVentas[eMedio].rFVenta.eMes && eAnioFV == aVentas[eMedio].rFVenta.eAnio){
			
			return eMedio; //Regresar el valor de eMedio (posición del arreglo en donde se encuentra la fecha de la venta).
			 
		} else{ //De lo contrario...
			
			return -1; //Indica que no se encontró.
		
		}
	}
}//Fin Función BuscarVentaPorFechaV.
/* **********************************************************************
	FUNCIÓN: GenerarIdVenta.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá generar el ID de una venta. 
	DE(PE): Ninguno.
	DS(PS): Número entero, positivo. 
	Retorna: Un número entero, positivo correspondiente al ID de la venta generado (eSiguiente).
********************************************************************** */
int GenerarIdVenta(){ //Función generar ID de venta.
	
	static int eSiguiente = 1; //Variable que generará los ID, empezando por uno.
	
	return (eSiguiente ++); //Regresar eSiguiente + 1
}//Fin Función GenerarIdVenta 

/* **********************************************************************
	PROCEDIMIENTO: LeerIdVenta.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear un módulo que permita leer los datos de la venta a buscar.
	DE(PE): Un número entero positivo que representan el Id de la venta (eId)
	DS(PS): El Id de venta.
	Retorna: El id de venta o de no encontrarlo un mensaje de error.
********************************************************************** */
int LeerIdVenta(int eTotal, int eUltimoId){
	
	int eId;
		
	if (eTotal == -1) {
		
		moverCursor (14, 42);
		printf ("-- No hay ventas registradas. --");
		fflush(stdin);
		getchar();
		return -1;
		
	} else {

		do {
			
			moverCursor (6, 38);
			printf("Ingrese el ID de venta: ");
			fflush(stdin);
			moverCursor (6, 80);
			scanf("%d", &eId);
		
		} while (eId < 1 || eId > eUltimoId);
	
		return eId;
	} 
} //Fin Función LeerIdVenta


/* **********************************************************************
	FUNCIÓN: MostrarDatosVenta.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Un conjunto de números enteros positivos que representan.
	DE(PE): Un número entero positivo que es el Id de la venta a buscar (eIdVenta).
	DS(PS): El registro de la venta (rVenta).
	Retorna: Ningún valor.
********************************************************************** */
void MostrarDatosVenta(TrVenta rVenta){
	
	int eNombre, eIdVenta;
	char cOtro;
	TaCadena cTipo;
	
	moverCursor (9, 48); 
	printf("Datos de venta: [%d]", 161, rVenta.eIdVenta);
	
	moverCursor (12, 45); 
	printf("%c Nombre de art%cculo: %s", 207, 161, rVenta.cNombre);
	moverCursor (14, 45); 
	printf("%c Id de art%cculo: %d", 207, 161, rVenta.eIdArticulo);
	moverCursor (16, 45); 
	printf("%c Fecha de venta: %02d/%02d/%02d", 207,
		rVenta.rFVenta.eDia, rVenta.rFVenta.eMes, rVenta.rFVenta.eAnio);
	moverCursor (18, 45); 
	printf("%c Precio unitario: %.2f", 207, rVenta.fPrecioUnit);
	moverCursor (20, 45); 
	printf("%c Cantidad de piezas vendidas: %d", 207, rVenta.ePzasVend);
	
} //Fin Procedimiento MostrarDatosVenta.


/* **********************************************************************
	PROCEDIMIENTO: ConsultarVentaPorId.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear una funcipon que permita buscar el registro de una venta ingresando su ID.
	DE(PE): EL arreglo de las ventas (aVentas), el índice (eTotal) y el Id de la venta (IdVenta).
	DS(PS): 
	Retorna: Ningún valor.
********************************************************************** */
void ConsultarVentaPorId(TaVentas aVentas, int eTotal, int eIdVenta){

	int ePos;
	
	ePos = BuscarVentaPorId(aVentas, eTotal, eIdVenta);
	
	if (ePos > -1){
	
		MostrarDatosVenta(aVentas[ePos]);	
		printf("\n\n\tPresione una tecla para continuar...");
		
	} else {
		
		printf("\n\n\tNo se encontr%c el id %d", 162, eIdVenta);
	}
} //Fin Procedimiento ConsultarVentaPorId.


/* **********************************************************************
	FUNCIÓN: ListarVentasPorId.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite listar ventas.
	DE(PE): El índice (eTotal) y el arreglo de ventas (aVentas).
	DS(PS): EL arreglo de ventas (aVentas) ordenado por Id de venta.
	Retorna: Ningún valor.
********************************************************************** */	
void ListarVentasPorId(TaVentas aVentas, int eTotal){
	
	char cSubcadena[20];
		
	if (eTotal != -1){
		
		ListarVentas(aVentas, eTotal - 1);
			
				OrdenarPorIdV(aVentas, eTotal); //Ejecutar OrdenarPorIdV (antes de mostrarlos). 
		
				strncpy(cSubcadena, aVentas[eTotal].cNombre, 20);
				cSubcadena[20] = '\0';
				
				printf("%2d %-20s " , aVentas[eTotal].eIdVenta, cSubcadena);
				
				printf("%4d %-20s %02d/%02d/%02d  %.2f %3d \n", 
				aVentas[eTotal].eIdArticulo, 
				cSubcadena,
				aVentas[eTotal].rFVenta.eDia, 
				aVentas[eTotal].rFVenta.eMes, 
				aVentas[eTotal].rFVenta.eAnio, 
				aVentas[eTotal].fPrecioUnit,
				aVentas[eTotal].ePzasVend);
	}
	
} //Fin Procedimiento ListarVentasPorID.

/* **********************************************************************
	FUNCIÓN: ListarVentasPorFV.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite listar ventas.
	DE(PE): El índice (eTotal) y el arreglo de ventas (aVentas).
	DS(PS): EL arreglo de ventas (aVentas) ordenado por fecha de venta.
	Retorna: Ningún valor.
********************************************************************** */	
void ListarVentasPorFV(TaVentas aVentas, int eTotal){
	
	char cSubcadena[20];
		
	if (eTotal != -1){
		
		ListarVentas(aVentas, eTotal - 1);
			
				OrdenarPorFVenta(aVentas, eTotal); //Ejecutar OrdenarPorFVenta (antes de mostrarlos). 
		
				strncpy(cSubcadena, aVentas[eTotal].cNombre, 20);
				cSubcadena[20] = '\0';
				
				printf("%2d " , aVentas[eTotal].eIdVenta);
				
				printf("%4d %-20s %02d/%02d/%02d  %.2f %3d \n", 
				aVentas[eTotal].eIdArticulo, 
				cSubcadena,
				aVentas[eTotal].rFVenta.eDia, 
				aVentas[eTotal].rFVenta.eMes, 
				aVentas[eTotal].rFVenta.eAnio, 
				aVentas[eTotal].fPrecioUnit,
				aVentas[eTotal].ePzasVend);
	} 
	
} //Fin Procedimiento ListarVentasPorFV.

/* **********************************************************************
	FUNCIÓN: OrdenarPorIdV.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite ordenar el arreglo (aVentas) por Id de venta (IdVenta).
	DE(PE): El índice (eTotal) y el arreglo de ventas (aVentas).
	DS(PS): Ninguno.
	Retorna: Ningún valor.
********************************************************************** */
void OrdenarPorIdV(TaVentas aVentas, int eTotal){
	
	int eCont1, eCont2, eTemporal; //Variables locales de tipo entero.
	
	if (eTotal = -1){ //Si el índice es igual a menos uno (arreglo vacío), entonces...
	
		printf("\nNo hay art%cculos registrados", 161);
		
	} else {
		
		for (eCont1 = 0; eCont1 < eTotal - 1; eCont1 ++){ //Desde eCont1 igual al primer elemento del arreglo, hasta eTotal - 1 hacer...
			
			for (eCont2 = 1; eCont2 < eTotal; eCont2 ++){//Desde eCont2 igual al segundo elemento del arreglo, hasta eTotal hacer...
				
				if (aVentas[eCont2].eIdVenta < aVentas[eCont1].eIdVenta){ /*Si el arreglo de artículos en la posición de contador 2 en el campo eIdVenta es menor al
				 arreglo de ventas en la posición contador 1 en el campo eIdVenta, entonces...*/
					eTemporal = aVentas[eCont2].eIdVenta; //Asignar a eTemporal el valor del arreglo de ventas en la posición de contador 2 en el campo IdVenta.
					aVentas[eCont2].eIdVenta = aVentas[eCont1].eIdVenta;
					aVentas[eCont1].eIdVenta = eTemporal;	//Asignar al arreglo de ventas en la posición de contador 1 en el campo IdVenta el valor de eTemporal. 
				}
			}
		}
	}
}//Fin Procedimiento OrdenarPorIdV

/* **********************************************************************
	FUNCIÓN: OrdenarPorFVenta.
	AUTOR: Fernández Ortiz Valeria Lizette.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite ordenar el arreglo (aVentas) por fecha de venta (aVentas.rFVenta).
	DE(PE): El índice (eTotal) y el arreglo de ventas (aVentas).
	DS(PS): Ninguno.
	Retorna: Ningún valor.
********************************************************************** */
void OrdenarPorFVenta(TaVentas aVentas, int eTotal){
	
	int eCont1, eCont2, eTemporal1, eTemporal2, eTemporal3; //Variables locales de tipo entero.
	
	if (eTotal = -1){ //Si el índice es igual a menos uno (arreglo vacío), entonces...
	
		printf("\nNo hay art%cculos registrados", 161);
		
	} else {
		
		for (eCont1 = 0; eCont1 < eTotal - 1; eCont1 ++){ //Desde eCont1 igual al primer elemento del arreglo, hasta eTotal - 1 hacer...
			
			for (eCont2 = 1; eCont2 < eTotal; eCont2 ++){//Desde eCont2 igual al segundo elemento del arreglo, hasta eTotal hacer...
				
				if (aVentas[eCont2].rFVenta.eDia < aVentas[eCont1].rFVenta.eDia && aVentas[eCont2].rFVenta.eMes < aVentas[eCont1].rFVenta.eMes && aVentas[eCont2].rFVenta.eAnio < aVentas[eCont1].rFVenta.eAnio){
					eTemporal1 = aVentas[eCont2].rFVenta.eDia;
					aVentas[eCont2].rFVenta.eDia = aVentas[eCont1].rFVenta.eDia;
					aVentas[eCont1].rFVenta.eDia = eTemporal1;

					eTemporal2 = aVentas[eCont2].rFVenta.eMes;
					aVentas[eCont2].rFVenta.eMes = aVentas[eCont1].rFVenta.eMes;
					aVentas[eCont1].rFVenta.eMes = eTemporal2;

					eTemporal3 = aVentas[eCont2].rFVenta.eAnio;
					aVentas[eCont2].rFVenta.eAnio = aVentas[eCont1].rFVenta.eAnio;
					aVentas[eCont1].rFVenta.eAnio = eTemporal3;
				}else {
					if (aVentas[eCont2].rFVenta.eDia < aVentas[eCont1].rFVenta.eDia && aVentas[eCont2].rFVenta.eMes < aVentas[eCont1].rFVenta.eMes && aVentas[eCont2].rFVenta.eAnio == aVentas[eCont1].rFVenta.eAnio){
						eTemporal1 = aVentas[eCont2].rFVenta.eDia;
					aVentas[eCont2].rFVenta.eDia = aVentas[eCont1].rFVenta.eDia;
					aVentas[eCont1].rFVenta.eDia = eTemporal1;

					eTemporal2 = aVentas[eCont2].rFVenta.eMes;
					aVentas[eCont2].rFVenta.eMes = aVentas[eCont1].rFVenta.eMes;
					aVentas[eCont1].rFVenta.eMes = eTemporal2;

					eTemporal3 = aVentas[eCont2].rFVenta.eAnio;
					aVentas[eCont2].rFVenta.eAnio = aVentas[eCont1].rFVenta.eAnio;
					aVentas[eCont1].rFVenta.eAnio = eTemporal3;
					} else {
						if (aVentas[eCont2].rFVenta.eDia < aVentas[eCont1].rFVenta.eDia && aVentas[eCont2].rFVenta.eMes == aVentas[eCont1].rFVenta.eMes && aVentas[eCont2].rFVenta.eAnio == aVentas[eCont1].rFVenta.eAnio) {
							eTemporal1 = aVentas[eCont2].rFVenta.eDia;
					aVentas[eCont2].rFVenta.eDia = aVentas[eCont1].rFVenta.eDia;
					aVentas[eCont1].rFVenta.eDia = eTemporal1;

					eTemporal2 = aVentas[eCont2].rFVenta.eMes;
					aVentas[eCont2].rFVenta.eMes = aVentas[eCont1].rFVenta.eMes;
					aVentas[eCont1].rFVenta.eMes = eTemporal2;

					eTemporal3 = aVentas[eCont2].rFVenta.eAnio;
					aVentas[eCont2].rFVenta.eAnio = aVentas[eCont1].rFVenta.eAnio;
					aVentas[eCont1].rFVenta.eAnio = eTemporal3;
						}
					}
				}
			}
		}
	}
}//Fin Procedimiento OrdenarPorFVenta
