/****************************************
NOMBRE DEL PROGRAMA: ExamenDiagnóstico.c
COPYRIGHT: SR 2019
AUTOR: Segura Rios Brenda Stephanie
OBJETIVO: Realizar exámen diagnóstico acerca de arreglos estáticos.
FECHA: 12/08/2019
*****************************************/
//LIBRERÍAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TIPOS
typedef char cCadena[30];

//ARREGLOS 
cCadena aNombre[5]={"Pedro", "Miguel Angel", "Juan Carlos", "Sebastian", "Andres"};
int Pedro [3] = {3,5,7};
int MiguelA [3] = {4,3,2};
int JuanC [3] = {7,7,7};
int Sebastian [3] = {9,4,2};
int Andres [3] = {6,3,8};

//PROTOTIPOS
void MultiplicarArreglo(int);
void Promedio(void);
int BuscarElemento (int);
void DesplegarNombres (int);
void ModificarNombre (cCadena);
void ModificarValores(int, int);
void MostrarTabla (void);

/* ----------------------------------------------------------------------
NOMBRE:main
TIPO: void
ARGUMENTOS: N/A
OBJETIVO: Función que declara un arreglo, lo inicializa, lo manipula y
        lo imprime en pantalla.
---------------------------------------------------------------------- */
int main (){
	
	int eOpcion, eNumero, eBuscar, eNuevo;
	char cOpcion;
	cCadena sModifica;
	
	printf("\nNOMBRE:\tSegura Rios Brenda Stephanie\n\n");
	
	do {
		printf("\tMen%c\n"
				"1. Parte I Pr%cctica.\n"
				"2. Parte Final.\n"
				"0. Salir\n\n"
				"Seleccione una opci%cn: ", 163, 160, 162);
		scanf("%d", &eOpcion);
		system("cls");
		
		switch(eOpcion){
		
			case 1: printf("\n\n\tIngrese un n%cmero entero: ", 163);
					scanf("%d", &eNumero);
				 	MultiplicarArreglo(eNumero);
				 	system("cls");
					break;
					
			case 2: system("cls");
					fflush(stdin);
					do {
						system("cls");
						fflush(stdin);
						printf("\n\n\tMen%c\n"
								"a. Desplegar promedio.\n"
								"b. Desplegar ocurrencias.\n"
								"c. Modificar nombre.\n"
								"d. Hacer reemplazo.\n"
								"e. Desplegar datos.\n"
								"f. Salir al men%c principal.\n\n"
								"Seleccione una opci%cn: ", 163, 163, 162);
						cOpcion = getchar();
						
						switch (cOpcion){
							
							case 'a':system("cls");
									Promedio();
									system("pause");
									system("cls");		
							break;
							
							case 'b':system("cls");
									fflush(stdin);
									printf("\n\tIngrese el n%cmero que desea buscar: ", 163);
									scanf("%d", &eBuscar);
									DesplegarNombres(eBuscar);
							break;
							
							case 'c':system("cls");
									fflush(stdin); 
									printf("\n\tIngrese el nombre que desea modificar: ", 40, 41);
									scanf("%s", sModifica);
									ModificarNombre(sModifica);
									system("pause");
							break;
							
							case 'd':system("cls");
									fflush(stdin); 
									printf("\n\n\tIngrese el valor que dese modificar: ");
									scanf("%d", &eNumero);
									printf("\n\tIngrese el nuevo valor: ");
									scanf("%d", &eNuevo);
									printf("\n\n");
									ModificarValores(eNumero, eNuevo);
									system("pause");
							break;
							
							case 'e':system("cls");
									fflush(stdin); 
									printf("\n\n");
									MostrarTabla ();
									printf("\n\n");
									system("pause");
							break;	
						}
					system("cls");
					} while (cOpcion != 'f');
		}
		
		fflush(stdin);
				
	} while (eOpcion != 0);
	
		if (eOpcion = 0){
			printf("Hasta luego.");
		}

	fflush(stdin);
	getchar();
	return 0;
	
}

/* ----------------------------------------------------------------------
NOMBRE:MultiplicarArreglo
TIPO:void
ARGUMENTOS: eNumero que indica en número a miltiplicar.
OBJETIVO: Multiplicar arreglo de 10 números por uno ingresado por usuario. 
---------------------------------------------------------------------- */
void MultiplicarArreglo(int eNumero){
	
		int Arreglo [10] = {3, 6, 90, 12, 33, 69, 96, 1313, 121, 88};
		int eContador, eTotal;
		
		printf("\n\nEl arreglo a multiplicar por [%d] es:", eNumero);
		for ( eContador = 0; eContador < 10; eContador ++){
			printf("[%d] ", Arreglo[eContador]);
		}
		
		for ( eContador = 0; eContador < 10; eContador ++){
			Arreglo[eContador] = Arreglo[eContador] * eNumero;
		}
		
		printf("\nEl arreglo final es:");
		for ( eContador = 0; eContador < 10; eContador ++){
			printf("[%d] ", Arreglo[eContador]);
		}
	printf("\n\n");
	fflush(stdin);
	system("pause");
}

/* ----------------------------------------------------------------------
NOMBRE: Promedio
TIPO:void
ARGUMENTOS: N/A
OBJETIVO: Promedio de los valores asignados a cada persona . 
---------------------------------------------------------------------- */
void Promedio(void){
	
	int eContador;
	float fTotal[5];

	for (eContador = 0; eContador < 3; eContador ++){
		
		fTotal[0] += Pedro[eContador];
		fTotal[1] += MiguelA[eContador];
		fTotal[2] += JuanC[eContador];
		fTotal[3] += Sebastian[eContador];
		fTotal[4] += Andres[eContador];
		
	}	
	
	printf("\n\n");
	for ( eContador = 0; eContador < 5; eContador ++){
		printf("\tEl promedio total de %s es: \t\t\t %.2f \n", aNombre[eContador], fTotal[eContador]/3);
	}
	printf("\n");
}

/* ----------------------------------------------------------------------
NOMBRE: DesplegarNombres
TIPO:void
ARGUMENTOS: eBuscar de tipo entero, es el numero a buscar en la lista.
OBJETIVO: Desplega los nombres de las personas que tienen el número ingresado
			en su registro.
---------------------------------------------------------------------- */
void DesplegarNombres (int eBuscar){
	
	int eContador;
	
	printf("\nLas personas que tienen el n%cmero [%d] en su registro son:\n\n", 163, eBuscar);
	
	for (eContador == 0; eContador < 3; eContador ++){
			
			if(eBuscar == Pedro[eContador]){
				printf("\t\t%s\n", aNombre[0]);		
			}
			if (eBuscar == MiguelA[eContador]){
				printf("\t\t%s\n", aNombre[1]);				
			}
			if(eBuscar == JuanC[eContador]){
				printf("\t\t%s\n", aNombre[2]);				
			}
			if(eBuscar == Sebastian[eContador]){
				printf("\t\t%s\n", aNombre[3]);				
			}
			if(eBuscar == Andres[eContador]){
				printf("\t\t%s\n", aNombre[4]);					
			}
		}
	
	printf("\n\n");
	system("pause");
	
}
	
/* ----------------------------------------------------------------------
NOMBRE:Modificar nombre
TIPO:void
ARGUMENTOS: sModificar es el nombre que se quiere cambiar.
OBJETIVO:Modificar el nombre que se indique.
---------------------------------------------------------------------- */
void ModificarNombre (cCadena sModificar){
	
	int eContador;
	cCadena sNuevo;
	
	for (eContador = 0; eContador < 5; eContador ++){
		
		if (strcmp(sModificar, aNombre[eContador]) == 0){
			
			printf("\n\tIngrese el nuevo nombre: ");
			scanf("%s", sNuevo);
			strcpy(aNombre[eContador], sNuevo);
			printf("\n\n\tEl nuevo nombre es %s\n\n", sNuevo);
			
		} 
	}
}

/* ----------------------------------------------------------------------
NOMBRE:Modificar valores
TIPO:void
ARGUMENTOS: eNumero es el numero que se desea cambiar y eNuevo es el nuevo número.
OBJETIVO:Reemplazar valores del registro.
---------------------------------------------------------------------- */
void ModificarValores(int eNumero, int eNuevo){
	
	int eContador;
		
	for (eContador == 0; eContador < 3; eContador ++){
		
		if (Pedro[eContador] == eNumero){
			printf("Se cambi%c [%d] por [%d] en %s\n", 162, Pedro[eContador], eNuevo, aNombre[0]);
			Pedro[eContador] = eNuevo;
		}
		if (MiguelA[eContador] == eNumero){
			printf("Se cambi%c [%d] por [%d] en %s\n", 162, MiguelA[eContador], eNuevo, aNombre[1]);
			MiguelA[eContador] = eNuevo;
		}
		if (JuanC[eContador] == eNumero){
			printf("Se cambi%c [%d] por [%d] en %s\n", 162, JuanC[eContador], eNuevo, aNombre[2]);
			JuanC[eContador] = eNuevo;
		}		
		if (Sebastian[eContador] == eNumero){
			printf("Se cambi%c [%d] por [%d] en %s\n", 162, Sebastian[eContador], eNuevo, aNombre[3]);
			Sebastian[eContador] = eNuevo;
		}	
		if (Andres[eContador] == eNumero){
			printf("Se cambi%c [%d] por [%d] en %s\n", 162, Andres[eContador], eNuevo, aNombre[4]);
			Andres[eContador] = eNuevo;
		}		
	}
	printf("\n\n");	
}	

/* ----------------------------------------------------------------------
NOMBRE:Mostrar tabla.
TIPO:void
ARGUMENTOS: N/A
OBJETIVO:Desplegar contenido de los arreglos.
---------------------------------------------------------------------- */
void MostrarTabla (void){ 

int eContador1, eContador2;

	printf("\n %s\t\t\t\t", aNombre[0]);		
	for (eContador2 = 0; eContador2 < 3; eContador2 ++){
		printf("[%d] ", Pedro[eContador2]);
	}	
	printf("\n %s\t\t\t", aNombre[1]);
	for (eContador2 = 0; eContador2 < 3; eContador2 ++){	
		printf("[%d] ", MiguelA[eContador2]);
	}	
	printf("\n %s\t\t\t", aNombre[2]);
	for (eContador2 = 0; eContador2 < 3; eContador2 ++){
		printf("[%d] ", JuanC[eContador2]);
	}	
	printf("\n %s\t\t\t", aNombre[3]);
	for (eContador2 = 0; eContador2 < 3; eContador2 ++){
		printf("[%d] ", Sebastian[eContador2]);
	}	
	printf("\n %s\t\t\t\t", aNombre[4]);
	for (eContador2 = 0; eContador2 < 3; eContador2 ++){
		printf("[%d] ", Andres[eContador2]);
	}	
}

