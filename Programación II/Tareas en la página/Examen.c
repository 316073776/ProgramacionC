/*
NOMBRE DEL PROGRAMA: Segura Rios.c
OBJETIVO: Examen
AUTOR: Segura Rios Brenda Stephanie
FECHA: 21/10/2019
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {			//Define estructura llamada nodo para que se pueda apuntar a la estructura
   int informacion;					
   struct nodo *liga;			//Apuntador (llamado liga) a estructura nodo.
} tipoNodo;

typedef tipoNodo *pNodo;


/*
NOMBRE: InsertaNodo
TIPO: void
PARÁMETROS: Inicio - Apunta al inicio de la lista.
DESCRIPCIÓN: Inserta un nodo a la lista
*/
void InsertaNodo(pNodo *Inicio){
	
	pNodo Nuevo, Aux1, Aux2;		
	int BANDERA;								
	char cContinuar;
	
	if (*Inicio == NULL){					//Si la lista está vacía
		*Inicio = (pNodo) malloc(sizeof(pNodo));
		printf ("Ingrese un n%cmero: ", 163);				
		scanf("%d", &(*Inicio)->informacion);				
		(*Inicio)->liga = NULL;	
		printf("\n\tSe agreg%c [%d] a la lista.\n\n", 162, (*Inicio)->informacion);	
							
	} else {								//De lo contrario
		Aux1 = *Inicio;
		BANDERA = 1;			//Verdadero
	
		Nuevo = (pNodo) malloc(sizeof(pNodo));
		printf ("Ingrese un n%cmero: ", 163);
		scanf("%d", &(Nuevo->informacion));				
		Nuevo->liga = NULL;
		
		while( Nuevo->informacion >= Aux1->informacion && BANDERA == 1){
			if (Aux1->liga != NULL){				
				Aux2 = Aux1;							
				Aux1 = Aux1->liga;					
			} else {							
				BANDERA = 0;
			}
		}
		
		if (BANDERA == 1){
			if (*Inicio == Aux1){					//Si el número va antes del inicio.								
				Nuevo->liga = *Inicio;							
				*Inicio = Nuevo;									
			} else {
				Aux2->liga = Nuevo;
				Nuevo->liga = Aux1;
			}	
		printf("\n\tSe agreg%c [%d] a la lista. \n\n", 162, Nuevo->informacion);
		} else {
			Aux1->liga = Nuevo;
			printf("\n\tSe agreg%c [%d] a la lista. \n\n", 162, Nuevo->informacion); 
		} 
	}	
}


/*
NOMBRE: Eliminar
TIPO: void
PARÁMETROS: Inicio - Apunta al inicio de la lista.
			Numero - Valor ingresado por el usuario.
DESCRIPCIÓN: Elimina un nodo de la lista.
*/
void Eliminar(pNodo *Inicio, int Numero){
	
	pNodo Aux1, Aux2;
	int BANDERA;
	
	Aux1 = *Inicio;			
	BANDERA = 1;		//Verdadero.
	
	while ( Aux1->informacion != Numero && BANDERA == 1){			//Mientras Aux1-Información sea diferente del num. ingresado y la bandera sea verdadera.
		if (Aux1->liga != NULL){
			Aux2 = Aux1;
			Aux1 = Aux1->liga;							//Se recorre la lista.
		} else {
			BANDERA = 0;
		}
	}
	
	if (BANDERA == 0){
		printf("\n\n\tEl n%cmero ingresado no se encontr%c.\n\n", 163,162);
	} else {
		if ( *Inicio == Aux1 ){			//Si el elemento a eliminar es el primero.
			*Inicio = Aux1->liga;			
		} else {
			Aux2->liga = Aux1->liga;
		}
		printf("\n\n\tSe elimin%c el elemento [%d] de la lista.\n\n", 162, Aux1->informacion);
		free (Aux1);
	}
}


/*
NOMBRE: Mostrar
TIPO: void
PARÁMETROS: Inicio - Apunta al inicio de la lista.
DESCRIPCIÓN: Muestra los elementos de la lista.
*/
void Mostrar (pNodo Inicio){
	
	pNodo Aux;
	
	Aux = Inicio;									
	printf("\n\n\tLISTA: ");
	
	do{
		
		printf(" [%d] ", Aux->informacion);		
		Aux = Aux->liga;						
			
	} while( Aux != NULL );   			//Recorre la lista.
	
	printf("\n\n");
}


/*
NOMBRE: main
TIPO: void
PARÁMETROS: N/A
DESCRIPCIÓN: Función que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
*/
void main (){
	
	pNodo Inicio = NULL;
	char cOpcion;
	int eDato;
	
	printf ("\n\n\tSegura Rios Brenda Stephanie");
	
	do { 								//Ciclo del menú		
	
		system("cls");			
	
		printf("\t\t         MEN%c\n\n", 233);
    	printf("\t\ta) Insertar nodo a la lista.\n", 254);
    	printf("\t\tb) Eliminar nodo de la lista.\n");
    	printf("\t\tc) Mostrar elementos de la lista.\n");
    	printf("\t\td) Salir.");

	    
	    printf("\n\nElija una opci%cn: ", 162);
    	cOpcion = getchar();
    	
    	system("cls");				
    	
    	switch(cOpcion){ 			//En caso de cOpcion... , hacer...
    	
    		case 'a':InsertaNodo (&Inicio);
    				fflush(stdin);  
					system("pause");
				break;
				
			case 'b':printf ("Ingrese un n%cmero a eliminar: ", 163);
					scanf("%d", &eDato);
					Eliminar (&Inicio, eDato);
    				fflush(stdin);  
					system("pause");
				break;

			case 'c':Mostrar (Inicio);
    				fflush(stdin);  
					system("pause");
				break;
    			
    		default:if (cOpcion > 'e'){
						printf("\n\n\t\tError en la selecci%cn\n\n", 162);
						fflush(stdin);  
						system("pause");
					}
				break; //Terminar el ciclo en caso de.
		}

	} while (cOpcion != 'd'); //Mientras la opción sea diferente de d, se seguirá mostrando el menú principal. 
	
	getchar (); 
     	    
}

