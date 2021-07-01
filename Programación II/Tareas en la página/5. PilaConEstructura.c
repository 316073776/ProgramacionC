/* **********************************************************************
NOMBRE DEL PROGRAMA: PilaConEstructura.c
OBJETIVO: Revisar qu� hace cada parte del programa y comentarlo.
AUTOR: Segura Rios Brenda Stephanie
FECHA: 26/08/2019
********************************************************************** */
//LIBRER�AS
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
Declaraci�n de tipo
----------------------------*/
typedef elem elemento;


/* --------------------------------------------------------------------
NOMBRE: Funci�n pila_vacia
TIPO: entero int
PAR�METROS: tope: 	Apuntador al �ltimo elemento de la pila.
			pila: 	Apuntador al inicio de la pila.
			n: 	  	N�mero de elementos m�ximo de la pila.
DESCRIPCI�N: Funci�n que indica que una pila est� vac�a.
		REGRESA: 1   Cuando la pila est� vac�a
				 0   Cuando la pila no est� vac�a
-------------------------------------------------------------------- */
int pila_vacia (elemento * tope, elemento* pila, int n) {

    if ( tope == pila + n){			//Si tope es igual a inicio + n
		
		return 1;						//La pila est� vac�a.
	
	} else {
		
		fprintf(stderr, "La pila no est%c vac%ca. \n", 160, 161);
		return 0;
	}
    
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n pila_llena
TIPO: entero int
PAR�METROS: tope: 	Apuntador al �ltimo elemento de la pila.
			inicio: 	Apuntador al inicio de la pila.
DESCRIPCI�N: Funci�n que indica si una pila est� llena.
		REGRESA: 1   Cuando la pila est� llena
				 0   Cuando la pila no est� llena
-------------------------------------------------------------------- */
int pila_llena (elemento * tope, elemento *inicio) {

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
void ver_tope (elemento tope) {
	
	printf("\nEl elemento que se encuentra al final de la pila es: %d\n\n\n", tope);

}


/* --------------------------------------------------------------------
NOMBRE: ver_pila
TIPO: void
ARGUMENTOS: inicio:		Apuntador a estructura de tipo elemento que indica el inicio de la pila. 
			tope: 		Apuntador a estructura de tipo elemento al �ltimo elemento.
			n:		 	M�ximo de elementos en la pila.
DESCRIPCI�N: Funci�n que muestra los elementos de una pila con estructuras.
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
NOMBRE: Funci�n push
TIPO: int
PAR�METROS: elementochar:	De tipo (char) caracter que se encuentra en la "estructura" elemento.
			elementoint:	De tipo (int) entero que se encuentra en la "estructura" elemento.
			tope: 			Apuntador por referencia, tipo elemento al �ltimo elemento de la pila.
			inicio:			Apuntador de tipo elemento que indica el inicio de la pila.
DESCRIPCI�N: Funci�n que agrega o apila un elemento a la pila, 
			 implementada en un arreglo din�mico.
-------------------------------------------------------------------- */
int push(char elementochar, int elementoint, elemento **tope, elemento *inicio) {
	
	if( pila_llena(inicio, *tope) == 0 ){		//Si pila est� vac�a.
	    	
		(**tope).caracter = elementochar;     		/*Por referencia, el contenido de lo que apunta (**tope) mandado por referencia
														.caracter, es igual al valor de elemento ('A')--Mandar un apuntador  por referencia, es decir, el tope cambia. (**)*/
		(**tope).numero = elementoint; 				//El contenido del apuntador tope.numero, es igual al valor de elemento (1)--Mandar un apuntador  por referencia, es decir, el tope cambia. (**)
		//xxx *tope.numero = elementoint; = El contenido de la estructura tope.numero   xxx
		
		(*tope)--;			//A tope se le resta un valor/una posici�n.
		
	} else {
			
		fprintf(stderr, "La pila est%c en overflow. \n", 160);		//Salida est�ndar.
		
	}
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n pop
TIPO: void
PAR�METROS: n: 
			tope: 			Apuntador por referencia, tipo elemento al �ltimo elemento de la pila.
			inicio:			Apuntador de tipo elemento que indica el inicio de la pila.
DESCRIPCI�N: Funci�n que elimina un elemento de una pila implementada 
			 en un arreglo din�mico.
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
DESCRIPCI�N: Funci�n que declara un arreglo, lo inicializa, lo manipula,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
main() {

elemento *pila;		//Apuntador llamado pila = no apunta a nada  tipo elemento
elemento *tope;		//Apuntador llamado tope = no apunta a nada  tipo elemento

int n;				//Declaro variable n de tipo entero.

    printf ("%cCu%cl es el tama%co de la pila? ", 168, 160, 164);
    scanf ("%d", &n);						//Guardo tama�o en n


    pila = (elemento*) malloc( sizeof(elemento) * n);			//pila = el espacio de memoria se lo asigno al apuntador pila.
																/*sizeof = regresa el tama�o del valor elemento en bites.
					  											sizeof se multiplica por n para saber de qu� tama�o necesito el espacio de memoria.
																(void*-sin tipo) malloc = reserva un espacio de memoria del tama�o de los bites que me indica sizeof. 
																  						- Reserva la cantidad de memoria de n elementos.
																(elemento*) = cast que le pone el tipo elemento a malloc ya que retorna un apuntador a ning�n tipo.*/
    
    tope = pila + n;						//A tope se le asigna el valor de pila(primer lugar de memoria) + n (tama�o de la pila)
    
    printf ("\nINICIO:\n");
    printf ("Tope: %p\t Pila %p\n", tope, pila);  		//Imprimir %p = direcci�n a la que est� apuntando Tope. y Pila.
     
    push('A', 1, &tope, pila);			
    push('B', 2, &tope, pila);
    push('C', 3, &tope, pila);
    printf	("\nDESPU%cS DE PUSH:\n", 144);
    printf ("Tope: %p\t Pila %p\n", tope, pila);		//Imprimir %p = direcci�n a la que est� apuntando Tope. y Pila.
    
    ver_pila(pila, tope, n);					//Manda a llamar a la funci�n ver_pila; pasa n, tope y pila.
    
    pop (n, &tope, pila);						//Manda a llamar a la funci�n pop; pasa la direcci�n de memora de tope.
    pop (n, &tope, pila);
    printf ("\nDESPU%cS DE POP:\n", 144);
	printf ("Tope: %p\t Pila %p\n", tope, pila);		//Imprimir %p = direcci�n a la que est� apuntando Tope. y Pila.
	
	ver_tope(*tope);				//Manda a llamar a la funci�n ver_tope; pasa la direcci�n de memora de tope.

    free(pila);    
    system ("PAUSE");
       
}

