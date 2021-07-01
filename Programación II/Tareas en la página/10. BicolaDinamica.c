/* **********************************************************************
NOMBRE DEL PROGRAMA: BicolaDinamica.c
OBJETIVO: Crear una bicola dinámica (con apuntadores).
AUTOR: Segura Rios Brenda Stephanie
FECHA: 23/09/2019
********************************************************************** */
//LIBRERÍAS
#include <stdio.h>
#include <stdlib.h>

/*ESTRUCTURAS---------------
Estructrura "tipoNodo" que contiene tres elementos.
valor: tipo int
anterior: tipo apuntador a estructura nodo.
siguiente: tipo apuntador a estructura nodo.
----------------------------*/
typedef struct nodo {			//Define estructura llamada nodo para que se pueda apuntar a la estructura
   int valor;
   struct nodo *anterior;		//Apuntador (llamado anterior) a estructura nodo.					
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
NOMBRE: Función bicola_vacia
TIPO: entero int
PARÁMETROS: 	inicio: 	Apuntador al inicio de la bicola.
DESCRIPCIÓN: 	Función que indica que la bicola está vacía.
		REGRESA: 0   Cuando la estructura está vacía
				 1   Cuando la estructura no está vacía
-------------------------------------------------------------------- */
int bicola_vacia (pInicio inicio) {		
	
	if(!inicio){			//Si no hay nodos en la estructura.	
		return 0; 			//Retornamos 0
	} else {				//De lo contrario
		return 1;
	}
}


/* --------------------------------------------------------------------
NOMBRE: Función agregar_inicio
TIPO: int
PARÁMETROS: inicio:	De tipo (pInicio) apuntador pasado por referencia al 
					inicio de la bicola.
			final: 	De tipo (pFinal) apuntador pasado por referencia al 
					ultimo elemento de la bicola.
			nuemero: Valor recibido desde la funcion main.
DESCRIPCIÓN: Función que agrega un elemento al inicio de la bicola.
-------------------------------------------------------------------- */
int agregar_inicio(pInicio *inicio, pFinal *final, int numero) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tamaño de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
    	fprintf (stderr, "\n\nMemoria insufuciente.");
    	return; 
    	
	} else {
		
		if (bicola_vacia(*inicio) == 0){	//Si la bicola está vacía		
				*final = nuevo;				//El final de nuestra bicola apunta al nuevo espacio de memoria.
				nuevo->siguiente = NULL;	//La variable "nuevo siguiente" apunta a NULL
			}else{
				(*inicio)->anterior = nuevo;	//inicio anterior apunta a nuevo.
				nuevo->siguiente = *inicio;		//La variable "nuevo siguiente" apunta a inicio.
			}
			
			*inicio = nuevo;			//El inicio de nuestra bicola apunta al nuevo espacio de memoria.
			nuevo->anterior = NULL;		//La variable "nuevo anterior" apunta a NULL
			
			nuevo->valor = numero;				//A la variable "nuevo valor" se le asigna el valor de "numero" (parámetro de la función main).
		}
	
	return numero; 
	fflush(stdin);
}


/* --------------------------------------------------------------------
NOMBRE: Función agregar_final
TIPO: void
PARÁMETROS: inicio:	De tipo (pInicio) apuntador pasado por referencia al primer elemento de la bicola.
			final: De tipo (pFinal) apuntador pasado por referencia al ultimo elemento de la bicola.
			número: valor recibido desde la funcion main.
DESCRIPCIÓN: Función que agrega un elemento al final de la bicola.
-------------------------------------------------------------------- */
int agregar_final(pInicio *inicio, pFinal *final, int numero) {
   
    pNodo nuevo;					//variable de tipo apuntador a una estructura (pNodo)llamada "nuevo".
 	
    	if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tamaño de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
	    	fprintf (stderr, "Memoria insufuciente.");
	    	return; 
    	
		} else {
			
			if (bicola_vacia(*inicio) == 0){	//Si la bicola está vacía		
				*inicio = nuevo;				//El inicio de nuestra bicola apunta al nuevo espacio de memoria.
				nuevo->anterior = NULL;		//La variable "nuevo anterior" apunta a NULL
			}else{
				(*final)->siguiente = nuevo;	//final siguente apunta a nuevo.
				nuevo->anterior = *final;
			}
			
			nuevo->siguiente = NULL;		//La variable "nuevo siguiente" apunta a NULL
			
			*final = nuevo;					//El final de nuestra bicola apunta al nuevo espacio de memoria.
			
			nuevo->valor = numero;				//A la variable "nuevo valor" se le asigna el valor de "numero" (parámetro de la función main).
		}
	
	return numero; 
	fflush(stdin);
	
}


/* --------------------------------------------------------------------
NOMBRE: Función borrar_inicio
TIPO: int
PARÁMETROS: inicio: Apuntador a inicio de la bicola
DESCRIPCIÓN: Función que elimina un elemento al inicio de una bicola.
-------------------------------------------------------------------- */
int borrar_inicio(pInicio *inicio, pFinal *final) {
	
   pNodo auxiliar; 		//Variable de tipo apuntador a una estructura (pNodo)llamada "auxiliar".
   
   auxiliar = *inicio;	//auxiliar apunta al primer elemento de la bicola.
   
   if (bicola_vacia(*inicio) == 0){ 		//Si no hay nodos en la bicola.
   
   		printf("\n\tLa bicola est%c vac%ca.\n\n", 160, 161);
   
   } else {
	   	if((*inicio)->siguiente == NULL && (*inicio)->anterior == NULL){
			*inicio = NULL;
			*final = NULL;
		} else {
	   		*inicio = (*inicio)->siguiente;			//Asignamos a inicio "inicio siguiente".
	   		(*inicio)->anterior = NULL;				//Inicio anterior apunta a NULL.
		}
	return auxiliar->valor;
	}
   free(auxiliar);						//Borrar el nodo.
}
 

/* --------------------------------------------------------------------
NOMBRE: Función borrar_final
TIPO: int
PARÁMETROS: final: Apuntador a final de la bicola
DESCRIPCIÓN: Función que elimina un elemento al final de una bicola.
-------------------------------------------------------------------- */
int borrar_final(pFinal *final, pInicio *inicio) {
	
   pNodo auxiliar; 		//Variable de tipo apuntador a una estructura (pNodo)llamada "auxiliar".
   
   auxiliar = *final;	//auxiliar apunta al último elemento de la bicola.
   
   if (bicola_vacia(*inicio) == 0){ 		//Si no hay nodos en la bicola.
   
   		printf("\n\tLa bicola est%c vac%ca.\n\n", 160, 161);
   
   } else {
		if((*final)->siguiente == NULL && (*final)->anterior == NULL){
			*inicio = NULL;
			*final = NULL;
		} else {
			*final = (*final)->anterior;			//Asignamos a final "final anterior".
			(*final)->siguiente = NULL;			//Final siguiente apunta a NULL.	
		}
	   return auxiliar->valor;
	}
   free(auxiliar);						//Borrar el nodo.
}


/* --------------------------------------------------------------------
NOMBRE: función ver_inicio
TIPO:  void
PARÁMETROS: inicio:	Apuntador de tipo int que contiene un elemento de la bicola.
DESCRIPCIÓN: Función que muestra el elemento inicial de la bicola.
-------------------------------------------------------------------- */
void ver_inicio (pInicio inicio) {
	
	if (bicola_vacia(inicio) == 1){
		
	printf("\n\nEl elemento que se encuentra al inicio de la bicola es: [%d]\n\n\n", inicio->valor);
	
	} else {
		
	printf("\n\tNo hay elementos en la bicola.");
	
	}	
}


/* --------------------------------------------------------------------
NOMBRE: función ver_final
TIPO:  void
PARÁMETROS: final:	Apuntador de tipo int que contiene un elemento de la bicola.
DESCRIPCIÓN: Función que muestra el elemento final de la bicola.
-------------------------------------------------------------------- */
void ver_final (pFinal final, pInicio inicio) {
	
	if (bicola_vacia(inicio) == 1){
		
	printf("\n\nEl elemento que se encuentra al final de la bicola es: [%d]\n\n\n", final->valor);
	
	} else {
		
	printf("\n\tNo hay elementos en la bicola.");
	
	}	
}


/* --------------------------------------------------------------------
NOMBRE: ver_bicola
TIPO: void
ARGUMENTOS: inicio: de tipo apuntador a elemntos pInicio.
DESCRIPCIÓN: Función que muestra los elementos de una bicola.
-------------------------------------------------------------------- */
void ver_bicola(pInicio inicio){
	
	pNodo auxiliar = inicio;					//la variable auxiliar guarda la estrucutura inicio.
	
	if(bicola_vacia(inicio) == 0){ 					//si la bicola está vacía.
	
		fprintf(stderr, "\n\n\t   La bicola est%c vac%ca", 160, 161);
	
	} else {
		
		printf("\n\n\t\tBicola: ");
		  
		do{
			printf(" [ %d ] ", auxiliar->valor);   		//Imprime el valor
			auxiliar = auxiliar->siguiente;				//Cambia valor al siguiente
	    }while (auxiliar != NULL);				//Mientras no apunte a NULL hacer...
    }
    
	free(auxiliar);	  								//Liberar variable 
}


/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
PARÁMETROS: N/A
DESCRIPCIÓN: Función que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
int main (){
	
	pInicio inicio = NULL;		//Variable llamada inicio, de tipo pinicio (apuntador a estructura tipoNodo) que apunta a NULL.
    pFinal final = NULL;		//Variable llamada inicio, de tipo pFinal (apuntador a estructura tipoNodo) que apunta a NULL.
   	int eNumero;				//Valor ingresado por el usuario
	int eOpcion; 				//Variable que permitirá seleccionar una opción del menú.

	do { 				//Ciclo repetir-hasta para que se muestre el menú principal cada vez que se desee.
	
		system("cls");			//Limpiar pantalla
		
		printf("\n\n\t\t------- BICOLA -------\n");
		printf("\t\t        MEN%C\n\n", 233);
    	printf("\t\t   %c %c Agregar\n", 175, 175);
    	printf("\t\t\t  %c 1. Al inicio\n", 254);
    	printf("\t\t\t  %c 2. Al final\n", 254);
    	printf("\t\t   %c %c Borrar\n", 175, 175);
    	printf("\t\t\t  %c 3. Al inicio\n", 254);
    	printf("\t\t\t  %c 4. Al final\n", 254);
	    printf("\t\t   %c %c Ver\n", 175, 175);
	    printf("\t\t\t  %c 5. Inicio\n", 254);
	    printf("\t\t\t  %c 6. Final\n\n", 254);
	    printf("\t\t\t  %c 7. Bicola completa\n\n", 254);
	    printf("\t\t   %c 0. Salir", 175, 175);
	    
	    printf("\n\nIntroduzca el n%cmero de la acci%cn que deseas realizar: ", 163, 162);
    	scanf("%d", &eOpcion); 		//Leer variable eOpcion.
    	
    	system("cls");				//Limpiar pantalla.
    	
    	switch(eOpcion){ 			//En caso de eOpcion... , hacer...
    	
		//AGREGAR------------------------------------------------------------------------------	
    		case 1:	printf("\n\t\t%cQu%c n%cmero deseas insertar a la bicola? ", 168, 130, 163);
   					scanf("%d", &eNumero);
   					printf("\n\t\tSE AGREG%c AL INICIO: [ %d ]\n\n\n", 224, agregar_inicio(&inicio, &final, eNumero));		//Se manda a llamar a la función agregar inicio.
					fflush(stdin);
   					system("pause");
				break;
			
			case 2: printf("\n\t\t%cQu%c n%cmero deseas insertar a la bicola? ", 168, 130, 163);
   					scanf("%d", &eNumero);
   					printf("\n\t\tSE AGREG%c AL FINAL: [ %d ]\n\n\n", 224, agregar_final(&inicio, &final, eNumero));		//Se manda a llamar a la función agregar final.
					fflush(stdin);
   					system("pause");
				break;
		
		//BORRAR------------------------------------------------------------------------------	
			case 3: printf("\n\n\tBorrar inicio:  [%d]\n\n\n", borrar_inicio(&inicio, &final));	//Se manda a llamar la función borrar_inicio.
					fflush(stdin);
   					system("pause");
				break;
				
			case 4: printf("\n\n\tBorrar final:  [%d]\n\n\n", borrar_final(&final, &inicio));	//Se manda a llamar la función borrar_final.
					fflush(stdin);
   					system("pause");
    			break;
		
		//VER ---------------------------------------------------------------------------------
    		case 5: ver_inicio (inicio);					//Se manda a llamar la función ver_inicio.
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
			
			case 6: ver_final (final, inicio);				//Se manda a llamar la función ver_final.
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
				
    		case 7: ver_bicola(inicio);						//Se manda a llamar la función ver_bicola.
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
