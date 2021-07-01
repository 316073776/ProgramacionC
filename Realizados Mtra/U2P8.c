/* **********
*  Programa: U2P8.c
*  Autor: 	 Isabel Ponce
*  Fecha: 	 Marzo de 2018
*  Objetivo: Mostrar el uso de los operadores ++ y -=
********** */
#include <stdio.h>

int main(){
     
     int eEntero = 3;
     
     system("cls");
     printf("Programa que muestra el uso de los operadores ++ y -=\n");

     printf("\nEntero = %d", eEntero);
     
     eEntero++;
     printf("\nDespu%cs de autoincremento. Entero = %d", 130, eEntero);
     
     eEntero -= 3;
     printf("\nDespu%cs de decremento de 3. Entero = %d", 130, eEntero);

	 fflush(stdin);
     getchar();
     return 0;
}
