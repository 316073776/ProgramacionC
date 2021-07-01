/* **********************************************************************
NOMBRE DEL PROGRAMA: P14Rango.c
OBJETIVO: Mostrar la suma de los números entre dos números.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 04/04/2019
********************************************************************** */
//Desde-Hasta
/*
#include <stdio.h>

int main (){
	
	int eSuma = 0, eNum, eContador;
	
	printf("Programa que suma todos los valores enteros entre 2 y el n%cmero dado.", 163);
	printf("\n\nIngresa un n%cmero entero: ", 163);
	scanf("%d", &eNum);
	
	if ( eNum >= 2 ){
		
		for ( eContador = 2; eContador <= eNum; eContador++){	
		eSuma += eContador;
		}
		
	} else {
		
		for ( eContador = 2; eContador >= eNum; eContador--){
		eSuma += eContador;
		}
		
	}
	
	printf("\nLa suma de los n%cmeros entre 2 y %d es igual a: %d", 163, eNum, eSuma);

	getchar();
	return 0;
}



// Mientras-Hacer

#include <stdio.h>

int main (){
	
	int eSuma = 0, eNum, eContador = 2;
	
	printf("Programa que suma todos los valores enteros entre 2 y el n%cmero dado.", 163);
	printf("\n\nIngresa un n%cmero entero: ", 163);
	scanf("%d", &eNum);
	
	if ( eNum >= 2 ){
		
		while ( eContador <= eNum ){
			
			eSuma += eContador;
			eContador ++;	 
		}	
		
	} else {
		
		while ( eContador >= eNum ){
			
			eSuma += eContador;
			eContador --;
		}
	}
	
	printf("\nLa suma de los n%cmeros entre 2 y %d es igual a: %d", 163, eNum, eSuma);
	
	getchar();
	return 0;
}
*/

// Repetir-Hasta

#include <stdio.h>

int main (){
	
	int eSuma = 0, eNum, eContador = 2;
	
	printf("Programa que suma todos los valores enteros entre 2 y el n%cmero dado.", 163);
	printf("\n\nIngresa un n%cmero entero: ", 163);
	scanf("%d", &eNum);
	
	if ( eNum >= 2 ){
		
		do {
			
			eSuma += eContador;
			eContador ++;	 
		} while ( eContador <= eNum );
		
	} else {
		
		do {
			
			eSuma += eContador;
			eContador --;
		} while ( eContador >= eNum );
	}
	
	printf("\nLa suma de los n%cmeros entre 2 y %d es igual a: %d", 163, eNum, eSuma);
	
	getchar();
	return 0;
}



