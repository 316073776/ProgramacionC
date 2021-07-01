/* **********************************************************************
NOMBRE DEL PROGRAMA: .c
OBJETIVO: 
AUTOR: Segura Rios Brenda Stephanie
FECHA: //2019
********************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main (){
int a[2], x;
int *ap;
ap = &a[0];
/* ap apunta a la direccion de a[0] */
x = *ap;
/* A x se le asigna el contenido de ap (a[0]
en este caso) */
*(ap + 1) = 100;
/* Se asigna al segundo elemento de 'a' el
valor 100 usando ap*/
	getchar();
	return 0;
}


