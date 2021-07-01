/* *********************************************************************************
PROGRAMA: P16CalculadoraV2.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 04/06/2019
OBJETIVO: Crear una calculadora con procedimientos.
********************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int Sumar(int, int, int);
int Restar(int, int, int);
int Multiplicar(int, int, int);
int Dividir(int, int, int);

int main (){
	
	float eResultado, eNum1, eNum2;

	printf("Programa que realiza las cuatro opereaciones aritm%cticas.", 130);
	printf("\n\nIngrese el primer n%cmero: ", 163);
	scanf("%d", &eNum1);
	printf("Ingrese el segundo n%cmero: ", 163);
	scanf("%d", &eNum2);
	
	printf("\n%d + %d = %d", eNum1, eNum2, Sumar(eNum1, eNum2, eResultado));
	printf("\n%d - %d = %d", eNum1, eNum2, Restar(eNum1, eNum2, eResultado));
	printf("\n%d * %d = %d", eNum1, eNum2, Multiplicar(eNum1, eNum2, eResultado));
	printf("\n%d / %d = %d", eNum1, eNum2, Dividir(eNum1, eNum2, eResultado));

	getchar ();
	return 0;
}


//Función Sumar
int Sumar(int eSumando1, int eSumando2, int eSuma){
	
	eSuma = eSumando1 + eSumando2;
	
}


//Función Restar
int Restar(int eValor1, int eValor2, int eResta){
	
	eResta = eValor1 - eValor2;
	
}


//Función Multiplicar
int Multiplicar(int eValor1, int eValor2, int eMultiplicacion){
	
	eMultiplicacion = eValor1 * eValor2;
	
}


//Función Dividir
int Dividir(int eDivisor, int eDividendo, int eDivision){
	
	if ( eDividendo == 0 ){
		
		printf("Error, el dividendo no puede ser igual a cero.");
		return 0;
	
	} else {
		
		eDivision = eDivisor / eDividendo;
		
	}
}
