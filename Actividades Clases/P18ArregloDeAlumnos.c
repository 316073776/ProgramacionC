/* ***********************

	OBSERVACIONES:
 El programa funciona completamente.
 Agregue algunas funciones para dar formato a las pantallas,
 esto modificó algunos módulos (sólo para mejorar la interfaz de usuario)
 y obliga a agregar la biblioteca windows.h.
 Las funciones que agregué DEBEN MOVERSE a una biblioteca,
 yo no las moví para poder enviarles sólo un archivo.
 Espero que les sirva para mejorar sus proyectos
 
*********************** */

/*
 Programa: A18ArregloDeAlumnos.c
 Autor: Zarain Facundo Nicolas
 Fecha:  24/05/18
 Objetivo: Actualización de datos de alumnos en un arreglo ordenado
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>		//OJO: se usa esta biblioteca para el marco

//Constantes
#define MAX_ALUM 50
#define MAX_CAL 6

//Tipos
typedef char TcCadena[30];
typedef struct {
 
	TcCadena cApPat, cApMat, cNombre;
} TrNombre;

typedef struct {

	int eDia, eMes, eAnio;
} TrFecha;

typedef float TaCalif[MAX_CAL];

typedef struct {
 
	TrNombre rNombre;
	TrFecha rFecNac;
	TaCalif aCalif;
	TcCadena cNumCta, cNumCel;    
} TrAlumno;

typedef TrAlumno TaAlumnos[MAX_ALUM];

//Prototipos
TrNombre LeerNombre(TcCadena);
TrAlumno LeerAlumno();
int BuscarAlumno(TaAlumnos, int, TrNombre);

void InsertarAlumno(TaAlumnos, int *, TrAlumno);
void BorrarAlumno(TaAlumnos, int *, TrNombre);
void ModificarAlumno(TaAlumnos, int, TrNombre);
void ConsultarAlumno(TaAlumnos, int, TrNombre);
int ListarAlumnos(TaAlumnos, int, int);

void LeerArchivo (TaAlumnos, int *);
void EscribirArchivo(TaAlumnos, int);

//estos prototipos deben ir en una biblioteca junto con las funciones
//MOVER A UNA BIBIOTECA
void marco(char [90]); 
void centrar(char *, int);
void gotoxy (int, int);
void linea(int);
void escribir(int, int, char []);
void mensaje(char [90]); 
void pausa();

//Programa Principal
int main(void){
 
	int eOpcion, eTotal;
	TaAlumnos aAlumnos;
	TrAlumno rAlumno, rNuevoAlumno;
	TrNombre rNombre;
	
	eTotal = -1;
	LeerArchivo(aAlumnos, &eTotal);
	
	do {
	
		marco("Sistema de Alumnos");
		
		escribir(10, 47, "1.- Alta Alumno");
		escribir(11, 47, "2.- Baja Alumno");
		escribir(12, 47, "3.- Cambios Alumno");
		escribir(13, 47, "4.- Consultar por nombre");
		escribir(14, 47, "5.- Listar Alumnos");
		escribir(15, 47, "6.- Salir del Programa");
		
		gotoxy(18, 48);
		printf("Seleccione una opci%cn: ", 162);
		scanf("%d", &eOpcion);				
		
		switch (eOpcion){
		
			case 1:	marco("--- Alta de Alumnos ---");
					rAlumno = LeerAlumno("a insertar: ");
					InsertarAlumno(aAlumnos, &eTotal, rAlumno);
					break;
			
			case 2: marco("--- Baja de Alumnos ---");
					rNombre = LeerNombre("a borrar: ");
					BorrarAlumno(aAlumnos, &eTotal, rNombre);
					break;
			
			case 3: marco("--- Cambio de Datos de un Alumno ---");
					rNombre = LeerNombre("a modificar: ");					
					ModificarAlumno(aAlumnos, eTotal, rNombre);
					break;
			 
			case 4: marco("--- Consulta de Alumnos ---");
					rNombre = LeerNombre("a consultar: ");
					ConsultarAlumno(aAlumnos, eTotal, rNombre);
					break;  
			
			case 5: marco("--- Lista de alumnos ordenados por nombre ---");
					ListarAlumnos(aAlumnos, eTotal, 4);
					mensaje("Presione una tecla para continuar.");
					break;
			
			case 6:	marco("Sistema de Alumnos");
					centrar("Programa terminado...", 13);
					break;
			
			default: mensaje("Opcion incorrecta");
					 break;
		}
		
		pausa();
	
	} while(eOpcion != 6);
	
	EscribirArchivo(aAlumnos, eTotal);	

} //Fin de programa principal

/*
	Función: LeerNombre.c
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Leer apellido paterno, materno y nombre de un alumno.
	DE: cTexto- Texto a mostrar para la lectura
	DS: Registro con apellido paterno, materno y nombre
*/
TrNombre LeerNombre(TcCadena cTexto){
 
	TrNombre rNombre;
	char cInstruccion[90] = "Ingrese el nombre del alumno ";
	
	strcat(cInstruccion, cTexto);
	//muestra interfaz
	centrar(cInstruccion, 6);
	linea(7);
	escribir( 9, 15, "Apellido paterno: ");
	escribir(10, 15, "Apellido materno: ");
	escribir(11, 15, "Nombre: ");

	//lee los datos
	gotoxy(9, 35);
	fflush(stdin);
	gets(rNombre.cApPat);

	gotoxy(10, 35);
	fflush(stdin);
	gets(rNombre.cApMat);

	gotoxy(11, 35);
	fflush(stdin);
	gets(rNombre.cNombre);
	
	//regresa registro leido
	return rNombre;
 
} //Fin Función LeerNombre

/*
	Procedimiento: LeerAlumno
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Leer los datos de un alumno
	DE:
	DS: Registro con Nombre completo, Número de cuenta, Número de celular, Fecha de
	 	nacimiento y 6 calificaciones
*/
TrAlumno LeerAlumno(){
 
	int eCalif;
	TrAlumno rAlumno;
	
	//muestra interfaz
	centrar("Ingrese los datos del alumno:", 4);
	linea(5);
	escribir(7, 5, "Apellido paterno: ");
	escribir(8, 5, "Apellido materno: ");
	escribir(9, 5, "Nombre: ");
	linea(10);
	escribir(12, 5, "Numero de cuenta: ");
	escribir(13, 5, "Numero de celular: ");
	linea(14);
	escribir(15, 5, "Fecha de nacimiento:");
	escribir(16, 10, "Dia: ");
	escribir(17, 10, "Mes: ");
	escribir(18, 10, "Anio: ");
	linea(19);
	escribir(20, 5, "Calificaciones:");

	//lee datos
	gotoxy(7, 25);
	fflush(stdin);
	gets(rAlumno.rNombre.cApPat);
	
	gotoxy(8, 25);
	fflush(stdin);
	gets(rAlumno.rNombre.cApMat);
	
	gotoxy(9, 25);
	fflush(stdin);
	gets(rAlumno.rNombre.cNombre);	

	gotoxy(12, 25);
	fflush(stdin);
	gets(rAlumno.cNumCta);	

	gotoxy(13, 25);
	fflush(stdin);
	gets(rAlumno.cNumCel);
	
	gotoxy(16, 25);
	scanf("%d", &rAlumno.rFecNac.eDia);
	gotoxy(17, 25);
	scanf("%d", &rAlumno.rFecNac.eMes);
	gotoxy(18, 25);
	scanf("%d", &rAlumno.rFecNac.eAnio);
	
	printf("\n\n");
	
	for (eCalif = 0; eCalif < MAX_CAL; eCalif ++){
	
		printf("\tCalificaci%cn %d: ", 162, eCalif + 1);
		scanf("%f", &rAlumno.aCalif[eCalif]);
	}
	
	//regresa el registro
	return rAlumno;

} //LeerAlumno

/*
 	Procedimiento: InsertarAlumno
	Autor:Facundo Zarain 
 	Fecha: 24/05/2018
 	Objetivo: insertar un registro de un alumno
 	DE: aAlumnos- arreglo de alumnos
    	eTotal- número de alumnos en el arreglo
     	rAlumno- registro con los datos del alumno a insertar
*/
void InsertarAlumno(TaAlumnos aAlumnos, int *eTotal, TrAlumno rAlumno){
 
	int ePos, eRecorre;
	TcCadena cNombre = "", cRecorre = "";
	
	strcat(strcat(strcat(strcat(strcat(cNombre, rAlumno.rNombre.cNombre), " "), 
		rAlumno.rNombre.cApPat), " "), rAlumno.rNombre.cApMat);
	
	if (*eTotal == MAX_ALUM - 1){
	
		mensaje("No hay espacio en el arreglo.");
	
	} else {
	
		if (*eTotal == -1 || strcmp (rAlumno.rNombre.cNombre, aAlumnos[*eTotal].rNombre.cNombre) > 0){
		
			(*eTotal)++;
			aAlumnos[*eTotal] = rAlumno;

			mensaje(strcat(cNombre, " registrado correctamente."));
		
		} else {
		
			ePos = BuscarAlumno(aAlumnos, *eTotal, rAlumno.rNombre);
			
			if (ePos != -1){
			
				mensaje(strcat(cNombre, " ya existe."));
			
			} else {
			
				eRecorre = *eTotal;
								
				strcat(strcat(strcat(strcat(strcat(cRecorre, aAlumnos[eRecorre].rNombre.cNombre), 
					" "), aAlumnos[eRecorre].rNombre.cApPat), " "),
					aAlumnos[eRecorre].rNombre.cApMat);
				
				while (eRecorre > -1 && strcmp (cNombre, cRecorre) < 0){
				
					aAlumnos[eRecorre + 1] = aAlumnos[eRecorre];
					eRecorre --;
					
					strcpy(cRecorre, "");
					strcat(strcat(strcat(strcat(strcat(cRecorre, aAlumnos[eRecorre].rNombre.cNombre), 
						" "), aAlumnos[eRecorre].rNombre.cApPat), " "),
						aAlumnos[eRecorre].rNombre.cApMat);
				}
			
				aAlumnos[eRecorre + 1] = rAlumno;
				(*eTotal) ++;
				
				mensaje(strcat(cNombre, " registrado correctamente."));						
			}
		}
	}
}//InsertarAlumno

/*
	Procedimiento: BorrarAlumno
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Borrar un registro de un alumno
	DE: aAlumnos- arreglo de alumnos
		eTotal- número de alumnos en el arreglo
		rNombre- registro con el nombre del alumno a borrar
*/
void BorrarAlumno(TaAlumnos aAlumnos, int *eTotal, TrNombre rNombre){
 
	int ePos, eRecorre;
	char cRespuesta;
	TcCadena cNombre = "";
	
	strcat(strcat(strcat(strcat(strcat(cNombre, rNombre.cNombre), " "), 
		rNombre.cApPat), " "), rNombre.cApMat);
	
	if (*eTotal == -1){
	
		mensaje("No hay datos.");
	
	} else {
	
		ePos = BuscarAlumno(aAlumnos, *eTotal, rNombre);
		
		if (ePos == -1){
		
			mensaje(strcat(cNombre, " no encontrado."));						
				
		} else {
		
			marco("--- Baja de Alumnos ---");
			ConsultarAlumno(aAlumnos, *eTotal, rNombre);
			mensaje(" ");
			
			centrar("Desea borrar el registro [S/N]? ", 22);
			cRespuesta = getchar();
			
			if (toupper(cRespuesta) == 'S') {

				for (eRecorre = ePos; eRecorre <= *eTotal - 1; eRecorre ++){
			
					aAlumnos[eRecorre] = aAlumnos[eRecorre + 1];
				}
				
				(*eTotal) --;
				
				mensaje(strcat(cNombre, " borrado correctamente."));						
				
			} else {
				
				mensaje("El registro no ha sido borrado.");						
			}
		}
	}
} //Fin Procedimiento BorrarAlumno

/*
	Procedimiento: ModificarAlumno
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Modificar un registro de un alumno
	DE: aAlumnos- arreglo de alumnos
		eTotal- número de alumnos en el arreglo
		rNombre- registro con el nombre del alumno a modificar
		rAlumno- registro con los nuevos datos del alumno a modificar
*/
void ModificarAlumno(TaAlumnos aAlumnos, int eTotal, TrNombre rNombre){

	int ePos, eDato, eCalif;
	float fCalif;
 	TcCadena cNombre = "";
	
	strcat(strcat(strcat(strcat(strcat(cNombre, rNombre.cNombre), " "), 
		rNombre.cApPat), " "), rNombre.cApMat);

	if (eTotal == -1) {
	
		mensaje("No hay datos.");
	
	} else {
	
		ePos = BuscarAlumno(aAlumnos, eTotal, rNombre);
		
		if (ePos == -1){
					
			mensaje(strcat(cNombre, " no encontrado."));						
		
		} else {
		
			do {
			
				marco("--- Cambio de Datos de un Alumno ---");
				ConsultarAlumno(aAlumnos, eTotal, rNombre);
				mensaje(" ");

				gotoxy(13, 50);
				printf("1. N%cmero de cuenta", 163);
				gotoxy(14, 50);
				printf("2. N%cmero de celular", 163);
				escribir(15, 50, "3. Fecha de nacimiento");
				escribir(16, 50, "4. Calificaciones");
				escribir(17, 50, "0. Regresar");
				
				escribir(19, 50, "                                                               ");
				escribir(21, 50, "                                                               ");
				escribir(22, 50, "                                                               ");
				escribir(23, 50, "                                                               ");
				escribir(24, 50, "                                                               ");
				
				gotoxy(19, 50);
				printf("Ingrese el n%cmero del dato a modificar: ", 163);
				scanf("%d", &eDato);
				
				switch(eDato) {
					case 1: gotoxy(21, 50);
							printf("N%cmero de cuenta: ", 163);
							fflush(stdin);
							gets(aAlumnos[ePos].cNumCta);
							break;
							
					case 2: gotoxy(21, 50);
							printf("N%cmero de celular: ", 163);
							fflush(stdin);
							gets(aAlumnos[ePos].cNumCel);
							break;
	
					case 3:	escribir(21, 50, "Fecha de nacimiento:");
							gotoxy(22, 58);
							printf("D%ca: ", 161);
							scanf("%d", &aAlumnos[ePos].rFecNac.eDia);
							gotoxy(23, 58);
							printf("Mes: ");
							scanf("%d", &aAlumnos[ePos].rFecNac.eMes);
							gotoxy(24, 58);
							printf("A%co: ", 164);
							scanf("%d", &aAlumnos[ePos].rFecNac.eAnio);
							break;

					case 4: gotoxy(21, 50);
							printf("Ingrese el n%cmero de la calificaci%cn a modificar: ", 163, 162);
							scanf("%d", &eCalif);
					
							if (eCalif >= 1 && eCalif <= 6){
					
								gotoxy(23, 52);
								printf("Ingrese la calificaci%cn %d: ", 162, eCalif);
								scanf("%f", &aAlumnos[ePos].aCalif[eCalif - 1]);
							}
							break;
							
					case 0: mensaje(strcat(cNombre, " modificado correctamente."));
							break;
							
					default: gotoxy(21, 50);
							 printf("Error en la selecci%cn", 162);
							 pausa();
				}
				
			} while (eDato != 0);			
		}
	}
} //Fin Procedimiento ModificarAlumno

/*
	Procedimiento: ConsultarAlumno
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Mostrar todos los datos de un alumnos
	DE: aAlumnos- arreglo de alumnos
	 	eTotal- número de alumnos en el arreglo
	 	rNombre- registro con el nombre del alumno a consultar
*/
void ConsultarAlumno(TaAlumnos aAlumnos, int eTotal, TrNombre rNombre){
 
	int ePos, eCalif;
	float fSuma = 0.0f;
 	TcCadena cNombre = "";
	
	strcat(strcat(strcat(cNombre, rNombre.cNombre), rNombre.cApPat), rNombre.cApMat);
	
	if (eTotal == -1){
	
		mensaje("No hay datos.");
	
	} else {
	
		ePos = BuscarAlumno(aAlumnos, eTotal, rNombre);
		
		if (ePos == -1){
		
			mensaje(strcat(cNombre, " no encontrado."));						
		
		} else {
		
			marco("--- Consulta de Alumnos ---");
			escribir(4, 5, "Nombre: ");
			printf("%s %s %s", aAlumnos[ePos].rNombre.cApPat, aAlumnos[ePos].rNombre.cApMat,
						aAlumnos[ePos].rNombre.cNombre);
			
			linea(5);
			escribir(6, 5, "Numero de cuenta: ");
			printf("%s", aAlumnos[ePos].cNumCta);
			escribir(7, 5, "Numero de celular: ");
			printf("%s", aAlumnos[ePos].cNumCel);
			linea(8);
			escribir(9, 5, "Fecha de nacimiento: ");
			printf("%02d/%02d/%02d", aAlumnos[ePos].rFecNac.eDia,
				aAlumnos[ePos].rFecNac.eMes, aAlumnos[ePos].rFecNac.eAnio);
			linea(10);
			escribir(11, 5, "Calificaciones:\n");			
			
			for (eCalif = 0; eCalif < MAX_CAL; eCalif ++){
			
				printf("\n\tCalificaci%cn %d: %5.1f", 162, eCalif + 1, aAlumnos[ePos].aCalif[eCalif]);
				fSuma += aAlumnos[ePos].aCalif[eCalif];
			}
			
			gotoxy(20, 5);
			printf("Promedio: %6.1f", fSuma / 6);
			mensaje("Presione una tecla para continuar.");
		}  
	}
} //Fin Procedimiento ConsultarAlumno

/*
	Procedimiento: ListarAlumnos
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Mostrar un listado de todos los alumnos
	DE: aAlumnos- arreglo de alumnos
		 eTotal- número de alumnos en el arreglo
*/
int ListarAlumnos(TaAlumnos aAlumnos, int eTotal, int eRen){
 
	int eCalif;
	
	if (eTotal == -1 || eRen == 27){
	
		marco("--- Lista de alumnos ordenados por nombre ---");
		escribir(3, 1, "No.Cta    Nombre\t\t\t\t\t\t  Num.Cel.   Fec.Nac.   Cal1 Cal2 Cal3 Cal4 Cal5 Cal6");
		linea(4);
		
	} else {  
	
		eRen = ListarAlumnos(aAlumnos, eTotal - 1, eRen) + 1;
		
		if (eRen == 27){
	
			mensaje("Presione una tecla para continuar.");
			pausa();
			marco("--- Lista de alumnos ordenados por nombre ---");
			escribir(3, 1, "No.Cta    Nombre\t\t\t\t\t\t  Num.Cel.   Fec.Nac.   Cal1 Cal2 Cal3 Cal4 Cal5 Cal6");
			linea(4);
			eRen = 5;	
		}
		
		gotoxy(eRen, 1);
		printf("%-9s %-15s %-15s %-22s %-10s %02d/%02d/%02d  ", 
			aAlumnos[eTotal].cNumCta,
			aAlumnos[eTotal].rNombre.cApPat, 
			aAlumnos[eTotal].rNombre.cApMat, 
			aAlumnos[eTotal].rNombre.cNombre, 
			aAlumnos[eTotal].cNumCel, 
			aAlumnos[eTotal].rFecNac.eDia, 
			aAlumnos[eTotal].rFecNac.eMes, 
			aAlumnos[eTotal].rFecNac.eAnio);
	
		for (eCalif = 0; eCalif < MAX_CAL; eCalif ++){
	
			printf("%5.1f", aAlumnos[eTotal].aCalif[eCalif]);
		}
	}
	
	return eRen;
}//Fin ListarAlumnos

/*
	Procedimiento: BuscarAlumno
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Buscar un alumno por nombre en un arreglo
	DE: aAlumnos- arreglo de alumnos
		 eTotal- número de alumnos en el arreglo
		 rNombre- registro con el nombre del alumno a localizar
*/
int BuscarAlumno(TaAlumnos aAlumnos, int eTotal, TrNombre rNombre){
	
	int eMedio, eMenor, eMayor;
	TcCadena cNombre = "", cMedio = "";
	
	if (eTotal == -1){
	
		return -1;
	
	} else {
	
		eMenor = 0;
		eMayor = eTotal;
		eMedio = (eMenor + eMayor) / 2;
		
		strcat(strcat(strcat(cNombre, rNombre.cNombre), rNombre.cApPat), rNombre.cApMat);
		strcat(strcat(strcat(cMedio, aAlumnos[eMedio].rNombre.cNombre), 
			aAlumnos[eMedio].rNombre.cApPat), aAlumnos[eMedio].rNombre.cApMat);
		
		while ( eMenor < eMayor && strcmp (cNombre, cMedio) != 0){
		      
			if (strcmp (cNombre, cMedio) < 0){
			
				eMayor = eMedio - 1;
			
			} else {
			
				eMenor = eMedio + 1;
			}
			
			eMedio = (eMenor + eMayor) / 2;
			
			strcpy(cMedio, "");
			strcat(strcat(strcat(cMedio, aAlumnos[eMedio].rNombre.cNombre), 
			aAlumnos[eMedio].rNombre.cApPat), aAlumnos[eMedio].rNombre.cApMat);
		}
		
		if (strcmp (cNombre, cMedio) == 0){
		
			return eMedio;
		
		} else {
		
			return -1;
		}
	}
} //Fin BuscarAlumno

/*
	Procedimiento: EscribirArchivo
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Buscar un alumno por nombre en un arreglo
	DE: aAlumnos- arreglo de alumnos
		 eTotal- número de alumnos en el arreglo
		 rNombre- registro con el nombre del alumno a localizar
*/
void EscribirArchivo(TaAlumnos aAlumnos, int eTotal){
        
	FILE *fArchivo;
	int ePos;
	
	if ((fArchivo = fopen("Alumnos.dat", "wb+")) == NULL) {
	
		printf("\nError al escribir en archivo\n");
		
	} else {
		
		for(ePos = 0; ePos <= eTotal; ePos++) {
		
			fwrite(&aAlumnos[ePos], sizeof(TrAlumno), 1, fArchivo);
		}
		
		fclose(fArchivo);        
	}
}//EscribirArchivo

/*
	Procedimiento: LeerArchivo
	Autor:Facundo Zarain 
	Fecha: 24/05/2018
	Objetivo: Buscar un alumno por nombre en un arreglo
	DE: aAlumnos- arreglo de alumnos
	 	eTotal- número de alumnos en el arreglo
	 	rNombre- registro con el nombre del alumno a localizar
*/
void LeerArchivo (TaAlumnos aAlumnos, int *eTotal){
        
	TrAlumno rAlumno;
	FILE *fArchivo;
	
	if ((fArchivo = fopen("Alumnos.dat", "rb+")) != NULL) {
	
		rewind(fArchivo);
		fread(&rAlumno, sizeof(rAlumno), 1, fArchivo);
		
		while(! feof(fArchivo)) {
		
			InsertarAlumno(aAlumnos, eTotal, rAlumno);
			fread(&rAlumno, sizeof(rAlumno), 1, fArchivo);
		}
		
		fclose(fArchivo);
	}
}//leerArchivo


//estas funcioes deben ir en una biblioteca junto con sus prototipos
//MOVER A UNA BIBIOTECA
//gotoxy: coloca el cursor de la pantalla en un renglon (eRen) y columna (eCol) especificados
void gotoxy (int eRen, int eCol) {
	
	HANDLE salida;	//manejador de recursos de windows
	COORD coord;	//objeto coordenada
	
	salida = GetStdHandle(STD_OUTPUT_HANDLE);	//obtiene manejador de salida estándar

	coord.Y = eRen;	//pone coordenada Y
	coord.X = eCol;	//pone coordenada X
	SetConsoleCursorPosition(salida, coord);	//mueve el cursor	
} //gotoxy

//marco: dibuja un borde en la pantalla
void marco(char cTitulo[]) {

	int eCol, eRen, eMaxRen = 27, eMaxCol = 118;
	HANDLE salida;	//manejador de recursos de windows
	COORD coord;	//objeto coordenada
	
	salida = GetStdHandle(STD_OUTPUT_HANDLE);	//obtiene manejador de salida estándar
	system ("color 1E"); 	//cambia color 1=azul fondo E=amarillo texto
	system ("cls");			//limpia la pantalla 

	printf ("%c", 201);  	//caracter esquina superior izquierda

	for (eCol = 1; eCol < eMaxCol; eCol++) {

		gotoxy(0, eCol);
		printf("%c", 205);	//línea superior
	}
	
	printf("%c",187);		//esquina superior derecha

	for (eRen = 1; eRen < eMaxRen; eRen++) {

		gotoxy(eRen, 0);		//borde izquierdo
		printf("%c", 186);

		gotoxy(eRen, eMaxCol);		//borde derecho
		printf("%c", 186);
	}
	
	printf("\n%c", 200);			//esquina inferior izquierda
	
	for (eCol = 1; eCol < eMaxCol; eCol++) {

		gotoxy(2, eCol);		//línea bajo título
		printf("%c",205);
	}
	
	for (eCol = 1; eCol < eMaxCol; eCol++) {

		gotoxy(eMaxRen, eCol);		//línea inferior
		printf("%c", 205);
	}

	printf("%c", 188);			//esquina inferior derecha
	
	centrar(cTitulo, 1);	//título
} //marco

//centrar: muestra en texto (cTexto) centrado en la pantalla en el renglón (eRen)
void centrar(char *cTexto, int eRen) {
	
	//limpia la línea
	gotoxy (eRen, 2);
	printf("                                                                             ");
		  //12345678901234567890123456789012345678901234567890123456789012345678901234567 (80 columnas - 3)
	
	//centra texto
	gotoxy(eRen, (118 - strlen(cTexto)) / 2);
	printf ("%s", cTexto);
} //centrar

//linea: muestra una línea en el renglón indicado
void linea(int eRen){
	
	int eCol;
		
	for (eCol = 1; eCol < 118; eCol++) {

		gotoxy(eRen, eCol);		//línea 
		printf("%c", 196);
	}
}

//escribe un texto en el reglón y columna especificados
void escribir(int eRen, int eCol, char cTexto[]){
	
	gotoxy(eRen, eCol);
	printf("%s", cTexto);
}

//muestra un mensaje en la última línea de la pantalla
void mensaje(char cTexto[90]){
	
	gotoxy (28, 1);
	printf("                                                                               ");
	centrar(cTexto, 28);
}

//muestra una flecha y detiene el programa
void pausa(){

	printf("<%c%c", 196, 217);
	fflush(stdin);
	getchar();
}
//MOVER HASTA AQUI A UNA BIBIOTECA
