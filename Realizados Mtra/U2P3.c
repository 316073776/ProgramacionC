/* **********
*  Programa: U2P3.c
*  Autor: 	 Isabel Ponce
*  Fecha:  	 Marzo de 2018
*  Objetivo: Calcular y mostrar el resultado de 35 + 12 / 3 * 37 – 18 / 6
********** */
#include <stdio.h>

int main(){
     
     int eResultado;
     
     system("cls");
     printf("Programa que muestra el resultado de 35 + 12 / 3 * 37 – 18 / 6\n\n");

     eResultado = 35 + 12 / 3 * 37 - 18 / 6;
     
     printf("35 + 12 / 3 * 37 - 18 / 6 = %d", eResultado);                   

	 fflush(stdin);
     getchar();
     return 0;     
}
