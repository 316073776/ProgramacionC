/* *********************************************************************************
PROGRAMA: P11Par.c
AUTOR: Segura Rios Brenda Stephane
FECHA: 27/03/2019
OBJETIVO: Mostrar si un número es par o impar.
********************************************************************************** */

#include <stdio.h>

int main (){
	
	int eNum, eResiduo;
	
	printf("Programa que determina si un n%cmero es par.", 163);
	
	printf("\n\nIngrese un n%cmero: ", 163);
	scanf("%d", &eNum);
	
	eResiduo = eNum % 2;
	
	if (eResiduo == 0){
		printf("\n %d es un n%cmero par.", eNum, 163);
	} else {
		printf("\n %d es un n%cmero impar.", eNum, 163);
	}

	getchar ();
	return 0;
}



