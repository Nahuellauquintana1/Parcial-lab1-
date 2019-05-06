#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int horas;
    float sueldoBruto;
    float sueldoNeto;
    int idSector;
    int estado;
} eEmpleado;

typedef struct
{
    int idSector;
    char descripcion[20];
    float valor;

}eSector;

void mostrarEmpleado(eEmpleado, eSector[], int);
void cargarEmpleado(eEmpleado lista[], int tam, eSector[], int ts);
void mostrarListaEmpleados(eEmpleado[], int, eSector[], int);
int buscarLibre(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado lista[], int tam);
int menuDeOpciones(char[]);
int menuModificaciones(char[], eEmpleado[],int);
void modificar(eEmpleado[], int, int);
void baja(eEmpleado[], int, int);
int buscarLegajo(eEmpleado lista[], int tam, int legajo);
void sueldomMaximo(eEmpleado lista[], int tam);
void mostrarMaximo(eEmpleado lista[], int tam, eSector sector[], int ts);
int contarCarlos(eEmpleado[],int);
void mostrarSectores(eEmpleado lista[],int t, eSector sectores[], int ts);

