/* **********************************************************************
NOMBRE DEL PROGRAMA: P18Promedio.c
OBJETIVO: Obtener el promedio de cinco calificaciones.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 09/05/2019
********************************************************************** */
#include <stdio.h>
#include <stdlib.h>

#define MAX 5   //Constante

typedef float TaCalificaciones[MAX];    //Tipo

void LeerCalificaciones(TaCalificaciones);     //Prototipo
float CalcularPromedio(TaCalificaciones);
void MostrarCalificaciones(TaCalificaciones);

int main (){
	
	TaCalificaciones aCalificaciones;
	
	printf("Programa que calcula el promedio de 5 calificaciones.\n\n");
	LeerCalificaciones(aCalificaciones);
	MostrarCalificaciones(aCalificaciones);
	printf("\n\nEl promedio de las %d calificaciones es: %.2f", MAX, CalcularPromedio(aCalificaciones));

	getchar();
	return 0;
}


void LeerCalificaciones(TaCalificaciones aCalificaciones){
	
	int eIndice;
	
	for ( eIndice = 0; eIndice < MAX; eIndice ++ ){
		
		printf("Ingrese la calificaci%cn [%d]: ", 162, eIndice + 1);
		scanf("%f", &aCalificaciones[eIndice]);
		
	}
}


float CalcularPromedio(TaCalificaciones aCalificaciones){
	
	int eCalificacion;
	float fSuma = 0.0f;
	
	for ( eCalificacion = 0; eCalificacion < MAX; eCalificacion ++){
		
		fSuma += aCalificaciones[eCalificacion];
	
	}
	
	return fSuma / MAX;
	
}


void MostrarCalificaciones(TaCalificaciones aCalificaciones){
	
	int eIndice;
	
	printf("\n\nLas calificaciones son: ");
	
	for ( eIndice = 0; eIndice < MAX; eIndice ++ ){
		
		printf("\nCalificaci%cn [%d]: %.2f", 162, eIndice + 1, aCalificaciones[eIndice]);
		
	}
}
