/* **********
*  Programa: U3P1.c
*  Autor: Isabel Ponce
*  Fecha: Abril de 2018
*  Objetivo: Realizar menú con las cuatro operaciones aritméticas básicas con 2 variables enteras 
********** */
#include <stdio.h>

int main(){
     
     int eOpc, eOperando1, eOperando2;
     
     do{

        system("cls");        
        printf("Calculadora B%csica\n\n", 160);
        
        printf("1. Suma\n2. Resta\n3. Multiplicaci%cn\n4. Divisi%cn\n5. Salir\n", 162, 162);
        printf("\nSeleccione un opci%cn: ", 162);
        scanf("%d", &eOpc);
        
        if (eOpc > 0 && eOpc < 5){
           printf("\nDame el primer operando: ");
           scanf("%d", &eOperando1);
           printf("Dame el segundo operando: ");
           scanf("%d", &eOperando2);
        }
        
        switch(eOpc){
           case 1: printf("\n%d + %d = %d", eOperando1, eOperando2, eOperando1 + eOperando2);
                   break;
           case 2: printf("\n%d - %d = %d", eOperando1, eOperando2, eOperando1 - eOperando2);
                   break;
           case 3: printf("\n%d * %d = %d", eOperando1, eOperando2, eOperando1 * eOperando2);
                   break;
           case 4: printf("\n%d / %d = %d", eOperando1, eOperando2, eOperando1 / eOperando2);
                   break;
           case 5: printf("\nFin del programa");
                   break;
           default: printf("Error en la selecci%cn", 162);
        }
        
        fflush(stdin);
        getchar();
        
     } while (eOpc != 5);
     
     return 0;
}
