/* **********************************************************************
	NOMBRE DEL PROGRAMA: MenuPrincipal.c
	OBJETIVO: Mostrar las opciones del menú principal para redireccionar a los submenús del sistema, que son: Artículos, Compras, Proveedores y Ventas.
	AUTOR(ES): 
				Fernández Ortiz Valeria Lizette
				Francisco Arellano Herdson Josue
				López Alejaldre Daniela Viridiana
				Segura Ríos Brenda Stephanie
				Varas Dayren Sarahi
	EQUIPO: SkyNet
	FECHA DE CREACIÓN: 23 de mayo del 2019.
	FECHA DE ÚLTIMA ACTUALIZACIÓN: 13 de junio del 2019.
********************************************************************** */

//BIBLIOTECAS
#include <stdio.h> //Biblioteca estándar de entrada y salida. 
#include <string.h> //Biblioteca para el manejo de cadenas.
#include <stdlib.h> //Biblioteca para conversión de datos.
#include <conio.h> //Biblioteca para manejo de caracteres.
#include "EditarMenu.h" //Biblioteca para editar la interfaz del menú.
#include "Articulos.c" //Biblioteca que contiene submenú de Artículos
//#include "Ventas.c" //Biblioteca que contiene el submenú de Ventas. 
#include "Proveedores.c" //Biblioteca que contiene el submenú de Proveedores. 
#include "Compras.c"  //Biblioteca que contiene el submenú de Compras.

/***********************************************************************
	FUNCIÓN: MenúPrincipal
	AUTOR: López Alejaldre Daniela Viridiana.
	FECHA DE CREACIÓN: 17 de abril del 2019.
	OBJETIVO: Crear el diseño de la aplicación del sistema (menú principal).
	DE(PE): No recibirá parámetros.
	DS(PS): Número entero, positivo. 
	RETORNA: 0 en caso de no encontrar fallas o cualquier otro número <> 0 en caso de encontrar un error. 
************************************************************************/
int main (){
	
	int eOpcion; //Variable que permitirá seleccionar una opción del menú principal.
	
	
	do { //Ciclo repetir-hasta para que se muestre el menú principal cada vez que se desee.
	
		system("cls");
		
		dibujarMarco(); //Invocar al procedimiento dibujarMarco
		moverCursor (2, 21); //Muestra línea en una posición.
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
	    
	    linea(22); //Dibuja una línea en el renglón indicado.
	    moverCursor (25, 33);
	    printf("Introduzca el n%cmero del sub-men%c que desea utilizar: ", 163, 163);
    
    	moverCursor(25, 87); //Mismo renglón que escribir nombre para leerlo.
    	scanf("%d", &eOpcion); //Leer variable eOpcion.
    	
    	switch(eOpcion){ //En caso de eOpcion, hacer...
    		
    		case 1: MenuArticulos(); //Ejecutar el sub-menú Artículos. 
    				break; //Terminar el ciclo en caso de.

    		case 2: MenuCompras(); //Ejecutar el sub-menú Compras. 
    				break; //Terminar el ciclo en caso de.
    				
			case 3: MenuProveedor(); //Ejecutar el sub-menú Proveedores. 
    				break; //Terminar el ciclo en caso de.
      				
    		//case 4: MenuVentas(); //Ejecutar el sub-menú Ventas. 
    		//		break; //Terminar el ciclo en caso de.
 				
    		case 5: moverCursor (28, 53);
				 	printf("%cHasta luego!", 173);//Imprimir con formato una despedida.
    				break; //Terminar el ciclo en caso de.
    				
    		default:moverCursor (28, 49);
					printf("Error en la selecci%cn\n", 162); //Imprimir con formato un error. 
					system("pause");
					break; //Terminar el ciclo en caso de.
    				 
		}
		
	} while (eOpcion != 5); //Mientras la opción sea diferente de 5, se seguirá mostrando el menú principal. 
	
	getchar (); //Obtener un caracter del teclado.
    return 0; //Regresar 0.  	    
}
