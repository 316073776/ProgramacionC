/* *********************************************************************************
PROGRAMA: U2P7 A
AUTOR: Segura Rios Brenda Stephane
FECHA: //2019
OBJETIVO: Probar el manejo del modificador extern.
********************************************************************************** */

#include "U2P7B.c"

int eNum1 = 50, eNum2 = 30;
int main(){
	
	printf("\nPrograma que muestra el manejo del modificador %cextern%c.", 34, 34);
	printf("\n\nLos n%cmeros iniciales son:", 163);
	printf("\nN%cmero 1 = %d y N%cmero 2 = %d", 163, eNum1, 163, eNum2);
	
	printf("\n\nEl n%cmero 1 es igual a %d", 163, eNum1);
	printf("\n\tResultado sin el modificador %cextern%c.", 34, 34);
	
	func33();
	printf("\n\nEl n%cmero 1 es igual a %d", 163, eNum1);
	printf("\n\tResultado con el modificador %cextern%c.", 34, 34);
	
	getchar ();
	return 0;
}



