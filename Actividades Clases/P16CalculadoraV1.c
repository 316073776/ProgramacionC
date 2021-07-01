/* *********************************************************************************
PROGRAMA: P16CalculadoraV1.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 04/06/2019
OBJETIVO: Crear una calculadora con funciones.
********************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

float Sumar(float, float);
float Restar(float, float);
float Multiplicar(float, float);
float Dividir(float, float);

int main (){
	
	float fNum1, fNum2;

	printf("Programa que realiza las cuatro opereaciones aritm%cticas.", 130);
	printf("\n\nIngrese el primer n%cmero: ", 163);
	scanf("%f", &fNum1);
	printf("Ingrese el segundo n%cmero: ", 163);
	scanf("%f", &fNum2);
	
	printf("\n%.2f + %.2f = %.2f", fNum1, fNum2, Sumar(fNum1, fNum2));
	printf("\n%.2f - %.2f = %.2f", fNum1, fNum2, Restar(fNum1, fNum2));
	printf("\n%.2f * %.2f = %.2f", fNum1, fNum2, Multiplicar(fNum1, fNum2));
	printf("\n%.2f / %.2f = %.2f", fNum1, fNum2, Dividir(fNum1, fNum2));

	getchar ();
	return 0;
}


//Función Sumar
float Sumar(float fSumando1, float fSumando2){
	
	return fSumando1 + fSumando2;
	
}


//Función Restar
float Restar(float fValor1, float fValor2){
	
	return fValor1 - fValor2;
	
}


//Función Multiplicar
float Multiplicar(float fValor1, float fValor2){
	
	return fValor1 * fValor2;
	
}


//Función Dividir
float Dividir(float fDivisor, float fDividendo){
	
	if ( fDividendo == 0 ){
		
		printf("Error, el dividendo no puede ser igual a cero.");
		return 0;
	
	} else {
		
		return fDivisor / fDividendo;
		
	}
}
