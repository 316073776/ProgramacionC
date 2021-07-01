/* **********************************************************************
	PROGRAMA: Proveedores.c
	AUTOR(ES): 
				Fernández Ortiz Valeria Lizette
				Francisco Arellano Herdson Josue
				López Alejaldre Daniela Viridiana
				Segura Ríos Brenda Stephanie
				Varas Dayren Sarahi
	EQUIPO: SkyNet
	OBJETIVO: Juntar las funciones que para realizar operaciones con los artículos.
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ULTIMA ACTUALIZACIÓN: 12 de junio del 2019 por López A. Daniela Viridiana. 
********************************************************************** */

//CONSTANTES.
#define MAX_PROVEEDORES 50

//TIPOS DE PROVEEDORES.

typedef char TaCadena [50]; //Declaración de tipo de dato cadena. 

typedef struct {	
	TaCadena cNombreProveedor, cDomicilio, cContacto, cTelefono, cEmail, cPaginaWeb, cMarcas; //Variables del registro proveedor de tipo cadena.
	int eIdProveedor;  //Variables que contendrán los ID.
	TrFecha rFecRegistro; //Variable para almacenar fechas de registro en el que se dio de alta un proveedor
	
}TrProveedor; //Registro de un proveedor.

typedef TrProveedor TaProveedores[MAX_PROVEEDORES]; //Declaración de un arreglo que contiene varios registros de proveedores


//PROTOTIPOS DE FUNCIONES/PROCEDIMIENTOS DE PROVEEDORES.
TrProveedor LeerProveedor();//Prototipo LeerProveedor.
void RegistrarProveedor(TaProveedores, int* , TrProveedor); //Prototipo de módulo RegistrarProveer
int BuscarProveedorPorId(TaProveedores, int, int); //Prototipo BuscarProveedorPorId.
int BuscarProveedorPorNombre(TaProveedores, int, TaCadena);
int GenerarIdProveedor(); //Prototipo de función generarIdProveedor.
//void ListarProveedor(TaProveedores, int, int); //Prototipo de módulo ListarProveedor. 
void BorrarProveedor(TaProveedores, int*, int); //Prototipo para borrar un proveedor
int LeerIdProveedor(TaCadena, int, int); //Prototipo para leer el ID ingresado
void MostrarDatosProveedor(TrProveedor); //Prototipo MostrarDatosProveedor
void ConsultarProveedorPorId(TaProveedores, int, int); //Prototipo Para consultar proveedor
void ConsultarProveedorPorNombre(TaProveedores, int, TaCadena); //Prototipo para consultar proveedor por nombre. 
void ModificarProveedor(TaProveedores, int, int); //Prototipo para Modificar datos de un proveedor
void MenuProveedor();//Procedimiento Sub-Menú Proveedores.
void OrdenarProveedorPorId(TaProveedores, int); 
void OrdenarProveedorPorNombre(TaProveedores, int);
void ListarProveedoresPorId(TaProveedores, int); 
void ListarProveedoresPorNombre(TaProveedores, int);

//DEFINICIÓN DE FUNCIONES/PROCEDIMIENTOS DE PROVEEDORES.
/* **********************************************************************
	FUNCIÓN: MenúProveedor
	AUTOR: Francisco Arellano Herdson Josue
	FECHA DE CREACIÓN: 17 de abril del 2019.
	FECHA DE ÚLIMA ACTUALIZACIÓN: 11/06/2019 por Segura Ríos Brenda Stephanie. 
	OBJETIVO: Crear el diseño de la aplicación del sistema (sub-menú Artículos).
	DE(PE): Ninguno.
	DS(PS): Número entero, positivo.
	Retorna: Un número entero, positivo correspondiente al resultado de la opción seleccionada (eOpcionV).
********************************************************************** */
void MenuProveedor() { 
    
    static int eTotal = -1;
    int eOpcionA, eIdProveedor, eOpcionLP;
    TrProveedor rProveedor;
	TaCadena cNombreProveedor;
	static TaProveedores aProveedores;
	 
    do{//Repetir...
	
	    system("cls");
	    dibujarMarco(); //Invocar al procedimiento dibujarMarco
		
		moverCursor (2, 36); //Se invoca a la función moverCursor y se le mandan los parámetros de renglón y columna donde deseamos que se posicione el cursor.
	    printf("%cBienvenid%c a la farmacia Ixoye - Submen%c Proveedores!", 173, 64, 163);
	    moverCursor (6, 45); 
	    printf("%c 1. Registrar Proveedor", 175);
	    moverCursor (9, 45);     
	    printf("%c 2. Borrar Proveedor ", 175);
	    moverCursor (12, 45);         
	    printf("%c 3. Actualizar proveedor", 175);
	    moverCursor (15, 45);
	    printf("%c 4. Consultar proveedor", 175, 161);
	    moverCursor (18, 45);
	    printf("%c 5. Listar proveedor", 175);
	    moverCursor (21, 45);
	   	printf("%c 6. Regresar a men%c principal", 175, 163);
	    
		linea(22); //Se dibuja una línea en el renglón indicado.
		moverCursor (25, 32);
	    printf("Introduzca el n%cmero de la operaci%cn que desea realizar: ", 163, 162);
	    
	    moverCursor (25, 89);
	    scanf("%d", &eOpcionA); //Leer el valor de la variable ingresada por el usuario.
	    
	    system("cls");
	    switch(eOpcionA){ //En caso del valor de lavariable eOpcionA hacer...
			
			case 1: rProveedor= LeerProveedor();	   //Invoca la función Leer proveedor y guarda su retorno en la variable
					RegistrarProveedor(aProveedores, &eTotal, rProveedor);	//Invoca la función registrar proveedor para guardar los datos.
				   	break;
				   	
			case 2: system("cls"); //Limpia la pantalla.
					dibujarMarco(); //Invoca a la función dibujarMarco.
	
					moverCursor (2, 35);
					printf("%cBienvenid%c a la farmacia Ixoye - Borrar Proveedor!", 173, 64);
			
					eIdProveedor = LeerIdProveedor("borrar", eTotal, aProveedores[eTotal].eIdProveedor); /*Asigna a eIdProveedor el valor de LeerIdProveedor*/
					
					if (eIdProveedor > -1){ //Si el IdProveedor es mayor a -1 (el arreglo no está vacío) entonces...					
						BorrarProveedor(aProveedores, &eTotal, eIdProveedor); //Se invoca a la función borrar proveedor... 
					}
										
		  			break;
		  			
			case 3: system("cls");
					dibujarMarco();
	
					moverCursor (2, 33);
					printf("%cBienvenid%c a la farmacia Ixoye - Actualizar proveedor!", 173, 64);
					eIdProveedor = LeerIdProveedor("modificar", eTotal, aProveedores[eTotal].eIdProveedor); //Asignar a eIdProveedor el valor de LeerIdProveedor
					
					if (eIdProveedor > -1){ //Si el idProveedor es mayor a menos uno...					
						ModificarProveedor(aProveedores, eTotal, eIdProveedor);	//Llamar a modificar Proveedor...
					} 
					
					break;
					
			case 4: system("cls"); 
					dibujarMarco();
					
					moverCursor(2, 30);
					printf("%cBienvenid%c a la farmacia Ixoye - Consultar proveedor!", 173, 64);
					eIdProveedor = LeerIdProveedor("consultar", eTotal, aProveedores[eTotal].eIdProveedor); //Asignar a eIdProveedor el valor de leerProveedor
										
					if (eIdProveedor > -1){	//Si el idProveedor es mayor a -1 (si el proveedor existe)									
						ConsultarProveedorPorId(aProveedores, eTotal, eIdProveedor); //Mandar a llamar al procedimiento consultar artículo.
						MenuProveedor();
					} else {
									
						fflush(stdin);
						MenuProveedor();
					}
					break;
					
			case 5: system("cls");
					dibujarMarco();
					
					moverCursor(2, 35);
					printf("%cBienvenid%c a la farmacia Ixoye - Listar Proveedor!", 173, 64);
					moverCursor(9, 45);
					printf("1. Listar proveedor por ID");
					moverCursor(12, 45);
					printf("2. Listar proveedor por nombre");
					moverCursor(15, 45);
					printf("3. Regresar a sub-men%c Proveedores", 161);
					linea(24);
					moverCursor(26, 34);
					printf("Ingresa el n%cmero de listado que deseas visualizar:", 163);
					fflush(stdin);
					moverCursor(26, 87);
					scanf("%d", &eOpcionLP);
					
					system("cls");
					dibujarMarco();
					
					switch(eOpcionLP){
					
						case 1: moverCursor(2, 46);
								printf("Lista de proveedores por ID:", 161);
								moverCursor(6, 2);		
								printf("|ID|     Nombre     |    Domicilio    | Fec.Registro |    Contacto    |  Tel%cfono  |     Email     |   P%cgina web  |", 130, 160);
								linea(8);
								OrdenarProveedorPorId(aProveedores, eTotal); //Ejecutar OrdenarPorId (antes de mostrarlos). 
								moverCursor(9,2);
								ListarProveedoresPorId(aProveedores, eTotal);
								moverCursor(29,40);
								system("pause");
								MenuProveedor();
								break;
								 
						case 2: moverCursor(2, 44);
								printf("Lista de proveedores por nombre:", 161);
								moverCursor(6, 2);		
								printf("|ID|     Nombre     |    Domicilio    | Fec.Registro |    Contacto    |  Tel%cfono  |     Email     |   P%cgina web  |", 130, 160);
								linea(8);
								OrdenarProveedorPorNombre(aProveedores, eTotal); //Ejecutar OrdenarProveedorPorNombre (antes de mostrarlos). 
								moverCursor(9,2);
								ListarProveedoresPorNombre(aProveedores, eTotal);
								moverCursor(29,40);
								system("pause");
								MenuProveedor();
								break;
							
						case 3: MenuProveedor();
								break;
						
						default: moverCursor(14, 49);
								 printf("---------Error en la selecci%cn---------", 162);
								 break;	
						
					} while (eOpcionLP != 3); //Repetir mientras la opción sea diferente de 3.
					
			case 6: main (); //Ejecutar menú principal.
					break;

			default:dibujarMarco();
					moverCursor(14, 49);
					printf("---------Error en la selecci%cn---------", 162);
					break;
		} 
		
		fflush(stdin);
		getchar();
	    
	} while (eOpcionA != 8);//Mientras la opción sea diferente de 8.
    
    //return 0; //Regresar el valor del número de la opción. 
} //main



/* **********************************************************************
	PROCEDIMIENTO: LeerProveedor
	AUTOR: Francisco Arellano Herdson Josue 
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 11 / 06 / 2019
	OBJETIVO: Crear el módulo que permitirá leer los datos de los proveedores
	DE(PE): Ninguno.
	DS(PS): Registro de los proveedores 
	Retorna: Una colección de datos heterogénea correspondiente a los datos del artículo (TrProveedor)
********************************************************************** */
TrProveedor LeerProveedor(){  // Yo tengo duda con con la función MoverCursor
	
	TrProveedor rProveedor; //Variable rProveedor de tipo registro de proveedor. 
	
	system("cls");
	dibujarMarco();
	
	moverCursor (2, 33);
	printf("%cBienvenid%c a la farmacia Ixoye - Registrar Proveedor!", 173, 64);
	moverCursor (6, 39);
	printf("Ingrese los siguientes datos del proveedor: ");
	
	moverCursor (10, 45);
	printf("%c Nombre : ", 207);
	fflush(stdin); //Limpia el buffer. 
	moverCursor (10, 56);
	gets(rProveedor.cNombreProveedor); //Obtener/leer el registro proveedor en el campo cNombreProvedor 
	
	moverCursor (12, 45);
	printf("%c Domicilio: ", 207);
	fflush(stdin);
	moverCursor (12, 59);
	gets(rProveedor.cDomicilio);
	
	moverCursor (14, 45);
	printf("%c Contacto: ", 207);
	fflush(stdin);
	moverCursor (14, 58);
	gets(rProveedor.cContacto);
	
	moverCursor (16, 45); // ¿Que se pone en mover cursor?
	printf("%c Telefono: ", 207);
	fflush(stdin);
	moverCursor (16, 58);
	gets(rProveedor.cTelefono);
	
	moverCursor (18, 45);
	printf("%c Email:  ", 207);
	fflush(stdin);
	moverCursor (18, 56);
	gets(rProveedor.cEmail);
	
	moverCursor (20, 45);
	printf("%c Sitio web: ", 207);
	fflush(stdin);
	moverCursor (20, 59);
	gets(rProveedor.cPaginaWeb);
	
	moverCursor (22, 45);
	printf("%c Fecha de Registro: ", 207);
	moverCursor (23, 50);
	printf("Dia: ");
	fflush(stdin);
	moverCursor (23, 55);
	scanf("%d", &rProveedor.rFecRegistro.eDia);
	moverCursor (24, 50);
	printf("Mes: ");
	fflush(stdin);
	moverCursor (24, 55);
	scanf("%d", &rProveedor.rFecRegistro.eMes);
	moverCursor (25, 50);
	printf("A%co: ", 164);
	fflush(stdin);
	moverCursor (25, 55);
	scanf("%d", &rProveedor.rFecRegistro.eAnio);
	
	rProveedor.eIdProveedor = GenerarIdProveedor(); //Invoco a la función que genera el ID del Proveedor. 
	
	return rProveedor;

}//FinProcedimiento LeerProveedor


/* **********************************************************************
	PROCEDIMIENTO: RegistrarProveedor
	AUTOR: Francisco Arellano Herdson Josue
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 12 de junio del 2019 por López. A. Daniela Viridiana. 
	OBJETIVO: Crear el módulo que permitirá registrar a los proveedores. 
	DE(PE): Colección de datos de registros de proveedor (TaProveedores), número entero, positivo que corresponde al índice del arreglo (eTotal), colección de datos heterogéneos (rProveedor).
	DS(PS): Ninguno.
	Retorna: Ningún valor. 
********************************************************************** */
void RegistrarProveedor(TaProveedores aProveedores, int *eTotal, TrProveedor rProveedor){ //Definición del procedimiento RegistrarProveedor. 
	
	int eRecorre; //Variable que permitirá recorrer el arreglo.
	
	if (*eTotal == MAX_PROVEEDORES - 1){ //Si el total del arreglo es igual al número máximo de proveedores posibles de registrar, entonces...
		
		moverCursor (28, 42);
		printf("No se pueden agregar m%cs proveedores.", 160); //Mostrar que no se pueden ingresar más proveedores
		
	} else { //de lo contrario...
		
		if (*eTotal == -1 || rProveedor.eIdProveedor > aProveedores[*eTotal].eIdProveedor){ /*Si el índice del arreglo de proveedores está en 0 o si el registro del
		artículo en el campo eIdProveedor es mayor al arreglo de proveedores en la posición eTotal en el campo IdProveedor, entonces...*/
			
			(*eTotal) ++; //Incrementar el valor de eTotal en uno.
			
			aProveedores[*eTotal] = rProveedor; //Asignar al arreglo proveedores en la posición eTotal el registro del proveedor
			moverCursor (28, 40);
			printf("%c%s%c registrado correctamente.", 34, rProveedor.cNombreProveedor, 34); //Mostrar que el proveedor ha sido registrado de forma exitosa.
			
		} else { //De lo contrario...
			
			if (BuscarProveedorPorId(aProveedores, *eTotal, rProveedor.eIdProveedor) != -1 ){ //Si buscar Proveedor por ID es diferente de 0...
				
				moverCursor (28, 54);
				printf("Ya existe %d", rProveedor.eIdProveedor); //Mostrar que ya existe el proveedor.
				
			} else { //De lo contrario...
				
				eRecorre = *eTotal; //Asignar a eRecorre el valor de eTotal
				
				while (eRecorre >= 0 && aProveedores[eRecorre].eIdProveedor > rProveedor.eIdProveedor){ /*Mientras eRecorre sea mayor a 0 y el arreglo de proveedores
				en la posición eRecorre en el campo IDProveedor sea mayor que el registro de proveedores en la posición IDProveedor hacer... */
					
					aProveedores[eRecorre + 1] = aProveedores[eRecorre]; //Asignar al arreglo en la posición eRecorre + 1 el registro del proveedor en la posición eRecorre.
					eRecorre --; //Decrementar el valor de eRecorre en uno.
				}
				aProveedores[eRecorre + 1] = rProveedor; //Asignar al arreglo de proveedores en la posición eRecorre + 1, el registro del proveedor.
				(*eTotal) ++; //Incrementar el valor de total en uno.
				
				moverCursor (28, 40);
				printf("%c%s%c registrado correctamente", 34, rProveedor.cNombreProveedor, 34); //Mostrar que el registro del proveedor se realizó adecuadamente. 
			}
		}
	}	
}//FinProcedimiento RegistrarProveedor


/* **********************************************************************
	FUNCIÓN: BuscarProveeedorPorId.
	AUTOR: Francisco Arellano Herdson Josue 
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá buscar a un proveedor  de acuerdo con su Id.
	DE(PE): Arreglo de Proveedores (TaProveedores  aProveedores), número entero, positivo, índice del arreglo (eTotal), número entero, positivo, que indica el Id del artículo (eIdProveedor)
	DS(PS): Registro del Proveedor
	Retorna: Una colección de datos heterogénea correspondiente a los datos del Proveedor (TrProveedor)
********************************************************************** */
int BuscarProveedorPorId(TaProveedores aProveedores, int eTotal, int eIdProveedor){ 
	
	int eMenor, eMayor, eMedio; //Declaro variables locales que me permitirán realizar una búsqueda binaria.
	
	if (eTotal == -1){ //Si total = -1 (arreglo vacío).
		
		return -1; //Regresar -1, en el caso de un arreglo que empieza desde 1, sería 0.
		
	} else {
		
		eMenor = 0; //Asignar a eMenor el valor de 0.
		eMayor = eTotal; //Asignar a eMayor el valor de eTotal.
		eMedio = (eMayor + eMenor) / 2; //Calcular eMedio = eMayor + eMenor / 2
		
		while (eMenor < eMayor && aProveedores[eMedio].eIdProveedor != eIdProveedor){ /*Mientras eMenor sea menor a eMayor Y el arreglo de proveedores en la posición
		de eMedio en el campo eIdProveedor sea diferente de eIdProveedor  (mientras no exista el id)
		*/
			if (eIdProveedor < aProveedores[eMedio].eIdProveedor){ /*Si el id del Proveedor es menor al arreglo de Proveedores en la posición eMedio en el campo eidArticulo 
			(se encuentra de la mitad del arreglo para abajo)*/
			
				eMayor = eMedio - 1; //Hacer que eMayor tome el valor de eMedio - 1 (que busque de la mitad del arreglo hacia abajo). 
				
			} else { //De lo contrario (se encuentra de la mitad del arreglo para arriba).
				
				eMenor = eMedio + 1; //Hacer que eMenor tome el valor de eMedio + 1 (que busque de la mitad del arreglo hacia arriba).
			} 
			
			eMedio = (eMenor + eMayor) / 2; //Volver a calcular eMedio con los nuevos valores de eMenor, eMayor. 
		}
		
		if (eIdProveedor == aProveedores[eMedio].eIdProveedor){//Si el id del Proveedor es igual al arreglo en la posición del centro en el campo eIdProveedor
			
			return eMedio; //Regresar el valor de eMedio (posición del arreglo en donde se encuentra el ID del proveedor.
			 
		} else{ //De lo contrario...
			
			return -1; //Indica que no se encontró.
		}
	}
}//FinFunción BuscarProveedorPorId.

/* **********************************************************************
	PROCEDIMIENTO: BuscarProveedorPorNombre
	AUTOR: López A. Daniela Viridiana. 
	FECHA DE CREACIÓN: 12 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear un módulo que permita encontrar la posición de un proveedor dentro de un arreglo, ingresando su nombre. 
	DE(PE): Arreglo de proveedores (aProveedores), número entero, positivo correspondiente al índice del arreglo (eTotal), cadena de caracteres que ingresará el usuario para buscar al proveedor.
	DS(PS): Número entero, que indica la posición en la que se encuentra el nombre del proveedor.
	Retorna: Un número entero. 
********************************************************************** */
int BuscarProveedorPorNombre(TaProveedores aProveedores, int eTotal, TaCadena cNombre){
	
	int eMenor, eMayor, eMedio; //Variables locales.
	
	if (eTotal == -1){ //Si el índice del arreglo indica que no hay elementos...
		
		return -1; //Regresar -1
		
	} else { //De lo contrario...
		
		eMenor = 0; //Hacer eMenor = 0
		eMayor = eTotal; //Hacer eMayor = eTotal.
		eMedio = (eMayor + eMenor) / 2; //Calcular eMedio es igual a la suma de eMayor + eMenor / 2
		
		while (eMenor < eMayor && strcmp(aProveedores[eMedio].cNombreProveedor, cNombre) != 0){ //Mientras eMenor sea menor que eMayor y el arreglo de proveedores en la posición de medio sea diferente de cNombre
			
			if (strcmp(cNombre, aProveedores[eMedio].cNombreProveedor) > 0){ //Si cNombre es mayor que el arreglo en la posición de eMedio (se encuentra de la mitad del arreglo hacia arriba).
				
				eMenor = eMedio + 1; //Hacer eMenor = eMedio + 1, buscar de la mitad del arreglo hacia arriba.
				
			} else { //De lo contrario...
				
				eMayor = eMedio - 1; //Hacer eMayor = eMedio - 1, buscar de la mitad del arreglo hacia abajo.
			}
		
			eMedio = (eMenor + eMayor) / 2; //Calcular eMedio nuevamente.
		} 
	
		if (strcmp(aProveedores[eMedio].cNombreProveedor, cNombre) == 0){ //Si el arreglo en la posición de medio es igual al nombre a buscar.
		
			return eMedio; //Regresar el valor de eMedio
		
		} else { //De lo contrario...
		
			return -1; //Regresar -1 (no se encontró). 
		}
	}	
}//FinFunción BuscarProveedorPorNombre 


/* **********************************************************************
	FUNCIÓN: GenerarIdProveedor
	AUTOR: Francisco Arellano Herdson Josue.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permitirá generar el ID de un  proveedor. 
	DE(PE): Ninguno.
	DS(PS): Número entero, positivo. 
	Retorna: Un número entero, positivo correspondiente al ID del proveedor generado (eSiguiente)
********************************************************************** */
int GenerarIdProveedor(){ //Función generar ID Provedor
	
	static int eSiguiente = 1; //Variable que generará los ID, empezando por uno.
	
	return (eSiguiente ++); //Regresar eSiguiente + 1
}//FinFunción Generar ID Proveedor. 


/* **********************************************************************
	PROCEDIMIENTO: BorrarProveedor
	AUTOR: Francisco Arellano Herdson Josue
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear una funcipon que permita borrar un proveedor.
	DE(PE): Arreglo de artículos (aProveedores), número entero, positivo, que corresponde al índice del arreglo (eTotal), número entero, positivo, correspondiente al Id del proveedor (eIdproveedor).
	DS(PS): Ninguno.
	Retorna: Ningún valor. 
********************************************************************** */
void BorrarProveedor(TaProveedores aProveedores, int *eTotal, int eIdProveedor){
	
	int ePos, eRecorre; //Variables locales. 
	char cConfirma; 
	
	if (*eTotal == -1){ //Si el total es igual a -1 (arreglo vacío), entonces...
		
		moverCursor (14, 42);
		printf("-- No hay proveedores registrados. --");
		moverCursor (15, 42);
		system("pause"); //Detener el programa. 
		
	} else { //De lo contrario...
		
		ePos = BuscarProveedorPorId(aProveedores, *eTotal, eIdProveedor); //Asignar a ePos el valor de la función BuscarProveedorPorId
		
		if (ePos == -1) { //Si la posición es igual a -1 (no se encontró).
			
			moverCursor (14, 49);
			printf("El ID [%d] no existe.", eIdProveedor);//-------------------REVISAR (no regresa el mensaje)
			system("pause"); //Detener el programa. 
					
		} else { //De lo contrario...

			MostrarDatosProveedor(aProveedores[ePos]); //Invocar a la función MostrarDatosProveedor
			linea(27); 
			moverCursor (27, 43); //Formato de pantalla.
			printf("%cDesea borrar el registro? [S/N]: ", 168);
			fflush(stdin); //Limpia el buffer.
			moverCursor (27, 77);
			cConfirma = getchar(); //Leer el valor de cConfirma.
			
			if (cConfirma == 's' || cConfirma == 'S'){ //Si cConfirma es igual a "s" ó a "S" hacer...
			
				for (eRecorre = ePos; eRecorre < *eTotal; eRecorre++){ //Desde eRecorre con el valor ePos, mientras eRecorre sea menor que el total del arreglo, incrementar su valor en uno.
					
					aProveedores[eRecorre] = aProveedores[eRecorre + 1]; //Asignar al arreglo de provedoores s en la posición eRecorre el valor de proveedores en la posición eRecorre + 1
				}
				
				(*eTotal)--; //Decrementar el índice en uno.
				moverCursor (28, 43);
				printf(" Proveedor borrado correctamente. ");
			}
		}
	}
} //BorrarProveedor


/* **********************************************************************
	FUNCIÓN: LeerIdProveedor
	AUTOR: Francisco Arellano Herdson Josue 
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite leer el ID ingresado.
	DE(PE): 
	DS(PS): 
	Retorna: 
********************************************************************** */
int LeerIdProveedor(TaCadena cOperacion, int eTotal, int eUltimoId){
	
	int eId;
		
	if (eTotal == -1) {
		
		moverCursor (14, 42);
		printf ("-- No hay Proveedores registrados. --");
		fflush(stdin);
		getchar();
		return -1;
		
	} else {

		do {
			
			moverCursor (6, 38);
			printf("Ingrese el ID del proveedor a %s: ", cOperacion);
			fflush(stdin);
			moverCursor (6, 80);
			scanf("%d", &eId);
		
		} while (eId < 1 || eId > eUltimoId);
	
		return eId;
	} 
} //LeerIdProveedor


/* **********************************************************************
	FUNCIÓN: MostrarDatosProveedor
	AUTOR: Francisco Arellano Herdson Josue
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite mostrar los datos guardados del proveedor
	DE(PE): 
	DS(PS): 
	Retorna: 
********************************************************************** */
void MostrarDatosProveedor(TrProveedor rProveedor){ //Tengo duda en los de mover cursor
	
	int eNombre, eIdProveedor;
	char cOtro;
	TaCadena cTipo;
	
	moverCursor (9, 48); 
	printf("Datos del Proveedor: [%d]", rProveedor.eIdProveedor);
	
	moverCursor (12, 45); 
	printf("%c Nombre Proveedor: %s", 207, rProveedor.cNombreProveedor);
	moverCursor (14, 45); 
	printf("%c Domicilio: %s", 207,  rProveedor.cDomicilio);
	moverCursor (16, 45); 
	printf("%c Contacto: %s", 207,  rProveedor.cContacto);
	moverCursor (18, 45); 
	printf("%c Telefono: %s", 207, rProveedor.cTelefono);
	moverCursor (20, 45); 
	printf("%c Email: %s",207, rProveedor.cEmail);
	moverCursor (22, 45);
	printf("%c P%cgina web: %s", 207,  160, rProveedor.cPaginaWeb);
	moverCursor (24, 45);
	printf("%c Fecha de registro: %02d/%02d/%02d", 207,
		rProveedor.rFecRegistro.eDia, rProveedor.rFecRegistro.eMes, rProveedor.rFecRegistro.eAnio);

} //MostrarDatosProveedor


/* **********************************************************************
	PROCEDIMIENTO: ConsultarProveedorPorId
	AUTOR: Francisco Arellano Herdson Josue
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear una funcipon que permita buscar el registro de un proveedor ingresando su ID.
	DE(PE): 
	DS(PS): 
	Retorna: 
********************************************************************** */
void ConsultarProveedorPorId(TaProveedores aProveedores, int eTotal, int eIdProveedor){

	int ePos;

	ePos = BuscarProveedorPorId(aProveedores, eTotal, eIdProveedor);
	
	if (ePos > -1){
	
		MostrarDatosProveedor(aProveedores[ePos]);
		linea(26);
		moverCursor(26, 50);
		printf(" %cConsulta exitosa! ", 173);
		moverCursor(28, 40);
		system("pause");
		
	} else {
		
		fflush(stdin);
		linea(26);
		moverCursor(26, 46);
		printf(" No se encontr%c el ID [%d]: ", 162, eIdProveedor);
		moverCursor(28, 40);
		system("pause");
	}
} //ConsultarProveedorPorId


/* **********************************************************************
	PROCEDIMIENTO: ConsultarProveedorPorNombre
	AUTOR: Francisco Arellano Herdson Josue
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear un módulo que permita consultar el registro de un proveedor ingresando su Nombre. 
	DE(PE): Arreglo de proveedores (aProveedores), número entero, positivo correspondiente al índice del arreglo (eTotal), cadena de caracteres que ingresará el usuario para buscar al proveedor.
	DS(PS): Ninguno.
	Retorna: Ninguno.
********************************************************************** */
void ConsultarProveedorPorNombre(TaProveedores aProveedores, int eTotal, TaCadena cNombre){
	
	int ePos; //Variable local que guardará la posición del proveedor dentro del arreglo. 

	ePos = BuscarProveedorPorNombre(aProveedores, eTotal, cNombre); //Asignar a ePos el valor de la función BuscarProveedorPorNombre 
	
	if (ePos > -1){ //Si la posición es mayor a -1 (sí se encontró el proveedor). 
	
		MostrarDatosProveedor(aProveedores[ePos]); //Mostrar los datos del proveedor. 
		moverCursor(27, 52);
		printf(" Para regresar: ");
		
	} else { //De lo contrario.
		moverCursor(27, 45);
		printf("No se encontr%c el proveedor %s", 162, cNombre); //Mostrar que no se encontró al proveedor. 
	}
	
}

/* **********************************************************************
	PROCEDIMIENTO: ModificarProveedor
	AUTOR: Francisco Arellano Herdson Josue
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 11 de junio del 2019 por López A. Daniela Viridiana.
	OBJETIVO: Crear el módulo que permite modificar o actualizar los datos guardados de un proveedor
	DE(PE): El arreglo de proveedores (aProveedores), un número entero, positivo correspondiente al índice del arreglo (eTotal) y un número entero, positivo, correspondiente al Id del proveedor (eIdProveedor).
	DS(PS): Ninguno. 
	Retorna: Ningún valor. 
********************************************************************** */
void ModificarProveedor(TaProveedores aProveedores, int eTotal, int eIdProveedor){
	
	int ePos, eDato, eNuevo; //Variables locales, enteras.
	TaCadena cTipo, cNuevo; //Variable local de tipo cadena. 
	float fNuevo;
	
	if (eTotal == -1){ //Si total es igual a menos uno, entonces...
		
		moverCursor (14, 42);
		printf ("-- No hay proveedores registrados. --"); //Mostrar que no hay arreglos registrados...
		
	} else { //De lo contrario...
		
		ePos = BuscarProveedorPorId(aProveedores, eTotal, eIdProveedor); //Asignar a la variable ePos el valor del procedimiento BuscarProveedorPorId
		
		if (ePos == -1) { //Si la posición retornada es -1, entonces... (no se encontró el proveedor).
			
			moverCursor (14, 49);
			printf("El ID [%d] no existe, no se pudo encontrar el Proveedor", eIdProveedor); //Mostrar que el ID no existe.
			
		} else { //De lo contrario...

			do { //Repetir...
					
				MostrarDatosProveedor(aProveedores[ePos]); //Invocar a la función MostrarDatosProveedor...
				
				moverCursor(9,10);
				printf("--Opciones:--");
				moverCursor(12,8);
				printf("1. Nombre Proveedor"
						"\n\t2. Domicilio"
						"\n\t3. Fecha de registro"
						"\n\t4. Contacto"
						"\n\t5. Telefono"
						"\n\t6. Email"
						"\n\t7. Sitio web"
					
						"\n\t8. Regresar");
				
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
					
					case 1: moverCursor (28, 45);
							printf(" Nuevo Proveedor:  ");
							fflush(stdin);
							moverCursor (28, 66);
							gets(cNuevo); //Leer el nuevo valor(cadena).
							strcpy(aProveedores[ePos].cNombreProveedor, cNuevo); //Asignar al arreglo de Proveedores en la posición ePos, el valor del nuevo dato ingresado 
							break;
					
					case 2: moverCursor (28, 45);
							printf(" Nuevo Domicilio:  ", 162);
							fflush(stdin);
							moverCursor (28, 65);
							gets(cNuevo); //Leer el nuevo valor (cadena).
							strcpy(aProveedores[ePos].cDomicilio, cNuevo); //Asignar al arreglo de proveedores en la posición ePos en el campo cPresentación el nuevo dato ingresado.
							break;
							
					case 3: moverCursor (28, 45);
							printf(" Nueva Fecha de registro: ");
							moverCursor (29, 51);
							printf("Dia: ");
							fflush(stdin);
							moverCursor (29, 56);
							scanf("%d", &eNuevo); //Leer el nuevo valor (entero).
							aProveedores[ePos].rFecRegistro.eDia = eNuevo; //Asignar al arreglo de artículos en la posición ePos en el campo rFecCaducidad en el subcampo eDia el nuevo valor ingresado. 
							moverCursor (30, 51);
							printf("Mes: ");
							fflush(stdin);
							moverCursor (30, 56);
							scanf("%d", &eNuevo);
							aProveedores[ePos].rFecRegistro.eMes = eNuevo;
							printf("A%co: ", 164);
							fflush(stdin);
							moverCursor (31, 56);
							scanf("%d", &eNuevo);
							aProveedores[ePos].rFecRegistro.eAnio = eNuevo;
							break;
		
					case 4: printf("\nNueva Contacto: ");
							fflush(stdin);
							gets(cNuevo);
							strcpy(aProveedores[ePos].cContacto, cNuevo);
							break;
							
					case 5: moverCursor (28, 47);
							printf(" Nuevo Telefono:  ");
							fflush(stdin);
							moverCursor (28, 64);
							gets(cNuevo);
							strcpy (aProveedores[ePos].cTelefono, cNuevo);
							break;
		
					case 6: moverCursor (28, 46);
							printf(" Nuevo Email:  ");
							fflush(stdin);
							moverCursor (28, 60);
							gets(cNuevo);
							strcpy (aProveedores[ePos].cEmail, cNuevo);
							break;
		
					case 7: moverCursor (28, 45);
							printf(" Nuevo Sitio Web:  ");
							fflush(stdin);
							moverCursor (28, 63);
							gets(cNuevo);
							strcpy (aProveedores[ePos].cPaginaWeb, cNuevo);
							break;
					
					
					case 8:moverCursor (14, 42);
							printf(" Registro modificado correctamente.");
							moverCursor (15, 40);
							system("pause");
							 MenuProveedor(); //Ejecutar el procedimiento menú Proveedores 
							 break;
					
					default: moverCursor (28, 48);
							printf(" Error en la selecci%cn. ", 162); //De lo contrario...mostrar error en la selección. 
				}
			} while (eDato != 8); //Mientras el dato sea diferente de 8	
		}
	}
} //ModificarProveedores	


/* **********************************************************************
	PROCEDIMIENTO: OrdenarProveedorPorId
	AUTOR: Francisco Arellano Herdson Josue 
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite ordenar el arreglo de Proveedores de acuerdo a su Id.
	DE(PE): El arreglo de Proveedores (aProveedores), un número entero, positivo correspondiente al índice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ningún valor. 
**********************************************************************/
void OrdenarProveedorPorId(TaProveedores aProveedores, int eTotal){
	
	int eCont1, eCont2, eTemporal; //Variables locales de tipo entero.
	
	if (eTotal == -1){ //Si total es igual a menos uno, entonces...
		
		moverCursor (14, 42);
		printf ("-- No hay proveedores registrados. --"); //Mostrar que no hay arreglos registrados...
		
	} else {
		
		for (eCont1 = 0; eCont1 < eTotal - 1; eCont1 ++){ //Desde eCont1 igual al primer elemento del arreglo, hasta eTotal - 1 hacer...
			
			for (eCont2 = 1; eCont2 < eTotal; eCont2 ++){//Desde eCont2 igual al segundo elemento del arreglo, hasta eTotal hacer...
				
				if (aProveedores[eCont2].eIdProveedor < aProveedores[eCont1].eIdProveedor){ /*Si el arreglo de artículos en la posición de contador 2 en el campo eIdArticulo es menor al
				 arreglo de artículos en la posición contador 1 en el campo eIdArtículo, entonces...*/
					eTemporal = aProveedores[eCont2].eIdProveedor; //Asignar a eTemporal el valor del arreglo de artículos en la posición de contador 2 en el campo id.
					aProveedores[eCont2].eIdProveedor = aProveedores[eCont1].eIdProveedor;
					aProveedores[eCont1].eIdProveedor = eTemporal;	//Asignar al arreglo de artículos en la posición de contador 1 en el campo id el valor de eTemporal. 
				}
			}
		}
	}
}//FinProcedimiento OrdenarProveedorPorId

/* **********************************************************************
	PROCEDIMIENTO: OrdenarProveedorPorNombre
	AUTOR: Francisco Arellano Herdson Jpsue 
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite ordenar el arreglo de proveedores de acuerdo a su nombre. 
	DE(PE): El arreglo de proveedores (aProveedores), un número entero, positivo correspondiente al índice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ningún valor. 
********************************************************************** */
void OrdenarProveedorPorNombre(TaProveedores aProveedores, int eTotal){
	
	int eCont1, eCont2; //Variables locales de tipo entero.
	TaCadena cTemporal;
	
	if (eTotal == -1){ //Si total es igual a menos uno, entonces...
		
		moverCursor (14, 42);
		printf ("-- No hay proveedores registrados. --"); //Mostrar que no hay arreglos registrados...
		
	} else {
		
		for (eCont1 = 0; eCont1 < eTotal - 1; eCont1 ++){ //Desde eCont1 igual al primer elemento del arreglo, hasta eTotal - 1 hacer...
			
			for (eCont2 = 1; eCont2 < eTotal; eCont2 ++){//Desde eCont2 igual al segundo elemento del arreglo, hasta eTotal hacer...
				
				if (aProveedores[eCont2].cNombreProveedor < aProveedores[eCont1].cNombreProveedor){ /*Si el arreglo de Proveedores en la posición de contador 2 en el campo cNombreProveedor es menor al
				 arreglo de artículos en la posición contador 1 en el campo cNombre, entonces...*/
					strcpy(cTemporal, aProveedores[eCont2].cNombreProveedor); //Asignar a eTemporal el valor del arreglo de proveedores en la posición de contador 2 en el campo cNombreProvedor.
					strcpy(aProveedores[eCont2].cNombreProveedor, aProveedores[eCont1].cNombreProveedor);
					strcpy(aProveedores[eCont1].cNombreProveedor, cTemporal);	//Asignar al arreglo de Proveedores en la posición de contador 1 en el campo cNombreProvedor el valor de eTemporal. 
				}
			}
		}
	}
}//FinProcedimiento OrdenarProveedorPorNombre

/* ************************
	PROCEDIMIENTO: ListarProveedoresPorId
	AUTOR: Francisco Arellano Herdson Josue 
	FECHA DE CREACIÓN: 11 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite listar el arreglo de Proveedores ordenado de acuerdo a su Id.
	DE(PE): El arreglo de artículos (aProveedores), un número entero, positivo correspondiente al índice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ningún valor. 
************************ */
void ListarProveedoresPorId(TaProveedores aProveedores, int eTotal){
		
		if (eTotal != -1){ //Si el total es distinto de -1, (arreglo con elementos)
		
			OrdenarProveedorPorId(aProveedores, eTotal); //Ejecutar OrdenarPorId (antes de mostrarlos). 
			ListarProveedoresPorId(aProveedores, eTotal - 1); //Hacer recursiva a la función mandándole el arreglo y el índice - 1 en cada llamada. 				
			    
			fflush(stdin);
			printf("%03d %-10s %-10s %02d/%02d/%04d %-10s %-10s %-10s %-10s %-10s \n   ", 
			aProveedores[eTotal].eIdProveedor,
			aProveedores[eTotal].cNombreProveedor, 
			aProveedores[eTotal].cDomicilio, 
			aProveedores[eTotal].rFecRegistro.eDia,
			aProveedores[eTotal].rFecRegistro.eMes, 
			aProveedores[eTotal].rFecRegistro.eAnio, 
			aProveedores[eTotal].cContacto, 
			aProveedores[eTotal].cTelefono, 
			aProveedores[eTotal].cEmail, 
			aProveedores[eTotal].cPaginaWeb);
			fflush(stdin); 
		}
}//FinProcedimiento ListarPorId


/* ************************
	PROCEDIMIENTO: ListarProveedoresPorNombre
	AUTOR: López A. Daniela Viridiana. 
	FECHA DE CREACIÓN: 12 de junio del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Crear el módulo que permite listar el arreglo de Proveedores ordenado de acuerdo a su nombre.
	DE(PE): El arreglo de proveedores (aProveedores), un número entero, positivo correspondiente al índice del arreglo (eTotal).
	DS(PS): Ninguno. 
	Retorna: Ningún valor. 
************************ */
void ListarProveedoresPorNombre(TaProveedores aProveedores, int eTotal){
	
	if (eTotal != -1){ //Si el total es distinto de -1, (arreglo con elementos)
				
				OrdenarProveedorPorNombre(aProveedores, eTotal); //Ejecutar OrdenarProveedorPorNombre (antes de mostrarlos). 
				ListarProveedoresPorNombre(aProveedores, eTotal - 1); //Hacer recursiva a la función mandándole el arreglo y el índice - 1 en cada llamada. 
	                
				printf("%03d %-10s %-10s %02d/%02d/%04d %-10s %-10s %-10s %-10s\n   ", 
				aProveedores[eTotal].eIdProveedor,
				aProveedores[eTotal].cNombreProveedor, 
				aProveedores[eTotal].cDomicilio, 
				aProveedores[eTotal].rFecRegistro.eDia,
				aProveedores[eTotal].rFecRegistro.eMes, 
				aProveedores[eTotal].rFecRegistro.eAnio, 
				aProveedores[eTotal].cContacto, 
				aProveedores[eTotal].cTelefono, 
				aProveedores[eTotal].cEmail, 
				aProveedores[eTotal].cPaginaWeb); //Muestra los campos del arreglo de proveedores. 
			}
}
