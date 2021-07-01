/* **********************************************************************
NOMBRE DEL PROGRAMA: P15Fibonacci.c
OBJETIVO: Mostrar los primeros 20 números de la serie de Fibonacci.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 04/04/2019
********************************************************************** */
#include <stdio.h>

int main (){
	
	int eContador = 0, eFibonacci, eUltimo = 1, ePenultimo;
	
	printf("Este programa muestra los primeros 20 n%cmeros de la serie de Fibonacci.", 163);
	printf("\n\n[%d] [%d]", eContador, eUltimo);
	
	for ( eContador = 3; eContador <= 20; eContador ++ ){
		
		eFibonacci = ePenultimo + eUltimo;
		ePenultimo = eUltimo;
		eUltimo = eFibonacci;
		
		printf(" [%d]", eFibonacci);
		
	}

	getchar();
	return 0;
}


