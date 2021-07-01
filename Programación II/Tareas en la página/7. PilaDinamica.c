/* **********************************************************************
NOMBRE DEL PROGRAMA: PilaDinámica.c
OBJETIVO: Revisar qué hace cada parte del programa y comentarlo.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 26/08/2019
********************************************************************** */
//LIBRERÍAS
#include <stdio.h>
#include <stdlib.h>


/*ESTRUCTURAS---------------
Estructrura "tipoNodo" que contiene dos elementos.
valor: tipo int
siguiente: tipo apuntador a estructura nodo.
----------------------------*/
typedef struct nodo {			//Define estructura llamada nodo para que se pueda apuntar a la estructura
   int valor;					
   struct nodo *siguiente;		//Apuntador (llamado siguiente) a estructura nodo.
} tipoNodo;						//Nombre de la estructura = tipoNodo
 
 
/*----------------------------
Declaración de tipo de dato:
pNodo: Apuntador a tipoNodo.
Pila: Apuntador a tipoNodo
----------------------------*/
typedef tipoNodo *pNodo;		//Tipo de dato pNodo que es apuntador a una estructura "tipoNodo"
typedef tipoNodo *Pila;			//Tipo de dato Pila que es pauntador a una estructura "tipoNodo"
 

/* --------------------------------------------------------------------
NOMBRE: Función pila_vacia
TIPO: entero int
PARÁMETROS: 	pila: 	Apuntador al inicio de la pila.
DESCRIPCIÓN: 	Función que indica que una pila está vacía.
		REGRESA: 1   Cuando la pila está vacía
				 0   Cuando la pila no está vacía
-------------------------------------------------------------------- */
int pila_vacia (Pila pila) {		
	
	if(!pila){			//Si no hay nodos en la pila.
	
		return 0; 		//Retornamos 0
 
	} else {
		
		return 1;
	}
    
}


/* --------------------------------------------------------------------
NOMBRE: Función push
TIPO: void
PARÁMETROS: ultimo:	De tipo (Pila) apuntador pasado por referencia al último elemento de la pila.
			v: valor recibido desde la funcion main.
DESCRIPCIÓN: Función que agrega o apila un elemento a la pila, 
			 implementada en un arreglo dinámico.
-------------------------------------------------------------------- */
void Push(Pila *ultimo, int v) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    /* ---Crear un nodo nuevo--- */
    if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tamaño de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
    	fprintf (stderr, "Memoria insufuciente.");
    	return; 
	} else {
	
	nuevo->valor = v;				//A la variable "nuevo valor" se le asigna el valor de "v" (parámetro de la función main).
	   
	nuevo->siguiente = *ultimo;		//A la variable "nuevo siguiente" se le asigna el valor de último (pasado por referencia, apuntador). 
	
	*ultimo = nuevo;			//El comienzo de nuestra pila es en nuevo espacio de memoria.
	
	}
	
	printf("PUSH: [ %d ] \n", v); 
	
}


/* --------------------------------------------------------------------
NOMBRE: Función pop
TIPO: int
PARÁMETROS: pila: Apuntador a tipos Pila.
DESCRIPCIÓN: Función que elimina un elemento de una pila implementada 
			 en un arreglo dinámico.
-------------------------------------------------------------------- */
int Pop(Pila *pila) {
	
   pNodo nodo; 		//Variable de tipo apuntador a una estructura (pNodo)llamada "nodo".
   int v;      		//Variable tipo entero llamada "v".
   
   nodo = *pila;	//Nodo apunta al primer elemento de la pila.
   
   if (pila_vacia(*pila) == 0){ 		//Si no hay nodos en la pila.
   
   		printf("\n\tLa pila est%c vac%ca.\n\n", 160, 161);
   
   } else {

	   *pila = nodo->siguiente;			//Asignamos a pila "nodo siguiente" toda la pila menos el primer elemento.
	   v = nodo->valor; 				//a la variable v se le asigna el valor de "nodo valor"
	}
   
   free(nodo);						//Borrar el nodo.
   return v;
 
}


/* --------------------------------------------------------------------
NOMBRE: ver_pila
TIPO: void
ARGUMENTOS: pila: de tipo apuntador a elemtnos Pila.
DESCRIPCIÓN: Función que muestra los elementos de una pila con estructuras.
-------------------------------------------------------------------- */
void ver_pila(Pila pila){
	
	pNodo aux; 
	
	if(pila_vacia(pila) == 0){ 
	
		fprintf(stderr, "\n\n\t   La pila est%c vac%ca", 160, 161);
	
	} else {
		
	printf("\n\nPila: ");
      while( pila != NULL){
         printf(" [ %d ] ", pila->valor);
         pila = pila->siguiente;
      }
   }
  
    
    
}//*****************************************


/* --------------------------------------------------------------------
NOMBRE: función ver_tope
TIPO:  void
PARÁMETROS: pila:	Apuntador de tipo char que contiene un caracter de la pila.
DESCRIPCIÓN: Función que muestra el último elemento insertado en la pila.
-------------------------------------------------------------------- */
void ver_tope (Pila ultimo) {
	
	if (ultimo != NULL){
		
	printf("\n\nEl elemento que se encuentra al final de la pila es: %d\n\n\n", ultimo->valor);
	
	} else {
		
	printf("\n\tNo hay elementos en la pila.");
	
	}
	
}


/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
ARGUMENTOS: N/A
DESCRIPCIÓN: Función que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
int main() {
   
   Pila pila = NULL;		//Variable llamada pila, de tipo Pila (apuntador a estructura tipoNodo) que apunta a NULL.
 
   Push(&pila, 20);			//Se manda a llamar a la función push.
   Push(&pila, 10);			//Pila se pasa por referencia.
   Push(&pila, 30);
   printf("\nPOP: [ %d ] \n\n", Pop(&pila)); 
   Push(&pila, 40);
   Push(&pila, 30);
   
   ver_pila(pila);
   printf("\n");
   
   printf("\nPOP: [ %d ] \n", Pop(&pila));
   printf("POP: [ %d ] \n\n", Pop(&pila));
   Push(&pila, 90);
   
   ver_pila(pila);
   printf("\n");
   
   printf("\nPOP: [ %d ] ", Pop(&pila));
   printf("\nPOP: [ %d ] ", Pop(&pila));
   printf("\nPOP: [ %d ] ", Pop(&pila));
   
   ver_pila(pila);
   ver_tope (pila);
   
   getche();
   return 0;
}

