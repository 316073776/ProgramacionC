/* **********************************************************************
NOMBRE DEL PROGRAMA: P07División.c
OBJETIVO: Dividir dos números flotantes y verificar que el denominador sea diferente de cero.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 14/03/2019
********************************************************************** */
#include <stdio.h>

int main (){
	
	float fNumerador, fDenominador, fDivision;
	
	printf("Programa que divide dos n%cmeros flotantes.", 163);
	
	printf("\n\nIngrese el n%cmerador: ", 163);
	scanf("%f", &fNumerador);

	printf("Ingrese de denominador: ");
	scanf("%f", &fDenominador);
	
	if(fDenominador == 0){
		printf("\n\nNo se puede realizar una divisi%cn entre cero.", 162);
	}else{
		fDivision = fNumerador / fDenominador;
		printf("\n\nEl resultado de %5.2f entre %5.2f es: %5.2f", fNumerador, fDenominador, fDivision);
	}

	getchar();
	return 0;
}


