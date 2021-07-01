/* **********************************************************************
NOMBRE DEL PROGRAMA: Paso de parámetro por referencia.c
OBJETIVO: Procedimiento, no reglesa valores.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 11/04/2019
********************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void suma(int eNum1, int eNum2, int *eResultado);

int main (void){
	
	int eValor1, eValor2, eTotal;
	
	system("cls");
	
	printf("\nSuma de valores.\n");
	printf("\nPrimer valor: ");
	scanf("%d", &eValor1);
	printf("\nSegundo valor: ");
	scanf("%d", &eValor2);
	
	suma(eValor1, eValor2, &eTotal);
	printf("\n%d + %d = %d", eValor1, eValor2, eTotal);

	getchar();
	return 0;
}

void suma(int eNum1, int eNum2, int *eResultado){
	
	*eResultado = eNum1 + eNum2;
	
}


