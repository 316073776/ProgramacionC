/* **********
*  Programa: U2P6.c
*  Autor: 	 Isabel Ponce
*  Fecha: 	 Marzo de 2018
*  Objetivo: Generar el siguiente n�mero de la serie que inicia en 350
********** */
#include <stdio.h>

//prototipo
int siguiente();

void main(){
     
     system("cls");
     printf("Programa que muestra el siguiente n�mero de la serie que inicia en 350\n");

     printf("\n%d", siguiente());
     printf("\n%d", siguiente());
     printf("\n%d", siguiente());
     printf("\n%d", siguiente());

     getche();
}

//definci�n de funci�n siguiente
int siguiente(){
     
     static int serie = 349;	//notar uso modificador static
     
     serie++;
     
     return serie;
}
