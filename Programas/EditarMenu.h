/* **********************************************************************
	PROGRAMA: EditarMenu.h
	AUTOR(ES): 
				Fernández Ortiz Valeria Lizette
				Francisco Arellano Herdson Josue
				López Alejaldre Daniela Viridiana
				Segura Ríos Brenda Stephanie
				Varas Dayren Sarahi
	EQUIPO: SkyNet
	OBJETIVO: Tener todas las funciones para editar la interfáz de un menú.
	FECHA DE CREACIÓN: 10 de junio del 2019.
	FECHA DE ULTIMA ACTUALIZACIÓN:
********************************************************************** */

//BIBLIOTECAS
#include <stdio.h>			
#include <stdlib.h>
#include <windows.h>
#include <string.h>


//PROTOTIPOS
void cambiarColor(); //Procedimiento cambiar color de consola.
void moverCursor (int, int); //Función PAra mover el cursor a donde se desee.
void dibujarMarco(); //Procedimiento para dibujar un marco en la consola.
void linea(int); //Procedimiento para dibujar una línea en el renglón deseado.


/* **********************************************************************
	FUNCIÓN: cambiarColor
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACIÓN: 10 / 06 / 2019
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Cambiar el color de la consola.
	DE(PE): 
	DS(PS): 
********************************************************************** */
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

	system("color 30");
	system("cls");
	
} 


/* **********************************************************************
	FUNCIÓN: moverCursor
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACIÓN: 10 / 06 / 2019
	FECHA DE ÚLTIMA ACTUALIZACIÓN:
	OBJETIVO: Mover el cursor a las coordenadas ingresadas.
	DE(PE): 
	DS(PS): 
********************************************************************** */
void moverCursor(int eRenglon, int eColumna){
	
	HANDLE salida; //manejador de recursos de windows
	COORD coord; //objeto coordenada
	
	salida = GetStdHandle(STD_OUTPUT_HANDLE);	//obtiene manejador de salida estándar
	
	coord.Y = eRenglon; //pone coordenada Y
	coord.X = eColumna; //pone coordenada X
	
	SetConsoleCursorPosition(salida, coord);	//mueve el cursor	ConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //mueve el cursor
}


/* **********************************************************************
	FUNCIÓN: dibujarMrco
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACIÓN: 10 / 06 / 2019
	FECHA DE ÚLTIMA ACTUALIZACIÓN:
	OBJETIVO: Dibujar un marco en la consola.
	DE(PE): 
	DS(PS): 
********************************************************************** */
void dibujarMarco(){
	
	cambiarColor();
	
	int eRenglon, eColumna;
	
	
	
	system ("cls");								//Limpia la pantalla 

	
	//Línea superior
	printf("%c", 201); //Esquina Superior Izquierda
	
	for ( eColumna = 1; eColumna < 118; eColumna ++ ){
		printf("%c", 205);	
	}

	//Lados		
	printf("%c\n", 187); //Esquina Superior Derecha
	for (eRenglon = 2; eRenglon < 29; eRenglon ++ ){
		printf("%c                                                         "
			    "                                                            %c\n", 186, 186);
	}	
	
	//Línea inferior
	printf("%c", 200); //Esquina Inferior Izquierda
	
	for ( eColumna = 1; eColumna < 118; eColumna ++ ){
		printf("%c", 205);	
	}
	
	printf("%c", 188); //Esquina Inferior Derecha
	
	//Dibujar línea bajo el título
	moverCursor(4,1);
	for ( eColumna = 1; eColumna < 118; eColumna ++ ){
		printf("%c", 205);
	}

}


/* **********************************************************************
	FUNCIÓN: linea
	AUTOR: Segura Rios Brenda Stephanie
	FECHA DE CREACIÓN: 10 / 06 / 2019
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 
	OBJETIVO: Dibujar una línea en el renglon indicado.
	DE(PE): 
	DS(PS): 
********************************************************************** */
void linea(int eRen){
	
	int eCol;
		
	for (eCol = 1; eCol < 118; eCol++) {

		moverCursor(eRen, eCol);		//línea 
		printf("%c", 196);				//Escribe el caracter
	}
}

