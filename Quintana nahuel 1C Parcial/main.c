#include <stdlib.h>
#include "peliculas.h"
#define T 40
#define TG 5
#define TA 10
#define TF 50
int menuDeOpciones(char[]);
int main()
{
    int opcion;
    int id;
    ePeliculas lista[T];
    inicializarPeliculas(lista,T);
    eGenero generos[TG] = {{1,"Accion"},{2,"Comedia"},{3,"Drama"}, {4,"Romance"},{5, "Terror"}};
    eActores actores[TA] ={{1,"Scarlett Johansson","Argentina"},{2,"Robert  Downey Jr","EEUU"},{3,"Mark Ruffalo","Canada"},{4,"Chris Evans","EEUU"},{5,"Chris Hemsworth","Argentina"},{6,"Samuel Jackson","EEUU"},{7,"Gwyneth Paltrow","Canada"},{8,"Paul Rudd","Argentina"},{9,"Bradley Cooper","EEUU"},{10,"Josh Brolin","Canada"}};
    do
    {
        opcion = menuDeOpciones("1.Cargar Pelicula\n2.Baja\n3.Modificar\n4.Mostrar\n5.Informar\n6.Salir\nElija una opcion: ");

         while (opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6 && opcion!=7 && opcion!=8 && opcion!=9 && opcion!=10 && opcion!=11 && opcion!=12 && opcion!=13 && opcion!=14)
        {
            printf("Error. Ha ingresado una opcion no valida\n\n");
            printf("Debe elegir una opcion valida: ");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
        case 1:
            cargarPelicula(lista,  T, generos, TG,actores, TA);
            break;
        case 2:
            baja(lista,T,id);
            break;
        case 3:
            menuModificaciones("1:Modificar Nombre\n2:Modificar Fecha\n3:Modificar Actor\n4:Salir al menu anterior\nElija una opcion: ", lista, T,generos, TG,actores,TA);
            break;
        case 4:
            mostrarListaPeliculas(lista, T, generos, TG, actores, TA);
            break;
        case 5:

            break;
        case 6:
            printf("Salir\n");
            opcion = 6;
            break;
        }
    }
    while(opcion!=6);
    return 0;
}
