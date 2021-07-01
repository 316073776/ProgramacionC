/* **********
*  Programa: U2P4.c
*  Autor: Isabel Ponce
*  Fecha: Marzo de 2018
*  Objetivo: Leer dos variables y obtener su división entera
********** */
#include <stdio.h>

int main(){
     
     int eResultado;
     float fOperando1, fOperando2;
     
     system("cls");
     printf("Programa que obtiene la división entera de dos variables\n\n");

     printf("Ingrese el numerador: ");
     scanf("%f", &fOperando1);
     
     printf("Ingrese el denominador: ");
     scanf("%f", &fOperando2);
     
     eResultado = (int) fOperando1 / fOperando2;
     
     printf("\nDivisión entera de %5.2f / %5.2f = %d", fOperando1, fOperando2, eResultado);                   

	 fflush(stdin);
     getchar();
     return 0;     
}
