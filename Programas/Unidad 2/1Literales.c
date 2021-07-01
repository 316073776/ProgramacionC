/*PROGRAMA: Literales.c
AUTOR: Segura Rios Brenda Stephanie
FECHA: 14/02/2019
OBJETIVO: Mostrar los diferentes tipos de literales en lenguaje C */

#include <stdio.h>
#include <stdlib.h>

#define ENTERO 12345
#define LARGO 1234567891
#define CORTO 10
#define SIN_SIGNO 1234u    //u=unsigned
#define HEXA 0x12384
#define OCTAL 01234

#define REAL 123456789.5f
#define DOBLE 123456789249546436.5
#define DOBLE_LARGO 15465387734378345743577973.5

#define CARACTER 'M'
#define SALTO '\n'
#define CADENA "Hola Mundo"
#define NULO NULL

int main (){ 
    system("cls");  //limpiar paltalla
    printf(" Entero decimal: %d", ENTERO);
    printf("\n Entero largo: %ld", LARGO);
    printf("\n Entero corto: %d", CORTO);
    printf("\n Entero sin signo: %u", SIN_SIGNO);
    printf("\n Hexadecimal: %x", HEXA);
    printf("\n Octal: %o", OCTAL);
    printf("\n Flotante: %f", REAL);
    printf("\n Flotante Formato: %5.1f", REAL);
    printf("\n Doble: %lf", DOBLE);
    printf("\n Doble Largo: %e", DOBLE_LARGO);
    printf("\n Caracter: %c", CARACTER);
    printf("\n Cadena: %s", CADENA);
    printf("\n Nulo: %s", NULO);
    printf("%c%c%c%c    Cadena: %s", SALTO, SALTO, SALTO, SALTO, CADENA);
    
    getchar();
    return 0;
    
}
    
