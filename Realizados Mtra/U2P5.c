/* **********
*  Programa: U2P5.c
*  Autor: 	 Isabel Ponce
*  Fecha: 	 Marzo de 2018
*  Objetivo: Crear dos constantes (FALSO y VERDADERO) y mostrarlas
********** */
#include <stdio.h>

//constantes
#define FALSO 0
#define VERDADERO 1

int main(){
     
     system("cls");
     printf("Programa que muestra el valor de las constantes FALSO y VERDADERO\n");

     printf("\nFALSO = %d", FALSO);
     printf("\nVERDADERO = %d", VERDADERO);

	 fflush(stdin);
     getchar();
     return 0;     
}
