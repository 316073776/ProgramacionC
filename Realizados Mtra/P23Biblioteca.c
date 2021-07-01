/*
	Programa: P23Biblioteca.c
	Autor: Isabel Ponce
	Fecha: 06/06/19
	Objetivo: Administrar los datos de los libros de una biblioteca
*/	
	
//Bibliotecas
#include<string.h>	
#include<stdio.h>
#include<stdlib.h>
#include "P23Libros.c"

int main(){
	
	int eOpcion;
	
	do{
	
		system("cls");
		printf("\n\n\tSistema de biblioteca\n");
		printf("\n\t\t1. Libros\n\t\t2. Autores\n\t\t3. Salir");
		printf("\n\n\tSeleccione una opcion: ");
		scanf("%d", &eOpcion);
		
		switch(eOpcion){
			
			case 1: MenuLibros();
					break;
								
			case 2: //MenuAutores()
		  			break;
		  			
			case 3: printf("Adios\n");
					break;
			default: printf("Error en la selecci%cn", 162);
					break;	  	
		}
				
	}while(eOpcion != 3);
	
	return 0;
} //main

