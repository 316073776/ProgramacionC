/* **********************************************************************
NOMBRE DEL PROGRAMA: U4P1.c
OBJETIVO: Realizar las 4 operaciones aritméticas básicas con funciones.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 02/05/2019
********************************************************************** */
#include <stdio.h>
#include "U4P1.h"		//Se agraga biblioteca que contiene las funciones comentadas.

/*int Sumar (int, int);
int Restar (int, int);
int Multiplicar (int, int);
int Dividir (int, int);*/

//Función principal
int main (){
	
	int eNum1, eNum2, eOpcion;
	
	printf("Programa que realiza las 4 operaciones aritm%cticas b%csicas.\n\n", 130, 160);
	
	do{

		
		printf("\n\n1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n5. Salir");
		printf("\n\nElige una opci%cn: ", 162);
		scanf("%d", &eOpcion);
		
		if (eOpcion >= 1 && eOpcion <= 4){
			
			printf("\nIngrese el primer n%cmero: ", 163);
			scanf("%d", &eNum1);
			printf("Ingrese el segundo n%cmero: ", 163);
			scanf("%d", &eNum2);
			
		}
		
		switch (eOpcion){
			
			case 1: printf("\n%d + %d = %d", eNum1, eNum2, Sumar(eNum1, eNum2));
					break;
			case 2: printf("\n%d - %d = %d", eNum1, eNum2, Restar(eNum1, eNum2));
					break;
			case 3: printf("\n%d x %d = %d", eNum1, eNum2, Multiplicar(eNum1, eNum2));
					break;
			case 4: printf("\n%d / %d = %d", eNum1, eNum2, Dividir(eNum1, eNum2));
					break;
			case 5: printf("\n\nHasta luego!");
					break;
			default: printf("\nOpci%cn inv%clida.\n\n", 162, 160);		
			
		}
		
	} while (eOpcion != 5);

	getchar();
	return 0;
}

//Funciones
/*int Sumar (int eNum1, int eNum2){
	return eNum1 + eNum2;
}

int Restar (int eNum1, int eNum2){
	return eNum1 - eNum2;
}

int Multiplicar (int eNum1, int eNum2){
	return eNum1 * eNum2;
}

int Dividir (int eNum1, int eNum2){
	if (eNum2 == 0){
		return 0;
	} else {
	return eNum1 / eNum2;
	}
}*/                   //Biblioteca U4P1.h
