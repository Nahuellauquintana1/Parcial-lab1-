#include "peliculas.h"
#include "PediryValidar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int buscarId(ePeliculas lista[], int tam, int id)
{
    int i;
    int indice = -1;
    for(i = 0; i<tam; i++)
    {
        if(lista[i].idPelicula == id)
        {
            indice = i;
        }
    }
    return indice;
}
void cargarPelicula(ePeliculas lista[], int tam,eGenero generos[], int tg, eActores actores[],int ta)
{
    int i;
    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        generarId(lista,tam);
        printf("Ingrese nombre de la pelicula: ");
        fflush(stdin);
        gets(lista[i].nombrePeliculas);
        printf("Ingrese el genero de la Pelicula: \n");
        mostrarGeneros(lista, tam, generos, tg);
        scanf("%d", &generos[i].idGenero);
        lista[i].idGenero = generos[i].idGenero;
        printf("Ingrese el Actor de la Pelicula: \n");
        mostrarActores(lista, tam, actores, ta);
        scanf("%d",&actores[i].idActor);
//       fecha[i].dia = devuelveInt("Ingrese el dia de Estreno: ");
//       fecha[i].mes = devuelveInt("Ingrse el mes de Estreno: ");
//       fecha[i].anio = devuelveInt("Ingrese el año de Estreno: ");
        lista[i].idActor = actores[i].idActor;
        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }

}
void mostrarListaPeliculas(ePeliculas lista[], int tam, eGenero generos[], int tg, eActores actores[], int ta)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarPelicula(lista[i], generos, tg, actores, ta);
        }
    }
}
void mostrarPelicula(ePeliculas unaPelicula, eGenero generos[], int tg,eActores actores[],int ta)
{

    char descripciongeneros[20];
    char descripcionactores[20];
    char paisAux[20];
    int i;
    int j;
    for(i=0; i<tg; i++)
    {
        if(unaPelicula.idGenero==generos[i].idGenero)
        {
            strcpy(descripciongeneros, generos[i].descripcion);

            break;
        }
    }
    for(j=0; j<ta; j++)
    {
        if(unaPelicula.idActor == actores[j].idActor)
        {
            strcpy(paisAux, actores[j].paisOrigen);
            strcpy(descripcionactores, actores[j].descripcion);
        }
    }
    printf("%d %10s  %s\n %s  %s \n", unaPelicula.idPelicula,unaPelicula.nombrePeliculas,descripciongeneros, descripcionactores,paisAux);

}
int buscarLibre(ePeliculas lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
void inicializarPeliculas(ePeliculas lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}
int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    return opcion;
}
void modificarNombre(ePeliculas lista[], int tam, int id)
{
    int flagExiste = 0;
    int indice;
    char nuevoNombre[25];
    indice = buscarId(lista,tam,id);

    if(indice != -1)
    {
        printf("Ingrese el nuevo Nombre: ");
        gets(nuevoNombre);
        strcpy(lista[indice].nombrePeliculas, nuevoNombre);
    }
    if(flagExiste == 0)
    {
        printf("No existe una pelicula con esa id");
    }
}
int menuModificaciones(char mensaje[], ePeliculas lista[], int tam, eGenero genero[], int ts,eActores actores[],int ta)
{
    int opcion;
    int id;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    do
    {
        switch(opcion)
        {
        case 1:
            printf("Ingrese el ID de la pelicula que desee cambiar el Nombre: ");
            scanf("%d", &id);
            modificarNombre(lista, tam, id);
            break;
        case 2:
            //printf("");
            break;
        case 3:
            /*printf("");
            scanf("%d", &id);
            modificarNombre(lista,tam,id);
            opcion = 4;
            break;*/
        case 4:
            opcion = 4;
            break;
        default:
            printf("Por favor ingrese una opcion valida\n");
            break;
        }
    }
    while(opcion != 4);
return 0;
}
void baja(ePeliculas lista[], int tam, int id)
{

    int i;
    int loEncontro = 0;
    printf("Ingrese ID: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].idPelicula)
        {

            lista[i].estado = LIBRE;
            loEncontro = 1;
            break;//modifcar
        }

    }

    if(loEncontro==0)
    {
        printf("El dato no existe");
    }

}
void mostrarGeneros(ePeliculas lista[],int tam,eGenero generos[], int tg)
{
    int i;
    for(i = 0; i<tg ; i++ )
    {
        printf("%d- %s\n", generos[i].idGenero, generos[i].descripcion);
    }

}
void mostrarActores(ePeliculas lista[],int tam,eActores actores[], int ta)
{
    int i;
    for(i = 0; i<ta ; i++ )
    {
        printf("%d- %s- %s\n", actores[i].idActor, actores[i].descripcion, actores[i].paisOrigen);
    }

}

void generarId(ePeliculas lista[],int tam)
{
    int i;
    int contadorId = 1000;
    for (i = 0;i<tam;i++)
    {
        lista[i].idPelicula = contadorId;
        contadorId++;
    }
}
