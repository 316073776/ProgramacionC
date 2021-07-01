/* **********************************************************************
NOMBRE DEL PROGRAMA: U4P1.h
OBJETIVO: Crear una biblioteca.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 02/05/2019
********************************************************************** */

int Sumar (int, int);
int Restar (int, int);
int Multiplicar (int, int);
int Dividir (int, int);

//Funciones
int Sumar (int eNum1, int eNum2){
	return eNum1 + eNum2;
}


int Restar (int eNum1, int eNum2){
	return eNum1 - eNum2;
}


int Multiplicar (int eNum1, int eNum2){
	return eNum1 * eNum2;
}


int Dividir (int eNum1, int eNum2){
	if (eNum2 == 0){
		return 0;
	} else {
	return eNum1 / eNum2;
	}
}
