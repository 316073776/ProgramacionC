/* *********************************************************************************
PROGRAMA: P12Promedio.c
AUTOR: Segura Rios Brenda Stephane
FECHA: 27/03/2019
OBJETIVO: Sacar el promedio de cinco calificaciones.
********************************************************************************** */

#include <stdio.h>

int main (){
	
	float fPromedio, fCalificacion, fSumaCal = 0;
	int eContadorCal;
	
	printf("Algoritmo que calcula el promedio de cinco calificaciones.");
	
	for (eContadorCal = 1 ; eContadorCal <= 5 ; eContadorCal ++){
	
		printf("\nIngrese la calificaci%cn n%cmero %d: ", 161, 163, eContadorCal);
		scanf("%f", &fCalificacion);
		
		fSumaCal = fSumaCal + fCalificacion;
	
	}
	
	fPromedio = fSumaCal / 5;
	printf("\n\nEl promedio de las cinco calificaciones es: %.2f", fPromedio);

	getchar ();
	return 0;
}



