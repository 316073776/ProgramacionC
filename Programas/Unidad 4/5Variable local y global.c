/* *********************************************************************************
PROGRAMA: Variables local yy global.
AUTOR: Segura Rios Brenda Stephane
FECHA: 02/05/2019
OBJETIVO: Ver la diferencia del uso de variable local y global en la modularizaci�n.
********************************************************************************** */

#include <stdio.h>

void funcion(); //Declaraci�n de la funci�n

int eNumero = 5;   //Variable global

int main (){
	
	int eNumero = 10;   //Variable local
	

	printf("Variable local: %d\n", eNumero);
	funcion ();

	getchar ();
	return 0;
}


void funcion(){
	printf("Variable global: %d", eNumero);
}



