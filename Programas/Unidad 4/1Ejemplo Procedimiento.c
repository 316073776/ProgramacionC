/* **********************************************************************
NOMBRE DEL PROGRAMA: EjemploProcedimiento.c
OBJETIVO: 
AUTOR: Segura Rios Brenda Stephanie
FECHA: 11/04/2019
********************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void mostrar(void);

int main (void){
	
	system("cls");
	printf("\nEstoy en la principal\n");
	mostrar();
	printf("\nDe vuelta en la principal.");

	getchar();
	return 0;
}

void mostrar(void){
	printf("\nAhora estoy en la funci%cn\n", 162);
	system("pause");
}



