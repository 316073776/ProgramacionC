/* *********************************************************************************
PROGRAMA: Math.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 15/05/2019
OBJETIVO: Ver ejemplo de funciones de la biblioteca math.
********************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Elevar a un exponente
/*int main(){

	float fBase, fExponente;
		
	printf("Programa que muestra algunas funciones internas de C\n");
	
	printf("Ingrese la base: ");
	scanf("%f", &fBase);
	printf("Ingrese el exponente: ");
	scanf("%f", &fExponente);
		
	printf("%.2f elevado a %.2f es %.2f", fBase, fExponente, pow(fBase, fExponente));

	
	
	getchar();
	return 0;
}*/


int main(){

	int eNumero;
	char cCadena [50];
	
	//Multiplica una cadena.	
/*	printf("Ingrese un n%cmero: ", 163);
	gets(cCadena);
	
	eNumero = atoi(cCadena);
	
	printf("%d x 2 = %d ", eNumero, eNumero*2);*/
	
	
	
/*	printf("\nIngrese el n%cmero a convertir: ", 163);
	scanf("%d", &eNumero);
	
	itoa(eNumero, cCadena, 16);
	printf("\nEl n%cmero en binario es: %s", 163, eNumero, cCadena);*/
	
	printf("\nIngrese el n%cmero a convertir: ", 163);
	eNumero = rand()%10 + 1;

	printf("El n%cmero aleatorio es %d", 163, eNumero);
	
	getchar();
	return 0;
}
