/*Programa: P20ArregloDesordenado.c
Autor: López Alejaldre Daniela Viridiana
Fecha: 23 de mayo del 2019.
Objetivo: Mostrar las operaciones que se pueden realizar con un arreglo desordenado
*/
#include <stdio.h>
#define MAX 10

typedef int TaNumeros[MAX];

//Protitpos de los procedimientos/funciones. 
void InsertarDesordenado(TaNumeros, int *eTotal, int); //A insertar le paso eTotal por referencia como *eTotal.
void EliminarDesordenado(TaNumeros, int *eTotal, int); //Solo tipos de variables, no nombres. 
int BuscarSecuencial (TaNumeros, int, int);
void ModificarDesordenado (TaNumeros, int, int, int);
void ListarArreglo (TaNumeros, int);

//Función principal. 
int main (){
	
	TaNumeros aNumeros;
	int eOpcion, eTotal = -1, eElemento, eNuevo;
	 
	do {
		system ("cls");
		printf("Programa que muestra el manejo de arreglos desordenados");
		printf("\n1. Insertar\n\n2. Eliminar \n\n3. Modificar \n\n4. Buscar \n\n5. Listar \n\n6. Salir");
		printf("\nSeleccione una opci%cn: ", 162);
		scanf("%d", &eOpcion);
		
		switch (eOpcion){
			
			case 1: printf("\nIngrese el n%cmero a insertar: ", 163);
					scanf("%d", &eElemento);
					InsertarDesordenado (aNumeros, &eTotal, eElemento);
					break;
					
			case 2: printf("\nIngrese el n%cmero a eliminar: ", 163);
					scanf("%d", &eElemento);
					EliminarDesordenado (aNumeros, &eTotal, eElemento);
					break;
					
			case 3: printf("\nIngrese el n%cmero a modificar: ", 163);
					scanf("%d", &eElemento);
					printf("\nIngrese el nuevo valor: ");
					scanf("%d", &eNuevo);
					ModificarDesordenado (aNumeros, eTotal, eElemento, eNuevo); //Ejecuto un procedimiento. 
					break;
					
			case 4: printf("\nIngrese el n%cmero a buscar: ", 163);
					scanf("%d", &eElemento);
					eNuevo = BuscarSecuencial (aNumeros, eTotal, eElemento); //Mando a llamar a la función. 
					
					if (eNuevo == -1){
						
						printf("\n%d no existe", eElemento);
						
					} else {
						
						printf("\n%d est%c en la posici%cn %d", eElemento, 160, 162, eNuevo + 1);
					}
					break;
					
			case 5: printf("\nContenido del arreglo");
					ListarArreglo(aNumeros, eTotal);
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

void InsertarDesordenado(TaNumeros aNumeros, int *eTotal,
	 int eElemento){
	 	
		if (*eTotal == MAX - 1){
			
			printf("\nEl arreglo se encuentra lleno");	
			
		} else{
			
			(*eTotal) ++;
			aNumeros[*eTotal] = eElemento;
		} 
		printf("\nEl elemento ha sido insertado de forma correcta");
 
		
	
}

void EliminarDesordenado(TaNumeros aNumeros, int *eTotal, int eElemento){
	
		int eRecorre, ePos;
		
		if (*eTotal == -1){
			
			printf("\nEl arreglo est%c vac%co", 160, 161);
			
		} else {
			
			ePos = 0;
			while (ePos <= *eTotal && aNumeros[ePos] != eElemento){
				
				ePos ++;
			}
		
			if (aNumeros[ePos] != eElemento){
					
				printf("\nNo existe el elemento, %d", eElemento);
					
			} else {
				
				for (eRecorre = ePos; eRecorre < *eTotal; eRecorre ++){
					
					aNumeros[eRecorre] = aNumeros[eRecorre + 1];
				}
				 
				(*eTotal) --;
				
			} 
			printf("\nEl elemento ha sido eliminado de forma correcta");
		}
}
			
			
int BuscarSecuencial (TaNumeros aNumeros, int eTotal, int eElemento){
	
	int ePos;
	
	if (eTotal == -1){
		
		return 0;
		
	} else {
		
		ePos = 0;
		
		while (ePos <= eTotal && aNumeros[ePos] != eElemento){
			
			ePos ++;
		} 
		
		if (aNumeros[ePos] == eElemento){
			
			return ePos;
		} else {
			
			return 0;
		}
	}
}
		
		
	

void ModificarDesordenado (TaNumeros aNumeros, int eTotal, 
							int eElemento, int eNuevo){
								
	int ePos;
	
	if (eTotal == -1){
		
		printf("\nNo hay elementos");
		
	} else {
		
		ePos = BuscarSecuencial (aNumeros, eTotal, eElemento);
		
		if (ePos == -1){
			
			printf("\nNo existe, %d", eElemento);
			
		} else {
			
			aNumeros[ePos] = eNuevo;
		}
	}
}



void ListarArreglo (TaNumeros aNumeros, int eTotal){
	
	if (eTotal != -1){
		
		ListarArreglo (aNumeros, eTotal - 1);
			
		printf("\naNumeros[%d] = %d", eTotal + 1, aNumeros[eTotal]);
		
	} 
}
