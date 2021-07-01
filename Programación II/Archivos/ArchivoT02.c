/* 21L02.c: Cómo leer y escribir un carâcter a la vez */
#include <stdio.h>

enum {EXITO, FRACASO};

void LeeEscribeCar(FILE *archEnt, FILE *archSal);

main(void)
{
 FILE *aptrf1, *aptrf2;
 char nomarchivo1[]= "haikusal.txt";
 char nomarchivo2[]= "haiku.txt";
 int valdevol = EXITO;
 
 if ((aptrf1 = fopen(nomarchivo1, "w")) == NULL){
    printf("No es posible abrir %s.\n", nomarchivo1);
    valdevol = FRACASO;
 } else if ((aptrf2 = fopen(nomarchivo2, "r")) == NULL){
   printf("No es posible abrir %s.\n", nomarchivo2);
   valdevol = FRACASO;
 } else {
   LeeEscribeCar(aptrf2, aptrf1);
   fclose(aptrf1);
   fclose(aptrf2);
 }
 system ("PAUSE");
 return valdevol;
}

/* definición de función */
void LeeEscribeCar(FILE *archEnt, FILE *archSal)
{
    char c;
    
    while ((c=fgetc(archEnt)) != EOF){
          fputc(c, archSal);  /* escribe en un archivo */
          putchar(c);         /* coloca el carâcter en la pantalla */
          putchar('*');         /* coloca el carâcter en la pantalla */

    }
}
