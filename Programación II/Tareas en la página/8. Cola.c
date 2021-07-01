/* **********************************************************************
NOMBRE DEL PROGRAMA: Cola.c
OBJETIVO: Revisar qu� hace cada parte del programa y comentarlo.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 12/09/2019
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
pNodo: Apuntador a tipoNodo
pInicio: Apuntador a tipoNodo
pFinal: Apuntador a tipoNodo
----------------------------*/
typedef tipoNodo *pNodo;			//Tipo de dato pNodo que es apuntador a una estructura "tipoNodo"
typedef tipoNodo *pInicio;			//Tipo de dato pInicio que es pauntador a una estructura "tipoNodo"
typedef tipoNodo *pFinal;			//Tipo de dato pFinal que es pauntador a una estructura "tipoNodo"
 

/* --------------------------------------------------------------------
NOMBRE: Funci�n cola_vacia
TIPO: entero int
PAR�METROS: 	inicio: 	Apuntador al inicio de la cola.
DESCRIPCI�N: 	Funci�n que indica que una cola est� vac�a.
		REGRESA: 1   Cuando la cola est� vac�a
				 0   Cuando la cola no est� vac�a
-------------------------------------------------------------------- */
int cola_vacia (pInicio inicio) {		
	
	if(!inicio){			//Si no hay nodos en la cola.
	
		return 1; 		//Retornamos 1
 
	} else {			//De lo contrario
		
		return 0;
	}
    
}


/* --------------------------------------------------------------------
NOMBRE: ver_pila
TIPO: void
ARGUMENTOS: inicio: de tipo apuntador a elemntos pInicio.
DESCRIPCI�N: Funci�n que muestra los elementos de una cola.
-------------------------------------------------------------------- */
void ver_cola(pInicio inicio){
	
	pNodo auxiliar = inicio;
	
	if(cola_vacia(inicio) == 1){ 					//si la cola est� vac�a.
	
		fprintf(stderr, "\n\n\t   La cola est%c vac%ca", 160, 161);
	
	}
		
	printf("\n\nCola: ");
	  
	while (auxiliar != NULL){						//Mientras no apunte a NULL hacer...
		printf(" [ %d ] ", auxiliar->valor);   		//Imprime el valor
		auxiliar = auxiliar->siguiente;				//Cambia valor al siguiente

    }
    
	free(auxiliar);	  								//Liberar variable
      
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n agregar
TIPO: void
PAR�METROS: inicio:	De tipo (pInicio) apuntador pasado por referencia al primer elemento de la cola.
			final: De tipo (pFinal) apuntador pasado por referencia al ultimo elemento de la cola.
			n�mero: valor recibido desde la funcion main.
DESCRIPCI�N: Funci�n que agrega un elemento a la cola.
-------------------------------------------------------------------- */
void agregar(pInicio *inicio, pFinal *final, int numero) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    	if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tama�o de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
    	fprintf (stderr, "Memoria insufuciente.");
    	return; 
    	
		} else {
			
			if (cola_vacia(*inicio) == 1){
				*inicio = nuevo;			//El inicio de nuestra pila apunta al nuevo espacio de memoria.
		
			}else{
				(*final)->siguiente = nuevo;	//final siguente apunta a nuevo.
			}
			
			*final = nuevo;
			
			nuevo->siguiente = NULL;		//A la variable "nuevo siguiente" apunta a NULL
		
			nuevo->valor = numero;				//A la variable "nuevo valor" se le asigna el valor de "numero" (par�metro de la funci�n main).
		}
	
	printf("AGREGAR: [ %d ] Inicio [%p] Final [%p]  \n", numero, *inicio, *final); 
	
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n borrar
TIPO: int
PAR�METROS: inicio: Apuntador a inicio de la cola
DESCRIPCI�N: Funci�n que elimina un elemento de una cola.
-------------------------------------------------------------------- */
int borrar(pInicio *inicio) {
	
   pNodo auxiliar; 		//Variable de tipo apuntador a una estructura (pNodo)llamada "auxiliar".
   int v;      		//Variable tipo entero llamada "v".
   
   auxiliar = *inicio;	//auxiliar apunta al primer elemento de la cola.
   
   if (cola_vacia(*inicio) == 1){ 		//Si no hay nodos en la cola.
   
   		printf("\n\tLa cola est%c vac%ca.\n\n", 160, 161);
   
   } else {

	   *inicio = (*inicio)->siguiente;			//Asignamos a inicio "inicio siguiente" toda la pila menos el primer elemento.
	   v = auxiliar->valor; 				//a la variable v se le asigna el valor de "auxiliar valor"
	}
   
   free(auxiliar);						//Borrar el nodo.
   printf("\n\nBorrar    %d", v);
 
}


/* --------------------------------------------------------------------
NOMBRE: funci�n ver_inicio
TIPO:  void
PAR�METROS: inicio:	Apuntador de tipo int que contiene un elemento de la cola.
DESCRIPCI�N: Funci�n que muestra el elemento inicia� de la cola.
-------------------------------------------------------------------- */
void ver_inicio (pInicio inicio) {
	
	if (cola_vacia(inicio) == 0){
		
	printf("\n\nEl elemento que se encuentra al inicio de la cola es: %d\n\n\n", inicio->valor);
	
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
   
   pInicio inicio = NULL;		//Variable llamada inicio, de tipo pinicio (apuntador a estructura tipoNodo) que apunta a NULL.
   pFinal final = NULL;		//Variable llamada inicio, de tipo pFinal (apuntador a estructura tipoNodo) que apunta a NULL.
   int numero = 0;
   char opcion;
   
   	printf("inicio [%p]  final [%p]  \n", inicio, final); 
   
   do {
   		
   		printf("%cDeseas agregar un n%cmero%c\n [s] Si\n [n] No\n", 168, 163, 63);
   		opcion = getchar();
   		
   		if (opcion == 's'){
   			
   			printf("%cQu%c n%cmero deseas agregar%c", 168, 130, 163, 63);
  			scanf("%d", &numero);
   			agregar(&inicio, &final, numero);
   			printf("\n\n");
   			
		   }
   		fflush(stdin);
   } while (opcion != 'n');
   
   ver_inicio (inicio);
   
   ver_cola(inicio);
   borrar(&inicio);
   borrar(&inicio);
   borrar(&inicio);
   
   ver_inicio (inicio);
   
   getche();
   return 0;
}

