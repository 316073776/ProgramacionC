/* **********************************************************************
NOMBRE DEL PROGRAMA: Paso de parámetro por valor.c
OBJETIVO: 
AUTOR: Segura Rios Brenda Stephanie
FECHA: 02/05/2019
********************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void suma(int x, int y, char *cad);

int main (void){
	
	int eValor1, eValor2;
	char cCadena[20];
	
	system("cls");
	
	printf("\nSuma de valores.\n");
	printf("\nPrimer valor: ");
	scanf("%d", &eValor1);
	printf("\nSegundo valor: ");
	scanf("%d", &eValor2);
	printf("\nCadena: ");
	fflush(stdin);
	gets(cCadena);
	suma(eValor1, eValor2, cCadena);
	
	getchar();
	return 0;
}


void suma(int x, int y, char *cCad){
	printf("\n\nTotal = %d", x + y);
	printf("\nLa cadena es: %s", cCad);
}

