/* *********************************************************************************
PROGRAMA: Factorial.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 12/05/2019
OBJETIVO: Sacar el factorial de un número.
********************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int factorial(int eNumero);

int main(){
	
	int eNumero;
	
	
	printf("Ingrese el n%cmero del que va a obtener el factorial: ", 163 );
	scanf("%d", &eNumero);
	
	printf("Factorial de %d es igual a %d", eNumero, factorial(eNumero));
	
	getchar();
	return 0;
}

int factorial(int eNumero){
	
	int eRes;
	
	if (eNumero == 1){
		
		return 1;
		
} else {
	
	eRes = factorial(eNumero -1)*eNumero;
	
	return eRes;
	}
}

