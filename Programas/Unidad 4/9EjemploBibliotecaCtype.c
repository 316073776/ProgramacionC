/* *********************************************************************************
PROGRAMA: Ctype.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 12/05/2019
OBJETIVO: Ver las funciones de la biblioteca ctype.
********************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//Comprueba si un caracter es alfabético y lo convierte en mayúscula y minúscula.
/*int main(){

	char cCaracter;
	
	printf("Programa que muestra algunas funciones internas de C\n");
	
	printf("Ingrese un caracter: ");
	cCaracter = getchar();
	
	if (isalpha(cCaracter) == 0){
		
		printf("El caracter %c no es alfab%ctico", cCaracter, 130);
		
	} else {
		
		printf("El caracter %c si es alfab%ctico", cCaracter, 130);
		printf("\nEl caracter %c en min%csculas es: %c", cCaracter, 163, tolower(cCaracter));
		printf("\nEl caracter %c en may%csculas es: %c", cCaracter, 163, toupper(cCaracter));
	}

	getchar();
	return 0;
}*/

int main(){

	char cCaracter;
	
	printf("Programa que muestra algunas funciones internas de C\n");
	
	printf("Ingrese un d%cgito: ", 161);
	cCaracter = getchar();
	
	if (isdigit(cCaracter) == 0){
		
		printf("El caracter %c no es un d%cgito", cCaracter, 161);
		
	} else {
		
		printf("El caracter %c si es un d%cgito", cCaracter, 161);
		
	}

	getchar();
	return 0;
}



