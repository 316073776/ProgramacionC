/* **********************************************************************
NOMBRE DEL PROGRAMA: PilasDeUnElemento.c
OBJETIVO: Revisar qu� hace cada parte del programa y comentarlo.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 22/08/2019
********************************************************************** */

//LIBRER�AS
#include <stdio.h> 
#include <stdlib.h>

/* --------------------------------------------------------------------
NOMBRE: Funci�n pila_vacia
TIPO: entero int
PAR�METROS: inicio: Apuntador al inicio de la pila.
			tope: 	Apuntador al �ltimo elemento de la pila.
			n: 	  	N�mero de elementos m�ximo de la pila.
DESCRIPCI�N: Funci�n que indica que una pila est� vac�a.
		REGRESA: 1   Cuando la pila est� vac�a
				 0   Cuando la pila no est� vac�a
-------------------------------------------------------------------- */
int pila_vacia (int n, char *inicio, char *tope) {		//Recibe par�metros por valor

    if ( tope == inicio + n){			//Si tope es igual a inicio + n
		
		return 1;						//La pila est� vac�a.
	
	} else {
		
		fprintf(stderr, "La pila no est%c vac%ca. \n", 160, 161);
		return 0;
	}
    
}

/* --------------------------------------------------------------------
NOMBRE: Funci�n pila_llena
TIPO: entero int
PAR�METROS:   inicio: 	Apuntador al inicio de la pila.
			  tope: 	Apuntador al �ltimo elemento de la pila.
DESCRIPCI�N: Funci�n que indica si una pila est� llena.
		REGRESA: 1   Cuando la pila est� llena
				 0   Cuando la pila no est� llena
-------------------------------------------------------------------- */

int pila_llena (char *inicio, char *tope) {

	if ( inicio == tope){ 			//Si tope es igual al inicio de la pila regresa 1.
	
		return 1;					//Pila llena
	
	} else {						//De lo contrario regresa 0.
	
		return 0;				
	}
        
}

/* --------------------------------------------------------------------
NOMBRE: funci�n ver_tope
TIPO:  void
PAR�METROS: fin:	Apuntador de tipo char que contiene un caracter de la pila.
DESCRIPCI�N: Funci�n que muestra el �ltimo elemento insertado en la pila.
-------------------------------------------------------------------- */
void ver_tope (char fin) {

	printf("\nEl elemento que se encuentra al final de la pila es: %c\n\n\n", fin);
    
}

/* --------------------------------------------------------------------
NOMBRE: ver_pila
TIPO: void
ARGUMENTOS: n:		 	Tama�o de la pila
			tope: 		Por referencia, tipo apuntador al �ltimo elemento.
			inicio:		De tipo char que indica el inicio de la pila. 	
DESCRIPCI�N: Funci�n que muestra todo el contenido de la pila.
-------------------------------------------------------------------- */
void ver_pila(int n,char *tope,char *inicio) {
	
	char *contador;			//Tipo apuntador a char.
	
	printf ("\nEl contenido de la pila es: \n");
	
	for (contador = tope + 1; contador <= inicio + n; contador ++){		//Desde tope hasta el final de la pila, contador aumenta 1 para recorrer la pila
		
		printf ("[%c]\t", *contador);							//Muestra el contenido de contador.
		
	}
	
	printf("\n\n");
    
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n push
TIPO: void
PAR�METROS: elemento:	De tipo (char) caracter que contiene el elemento a agregar.
			tope: 		Por referencia, tipo apuntador al �ltimo elemento.
			inicio:		De tipo char que indica el inicio de la pila.
DESCRIPCI�N: Funci�n que agrega o apila un elemento a la pila, 
			 implementada en un arreglo din�mico.
-------------------------------------------------------------------- */

void push (char elemento, char **tope, char *inicio) {  		//Llamada por referencia a un apuntador
     
    if( pila_llena(inicio, *tope) == 0 ){		//Si pila est� vac�a.
    	
	    **tope = elemento;     	/*El contenido del apuntador tope, es igual al valor de elemento ('A')
		 						Mandar un apuntador  por referencia, es decir, el tope cambia. (**)*/
	    (*tope)--;			//A tope se le resta un valor/una posici�n.
	
	} else {
		
		fprintf(stderr, "La pila est%c en overflow. \n", 160);		//Salida est�ndar.
	
	}
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n pop
TIPO: void
PAR�METROS: tope: 	Apuntador por referencia que se actualiza cuando eliminamos un elemento.
			inicio: Apuntador al inicio de la pila.
			n: 	  	N�mero de elementos m�ximo de la pila.
DESCRIPCI�N: Funci�n que elimina un elemento de una pila implementada 
			 en un arreglo din�mico.
-------------------------------------------------------------------- */

void pop (int n, char **tope, char *inicio) { 
    
    if( pila_vacia(n, inicio, *tope) == 0){
    	
		(*tope) ++;		//Se elimina un elemento al incrementar en uno.
		
	}else { 
	
    	fprintf(stderr, "La pila est%c vacia.\n", 160);
	}
} 


/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
ARGUMENTOS: N/A
DESCRIPCI�N: Funci�n que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */

main() {

char *pila;		//Apuntador a caracteres - Arreglo local
char *tope;		//Apuntador a caracteres

int n;			//Indicador del tama�o de la pila.

    printf ("%cCu%cl es el tama%co de la pila? ", 168, 160, 164);
    scanf ("%d", &n);


    pila = (char*) malloc(sizeof(char) * n);  //pila = el espacio de memoria se lo asigno al apuntador pila.
											  /*sizeof = regresa el tama�o del valor de un caracter en bites.
  											  sizeof se multiplica por n para saber de qu� tama�o necesito el espacio de memoria.
											  (void*-sin tipo) malloc = reserva un espacio de memoria del tama�o de los bites que me indica sizeof. 
											  							- Reserva la cantidad de memoria de n elementos.
											  (char*) = cast que le pone el tipo caracter a malloc ya que retorna un apuntador a ning�n tipo.*/
    
    tope = pila + n;		//A tope se le asigna el valor de pila(primer lugar de memoria) + n (tama�o de la pila)
    
    printf ("\nINICIO:\n");
    printf ("Tope: %p\t Pila %p\n", tope, pila);  		//Imprimir %p = direcci�n a la que est� apuntando Tope. y Pila.
     
    push('A', &tope, pila);		//Mandar a llamar a la funci�n push; pasa por par�metros el caracter A, la direcci�n de memoria de tope y el inicio de la pila.
    push('B', &tope, pila);
    push('C', &tope, pila);
    push('D', &tope, pila);
    printf	("\nDESPU%cS DE PUSH:\n", 144);
    printf ("Tope: %p\t Pila %p\n", tope, pila);		//Imprimir %p = direcci�n a la que est� apuntando Tope. y Pila.
    
    ver_pila(n, tope, pila);		//Manda a llamar a la funci�n ver_pila; pasa n, tope y pila.
    
    pop(n, &tope, pila);			//Manda a llamar a la funci�n pop; pasa la direcci�n de memora de tope.
    pop(n, &tope, pila);
    printf ("\nDESPU%cS DE POP:\n", 144);
	printf ("Tope: %p\t Pila %p\n", tope, pila);		//Imprimir %p = direcci�n a la que est� apuntando Tope. y Pila.
    
	ver_tope(*tope);				//Manda a llamar a la funci�n ver_tope; pasa la direcci�n de memora de tope.
    
    free(pila);    		//Pila apunta a alg�n lado, ya no apunta a la direcci�n de memoria asignada anteriormente.
    system ("PAUSE");		// detiene la ejecuci�n del programa.
       
} 


