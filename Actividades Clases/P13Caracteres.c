/* *********************************************************************************
PROGRAMA: P13Caracteres.c
AUTOR: Segura Rios Brenda Stephane
FECHA: 27/03/2019
OBJETIVO: Contar cuantos caracteres o digitos ingresó el usuario.
********************************************************************************** */

#include <stdio.h>

int main (){
	
	int eDigitos = 0, eCaracteres = 0;
	char cCaracter;
	
	printf("Programa que cuenta cu%cntos caracteres y cu%cntos d%cgitos se ingresaron.", 160, 160, 161);
	
	do {
		
		printf("\n\nIngrese un caracter: ");
		fflush(stdin);
		
		cCaracter = getchar();
	
		if (cCaracter > 48 && cCaracter < 58){
		
			eDigitos ++;
		
		} else if (cCaracter > 64 && cCaracter < 91 || cCaracter > 96 && cCaracter < 123){
		
			eCaracteres ++;
		
		}	
		
	} while (cCaracter != 48);
		
	printf("\n\nD%cgitos ingresados: %d\nCaracteres ingresados: %d", 161, eDigitos, eCaracteres);
	
	getchar ();
	return 0;
}



