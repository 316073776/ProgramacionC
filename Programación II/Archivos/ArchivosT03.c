/* 21L03.c: Cómo leer y escribir una linea de caracteres a la vez */
#include <stdio.h>

enum {EXITO, FRACASO, MAX_LEN = 81};

void LeeEscribeLinea(FILE *archEnt, FILE *archSal);

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
           printf("No es posible abrir %s para lectura.\n", nomarchivo2);
           valdevol = FRACASO;
        } else {
            LeeEscribeLinea(aptrf2, aptrf1);
            fclose(aptrf1);
            fclose(aptrf2);
        }
 system ("PAUSE");           
 return valdevol;
}

/* definición de función */
void LeeEscribeLinea(FILE *archEnt, FILE *archSal)
{
 char bufer[MAX_LEN] ;
 
      while (fgets(bufer, MAX_LEN, archEnt) != NULL){
             fputs(bufer, archSal);
             printf("%s*", bufer) ;
      } 
}
