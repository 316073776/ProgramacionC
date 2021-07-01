/* *********************************************************************************
PROGRAMA: U3P3.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 04/04/2019
OBJETIVO: Obtener el promedio de 5 calificaciones solicitadas al usuario.
********************************************************************************** */

#include <stdio.h>

int main (){
	
	float fPromedio, fCalificacion, fSumaCal = 0;
	int eContadorCal;
	
	printf("Programa que calcula el promedio de cinco calificaciones.\n\n");
	
	for (eContadorCal = 1 ; eContadorCal <= 5 ; eContadorCal ++){
	
		printf("Ingrese la calificaci%cn n%cmero %d: ", 162, 163, eContadorCal);
		scanf("%f", &fCalificacion);
		
		fSumaCal += fCalificacion;
	
	}
	
	printf("\n\nEl promedio de las cinco calificaciones es: %.2f", fSumaCal / 5 );

	getchar ();
	return 0;
}


