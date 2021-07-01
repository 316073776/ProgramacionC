/* **********************************************************************
NOMBRE DEL PROGRAMA: ListasDoblementeLigadas.c
OBJETIVO: Probar las funciones de las listas.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 17/10/2019
********************************************************************** */
//LIBRERÍAS
#include <stdio.h>
#include <stdlib.h>


/*ESTRUCTURAS---------------
Estructrura "tipoNodo" que contiene dos elementos.
informacion: tipo int
liga: tipo apuntador a estructura nodo.
ligaAnterior: tipo apuntador a estructura nodo.
----------------------------*/
typedef struct nodo {			//Define estructura llamada nodo para que se pueda apuntar a la estructura
   int informacion;					
   struct nodo *liga;			//Apuntador (llamado liga) a estructura nodo.
   struct nodo *ligaAnterior;	//Apuntador (llamado ligaAnterior) a estructura nodo.
} tipoNodo;						//Nombre de la estructura = tipoNodo
 
 
/*----------------------------
Declaración de tipo de dato:
pNodo: Apuntador a tipoNodo.
----------------------------*/
typedef tipoNodo *pNodo;		//Tipo de dato pNodo que es apuntador a una estructura "tipoNodo"

/* --------------------------------------------------------------------
NOMBRE: Función CreaInicio
TIPO: void
PARÁMETROS: P - Apuntador tipo pNodo al inicio de la lista.
			F - Apuntador tipo pNodo al final de la lista.
DESCRIPCIÓN: Crea una lista y agrega elementos al inicio..
-------------------------------------------------------------------- */
void CreaInicio(pNodo *P, pNodo *F){
	
	pNodo Q;										
	char cContinuar;
	
	*P = (pNodo) malloc(sizeof(pNodo));				//Crea P - Primer nodo de la lista.
	printf("\n\n\tIngrese NODO INICIAL: ");
	scanf("%d", &(*P)->informacion);				//Leer P -> información.
	(*P)->liga = NULL;								//Hacer que P -> liga apunte a  NULL.
	(*P)->ligaAnterior = NULL;						//Hacer que P -> ligaAnterior apunte a  NULL.
	*F = *P;
	
	do{
		Q = (pNodo) malloc(sizeof(pNodo));				//Crea Q
		printf("\n\tIngrese NODO: ");
		scanf("%d", &(Q->informacion));					//Leer Q -> información.
		Q->liga = *P;									//Hacer que Q -> liga apunte a  P.
		Q->ligaAnterior = NULL;
		(*P)->ligaAnterior = Q;
		*P = Q;											//Igualar P a Q para cambiar el inicio.
		printf("\n\t%cDesea continuar? ", 168);
		fflush (stdin);
		cContinuar = getchar();
	} while (cContinuar != 'n');						//Hasta que el usuario salga.
	
}

/* --------------------------------------------------------------------
NOMBRE: Función CreaFinal
TIPO: void
PARÁMETROS: P - Apuntador tipo pNodo al inicio de la lista.
			F - Apuntador tipo pNodo al final de la lista.
DESCRIPCIÓN: Crea una lista y agrega elementos al final.
-------------------------------------------------------------------- */
void CreaFinal(pNodo *P, pNodo *F){
	pNodo Q, T;
	char cContinuar;
	
	*P = (pNodo) malloc(sizeof(pNodo));				//Crea P - Primer nodo de la lista.
	printf("\n\n\tIngrese NODO INICIAL: ");
	scanf("%d", &(*P)->informacion);				//Leer P -> información.
	(*P)->liga = NULL;								//Hacer que P->liga apunte a  NULL.
	(*P)->ligaAnterior = NULL;						//Hacer que P -> ligaAnterior apunte a  NULL.
	T = *P;											//T apunta al inicio.
	
	do{
		Q = (pNodo) malloc(sizeof(pNodo));				//Crea Q
		printf("\n\tIngrese NODO: ");
		scanf("%d", &(Q->informacion));					//Leer Q -> información.
		Q->liga = NULL;									//Hacer que Q -> liga apunte a  NULL.
		Q->ligaAnterior = T;
		T->liga = Q;									//T->liga apunta a Q.
		T = Q;											//Igualar T a Q.
		*F = Q;
		printf("\n\t%cDesea continuar? ", 168);
		fflush (stdin);
		cContinuar = getchar();
	} while (cContinuar != 'n');						//Hasta que el usuario salga.
}

/* --------------------------------------------------------------------
NOMBRE: Función RecorreIterativoInicio
TIPO: void
PARÁMETROS: P - Apuntador tipo pNodo al inicio de la lista. 
DESCRIPCIÓN: Recorre la lista de forma iterativa y la imprime.
-------------------------------------------------------------------- */
void RecorreIterativoInicio (pNodo P){
	pNodo Q;
	
	Q = P;										//Q apunta al inicio de la lista.
	printf("\n\n\tLISTA: ");
	
	do{
		
		printf(" [%d] ", Q->informacion);		//Imprime Q->informacion.
		Q = Q->liga;							//Apuntar al siguiente nodo de la lista
			
	} while( Q != NULL );
}

/* --------------------------------------------------------------------
NOMBRE: Función RecorreIterativoFinal
TIPO: void
PARÁMETROS: F - Apuntador tipo pNodo al final de la lista. 
DESCRIPCIÓN: Recorre la lista de forma iterativa y la imprime.
-------------------------------------------------------------------- */
void RecorreIterativoFinal (pNodo F){
	pNodo Q;
	
	Q = F;										//Q apunta al final de la lista.
	printf("\n\n\tLISTA: ");
	
	do{
		
		printf(" [%d] ", Q->informacion);		//Imprime Q->informacion.
		Q = Q->ligaAnterior;					//Apuntar al siguiente nodo de la lista
			
	} while( Q != NULL );
}

/* --------------------------------------------------------------------
NOMBRE: Función RecorreRecursivoInicio
TIPO: void
PARÁMETROS: P - Apuntador tipo pNodo al inicio de la lista. 
DESCRIPCIÓN: Recorre la lista de forma recursiva y la imprime.
-------------------------------------------------------------------- */
void RecorreRecursivoInicio(pNodo P){
	
	if ( P != NULL ){								//Si el inicio es diferente de NULL.
		printf(" [%d] ", P->informacion);
		RecorreRecursivoInicio (P->liga);
	}
}

/* --------------------------------------------------------------------
NOMBRE: Función RecorreRecursivoFinal
TIPO: void
PARÁMETROS: F - Apuntador tipo pNodo al final de la lista. 
DESCRIPCIÓN: Recorre la lista de forma recursiva y la imprime.
-------------------------------------------------------------------- */
void RecorreRecursivoFinal(pNodo F){
	
	if ( F != NULL ){								//Si el inicio es diferente de NULL.
		printf(" [%d] ", F->informacion);
		RecorreRecursivoFinal (F->ligaAnterior);
	}
}

/* --------------------------------------------------------------------
NOMBRE: InsetaFinal
TIPO: void
PARÁMETROS: P - Apuntador tipo pNodo al inicio de la lista. 
DESCRIPCIÓN: Inserta un nodo al final de la lista.
-------------------------------------------------------------------- */
void InsertaFinal(pNodo *F){
	
	pNodo Q, T;
	
	T = *F;
	Q = (pNodo) malloc(sizeof(pNodo));			//Crea Q
	printf("\n\n\tIngrese un nodo: ");
	scanf("%d", &(Q->informacion));				
	Q->liga = NULL;								//Q->liga apunta a NULL.
	Q->ligaAnterior = T;
	*F = Q;
	T->liga = Q;								//T->liga apunta al nuevo nodo (Q).
	printf("\n\tSe agreg%c [%d] al final de la lista.", 162, Q->informacion);
}

/* --------------------------------------------------------------------
NOMBRE: InsertaAntes
TIPO: void
PARÁMETROS: P - Apunta al inicio de la lista.
			REF - Inserta antes de: 
DESCRIPCIÓN: Insertar antes de un elemento ingresado por el usuario.
-------------------------------------------------------------------- */
void InsertaAntes(pNodo *P, int REF){
	
	pNodo Q, X;
	int BAND;			//Bandera
	
	Q = *P;				//Q apunta al inicio de la lista.
	BAND = 1;			//Verdadero
	
	while( Q->informacion != REF && BAND == 1){		//Mientras Q->información sea diferente del número ingresado y Bandera sea verdadera.
		if (Q->liga != NULL){				
			Q = Q->liga;					//Q se recorre al siguiente nodo.
		} else {							//Se recorre toda la lista.
			BAND = 0;
		}
	} 
	
	if (BAND == 1){
		X = (pNodo) malloc(sizeof(pNodo));			//Crea X
		printf("\n\n\tIngrese un nodo: ");
		scanf("%d", &(X->informacion));
		if (*P == Q){								//Si Q apunta al inicio
			X->liga = *P;
			X->ligaAnterior = NULL;
			(*P)->ligaAnterior = X;							
			*P = X;									//Se cambia el inicio
		} else {
			X->ligaAnterior = Q->ligaAnterior;
			(Q->ligaAnterior)->liga = X;
			Q->ligaAnterior = X;
			X->liga = Q;
		}
		printf("\n\tSe agreg%c [%d] antes de [%d]", 162, X->informacion, REF);
	} else { 
		printf("\n\nNo se encontr%c el nodo ingresado.", 162);
	}
}

/* --------------------------------------------------------------------
NOMBRE: EliminaPrimero
TIPO: void
PARÁMETROS: P - Apunta al inicio de la lista. 
DESCRIPCIÓN: Función que borra el primer elmento de la lista.
-------------------------------------------------------------------- */
void EliminaPrimero(pNodo *P){
	pNodo Q;
	
	Q = *P;							//Q apunta al inicio.
	
	if ( Q->liga != NULL ){ 		//Si la lista tiene más de un nodo
		*P = Q->liga;				//Redefine inicio.
		(*P)->ligaAnterior = NULL;
	} else {						//Si sólo hay un nodo
		*P = NULL;
	}
	printf("\n\n\tSe elimin%c [%d] de la lista.", 162, Q->informacion);
	free(Q);
}

/* --------------------------------------------------------------------
NOMBRE: EliminaUltimo
TIPO: void
PARÁMETROS: P - Apuntador al primer elemento de la lista. 
DESCRIPCIÓN: Elimina el último nodo de la lista.
-------------------------------------------------------------------- */
void EliminaUltimo(pNodo P, pNodo *F){
	pNodo Q;
	
	if ( P->liga == NULL){		//Si la lista tiene un sólo elemento.
		free(P);				//Libera P.
		P = NULL;					
	} else {					//Si hay más de un elemento.
		Q = *F;					//Q apunta al final.
		*F = (*F)->ligaAnterior;
		(*F)->liga = NULL;
		printf("\n\n\tSe elimin%c [%d] de la lista.", 162, Q->informacion);
		free(Q);
	}
	
}

/* --------------------------------------------------------------------
NOMBRE: EliminaX 
TIPO: void
PARÁMETROS: P - Apunta al inicio de la lista.
			X - Valor a eliminar, ingresado por el usuario. 
DESCRIPCIÓN:  Eliminar un nodo con información X de una lista.
-------------------------------------------------------------------- */
void EliminaX(pNodo *P, pNodo *F, int X){
	pNodo Q, T;
	int BAND;
	
	Q = *P;			//Q apunta al inicio de la lista.
	BAND = 1;		//Verdadero.
	
	while ( Q->informacion != X && BAND == 1){			//Mientras Q->informacion sea diferente del num. ingresado y la bandera sea verdadera.
		if (Q->liga != NULL){
			T = Q;
			Q = Q->liga;				//Se recorre la lista.
		} else {
			BAND = 0;
		}
	}
	
	if (BAND == 0){
		printf("\n\n\tEl elemento no se encontr%c.", 162);
	} else {
		if ( *P == Q ){			//Si el elemento a eliminar es el primero.
			*P = Q->liga;			//Se cambia el inicio.
			(*P)->ligaAnterior = NULL;
		} else {
			if(Q == *F){
				*F = (*F)->ligaAnterior;
			} else {
				T->liga = Q->liga;
			}
		}
		printf("\n\n\tSe elimin%c el elemento [%d] de la lista.", 162, Q->informacion);
		free (Q);
	}
}

/* --------------------------------------------------------------------
NOMBRE: BuscaRecursivo
TIPO: void
PARÁMETROS: P - apunta al inicio de la lista.
			X - Elemento a buscar.
DESCRIPCIÓN: Buscar recursivamente un elemento X en una lista desordenada.
-------------------------------------------------------------------- */
void BuscaRecursivo(pNodo P, int X){
	if (P != NULL){ 										//Si hay elementos en la lista
		if ( P->informacion == X){							//Si es igual al elemento a buscar.
			printf("\n\n\tEl elemento [%d] si se encuentra en la lista.\n", P->informacion);
		} else {
			BuscaRecursivo(P->liga, X);
		}
	} else {
		printf ("\n\n\tNo se encuentra el elemento a buscar.\n");
	}
}
/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
PARÁMETROS: N/A
DESCRIPCIÓN: Función que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
int main (){
	
	pNodo Inicio = NULL;
	pNodo Final = NULL;
	int eOpcion, eDato;
	
	do { 				//Ciclo repetir-hasta para que se muestre el menú principal cada vez que se desee.
	
		system("cls");			//Limpiar pantalla
		
		printf("\n\n\t\t------- LISTAS -------\n");
		printf("\t\t         MEN%C\n\n", 233);
    	printf("\t\t\t  %c 1. Crea Inicio\n", 254);
    	printf("\t\t\t  %c 2. Crea Final\n", 254);
    	printf("\n\t\t        - Recorre Iterativo -\n");
    	printf("\t\t\t  %c 3. Por el Inicio\n", 254);
    	printf("\t\t\t  %c 4. Por el Final\n", 254);
    	printf("\n\t\t        - Recorre Recursivo -\n");
    	printf("\t\t\t  %c 5. Por el Inicio\n", 254);
    	printf("\t\t\t  %c 6. Por el Final\n\n", 254);
	    printf("\t\t\t  %c 7. Inserta Final\n", 254);
	    printf("\t\t\t  %c 8. Inserta Antes\n", 254);
	    printf("\t\t\t  %c 9. Elimina Primero\n", 254);
	    printf("\t\t\t  %c 10. Elimina %cltimo\n", 254, 233);
	    printf("\t\t\t  %c 11. Elimina X\n", 254);
	    printf("\t\t\t  %c 12. Busca Recursivo\n\n", 254);
	    printf("\t\t   %c 0. Salir", 175, 175);
	    
	    printf("\n\nIntroduzca el n%cmero de la acci%cn que deseas realizar: ", 163, 162);
    	scanf("%d", &eOpcion); 		//Leer variable eOpcion.
    	
    	system("cls");				//Limpiar pantalla.
    	
    	switch(eOpcion){ 			//En caso de eOpcion... , hacer...
    	
    		case 1:	CreaInicio(&Inicio, &Final);
    				printf("\n\n");
    				fflush(stdin);
   					system("pause");
				break;
			
			case 2: CreaFinal(&Inicio, &Final);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
		
			case 3: RecorreIterativoInicio(Inicio);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
				
			case 4: RecorreIterativoFinal(Final);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
				
			case 5: printf("\n\n\tLISTA: ");
					RecorreRecursivoInicio(Inicio);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
    			
    		case 6: printf("\n\n\tLISTA: ");
					RecorreRecursivoFinal(Final);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
		
    		case 7: InsertaFinal(&Final);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
			
			case 8: printf("\n\n\tInsertar antes de: ");
					scanf("%d", &eDato);
					InsertaAntes(&Inicio, eDato);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
				
    		case 9: EliminaPrimero(&Inicio);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
   				break;
   					
   			case 10:EliminaUltimo(Inicio, &Final);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
   				break;
				   	
   			case 11: printf("\n\n\t%cQu%c elemento deseas eliminar? ", 168, 130);
					scanf("%d", &eDato);
			   		EliminaX(&Inicio, &Final, eDato);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
   				break;
				   	
   			case 12:printf("\n\n\t%cQu%c elemento deseas buscar? ", 168, 130);
					scanf("%d", &eDato); 
			   		BuscaRecursivo(Inicio, eDato);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
    			
    		default:if (eOpcion > 12){
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
