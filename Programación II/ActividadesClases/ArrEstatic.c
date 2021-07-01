/*
  Name: arreglo estatico.c
  Copyright: EM 2018
  Author: Esther Martinez
  Date: 11/08/18 22:08
  Description: Programa ejemplo de un arreglo estático de 5 elementos. 
               Curso Programación.
               
               
*/
#include <stdio.h>
#define MAX 500

/*
  Name: inicializa 
  Tipo: void
  Args: A :  arreglo entero de 10 elementos
  Description: Función que inicializa los elementos de un arreglo
*/

void inicializa (int A[MAX])
{
     int i;    // variable contador del arreglo
     for (i=0; i<MAX; i++)
            A[i] = i ;
}

/*
  Name: sumaDos 
  Tipo: void
  Args: A :  arreglo entero de MAX elementos
  Description: Función que suma 2 a los elementos de un arreglo entero
*/
void sumaDos (int A[MAX])
{
     int i;
     for ( i=0; i<MAX; i++)
            A[i] = A[i] + 2;
}

/*
  Name: imprimeArreglo 
  Tipo: void
  Args: A :  arreglo entero de MAX elementos
  Description: Función que imprime en pantalla los elementos de un arreglo
*/
void imprimeArreglo (int A[MAX])
{
     int i;
     for (i=0; i<MAX; i++)
          printf(" %i  ", A[i]);
     
     printf("\n");
}


/*
  Name: main 
  Tipo: void
  Args: N/A
  Description: Función que declara un arreglo, lo inicializa, lo manipula y
               lo imprime en pantalla.
*/
 main()
{
  int vector[MAX];  // arreglo local

  inicializa(vector);         // inicializa el vector en 0
  imprimeArreglo(vector);     // imprime en pantalla los valores del vector
  
  sumaDos (vector);           // suma dos a los elementos del vector
  imprimeArreglo(vector);     // imprime en pantalla los valores del vector
  
  
  system("PAUSE");            // detiene la ejecución del programa.
}


