/*PROGRAMA: U2P1.c
AUTOR: Segura Rios Brenda Stephanie
OBJETIVO: Realizar 4 operaciones aritméticas con dos variables.
FECHA: 28-02-2019
*/

#include <stdio.h>

int main(){
	
	int eNum1, eNum2;
	
	printf("\nPrograma que solicita dos variables y realiza cuatro operaciones aritm%cticas.", 130);
	
	printf("\nIngrese el primer n%cmero:", 163);
	scanf("%d", &eNum1);
	
	printf("\nIngrese el segundo n%cmero:", 163);
	scanf("%d", &eNum2);
	
	printf("\n%d + %d = %d", eNum1, eNum2, eNum1 + eNum2);
	printf("\n%d - %d = %d", eNum1, eNum2, eNum1 - eNum2);
	printf("\n%d x %d = %d", eNum1, eNum2, eNum1 * eNum2);
	printf("\n%d / %d = %5.2f", eNum1, eNum2, eNum1 / eNum2);
	
	getchar ();
	return 0;
		
}

