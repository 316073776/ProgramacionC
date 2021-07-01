/* **********************************************************************
NOMBRE DEL PROGRAMA: ListasCircularesSimples.c
OBJETIVO: Probar las funciones de las listas.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 10/10/2019
********************************************************************** */
//LIBRER�AS
#include <stdio.h>
#include <stdlib.h>


/*ESTRUCTURAS---------------
Estructrura "tipoNodo" que contiene dos elementos.
informaci�n: tipo int
liga: tipo apuntador a estructura nodo.
----------------------------*/
typedef struct nodo {			//Define estructura llamada nodo para que se pueda apuntar a la estructura
   int informacion;					
   struct nodo *liga;			//Apuntador (llamado liga) a estructura nodo.
} tipoNodo;						//Nombre de la estructura = tipoNodo
 
 
/*----------------------------
Declaraci�n de tipo de dato:
pNodo: Apuntador a tipoNodo.
----------------------------*/
typedef tipoNodo *pNodo;		//Tipo de dato pNodo que es apuntador a una estructura "tipoNodo"

/* --------------------------------------------------------------------
NOMBRE: Funci�n CreaInicio
TIPO: void
PAR�METROS: P - Apuntador tipo pNodo al inicio de la lista.
			F - Apuntador al Final de la lista.
DESCRIPCI�N: Crea una lista y agrega elementos al inicio..
-------------------------------------------------------------------- */
void CreaInicio(pNodo *P, pNodo *F){
	
	pNodo Q;										
	char cContinuar;
	
	*P = (pNodo) malloc(sizeof(pNodo));				//Crea P - Primer nodo de la lista.
	printf("\n\n\tIngrese NODO INICIAL: ");
	scanf("%d", &(*P)->informacion);				//Leer P -> informaci�n.
	*F = *P;											//Igualar final a inicio.
	(*P)->liga = *F;
	
	do{
		Q = (pNodo) malloc(sizeof(pNodo));				//Crea Q
		printf("\n\tIngrese NODO: ");
		scanf("%d", &(Q->informacion));					//Leer Q -> informaci�n.
		Q->liga = *P;									//Hacer que Q -> liga apunte a inicio.
		*P = Q;											//Igualar P a Q para cambiar el inicio.
		(*F)->liga = *P;									//Final->liga apunta al inicio
		printf("\n\t%cDesea continuar? ", 168);
		fflush (stdin);
		cContinuar = getchar();
	} while (cContinuar != 'n');						//Hasta que el usuario salga.
	
}

/* --------------------------------------------------------------------
NOMBRE: Funci�n CreaFinal
TIPO: void
PAR�METROS: P - Apuntador tipo pNodo al inicio de la lista.
			F - Apuntador al Final de la lista.
DESCRIPCI�N: Crea una lista y agrega elementos al final.
-------------------------------------------------------------------- */
void CreaFinal(pNodo *P, pNodo *F){
	pNodo Q;
	char cContinuar;
	
	*P = (pNodo) malloc(sizeof(pNodo));				//Crea P - Primer nodo de la lista.
	printf("\n\n\tIngrese NODO INICIAL: ");
	scanf("%d", &(*P)->informacion);				//Leer P -> informaci�n.
	*F = *P;											//Final apunta al inicio.
	(*P)->liga = *F;
	
	do{
		Q = (pNodo) malloc(sizeof(pNodo));				//Crea Q
		printf("\n\tIngrese NODO: ");
		scanf("%d", &(Q->informacion));					//Leer Q -> informaci�n.
		(*F)->liga = Q;									//F->liga apunta a Q.
		Q->liga = *P;									//Hacer que Q -> liga apunte al inicio.
		*F = Q;											//Igualar F a Q.
		printf("\n\t%cDesea continuar? ", 168);
		fflush (stdin);
		cContinuar = getchar();
	} while (cContinuar != 'n');						//Hasta que el usuario salga.
}

/* --------------------------------------------------------------------
NOMBRE: Funci�n RecorreIterativo
TIPO: void
PAR�METROS: P - Apuntador tipo pNodo al inicio de la lista. 
DESCRIPCI�N: Recorre la lista de forma iterativa y la imprime.
-------------------------------------------------------------------- */
void RecorreIterativo (pNodo P){
	pNodo Q;
	
	Q = P;										//Q apunta al inicio de la lista.
	printf("\n\n\tLISTA: ");
	
	do{
		
		printf(" [%d] ", Q->informacion);		//Imprime Q->informacion.
		Q = Q->liga;							//Apuntar al siguiente nodo de la lista
			
	} while( Q != P );							//Hasta que Q sea diferente del inicio.
}

/* --------------------------------------------------------------------
NOMBRE: Funci�n RecorreRecursivo
TIPO: void
PAR�METROS: P - Apuntador tipo pNodo al inicio de la lista. 
DESCRIPCI�N: Recorre la lista de forma recursiva y la imprime.
-------------------------------------------------------------------- */
void RecorreRecursivo(pNodo P, pNodo F){						
	
	if ( P != F ){								//Si el inicio es diferente de NULL.
		printf(" [%d] ", P->informacion);
		if(P->liga == F){
			printf(" [%d]", F->informacion);
		}
		RecorreRecursivo (P->liga, F);
	}
}

/* --------------------------------------------------------------------
NOMBRE: InsetaFinal
TIPO: void
PAR�METROS: P - Apuntador tipo pNodo al inicio de la lista. 
			F - Apuntador al Final de la lista.
DESCRIPCI�N: Inserta un nodo al final de la lista.
-------------------------------------------------------------------- */
void InsertaFinal(pNodo P, pNodo *F){
	
	pNodo Q;
	
	Q = (pNodo) malloc(sizeof(pNodo));			//Crea Q
	printf("\n\n\tIngrese un nodo: ");
	scanf("%d", &(Q->informacion));				
	Q->liga = P;								//Q->liga apunta a NULL.
	(*F)->liga = Q;								//F->liga apunta al nuevo nodo (Q).
	*F = Q;										//F apunta al nuevo nodo.
	printf("\n\tSe agreg%c [%d] al final de la lista.", 162, Q->informacion);
}

/* --------------------------------------------------------------------
NOMBRE: InsertaAntes
TIPO: void
PAR�METROS: P - Apunta al inicio de la lista.
			F - Apuntador al Final de la lista.
			REF - Inserta antes de: 
DESCRIPCI�N: Insertar antes de un elemento ingresado por el usuario.
-------------------------------------------------------------------- */
void InsertaAntes(pNodo *P, pNodo *F, int REF){	
	
	pNodo Q, T, X;
	int BAND;			//Bandera
	
	Q = *P;				//Q apunta al inicio de la lista.
	BAND = 1;			//Verdadero
	
	while( Q->informacion != REF && BAND == 1){		//Mientras Q->informaci�n sea diferente del n�mero ingresado y Bandera sea verdadera.
		if (Q->liga != *P){				
			T = Q;							//T apunta a Q.
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
			*P = X;									//Se cambia el inicio
			(*F)->liga = *P;
		} else {
			T->liga = X;
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
PAR�METROS: P - Apunta al inicio de la lista.
			F - Apuntador al Final de la lista. 
DESCRIPCI�N: Funci�n que borra el primer elmento de la lista.
-------------------------------------------------------------------- */
void EliminaPrimero(pNodo *P, pNodo *F){
	pNodo Q;
	
	Q = *P;							//Q apunta al inicio.
	
	if ( Q->liga != NULL ){ 		//Si la lista tiene m�s de un nodo
		*P = Q->liga;				//Redefine inicio.
		(*F)->liga = *P;
	} else {						//Si s�lo hay un nodo
		*P = NULL;
	}
	printf("\n\n\tSe elimin%c [%d] de la lista.", 162, Q->informacion);
	free(Q);
}

/* --------------------------------------------------------------------
NOMBRE: EliminaUltimo
TIPO: void
PAR�METROS: P - Apuntador al primer elemento de la lista. 
			F - Apuntador al Final de la lista.
DESCRIPCI�N: Elimina el �ltimo nodo de la lista.
-------------------------------------------------------------------- */
void EliminaUltimo(pNodo P, pNodo *F){
	pNodo Q, T;
	
	if ( P->liga == P){		//Si la lista tiene un s�lo elemento.
		free(P);				//Libera P.
		P = NULL;					
	} else {					//Si hay m�s de un elemento.
		Q = P;					//Q apunta al inicio.
		while ( Q->liga != P ){		
			T = Q;						
			Q = Q->liga;				//Se recorre la lista hasta el final
		}
		T->liga = P;
		*F = T;
		printf("\n\n\tSe elimin%c [%d] de la lista.", 162, Q->informacion);
		free(Q);
	}
	
}

/* --------------------------------------------------------------------
NOMBRE: EliminaX 
TIPO: void
PAR�METROS: P - Apunta al inicio de la lista.
			F - Apuntador al Final de la lista.
			X - Valor a eliminar, ingresado por el usuario. 
DESCRIPCI�N:  Eliminar un nodo con informaci�n X de una lista.
-------------------------------------------------------------------- */
void EliminaX(pNodo *P, pNodo *F, int X){
	pNodo Q, T;
	int BAND;
	
	Q = *P;			//Q apunta al inicio de la lista.
	BAND = 1;		//Verdadero.
	
	while ( Q->informacion != X && BAND == 1){			//Mientras Q->informacion sea diferente del num. ingresado y la bandera sea verdadera.
		if (Q->liga != *P){
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
			(*F)->liga = *P;
		} else {
			T->liga = Q->liga;
			if (Q == *F){
				*F = T;
				(*F)->liga = *P;
			}
		}
		printf("\n\n\tSe elimin%c el elemento [%d] de la lista.", 162, Q->informacion);
		free (Q);
	}
}

/* --------------------------------------------------------------------
NOMBRE: BuscaRecursivo
TIPO: void
PAR�METROS: P - apunta al inicio de la lista.
			X - Elemento a buscar.
DESCRIPCI�N: Buscar recursivamente un elemento X en una lista desordenada.
-------------------------------------------------------------------- */
void BuscaRecursivo(pNodo P, int X){									
	if (P != NULL){ 														//Si hay elementos en la lista
		if ( P->informacion == X){											//Si es igual al elemento a buscar.
			printf("\n\n\tEl elemento [%d] si se encuentra en la lista.\n", P->informacion);
		} else {
			if( P->liga == P){
				printf("\n\n\tEl elemento [%d] no se encuentra en la lista.\n", X);
			} else {
				BuscaRecursivo(P->liga, X);
			}
		}
	} else {
		printf ("\n\n\tLista vac%ca.\n", 161);
	}
}

/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
PAR�METROS: N/A
DESCRIPCI�N: Funci�n que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
int main (){
	
	pNodo Inicio = NULL;
	pNodo Final = NULL;
	int eOpcion, eDato;
	
	do { 				//Ciclo repetir-hasta para que se muestre el men� principal cada vez que se desee.
	
		system("cls");			//Limpiar pantalla
		
		printf("\n\n\t\t------- LISTAS -------\n");
		printf("\t\t         MEN%C\n\n", 233);
    	printf("\t\t\t  %c 1. Crea Inicio\n", 254);
    	printf("\t\t\t  %c 2. Crea Final\n", 254);
    	printf("\t\t\t  %c 3. Recorre Iterativo\n", 254);
    	printf("\t\t\t  %c 4. Recorre Recursivo\n", 254);
	    printf("\t\t\t  %c 5. Inserta Final\n", 254);
	    printf("\t\t\t  %c 6. Inserta Antes\n", 254);
	    printf("\t\t\t  %c 7. Elimina Primero\n", 254);
	    printf("\t\t\t  %c 8. Elimina %cltimo\n", 254, 233);
	    printf("\t\t\t  %c 9. Elimina X\n", 254);
	    printf("\t\t\t  %c 10. Busca Recursivo\n\n", 254);
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
		
			case 3: RecorreIterativo(Inicio);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
				break;
				
			case 4: printf("\n\n\tLISTA: ");
					RecorreRecursivo(Inicio, Final);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
		
    		case 5: InsertaFinal(Inicio, &Final);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
			
			case 6: printf("\n\n\tInsertar antes de: ");
					scanf("%d", &eDato);
					InsertaAntes(&Inicio, &Final, eDato);
					printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break; 
				
    		case 7: EliminaPrimero(&Inicio, &Final);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
   				break;
   					
   			case 8: EliminaUltimo(Inicio, &Final);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
   				break;
				   	
   			case 9: printf("\n\n\t%cQu%c elemento deseas eliminar? ", 168, 130);
					scanf("%d", &eDato);
			   		EliminaX(&Inicio, &Final, eDato);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
   				break;
				   	
   			case 10:printf("\n\n\t%cQu%c elemento deseas buscar? ", 168, 130);
					scanf("%d", &eDato); 
			   		BuscaRecursivo(Inicio, eDato);
    				printf("\n\n");
					fflush(stdin);
   					system("pause");
    			break;
    			
    		default:if (eOpcion > 10){
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

