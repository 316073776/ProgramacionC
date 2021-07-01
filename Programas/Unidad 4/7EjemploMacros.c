/* *********************************************************************************
PROGRAMA: EjemploMacros.c
AUTOR: Segura Rios Brenda Stephane
FECHA: 09/05/2019
OBJETIVO: Ver ejemplo de uso de macros.
********************************************************************************** */

#include <stdio.h>

#define cuadrado(x) x * x		//Macro

int main (){
	
	int eNumero;
	
	printf("Cuadrado de un n%cmero.\n", 163);
	printf("\nIngrese un n%cmero: ", 163);
	scanf("%d", &eNumero);
	
	printf("\nEl cuadrado de %d = %d", eNumero, cuadrado(eNumero));

	getchar ();
	return 0;
}



