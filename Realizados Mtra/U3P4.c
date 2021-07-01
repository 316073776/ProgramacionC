/* **********
*  Programa: U3P4.c
*  Autor: Isabel Ponce
*  Fecha: Abril de 2018
*  Objetivo: Leer un conjunto de valores ingresados por el usuario hasta que ingrese 0
             y mostrar cu�ntos ingreso e indicar cu�l fue el mayor de todos.
********** */
#include <stdio.h>

int main(){
     
     int eNumero, eContador = 0, eMayor;
     
     printf("\nLeer n�meros y obtener cu�ntos se ingresaron y el mayor\n\n");
     
     printf("Ingrese un n�mero (0 = Terminar): ");
     scanf("%d", &eNumero);
     eMayor = eNumero;
        
     while (eNumero != 0) {

     	eContador++;
        printf("Ingrese un n�mero (0 = Terminar): ");
        scanf("%d", &eNumero);
        
        if (eNumero > eMayor) {
           eMayor = eNumero;
        }                
     } 

     printf("\nSe leyeron %d y el mayor fue %d", eContador, eMayor);
     getchar();
     return 0;
}
