/* **********************************************************************
	NOMBRE DEL PROGRAMA: MenuPrincipal.c
	OBJETIVO: Mostrar las opciones del men� principal para redireccionar a los submen�s del sistema, que son: Art�culos, Compras, Proveedores y Ventas.
	AUTOR(ES): 
				Fern�ndez Ortiz Valeria Lizette
				Francisco Arellano Herdson Josue
				L�pez Alejaldre Daniela Viridiana
				Segura R�os Brenda Stephanie
				Varas Dayren Sarahi
	EQUIPO: SkyNet
	FECHA DE CREACI�N: 23 de mayo del 2019.
	FECHA DE �LTIMA ACTUALIZACI�N: 13 de junio del 2019.
********************************************************************** */

//BIBLIOTECAS
#include <stdio.h> //Biblioteca est�ndar de entrada y salida. 
#include <string.h> //Biblioteca para el manejo de cadenas.
#include <stdlib.h> //Biblioteca para conversi�n de datos.
#include <conio.h> //Biblioteca para manejo de caracteres.
#include "EditarMenu.h" //Biblioteca para editar la interfaz del men�.
#include "Articulos.c" //Biblioteca que contiene submen� de Art�culos
//#include "Ventas.c" //Biblioteca que contiene el submen� de Ventas. 
#include "Proveedores.c" //Biblioteca que contiene el submen� de Proveedores. 
#include "Compras.c"  //Biblioteca que contiene el submen� de Compras.

/***********************************************************************
	FUNCI�N: Men�Principal
	AUTOR: L�pez Alejaldre Daniela Viridiana.
	FECHA DE CREACI�N: 17 de abril del 2019.
	OBJETIVO: Crear el dise�o de la aplicaci�n del sistema (men� principal).
	DE(PE): No recibir� par�metros.
	DS(PS): N�mero entero, positivo. 
	RETORNA: 0 en caso de no encontrar fallas o cualquier otro n�mero <> 0 en caso de encontrar un error. 
************************************************************************/
int main (){
	
	int eOpcion; //Variable que permitir� seleccionar una opci�n del men� principal.
	
	
	do { //Ciclo repetir-hasta para que se muestre el men� principal cada vez que se desee.
	
		system("cls");
		
		dibujarMarco(); //Invocar al procedimiento dibujarMarco
		moverCursor (2, 21); //Muestra l�nea en una posici�n.
		printf("%cBienvenido al men%c principal del Sistema Compra-Venta de la farmacia Ixoye!", 173, 163);
    	moverCursor (7, 50);
    	printf("%c 1. Art%cculo(s)", 175, 161);
    	moverCursor (10, 50);     
    	printf("%c 2. Compra(s)", 175);
	    moverCursor (13, 50);         
	    printf("%c 3. Proveedor(es)", 175);
	    moverCursor (16, 50);
	    printf("%c 4. Venta(s)", 175);
	    moverCursor (19, 50);
	    printf("%c 5. Salir", 175);
	    
	    linea(22); //Dibuja una l�nea en el rengl�n indicado.
	    moverCursor (25, 33);
	    printf("Introduzca el n%cmero del sub-men%c que desea utilizar: ", 163, 163);
    
    	moverCursor(25, 87); //Mismo rengl�n que escribir nombre para leerlo.
    	scanf("%d", &eOpcion); //Leer variable eOpcion.
    	
    	switch(eOpcion){ //En caso de eOpcion, hacer...
    		
    		case 1: MenuArticulos(); //Ejecutar el sub-men� Art�culos. 
    				break; //Terminar el ciclo en caso de.

    		case 2: MenuCompras(); //Ejecutar el sub-men� Compras. 
    				break; //Terminar el ciclo en caso de.
    				
			case 3: MenuProveedor(); //Ejecutar el sub-men� Proveedores. 
    				break; //Terminar el ciclo en caso de.
      				
    		//case 4: MenuVentas(); //Ejecutar el sub-men� Ventas. 
    		//		break; //Terminar el ciclo en caso de.
 				
    		case 5: moverCursor (28, 53);
				 	printf("%cHasta luego!", 173);//Imprimir con formato una despedida.
    				break; //Terminar el ciclo en caso de.
    				
    		default:moverCursor (28, 49);
					printf("Error en la selecci%cn\n", 162); //Imprimir con formato un error. 
					system("pause");
					break; //Terminar el ciclo en caso de.
    				 
		}
		
	} while (eOpcion != 5); //Mientras la opci�n sea diferente de 5, se seguir� mostrando el men� principal. 
	
	getchar (); //Obtener un caracter del teclado.
    return 0; //Regresar 0.  	    
}
