/* **********************************************************************
NOMBRE DEL PROGRAMA: P02Suma.c
OBJETIVO: Mostrar la suma de dos números.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 07/03/2019
********************************************************************** */
#include<stdio.h>

int main (){
	
	int eSuma, eNum1, eNum2;
	
	printf("\nPrograma que suma dos n%cmeros enteros.", 163);
	printf("\n\nIngrese el primer n%cmero: ", 163);
	scanf("%d", &eNum1);
	
	printf("Ingrese el segundo n%cmero: ", 163);
	scanf("%d", &eNum2);
	
	eSuma = eNum1 + eNum2;
	
	printf("\nLa suma de %d + %d es igual a %d.", eNum1, eNum2, eSuma);
	
	getchar();
	return 0;
	
}

