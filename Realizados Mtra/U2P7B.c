/* **********
*  Programa: U2P7B.c
*  Autor: 	 Isabel Ponce
*  Fecha: 	 Marzo de 2018
*  Objetivo: Mostrar el uso del modificador extern
********** */
#include <stdio.h>

void modifica(){
     
     int eMaximo;
	 //accede a la varaible fPi declarada en el otro programa
	 //gracias al modificador extern
     extern float fPi;

     eMaximo = 32;
     fPi = 54.2;	//por tanto, puede modificarla
}
