/* *********************************************************************************
PROGRAMA: U2P4
AUTOR: Segura Rios Brenda Stephane
FECHA: 06/03/2019
OBJETIVO: Obtener dos variables, obtener su división y asignar su resultado 
			a una variable flotante.
********************************************************************************** */

#include <stdio.h>

int main (){
int eNum1, eNum2;
float fResultado;

	printf("\nPrograma que realiza la divisi%cn de dos variables enteras.\n", 162);
	
	printf("\nIngrese el numerador:");
	scanf("%d", &eNum1);
	printf("\nIngrese el denominador:");
	scanf("%d", &eNum2);
	
	fResultado = (float) eNum1 / eNum2;
	printf("\nEl resultado de la divisi%cn de %d %c %d es: %5.3f", 162, eNum1, 246, eNum2, fResultado);
	
	getchar ();
	return 0;
}

