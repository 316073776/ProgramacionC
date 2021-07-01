/* **********************************************************************
NOMBRE DEL PROGRAMA: Pila_cola.c
OBJETIVO: Crear un menú que contenga las acciones a realizar con pilas y 
		  colas y poder invertir éstas.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 19/09/2019
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
  
/*TIPO DE DATO-----------------
Declaración de tipo de dato:
pNodo: Apuntador a tipoNodo.
pInicio: Apuntador a tipoNodo.
pFinal: Apuntador a tipoNodo.
----------------------------*/
typedef tipoNodo *pNodo;		//Tipo de dato pNodo que es apuntador a una estructura "tipoNodo"
typedef tipoNodo *pInicio;			//Tipo de dato pInicio que es pauntador a una estructura "tipoNodo"
typedef tipoNodo *pFinal;			//Tipo de dato pFinal que es pauntador a una estructura "tipoNodo"


/* --------------------------------------------------------------------
NOMBRE: Función estructura_vacia
TIPO: entero int
PARÁMETROS: 	principio: 	Apuntador al inicio de la estructura.
DESCRIPCIÓN: 	Función que indica que una estructura está vacía.
		REGRESA: 0   Cuando la estructura está vacía
				 1   Cuando la estructura no está vacía
-------------------------------------------------------------------- */
int estructura_vacia (pInicio principio) {		
	
	if(!principio){			//Si no hay nodos en la estructura.	
		return 0; 			//Retornamos 0
	} else {				//De lo contrario
		return 1;
	}
}


/* --------------------------------------------------------------------
NOMBRE: Función push
TIPO: int
PARÁMETROS: tope:	De tipo (pInicio) apuntador pasado por referencia al 
					último elemento insertado de la pila.
			nuemero: valor recibido desde la funcion main.
DESCRIPCIÓN: Función que agrega o apila un elemento a la pila, 
			 implementada en un arreglo dinámico.
-------------------------------------------------------------------- */
int Push(pInicio *tope, int numero) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tamaño de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
    	fprintf (stderr, "\n\nMemoria insufuciente.");
    	return; 
    	
	} else {
	
	nuevo->valor = numero;				//A la variable "nuevo valor" se le asigna el valor de "v" (parámetro de la función main).  
	nuevo->siguiente = *tope;			//A la variable "nuevo siguiente" se le asigna el valor de último (pasado por referencia, apuntador). 
	*tope = nuevo;					//El comienzo de nuestra pila es en nuevo espacio de memoria.
	
	}

	return numero; 
	fflush(stdin);
}


/* --------------------------------------------------------------------
NOMBRE: Función pop
TIPO: int
PARÁMETROS: tope: De tipo (pInicio) apuntador pasado por referencia al 
				  último elemento insertado de la pila.
DESCRIPCIÓN: Función que elimina un elemento de una pila implementada 
			 en un arreglo dinámico.
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
				  último elemento insertado de la pila.
DESCRIPCIÓN: Función que muestra los elementos de una pila con estructuras.
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
NOMBRE: función ver_tope
TIPO:  void
PARÁMETROS: tope: Apuntador De tipo (pInicio) apuntador pasado por referencia al 
				  último elemento insertado de la pila.
DESCRIPCIÓN: Función que muestra el último elemento insertado en la pila.
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
DESCRIPCIÓN: Función que muestra los elementos de una cola.
-------------------------------------------------------------------- */
void ver_cola(pInicio inicio){
	
	pNodo auxiliar = inicio;
	
	if(estructura_vacia(inicio) == 0){ 					//si la cola está vacía.
	
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
NOMBRE: Función agregar
TIPO: void
PARÁMETROS: inicio:	De tipo (pInicio) apuntador pasado por referencia al primer elemento de la cola.
			final: De tipo (pFinal) apuntador pasado por referencia al ultimo elemento de la cola.
			número: valor recibido desde la funcion main.
DESCRIPCIÓN: Función que agrega un elemento a la cola.
-------------------------------------------------------------------- */
int agregar(pInicio *inicio, pFinal *final, int numero) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    	if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tamaño de la estructura tipoNodo
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
		
			nuevo->valor = numero;				//A la variable "nuevo valor" se le asigna el valor de "numero" (parámetro de la función main).
		}
	
	return numero; 
	fflush(stdin);
	
}


/* --------------------------------------------------------------------
NOMBRE: Función borrar
TIPO: int
PARÁMETROS: inicio: Apuntador a inicio de la cola
DESCRIPCIÓN: Función que elimina un elemento de una cola.
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
NOMBRE: función ver_inicio
TIPO:  void
PARÁMETROS: inicio:	Apuntador de tipo int que contiene un elemento de la cola.
DESCRIPCIÓN: Función que muestra el elemento iniciañ de la cola.
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
PARÁMETROS: inicio: indica el inicio de la cola.
			final:  indica el final de la cola.
			tope:   indica el tope de la pila.
DESCRIPCIÓN: Función que invierte una pila pasando sus elementos a la cola y 	
			 regresandolos a la estructura pila.
-------------------------------------------------------------------- */
void invertir_pila(pInicio *inicio, pFinal *final, pInicio *tope){
	
	pNodo auxiliar;
	
	if (estructura_vacia(*tope) == 0){
		printf("\n\tNo hay elementos en la pila.");
	
	} else {
		
		while (*inicio != NULL){			//Si la cola no está vacía
			do{								//Hacer... 
				borrar(inicio);				//Manda a llamar a la función borrar	
			} while(*inicio != NULL); 		//mientras inicio sea diferente de NULL = Para vacíar cola	
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
PARÁMETROS: inicio: indica el inicio de la cola.
			final:  indica el final de la cola.
			tope:   indica el tope de la pila.
DESCRIPCIÓN: Función que invierte una cola pasando sus elementos a la pila y 	
			 regresandolos a la estructura cola.
-------------------------------------------------------------------- */
int invertir_cola(pInicio *inicio, pFinal *final, pInicio *tope){
	
	pNodo auxiliar;
	
	if (estructura_vacia(*inicio) == 0){
		printf("\n\tNo hay elementos en la cola.");
	
	} else {
		
		while (*tope != NULL){			//Si la pila no está vacía
			do{							//Hacer... 
				Pop(tope);				//Manda a llamar a la función Pop	
			} while(*tope != NULL); 	//mientras tope sea diferente de NULL = Para vacíar pila	
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
			agregar(inicio, final, auxiliar->valor);		//Se manda a llamar la función agregar, mandando el valor de auxiliar.
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
PARÁMETROS: N/A
DESCRIPCIÓN: Función que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
int main (){
	
	pInicio pila = NULL;		//Variable llamada pila, de tipo Pila (apuntador a estructura tipoNodo) que apunta a NULL.
	pInicio inicio = NULL;		//Variable llamada inicio, de tipo pinicio (apuntador a estructura tipoNodo) que apunta a NULL.
    pFinal final = NULL;		//Variable llamada inicio, de tipo pFinal (apuntador a estructura tipoNodo) que apunta a NULL.
   	int eNumero;				//Valor ingresado por el usuario
	int eOpcion; 				//Variable que permitirá seleccionar una opción del menú.

	do { 				//Ciclo repetir-hasta para que se muestre el menú principal cada vez que se desee.
	
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
   					printf("\n\t\tPUSH: [ %d ]\n\n\n", Push(&pila, eNumero));		//Se manda a llamar a la función push.
					fflush(stdin);
   					system("pause");
				break;
			
			case 2: printf("\n\n\tPOP: [ %d ] \n", Pop(&pila));		//Se manda a llamar a la función pop.
					printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
			
			case 3: ver_tope (pila);				//Se manda a llamar a la función ver tope.
					printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
				
			case 4: ver_pila(pila);					//Se manda a llamar a la función ver pila.
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
		
		//OPCIONES DE COLA------------------------------------------------------------------------------
    		case 5: printf("\n\n\t\t%cQu%c n%cmero deseas insertar a la cola? ", 168, 130, 163);
   					scanf("%d", &eNumero);
   					printf("\n\n\t\tAGREGAR: [ %d ]\n\n\n", agregar(&inicio, &final, eNumero));			//Se manda a llamar la función agregar.
					fflush(stdin);
   					system("pause");
   				break;
			
			case 6: printf("\n\n\tBorrar  [%d]\n\n\n", borrar(&inicio));	//Se manda a llamar la función borrar.
					fflush(stdin);
   					system("pause"); 
				break;
				
    		case 7: ver_cola(inicio);						//Se manda a llamar la función ver_cola.
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
    			
    		case 8: ver_inicio (inicio);					//Se manda a llamar la función ver_inicio.
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
    			
		//OPCIONES DE INVERSIÓN------------------------------------------------------------------------------	
			case 9: invertir_pila(&inicio, &final, &pila);						//Se manda a llamar la función invertir_pila.
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
    		
    		case 10:invertir_cola(&inicio, &final, &pila);	//Se manda a llamar la función invertir_cola.
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

	} while (eOpcion != 0); //Mientras la opción sea diferente de 0, se seguirá mostrando el menú principal. 
	
	getchar (); //Obtener un caracter del teclado.
    return 0; //Regresar 0.  	    
}
