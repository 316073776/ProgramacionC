#include <stdio.h>
typedef struct
{
char titulo[100];
char autor[80];
int anio;
char editorial[80];
int edicion;
} libro;

void escribir_registro( FILE *arch )
{
libro l;
char opcion;
do
{
	
printf("\n\n\nTitulo del libro: ");
fflush(stdin);
gets(l.titulo);
printf("\nAutor: ");
fflush(stdin);
gets(l.autor);
printf("\nAño: ");
scanf("%i", &l.anio);
printf("\nEditorial: ");
fflush(stdin);
gets(l.editorial);
printf("\nEdicion: ");
scanf("%i", &l.edicion);
fwrite(&l,sizeof(libro),1,arch); //escritura del registro
//en archivo
printf("\n\nDesea continuar: ");
opcion=getche();
}while(opcion != 'n');
}

void leer_registro(FILE *arch) {
libro l;
int tamanio=sizeof(libro);
rewind (arch);
while (fread (&l, tamanio, 1, arch) != 0 )
printf("%s %s %i %s %i\n", l.titulo, l.autor, l.anio, l.editorial, l.edicion);
}


main() {
FILE *arch;
int opcion;
arch=fopen("libros.dat","a+b");
if(arch != NULL) {
do {
printf("1. Dar de alta un libro\n2. Ver listado de libros\n0. Salir\n");
scanf("%i", &opcion);
switch(opcion) {
case 1:
escribir_registro(arch);
break;
case 2:
leer_registro(arch);
break;
case 0:
fclose(arch);
break;
}
getch();
}while (opcion != 0);
}
else
printf("Error al abrir el archivo");
}

