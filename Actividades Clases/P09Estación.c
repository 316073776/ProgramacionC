 /* **********************************************************************
NOMBRE DEL PROGRAMA: P09Estación.c
OBJETIVO: Indicar en qué estación te encuentras dependiendo los números recibidos.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 21/03/2019
********************************************************************** */
#include <stdio.h>

int main (){
	
	int eDia, eMes;
	
	printf("Programa que al recibir un n%cmero correspondiente al mes y otro correspondiente al d%ca devuelve un mensaje que indica la estaci%cn.", 163, 161, 163);
	printf("\n\nEscribir un n%cmero que corresponde al mes: ", 163);
	scanf("%d", &eMes);
	printf("Escribir el n%cmero que corresponde al d%ca: ", 163, 161);
	scanf("%d", &eDia);
	
	if (eDia < 1 || eDia > 31){
		printf ("Error, d%ca fuera de rango.", 161);
		
	} else {
		
		switch (eMes) {
		
			case 1:
			case 2 :
			case 12 :
				if (eMes = 12 && eDia < 21){
					printf("Es oto%co.", 164);
				} else {
					printf("Es invierno.");
				}
			break;
			
			case 3:
			case 4:
			case 5:
				if (eMes = 3 && eDia < 21){
					printf("Es invierno.");
				} else {
					printf("Es primavera.");
				}
			break;
			
			case 6:
			case 7:
			case 8:
				if (eMes = 6 && eDia < 21){
					printf("Es primavera.");
				} else {
				printf("Es verano.");
				}
			break;
			
			case 9:
			case 10:
			case 11:
				if 	(eMes = 9 && eDia < 21){
					printf("Es verano.");
				} else {
					printf("Es Oto%co.", 164);
				}
			break;	
			
			default :
				printf("Error, mes fuera de rango.");
		}
		
	}

	getchar();
	return 0;
}


