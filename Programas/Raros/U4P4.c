/* **********************************************************************
NOMBRE DEL PROGRAMA: U4P4.c
OBJETIVO: Mostrar el uso de macros en C.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 09/05/2019
********************************************************************** */
#include <stdio.h>
#define sumar(eNumero1, eNumero2) eNumero1 + eNumero2   //Macros
#define restar(eNumero1, eNumero2) eNumero1 - eNumero2
#define multiplicar(eNumero1, eNumero2) eNumero1 * eNumero2
#define dividir(eNumero1, eNumero2) eNumero1 / eNumero2
#define entero int                                     //Macros para sustituir programa en español.
#define escribir printf

entero main (){
	
	entero eNumero1, eNumero2;
	
	escribir("Programa que obtiene la suma de un n%cmero.\n", 163);
	
	escribir("\nIngrese el primer n%cmero: ", 163);
	scanf("%d", &eNumero1);
	escribir("Ingrese el segundo n%cmero: ", 163);
	scanf("%d", &eNumero2);
	
	escribir("\n\n%d + %d = %d", eNumero1, eNumero2, sumar(eNumero1, eNumero2));
	escribir("\n%d - %d = %d", eNumero1, eNumero2, restar(eNumero1, eNumero2));
	escribir("\n%d * %d = %d", eNumero1, eNumero2, multiplicar(eNumero1, eNumero2));
	escribir("\n%d / %d = %d", eNumero1, eNumero2, eNumero2 == 0 ? 0 : dividir(eNumero1, eNumero2));   //Ternario para verivicar el numerador.
	
	getchar();
	return 0;
}


