/* **********************************************************************
NOMBRE DEL PROGRAMA: P03Circulo.c
OBJETIVO: Determinar el área y el perímetro de un círculo a partir de su radio.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 07/03/2019
********************************************************************** */
#include <stdio.h>

#define PI 3.1416

int main (){
	
	float fRadio, fArea, fPerimetro;
	
	printf("Programa que calcula el per%cmetro y el %crea de un c%crculo a partir de su radio.", 161, 160,161);
	printf("\nIngrese el radio: ");
	scanf("%f", &fRadio);
	
	fArea = PI * (fRadio * fRadio);
	fPerimetro = (2 * PI) * fRadio;
	
	printf("\nEl c%crculo de radio %.2f, tiene un %crea de: %.2f y un per%cmetro de: %.2f.", 161, fRadio, 160, fArea, 161, fPerimetro);
	
	fflush (stdin);
	getchar();
	return 0;
}

