/* **********************************************************************
NOMBRE DEL PROGRAMA: Ejemplo Areglo.c
OBJETIVO: 
AUTOR: Segura Rios Brenda Stephanie
FECHA: 09/05/2019
********************************************************************** */
#include <stdio.h>

int main (void){    //void = No recibe parámetros.
	
	int aEnteros[100];
	int eCont;
	
	for ( eCont = 0; eCont < 100; eCont ++ ){
		
		aEnteros[eCont] = eCont;
		
	}
	
	printf("%d", aEnteros[4]);

	getchar();
	return 0;
}


