/* **********************************************************************
NOMBRE DEL PROGRAMA: ColaPrioridad.c
OBJETIVO: Crear una cola que permita ingresar prioridades
AUTOR: Segura Rios Brenda Stephanie
FECHA: 19/09/2019
********************************************************************** */
//LIBRER�AS
#include <stdio.h>
#include <stdlib.h>

/*ESTRUCTURAS---------------
Estructura "tipoPNodo" que contiene:
prioridad: tipo int
siguiente: tipo apuntador a estructura Pnodo.
InicioNodo: tipo  apuntador a estructura Pnodo.
FinNodo: tipo  apuntador a estructura Pnodo.
Estructura "tipoNodo" que contiene:
valor: tipo int
siguiente: tipo apuntador a estructura nodo.
----------------------------*/
typedef struct Pnodo {			//Nodo de prioridades
   int prioridad;					
   struct Pnodo *siguiente;			//Apuntador (llamado siguiente) a estructura Pnodo.
   struct Pnodo *InicioNodo;        //Apuntador (llamado InicioNodo) a estructura Pnodo.
   struct Pnodo *FinNodo;       	//Apuntador (llamado FinNodo) a estructura Pnodo.
} tipoPNodo;						//Nombre de la estructura = tipoNodo

typedef struct nodo {			//Nodo de colas
   int valor;					
   struct nodo *siguiente;			//Apuntador (llamado siguiente) a estructura nodo.
} tipoNodo;							//Nombre de la estructura = tipoNodo

  
/*TIPO DE DATO-----------------
Declaraci�n de tipo de dato:
pNodo: Apuntador a tipoNodo.
pNodoP: Apuntador a tipoPNodo.
----------------------------*/
typedef tipoNodo *pNodo;		//Tipo de dato pNodo que es apuntador a una estructura "tipoNodo"
typedef tipoPNodo *pNodoP;		//Tipo de dato pNodoP que es apuntador a una estructura "tipoPNodo"


/* --------------------------------------------------------------------
NOMBRE: Funci�n prioridad_vacia
TIPO: entero int
PAR�METROS: 	inicio: 	Apuntador al inicio de la estructura.
DESCRIPCI�N: 	Funci�n que indica que una estructura est� vac�a.
		REGRESA: 0   Cuando la estructura est� vac�a
				 1   Cuando la estructura no est� vac�a
-------------------------------------------------------------------- */
int prioridad_vacia (pNodoP inicio) {		
	
	if(!inicio){			//Si no hay nodos en la estructura.	
		return 0; 			//Retornamos 0
	} else {				//De lo contrario
		return 1;
	}
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n CreaColaPrioridad
TIPO: void
PAR�METROS: 	inicio: Inicio de la cola de prioridad
				final: final de la cola de prioridad
				NumPrioridad: 	Cantidad de prioridades deseadas.
DESCRIPCI�N: 	Funci�n que crea una cola de prioridades.
-------------------------------------------------------------------- */
void CreaColaPrioridad(pNodoP *inicio, pNodoP *final, int NumPrioridad){
	
	pNodoP nuevo;						//variable de tipo apuntador a una estructura (pNodoP)llamada "nuevo".
 	int Cont;							//Variable de contador.
 	
    	if ((nuevo = (pNodoP)malloc(sizeof (tipoPNodo))) == NULL){/* Se reserva el espacio de memoria de tama�o de la estructura tipoPNodo
	   															se hace un cast a un tipo pNodoP y el valor se le asigna a la variable "nuevo"
																se compara con que no haya espacio en memoria*/
	    	printf ("Memoria insufuciente.");
	    	return; 
    	
		} else {
			for(Cont = 1; Cont <= NumPrioridad; Cont ++){
				if (prioridad_vacia(*inicio) == 0){					//Si no hay nodos en la estructura.	
					*inicio = nuevo;								//El inicio de nuestra cola apunta al nuevo espacio de memoria.
					
				}else{
					(*final)->siguiente = nuevo;	//final siguente apunta a nuevo.
				}	
				*final = nuevo;							//El final de nuestra cola apunta al nuevo espacio de memoria.
				nuevo->prioridad = Cont;				//A la variable "nuevo prioridad" se le asigna el valor de Cont.
				nuevo->siguiente = NULL;				//A la variable "nuevo siguiente" apunta a NULL
				nuevo->InicioNodo = NULL;				//A la variable "nuevo inicioNodo" apunta a NULL
				nuevo->FinNodo = NULL;					//A la variable "nuevo finNodo" apunta a NULL
				printf(" [%d] ", nuevo->prioridad);
			}
		} 
	fflush(stdin);
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n AgregarAPrioridad
TIPO: void
PAR�METROS: 	inicioP: apuntador al incio de Cola de prioridad.
				finalP: apuntador al final de Cola de prioridad.
				Prioridad: 	prioridad deseada
				Numero: valor a insertar.
DESCRIPCI�N: 	Funci�n que crea una cola de prioridad.
-------------------------------------------------------------------- */
void AgregarAPrioridad(pNodoP *inicioP, pNodoP *finalP, int Prioridad, int Numero){
	
	pNodoP auxiliar;
	
	if(prioridad_vacia(*inicioP) == 0){ 					//si la cola est� vac�a.
		fprintf(stderr, "\n\n\t   La cola de prioridad est%c vac%ca\n\n", 160, 161);
	
	} else {
	auxiliar = *inicioP;							//la variable auxiliar guarda la estrucutura inicio.
	do{
		while (auxiliar->prioridad == Prioridad){
			printf("PRIORIDAD: [%d]", auxiliar->prioridad);
			printf("\n\n\t\tAGREGAR: [ %d ]\n\n\n", agregar(auxiliar, Numero));
		} 
		if  (auxiliar->prioridad != Prioridad){
			auxiliar = auxiliar->siguiente;				//Cambia valor al siguiente
	 	}
	} while (auxiliar != NULL);							//Mientras no apunte a NULL hacer...
	}
	free(auxiliar);	  								//Liberar variable 
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n agregar
TIPO: int
PAR�METROS: prioridad:	De tipo (pNodoP).
			valor: valor recibido desde la funcion main.
DESCRIPCI�N: Funci�n que agrega un elemento a la cola.
-------------------------------------------------------------------- */
int agregar(pNodoP prioridad, int valor) {
   
    pNodo nuevo, aux;								//variable de tipo apuntador a una estructura (pNodo).
 	
    	if ((nuevo = (pNodo)malloc(sizeof (tipoNodo))) == NULL){/* Se reserva el espacio de memoria de tama�o de la estructura tipoNodo
	   													se hace un cast a un tipo pNodo y el valor se le asigna a la variable "nuevo"
														se compara con que no haya espacio en memoria*/
	    	fprintf (stderr, "Memoria insufuciente.");
	    	return; 
    	
		} else {
			
			if (prioridad->InicioNodo == NULL){
				prioridad->InicioNodo = nuevo;		
			}else{
				aux = prioridad->FinNodo;
				aux->siguiente = nuevo;
			}
			prioridad->FinNodo = nuevo;
			nuevo->siguiente = NULL;			//A la variable "nuevo siguiente" apunta a NULL
			nuevo->valor = valor;				//A la variable "nuevo valor" se le asigna el valor de "numero" (par�metro de la funci�n main).
		}
	return valor; 
	fflush(stdin);
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n BorrarAPrioridad
TIPO: void
PAR�METROS: 	inicioP: apuntador al incio de Cola de prioridad.
				finalP: apuntador al final de Cola de prioridad.
				Prioridad: 	prioridad deseada
DESCRIPCI�N: 	Funci�n que crea una cola de prioridad.
-------------------------------------------------------------------- */
void BorrarAPrioridad(pNodoP *inicioP, pNodoP finalP, int Prioridad) {
	
	pNodoP auxiliar;
	
	if(prioridad_vacia(inicioP) == 0){ 					//si la cola est� vac�a.
		fprintf(stderr, "\n\n\t   La cola de prioridad est%c vac%ca\n\n", 160, 161);
	
	} else {
	auxiliar = inicioP;							//la variable auxiliar guarda la estrucutura inicio.
	do{
		if (auxiliar->prioridad == Prioridad){
			printf("PRIORIDAD: [%d]", auxiliar->prioridad);
			printf("\n\n\t\tBORRAR: [ %d ]\n\n\n", borrar(auxiliar));
		} else {
			auxiliar = auxiliar->siguiente;				//Cambia valor al siguiente
	 	}
	} while (auxiliar != NULL);							//Mientras no apunte a NULL hacer...
	}
	free(auxiliar);	  								//Liberar variable 
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n borrar
TIPO: int
PAR�METROS: Prioridad: Prioridad de la que se va a borrar el valor.
DESCRIPCI�N: Funci�n que elimina un elemento de una cola.
-------------------------------------------------------------------- */
int borrar(pNodoP Prioridad) {
	
   pNodo auxiliar; 		//Variable de tipo apuntador a una estructura (pNodo)llamada "auxiliar".
   int v;      			//Variable tipo entero llamada "v".
   
   if (Prioridad->InicioNodo == NULL){ 		//Si no hay nodos en la cola.
   
   		printf("\n\tLa cola est%c vac%ca.\n\n", 160, 161);
   
   } else {
		
		auxiliar = Prioridad->InicioNodo;						//auxiliar apunta al primer elemento de la cola.
	   	Prioridad->InicioNodo = auxiliar->siguiente;			//Asignamos a "inicio nodo" el siguiente elemento.
	  	v = auxiliar->valor; 				//a la variable v se le asigna el valor de "auxiliar valor"
	    return v;
	}
   free(auxiliar);						//Borrar el nodo.
}


/* --------------------------------------------------------------------
NOMBRE: ver_cola
TIPO: void
ARGUMENTOS:		inicioP: apuntador al incio de Cola de prioridad.
				finalP: apuntador al final de Cola de prioridad.
				Prioridad: 	prioridad deseada
DESCRIPCI�N: Funci�n que muestra los elementos de una cola.
-------------------------------------------------------------------- */
void ver_cola(pNodoP inicioP, pNodoP finalP, int Prioridad){
	
	pNodoP auxiliar;
	pNodo auxiliarDos = auxiliar->InicioNodo;
	
	if(prioridad_vacia(inicioP) == 0){ 					//si la cola est� vac�a.
		fprintf(stderr, "\n\n\t   La cola de prioridad est%c vac%ca\n\n", 160, 161);
	
	} else {
	auxiliar = inicioP;							//la variable auxiliar guarda la estrucutura inicio.
	do{
		if (auxiliar->prioridad == Prioridad){
			if(auxiliar->InicioNodo == NULL){ 					//si la cola est� vac�a.
	
				fprintf(stderr, "\n\n\t   La cola est%c vac%ca", 160, 161);
	
			} else {
				
			printf("PRIORIDAD: [%d]", auxiliar->prioridad);
			printf("\n\n\t\tCOLA: ");
				while (auxiliarDos != NULL){						//Mientras no apunte a NULL hacer...
					printf(" [ %d ] ", auxiliarDos->valor);   		//Imprime el valor
					auxiliarDos = auxiliarDos->siguiente;				//Cambia valor al siguiente
	    		}
			} 
		}else {
			auxiliar = auxiliar->siguiente;				//Cambia valor al siguiente
	 	}
	} while (auxiliar != NULL);							//Mientras no apunte a NULL hacer...
	}
	free(auxiliar);	  								//Liberar variable 
}


/* --------------------------------------------------------------------
NOMBRE: funci�n ver_inicio
TIPO:  void
PAR�METROS: 	inicioP: apuntador al incio de Cola de prioridad.
				finalP: apuntador al final de Cola de prioridad.
				Prioridad: 	prioridad deseada
DESCRIPCI�N: Funci�n que muestra el elemento inicia� de la cola.
-------------------------------------------------------------------- */
void ver_inicio (pNodoP inicioP, pNodoP finalP, int Prioridad) {
	
	pNodoP auxiliar;
		
	if(prioridad_vacia(inicioP) == 0){ 					//si la cola est� vac�a.
		fprintf(stderr, "\n\n\t   La cola de prioridad est%c vac%ca\n\n", 160, 161);
	
	} else {
	auxiliar = inicioP;							//la variable auxiliar guarda la estrucutura inicio.
	
	do{
		if (auxiliar->prioridad == Prioridad){
			
			if (auxiliar->InicioNodo == NULL){
				printf("\n\tNo hay elementos en la cola.");
			} else {
				printf("\n\nEl elemento que se encuentra al inicio de la cola es: [%d]\n\n\n", auxiliar->prioridad);
			}
		} else {
			auxiliar = auxiliar->siguiente;				//Cambia valor al siguiente
	 	}
	} while (auxiliar != NULL);							//Mientras no apunte a NULL hacer...
	}

	free(auxiliar);	  								//Liberar variable 
	}	


/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
PAR�METROS: N/A
DESCRIPCI�N: Funci�n que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
int main (){
	
	pNodoP inicio = NULL;				//Variable llamada inicio, de tipo pNodoP (apuntador a estructura tipoPNodo) que apunta a NULL.
    pNodoP final = NULL;				//Variable llamada final, de tipo pNodoP (apuntador a estructura tipoPNodo) que apunta a NULL.
   	int eNumero, ePrioridad, Prioridades;			//Valor ingresado por el usuario
	int eOpcion; 							//Variable que permitir� seleccionar una opci�n del men�.

	printf("\n\n\t\t%cCu%cntas prioridades desea ingresar? ", 168, 160);
	scanf("%d", &Prioridades);
	system("cls");
	printf("\n\n\t\tPRIORIDADES: ");
	CreaColaPrioridad(&inicio, &final, Prioridades);
	printf("\n\n");
	system("pause");

	do { 				//Ciclo repetir-hasta para que se muestre el men� principal cada vez que se desee.
	
		system("cls");			//Limpiar pantalla
		
		printf("\t\t        MEN%C\n\n", 233);
    	printf("\t\t   %c %c Cola\n", 175, 175);
    	printf("\t\t\t  %c 1. Agregar elemento\n", 254);
    	printf("\t\t\t  %c 2. Borrar elemento\n", 254);
    	printf("\t\t\t  %c 3. Ver inicio\n", 254);
    	printf("\t\t\t  %c 4. Ver cola\n\n", 254);
    	printf("\t\t   %c 0. Salir", 254);
	    
	    printf("\n\nIntroduzca el n%cmero de la acci%cn que deseas realizar: ", 163, 162);
    	scanf("%d", &eOpcion); 		//Leer variable eOpcion.
    	
    	system("cls");				//Limpiar pantalla.
    	
    	switch(eOpcion){ 			//En caso de eOpcion... , hacer...

	    	case 1: printf("\n\n\t\t%cQu%c n%cmero deseas insertar a la cola? ", 168, 130, 163);
   					scanf("%d", &eNumero);
   					printf("\n\n\t\t%cQu%c prioridad deseas asignarle? ", 168, 130);
   					scanf("%d", &ePrioridad);
   					if(ePrioridad <= Prioridades){
   						AgregarAPrioridad(&inicio, &final, ePrioridad, eNumero);			//Se manda a llamar la funci�n agregar.
					} else {
						printf("\n\nPrioridad no existente.\n\n");
					}
					fflush(stdin);
   					system("pause");
   			break;
			
			case 2: printf("\n\n\t\t%cDe qu%c prioridad deseas borrar? ", 168, 130);
   					scanf("%d", &ePrioridad);
   					if(ePrioridad <= Prioridades){
   						BorrarAPrioridad(&inicio, final, ePrioridad);	//Se manda a llamar la funci�n borrar.
					} else {
						printf("\n\nPrioridad no existente.\n\n");
					}
					fflush(stdin);
   					system("pause"); 
				break;
				
    		case 3: printf("\n\n\t\t%cDe qu%c prioridad deseas ver el inicio? ", 168, 130);
   					scanf("%d", &ePrioridad);
   					if(ePrioridad <= Prioridades){
						ver_inicio (inicio, final, ePrioridad);					//Se manda a llamar la funci�n ver_inicio.
    				}
					fflush(stdin);
   					system("pause"); 
				break;
    			
    		case 4: printf("\n\n\t\t%cDe qu%c prioridad deseas ver la cola? ", 168, 130);
   					scanf("%d", &ePrioridad);
   					if(ePrioridad <= Prioridades){
   						ver_cola(inicio, final, ePrioridad);						//Se manda a llamar la funci�n ver_cola.
					} else {
						printf("\n\nPrioridad no existente.\n\n");
					}
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

