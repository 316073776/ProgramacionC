/* *****
* Programa: A22Matriz.c
* Autor: Misael Martínez Vázquez
* Objetivo: 
* Fecha: 30/05/2019
***** */

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define MAX_REN 3
#define MAX_COL 3

//Tipos
typedef int TaMatriz[MAX_REN][MAX_COL];
 
//Prototipos
void LeerMatriz(TaMatriz);
void EscribirMatriz(TaMatriz);
int BuscarMatriz(TaMatriz, int, int*, int*);
void TransponerMatriz(TaMatriz);
int EsSimetrica(TaMatriz);

//Programa Principal
int main(){
	
	TaMatriz aMatriz;
	int eRen, eCol, eOpcion, eElemento;
	
	do {
		
		system("cls");
		printf("\n\n\tPrograma que muestra el manejo b%csico de matrices\n\n", 160);
		printf("\t\t1. Leer\n\t\t2. Escribir\n\t\t3. Buscar\n\t\t4. Transponer\n"
				"\t\t5. Verificar Simetr%ca\n\t\t6. Salir\n", 161);
		printf("\n\n\t\tSeleccione una opci%cn: ", 162);
		scanf("%d", &eOpcion);
		
		system("cls");
		
		switch (eOpcion){
			
			case 1: LeerMatriz(aMatriz);
					break;
			
			case 2: EscribirMatriz(aMatriz);			
					break;
					
			case 3: printf("Ingrese el elemento que desea buscar:");
					scanf("%d", &eElemento);
					
					if (BuscarMatriz(aMatriz, eElemento, &eRen, &eCol)){
						
						printf("El elemento %d se encuentra en la posici%cn [%d, %d]", eElemento, 162, eRen + 1, eCol + 1);
						
					} else{
						
						printf("No se encontr%c el elemento %d", 162, eElemento);
					}
					break;
					
			case 4: TransponerMatriz(aMatriz);
					break;
						
			case 5: if (EsSimetrica(aMatriz)){
					
						printf("\n\n\t\tLa matriz SI es sim%ctrica", 130);
						
					} else{
						
						printf("\n\n\t\tLa matriz NO es sim%ctrica", 130);
					}
					break;
					
			case 6: printf("Adios!");
					break;
								
			default: printf("Error en la selecci%cn", 162);
							
		
		}
		
		fflush(stdin);
		getchar();
		
	} while (eOpcion != 6);

	return 0;
}

/*
	Procedimiento: LeerMatriz
	Autor:
	Fecha:
	Objetivo: Almacenar todos los datos de una matriz de enteros
	DE: Matriz de enteros (aMatriz)
	DS:
*/
void LeerMatriz(TaMatriz aMatriz){
	
	int eRen, eCol;
	
	printf("\n\nIngrese los datos de la matriz:\n\n");

	for (eRen = 0; eRen < MAX_REN; eRen++){
		
		for (eCol = 0; eCol < MAX_COL; eCol++){
			
			printf("Matriz [%d, %d]: ", eRen + 1, eCol + 1);
			scanf("%d", &aMatriz[eRen][eCol]);
			
		}
	}
	
	printf("\n\nMatriz registrada correctamente!");

} //LeerMatriz

/*
	Procedimiento: EscribirMatriz
	Autor:
	Fecha:
	Objetivo: Mostrar todos los datos almacenados en una matriz de enteros
	DE: Matriz de enteros (aMatriz)
	DS: Los datos de la matriz (aMatriz[renglon][columna])
*/
void EscribirMatriz(TaMatriz aMatriz){
	
	int eRen, eCol;
	
	printf("\n\nLos datos de la matriz son: \n\n");

	for (eRen = 0; eRen < MAX_REN; eRen++){
		
		for (eCol = 0; eCol < MAX_COL; eCol++){
			
			printf("\t%d, ", aMatriz[eRen][eCol]);
			
		}
		printf("\n");
	}
} //EscribirMatriz

/*
	Función: BuscarMatriz
	Autor:
	Fecha:
	Objetivo: Localizar un valor (eElemento) dentro de una matriz de enteros
	DE: aMatriz: Matriz de enteros
		eElemento: valor a localizar en la matriz
	DS: eRen: renglón donde se encuentra el elemento, si existe 
		eCol: columna donde se enecuentra el elemento, si existe
	Retorna: Verdadero si encuentra el elemento, Falso de lo contrario
*/
int BuscarMatriz(TaMatriz aMatriz, int eElemento, int *eRen, int *eCol){

	*eRen = 0;
	*eCol = 0;
		
			//cambio condiciones al revés
	while (*eRen < MAX_REN && eElemento != aMatriz[*eRen][*eCol]) {
			
			//cambio condiciones al revés
		while (*eCol < MAX_COL && eElemento != aMatriz[*eRen][*eCol]){
			
			(*eCol)++;
		}
				
		if (*eCol == MAX_COL) {	//cambio
		//} && eElemento != aMatriz[*eRen][*eCol]){
	
			(*eRen)++;
			*eCol = 0;
		}
	}
		
	if (eElemento == aMatriz[*eRen][*eCol]){

		return 1;
		
	} else {

		return 0;
	}	
} //BuscarMatriz

/*
	Procedimiento: TransponerMatriz
	Autor:
	Fecha:
	Objetivo: Cambiar los elementos que se encuentran en los renglones, a las columnas y viceversa
	DE: Matriz de enteros (aMatriz)
	DS:
*/
void TransponerMatriz(TaMatriz aMatriz){
	
	int eRen, eCol, eTemp;

	if (MAX_REN != MAX_COL){
	
		printf("La matriz no es cuadrada, no se puede transponer.");
	
	} else {
	
		for (eRen = 0; eRen < MAX_REN - 1; eRen++){
			
			for (eCol = eRen + 1; eCol < MAX_COL; eCol++){
				
				eTemp = aMatriz[eRen][eCol];
				aMatriz[eRen][eCol] = aMatriz[eCol][eRen];
				aMatriz[eCol][eRen] = eTemp;
			}
		}
		
		printf("Matriz Transpuesta correctamente.");
	}
} //TransponerMatriz

/*
	Función: EsSimetrica
	Autor:
	Fecha:
	Objetivo: Identificar si una matriz de enteros es igual a su transpuesta
	DE: aMatriz: Matriz de enteros
	DS: 
	Retorna: Verdadero si es simétrica, Falso de lo contrario
*/
int EsSimetrica(TaMatriz aMatriz){
	
	int lSimetrica, eRen, eCol;
	
	if (MAX_REN != MAX_COL){
		
		return 0;
		
	} else {
		
		lSimetrica = 1;
		eRen = 0;
		
		while (lSimetrica && eRen < MAX_REN - 1){
			
			eCol = eRen + 1; //cambio
			
			while (lSimetrica && eCol < MAX_COL){
				
				if (aMatriz[eRen][eCol] != aMatriz[eCol][eRen]){
					
					lSimetrica = !lSimetrica;
				}
				
				eCol++; //cambio
			}
			
			eRen++;			
		}
	}
	
	return lSimetrica;	
	
} //EsSimetrica
