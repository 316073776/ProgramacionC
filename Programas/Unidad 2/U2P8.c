/* *********************************************************************************
PROGRAMA: 
AUTOR: Segura Rios Brenda Stephane
FECHA: 06/03/2019
OBJETIVO: Usar los operadores ++ y -=.
********************************************************************************** */

#include <stdio.h>

int main (){

int eVariable = 3;

	printf("\nPrograma que muestra el uso de los operadores ++ y -=.");
	
	printf("\n\nValor inicial = %d", eVariable);
	
	eVariable++;
	printf("\n\nDespu%cs de un autoincremento, el valor ahora es = %d", 130, eVariable);
	
	eVariable -= 3;
	printf("\n\nDespu%cs de decrementarle en 3, el valor ahora es = %d", 130, eVariable);
	
	
	getchar ();
	return 0;
}


