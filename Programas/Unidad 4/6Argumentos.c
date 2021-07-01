/* *********************************************************************************
PROGRAMA: Argumentos.c
AUTOR: Segura Rios Brenda Stephane
FECHA: 11/04/2019
OBJETIVO: Ver el uso de argv y argc
********************************************************************************** */

#include <stdio.h>

int main (int argc, char *argv[]){
	
	int eCont = 1;
	
	printf("\nTotal de par%cmetros: %d", 160, argc);
	printf("\nNombre del programa: %s", argv[0]);
	
	while ( eCont < argc ){
		
		printf("\nargv[%d] = %s", eCont, argv[eCont]);
		
		eCont ++;
		
	}

	getchar ();
	return 0;
}



