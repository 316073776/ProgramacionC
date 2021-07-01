/*
	Progrma: P23Libros.c
	Autor: David Latapi
	Fecha: 05/06/19
	Objetivo: Mostrar el manejo de arreglos de registros con arreglos y registros.
*/	

//Constantes

#define MAX_LIBROS 100
#define MAX_AUTORES 5

//Tipos

typedef struct{
	int eDia, eMes, eAnio;
}TrFecha;

typedef enum{
	LP = 1, TELE, BD, SEGURIDAD
}TeGenero;

typedef char TaCadena[30];

typedef struct{
	int aAutores[MAX_AUTORES];
	TaCadena cTitulo;
	int eNumEdicion, eAnioEdicion, eNumCopias, eId;
	TaCadena cEditorial, cPais, cISBN;
	TrFecha rFecRegistro;
	TeGenero eGenero;
}TrLibro;

typedef TrLibro TaLibros[MAX_LIBROS];
 
//Prototipos
TrLibro LeerLibro();
void InsertarLibro (TaLibros, int*, TrLibro);
int BuscarLibroPorId( TaLibros, int, int );
int GenerarIdLibro ();
void ListarLibros(TaLibros, int);
void ObtenerGenero(int, TaCadena);
void InicializarAutores(int aAutores[MAX_AUTORES]);
void BorrarLibro (TaLibros, int*, int);
int LeerIdLibro(TaCadena, int, int);
void MostrarDatosLibro(TrLibro);
void ConsultarLibroPorId(TaLibros, int, int);
void ModificarLibro(TaLibros, int, int);
void MenuLibros();

void MenuLibros(){

	static int eTotal = -1;
	int eOpcion, eId;
	TrLibro rLibro;
	TaCadena cTitulo;
	static TaLibros aLibros;
	
	do{
	
		system("cls");
		printf("Administraci%cn de libros\n", 162);
		printf("\n1. Registrar Libro\n2. Borrar Libro\n3. Modificar datos Libro\n4. Consultar Libro\n5. Listar Libros\n6. Regresar a men%c principal\n\n", 163 );
		printf("Seleccione una opcion: ");
		scanf("%d", &eOpcion);
		
		system("cls");
		switch(eOpcion){
			
			case 1: printf("\n\t\tAdministraci%cn de Libros. Registrar Libro.\n", 162);
					rLibro = LeerLibro();
					InsertarLibro(aLibros, &eTotal, rLibro);					
					break;
								
			case 2: printf("\n\t\tAdministraci%cn de Libros. Borrar Libro.\n", 162);
					eId = LeerIdLibro("borrar", eTotal, aLibros[eTotal].eId);
					
					if (eId > -1){					
						BorrarLibro(aLibros, &eTotal, eId);	
					}					
		  			break;
		  			
			case 3: printf("\n\t\tAdministraci%cn de Libros. Modificar Datos Libro.\n", 162);
					eId = LeerIdLibro("modificar", eTotal, aLibros[eTotal].eId);
					
					if (eId > -1){					
						ModificarLibro(aLibros, eTotal, eId);	
					}
					break;
					
			case 4: printf("\n\t\tAdministraci%cn de Libros. Consultar Libro.\n", 162);
					eId = LeerIdLibro("consultar", eTotal, aLibros[eTotal].eId);
										
					if (eId > -1){										
						ConsultarLibroPorId(aLibros, eTotal, eId);
					} 					
					
					break;
			
			case 5: printf("Lista de libros: \n");
										
					printf("ID Titulo                Autores       Edic A%co Ed Editorial  Pais       ISBN       Fec.Reg. Genero              Copias\n", 164);
					printf("_______________________________________________________________________________________________________________________\n");
					
					ListarLibros(aLibros, eTotal);
					break;
		
			case 6: printf("Regresando a men%c principal...", 163);
					break;
		
			default: printf("Error en la selecci%cn", 162);
					break;	  	
		}
		
		fflush(stdin);
		getchar();
		
	}while(eOpcion != 6);
	
} //main

TrLibro LeerLibro(){

	TrLibro rLibro;
	int eAutor, eIdAutor;
	char cOtro;
	TaCadena cGenero;
	 
	printf("\n\t\tIngrese los siguientes datos del libro: \n");
	
	printf("\nTitulo: ");
	fflush(stdin);
	gets(rLibro.cTitulo);
	
	InicializarAutores(rLibro.aAutores);	
	eAutor = 0;
	
	do{
		
		printf("Autor %d: ", eAutor + 1);
		scanf("%d", &eIdAutor);
		rLibro.aAutores[eAutor] = eIdAutor;
		printf("\n%cDesea ingresar otro autor? ", 168);
		fflush(stdin);
		cOtro = getchar();
 		eAutor ++;
 		
	}while(cOtro != 'n' && cOtro != 'N' );
	
	printf("Editorial: ");
	fflush(stdin);
	gets(rLibro.cEditorial);
	
	printf("Edici%cn: ",162);
	fflush(stdin);
	scanf("%d", &rLibro.eNumEdicion);
	
	printf("A%co de edici%cn: ", 164, 162);
	fflush(stdin);
	scanf("%d", &rLibro.eAnioEdicion);
	
	printf("Pais de origen: ");
	fflush(stdin);
	gets(rLibro.cPais);
	
	printf("ISBN: ");
	fflush(stdin);
	gets(rLibro.cISBN);
	
	printf("Fecha de registro: ");
	printf("\n\tDia: ");
	fflush(stdin);
	scanf("%d", &rLibro.rFecRegistro.eDia);
	printf("\tMes: ");
	fflush(stdin);
	scanf("%d", &rLibro.rFecRegistro.eMes);
	printf("\tA%co: ", 164);
	fflush(stdin);
	scanf("%d", &rLibro.rFecRegistro.eAnio);

	printf("G%cnero: ", 130);
	fflush(stdin);
	scanf("%d", &rLibro.eGenero);
	ObtenerGenero(rLibro.eGenero, cGenero);
	printf("\t%s\n", cGenero);
	
	printf("N%cmero de copias: ", 163);
	fflush(stdin);
	scanf("%d", &rLibro.eNumCopias);

	rLibro.eId = GenerarIdLibro();
	
	return rLibro;
	
} //LeerLibro 

void InsertarLibro (TaLibros aLibros, int *eTotal, TrLibro rLibro) {
	
	int eRecorre;
	
	if(*eTotal == MAX_LIBROS - 1) {
		
		printf("No se pueden agregar m%cs libros", 160);
	
	} else {
		
		if(*eTotal == -1 || rLibro.eId > aLibros[*eTotal].eId)	{
		
			(*eTotal)++;
			aLibros[*eTotal] = rLibro;
			printf("\n\n\t%s registrado correctamente.", rLibro.cTitulo);
		
		} else {
		
			if(BuscarLibroPorId(aLibros, *eTotal, rLibro.eId) != -1) {
		
				printf("\n\n\tYa existe %d", rLibro.eId);
		
			} else {
				
				eRecorre = *eTotal;
				while (eRecorre >= 0 && aLibros[eRecorre].eId > rLibro.eId){
					aLibros[eRecorre + 1] = aLibros[eRecorre];
					eRecorre--;
				}
				aLibros[eRecorre + 1] = rLibro;
				(*eTotal)++;

				printf("\n\n\t%s registrado correctamente.", rLibro.cTitulo);
			}
		}
	} 
} //InsertarLibro

int BuscarLibroPorId( TaLibros aLibros, int eTotal, int eId){
	
	int eMenor, eMayor, eMedio;
	
	if(eTotal == -1 ){
		
		return -1;
		
	} else {
		
		eMenor = 0;
		eMayor = eTotal;
		eMedio = (eMayor + eMenor) / 2;
		
		while ( eMenor < eMayor && aLibros[eMedio].eId != eId){
			
			if( eId < aLibros[eMedio].eId){
				eMayor = eMedio - 1;
			} else {
				eMenor = eMedio + 1;
			}
			
			eMedio = (eMayor + eMenor) / 2;
		}
		
		if ( eId == aLibros[eMedio].eId){
			return eMedio;
		} else{
			return -1;
		}
	}
} //BuscarLibroPorId

int GenerarIdLibro (){
	
	static int eSiguiente = 1;
	
	return (eSiguiente++);
} //GenerarIdLibro

void ListarLibros(TaLibros aLibros, int eTotal){
	
	int eAutor;
	TaCadena cGenero;
	char cSubcadena[20];
		
	if (eTotal != -1){
		
		ListarLibros(aLibros, eTotal - 1);
		
		strncpy(cSubcadena, aLibros[eTotal].cTitulo, 20);
		cSubcadena[20] = '\0';
		
		printf("%2d %-20s " , aLibros[eTotal].eId, cSubcadena);
		
		for(eAutor = 0; eAutor < MAX_AUTORES; eAutor++){
			
			if(aLibros[eTotal].aAutores[eAutor] != 0){
				printf("%2d ", aLibros[eTotal].aAutores[eAutor]);	
			} else {
				printf("   ");
			}
			
		}
		
		ObtenerGenero(aLibros[eTotal].eGenero, cGenero);
		strncpy(cSubcadena, cGenero, 20);
		cSubcadena[20] = '\0';
                
		printf("%4d %6d %-10s %-10s %-10s %02d/%02d/%02d %-20s %5d \n", 
		aLibros[eTotal].eNumEdicion, 
		aLibros[eTotal].eAnioEdicion, 
		aLibros[eTotal].cEditorial, 
		aLibros[eTotal].cPais, 
		aLibros[eTotal].cISBN, 
		aLibros[eTotal].rFecRegistro.eDia, 
		aLibros[eTotal].rFecRegistro.eMes, 
		aLibros[eTotal].rFecRegistro.eAnio, 
		cSubcadena,
		aLibros[eTotal].eNumCopias);
	} 
	
} //ListarLibros

void ObtenerGenero(int eGenero, TaCadena cGenero){
	
	switch(eGenero){
		case LP: strcpy(cGenero, "Lenguajes de programacion");
				break;
		case TELE: strcpy(cGenero, "Redes y telecomunicaciones");
				break;	 
		case BD: strcpy(cGenero, "Bases de datos");
				break;
		case SEGURIDAD: strcpy(cGenero, "Seguridad informatica");
				break;
		default: strcpy(cGenero, "Indefinido");
				break;
	}	
} //ObtenerGenero 

void InicializarAutores(int aAutores[MAX_AUTORES]){
	int eAutor;
	for(eAutor = 0; eAutor < MAX_AUTORES; eAutor++){
		aAutores[eAutor] = 0;
	}
} //InicializarAutores

void BorrarLibro (TaLibros aLibros, int *eTotal, int eId){
	
	int ePos, eRecorre;
	char cConfirma; 
	
	if (*eTotal == -1){
		
		printf("\n\n\tNo hay libros registrados.");
		
	} else {
		
		ePos = BuscarLibroPorId(aLibros, *eTotal, eId);
		
		if (ePos == -1) {
			
			printf("\n\n\tEl id %d no existe.", eId);
					
		} else {

			MostrarDatosLibro(aLibros[ePos]);
			printf("\n\n\t\t%cDesea borrar el registro?[S/N]: ", 168);
			fflush(stdin);
			cConfirma = getchar(); 
			
			if (cConfirma == 's' || cConfirma == 'S'){
			
				for (eRecorre = ePos; eRecorre < *eTotal; eRecorre++){
					
					aLibros[eRecorre] = aLibros[eRecorre + 1];
				}
				
				(*eTotal)--;

				printf("\n\n\tLibro borrado correctamente.");
			}
		}
	}
} //BorrarLibro 

int LeerIdLibro(TaCadena cOperacion, int eTotal, int eUltimoId){
	
	int eId;
		
	if (eTotal == -1) {
		
		printf ("\n\nNo hay libros registrados.");
		fflush(stdin);
		getchar();
		return -1;
		
	} else {

		do {
		
			printf("\n\nIngrese el id del libro a %s: ", cOperacion);
			fflush(stdin);
			scanf("%d", &eId);
		
		} while (eId < 1 || eId > eUltimoId);
	
		return eId;
	} 
} //LeerIdLibro

void MostrarDatosLibro(TrLibro rLibro){
	
	int eAutor, eIdAutor;
	char cOtro;
	TaCadena cGenero;
	 
	printf("\n\t\tDatos del libro: %d \n", rLibro.eId);
	
	printf("\n\nTitulo: %s", rLibro.cTitulo);
	
	for (eAutor = 0; eAutor < MAX_AUTORES; eAutor++){
	
		if (rLibro.aAutores[eAutor] != 0){		
			printf("\nAutor %d: %d", eAutor + 1, rLibro.aAutores[eAutor]);	
		}
	}
	
	printf("\nEditorial: %s", rLibro.cEditorial);	
	printf("\nEdici%cn: %d", 162, rLibro.eNumEdicion);	
	printf("\nA%co de edici%cn: %d", 164, 162, rLibro.eAnioEdicion);
	printf("\nPais de origen: %s", rLibro.cPais);	
	printf("\nISBN: %s", rLibro.cISBN);
	printf("\nFecha de registro: %02d/%02d/%02d",
		rLibro.rFecRegistro.eDia, rLibro.rFecRegistro.eMes, rLibro.rFecRegistro.eAnio);

	ObtenerGenero(rLibro.eGenero, cGenero);
	printf("\nG%cnero: %s", 130, cGenero);	
	printf("\nN%cmero de copias: %d", 163, rLibro.eNumCopias);
	
} //MostrarDatosLibro

void ConsultarLibroPorId(TaLibros aLibros, int eTotal, int eId){

	int ePos;

	ePos = BuscarLibroPorId(aLibros, eTotal, eId);
	
	if (ePos > -1){
	
		MostrarDatosLibro(aLibros[ePos]);	
		printf("\n\n\tPresione una tecla para continuar...");
		
	} else {
		
		printf("\n\n\tNo se encontr%c el id %d", 162, eId);
	}
} //ConsultarLibroPorId

void ModificarLibro(TaLibros aLibros, int eTotal, int eId){
	
	int ePos, eDato, eAutor; 
	TaCadena cGenero;
	
	if (eTotal == -1){
		
		printf("\n\n\tNo hay libros resgistrados.");
		
	} else {
		
		ePos = BuscarLibroPorId(aLibros, eTotal, eId);
		
		if (ePos == -1) {
			
			printf("\n\n\tNo existe el id %d.", eId);
			
		} else {

			do {
					
				MostrarDatosLibro(aLibros[ePos]);
				
				printf("\n\n1. T%ctulo"
						"\n2. Autor"
						"\n3. Editorial"
						"\n4. Edici%cn"
						"\n5. A%co de edici%cn"
						"\n6. Pais de origen"
						"\n7. ISBN"
						"\n8. Fecha de registro"
						"\n9. G%cnero"
						"\n10. N%cmero de copias"
						"\n11. Regresar", 161, 162, 164, 162, 130, 163);
				printf("\n\n\tSeleccione el dato a modificar: ");
				scanf("%d", &eDato);
				
				switch(eDato){
					
					case 1: printf("\nNuevo T%ctulo: ", 161);
							fflush(stdin);
							gets(aLibros[ePos].cTitulo);
							break;
					
					case 2: printf("N%cmero de Autor a modificar: ", 163);
							scanf("%d", &eAutor);
							printf("Nuevo Id de Autor: ");
							scanf("%d", &aLibros[ePos].aAutores[eAutor - 1]);
							break;
							
					case 3: printf("Nueva Editorial: "); 		
							fflush(stdin);
							gets(aLibros[ePos].cEditorial);
							break;
		
					case 4: printf("Nueva Edici%cn: ", 162);
							fflush(stdin);
							scanf("%d", &aLibros[ePos].eNumEdicion);
							break;
							
					case 5: printf("Nuevo A%co de edici%cn: ", 164, 162);
							fflush(stdin);
							scanf("%d", &aLibros[ePos].eAnioEdicion);
							break;
		
					case 6: printf("Nuevo Pais de origen: ");
							fflush(stdin);
							gets(aLibros[ePos].cPais);
							break;
		
					case 7: printf("Nuevo ISBN: ");
							fflush(stdin);
							gets(aLibros[ePos].cISBN);
							break;
		
					case 8:	printf("Nueva Fecha de registro: ");
							printf("\n\tDia: ");
							fflush(stdin);
							scanf("%d", &aLibros[ePos].rFecRegistro.eDia);
							printf("\tMes: ");
							fflush(stdin);
							scanf("%d", &aLibros[ePos].rFecRegistro.eMes);
							printf("\tA%co: ", 164);
							fflush(stdin);
							scanf("%d", &aLibros[ePos].rFecRegistro.eAnio);
							break;
			
					case 9: printf("Nuevo G%cnero: ", 130);
							fflush(stdin);
							scanf("%d", &aLibros[ePos].eGenero);
							ObtenerGenero(aLibros[ePos].eGenero, cGenero);
							printf("\t%s\n", cGenero);
							break;
		
					case 10: printf("Nuevo N%cmero de copias: ", 163);
							fflush(stdin);
							scanf("%d", &aLibros[ePos].eNumCopias);
							break;
					case 11: printf("Registro modificado correctamente.");
							 break;
					
					default: printf("Error en la selecci%cn.", 162); 
				}
			} while (eDato != 11);
			
		}
	}
} //ModificarLibro	
