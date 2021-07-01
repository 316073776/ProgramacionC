/* *********************************************************************************
PROGRAMA: U3P2.c
AUTOR: Segura Rios Brenda Stephane
FECHA: 04/04/2019
OBJETIVO: Sumar todos los valores entre 5 y 30.
********************************************************************************** */

#include <stdio.h>

int main (){
	
	int eContador = 5, eFinal = 30, eSuma = 0;
	
	printf("Programa que suma los valores entre 5 y 30.\n\n");
	
	do{
		
		eSuma += eContador;
		eContador ++;
		
	} while ( eContador <= eFinal );
	
	printf("La suma de los n%cmeros es: %d", 163, eSuma);

	getchar ();
	return 0;
}



