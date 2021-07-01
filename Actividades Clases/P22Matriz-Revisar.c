/* **********************************************************************
NOMBRE DEL PROGRAMA: P22Matriz.c
OBJETIVO: 
AUTOR: Segura Rios Brenda Stephanie
FECHA: 30/05/2019
********************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define MAX_REN 5
#define MAX_COL 5

typedef int TaMatriz[MAX_REN][MAX_COL];

void LeerMatriz(TaMatriz);
void EscribirMatriz(TaMatriz);
int BuscarMatriz(TaMatriz, int, int*, int*);
void TransponerMatriz(TaMatriz);
void EsSimetrica(TaMAtriz);

int main (){
	
	TaMatriz aMatriz;
	int eRen, eCol, eOpcion, eElemento;
	
	printf("Progama que realiza manejo b%csico de matrices bidimensionales.", 160);
	printf("\n\n1.Leer\n2. Escribir\n3. Buscar\n4. Transponer\n5. Simetr%ca\n6. Salir", 161);
	printf("Seleccione una opci%cn: ", 162);
	scanf("%d", &eOpcion);
	
	do{
	
		switch( eOpcion ){
			
			case 1: LeerMatriz(aMatriz);
					break;
					
			case 2: EscribirMatriz(aMatriz);
					break;
					
			case 3: printf("Ingrese el elemento que desee buscar: ");
					scanf("%d", &eElemento);
					
					if( BuscarMatriz(aMatriz, eElemento, &eRen, &eCol)){
				
						printf("El elemento %d se encuantra");
	   					
					} else {
						
						printf("No e encontr%c el elemento", 162);
					}
					break;
			
			case 4: TransponerMatriz(aMatriz);
					break;
			
			case 5: if (EsSimetrica(aMatriz)){
						
						printf("La matriz es simetrica.");
						
					} else {
					
						printf("La matriz no es simetrica.");
					}
					break;
			
			case 6: printf("Adios!!!");
					break;
					
			default: printf("Error en la selecci%cn.", 162);
					break;
					
		}
		
		fflush(stdin);
		getchar();
		
	} while(eOpcion != 6);
	return 0;

}


void LeerMatriz(TaMatriz){
	
	int eRen, eCol;
	
	for( eRen = 0; eRen < MAX_REN; eRen++ ){
		
		for( eCol = 0; eCol < MAX_COL; eCol++ ){
			
			printf("Ingrese la matriz [&d, %d]", eRen + 1, eCol + 1);
			scanf("%d", &aMatriz[eRen][eCol]);
			
		}
	}
}


void EscribirMatriz(TaMatriz aMatriz){
	
	int eRen, eCol;
	
	for( eRen = 0; eRen < MAX_REN; eRen++ ){
		
		for( eCol = 0; eCol < MAX_COL; eCol++ ){
			
			printf("\tMatriz [&d, %d] = ", eRen + 1, eCol + 1, aMatriz[eRen][eCol]);
			
		}
		
		printf("\n");
	}
	
}


int BuscarMatriz(TaMatriz aMatriz, int eElemento, int *eRen, int *eCol){
	
	*eRen = 0;
	*eCol = 0;
	
	while(eElemento != aMatriz[*eRen][*eCol] && *eRen < MAX_REN ){
		
		*eCol = 0;	
		
		while(eElemento != aMatriz[*eRen][*eCol] && *eCol < MAX_COL ){
			
			(*eCol) ++;
			
		}
	
		if(eElemento != aMatriz[*eRen][*eCol]){
		
			(*eRen) ++;
		
		}
	}
	
	if(eElemento == aMatriz[*eRen][*eCol]){
		
		return 1;
		
	} else {
		
		return 0;
		
	}
}


void TransponerMatriz(TaMatriz aMatriz){
	
	int eRen, eCol, eTemp;
	
	for( eRen = 0; eRen < MAX_REN - 1; eRen ++ ){
		
		for( eCol = eRen + 1; eCol < MAX_COL; eCol ++ ){
			
			eTemp = aMatriz[eRen][eCol];
			aMatriz[eRen][eCol] = aMatriz[eCol][eRen];
			aMatriz[eCol][eRen] = eTemp;
			
		}
	}
}




int EsSimetrica(TaMAtriz aMAtriz){
	
	int lSimetrica, eRen, eCol;
	
	if (MAX_REN != MAX_COL){
		
		return 0;
		
	} else {
		
		lSimetrica = 1;
		eRen = 0;
		
		while(lSimetrica && eRen < MAX_REN - 1){
			
			eCol = eRen;
			
			while(lSimetrica && eCol < MAX_COL){
				
				eCol ++;
				
				if( aMatriz[eRen][eCol] != aMatriz[eCol][eRen]){
					
					lSimetrica = !lSimetrica;
					
				}
			}
			
			eRen ++;
			
		}
	}
}
