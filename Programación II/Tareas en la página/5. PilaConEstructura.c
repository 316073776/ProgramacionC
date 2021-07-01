/* **********************************************************************
NOMBRE DEL PROGRAMA: PilaConEstructura.c
OBJETIVO: Revisar qué hace cada parte del programa y comentarlo.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 26/08/2019
********************************************************************** */
//LIBRERÍAS
#include <stdio.h>
#include <stdlib.h>

/*ESTRUCTURAS---------------
Estructrura "elem" que contiene dos elementos.
numero: tipo int
caracter: tipo char
----------------------------*/
typedef struct {
        int numero;
        char caracter;
        } elem;

/*----------------------------
Declaración de tipo
----------------------------*/
typedef elem elemento;


/* --------------------------------------------------------------------
NOMBRE: Función pila_vacia
TIPO: entero int
PARÁMETROS: tope: 	Apuntador al último elemento de la pila.
			pila: 	Apuntador al inicio de la pila.
			n: 	  	Número de elementos máximo de la pila.
DESCRIPCIÓN: Función que indica que una pila está vacía.
		REGRESA: 1   Cuando la pila está vacía
				 0   Cuando la pila no está vacía
-------------------------------------------------------------------- */
int pila_vacia (elemento * tope, elemento* pila, int n) {

    if ( tope == pila + n){			//Si tope es igual a inicio + n
		
		return 1;						//La pila está vacía.
	
	} else {
		
		fprintf(stderr, "La pila no est%c vac%ca. \n", 160, 161);
		return 0;
	}
    
}


/* --------------------------------------------------------------------
NOMBRE: Función pila_llena
TIPO: entero int
PARÁMETROS: tope: 	Apuntador al último elemento de la pila.
			inicio: 	Apuntador al inicio de la pila.
DESCRIPCIÓN: Función que indica si una pila está llena.
		REGRESA: 1   Cuando la pila está llena
				 0   Cuando la pila no está llena
-------------------------------------------------------------------- */
int pila_llena (elemento * tope, elemento *inicio) {

	if ( inicio == tope){ 			//Si tope es igual al inicio de la pila regresa 1.
	
		return 1;					//Pila llena
	
	} else {						//De lo contrario regresa 0.
	
		return 0;				
	}
        
}


/* --------------------------------------------------------------------
NOMBRE: función ver_tope
TIPO:  void
PARÁMETROS: fin:	Apuntador de tipo char que contiene un caracter de la pila.
DESCRIPCIÓN: Función que muestra el último elemento insertado en la pila.
-------------------------------------------------------------------- */
void ver_tope (elemento tope) {
	
	printf("\nEl elemento que se encuentra al final de la pila es: %d\n\n\n", tope);

}


/* --------------------------------------------------------------------
NOMBRE: ver_pila
TIPO: void
ARGUMENTOS: inicio:		Apuntador a estructura de tipo elemento que indica el inicio de la pila. 
			tope: 		Apuntador a estructura de tipo elemento al último elemento.
			n:		 	Máximo de elementos en la pila.
DESCRIPCIÓN: Función que muestra los elementos de una pila con estructuras.
-------------------------------------------------------------------- */
void ver_pila ( elemento *inicio, elemento *tope, int n) {
	
	elemento *aux; 	//Tipo apuntador a elemntos.
	
	printf ("\nEl contenido de la pila es: \n");
	
	for (aux = tope + 1; aux <= inicio + n; aux ++){
		
		printf("[%d]\t[%c]\n", (*aux).numero, (*aux).caracter);	
		
	}
	
	printf("\n");
    
}


/* --------------------------------------------------------------------
NOMBRE: Función push
TIPO: int
PARÁMETROS: elementochar:	De tipo (char) caracter que se encuentra en la "estructura" elemento.
			elementoint:	De tipo (int) entero que se encuentra en la "estructura" elemento.
			tope: 			Apuntador por referencia, tipo elemento al último elemento de la pila.
			inicio:			Apuntador de tipo elemento que indica el inicio de la pila.
DESCRIPCIÓN: Función que agrega o apila un elemento a la pila, 
			 implementada en un arreglo dinámico.
-------------------------------------------------------------------- */
int push(char elementochar, int elementoint, elemento **tope, elemento *inicio) {
	
	if( pila_llena(inicio, *tope) == 0 ){		//Si pila está vacía.
	    	
		(**tope).caracter = elementochar;     		/*Por referencia, el contenido de lo que apunta (**tope) mandado por referencia
														.caracter, es igual al valor de elemento ('A')--Mandar un apuntador  por referencia, es decir, el tope cambia. (**)*/
		(**tope).numero = elementoint; 				//El contenido del apuntador tope.numero, es igual al valor de elemento (1)--Mandar un apuntador  por referencia, es decir, el tope cambia. (**)
		//xxx *tope.numero = elementoint; = El contenido de la estructura tope.numero   xxx
		
		(*tope)--;			//A tope se le resta un valor/una posición.
		
	} else {
			
		fprintf(stderr, "La pila est%c en overflow. \n", 160);		//Salida estándar.
		
	}
}


/* --------------------------------------------------------------------
NOMBRE: Función pop
TIPO: void
PARÁMETROS: n: 
			tope: 			Apuntador por referencia, tipo elemento al último elemento de la pila.
			inicio:			Apuntador de tipo elemento que indica el inicio de la pila.
DESCRIPCIÓN: Función que elimina un elemento de una pila implementada 
			 en un arreglo dinámico.
-------------------------------------------------------------------- */
void pop (int n, elemento **tope, elemento *inicio) {

    if( pila_vacia(*tope, inicio, n) == 0){
    	
		(*tope) ++;		//Se elimina un elemento al incrementar en uno.
		
	}else { 
	
    	fprintf(stderr, "La pila est%c vacia.\n", 160);
    	
	}
} 


/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
ARGUMENTOS: N/A
DESCRIPCIÓN: Función que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
main() {

elemento *pila;		//Apuntador llamado pila = no apunta a nada  tipo elemento
elemento *tope;		//Apuntador llamado tope = no apunta a nada  tipo elemento

int n;				//Declaro variable n de tipo entero.

    printf ("%cCu%cl es el tama%co de la pila? ", 168, 160, 164);
    scanf ("%d", &n);						//Guardo tamaño en n


    pila = (elemento*) malloc( sizeof(elemento) * n);			//pila = el espacio de memoria se lo asigno al apuntador pila.
																/*sizeof = regresa el tamaño del valor elemento en bites.
					  											sizeof se multiplica por n para saber de qué tamaño necesito el espacio de memoria.
																(void*-sin tipo) malloc = reserva un espacio de memoria del tamaño de los bites que me indica sizeof. 
																  						- Reserva la cantidad de memoria de n elementos.
																(elemento*) = cast que le pone el tipo elemento a malloc ya que retorna un apuntador a ningún tipo.*/
    
    tope = pila + n;						//A tope se le asigna el valor de pila(primer lugar de memoria) + n (tamaño de la pila)
    
    printf ("\nINICIO:\n");
    printf ("Tope: %p\t Pila %p\n", tope, pila);  		//Imprimir %p = dirección a la que está apuntando Tope. y Pila.
     
    push('A', 1, &tope, pila);			
    push('B', 2, &tope, pila);
    push('C', 3, &tope, pila);
    printf	("\nDESPU%cS DE PUSH:\n", 144);
    printf ("Tope: %p\t Pila %p\n", tope, pila);		//Imprimir %p = dirección a la que está apuntando Tope. y Pila.
    
    ver_pila(pila, tope, n);					//Manda a llamar a la función ver_pila; pasa n, tope y pila.
    
    pop (n, &tope, pila);						//Manda a llamar a la función pop; pasa la dirección de memora de tope.
    pop (n, &tope, pila);
    printf ("\nDESPU%cS DE POP:\n", 144);
	printf ("Tope: %p\t Pila %p\n", tope, pila);		//Imprimir %p = dirección a la que está apuntando Tope. y Pila.
	
	ver_tope(*tope);				//Manda a llamar a la función ver_tope; pasa la dirección de memora de tope.

    free(pila);    
    system ("PAUSE");
       
}

