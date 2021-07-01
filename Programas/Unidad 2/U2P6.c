/* *********************************************************************************
PROGRAMA: U2P6
AUTOR: Segura Rios Brenda Stephane
FECHA: 06/03/2019
OBJETIVO: Generar y mostrar el siguiente número de una serie que inicia en 350.
********************************************************************************** */

#include <stdio.h>

int eSig();

void main(){

    printf("\nPrograma que genera y muestra el siguiente n%cmero de una serie que inicia en 350.", 163);

    printf("\n\nPrimer n%cmero:", 163);
	printf("\n%d", eSig());
	
	printf("\n\nSiguiente n%cmero:", 163);
    printf("\n%d", eSig());

     getchar();
}

int eSig(){
     
    static int eSerie = 349;     
    eSerie++;
     
    return eSerie;
}


