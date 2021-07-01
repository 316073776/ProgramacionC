/* **********************************************************************
NOMBRE DEL PROGRAMA: P06Múltiplo.c
OBJETIVO: Indicar si un número es múltiplo de otro.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 14/03/2019
********************************************************************** */
#include <stdio.h>

int main (){
	
	int eNum1, eNum2, eResiduo;
	
	printf("Programa que indica si un n%cmero es m%cltiplo de otro.", 163, 163);
	
	printf("\n\nIngrese el primer n%cmero: ", 163);
	scanf("%d", &eNum1);
	printf("\nIngrese el segundo n%cmero: ", 163);
	scanf("%d", &eNum2);
	
	eResiduo = eNum1 % eNum2;
	
	if (eResiduo == 0){
		printf("\n\n%d s%c es m%cltiplo de %d", eNum1, 161, 163, eNum2);
	}else{
		printf("\n\n%d no es m%cltiplo de %d", eNum1, 163, eNum2);
	}
	
	getchar();
	return 0;
}


