/* **********************************************************************
NOMBRE DEL PROGRAMA: P08PositivoNegativoCero.c
OBJETIVO: Identificar si un número es positivo, negativo o cero.
AUTOR: Segura Rios Brenda Stephanie
FECHA: //2019
********************************************************************** */
#include <stdio.h>

int eRes, eNum;
int main (){
	
	printf("Programa que identifica si un n%cmero es positivo, negativo o cero.", 163);
	printf("\n\nIngrese el n%cmero que dese utilizar: ", 163);
	scanf("%d", &eNum);
	
	if(eNum > 0){
		eRes = eNum / 4;
		printf("El resultado de %d entre 4 es: %d", eNum, eRes);
	}
	else if (eNum < 0){
		eRes = eNum * 3;
		printf("El resultado de %d por 3 es: %d", eNum, eRes);
	} else {
		eRes = eNum + 6;
		printf("El resultado de %d mas 6 es: %d", eNum, eRes);
	}
	
	getchar();
	return 0;
}


