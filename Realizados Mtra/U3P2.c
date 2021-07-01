/* **********
*  Programa: U3P2.c
*  Autor: Isabel Ponce
*  Fecha: Abril de 2018
*  Objetivo: Sumar todos los valores entre 5 y 30
********** */
#include <stdio.h>

#define INICIO 5
#define FIN 30

int main(){
     
     int eContador, eSuma = 0;
     
     for (eContador = INICIO + 1; eContador < FIN; eContador++){
         
         eSuma += eContador;
         
     }
     
     printf("\nLa suma de los valores entre %d y %d = %d", INICIO, FIN, eSuma);
     getchar();
     return 0;
}
