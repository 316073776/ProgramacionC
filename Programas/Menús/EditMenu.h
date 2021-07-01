/* **********************************************************************
NOMBRE DEL PROGRAMA: Menú.h
OBJETIVO: Tener todas las funciones de un menú.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 11/04/2019
********************************************************************** */

//BIBLIOTECAS
#include <stdio.h>			
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//PROTOTIPOS
void cambiarColor();
void dibujarMarco();
void moverCursor (int, int);
void linea(int);
void centrarTexto(char * cTexto, int eRenglon); 
void mensajeUltLin(char cTexto[90]);
void pausa();

//FUNCIONES

//Función para cambiar color de la consola y texto.************************
void cambiarColor(){	
/*color de consola : 		
0 = Negro					A = Verde claro 
1 = Azul					B = Aguamarina claro
2 = Verde					C = Rojo claro 
3 = Aguamarina 				D = Purpura claro 
4 = Rojo					E = Amarillo claro 
5 = Purpura					F = Blanco brillante
6 = Amarillo 
7 = Blanco 
8 = Gris 
9 = Azul claro */

	system("color DF");
	system("cls");
	
} 


//Función para dibujar marco.********************************************
void dibujarMarco(){
	
	int eRenglon, eColumna;

	cambiarColor();								//Función para cambiar color
	system ("cls");								//Limpia la pantalla 

	
	//Línea superior
	printf("%c", 201); //Esq.Sup.Izq.
	
	for ( eColumna = 1; eColumna < 118; eColumna ++ ){
		printf("%c", 205);	
	}

	//Lados		
	printf("%c\n", 187); //Esq.Sup.Der.
	for (eRenglon = 2; eRenglon < 29; eRenglon ++ ){
		printf("%c                                                         "
			    "                                                            %c\n", 186, 186);
	}	
	
	//Línea inferior
	printf("%c", 200); //Esq.Inf.Izq
	
	for ( eColumna = 1; eColumna < 118; eColumna ++ ){
		printf("%c", 205);	
	}
	
	printf("%c", 188); //Esq.Inf.Izq
	
	//Línea bajo el título
	moverCursor(4,1);
	for ( eColumna = 1; eColumna < 118; eColumna ++ ){
		printf("%c", 205);
	}

}


//Función para mover el cursor.**************************************************
void moverCursor(int eRenglon, int eColumna){
	
	HANDLE salida; //manejador de recursos de windows
	COORD coord; //objeto coordenada
	
	salida = GetStdHandle(STD_OUTPUT_HANDLE);	//obtiene manejador de salida estándar
	
	coord.Y = eRenglon; //pone coordenada Y
	coord.X = eColumna; //pone coordenada X
	
	SetConsoleCursorPosition(salida, coord);	//mueve el cursor	ConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //mueve el cursor
}


//Linea: muestra una línea en el renglón indicado.*******************************
void linea(int eRen){
	
	int eCol;
		
	for (eCol = 1; eCol < 118; eCol++) {

		moverCursor(eRen, eCol);		//línea 
		printf("%c", 196);
	}
}


//Centrar texto *******************************************************************
void centrarTexto(char *cTexto, int eRenglon){				
	
	moverCursor(eRenglon, ( 59 - strlen(cTexto) / 2 ) );
	printf ("%s", cTexto);
	
}


//Mensaje en última línea.*********************************************************
void mensajeUltLin(char cTexto[90]){
	
	moverCursor (28, 1);
	centrarTexto(cTexto, 28);

}


//muestra una flecha y detiene el programa
void pausa(){

	printf("<%c%c%c", 196, 196, 217);
	fflush(stdin);
	getchar();

}



