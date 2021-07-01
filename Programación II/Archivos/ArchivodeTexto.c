/* 21L01.c: Cómo abrir y cerrar un archivo */
#include <stdio.h>

enum {EXITO, FRACASO};

main(void) 
{
FILE *aptrf; 
char nomarchivo[]= "Haiku.txt";
int valdevol = EXITO;

if ((aptrf = fopen(nomarchivo, "r")) == NULL){
   printf("No es posible abrir %s.\n", nomarchivo);
   valdevol = FRACASO;
} else {
  printf("El valor de aptrf es: 0x%p\n", aptrf);
  printf("Listo para cerrar el archivo.\n");
  fclose(aptrf) ;
}

system("PAUSE");
return valdevol;

}
