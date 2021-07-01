/* **********************************************************************
NOMBRE DEL PROGRAMA: P01Saludo.c
OBJETIVO: Programa que saluda
AUTOR: Segura Rios Brenda Stephanie
FECHA: 14/03/2019
********************************************************************** */
#include <stdio.h>

int main (){
	char cNombre[30];
	
	printf("\nPrograma que te saluda.");
	printf("\nIngresa tu nombre: ");
	scanf("%s", &cNombre);
	
	printf("Hola %s", cNombre);

	getchar();
	return 0;
}

