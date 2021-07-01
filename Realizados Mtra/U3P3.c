/* **********
*  Programa: U3P3.c
*  Autor: Isabel Ponce
*  Fecha: Abril de 2018
*  Objetivo: Obtener el promedio de 5 calificaciones solicitadas al usuario
********** */
#include <stdio.h>

#define TOTAL_CAL 5

int main(){
     
     float fCalif, fSuma = 0;
     int eContador;
     
     printf("\nObtener el promedio de %d calificaciones.\n\n", TOTAL_CAL);
     
     for (eContador = 1; eContador <= TOTAL_CAL; eContador++){
         
         printf("Dame la calificicaci%cn %d: ", 162, eContador);
         scanf("%f", &fCalif);
         
         fSuma += fCalif;
         
     }

     printf("\nEl promedio de las %d calificaciones es %5.2f", TOTAL_CAL, fSuma / TOTAL_CAL);
     getchar();
     return 0;
}
