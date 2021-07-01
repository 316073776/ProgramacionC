/* **********
*  Programa: U2P7A.c
*  Autor:    Isabel Ponce
*  Fecha: 	 Marzo de 2018
*  Objetivo: Mostrar el uso del modificador extern
********** */
#include "U2P7B.C"	//incluye otro archivo

int eMaximo = 5;
float fPi = 3.1416;

void main(){
     
     system("cls");
     printf("Programa que muestra el uso del modificador extern.\n");

     printf("\nMaximo = %d \nPI = %5.4f ", eMaximo, fPi);
     
     modifica();
     
     printf("\nMaximo = %d \nPI = %5.4f", eMaximo, fPi);
     printf("\n\nNo cambia eMaximo porque no tiene modificardor extern");
     printf("\nSi cambia Pi porque tiene modificador extern");
	 printf("\nse puede acceder y modificar desde otro programa");

	 fflush(stdin);
     getchar();
     return 0;
}
