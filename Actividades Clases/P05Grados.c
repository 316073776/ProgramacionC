/* **********************************************************************
NOMBRE DEL PROGRAMA: P05Grados.c
OBJETIVO: Convertir grados Celcius en Fharenheit
AUTOR: Segura Rios Brenda Stephanie
FECHA: 14/03/2019
********************************************************************** */
#include <stdio.h>

#define SUM 32
#define MUL 1.8

int main (){
	
	float fFah, fCel;
	
	printf("Programa que convierte grados Celcius en Fahrenheit.");
	printf("\n\nIngresa la teperatura en grados Celcius: ");
	scanf("%f", &fCel);
	
	fFah = fCel * MUL + SUM;
	
	printf("La temperatura de %5.2f grados Celcius es igual a %5.2f grados Fahrenheit.", fCel, fFah);

	getchar();
	return 0;
}

