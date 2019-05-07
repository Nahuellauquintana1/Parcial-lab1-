#include "Empleado.h"
#include "PediryValidar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int buscarLegajo(eEmpleado lista[], int tam, int legajo)
{
    int i;
    int indice = -1;
    for(i = 0; i<tam; i++)
    {
        if(lista[i].legajo == legajo)
        {
            indice = i;
        }
    }
    return indice;
}
void cargarEmpleado(eEmpleado lista[], int tam, eSector sector[], int ts)
{
    int i;
    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        lista[i].legajo = devuelveInt("Ingrese el numero de legajo: ");
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        lista[i].sexo = devuelveChar("Ingrese el Sexo: ");
        printf("Elija el Sector del empleado: \n");
        mostrarSectores(lista, tam, sector, ts);
        scanf("%d", &lista[i].idSector);
        lista[i].horas = devuelveInt("Ingrese la carga horaria del empleado: ");
        sueloBrutoCalculo(lista, tam, sector, ts);
        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }

}
void mostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i], sectores, ts);
        }

    }
}
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int ts)
{

    char descripcionSector[20];
    int i;
    for(i=0; i<ts; i++)
    {
        if(unEmpleado.idSector==sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].descripcion);
            break;
        }
    }
    printf("%d %10s %c %.2f %.2f   %s\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto,descripcionSector);

}
int buscarLibre(eEmpleado lista[], int tam)
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
void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}
void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[]= {1,8,9,7,2,4};
    char nombres[][50]= {"Carlos","Maria","Carlos","Pedro","Carlos","Mateo"};
    char sexo[]= {'M','F','M','M','M','M'};
    float sueldosBruto[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,2,3,1,2,2};
    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
}
int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    return opcion;
}
void modificar(eEmpleado lista[], int tam, int legajo)
{
    int flagExiste = 0;
    int indice;
    int sueldoBruto = 0;
    indice = buscarLegajo(lista,tam,legajo);

    if(indice != -1)
    {
        lista[indice].sueldoBruto = sueldoBruto;
    }
    if(flagExiste == 0)
    {
        printf("No existe un empleado con ese legajo");
    }
}
int menuModificaciones(char mensaje[], eEmpleado lista[], int tam)
{
    int opcion;
    int legajo;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    do
    {
        switch(opcion)
        {
        case 1:
            printf("Ingrese el legajo del Empleado que desea cambiar el nombre: ");
            scanf("%d", &legajo);
            break;
        case 2:
            printf("Ingrese el legajo del Empleado que desea cambiar el sexo: ");
            break;
        case 3:
            printf("Ingrese el legajo del Empleado que desea cambiar el SueldoBruto: ");
            scanf("%d", &legajo);
            modificar(lista,tam,legajo);
            opcion = 4;
            break;
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
float sueldoMaximo(eEmpleado lista[], int tam)
{
    int i;
    float maximo;
    int flagmaximo = 0;
    for(i = 0; i < tam ; i++)
{
    if(lista[i].estado==OCUPADO)
    {
        if(flagmaximo == 0 || lista[i].sueldoBruto > maximo)
        {
            maximo = lista[i].sueldoBruto;
            flagmaximo = 1;
        }
    }
}
    return maximo;
}
void mostrarMaximo(eEmpleado lista[], int tam, eSector sector[], int ts)
{
    float importeMaximo;
    int i;
    importeMaximo = sueldoMaximo(lista, tam);

    for(i = 0; i < tam; i++)
    {
        if(lista[i].sueldoBruto == importeMaximo && lista[i].estado == OCUPADO)
        {
            mostrarEmpleado(lista[i], sector, ts);
        }
    }
}
void baja(eEmpleado lista[], int tam, int legajo)
{

    int i;
    int loEncontro = 0;
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(legajo == lista[i].legajo)
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
int contarCarlos(eEmpleado lista[], int tam)
{
    int contadorCarlos = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(stricmp(lista[i].nombre,"carlos")==0 && lista[i].sueldoBruto>20000)
            {
                contadorCarlos++;
            }
        }
    }

    return contadorCarlos;
}

void sueloBrutoCalculo(eEmpleado lista[], int tam, eSector sector[], int ts)
{
    int i;
    int j;
    for(i = 0; i<tam; i++)
    {
        for(j = 0; j<ts; j++)
        {
            if(lista[i].idSector == sector[j].idSector)
            {
                            lista[i].sueldoBruto = lista[i].horas * sector[j].valor;
                            lista[i].sueldoNeto = lista[i].sueldoBruto * 0.85;

            }
        }
    }
}
void mostrarSectores(eEmpleado lista[],int tam, eSector sectores[], int ts)
{
    int i;
    for(i = 0; i<ts ; i++ )
    {
        printf("%d- %s\n", sectores[i].idSector, sectores[i].descripcion);
    }

}
