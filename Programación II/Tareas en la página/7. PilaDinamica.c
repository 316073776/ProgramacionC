/* **********************************************************************
NOMBRE DEL PROGRAMA: PilaDin�mica.c
OBJETIVO: Revisar qu� hace cada parte del programa y comentarlo.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 26/08/2019
********************************************************************** */
//LIBRER�AS
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
Declaraci�n de tipo de dato:
pNodo: Apuntador a tipoNodo.
Pila: Apuntador a tipoNodo
----------------------------*/
typedef tipoNodo *pNodo;		//Tipo de dato pNodo que es apuntador a una estructura "tipoNodo"
typedef tipoNodo *Pila;			//Tipo de dato Pila que es pauntador a una estructura "tipoNodo"
 

/* --------------------------------------------------------------------
NOMBRE: Funci�n pila_vacia
TIPO: entero int
PAR�METROS: 	pila: 	Apuntador al inicio de la pila.
DESCRIPCI�N: 	Funci�n que indica que una pila est� vac�a.
		REGRESA: 1   Cuando la pila est� vac�a
				 0   Cuando la pila no est� vac�a
-------------------------------------------------------------------- */
int pila_vacia (Pila pila) {		
	
	if(!pila){			//Si no hay nodos en la pila.
	
		return 0; 		//Retornamos 0
 
	} else {
		
		return 1;
	}
    
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n push
TIPO: void
PAR�METROS: ultimo:	De tipo (Pila) apuntador pasado por referencia al �ltimo elemento de la pila.
			v: valor recibido desde la funcion main.
DESCRIPCI�N: Funci�n que agrega o apila un elemento a la pila, 
			 implementada en un arreglo din�mico.
-------------------------------------------------------------------- */
void Push(Pila *ultimo, int v) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    /* ---Crear un nodo nuevo--- */
    if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tama�o de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
    	fprintf (stderr, "Memoria insufuciente.");
    	return; 
	} else {
	
	nuevo->valor = v;				//A la variable "nuevo valor" se le asigna el valor de "v" (par�metro de la funci�n main).
	   
	nuevo->siguiente = *ultimo;		//A la variable "nuevo siguiente" se le asigna el valor de �ltimo (pasado por referencia, apuntador). 
	
	*ultimo = nuevo;			//El comienzo de nuestra pila es en nuevo espacio de memoria.
	
	}
	
	printf("PUSH: [ %d ] \n", v); 
	
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n pop
TIPO: int
PAR�METROS: pila: Apuntador a tipos Pila.
DESCRIPCI�N: Funci�n que elimina un elemento de una pila implementada 
			 en un arreglo din�mico.
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
DESCRIPCI�N: Funci�n que muestra los elementos de una pila con estructuras.
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
NOMBRE: funci�n ver_tope
TIPO:  void
PAR�METROS: pila:	Apuntador de tipo char que contiene un caracter de la pila.
DESCRIPCI�N: Funci�n que muestra el �ltimo elemento insertado en la pila.
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
DESCRIPCI�N: Funci�n que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
int main() {
   
   Pila pila = NULL;		//Variable llamada pila, de tipo Pila (apuntador a estructura tipoNodo) que apunta a NULL.
 
   Push(&pila, 20);			//Se manda a llamar a la funci�n push.
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

