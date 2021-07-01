/* **********************************************************************
NOMBRE DEL PROGRAMA: U3P1.c
OBJETIVO: Programa que muestra un menú y realiza las cuatro operaciones aritméticas.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 28/03/2019
********************************************************************** */
#include <stdio.h>

int main (){
	
	int eOpcion, eNum1, eNum2;
	
	printf("Programa que realiza las cuatro operaciones aritm%cticas.", 130);

	do {
		
		printf("\n\nMen%c:\n1.- Suma.\n2.- Resta\n3.- Multiplicaci%cn.\n4.- Divisi%cn.\n5.- Salir.", 163, 162, 162);
		printf("\n\nSeleccione una opci%cn:", 162);
		scanf("%d", &eOpcion);
		
		if (eOpcion > 0 && eOpcion < 5 ){
			
			printf("\nIngrese el primer n%cmero: ", 163);
			scanf("%d", &eNum1);
			
			printf("\nIngrese el segundo n%cmero: ", 163);
			scanf("%d", &eNum2);
		}
		
		switch (eOpcion){
			
			case 1 :
				printf("La suma de %d + %d es igual a: %d", eNum1, eNum2, eNum1 + eNum2);
				break;	
			
			case 2 :
				printf("La resta de %d - %d es igual a: %d", eNum1, eNum2, eNum1 - eNum2);
				break;
			
			case 3 : 
				printf("La multiplicaci%cn de %d x %d es igual a: %d", 162, eNum1, eNum2, eNum1 * eNum2);
				break;
				
			case 4 : 
				printf("La divici%cn de %d %c %d es igual a: %5.2f", 162, eNum1, 246, eNum2, eNum1 / eNum2);
				break;
				
			case 5 :
				printf("Has salido del programa.");
				
			default : 
				printf("Selecci%cn inválida.", 162);
				
		}
		
		getchar();	
		fflush(stdin);	
	} while ( eOpcion != 5 );
	

	return 0;
}


