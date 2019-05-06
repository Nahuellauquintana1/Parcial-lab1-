#include <stdlib.h>
#include "Empleado.h"
#define T 10
#define TS 3
int menuDeOpciones(char[]);
int main()
{
    int opcion;
    eEmpleado lista[T];
    inicializarEmpleados(lista,T);
    eSector sectores[TS] = {{1,"Contabilidad",100},{2,"Sistemas",200},{3, "RRHH", 150}};
    hardcodearDatosEmpleados(lista,6);
    do
    {
        opcion = menuDeOpciones("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Informar\n6.Salir\nElija una opcion: ");
        switch(opcion)
        {
        case 1:
            cargarEmpleado(lista,  T, sectores, TS);
            break;
        case 2:

            break;
        case 3:
            menuModificaciones("1:Modificar Nombre\n2:Modificar Sexo\n3:Modificar Sueldo Bruto\n4:Salir al menu anterior\nElija una opcion: ", lista, T);
            break;
        case 4:
            mostrarListaEmpleados(lista, T, sectores, TS);
            break;
        case 5:
            mostrarMaximo(lista,T, sectores, TS);

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
