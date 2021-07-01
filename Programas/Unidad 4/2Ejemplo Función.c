/* **********************************************************************
NOMBRE DEL PROGRAMA: EjemploFunci�n.c
OBJETIVO: Pedir dos n�meros y los suma.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 11/04/2019
********************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int suma(void); //Void=no recibe par�metro

/*int main (void){
	
	int eTotal;
	
	system("cls");
	printf("Suma valores\n\n");
	eTotal = suma();
	printf("\n%d", eTotal);

	getchar();
	return 0;
}

int suma(void){
	
	int eValor1, eValor2, eTotalDev;
	
	printf("Primer valor: ");
	scanf("%d", &eValor1);
	printf("Segundo valor: ");
	scanf("%d", &eValor2);
	eTotalDev = eValor1 + eValor2;
	
	return eTotalDev;
	
} */

//Programa anterior escrito m�s simplificado.
int main(void) {
	
	system("cls");
	printf("Suma valores\n");
	printf("\n%d", suma());

	getchar();
	return 0;
}

int suma(void) {
	int eValor1, eValor2;
	printf("Primer valor: ");
	scanf("%d", &eValor1);
	printf("Segundo valor: ");
	scanf("%d", &eValor2);
	
	return eValor1 + eValor2;
}
