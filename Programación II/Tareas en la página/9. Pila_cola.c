/* **********************************************************************
NOMBRE DEL PROGRAMA: Pila_cola.c
OBJETIVO: Crear un men� que contenga las acciones a realizar con pilas y 
		  colas y poder invertir �stas.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 19/09/2019
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
  
/*TIPO DE DATO-----------------
Declaraci�n de tipo de dato:
pNodo: Apuntador a tipoNodo.
pInicio: Apuntador a tipoNodo.
pFinal: Apuntador a tipoNodo.
----------------------------*/
typedef tipoNodo *pNodo;		//Tipo de dato pNodo que es apuntador a una estructura "tipoNodo"
typedef tipoNodo *pInicio;			//Tipo de dato pInicio que es pauntador a una estructura "tipoNodo"
typedef tipoNodo *pFinal;			//Tipo de dato pFinal que es pauntador a una estructura "tipoNodo"


/* --------------------------------------------------------------------
NOMBRE: Funci�n estructura_vacia
TIPO: entero int
PAR�METROS: 	principio: 	Apuntador al inicio de la estructura.
DESCRIPCI�N: 	Funci�n que indica que una estructura est� vac�a.
		REGRESA: 0   Cuando la estructura est� vac�a
				 1   Cuando la estructura no est� vac�a
-------------------------------------------------------------------- */
int estructura_vacia (pInicio principio) {		
	
	if(!principio){			//Si no hay nodos en la estructura.	
		return 0; 			//Retornamos 0
	} else {				//De lo contrario
		return 1;
	}
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n push
TIPO: int
PAR�METROS: tope:	De tipo (pInicio) apuntador pasado por referencia al 
					�ltimo elemento insertado de la pila.
			nuemero: valor recibido desde la funcion main.
DESCRIPCI�N: Funci�n que agrega o apila un elemento a la pila, 
			 implementada en un arreglo din�mico.
-------------------------------------------------------------------- */
int Push(pInicio *tope, int numero) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tama�o de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
    	fprintf (stderr, "\n\nMemoria insufuciente.");
    	return; 
    	
	} else {
	
	nuevo->valor = numero;				//A la variable "nuevo valor" se le asigna el valor de "v" (par�metro de la funci�n main).  
	nuevo->siguiente = *tope;			//A la variable "nuevo siguiente" se le asigna el valor de �ltimo (pasado por referencia, apuntador). 
	*tope = nuevo;					//El comienzo de nuestra pila es en nuevo espacio de memoria.
	
	}

	return numero; 
	fflush(stdin);
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n pop
TIPO: int
PAR�METROS: tope: De tipo (pInicio) apuntador pasado por referencia al 
				  �ltimo elemento insertado de la pila.
DESCRIPCI�N: Funci�n que elimina un elemento de una pila implementada 
			 en un arreglo din�mico.
-------------------------------------------------------------------- */
int Pop(pInicio *tope) {
	
   pNodo nodo; 		//Variable de tipo apuntador a una estructura (pNodo)llamada "nodo".
   int v;      		//Variable tipo entero llamada "v".
   
   nodo = *tope;	//Nodo apunta al tope de la pila.
   
   if (estructura_vacia(*tope) == 0){ 		//Si no hay nodos en la pila.
   
   		printf("\n\tLa pila est%c vac%ca.\n\n", 160, 161);
   
   } else {

	   *tope = nodo->siguiente;			//Asignamos a tope "nodo siguiente" toda la pila menos el primer elemento.
	   v = nodo->valor; 				//a la variable v se le asigna el valor de "nodo valor"
		return v; 
	}
   
   free(nodo);						//Borrar el nodo.
   
}


/* --------------------------------------------------------------------
NOMBRE: ver_pila
TIPO: void
ARGUMENTOS: tope: De tipo (pInicio) apuntador pasado por referencia al 
				  �ltimo elemento insertado de la pila.
DESCRIPCI�N: Funci�n que muestra los elementos de una pila con estructuras.
-------------------------------------------------------------------- */
void ver_pila(pInicio tope){
	
	
	if(estructura_vacia(tope) == 0){ 
	
		fprintf(stderr, "\n\n\t   La pila est%c vac%ca.", 160, 161);
	
	} else {	
		printf("\n\n\t\tPila: ");
      	
		while( tope != NULL){
         	printf(" [ %d ] ", tope->valor);
         	tope = tope->siguiente;
      	}
   }
}


/* ------------------------------------------------------------------------
NOMBRE: funci�n ver_tope
TIPO:  void
PAR�METROS: tope: Apuntador De tipo (pInicio) apuntador pasado por referencia al 
				  �ltimo elemento insertado de la pila.
DESCRIPCI�N: Funci�n que muestra el �ltimo elemento insertado en la pila.
--------------------------------------------------------------------------- */
void ver_tope (pInicio tope) {
	
	if (tope != NULL){
		
	printf("\n\nEl elemento que se encuentra al final de la pila es: [ %d ]\n\n\n", tope->valor);
	
	} else {
		
	printf("\n\tNo hay elementos en la pila.");
	
	}
	
}


/* --------------------------------------------------------------------
NOMBRE: ver_cola
TIPO: void
ARGUMENTOS: inicio: de tipo apuntador a elemntos pInicio.
DESCRIPCI�N: Funci�n que muestra los elementos de una cola.
-------------------------------------------------------------------- */
void ver_cola(pInicio inicio){
	
	pNodo auxiliar = inicio;
	
	if(estructura_vacia(inicio) == 0){ 					//si la cola est� vac�a.
	
		fprintf(stderr, "\n\n\t   La cola est%c vac%ca", 160, 161);
	
	} else {
		
		printf("\n\n\t\tCola: ");
		  
		while (auxiliar != NULL){						//Mientras no apunte a NULL hacer...
			printf(" [ %d ] ", auxiliar->valor);   		//Imprime el valor
			auxiliar = auxiliar->siguiente;				//Cambia valor al siguiente
	    }
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
int agregar(pInicio *inicio, pFinal *final, int numero) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    	if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tama�o de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
	    	fprintf (stderr, "Memoria insufuciente.");
	    	return; 
    	
		} else {
			
			if (estructura_vacia(*inicio) == 0){
				*inicio = nuevo;			//El inicio de nuestra cola apunta al nuevo espacio de memoria.
		
			}else{
				(*final)->siguiente = nuevo;	//final siguente apunta a nuevo.
			}
			
			*final = nuevo;
			
			nuevo->siguiente = NULL;		//A la variable "nuevo siguiente" apunta a NULL
		
			nuevo->valor = numero;				//A la variable "nuevo valor" se le asigna el valor de "numero" (par�metro de la funci�n main).
		}
	
	return numero; 
	fflush(stdin);
	
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
   
   if (estructura_vacia(*inicio) == 0){ 		//Si no hay nodos en la cola.
   
   		printf("\n\tLa cola est%c vac%ca.\n\n", 160, 161);
   
   } else {

	   *inicio = (*inicio)->siguiente;			//Asignamos a inicio "inicio siguiente" toda la pila menos el primer elemento.
	   v = auxiliar->valor; 				//a la variable v se le asigna el valor de "auxiliar valor"
	   return v;
	}
   
   free(auxiliar);						//Borrar el nodo.
 
}


/* --------------------------------------------------------------------
NOMBRE: funci�n ver_inicio
TIPO:  void
PAR�METROS: inicio:	Apuntador de tipo int que contiene un elemento de la cola.
DESCRIPCI�N: Funci�n que muestra el elemento inicia� de la cola.
-------------------------------------------------------------------- */
void ver_inicio (pInicio inicio) {
	
	if (estructura_vacia(inicio) == 1){
		
	printf("\n\nEl elemento que se encuentra al inicio de la cola es: [%d]\n\n\n", inicio->valor);
	
	} else {
		
	printf("\n\tNo hay elementos en la cola.");
	
	}	
}


/* --------------------------------------------------------------------
NOMBRE: invertir_pila
TIPO: void
PAR�METROS: inicio: indica el inicio de la cola.
			final:  indica el final de la cola.
			tope:   indica el tope de la pila.
DESCRIPCI�N: Funci�n que invierte una pila pasando sus elementos a la cola y 	
			 regresandolos a la estructura pila.
-------------------------------------------------------------------- */
void invertir_pila(pInicio *inicio, pFinal *final, pInicio *tope){
	
	pNodo auxiliar;
	
	if (estructura_vacia(*tope) == 0){
		printf("\n\tNo hay elementos en la pila.");
	
	} else {
		
		while (*inicio != NULL){			//Si la cola no est� vac�a
			do{								//Hacer... 
				borrar(inicio);				//Manda a llamar a la funci�n borrar	
			} while(*inicio != NULL); 		//mientras inicio sea diferente de NULL = Para vac�ar cola	
			printf("\nYa se vaci%c la cola.\t", 162);
		}
		
		printf("\n\n\tPILA ORIGINAL: ");
		ver_pila(*tope);
		
		do{
			auxiliar = *tope;				//A la variable auxiliar se le asigna la estructura tope.
			agregar(inicio, final, auxiliar->valor);	//Se manda a llamar la funcion agregar, mandando el valor de auxiliar.
			Pop(tope);						//Se hace pop al elemento tope de la pila.
		} while (*tope != NULL);			//Mientras tope sea diferente de NULL.

		printf("\n\n\tCOLA TEMPORAL: ");
		ver_cola(*inicio);
		
		do{
			auxiliar = *inicio;				//A la variable auxiliar se le asigna la estructura inicio.
			Push(tope, auxiliar->valor);	//Se manda a llamar la funcion Push, mandando el valor de auxiliar.
			borrar(inicio);					//Se borra el elemento inicio de la cola.
		} while (*inicio != NULL);			//Mientras inicio sea diferente de null.
		
		printf("\n\n\tPILA INVERTIDA: ");
		ver_pila(*tope);
		
	}	
	
	free(auxiliar);						//Borrar el nodo.
}


/* --------------------------------------------------------------------
NOMBRE: invertir_cola
TIPO: void
PAR�METROS: inicio: indica el inicio de la cola.
			final:  indica el final de la cola.
			tope:   indica el tope de la pila.
DESCRIPCI�N: Funci�n que invierte una cola pasando sus elementos a la pila y 	
			 regresandolos a la estructura cola.
-------------------------------------------------------------------- */
int invertir_cola(pInicio *inicio, pFinal *final, pInicio *tope){
	
	pNodo auxiliar;
	
	if (estructura_vacia(*inicio) == 0){
		printf("\n\tNo hay elementos en la cola.");
	
	} else {
		
		while (*tope != NULL){			//Si la pila no est� vac�a
			do{							//Hacer... 
				Pop(tope);				//Manda a llamar a la funci�n Pop	
			} while(*tope != NULL); 	//mientras tope sea diferente de NULL = Para vac�ar pila	
			printf("\nYa se vaci%c la pila.\t", 162);
		}
		
		printf("\n\n\tCOLA ORIGINAL: ");
		ver_cola(*inicio);
		
		do{
			auxiliar = *inicio;				//A la variable auxiliar se le asigna la estructura inicio.
			Push(tope, auxiliar->valor);	//Se manda a llamar la funcion Push, mandando el valor de auxiliar.
			borrar(inicio);					//Se borra el elemento inicio de la cola.
		} while (*inicio != NULL);			//Mientras inicio sea diferente de NULL.

		printf("\n\n\tPILA TEMPORAL: ");
		ver_pila(*tope);
		
		do{
			auxiliar = *tope;				//A la variable auxiliar se le asigna la estructura tope.
			agregar(inicio, final, auxiliar->valor);		//Se manda a llamar la funci�n agregar, mandando el valor de auxiliar.
			Pop(tope);						//Se hace pop al tope de la pila.
		} while (*tope != NULL);			//Mientras tope sea diferente de null.
		
		printf("\n\n\tCOLA INVERTIDA: ");
		ver_cola(*inicio);
		
	}	
	free(auxiliar);						//Borrar el nodo.
}


/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
PAR�METROS: N/A
DESCRIPCI�N: Funci�n que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
int main (){
	
	pInicio pila = NULL;		//Variable llamada pila, de tipo Pila (apuntador a estructura tipoNodo) que apunta a NULL.
	pInicio inicio = NULL;		//Variable llamada inicio, de tipo pinicio (apuntador a estructura tipoNodo) que apunta a NULL.
    pFinal final = NULL;		//Variable llamada inicio, de tipo pFinal (apuntador a estructura tipoNodo) que apunta a NULL.
   	int eNumero;				//Valor ingresado por el usuario
	int eOpcion; 				//Variable que permitir� seleccionar una opci�n del men�.

	do { 				//Ciclo repetir-hasta para que se muestre el men� principal cada vez que se desee.
	
		system("cls");			//Limpiar pantalla
		
		printf("\n\n\t\t-----PROGRAMA 9-----\n");
		printf("\t\t        MEN%C\n\n", 233);
    	printf("\t\t   %c %c Pila\n", 175, 175);
    	printf("\t\t\t  %c 1. Push\n", 254);
    	printf("\t\t\t  %c 2. Pop\n", 254);
    	printf("\t\t\t  %c 3. Ver tope\n", 254);
    	printf("\t\t\t  %c 4. Ver pila\n\n", 254);
    	printf("\t\t   %c %c Cola\n", 175, 175);
    	printf("\t\t\t  %c 5. Agregar\n", 254);
    	printf("\t\t\t  %c 6. Borrar\n", 254);
    	printf("\t\t\t  %c 7. Ver cola\n", 254);
    	printf("\t\t\t  %c 8. Ver inicio\n\n", 254);
	    printf("\t\t   %c %c Invertir\n", 175, 175);
	    printf("\t\t\t  %c 9. De pila a cola\n", 254);
	    printf("\t\t\t  %c 10. De cola a pila\n\n", 254);
	    printf("\t\t   %c 0. Salir", 175, 175);
	    
	    printf("\n\nIntroduzca el n%cmero de la acci%cn que deseas realizar: ", 163, 162);
    	scanf("%d", &eOpcion); 		//Leer variable eOpcion.
    	
    	system("cls");				//Limpiar pantalla.
    	
    	switch(eOpcion){ 			//En caso de eOpcion... , hacer...
    	
		//OPCIONES DE PILA------------------------------------------------------------------------------	
    		case 1:	printf("\n\t\t%cQu%c n%cmero deseas insertar a la pila? ", 168, 130, 163);
   					scanf("%d", &eNumero);
   					printf("\n\t\tPUSH: [ %d ]\n\n\n", Push(&pila, eNumero));		//Se manda a llamar a la funci�n push.
					fflush(stdin);
   					system("pause");
				break;
			
			case 2: printf("\n\n\tPOP: [ %d ] \n", Pop(&pila));		//Se manda a llamar a la funci�n pop.
					printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
			
			case 3: ver_tope (pila);				//Se manda a llamar a la funci�n ver tope.
					printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
				
			case 4: ver_pila(pila);					//Se manda a llamar a la funci�n ver pila.
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
		
		//OPCIONES DE COLA------------------------------------------------------------------------------
    		case 5: printf("\n\n\t\t%cQu%c n%cmero deseas insertar a la cola? ", 168, 130, 163);
   					scanf("%d", &eNumero);
   					printf("\n\n\t\tAGREGAR: [ %d ]\n\n\n", agregar(&inicio, &final, eNumero));			//Se manda a llamar la funci�n agregar.
					fflush(stdin);
   					system("pause");
   				break;
			
			case 6: printf("\n\n\tBorrar  [%d]\n\n\n", borrar(&inicio));	//Se manda a llamar la funci�n borrar.
					fflush(stdin);
   					system("pause"); 
				break;
				
    		case 7: ver_cola(inicio);						//Se manda a llamar la funci�n ver_cola.
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
    			
    		case 8: ver_inicio (inicio);					//Se manda a llamar la funci�n ver_inicio.
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
    			
		//OPCIONES DE INVERSI�N------------------------------------------------------------------------------	
			case 9: invertir_pila(&inicio, &final, &pila);						//Se manda a llamar la funci�n invertir_pila.
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
    		
    		case 10:invertir_cola(&inicio, &final, &pila);	//Se manda a llamar la funci�n invertir_cola.
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
    				
    		default:if (eOpcion != 0){
						printf("\n\n\t\tError en la selecci%cn\n\n", 162);
						fflush(stdin);  
						system("pause");
					}
				break; //Terminar el ciclo en caso de.
    				 
		}

	} while (eOpcion != 0); //Mientras la opci�n sea diferente de 0, se seguir� mostrando el men� principal. 
	
	getchar (); //Obtener un caracter del teclado.
    return 0; //Regresar 0.  	    
}
