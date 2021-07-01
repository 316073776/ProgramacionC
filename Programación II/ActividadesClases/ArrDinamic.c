/*
  Name: arreglodinamico.c
  Copyright: EM 2018
  Author: Esther Martinez
  Date: 11/08/18 22:08
  Description: Programa ejemplo de un arreglo din�mico de 5 elementos. 
               Curso Programaci�n.
               
               
*/
#include <stdio.h>
#include <stdlib.h>

/*
  Name: inicializa 
  Tipo: void
  Args: A :  arreglo entero de 10 elementos
  Description: Funci�n que inicializa los elementos de un arreglo
*/

void inicializa (int *A, int MAX)  //A = apuntador a un vector din�mico, MAX = el tama�o del arreglo
{
     int i;    // variable contador del arreglo
     for (i=0; i<MAX; i++) 
            A[i] = i ;
}

/*
  Name: sumaDos 
  Tipo: void
  Args: A :  arreglo entero de MAX elementos
  Description: Funci�n que suma 2 a los elementos de un arreglo entero
*/
void sumaDos (int *A, int MAX) //A = apuntador a un vector din�mico, MAX = el tama�o del arreglo
{
     int i;
     for ( i=0; i<MAX; i++)
            A[i] = A[i] + 2; //A todo lo que hay en mi arreglo, le sumo dos.
}

/*
  Name: imprimeArreglo 
  Tipo: void
  Args: A :  arreglo entero de MAX elementos
  Description: Funci�n que imprime en pantalla los elementos de un arreglo
*/
void imprimeArreglo (int *A, int MAX)  //A = apuntador a un vector din�mico, MAX = el tama�o del arreglo
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
  Description: Funci�n que declara un arreglo, lo inicializa, lo manipula y
               lo imprime en pantalla.
*/
 main() {
  int *vector;  // apuntador a enteros - arreglo local
  int n;            //numero de elementos del arreglo
  
  
  printf ("Cuantos elementos necesitas: ");
  scanf ("%d",&n);
  
  vector = (int *) malloc (sizeof(int)*n);  /*sizeof = regresa el tama�o del valor de un tipo de dato en bites. - Medida del entero.
  											  sizeof se multiplica por n para saber de qu� tama�o necesito el espacio de memoria.
											  malloc = reserva un espacio de memoria del tama�o de los bites que me indica sizeof. - Reserva la cantidad de memoria de n elementos.
											  (int *) = cast que le pone el tipo entero a malloc ya que retorna un apuntador a ning�n tipo.
											  vector = el espacio de memoria se lo asigno al apuntador vector.*/
														
  inicializa (vector, n);         // inicializa el vector en 0
  imprimeArreglo (vector, n);     // imprime en pantalla los valores del vector
  
  sumaDos (vector,n);           // suma dos a los elementos del vector
  imprimeArreglo(vector,n);     // imprime en pantalla los valores del vector
  
  free(vector);					//Libera espacio en la memoria.
  
  system("PAUSE");            // detiene la ejecuci�n del programa.
}
