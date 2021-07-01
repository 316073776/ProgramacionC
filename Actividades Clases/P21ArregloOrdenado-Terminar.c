/* **********************************************************************
NOMBRE DEL PROGRAMA: P21ArregloOrdenado.c
OBJETIVO: Mostrar las operaciones que se pueden realizar en un arreglo ordenado.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 23/05/2019
********************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef char TaCadena [30];
typedef TaCadena TaNombres[MAX];

void InsertarOrdenado (TaNombres, int*, TaCadena);
void EliminarOrdenado (TaNombres, int*, TaCadena);
int BuscarBinario (TaNombres, int, TaCadena);
void ModificarOrdenado (TaNnombres, int, TaCadena , TaCadena);
void ListarArreglo (TaNombres, int *eTotal);


int main (){
	
	TaNombres aNombres;
	TaCadena, cNombre, cNuevo;
	int eOpcion, eTotal = -1;
	
	printf("Programa que muestra el manejo de arreglos ordenados.\n");
	
	do {
		
		system ("cls");
		printf("\n1.- Insertar. \n2.- Eliminar. \n3.- Modificar. 4.- Buscar. \n5.- Listar. \n6.- Salir.");
		printf("\nSeleccione una opci%cn: ", 163);
		scanf("%d", &eOpcion);
		
		switch (eOpcion){
			
			case 1: printf("\nIngrese la cadena a insertar: ", 163);
					fflush(stdin);
					gets(cNombre);
					InsertarOrdenado (aNombres, &eTotal, cNombre);
					break;
					
			case 2: printf("\nIngrese el nombre a borrar: ");
					fflush(stdin);
					gets(cNombre);
					EliminarOrdenado (aNombres, &eTotal, cNombre);
					break;
					
			case 3: printf("\nIngrese el nombre a modificar: ");
					fflush(stdin);
					gets(cNombre);
					printf("Ingrese el nuevo nombre: ");
					fflush(stdin);
					gets(cNuevo);
					ModificarOrdenado (aNombres, &eTotal, cNombre, cNuevo);
					break;
					
			case 4: printf("\nIngrese el nombre a buscar: ");
					fflush(stdin);
					gets(cNombre);
					
					ePsición = BuscarBinario (aNombres, &eTotal, cNombre);
					
					if (ePosicion == -1 ){
						
						printf("%s no existe.", cNombre);
						
					} else {
						
						printf(" %s esta en la posicion %s ", eElemento, eNuevo);
						
					}
					InsertarOrdenado (aNombres, &eTotal, eElemento);
					break;
					
			case 5: ListarArrglo(aNombres, &eTotal);
			
			case 6: printf("Adios.");
			
		}
		
	} while (eOpcion != 6);
	
	getchar();
	return 0;
}


void InsertarOrdenado ( TaNombres aNombres, int *eTotal, TaCadena cNombre ){
	
	int eRecorre;
	
	if ( *eTotal == MAX - 1 ){
		
		printf("El arreglo ya est%c lleno.", 160);
		
	} else if (*eTotal == -1 || strcmp(cNombre, aNombres[*eTotal]) > 0){
		
		(*eTotal) ++;
		strcpy(aNombres[*eTotal], cNombre);
		printf("%s insertado correctamente", cNombre);
		
	} else if (BuscarBinario(aNombres, *eTotal, cNombre) != -1) {
		
		printf("Ya existe %s", cNombre);
		
	} else {
		
		eRecorre = *eTotal;
		
		while (eRecorre >= 0 && strcmp(aNombres[eRecorre], cNombre) > 0){
			
			strcpy (aNombres[eRecorre + 1], aNombres [eRecorre]);
			eRecorre --;
			
		}
		
		strcpy(aNombres[eRecorre + 1], cNombre);
		(*eTotal) ++;
		
	}
}


void EliminarOrdenado (TaNombres aNombres, int *eTotal, TaCadena cNombre){
	
	int eRecorre, ePos;
	
	if (*eTotal == -1) {
		
		printf("El arreglo est%c vac%co.", 160, 161);
		
	} else {
		
		ePos = BuscarBinario(aNombres, *eTotal, cNombre);
		
		if ( ePos == -1 ){
			
			printf("No existe el elemento %s en el arreglo.", cNombre);
			
		} else {
			
			for (eRecorre = ePos; eRecorre < *eTotal; eRecorre ++ ){
				
				strcpy( aNombres[eRecorre] = aNombres[eRecorre + 1] );
				
			}
			
			(*eTotal) --;
			
		}
		
	}
	
}

/**************************************************************** 
	FUNCIÓN: BuscarBinario
	DE: Arreglo de nombres (aNombres)
		Total de elementos en el arreglo (eTotal)
		Nombre a buscar (cNombre)
	DS: (Parametros, si gubiera.
	Retorno: La posición en la que se encuentra el elemnto.
****************************************************************/

int BuscarBinario (TaNombres aNombres, int *eTotal, TaCadena cNombre){
	
	int eMenor, eMayor, eMedio;
	
	if (eTotal == -1){
		
		return -1;
		
	} else {
		
		eMenor = 0;
		eMayor = 0;
		eMedio = (eMayor + eMenor) / 2;
		
		while ( eMenor < eMayor && strcmp(aNombres[eMedio], cNombre) != 0){		}
			
			if ( strcmp(aNombres[eMedio], cNombre) == 0 ){
			
				eMenor = eMedio +1;
			
			} else {
			
				eMayor = eMedio - 1;
			
			}
		
			eMedio = (eMenor + eMayor) / 2;
		
		}
	
		if ( strcmp(aNombres[eMedio], cNombre) == 0 ){
			
			return eMedio;
			
		} else {
			
			return -1;
			
		}
	}
}


void ModificarOrdenado (TaNombres aNombres, int eTotal, TaCadena cNombre, TaCadena cNuevo){
	
	if ( eTotal == -1 ){
		
		printf("El arreglo est%c vac%co.", 160, 161);
		
	} else if ( BuscarBinario (aNombres, eTotal, cNombre) == -1 ){
			
		printf("No existe el elemento %s en el arreglo.", cNombre);
			
	} else if ( BuscarBinario (aNombres, eTotal, cNombre) =! -1 ){
			
		printf("Ya existe %s", cNuevo);
		
	} else {
			
		EliminarOrdenado(aNombres, &eTotal, cNombre);
		InsertarOrdenado(aNombres, &eTotal, cNuevo);
		printf("%s modificado correctamente.", cNombre);
			
	}
		
}
	



/********************************************************
	Procedimiento: ListarArreglo.
	Objetivo: Mostrar todos los elementos del arreglo.
	Autor:
	Fecha de creación:
	Fecha de la última actualización:
	DE:
	DS:
********************************************************/
void ListarArreglo (TaNumeros aNumeros, int *eTotal){
	
	if( *eTotal != -1 ){
		
		ListarArreglo (aNumeros, *eTotal - 1);
		printf("aNumeros[%d] = %d", *eTotal, aNumeros[*eTotal]);
		
	}
	
}
					EliminarDesordenado (aNumeros, &eTotal, eElemento);
					break;
					
			case 3: printf("\nIngrese el n%cmero a modificar: ", 164);
					scanf("%d", &eElemento);
					printf("Ingrese un valor: ");
					scanf("%d", &eElemento);
					ModificarDesordenado (aNumeros, &eTotal, eElemento, eNuevo + 1);
					break;
					
			case 4: printf("\nIngrese el n%cmero a buscar: ", 164);
					scanf("%d", &eElemento);
					eNuevo = BuscarSecuencial (aNumeros, &eTotal, eElemento);
					
					if (eNuevo == -1 ){
						
						printf("%d no está declarado en el arreglo.", eElemento);
						
					} else {
						
						printf(" %d esta en la posicion %d ", eElemento, eNuevo);
						
					}
					InsertarDesordenado (aNumeros, &eTotal, eElemento);
					break;
					
			case 5: ListarArrglo(aNumeros, &eTotal);
			
			case 6: printf("Adios.");
			
		}
		
	} while (eOpcion != 6);
	
	getchar();
	return 0;
}


void InsertarDesordenado ( TaNumeros aNumeros, int *eTotal, int eElemento ){
	
	if ( *eTotal == MAX - 1 ){
		
		printf("El arreglo ya est%c lleno.", 160);
		
	} else {
		
		(*eTotal) ++;
		aNumeros[*eTotal] = eElemento;
	}
}

void EliminarDesordenado (TaNumeros aNumeros, int *eTotal, int eElemento){
	
	int eRecorre, ePos;
	
	if (*eTotal == -1) {
		
		printf("El arreglo est%c vac%co.", 160, 161);
		
	} else {
		
		ePos = 0;
		while ( ePos <= *eTotal && aNumeros[ePos] != eElemento){
			
			ePos ++;
			
		}
		
		if ( aNumeros[ePos] != eElemento ){
			
			printf("No existe el elemento %d en el arreglo.", eElemento);
			
		} else {
			
			for (eRecorre = ePos; eRecorre < *eTotal; eRecorre ++ ){
				
				aNumeros[eRecorre] = aNumeros[eRecorre + 1];
				
			}
			
			(*eTotal) --;
			
		}
		
	}
	
}


int BuscarSecuencial (TaNumeros aNumeros, int *eTotal, int eElemento){
	
	int ePos;
	
	if (*eTotal == -1){
		
		return 0;
		
	} else {
		
		ePos = 0;
		
		while ( ePos <= eTotal && aNumeros[ePos] != eElemento ){
			
			ePos ++;
			
		}
		
		if ( aNumeros[ePos] == eElemento ){
			
			return ePos;
			
		} else {
			
			return 0;
			
		}
	}
}


void ModificarDesordenado (TaNumeros aNumeros, int *eTotal, int eElemento, int eNuevo){
	
	int ePos;
	
	if ( eTotal == -1 ){
		
		printf("El arreglo est%c vac%co.", 160, 161);
		
	} else {
		
		ePos = BuscarSecuencial (aNumeros, eTotal, eElemento);
		
		if ( ePos == -1 ){
			
			printf("No existe el elemento %d en el arreglo.", eElemento);
			
		} else {
			
			aNumeros[ePos] = eNuevo;
			
		}
		
	}
	
}


void ListarArreglo (TaNumeros aNumeros, int *eTotal){
	
	if( *eTotal != -1 ){
		
		ListarArreglo (aNumeros, *eTotal - 1);
		printf("aNumeros[%d] = %d", *eTotal, aNumeros[*eTotal]);
		
	}
	
}
