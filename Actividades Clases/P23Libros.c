/* **********************************************************************
	NOMBRE DEL PROGRAMA: P23Libros.c
	OBJETIVO: 
	AUTOR: Segura Rios Brenda Stephanie
	FECHA: 05/06/2019
********************************************************************** */

//BILIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CONSTANTES
#define MAX_LIBROS 10
#define MAX_AUTORES 5

//TIPOS
typedef struct{  					//Definir tipo: registro
	int eDia, eMes, eAnio;	
}TrFecha;

typedef enum{						//Definir tipo: enumerado
	LP, TELE, BD, SEGURIDAD			//No lleva ;
}TeGenero;

typedef char TaCadena[30];

typedef struct{
	int aAutores[MAX_AUTORES];
	TaCadena cTitulo, cEditorial, cPais, cISBN;
	int eNumEdicion, eAnioEdicion, eCopias, eId;
	TrFecha rFecRegistro;
	TeGenero eGenero;
}TrLibro;

typedef TrLibro TaLibros[MAX_LIBROS];

//PROTOTIPOS
TrLibro LeerLibro();
void InsertarLibro(TaLibros, int*, TrLibro);
int BuscarLibroPorId(TaLibros, int, int);
int GenerarIdLibro();
void ListarLibros(TaLibros, int);
void InicializarAutores(TaAutores);

//FUNCIÓN PRINCIPAL
int main (){
	
	//VARIABLES
	int eTotal = -1, eOpcion, eId;
	TrLibro rLibro;
	TaCadena cTitulo;
	TaLibros aLibros;
	TeGenero eGenero;
	
	system("cls");
	printf("Administracion de libros."); 
	

	getchar();
	return 0;
}


TrLibro LeerLibro(){
	
	char cOtro;
	TrLibro rLibro;
	int eAutor;
	
	printf("Ingrese los datos del libro: ");
	printf("T%ctulo: ", 162);
	fflush(stdin);
	gets(rLibro.cTitulo);
	eAutor = 0;
	do{
		
		printf("Ingrese el autor %d :", eAutor + 1);
		scanf("%d", rLibro.aAutores[eAutor]);
		printf("¿Desea ingresar otro autor?");
		cOtro = getchar();
		eAutor ++;
		 
	}while ( cOtro != 'n' && cOtro != 'N' );
	
	printf("Editorial: ");
	gets(rLibro.cEditorial);
	printf("N%cmero de edici%cn: ", 163, 162);
	scanf("%d", &rLibro.eNumEdicion);
	printf("A%co de edici%cn: ", 164, 162);
	scanf("%d", &rLibro.eAnioEdicion);
	printf("Pa%cs de origen: ", 161);
	gets(rLibro.cPais);
	printf("ISBN: ");
	gets(rLibro.cISBN);
	printf("Fecha de registro: ");
	printf("\n\tD%ca: ", 161);
	scanf("%d", rLibro.rFecRegistro.eDia);
	printf("\tMes: ");
	scanf("%d", rLibro.rFecRegistro.eMes);
	printf("\tA%co: ", 164);
	scanf("%d", rLibro.rFecRegistro.eAnio);	
	printf("Copias: ");
	scanf("%d", rLibro.eCopias);
	printf("Genero: ");
	scanf("%d", &rLibro.eGenero);
	
	rLibro.eId = GenerarIdLibro();
	return rLibro;
	
}


void InsertarLibro(TaLibros aLibros, int *eTotal, TrLibro rLibro){
	
	int eRecorre;
	
	if(*eTotal == MAX_LIBROS - 1){
		
		printf("No se pueden agregar m%cs libros.", 160);
		
	} else if (*eTotal == -1 || rLibro.eId > aLibros[*eTotal].eId){
		
		(*eTotal) ++;
		aLibros[*eTotal] = rLibro;
		
	} else if (BuscarLibroPorId(aLibros, *eTotal, rLibro.eId) != -1){
		
		printf("Ya existe %d.", rLibro.eId);
			
	} else {
			
		eRecorre = *eTotal;
		while (eRecorre >= 0 && aLibros[eRecorre].eId > rLibro.eId){
			
			aLibros[eRecorre + 1] = aLibros[eRecorre];
			eRecorre --;
			
		}
		
		aLibros[eRecorre + 1] = rLibro;
		(*eTotal) ++;
		
	}
}


int BuscarLibroPorId(TaLibros aLibros, int eTotal, int eId){
	
	int eMenor, eMayor, eMedio;
	
	if( eTotal == -1 ){
		
		return 0;
		
	} else {
		
		eMenor = 0;
		eMayor = eTotal;
		eMedio = (eMayor + eMenor) / 2;
		
		while ( eMenor < eMayor && aLibros[eMedio].eId != eId ){
			
			if ( eId > aLibros[eMedio].eId){
				
				eMayor = eMedio --;
				
			} else {
				
				eMenor = eMedio ++;
				
			}
			
			eMedio = (eMayor + eMenor) / 2;
			
		}
		
		if ( eId == aLibros[eMedio].eId){
			
			return eMedio;
			
		} else {
			
			return -1;
			
		}
	}
}


int GenerarIdLibro(){
	
	static int eSiguiente = 0;
	
	return (eSiguiente ++);
	
}


void ListarLibros(TaLibros aLibros, int eTotal){
	
	int eAutor;
	TaCadena cGenero;
	
	if ( eTotal != 0 ){
		
		ListarLibros(aLibros, eTotal - 1);
		printf("%d , %s", aLibros[eTotal].eId, aLibros[eTotal].eTitulo);
		for ( eAutor = 0; eAutor < MAX_AUTORES; eAutor++ ){
			
			printf("%d", aLibros[eTotal].aAutores[eAutor]);
			
		}
		
		obtenerGenero(aLibros[eTotal].eGenero, cGenero);
		printf("\n%d\n%d\n%s\n%s\n%s\n%d / %d / %d\n%d\n%d", 
				aLibros[eTotal].eNumEdicion, 
				aLibros[eTotal].eAnioEdicion, 
				aLibros[eTotal].cEditorial, 
				aLibros[eTotal].cPais, 
				aLibros[eTotal].cISBN, 
				aLibros[eTotal].rFecRegistro.eDia, 
				aLibros[eTotal].rFecRegistro.eMes,  
				aLibros[eTotal].rFecRegistro.eAnio, 
				cGenero, 
				aLibros[eTotal].eCopias);
	} else {
		
		printf ("Registro vac%co.", 160);
		
	}
}


void ObtenerGenero(int eGenero){
	
	
}


void InicializarAutores(TaAutores aAtutores[MAX_AUTORES]){
	
	int eAutor;
	
	for (eAutor = 0; aAutor < MAX_AUTORES; eAutor ++){
		
		aAutores[aAutor] = 0;
		
	}
}
