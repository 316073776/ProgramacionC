/* **********
*  Programa: U2P1.c
*  Autor: 	 Isabel Ponce
*  Fecha: 	 Marzo de 2018
*  Objetivo: Realizar las cuatro operaciones aritméticas básicas con 2 variables
********** */
#include <stdio.h>

int main(){
     
     int eOperando1, eOperando2;
     
     system("cls");
     printf("Programa que calcula de las 4 operaciones aritm%cticas b%csicas\n\n", 130, 160);

     printf("Ingrese el primer operando: ");
     scanf("%d", &eOperando1);
     
     printf("Ingrese el segundo operando: ");
     scanf("%d", &eOperando2);
     
     printf("\n\n%d + %d = %d", eOperando1, eOperando2, eOperando1 + eOperando2);
     printf("\n%d - %d = %d", eOperando1, eOperando2, eOperando1 - eOperando2);
     printf("\n%d x %d = %d", eOperando1, eOperando2, eOperando1 * eOperando2);
     printf("\n%d / %d = %d", eOperando1, eOperando2, eOperando1 / eOperando2);

	 fflush(stdin);
     getchar();
     return 0;
}          
