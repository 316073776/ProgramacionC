
#include <stdlib.h>

void inicializa (int A[10]){
	
	int i;
	
	for ( i = 0; i < 10; i ++){
		A[i] = i;
	}
}

void sumaDos (int A[10]){
	
	int i;
	
	for (i = 0; i < 10; i ++){
		A[i] += 2;
	}
}

void imprimeArreglo (int A[10]){
  int i;
  for (i = 0; i < 10; i ++){

 	 printf(" %i ", A[i]);
	 }
}

void main()
{
	
 int vector[10];
 
 inicializa(vector);
 imprimeArreglo(vector);

 sumaDos (vector);
 imprimeArreglo (vector);
}
