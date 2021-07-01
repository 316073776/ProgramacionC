

#include <stdio.h>
#include <stdlib.h>

int main() {
    char caracter = 'm';
    signed char caracterConSigno = 'e';
    unsigned char caracterSinSigno = 'd';
    char* cadena = "Hola Mundo";
    
    int entero = 3213;
    signed int enteroConSigno = 3213;
    unsigned int enteroSinSigno = 6546;
    
    short int enteroCorto = 3213;
    signed short int enteroCortoConSigno = 3213;
    unsigned short int enteroCortoSinSigno = 3123;
    
    long int enteroLargo = 12331223;
    signed long int enteroLargoConSigno = 1232123123;
    unsigned long int enteroLargoSinSigno = 123112321;
    
    int octal = 021236563;
    int hexadecimal = 0x1232112;
    
    float real = 1237345435.1f;
    double doble = 1234543453216574343.1;
    long double dobleLargo = 4212387687354541186571.1;
    
    system("cls");
    
    printf("\n\nCaracter: %c", caracter);
    printf("\nCaracter Con Signo: %c", caracterConSigno);
    printf("\nCaracter Sin Signo: %c", caracterSinSigno);
    printf("\nCadena: %s", cadena);
    
    printf("\n\nEntero: %d", entero);
    printf("\nEntero Con Signo: %d", enteroConSigno);
    printf("\nEntero Sin Signo: %u", enteroSinSigno);
    
    printf("\n\nEntero Corto: %d", enteroCorto);
    printf("\nEntero Corto Con Signo: %d", enteroCortoConSigno);
    printf("\nEntero Corto Sin Signo: %d", enteroCortoSinSigno);
    
    printf("\n\nEntero largo: %ld", enteroLargo);
    printf("\nEntero largo con signo: %ld", enteroLargoConSigno);
    printf("\nEntero largo sin signo: %lu", enteroLargoSinSigno);

    printf("\n\nOctal: %o", octal);
    printf("\nHexadecimal: %x", hexadecimal);
    
    printf("\n\nReal: %f", real);
    printf("\nDoble: %lf", doble);
    printf("\nDoble largo: %.20lg\n\n", dobleLargo);
    
    getchar ();
    return 0;
    
}
