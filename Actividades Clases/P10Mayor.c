/* **********************************************************************
NOMBRE DEL PROGRAMA: P10Mayor.c
OBJETIVO: Identificar el número mayor de tres valores ingresados.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 21/03/2019
********************************************************************** */
#include <stdio.h>

int main (){
	
	int eNum1, eNum2, eNum3;
	
	printf("Programa que indica el n%cmero mayor.", 163);
	printf("\n\nIntroduce el primer n%cmero: ", 163);
	scanf("%d", &eNum1);
	printf("Introduce el segundo n%cmero: ", 163);
	scanf("%d", &eNum2);
	printf("Introduce el tercer n%cmero: ", 163);
	scanf("%d", &eNum3);
	
	if (eNum1 > eNum2 && eNum1 > eNum3){
		printf("\n %d es mayor que %d y %d", eNum1, eNum2, eNum3);
	} else if (eNum1 == eNum2 && eNum1 == eNum3) {
		printf("\nTodos los n%cmeros son iguales.", 163);

	} else if (eNum1 == eNum2){
		if (eNum2 > eNum3){
			printf("\n%d y %d son iguales y mayores que %d", eNum1, eNum2, eNum3);
		} else {
			printf("\n%d y %d son iguales y menores que %d", eNum1, eNum2, eNum3);
		}

	} else if (eNum2 == eNum3){
		if (eNum3 > eNum1){
			printf("\n%d y %d son iguales y mayores que %d", eNum2, eNum3, eNum1);
		} else {
			printf("\n%d y %d son iguales y menores que %d", eNum2, eNum3, eNum1);
		}

	} else if (eNum1 == eNum3){
		if (eNum3 > eNum2){
			printf("\n%d y %d son iguales y mayores que %d", eNum1, eNum3, eNum2);
		} else {
			printf("\n%d y %d son iguales y menores que %d", eNum1, eNum3, eNum2);
		}

	} else if (eNum2 > eNum1 && eNum2 > eNum3){
		printf("\n%d es mayor que %d y %d", eNum2, eNum1, eNum3);
	} else {
		printf("\n%d es mayor que %d y %d", eNum3, eNum1, eNum2);
	}

	getchar();
	return 0;
}


