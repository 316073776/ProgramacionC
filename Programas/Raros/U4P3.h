/* *********************************************************************************
PROGRAMA: U4P3.h
AUTOR: Segura Rios Brenda Stephane
FECHA: 09/05/2019
OBJETIVO: Crear una biblioteca con las funciones recursivas e incluirlas en otro archivo.
********************************************************************************** */

#include <stdio.h>

int Sumar (int, int);
int Restar (int, int);
int Multiplicar (int, int);
int Dividir (int, int);


//Recursivo
int Sumar (int eNum1, int eNum2){
	
	if(eNum2 == 0){
		
		return eNum1;
		
	} else {
		
		return Sumar(eNum1, eNum2 - 1) + 1;
	
	}
}

int Restar (int eNum1, int eNum2){

	if(eNum2 == 0){
		
		return eNum1;
		
	} else {
		
		return Restar(eNum1, eNum2 - 1) - 1;
	}
}

int Multiplicar (int eNum1, int eNum2){

	if(eNum2 == 1){
		
		return eNum1;
		
	} else if(eNum2 == 0 || eNum1 == 0){
		
		return 0;
	
	} else {
			
		return Multiplicar(eNum1, eNum2 - 1) + eNum1;
			
	}
}


int Dividir (int eNum1, int eNum2){
	
	if (eNum2 == 0){
		
		return 0;
		
	} else if (eNum2 == 1){
		
		return eNum1;
		
	} else if (eNum1 == eNum2){
		
		return 1;
		
	} else if (eNum2 < eNum1){
		
		return Dividir(eNum1 - eNum2, eNum2) + 1;
	
	} else {
		
		return 0;
		
	}




