#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    char nombrePeliculas[20];
    int idGenero;
    int idPelicula;
    int idActor;
    int estado;

} ePeliculas;

typedef struct
{
    int idGenero;
    char descripcion[20];

}eGenero;

/*typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;*/


typedef struct
{
    int idActor;
    char descripcion[60];
    char paisOrigen[60];

}eActores;


void mostrarPelicula(ePeliculas, eGenero[], int,eActores[], int);
void cargarPelicula(ePeliculas lista[], int tam, eGenero[], int tg,eActores[], int);
void mostrarListaPeliculas(ePeliculas[], int, eGenero[], int, eActores[], int);
int buscarLibre(ePeliculas[], int);
void inicializarPeliculas(ePeliculas[], int);
int menuDeOpciones(char[]);
int menuModificaciones(char[], ePeliculas[],int, eGenero[],int,eActores[], int);
void modificarNombre(ePeliculas[], int, int);
void baja(ePeliculas[], int, int);
int buscarId(ePeliculas lista[], int tam, int legajo);
void mostrarGeneros(ePeliculas lista[],int t, eGenero sectores[], int ts);
void mostrarActores(ePeliculas lista[],int t, eActores actores[], int ta);
