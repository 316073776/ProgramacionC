/* **********************************************************************
	PROGRAMA: Articulos.c
	AUTOR(ES): 
				Fern�ndez Ortiz Valeria Lizette
				Francisco Arellano Herdson Josue
				L�pez Alejaldre Daniela Viridiana
				Segura R�os Brenda Stephanie
				Varas Dayren Sarahi
	EQUIPO: SkyNet
	OBJETIVO: Juntar las funciones necesarias para realizar operaciones con los art�culos.
	FECHA DE CREACI�N: 11 de junio del 2019.
	FECHA DE ULTIMA ACTUALIZACI�N: 13 de jinuio del 2019.
********************************************************************** */

//CONSTANTES.
#define MAX_ARTICULOS 100


//TIPOS.
typedef struct {
	int eDia, eMes, eAnio;
}TrFecha; //Declaraci�n de registro TrFecha, que permitir� manejar una variable de este tipo con los campos: d�a, mes, a�o.

typedef enum {
	ALIMENTOS = 1, BOTICA, MEDICAMENTOS, PERFUMES //Botica tomar� el valor de alimentos + 1, medicamentos tomar� el valor de botica + 1 y as� consecutivamente. 
}TeTipo; //Declaraci�n de enumerado TeTipo, que permitir� clasificar un art�culo de acuerdo a su tipo.

typedef char TaCadena [50]; //Declaraci�n de tipo de dato cadena. 

typedef struct {	
	TaCadena cNombre, cMarca, cPresentacion, cProveedor, cContenidoNeto, cSustanciaActiva; //Nombre del art�culo de tipo cadena.
	int eIdProveedor, eIdArticulo; //Variables que contendr�n los ID.
	int eExistenciaMax, eExistenciaMin; //Variables para existencias m�ximas y m�nimas. 
	TrFecha rFecRegistro, rFecCaducidad; //Variable para almacenar fechas de registro. 
	TeTipo eTipo; //Variable para clasificar art�culos seg�n su tipo.
	float fPrecio, fCosto; //Variables para almacenar precio y costo de art�culos.		
}TrArticulo; //Registro de un art�culo.

typedef TrArticulo TaArticulos[MAX_ARTICULOS]; //Declaraci�n de un arreglo que contiene varios registros de art�culos. 


//PROTOTIPOS
TrArticulo LeerArticulo();//Prototipo LeerArticulo.
void RegistrarArticulo(TaArticulos, int* , TrArticulo); //Prototipo de m�dulo RegistrarArticulo.
int BuscarArticuloPorId(TaArticulos, int, int); //Prototipo BuscarArticuloPorId.
int BuscarBinario (TaArticulos, int, TaCadena); //Prototipo BuscarBinario (buscar un art�culo por nombre). 
int GenerarIdArticulo(); //Prototipo de funci�n generarIdArticulo.
void ObtenerTipo(int, TaCadena); //Prototipo de ObtenerTipo
void BorrarArticulo (TaArticulos, int*, int); //Prototipo para borrar un art�culo
int LeerIdLArticulo(TaCadena, int, int); //Prototipo para leer el ID ingresado
void MostrarDatosArticulo(TrArticulo); //Prototipo MostrarDatosArticulo.
void ConsultarArticuloPorId(TaArticulos, int, int); //Prototipo Para consultar articulo
void ConsultarArticuloPorNombre(TaArticulos, int, TaCadena); //Prototipo para consultar art�culo por nombre. 
void ModificarArticulo(TaArticulos, int, int); //Prototipo para Modificar datos de un art�culo
void OrdenarPorId(TaArticulos, int); //Prototipo para ordenar art�culos de acuerdo a su ID.
void OrdenarPorNombre(TaArticulos, int); //Prototipo para ordenar art�culos de acuerdo a su nombre.
void OrdenarPorTipo(TaArticulos, int); //Prototipo para ordenar art�culos de acuerdo a su tipo.
void ListarPorId(TaArticulos, int); //Prototipo del m�dulo que lista art�culos ordenados por ID.
void ListarPorNombre(TaArticulos, int); //Prototipo del m�dulo que lista art�culos ordenados por nombre.
void ListarPorTipo(TaArticulos, int); //Prototipo del m�dulo que lista art�culos ordenados por tipo.
void MenuArticulos(); //Procedimiento Sub-Men� Art�culos.


//FUNCIONES
/* **********************************************************************
	FUNCI�N: Men�Ventas
	AUTOR: L�pez Alejaldre Daniela Viridiana / Segura Rios Brenda Stephanie
	FECHA DE CREACI�N: 17 de abril del 2019. 
	OBJETIVO: Crear el dise�o de la aplicaci�n del sistema (sub-men� Art�culos).
	DE(PE): Ninguno.
	DS(PS): N�mero entero, positivo.
	Retorna: Un n�mero entero, positivo correspondiente al resultado de la opci�n seleccionada (eOpcionV).
********************************************************************** */
void MenuArticulos() {  
    
    static int eTotal = -1;
    int eOpcionA, eIdArticulo, eOpcionL, eOpcionC, ePos;
    TrArticulo rArticulo;
	TaCadena cNombre;
	static TaArticulos aArticulos;
	 
    do{//Repetir...
	
	    system("cls");
	    dibujarMarco(); //Invocar al procedimiento dibujarMarco
		
		moverCursor (2, 36); //Se invoca a la funci�n moverCursor y se le mandan los par�metros de rengl�n y columna donde deseamos que se posicione el cursor.
	    printf("%cBienvenid%c a la farmacia Ixoye - Submen%c Art%cculos!", 173, 64, 163, 161);
	    moverCursor (6, 45); 
	    printf("%c 1. Registrar art%cculo", 175, 161);
	    moverCursor (9, 45);     
	    printf("%c 2. Borrar art%cculo ", 175, 161);
	    moverCursor (12, 45);         
	    printf("%c 3. Actualizar art%cculo", 175, 161);
	    moverCursor (15, 45);
	    printf("%c 4. Consultar art%cculo", 175, 161);
	    moverCursor (18, 45);
	    printf("%c 5. Listar art%cculos", 175, 161);
	    moverCursor (21, 45);
	   	printf("%c 6. Regresar a men%c principal", 175, 163);
	    
		linea(22); //Se dibuja una l�nea en el rengl�n indicado.
		moverCursor (25, 32);
	    printf("Introduzca el n%cmero de la operaci%cn que desea realizar: ", 163, 162);
	    
	    moverCursor (25, 89);
	    scanf("%d", &eOpcionA); //Leer el valor de la variable ingresada por el usuario.
	    
	    system("cls");
	    switch(eOpcionA){ //En caso del valor de lavariable eOpcionA hacer...
			
			case 1: rArticulo = LeerArticulo();	   //Invoca la funci�n Leer articulo y guarda su retorno en la variable
					RegistrarArticulo (aArticulos, &eTotal, rArticulo);	//Invoca la funci�n registrar art�culo para guardar los datos.
				   	break;
				   	
			case 2: system("cls"); //Limpia la pantalla.
					dibujarMarco(); //Invoca a la funci�n dibujarMarco.
	
					moverCursor (2, 35);
					printf("%cBienvenid%c a la farmacia Ixoye - Borrar Art%cculo!", 173, 64, 161);
			
					eIdArticulo = LeerIdArticulo("borrar", eTotal, aArticulos[eTotal].eIdArticulo); /*Asigna a eIdArt�culo el valor de LeerIdArt�culo*/
					
					if (eIdArticulo > -1){ //Si el IdArt�culo es mayor a -1 (el arreglo no est� vac�o) entonces...					
						BorrarArticulo(aArticulos, &eTotal, eIdArticulo); //Se invoca a la funci�n borrar art�culo...
						
					} 
										
		  			break;
		  			
			case 3: system("cls");
					dibujarMarco();
	
					moverCursor (2, 33);
					printf("%cBienvenid%c a la farmacia Ixoye - Actualizar Art%cculo!", 173, 64, 161);
					eIdArticulo = LeerIdArticulo("modificar", eTotal, aArticulos[eTotal].eIdArticulo); //Asignar a eIdArt�culo el valor de LeerIdArt�culo.
					
					if (eIdArticulo > -1){ //Si el idArt�culo es mayor a menos uno...					
						ModificarArticulo(aArticulos, eTotal, eIdArticulo);	//Llamar a modificar art�culo...
					} 
					break;
					
			case 4: system("cls"); 
					dibujarMarco();
					
					moverCursor (2, 34);
					printf("%cBienvenid%c a la farmacia Ixoye - Consultar Art%cculo!", 173, 64, 161);
					moverCursor (10, 45);
					printf("1. Consultar por ID");
					moverCursor (13, 45);
					printf("2. Consultar por nombre");
					moverCursor (16, 45);
					printf("3. Regresar a sub-men%c Art%cculos", 163, 161);
					
					linea (22);
					moverCursor (25, 35);
					printf("Ingresa el n%cmero de la consulta que deseas realizar: ", 163);
					moverCursor (25, 89);
					scanf("%d", &eOpcionC);
					
					system("cls");
					switch (eOpcionC){
						
						case 1: system("cls");
								dibujarMarco();
								moverCursor (2, 30);
								printf("%cBienvenid%c a la farmacia Ixoye - Consultar Art%cculo por ID!", 173, 64, 161);
								eIdArticulo = LeerIdArticulo("consultar", eTotal, aArticulos[eTotal].eIdArticulo); //Asignar a eIdArt�culo el valor de leeridArt�culo
										
								if (eIdArticulo > -1){	//Si el idArt�culo es mayor a -1 (si el art�culo existe)									
								ConsultarArticuloPorId(aArticulos, eTotal, eIdArticulo); //Mandar a llamar al procedimiento consultar art�culo.
								MenuArticulos();
								
								} else {
									
									fflush(stdin);
									MenuArticulos();
								}
								
								break;
								
						case 2: system("cls");
								dibujarMarco();
								moverCursor (2, 28);
								printf("%cBienvenid%c a la farmacia Ixoye - Consultar Art%cculo por Nombre!", 173, 64, 161);
								moverCursor(6, 45);
								printf("Ingresa el nombre del art%cculo: ", 161);
								moverCursor(6, 77);
								fflush(stdin);
								gets(cNombre);
								
								ePos = 	BuscarBinario(aArticulos, eTotal, cNombre);
								
								if (ePos > -1){ //Si ePos es mayor a -1 (s� se encontr� el art�culo).
								
								    ConsultarArticuloPorNombre(aArticulos, eTotal, cNombre); //Mandar a llamar al procedimiento consultar art�culo.
									MostrarDatosArticulo(aArticulos[ePos]);
									linea(26);
									moverCursor(26, 50);
									printf(" %cConsulta exitosa! ", 173);
									moverCursor(28, 40);
									system("pause");
									MenuArticulos();
									
								} else {
									
									fflush(stdin);
									linea(26);
									moverCursor(26, 40);
									printf("No se encontr%c el art%cculo %s", 162, 161, cNombre);
									moverCursor(28, 40);
									system("pause");
									MenuArticulos();
								}						
							    break;
							
						case 3: MenuArticulos();
								break;
								
						default: moverCursor(28, 49);
								 printf("---------Error en la selecci%cn---------", 162);
								 break;	
								 
					} while (eOpcionC != 3); //Mientras la opci�n sea diferente de 3
					
					MenuArticulos();
					break;
					
			case 5: system("cls"); 
					dibujarMarco();
					
					moverCursor(2, 35);
					printf("%cBienvenid%c a la farmacia Ixoye - Listar Art%cculo!", 173, 64, 161);
					moverCursor(9, 45);
					printf("1. Listar art%cculo por ID", 161);
					moverCursor(12, 45);
					printf("2. Listar art%cculo por nombre", 161);
					moverCursor(15, 45);
					printf("3. Listar art%cculo por tipo ", 161);
					moverCursor(18, 45);
					printf("4. Regresar a sub-men%c Art%cculos", 163, 161);
					linea(24);
					moverCursor(26, 34);
					printf("Ingresa el n%cmero de listado que deseas visualizar:", 163);
					fflush(stdin);
					moverCursor(26, 87);
					scanf("%d", &eOpcionL);
					
					system("cls");
					dibujarMarco();
					
					switch(eOpcionL){
						
						case 1: moverCursor(2, 47);
								printf("Lista de art%cculos por ID:", 161);
								moverCursor(6, 2);		
								printf("|ID| Nombre |Presentaci%cn|Fec.Caducidad| Marca | Proveedor |Ex.M%cxima|Ex.M%cnima|Precio|Costo|Fec.Registro| ", 162, 160, 161);
								linea(8);
								OrdenarPorId(aArticulos, eTotal); //Ejecutar OrdenarPorId (antes de mostrarlos). 
								moverCursor(9,2);
								ListarPorId(aArticulos, eTotal);
								moverCursor(29,40);
								system("pause");
								MenuArticulos();
								break;
								
						case 2: moverCursor(2, 55);
								printf("Lista de art%cculos por nombre: ", 161);
								moverCursor(6, 2);		
								printf("| Nombre |ID|Presentaci%cn|Fec.Caducidad| Marca | Proveedor |Ex.M%cxima|Ex.M%cnima|Precio|Costo|Fec.Registro| ", 162, 160, 161);
								linea(8);
								OrdenarPorNombre(aArticulos, eTotal);
								moverCursor(9,2);
								ListarPorNombre(aArticulos, eTotal);
								moverCursor(29,40);
								system("pause");
								MenuArticulos();
								break;
								
						case 3: moverCursor(2, 46);
								printf("Lista de art%cculos por tipo:", 161);
								moverCursor(6, 2);		
								printf("ID| Nombre |Presentaci%cn|Fec.Caducidad| Marca | Proveedor |Ex.M%cxima|Ex.M%cnima|Precio|Costo|Fec.Registro|  Tipo  |", 162, 160, 161);
								linea(8);
								OrdenarPorTipo(aArticulos, eTotal);
								moverCursor(9,2);
								ListarPorTipo(aArticulos, eTotal);
								moverCursor(29,40);
								system("pause");
								MenuArticulos();
								break;
								
						case 4: MenuArticulos();
								break;
								
						default:moverCursor(14, 49);
								 printf("---------Error en la selecci%cn---------", 162);
								 break;	
					} 
					break;
					
			case 6: main (); //Ejecutar men� principal.
					break;

			default:dibujarMarco();
					moverCursor(14, 49);
					printf("---------Error en la selecci%cn---------", 162);
					break;
		} 
		
		fflush(stdin);
		getchar();
	    
	} while (eOpcionA != 6);//Mientras la opci�n sea diferente de 6.
    
    
} //main



/* **********************************************************************
	PROCEDIMIENTO: LeerArticulo
	AUTOR: L�pez Alejaldre Daniela V. / Segura Rios Brenda Stephanie
	FECHA DE CREACI�N: 10 de junio del 2019.
	OBJETIVO: Crear el m�dulo que permitir� leer los datos de un art�culo.
	DE(PE): Ninguno.
	DS(PS): Registro del art�culo.
	Retorna: Una colecci�n de datos heterog�nea correspondiente a los datos del art�culo (TrArticulo)
********************************************************************** */
TrArticulo LeerArticulo(){ 
	
	TrArticulo rArticulo; //Variable rArticulo de tipo registro de art�culo.
	TaCadena cTipo; //Permitir� mostrar el tipo del art�culo seg�n el enumerado. 

	system("cls");
	dibujarMarco();
	
	moverCursor (2, 33);
	printf("%cBienvenid%c a la farmacia Ixoye - Registrar Art%cculo!", 173, 64, 161);
	moverCursor (6, 39);
	printf("Ingrese los siguientes datos del art%cculo: ", 161);
	
	moverCursor (9, 45);
	printf("%c Nombre: ", 207);
	fflush(stdin); //Limpia el buffer. 
	moverCursor (9, 56);
	gets(rArticulo.cNombre); //Obtener/leer el registro art�culo en el campo cNombre 
	
	moverCursor (10, 45);
	printf("%c Presentaci%cn: ", 207, 162);
	fflush(stdin);
	moverCursor (10, 62);
	gets(rArticulo.cPresentacion);
	
	moverCursor (12, 45);
	printf("%c Fecha de caducidad: ", 207);
	moverCursor (13, 50);
	printf("Dia: ");
	fflush(stdin);
	moverCursor (13, 55);
	scanf("%d", &rArticulo.rFecCaducidad.eDia);
	moverCursor (14, 50);
	printf("Mes: ");
	fflush(stdin);
	moverCursor (14, 55);
	scanf("%d", &rArticulo.rFecCaducidad.eMes);
	moverCursor (15, 50);
	printf("A%co: ", 164);
	fflush(stdin);
	moverCursor (15, 55);
	scanf("%d", &rArticulo.rFecCaducidad.eAnio);
	
	moverCursor (17, 45);
	printf("%c Marca: ", 207);
	fflush(stdin);
	moverCursor (17, 55);
	gets(rArticulo.cMarca);
	
	moverCursor (18, 45);
	printf("%c Proveedor: ", 207);
	fflush(stdin);
	moverCursor (18, 59);
	gets(rArticulo.cProveedor);
	
	moverCursor (19, 45);
	printf("%c Existencia m%cxima: ", 207, 160);
	fflush(stdin);
	moverCursor (19, 67);
	scanf("%d", &rArticulo.eExistenciaMax); //Leer un entero dentro del registro rArt�culo en el campo eExistenciaMax
	
	moverCursor (20, 45);
	printf("%c Existencia m%cnima: ", 207,161);
	fflush(stdin);
	moverCursor (20, 67);
	scanf("%d", &rArticulo.eExistenciaMin);
	
	moverCursor (21, 45);
	printf("%c Precio unitario: %c", 207, 36);
	fflush(stdin);
	moverCursor (21, 66);
	scanf("%f", &rArticulo.fPrecio); //Leer un flotante dentro del registro rArt�culo en el campo fPrecio. 
	
	moverCursor (22, 45);
	printf("%c Costo unitario: %c", 207, 36);
	fflush(stdin);
	moverCursor (22, 65);
	scanf("%f", &rArticulo.fCosto);
	
	moverCursor (24, 45);
	printf("%c Tipo de art%cculo: ", 207, 161);
	fflush(stdin);
	moverCursor (24, 65);
	scanf("%d", &rArticulo.eTipo);
	ObtenerTipo(rArticulo.eTipo, cTipo);
	moverCursor (25, 60);
	printf("%c %s %c", 62, cTipo, 60);
	
	system("cls");
	dibujarMarco();
	moverCursor (2, 33);
	printf("%cBienvenid%c a la farmacia Ixoye - Registrar Art%cculo!", 173, 64, 161);

	moverCursor (12, 45);
	printf("%c Fecha de registro: ", 207);
	moverCursor (13, 50);
	printf("Dia: ");
	fflush(stdin);
	moverCursor (13, 55);
	scanf("%d", &rArticulo.rFecRegistro.eDia);
	moverCursor (14, 50);
	printf("Mes: ");
	fflush(stdin);
	moverCursor (14, 55);
	scanf("%d", &rArticulo.rFecRegistro.eMes);
	moverCursor (15, 50);
	printf("A%co: ", 164);
	fflush(stdin);
	moverCursor (15, 55);
	scanf("%d", &rArticulo.rFecRegistro.eAnio);
	
	rArticulo.eIdArticulo = GenerarIdArticulo(); //Invoco a la funci�n que genera el ID del art�culo. 
	
	return rArticulo;

}//FinProcedimiento LeerArt�culo. 


/* **********************************************************************
	PROCEDIMIENTO: RegistrarArticulo
	AUTOR: L�pez Alejaldre Daniela V.
	FECHA DE CREACI�N: 10 de junio del 2019.
	OBJETIVO: Crear el m�dulo que permitir� registrar art�culos. 
	DE(PE): aArticulos es un arreglo, e Total es un n�mero entero positivo, rArticulo, es un registro.
	DS(PS): N�mero entero, positivo. 
	Retorna: Un n�mero entero, positivo correspondiente al resultado de la opci�n seleccionada (eOpcionC)
********************************************************************** */
void RegistrarArticulo(TaArticulos aArticulos, int *eTotal, TrArticulo rArticulo){ //Definici�n del procedimiento RegistrarArticulo. 
	
	int eRecorre; //Variable que permitir� recorrer el arreglo.
	
	if (*eTotal == MAX_ARTICULOS - 1){ //Si el total del arreglo es igual al n�mero m�ximo de art�culos posibles de registrar, entonces...
		
		moverCursor (28, 42);
		printf("No se pueden agregar m%cs art%cculos.", 160, 161); //Mostrar que no se pueden ingresar m�s art�culos.
		
	} else { //de lo contrario...
		
		if (*eTotal == -1 || rArticulo.eIdArticulo > aArticulos[*eTotal].eIdArticulo){ /*Si el �ndice del arreglo de art�culos est� en 0 o si el registro del
		art�culo en el campo eIdArticulo es mayor al arreglo de art�culos en la posici�n eTotal en el campo IdArt�culo, entonces...*/
			
			(*eTotal) ++; //Incrementar el valor de eTotal en uno.
			
			aArticulos[*eTotal] = rArticulo; //Asignar al arreglo art�culos en la posici�n eTotal el registro del art�culo.
			moverCursor (28, 45);
			printf("%c%s%c registrado correctamente.", 34, rArticulo.cNombre, 34); //Mostrar que el art�culo ha sido registrado de forma exitosa.
			
		} else { //De lo contrario...
			
			if (BuscarArticuloPorId(aArticulos, *eTotal, rArticulo.eIdArticulo) != -1 ){ //Si buscar Art�culo por ID es diferente de 0...
				
				moverCursor (28, 54);
				printf("Ya existe %d", rArticulo.eIdArticulo); //Mostrar que ya existe el art�culo.
				
			} else { //De lo contrario...
				
				eRecorre = *eTotal; //Asignar a eRecorre el valor de eTotal
				
				while (eRecorre >= 0 && aArticulos[eRecorre].eIdArticulo > rArticulo.eIdArticulo){ /*Mientras eRecorre sea mayor a 0 y el arreglo de art�culos 
				en la posici�n eRecorre en el campo IDArt�culo sea mayor que el registro de art�culos en la posici�n IDArt�culo hacer... */
					
					aArticulos[eRecorre + 1] = aArticulos[eRecorre]; //Asignar al arreglo en la posici�n eRecorre + 1 el registro del art�culo en la posici�n eRecorre.
					eRecorre --; //Decrementar el valor de eRecorre en uno.
				}
				aArticulos[eRecorre + 1] = rArticulo; //Asignar al arreglo de art�culos en la posici�n eRecorre + 1, el registro del art�culo.
				(*eTotal) ++; //Incrementar el valor de total en uno.
				
				moverCursor (28, 45);
				printf("%c%s%c registrado correctamente", 34, rArticulo.cNombre, 34); //Mostrar que el registro del art�culo se realiz� adecuadamente. 
			}
		}
	}	
}//FinProcedimiento RegistrarArt�culo


/* **********************************************************************
	FUNCI�N: BuscarArticuloPorId.
	AUTOR: L�pez Alejaldre Daniela V.
	FECHA DE CREACI�N: 10 de junio del 2019.
	OBJETIVO: Crear el m�dulo que permitir� buscar un art�culo de acuerdo con su Id.
	DE(PE): Arreglo de art�culos (TaArticulos aArticulos), n�mero entero, positivo, �ndice del arreglo (eTotal), n�mero entero, positivo, que indica el Id del art�culo (eIdArticulo)
	DS(PS): Registro del art�culo.
	Retorna: Una colecci�n de datos heterog�nea correspondiente a los datos del art�culo (TrArticulo)
********************************************************************** */
int BuscarArticuloPorId(TaArticulos aArticulos, int eTotal, int eIdArticulo){ 
	
	int eMenor, eMayor, eMedio; //Declaro variables locales que me permitir�n realizar una b�squeda binaria.
	
	if (eTotal == -1){ //Si total = -1 (arreglo vac�o).
		
		return -1; //Regresar -1, en el caso de un arreglo que empieza desde 1, ser�a 0.
		
	} else {
		
		eMenor = 0; //Asignar a eMenor el valor de 0.
		eMayor = eTotal; //Asignar a eMayor el valor de eTotal.
		eMedio = (eMayor + eMenor) / 2; //Calcular eMedio = eMayor + eMenor / 2
		
		while (eMenor < eMayor && aArticulos[eMedio].eIdArticulo != eIdArticulo){ /*Mientras eMenor sea menor a eMayor Y el arreglo de art�culos en la posici�n
		de eMedio en el campo eIdArt�culo sea diferente de eIdArt�culo (mientras no exista el id)
		*/
			if (eIdArticulo < aArticulos[eMedio].eIdArticulo){ /*Si el id del art�culo es menor al arreglo de art�culos en la posici�n eMedio en el campo eidArticulo 
			(se encuentra de la mitad del arreglo para abajo)*/
			
				eMayor = eMedio - 1; //Hacer que eMayor tome el valor de eMedio - 1 (que busque de la mitad del arreglo hacia abajo). 
				
			} else { //De lo contrario (se encuentra de la mitad del arreglo para arriba).
				
				eMenor = eMedio + 1; //Hacer que eMenor tome el valor de eMedio + 1 (que busque de la mitad del arreglo hacia arriba).
			} 
			
			eMedio = (eMenor + eMayor) / 2; //Volver a calcular eMedio con los nuevos valores de eMenor, eMayor. 
		}
		
		if (eIdArticulo == aArticulos[eMedio].eIdArticulo){//Si el id del art�culo es igual al arreglo en la posici�n del centro en el campo eIdArt�culo
			
			return eMedio; //Regresar el valor de eMedio (posici�n del arreglo en donde se encuentra el ID del art�culo).
			 
		} else{ //De lo contrario...
			
			return -1; //Indica que no se encontr�.
		
		}
	}
}//FinFunci�n BuscarArt�culoPorId.


/* **********************************************************************
	FUNCI�N: BuscarBinario
	AUTOR: L�pez Alejaldre Daniela V.
	FECHA DE CREACI�N: 11 de junio del 2019.
	OBJETIVO: Crear el m�dulo que permitir� buscar un art�culo de acuerdo con su nombre.
	DE(PE): Arreglo de art�culos (TaArticulos aArticulos), n�mero entero, positivo, �ndice del arreglo (eTotal), cadena de caracteres que indica el nombre del art�culo a buscar (cNombre)
	DS(PS): Posici�n en la que se encuentra el art�culo, n�mero entero, positivo. 
	Retorna: ePos
********************************************************************** */
int BuscarBinario (TaArticulos aArticulos, int eTotal, TaCadena cNombre){
	
	int eMenor, eMayor, eMedio; //Variables locales.
	
	if (eTotal == -1){ //Si el �ndice del arreglo indica que no hay elementos...
		
		return -1; //Regresar -1
		
	} else { //De lo contrario...
		
		eMenor = 0; //Hacer eMenor = 0
		eMayor = eTotal; //Hacer eMayor = eTotal.
		eMedio = (eMayor + eMenor) / 2; //Calcular eMedio es igual a la suma de eMayor + eMenor / 2
		
		while (eMenor < eMayor && strcmp(aArticulos[eMedio].cNombre, cNombre) != 0){ //Mientras eMenor sea menor que eMayor y el arreglo de art�culos en la posici�n de medio sea diferente de cNombre
			
			if (strcmp(cNombre, aArticulos[eMedio].cNombre) > 0){ //Si cNombre es mayor que el arreglo en la posici�n de eMedio (se encuentra de la mitad del arreglo hacia arriba).
				
				eMenor = eMedio + 1; //Hacer eMenor = eMedio + 1, buscar de la mitad del arreglo hacia arriba.
				
			} else { //De lo contrario...
				
				eMayor = eMedio - 1; //Hacer eMayor = eMedio - 1, buscar de la mitad del arreglo hacia abajo.
			}
		
			eMedio = (eMenor + eMayor) / 2; //Calcular eMedio nuevamente.
		} 
	
		if (strcmp(aArticulos[eMedio].cNombre, cNombre) == 0){ //Si el arreglo en la posici�n de medio es igual al nombre a buscar.
		
			return eMedio; //Regresar el valor de eMedio
		
		} else { //De lo contrario...
		
			return -1; //Regresar -1 (no se encontr�). 
		}
	}
}


/* **********************************************************************
	FUNCI�N: GenerarIdArticulo.
	AUTOR: L�pez Alejaldre Daniela V.
	FECHA DE CREACI�N: 10 de junio del 2019.
	FECHA DE �LTIMA ACTUALIZACI�N: 
	OBJETIVO: Crear el m�dulo que permitir� generar el ID de un art�culo. 
	DE(PE): Ninguno.
	DS(PS): N�mero entero, positivo. 
	Retorna: Un n�mero entero, positivo correspondiente al ID del art�culo generado (eSiguiente)
********************************************************************** */
int GenerarIdArticulo(){ //Funci�n generar ID art�culo.
	
	static int eSiguiente = 1; //Variable que generar� los ID, empezando por uno.
	
	return (eSiguiente ++); //Regresar eSiguiente + 1
}//FinFunci�n Generar ID art�culo.  


/* **********************************************************************
	PROCEDIMIENTO: ObtenerTipo
	AUTOR: L�pez Alejaldre Daniela V.
	FECHA DE CREACI�N: 10 de junio del 2019.
	OBJETIVO: Crear el m�dulo que permitir� obtener el tipo de art�culo de acuerdo a un enumerado.
	DE(PE): N�mero entero, positivo, correspondiente al enumerado TeTipo (eTipo), cadena de caracteres (TaCadena cTipo).
	DS(PS): Ninguno.
	Retorna: No regresa nada. 
********************************************************************** */
void ObtenerTipo(int eTipo, TaCadena cTipo){
	
	switch(eTipo){ //En caso de eTipo, hacer...
		
		case ALIMENTOS: strcpy(cTipo, "Alimentos y bebidas"); //Asignar a la cadena cTipo el valor de "Alimentos y bebidas".
						break; //Romper/terminar el ciclo. 
		case BOTICA: strcpy (cTipo, "Botica"); //Asignar a la cadena cTipo el valor de "Botica".
					 	break;
		case MEDICAMENTOS: strcpy(cTipo, "Medicamentos"); //Asignar a la cadena cTipo el valor de "Medicamentos".
						break;
		case PERFUMES: strcpy(cTipo, "Perfumes"); //Asignar a la cadena cTipo el valor de "Perfumes".
					   break;
		default: strcpy(cTipo, "Indefinido"); //Asignar a la cadena cTipo el valor de "Indefinido".
				 break; //Romper/terminar el ciclo.
	} //Fin en caso de.
}//FinProcedimiento ObtenerTipo.


/* **********************************************************************
	PROCEDIMIENTO: BorrarArticulo
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACI�N: 11 de junio del 2019.
	OBJETIVO: Crear una funcipon que permita borrar un art�culo.
	DE(PE): Arreglo de art�culos (aArticulos), n�mero entero, positivo, que corresponde al �ndice del arreglo (eTotal), n�mero entero, positivo, correspondiente al Id del art�culo (eIdArticulo).
	DS(PS): Ninguno.
	Retorna: Ning�n valor. 
********************************************************************** */
void BorrarArticulo (TaArticulos aArticulos, int *eTotal, int eIdArticulo){
	
	int ePos, eRecorre; //Variables locales. 
	char cConfirma; 
	
	if (*eTotal == -1){ //Si el total es igual a -1 (arreglo vac�o), entonces...
		
		moverCursor (14, 42);
		printf("-- No hay art%cculos registrados. --", 161);
		moverCursor (15, 42);
		system("pause"); //Detener el programa. 
		
	} else { //De lo contrario...
		
		ePos = BuscarArticuloPorId(aArticulos, *eTotal, eIdArticulo); //Asignar a ePos el valor de la funci�n BuscarArticuloPorId
		
		if (ePos == -1) { //Si la posici�n es igual a -1 (no se encontr�).
			
			fflush(stdin);
			linea(26);
			moverCursor (14, 50);
			printf("El ID [%d] no existe.", eIdArticulo);
			moverCursor (28, 40);
			system("pause"); //Detener el programa. 
					
		} else { //De lo contrario...

			MostrarDatosArticulo(aArticulos[ePos]); //Invocar a la funci�n MostrarDatosArticulo
			linea(27); 
			moverCursor (27, 42); //Formato de pantalla.
			printf(" %cDesea borrar el registro? [S/N]: ", 168);
			fflush(stdin); //Limpia el buffer.
			moverCursor (27, 77);
			cConfirma = getchar(); //Leer el valor de cConfirma.
			
			if (cConfirma == 's' || cConfirma == 'S'){ //Si cConfirma es igual a "s" � a "S" hacer...
			
				for (eRecorre = ePos; eRecorre < *eTotal; eRecorre++){ //Desde eRecorre con el valor ePos, mientras eRecorre sea menor que el total del arreglo, incrementar su valor en uno.
					
					aArticulos[eRecorre] = aArticulos[eRecorre + 1]; //Asignar al arreglo de art�culos en la posici�n eRecorre el valor de art�culos en la posici�n eRecorre + 1
				}
				
				(*eTotal)--; //Decrementar el �ndice en uno.
				moverCursor (28, 43);
				printf(" Art%cculo borrado correctamente. ", 161);
			}
		}
	}
} //BorrarArticulo


/* **********************************************************************
	FUNCI�N: LeerIdArticulo
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACI�N: 11 de junio del 2019.
	OBJETIVO: Crear el m�dulo que permite leer el ID ingresado.
	DE(PE): cOperaci�n, cadena que indica la operaci�n del modulo, eTotal, entero
			positivo, eUltimoID, entero positivo.
	DS(PS): eId, regresa el id ingresado, -1 indica que no hay art�culos.
	Retorna: eID o -1. 
********************************************************************** */
int LeerIdArticulo(TaCadena cOperacion, int eTotal, int eUltimoId){
	
	int eId;
		
	if (eTotal == -1) {
		
		moverCursor (14, 42);
		printf ("-- No hay art%cculos registrados. --", 161);
		fflush(stdin);
		getchar();
		return -1;
		
	} else {

		do {
			
			moverCursor (6, 38);
			printf("Ingrese el ID del art%cculo a %s: ", 161, cOperacion);
			fflush(stdin);
			moverCursor (6, 80);
			scanf("%d", &eId);
		
		} while (eId < 1 || eId > eUltimoId);
	
		return eId;
	} 
} //LeerIdArticulo


/* **********************************************************************
	FUNCI�N: MostrarDatosArticulo
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACI�N: 11 de junio del 2019.
	OBJETIVO: Crear el m�dulo que permite mostrar los datos guardados del Articulo.
	DE(PE): rArticulo es un registro.
	DS(PS): Imprime datos del art�culo.
********************************************************************** */
void MostrarDatosArticulo(TrArticulo rArticulo){
	
	int eNombre, eIdArticulo;
	char cOtro;
	TaCadena cTipo;
	
	moverCursor (9, 48); 
	printf("Datos del art%cculo: [%d]", 161, rArticulo.eIdArticulo);
	
	moverCursor (12, 45); 
	printf("%c Nombre: %s", 207, rArticulo.cNombre);
	moverCursor (13, 45); 
	printf("%c Presentac%cn: %s", 207, 162, rArticulo.cPresentacion);
	moverCursor (14, 45); 
	printf("%c Fecha de caducidad: %02d/%02d/%02d", 207,
		rArticulo.rFecCaducidad.eDia, rArticulo.rFecCaducidad.eMes, rArticulo.rFecCaducidad.eAnio);
	moverCursor (15, 45); 
	printf("%c Marca: %s", 207, rArticulo.cMarca);	
	moverCursor (16, 45); 
	printf("%c Proveedor: %s", 207, rArticulo.cProveedor);
	moverCursor (17, 45); 
	printf("%c Existencias m%cximas: %d", 207, 160, rArticulo.eExistenciaMax);	
	moverCursor (18, 45); 
	printf("%c Existencias m%cnimas: %d", 207, 161, rArticulo.eExistenciaMin);
	moverCursor (19, 45); 
	printf("%c Precio unitario: %.2f", 207, rArticulo.fPrecio);
	moverCursor (20, 45); 
	printf("%c Costo unitario: %.2f", 207, rArticulo.fCosto);
	moverCursor (21, 45); 
	printf("%c Fecha de registro: %02d/%02d/%02d", 207,
		rArticulo.rFecRegistro.eDia, rArticulo.rFecRegistro.eMes, rArticulo.rFecRegistro.eAnio);
	
	ObtenerTipo(rArticulo.eTipo, cTipo);
	moverCursor (22, 45); 
	printf("%c Tipo de art%cculo: %s", 207, 161, cTipo);	
	
} //MostrarDatosArticulo


/* **********************************************************************
	PROCEDIMIENTO: ConsultarAriculoPorId
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACI�N: 11 de junio del 2019.
	OBJETIVO: Crear una funcipon que permita buscar el registro de un articulo ingresando su ID.
	DE(PE): Colecci�n de registros de un art�culo (aArticulos), n�mero entero, positivo, 
			correspondiente al �ndice del arreglo (eTotal), n�mero entero, positivo, correspondiente al id del art�culo (eIdArticulo).
********************************************************************** */
void ConsultarArticuloPorId(TaArticulos aArticulos, int eTotal, int eIdArticulo){

	int ePos;
    
    fflush(stdin);
	ePos = BuscarArticuloPorId(aArticulos, eTotal, eIdArticulo); // Llama a la funci�n para buscar el ID ingresado
	
	if (ePos > -1){
	
		MostrarDatosArticulo(aArticulos[ePos]);	
		linea(26);
		moverCursor(26, 50);
		printf(" %cConsulta exitosa! ", 173);
		moverCursor(28, 40);
		system("pause");
		
	} else {
		
		fflush(stdin);
		linea(26);
		moverCursor(26, 46);
		printf(" No se encontr%c el ID [%d]: ", 162, eIdArticulo);
		moverCursor(28, 40);
		system("pause");
		
	}
} //ConsultarArticuloPorId


/* **********************************************************************
	PROCEDIMIENTO: ConsultarArticuloPorNombre
	AUTOR: L�pez Alejaldre Daniela Viridiana.
	FECHA DE CREACI�N: 11 de junio del 2019.
	OBJETIVO: Crear un m�dulo que permita consultar el registro de un articulo ingresando su Nombre. 
	DE(PE): Arreglo de art�culos (aArticulos), n�mero entero, positivo correspondiente al �ndice del arreglo (eTotal).
	DS(PS): Ninguno.
	Retorna: Ninguno.
********************************************************************** */
void ConsultarArticuloPorNombre(TaArticulos aArticulos, int eTotal, TaCadena cNombre){
	
	int ePos;

	ePos = BuscarBinario(aArticulos, eTotal, cNombre); //Asignar a ePos el valor de la funci�n BuscarBinario.
	
	if (ePos > -1){ //Si la posici�n es mayor a -1 (s� se encontr� el art�culo)
	
		MostrarDatosArticulo(aArticulos[ePos]);	//Invocar a la funci�n mostrar datos art�culo en la posici�n indicada. 
		moverCursor(27, 52);
		printf(" Para regresar: ");
		
	} else { //De lo contrario...
		
		moverCursor(27, 45);
		printf(" No se encontr%c el art%cculo %c %s %c:", 162, 161, 34, cNombre, 34); //Mostrar mensaje indicando que no se encontr� el art�culo. 
	
	}
	
}

/* **********************************************************************
	PROCEDIMIENTO: ModificarArticulo
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACI�N: 11 de junio del 2019.
	FECHA DE �LTIMA ACTUALIZACI�N: 11 de junio del 2019 por L�pez A. Daniela Viridiana.
	OBJETIVO: Crear el m�dulo que permite modificar o actualizar los datos guardados del Articulo.
	DE(PE): El arreglo de art�culos (aArt�culos), un n�mero entero, positivo correspondiente al �ndice del arreglo (eTotal) y un n�mero entero, positivo, correspondiente al Id del art�culo (eIdArticulo).
	DS(PS): Ninguno. 
	Retorna: Ning�n valor. 
********************************************************************** */
void ModificarArticulo(TaArticulos aArticulos, int eTotal, int eIdArticulo){
	
	int ePos, eDato, eNuevo; //Variables locales, enteras.
	TaCadena cTipo, cNuevo; //Variable local de tipo cadena. 
	float fNuevo;
	
	if (eTotal == -1){ //Si total es igual a menos uno, entonces...
		
		moverCursor (14, 42);
		printf ("-- No hay art%cculos registrados. --", 161); //Mostrar que no hay arreglos registrados...
		
	} else { //De lo contrario...
		
		ePos = BuscarArticuloPorId(aArticulos, eTotal, eIdArticulo); //Asignar a la variable ePos el valor del procedimiento BuscarArt�culoPorId
		
		if (ePos == -1) { //Si la posici�n retornada es -1, entonces... (no se encontr� el art�culo).
			
			moverCursor (14, 30);
			printf("-- El ID [%d] no existe, no se pudo encontrar el art%cculo.--", eIdArticulo, 161); //Mostrar que el ID no existe.
			
		} else { //De lo contrario...

			do { //Repetir...
					
				MostrarDatosArticulo(aArticulos[ePos]); //Invocar a la funci�n MostrarDatosArt�culo...
				moverCursor(9,10);
				printf("--Opciones:--");
				moverCursor(12,8);
				printf("1. Nombre"
						"\n\t2. Presentaci%cn"
						"\n\t3. Fecha de caducidad"
						"\n\t4. Marca"
						"\n\t5. Proveedor"
						"\n\t6. Existencias m%cximas"
						"\n\t7. Existencias m%cnimas"
						"\n\t8. Precio unitario"
						"\n\t9. Consto unitario"
						"\n\t10. Fecha de registro"
						"\n\t11. Tipo"
						"\n\t12. Regresar", 162, 160, 161);
				
				linea(26);
				moverCursor (26, 40);
				printf(" Seleccione el dato a modificar: "); //Solicitar el dato que se desea modificar...
				moverCursor (26, 73);
				scanf("%d", &eDato); //Leer el dato.
				fflush(stdin);
				
				system("cls");
				dibujarMarco();
				moverCursor (2, 33);
				printf("%cBienvenid%c a la farmacia Ixoye - Actualizar Art%cculo!", 173, 64, 161);
				
				switch(eDato){ //En caso de el valor del dato hacer...
					
					case 1: 
							moverCursor (28, 45);
							printf(" Nuevo Nombre:  ");
							fflush(stdin);
							moverCursor (28, 61);
							gets(cNuevo); //Leer el nuevo valor(cadena).
							strcpy (aArticulos[ePos].cNombre, cNuevo); //Asignar al arreglo de art�culos en la posici�n ePos, el valor del nuevo dato ingresado 
							break;
					
					case 2:	moverCursor (28, 45);
							printf(" Nueva Presentaci%cn:  ", 162);
							fflush(stdin);
							moverCursor (28, 66);
							gets(cNuevo); //Leer el nuevo valor (cadena).
							strcpy(aArticulos[ePos].cPresentacion, cNuevo); //Asignar al arreglo de art�culos en la posici�n ePos en el campo cPresentaci�n el nuevo dato ingresado.
							break;
							
					case 3: moverCursor (28, 45);
							printf(" Nueva Fecha de Caducidad: "); 		
							moverCursor (29, 51);
							printf("Dia: ");
							fflush(stdin);
							moverCursor (29, 56);
							scanf("%d", &eNuevo); //Leer el nuevo valor (entero).
							aArticulos[ePos].rFecCaducidad.eDia = eNuevo; //Asignar al arreglo de art�culos en la posici�n ePos en el campo rFecCaducidad en el subcampo eDia el nuevo valor ingresado. 
							moverCursor (30, 51);
							printf("Mes: ");
							fflush(stdin);
							moverCursor (30, 56);
							scanf("%d", &eNuevo);
							aArticulos[ePos].rFecCaducidad.eMes = eNuevo;
							moverCursor (31, 51);
							printf("A%co: ", 164);
							fflush(stdin);
							moverCursor (31, 56);
							scanf("%d", &eNuevo);
							aArticulos[ePos].rFecCaducidad.eAnio = eNuevo;
							break;
		
					case 4: moverCursor (28, 46);
							printf(" Nueva Marca:  ");
							fflush(stdin);
							moverCursor (28, 60);
							gets(cNuevo);
							strcpy(aArticulos[ePos].cMarca, cNuevo);
							break;
							
					case 5: moverCursor (28, 47);
							printf(" Nuevo Proveedor:  ");
							fflush(stdin);
							moverCursor (28, 65);
							gets(cNuevo);
							strcpy (aArticulos[ePos].cProveedor, cNuevo);
							break;
		
					case 6: moverCursor (28, 45);
							printf(" Nuevas Exictencias M%cximas:  ", 160);
							fflush(stdin);
							moverCursor (28, 74);
							scanf("%d", &eNuevo);
							aArticulos[ePos].eExistenciaMax = eNuevo;
							break;
		
					case 7: moverCursor (28, 46);
							printf(" Nuevas Existencias M%cnimas:  ", 161);
							fflush(stdin);
							moverCursor (28, 75);
							scanf("%d", &eNuevo);
							aArticulos[ePos].eExistenciaMin = eNuevo;
							break;
					
					case 8: moverCursor (28, 45);
							printf(" Nuevo Precio Unitario:  ");
							fflush(stdin);
							moverCursor (28, 69);
							scanf("%f", &fNuevo);
							aArticulos[ePos].fPrecio = fNuevo;
							break;
		
					case 9: moverCursor (28, 47);
							printf(" Nuevo Costo Unitario:  ");
							fflush(stdin);
							moverCursor (28, 70);
							scanf("%f", &fNuevo);
							aArticulos[ePos].fCosto = fNuevo;
							break;
								
					case 10:moverCursor (28, 45);
							printf(" Nueva Fecha de registro: ");
							moverCursor (29, 51);
							printf("Dia: ");
							fflush(stdin);
							moverCursor (29, 56);
							scanf("%d", &eNuevo);
							aArticulos[ePos].rFecRegistro.eDia = eNuevo;
							moverCursor (30, 51);
							printf("Mes: ");
							fflush(stdin);
							moverCursor (30, 56);
							scanf("%d", &eNuevo);
							aArticulos[ePos].rFecRegistro.eMes = eNuevo;
							moverCursor (31, 51);
							printf("A%co: ", 164);
							fflush(stdin);
							moverCursor (31, 56);
							scanf("%d", &eNuevo);
							aArticulos[ePos].rFecRegistro.eAnio = eNuevo;
							break;
				
					case 11:moverCursor (28, 53);
							printf(" Nuevo Tipo:  ");
							fflush(stdin);
							moverCursor (28, 66);
							scanf("%d", &aArticulos[ePos].eTipo);
							ObtenerTipo(aArticulos[ePos].eTipo, cTipo);
							moverCursor (29, 52);
							printf("%c%s%c", 62, cTipo, 60);
							break;
					
					
					case 12:moverCursor (14, 42);
							printf(" Registro modificado correctamente.");
							moverCursor (15, 40);
							system("pause");
							MenuArticulos(); //Ejecutar el procedimiento men� art�culos. 
							break;
					
					default:moverCursor (28, 48);
							printf(" Error en la selecci%cn. ", 162); //De lo contrario...mostrar error en la selecci�n. 
				}
			} while (eDato != 12); //Mientras el dato sea diferente de 12	
		}
	}
} //ModificarArticulo	


/* **********************************************************************
	PROCEDIMIENTO: OrdenarPorId
	AUTOR: L�pez A. Daniela Viridiana.
	FECHA DE CREACI�N: 11 de junio del 2019.
	OBJETIVO: Crear el m�dulo que permite ordenar el arreglo de art�culos de acuerdo a su Id.
	DE(PE): El arreglo de art�culos (aArt�culos), un n�mero entero, positivo correspondiente al �ndice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ning�n valor. 
********************************************************************** */
void OrdenarPorId(TaArticulos aArticulos, int eTotal){
	
	int eCont1, eCont2, eTemporal; //Variables locales de tipo entero.
	
	if (eTotal == -1){ //Si total es igual a menos uno, entonces...
		
		moverCursor (14, 42);
		printf ("-- No hay art%cculos registrados. --", 161); //Mostrar que no hay arreglos registrados...
		
	} else {
		
		for (eCont1 = 0; eCont1 < eTotal - 1; eCont1 ++){ //Desde eCont1 igual al primer elemento del arreglo, hasta eTotal - 1 hacer...
			
			for (eCont2 = 1; eCont2 < eTotal; eCont2 ++){//Desde eCont2 igual al segundo elemento del arreglo, hasta eTotal hacer...
				
				if (aArticulos[eCont2].eIdArticulo < aArticulos[eCont1].eIdArticulo){ /*Si el arreglo de art�culos en la posici�n de contador 2 en el campo eIdArticulo es menor al
				 arreglo de art�culos en la posici�n contador 1 en el campo eIdArt�culo, entonces...*/
					eTemporal = aArticulos[eCont2].eIdArticulo; //Asignar a eTemporal el valor del arreglo de art�culos en la posici�n de contador 2 en el campo id.
					aArticulos[eCont2].eIdArticulo = aArticulos[eCont1].eIdArticulo;
					aArticulos[eCont1].eIdArticulo = eTemporal;	//Asignar al arreglo de art�culos en la posici�n de contador 1 en el campo id el valor de eTemporal. 
				}
			}
		}	
	}
}//FinProcedimiento OrdenarPorId


/* **********************************************************************
	PROCEDIMIENTO: OrdenarPorNombre
	AUTOR: L�pez A. Daniela Viridiana.
	FECHA DE CREACI�N: 11 de junio del 2019.
	FECHA DE �LTIMA ACTUALIZACI�N: 
	OBJETIVO: Crear el m�dulo que permite ordenar el arreglo de art�culos de acuerdo a su nombre. 
	DE(PE): El arreglo de art�culos (aArt�culos), un n�mero entero, positivo correspondiente al �ndice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ning�n valor. 
********************************************************************** */
void OrdenarPorNombre(TaArticulos aArticulos, int eTotal){
	
	int eCont1, eCont2; //Variables locales de tipo entero.
	TaCadena cTemporal;
	
	if (eTotal == -1){ //Si total es igual a menos uno, entonces...
		
		moverCursor (14, 42);
		printf ("-- No hay art%cculos registrados. --", 161); //Mostrar que no hay arreglos registrados...
		
	} else {
		
		for (eCont1 = 0; eCont1 < eTotal - 1; eCont1 ++){ //Desde eCont1 igual al primer elemento del arreglo, hasta eTotal - 1 hacer...
			
			for (eCont2 = 1; eCont2 < eTotal; eCont2 ++){//Desde eCont2 igual al segundo elemento del arreglo, hasta eTotal hacer...
				
				if (aArticulos[eCont2].cNombre < aArticulos[eCont1].cNombre){ /*Si el arreglo de art�culos en la posici�n de contador 2 en el campo cNombre es menor al
				 arreglo de art�culos en la posici�n contador 1 en el campo cNombre, entonces...*/
					strcpy(cTemporal, aArticulos[eCont2].cNombre); //Asignar a eTemporal el valor del arreglo de art�culos en la posici�n de contador 2 en el campo cNombre.
					strcpy(aArticulos[eCont2].cNombre, aArticulos[eCont1].cNombre);
					strcpy(aArticulos[eCont1].cNombre, cTemporal);	//Asignar al arreglo de art�culos en la posici�n de contador 1 en el campo cNombre el valor de eTemporal. 
				}
			}
		}
	}
}//FinProcedimiento OrdenarPorNombre


/* **********************************************************************
	PROCEDIMIENTO: OrdenarPorTipo
	AUTOR: L�pez A. Daniela Viridiana.
	FECHA DE CREACI�N: 11 de junio del 2019.
	FECHA DE �LTIMA ACTUALIZACI�N: 
	OBJETIVO: Crear el m�dulo que permite ordenar el arreglo de art�culos de acuerdo a su tipo.
	DE(PE): El arreglo de art�culos (aArt�culos), un n�mero entero, positivo correspondiente al �ndice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ning�n valor. 
********************************************************************** */
void OrdenarPorTipo(TaArticulos aArticulos, int eTotal){
	
	int eCont1, eCont2, eTemporal; //Variables locales de tipo entero.
	
	if (eTotal == -1){ //Si total es igual a menos uno, entonces...
		
		moverCursor (14, 42);
		printf ("-- No hay art%cculos registrados. --", 161); //Mostrar que no hay arreglos registrados...
		
	} else {
		
		for (eCont1 = 0; eCont1 < eTotal - 1; eCont1 ++){ //Desde eCont1 igual al primer elemento del arreglo, hasta eTotal - 1 hacer...
			
			for (eCont2 = 1; eCont2 < eTotal; eCont2 ++){//Desde eCont2 igual al segundo elemento del arreglo, hasta eTotal hacer...
				
				if (aArticulos[eCont2].eTipo < aArticulos[eCont1].eTipo){ /*Si el arreglo de art�culos en la posici�n de contador 2 en el campo eTipo es menor al
				 arreglo de art�culos en la posici�n contador 1 en el campo eTipo, entonces...*/
					eTemporal = aArticulos[eCont2].eTipo; //Asignar a eTemporal el valor del arreglo de art�culos en la posici�n de contador 2 en el campo eTipo.
					aArticulos[eCont2].eTipo = aArticulos[eCont1].eTipo;
					aArticulos[eCont1].eTipo = eTemporal;	//Asignar al arreglo de art�culos en la posici�n de contador 1 en el campo eTipo el valor de eTemporal. 
				}
			}
		}
	}
}//FinProcedimiento OrdenarPorTipo


/* **********************************************************************
	PROCEDIMIENTO: ListarPorId
	AUTOR: L�pez A. Daniela Viridiana.
	FECHA DE CREACI�N: 11 de junio del 2019.
	FECHA DE �LTIMA ACTUALIZACI�N: 13/06/2019 por Segura Rios Brenda Stephanie
	OBJETIVO: Crear el m�dulo que permite listar el arreglo de art�culos ordenado de acuerdo a su Id.
	DE(PE): El arreglo de art�culos (aArt�culos), un n�mero entero, positivo correspondiente al �ndice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ning�n valor. 
********************************************************************** */
void ListarPorId(TaArticulos aArticulos, int eTotal){
	
		int eContador = -1;
		
		if (eTotal != -1){ //Si el total es distinto de -1, (arreglo con elementos)
		
		
		OrdenarPorId(aArticulos, eTotal); //Ejecutar OrdenarPorId (antes de mostrarlos). 
		ListarPorId(aArticulos, eTotal - 1); //Hacer recursiva a la funci�n mand�ndole el arreglo y el �ndice - 1 en cada llamada. 	
		
		
			fflush(stdin);
			printf("%03d %-10s %-10s %02d/%02d/%04d %-10s %-10s   %03d   %03d   %c%0.2f   %c%0.2f   %02d/%02d/%04d\n  ", 
			aArticulos[eTotal].eIdArticulo,
			aArticulos[eTotal].cNombre, 
			aArticulos[eTotal].cPresentacion, 
			aArticulos[eTotal].rFecCaducidad.eDia,
			aArticulos[eTotal].rFecCaducidad.eMes, 
			aArticulos[eTotal].rFecCaducidad.eAnio, 
			aArticulos[eTotal].cMarca, 
			aArticulos[eTotal].cProveedor, 
			aArticulos[eTotal].eExistenciaMax, 
			aArticulos[eTotal].eExistenciaMin, 36,
			aArticulos[eTotal].fPrecio, 36,
			aArticulos[eTotal].fCosto,
			aArticulos[eTotal].rFecRegistro.eDia,
			aArticulos[eTotal].rFecRegistro.eMes,
			aArticulos[eTotal].rFecRegistro.eAnio); 
			 
			
			fflush(stdin);
			
		}
}//FinProcedimiento ListarPorId


/* **********************************************************************
	PROCEDIMIENTO: ListarPorNombre
	AUTOR: L�pez A. Daniela Viridiana.
	FECHA DE CREACI�N: 11 de junio del 2019.
	FECHA DE �LTIMA ACTUALIZACI�N: 13/ 06/2019 por Segura Rios Brenda Stephanie
	OBJETIVO: Crear el m�dulo que permite listar el arreglo de art�culos ordenado de acuerdo a su nombre.
	DE(PE): El arreglo de art�culos (aArt�culos), un n�mero entero, positivo correspondiente al �ndice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ning�n valor. 
********************************************************************** */
void ListarPorNombre(TaArticulos aArticulos, int eTotal){
	

		
		if (eTotal != -1){ //Si el total es distinto de -1, (arreglo con elementos)
		
		
			OrdenarPorNombre(aArticulos, eTotal); //Ejecutar OrdenarPorNombre (antes de mostrarlos). 
			ListarPorNombre(aArticulos, eTotal - 1); //Hacer recursiva a la funci�n mand�ndole el arreglo y el �ndice - 1 en cada llamada. 
			
			fflush(stdin);	
			printf("%-10s  %03d %-10s  %02d/%02d/%04d  %-10s %-10s   %03d   %03d   %c%0.2f   %c%0.2f   %02d/%02d/%04d\n  ", 
			aArticulos[eTotal].cNombre, 
			aArticulos[eTotal].eIdArticulo,
			aArticulos[eTotal].cPresentacion, 
			aArticulos[eTotal].rFecCaducidad.eDia,
			aArticulos[eTotal].rFecCaducidad.eMes, 
			aArticulos[eTotal].rFecCaducidad.eAnio, 
			aArticulos[eTotal].cMarca, 
			aArticulos[eTotal].cProveedor, 
			aArticulos[eTotal].eExistenciaMax, 
			aArticulos[eTotal].eExistenciaMin, 36,
			aArticulos[eTotal].fPrecio, 36,
			aArticulos[eTotal].fCosto,
			aArticulos[eTotal].rFecRegistro.eDia,
			aArticulos[eTotal].rFecRegistro.eMes,
			aArticulos[eTotal].rFecRegistro.eAnio); 
			fflush(stdin);
			
		}
		
}//FinProcedimiento ListarPorNombre


/* **********************************************************************
	PROCEDIMIENTO: ListarPorTipo
	AUTOR: L�pez A. Daniela Viridiana.
	FECHA DE CREACI�N: 11 de junio del 2019.
	FECHA DE �LTIMA ACTUALIZACI�N: 
	OBJETIVO: Crear el m�dulo que permite listar el arreglo de art�culos ordenado de acuerdo a su tipo.
	DE(PE): El arreglo de art�culos (aArt�culos), un n�mero entero, positivo correspondiente al �ndice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ning�n valor. 
********************************************************************** */
void ListarPorTipo(TaArticulos aArticulos, int eTotal){
	
		TaCadena cTipo; //Tipo del art�culo (cadena de caracteres). 
		char cSubcadena [20]; //Cadena de 50 caracteres. 
		
		if (eTotal != -1){ //Si el total es distinto de -1, (arreglo con elementos)
		
			OrdenarPorTipo(aArticulos, eTotal); //Ejecutar OrdenarPorTipo (antes de mostrarlos). 
			ListarPorTipo(aArticulos, eTotal - 1); //Hacer recursiva a la funci�n mand�ndole el arreglo y el �ndice - 1 en cada llamada. 
		
			strncpy (cSubcadena, aArticulos[eTotal].cNombre, 20);
			cSubcadena[20] = '\0'; //Asigna a subcadena el valor de 0
		
			printf("%2d %-20s " , aArticulos[eTotal].eIdArticulo, cSubcadena); //Mostrar el arreglo de art�culos en la posici�n �ndice en el campo id y el valor de subcadena	
							
			
			ObtenerTipo(aArticulos[eTotal].eTipo, cTipo); //Obtener el tipo del art�culo del arreglo art�culos en la posici�n eTotal en el campo eTipo.
			strncpy(cSubcadena, cTipo, 20); //Copia a cSubcadena los primeros 20 caracteres de cTipo.
			cSubcadena[20] = '\0'; //Asigna a subcadena el valor de 0
                
			printf("%03d %-10s %-10s %02d/%02d/%04d %-10s %-10s %03d %03d %c%0.2f %c%0.2f %02d/%02d/%04d %-20s\n", 
			aArticulos[eTotal].eIdArticulo,
			aArticulos[eTotal].cNombre, 
			aArticulos[eTotal].cPresentacion, 
			aArticulos[eTotal].rFecCaducidad.eDia,
			aArticulos[eTotal].rFecCaducidad.eMes, 
			aArticulos[eTotal].rFecCaducidad.eAnio, 
			aArticulos[eTotal].cMarca, 
			aArticulos[eTotal].cProveedor, 
			aArticulos[eTotal].eExistenciaMax, 
			aArticulos[eTotal].eExistenciaMin,
			aArticulos[eTotal].fPrecio,
			aArticulos[eTotal].fCosto,
			aArticulos[eTotal].rFecRegistro.eDia,
			aArticulos[eTotal].rFecRegistro.eMes,
			aArticulos[eTotal].rFecRegistro.eAnio,
			cSubcadena, 36, 36); //Muestra el tipo del art�culo. 
		}
}//FinProcedimiento ListarPorTipo

