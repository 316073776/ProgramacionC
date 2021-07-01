/* *********************************************************************************
PROGRAMA: HacerFuncionarMenú.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 12/05/2019
OBJETIVO: Ver cómo funciona la blioteca de menú.h.
********************************************************************************** */
#include <stdio.h>
#include "EditMenu.h"

void cambiarColor();
void dibujarMarco();
void moverCursor (int, int);
void linea(int);
void centrarTexto(char * cTexto, int eRenglon); 
void mensajeUltLin(char cTexto[90]);
void pausa();

int main (){
	
	int eRenglon, eOpcion;
	char cTexto[] = {"Hola como estas."};
	char cUltimaLinea[90] = {"ERROR"};
	
	dibujarMarco(); //Agrega marco en la ventana
	linea(10);
	
	moverCursor(15, 40); //Muestra línea en una posición	
	printf("Men%c", 163);
	moverCursor(17, 50);
	printf("\n1.- Empleados"
			"\n2.-Calcular n%cmina"
			"\n3.-Generar recibos de n%cmina"
			"\n4.- Salir"
			"\nIngrese la opci%cn que desea:", 162, 162, 162);		
	centrarTexto(cTexto, 2);
	mensajeUltLin(cUltimaLinea);
	moverCursor(15,30); //luego lee
	scanf("%d", &eOpcion);
	
	pausa();
	getchar();
	return 0;
	
}



