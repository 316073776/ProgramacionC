/* **********
*  Programa: U2P2.c
*  Autor:  	Isabel Ponce
*  Fecha: 	 Marzo de 2018
*  Objetivo: Mostrar si la suma de 2 variables es menor, mayor o igual a 0
			 usando el operador ternario
********** */
#include <stdio.h>

int main(){
     
     int eOperando1, eOperando2;
     
     system("cls");
     printf("Programa que muestra si la suma de dos variables es mayor, menor o igual a 0\n\n");

     printf("Ingrese el primer operando: ");
     scanf("%d", &eOperando1);
     
     printf("Ingrese el segundo operando: ");
     scanf("%d", &eOperando2);
     
     printf("\n\nLa suma de %d + %d es %s a cero", eOperando1, eOperando2,
        eOperando1 + eOperando2 > 0 ? "Mayor" : 
        eOperando1 + eOperando2 < 0 ? "Menor" : "Igual");

	 fflush(stdin);
     getchar();
     return 0;     
}          
