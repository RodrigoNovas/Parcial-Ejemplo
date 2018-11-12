#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "juego.h"
#include "alquileres.h"
#define ELEMENTS_JUEGOS 200

///GENERAR ID DEL CLIENTE
static int generarNextId()
{
    static int idJuego=0;
    idJuego++;
    return idJuego;
}
///--------------------------------------------
///INICIALIZAR JUEGOS
void inicializarJuego(eJuegos* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=0;
    }
}
///-----------------------------------------------
///MENU JUEGOS
int menuJuegos(eJuegos juegos[], int len)
{
    int opcionJuego=0;
    int flagJuego=0;

    do
    {
        system("cls");
        printf("\n *** MENU JUEGOS *** \n\n");
        printf(" 1. ALTA\n");
        printf(" 2. MODIFICACION\n");
        printf(" 3. BAJA\n");
        printf(" 4. LISTAR\n");
        printf(" 5. SALIR\n");
        printf(" Seleccione una opcion: ");
        fflush(stdin);
        scanf("%d",&opcionJuego);

        switch(opcionJuego)
        {
        case 1:
            agregarJuego(juegos, len);
            flagJuego=1;
            break;
        case 2:
            if(flagJuego==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                mofidificarJuego(juegos, len);
            }
            break;
        case 3:
            if(flagJuego==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                borrarJuego(juegos, len);
            }
            break;
        case 4:
            if(flagJuego==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                ordenarJuego(juegos, ELEMENTS_JUEGOS);
            }
            break;
        case 5:
            printf("Saliendo..\n\n");
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }
        system("pause");
    }
    while(opcionJuego!=5);

    return opcionJuego;
}
///------------------------------------------------
///BUSCAR ESPACIO LIBRE
int buscarEspacioLibreJuego(eJuegos list[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
///-----------------------------------------------
///BUSCAR JUEGO POR ID
int buscarJuegoPorID(eJuegos list[], int len, int idJuego)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].idJuegos==idJuego)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
///-----------------------------------------------------
///MOSTRAR JUEGO
void mostrarJuego(eJuegos list)
{
    printf("%d\t%s\t\t%f\n\n",list.idJuegos,list.descripcion, list.importe);
}
///------------------------------------------------------
///MOSTRAR JUEGOS
void mostrarJuegos(eJuegos list[], int len)
{
    printf("\n *** JUEGOS ***\n");
    printf("ID\tDESCRIPCION\tIMPORTE\n\n");
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            printf("%d\t%s\t\t%f\n\n",list[i].idJuegos,list[i].descripcion, list[i].importe);
        }
    }
}
///---------------------------------------------------
///ALTA CLIENTE
int agregarJuego(eJuegos list[], int len)
{
    eJuegos juego;

    int retorno=-1;
    int found;

    system("cls");
    printf("\n  *** Alta Juego ***\n\n");

    found = buscarEspacioLibreJuego(list, len);

    if(found == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        getValidString(" Ingrese la descripcion: ", juego.descripcion,3,50);
        getValidFloat(&juego.importe," Ingrese el importe: ", " Ingrese solo numeros. Rango: [1-1500]", 1, 1500);

        juego.idJuegos=generarNextId();
        juego.isEmpty=1;
        retorno=0;

        list[found]=juego;

    }
    return retorno;
}
///---------------------------------------------------------
///MODIFICACION JUEGO
int mofidificarJuego(eJuegos list[], int len)
{
    int idJuego;
    int retorno=-1;
    int found;
    char respuesta;
    int opcion=0;

    system("cls");
    printf("\n  *** MODIFICAR JUEGO ***\n\n");

    getValidInt(" Ingrese el ID del juego que desea modificar\n",&idJuego,1,200);

    found=buscarJuegoPorID(list,len,idJuego);

    if(found>= 0 && list[found].isEmpty == 1)
    {
        mostrarJuego(list[found]);

        getValidString("Desea modificar este juego? s/n\n",&respuesta,1,1);

        if(respuesta=='s')
        {
            do
            {
                system("cls");
                printf("\n *** MODIFICAIONES JUEGOS *** --\n\n");
                printf(" 1. Descripcion\n");
                printf(" 2. Importe\n");
                printf(" 3. Salir\n\n");
                fflush(stdin);
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    getValidString(" Ingrese nueva descripcion: \n",list[found].descripcion,1,51);
                    break;
                case 2:
                    getValidFloat(&list[found].importe," Ingrese el importe: ", " Ingrese solo numeros. Rango: [1-1500]", 1, 1500);
                    break;
                case 3:
                    mostrarJuego(list[found]);
                    printf(" Saliendo...");
                    break;
                default:
                    printf(" Opcion incorrecta \n");
                    break;
                }
                system("pause");
            }
            while(opcion!=3);
        }

        else
        {
            printf(" Modificacion cancelada\n\n");
        }
    }
    else
    {
        printf(" Juego no encontrado\n");
    }
    return retorno;
}
///--------------------------------------------------------
///BAJA JUEGO
int borrarJuego(eJuegos list[], int len)
{
    int idJuego;
    int found;
    char borrar;

    system("cls");
    printf("  *** Baja Juego ***\n\n");

    getValidInt("Ingrese el ID del juego que desea dar de baja\n",&idJuego,1,200);

    found=buscarJuegoPorID(list,len,idJuego);

    if(found>= 0 && list[found].isEmpty == 1)
    {
        mostrarJuego(list[found]);

        getValidString("¿Esta seguro de que quiere dar de baja a este juego? s/n\n",&borrar,1,1);

        if(borrar=='s')
        {
            list[found].isEmpty=1;
            printf(" Juego dado de baja\n\n");
        }
        else
        {
            printf("Cancelado\n\n");
        }
    }

    else
    {
        printf("Juego no encontrado\n");
    }
    return -1;
}
///-------------------------------------------------------
///ORDENAR JUEGOS
int ordenarJuego(eJuegos* list, int len)
{
    eJuegos juegos;

    system("cls");
    printf("  ***  JUEGOS ***\n\n");
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j--)
        {
            if(list[i].importe<list[j].importe)
            {
                juegos = list[i];
                list[i] = list[j];
                list[j] = juegos;
            }

            else if(list[i].importe == list[j].importe && strcmp(list[j].descripcion,list[i].descripcion)>0)
            {
                juegos = list[i];
                list[i] = list[j];
                list[j] = juegos;
            }
        }
    }
    mostrarJuegos(list, len);

    return 0;
}

void harcodearJuegos(eJuegos y[])
{
    eJuegos x[]=
    {
        {1,"Zelda", 500,1},
        {2,"WOW", 80,1},
        {3,"Minecraft", 159,1},
        {4,"Ninja", 653,1},
        {5,"Mario", 1000,1}
    };

    for(int i=0; i<5; i++)
    {
        y[i] = x[i];
    }
}

