/* *********************************************************************************
PROGRAMA: P04Cuadrado.c 
AUTOR: Segura Rios Brenda Stephane
FECHA: 27/03/2019
OBJETIVO: Obtener el cuadrado de un número entero.
********************************************************************************** */

#include <stdio.h>

int main (){
	
	int eCuadrado, eNum;
	
	printf("Programa que calcula el cuadrado de un n%cmero entero.", 163);
	printf("\n\nIngresa un n%cmero entero: ", 163);
	scanf("%d", &eNum);
	
	eCuadrado = eNum * eNum;
	
	printf("El cuadrado de %d es %d", eNum, eCuadrado);

	getchar ();
	return 0;
}



