/*Programa: P21ArregloOrdenado.c
Autor: López Alejaldre Daniela Viridiana
Fecha: 23 de mayo del 2019.
Objetivo: Mostrar las operaciones que se pueden realizar con un arreglo ordenado.
*/
//Incluyo Bibliotecas.
#include <string.h>
#include <stdio.h>

//Definición de constantes.
#define MAX 10

//Definición de tipos de datos, cadena y arreglo. 
typedef char TaCadena [30]; 
typedef TaCadena TaNombres [MAX];

//Prototipos de funciones/procedimientos. 
void InsertarOrdenado (TaNombres, int*, TaCadena);
void EliminarOrdenado (TaNombres, int*, TaCadena);
void ModificarOrdenado (TaNombres, int, TaCadena, TaCadena);
int BuscarBinario (TaNombres, int, TaCadena);
void ListarArreglo (TaNombres, int);


//Función Principal. 
int main (){
	
	int eTotal = -1, eOpcion, ePosicion;
	TaCadena cNombre, cNuevo;
	TaNombres aNombres;
	
	do {
		system ("cls");
		printf("Programa que muestra el manejo de arreglos de nombres ordenados");
		printf("\n1. Insertar\n2. Eliminar \n3. Modificar \n4. Buscar \n5. Listar \n6. Salir");
		printf("\nSeleccione una opci%cn: ", 162);
		scanf("%d", &eOpcion);
		
		switch (eOpcion){
			
			case 1: printf("\nIngrese el nombre a insertar: ");
					fflush(stdin);
				    gets(cNombre);
					InsertarOrdenado (aNombres, &eTotal, cNombre);
					break;
					
			case 2: printf("\nIngrese el nombre a borrar: ");
					fflush(stdin);
					gets(cNombre);
					EliminarOrdenado (aNombres, &eTotal, cNombre);
					break;
					
			case 3: printf("\nIngrese el nombre a modificar: ");
					fflush(stdin);
					gets(cNombre);
					printf("\nIngrese el nuevo nombre: ");
					fflush(stdin);
					gets(cNuevo);
					ModificarOrdenado (aNombres, eTotal, cNombre, cNuevo); //Ejecuto un procedimiento. 
					break;
					
			case 4: printf("\nIngrese el nombre a buscar: ");
					fflush(stdin);
					gets(cNombre);
					
					ePosicion = BuscarBinario(aNombres, eTotal, cNombre); //Mando a llamar a la función. 
					
					if (ePosicion == -1){
						
						printf("\n%s no existe", cNombre);
						
					} else {
						
						printf("\n%s est%c en la posici%cn %d", cNombre, 160, 162, ePosicion + 1);
					}
					break;
					
			case 5: printf("\nContenido del arreglo");
					ListarArreglo(aNombres, eTotal);
					break;
					
			case 6: printf("\nAdios");
					break;
					
			default: printf("\nError en la selecci%cn", 162);	
		}
		
		fflush(stdin);
		getchar();
			
		
	} while (eOpcion != 6);
	
	
	return 0;
	
}

/*	
	Procedimiento: Insertar Ordenado.
	Objetivo: Añadir un elemento a un arreglo.
	Autor: López Alejaldre Daniela Viridiana. 
	Fecha de creación: 23/mayo/2019.
	Fecha de última actualización: 30/mayo/2019. Grupo 2291. 
	DE: Arreglo de nombres (aNombres)
		Total de elementos del arreglo (eTotal).
		Elemento a insertar (cNombre).
	DS: Añade adecuadamente un elemento dentro de un arreglo en la posición correcta.  
*/
void InsertarOrdenado (TaNombres aNombres, int *eTotal, TaCadena cNombre){ //*eTotal me da el valor de eTotal a diferencia de eTotal que me da ¿En qué posición de memoria se encuentra eTotal? 
	
	int eRecorre;
	
	if (*eTotal == MAX - 1){  
		
		printf("\nNo hay espacio, el arreglo est%c lleno", 160);
	} else {
		
		if (*eTotal == -1 || strcmp(cNombre, aNombres[*eTotal]) > 0){ //Siempre comparo las cadenas contra cero. 
			
			(*eTotal) ++; //Incremento el valor de eTotal en uno. 
			
			strcpy(aNombres[*eTotal], cNombre); //Función strcpy que me permite copiar el contenido de una cadena a otra. 
			printf("\n%s insertado correctamente", cNombre);			
			
		} else {
			
			if (BuscarBinario(aNombres, *eTotal, cNombre) != -1) {//Si en la llamada que tengo que hacer tuviera que pasarlo por referencia (en este caso lo pasamos por valor), si fuera por referencia, quitarle asterisco y el &
			
				printf("Ya existe %s", cNombre);
				
			} else {
				
				eRecorre = *eTotal; //Cuando eTotal recibe el valor, va entre paréntesis, sino no.
				
				while (eRecorre >= 0 && strcmp(aNombres[eRecorre], cNombre) > 0){ //strcmp compara el tamaño de cadenas. Siempre la comparación es contra cero. 
					
					strcpy (aNombres[eRecorre + 1], aNombres [eRecorre]);
					
					eRecorre --; //Decremento eRecorre en uno. 
			    } 
				
				strcpy(aNombres[eRecorre + 1], cNombre); 
				(*eTotal) ++;
				printf("\n%s insertado correctamente", cNombre);
			}
	    }
    }
}

/*	
	Procedimiento: EliminarOrdenado.
	Objetivo: Borrar un elemento de un arreglo.
	Autor: López Alejaldre Daniela Viridiana. 
	Fecha de creación: 23/mayo/2019.
	Fecha de última actualización: 30/mayo/2019. Grupo 2291.
	DE: Arreglo de nombres (aNombres)
		Total de elementos del arreglo (eTotal).
		Elemento a borrar (cNombre).
	DS: Borra adecuadamente el elemento de un arreglo. 
*/
void EliminarOrdenado (TaNombres aNombres, int *eTotal, TaCadena cNombre){
	
	
	int eRecorre, ePos; //Variables locales del módulo. 
	
	if (*eTotal == -1){ //Comparo si eTotal es igual a menos uno porque en C los arreglos empiezan en cero, si comparara contra cero, el arreglo tendría un elemento. 
		
		printf("\nEl arreglo est%c vac%co", 160, 161);
		
	} else {
		
		ePos = BuscarBinario (aNombres, *eTotal, cNombre);
		
		if (ePos == -1){
			
			printf("No existe %s", cNombre);
			
		} else {
			
			for (eRecorre = ePos; eRecorre < *eTotal; eRecorre ++){
			
				strcpy(aNombres[eRecorre], aNombres[eRecorre + 1]);	//Para asignar un valor a una cadena.
			}
			
			(*eTotal) --;
			
			printf("\n%s borrado correctamente", cNombre);
		}
	}	
}

/*	
	Procedimiento: ModificarOrdenado.
	Objetivo: Modificar uno de los elementos de un arreglo.
	Autor: López Alejaldre Daniela Viridiana. 
	Fecha de creación: 23/mayo/2019.
	Fecha de última actualización: 30/mayo/2019. Grupo 2291. 
	DE: Arreglo de nombres (aNombres)
		Total de elementos del arreglo (eTotal).
		Elemento dentro del arreglo a modificar (cNombre).
		Elemento que deseamos añadir en lugar del elemento antigüo (cNuevo).
	DS: Modifica uno de los elementos que componen al arreglo.
*/		 	
void ModificarOrdenado (TaNombres aNombres, int eTotal, TaCadena cNombre, TaCadena cNuevo){
	
	if (eTotal == -1){
		
		printf("\nEl arreglo est%c vac%co", 160, 161);
		
	} else{
	
		if (BuscarBinario (aNombres, eTotal, cNombre) == -1){
		
				printf("\nNo existe %s", cNombre);
		
		} else{
		
			if (BuscarBinario(aNombres, eTotal, cNuevo) != -1){
				
				printf("\nYa existe %s", cNuevo);
						
			} else {
						
				EliminarOrdenado(aNombres, &eTotal, cNombre);
				InsertarOrdenado(aNombres, &eTotal, cNuevo);		
				printf("\n%s modificado correctamente", cNombre);
			}
		}
	}			
}

/*
	Función: BuscarBinario.
	DE: Arreglo de nombres (aNombres).
		Total de elementos en el arreglo (eTotal).
		Nombre a buscar (cNombre).
	DS: (Parámetros si hubiera).
	Retorna: La posición en la que se encuentra el elemento.
*/
int BuscarBinario (TaNombres aNombres, int eTotal, TaCadena cNombre){
	
	int eMenor, eMayor, eMedio;
	
	if (eTotal == -1){
		
		return -1;
		
	} else {
		
		eMenor = 0;
		eMayor = eTotal;
		eMedio = (eMayor + eMenor) / 2;
		
		while (eMenor < eMayor && strcmp(aNombres[eMedio], cNombre) != 0){
			
			if (strcmp(cNombre, aNombres[eMedio]) > 0){
				
				eMenor = eMedio + 1;
				
			} else {
				
				eMayor = eMedio - 1;
			}
		
			eMedio = (eMenor + eMayor) / 2;
		} 
	
		if (strcmp(aNombres[eMedio], cNombre) == 0){
		
			return eMedio;
		
		} else {
		
			return -1;
		}
	}
}

/*	
	Procedimiento: ListarArreglo.
	Objetivo: Mostrar todos los elementos de un arreglo.
	Autor: López Alejaldre Daniela Viridiana. 
	Fecha de creación: 23/mayo/2019.
	Fecha de última actualización: 30/mayo/2019. Grupo 2291. 
	DE: Arreglo de nombres (aNombres)
		Total de elementos del arreglo (eTotal).
	DS: Muestra todos los elementos del arreglo. 
*/
void ListarArreglo (TaNombres aNombres, int eTotal){
	
	if (eTotal != -1){
		
		ListarArreglo (aNombres, eTotal - 1);
		
		printf("\naNombres[%d] = %s", eTotal + 1, aNombres[eTotal]);
	}
}



