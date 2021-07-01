/* *********************************************************************************
PROGRAMA: U3P4.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 04/04/2019
OBJETIVO: Mostrar cuántos valores se ingresaron y cuál fue el mayor de todos.
********************************************************************************** */

#include <stdio.h>

int main (){
	
	int eValor, eContador, eMayor;
	
	printf("Programa que muestra el n%cmero mayor de un conjunto de valores ingresados.\n\n", 163);
	
	printf("Ingrese un valor [0 = Salir]: ");
	scanf("%d", &eValor);
	
	if ( eValor != 0 ){
		
		eMayor = eValor;
		eContador = 1;
	
	}
		
	do{

		printf("Ingrese un valor [0 = Salir]: ");
		scanf("%d", &eValor);

		if ( eValor != 0 ){
			
			if ( eValor >= eMayor && eValor != 0 ){
				
				eMayor = eValor;
					
			}
			
		eContador ++;
		
		}
		
	} while ( eValor != 0 );
	
	printf("\nIngresaste %d valores y el mayor es %d", eContador, eMayor);
	
	getchar ();
	return 0;
}



