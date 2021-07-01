/* **********************************************************************
NOMBRE DEL PROGRAMA: Apuntadores.c
OBJETIVO: Ver un ejemplo del uso de apuntadores.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 11/08/2019
********************************************************************** */

#include <stdio.h>

/*------------------------------------------------------------------------------
  NOMBRE: main 
  TIPO: void
  ARGUMENTOS: N/A
  DESCRIPCIÓN: Función que declara variables, las incializa, las manipula y 
  				muestra en pantalla.
------------------------------------------------------------------------------*/
int main() {
	
	int x = 1, y = 2 ;
	int *ap;
	
	//printf("x: %d\t y:%d\t ap:%d \n", x, y, *ap);
	ap = &x;
	printf("x: %d\t %p\t y:%d\t%p\t ap: %d\t %p\t %p \n", x, &x, y, &y, *ap, &ap,ap);
	y = *ap;
	printf("x: %d\t %p\t y:%d\t%p\t ap: %d\t %p\t %p \n", x, &x, y, &y, *ap, &ap,ap);
	x = (int)ap ;
	printf("x: %d\t %p\t y:%d\t%p\t ap: %d\t %p\t %p \n", x, &x, y, &y, *ap, &ap,ap);
	*ap = 3;
	printf("x: %d\t %p\t y:%d\t%p\t ap: %d\t %p\t %p \n", x, &x, y, &y, *ap, &ap,ap);
}


