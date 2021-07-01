/* *********************************************************************************
PROGRAMA: U2P1
AUTOR: Segura Rios Brenda Stephane
FECHA: 06/03/2019
OBJETIVO: Mostrar si el resultado de una suma es menor, mayor o igual a cero.
********************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main (){
	int eNum1, eNum2;
	
	printf("\nPrograma que muestra si el resultado de la suma de dos variables es menor, mayor o igual a cero.\n");
	
	printf("\nIngrese el primer n%cmero:", 163);
	scanf("%d", &eNum1);
	printf("\nIngrese el segundo n%cmero:", 163);
	scanf("%d", &eNum2);
	
	printf("\nLa suma de %d + %d es %s a cero", eNum1, eNum2,
        eNum1 + eNum2 < 0 ?"Menor" :eNum1 + eNum2 > 0 ?"Mayor" :"Igual");
	
	getchar();
	return 0;
}

