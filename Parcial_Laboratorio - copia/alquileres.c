#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juego.h"
#include "cliente.h"
#include "alquileres.h"

///GENERA ID DE ALQUILERES
static int generarNextId()
{
    static int idAlquiler=0;
    idAlquiler++;
    return idAlquiler;
}
///--------------------------------------
///INICIALIZA ALQUILERES
void inicializarAlquileres(eAlquileres* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=0;
    }
}
///---------------------------------------
///ELIJIR EL CLIENTE DEL ALQUILER
int elegirCliente(eCliente clientes[], int len)
{
    int idCliente;
    int retorno=-1;

    mostrarClientes(clientes, len);
    printf("\nSeleccione un cliente: ");
    scanf("%d", &idCliente);

    for(int i=0; i < len; i++)
    {
        if(clientes[i].idCliente==idCliente && clientes[i].isEmpty == 1)
        {
            retorno=idCliente;
            break;
        }
    }

    return retorno;
}
///---------------------------------------------
///ELIJIR JUEGO
int elegirJuegos(eJuegos juegos[], int len)
{
    int idJuegos;
    int retorno= -1;

    mostrarJuegos(juegos, len);
    printf("\nSeleccione un juego: ");
    scanf("%d", &idJuegos);

    for(int i=0; i < len; i++)
    {
        if(juegos[i].idJuegos==idJuegos && juegos[i].isEmpty == 1)
        {
            retorno=idJuegos;
            break;
        }
    }

    return retorno;
}
///---------------------------------------------------------
///BUSCAR ESPACIO LIBRE EN ALQUILERES
int buscarEspacioLibreAlquileres(eAlquileres list[], int len)
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
///----------------------------------------------------------------------
///AGREGAR UN NUEVO ALQUILER
int agregarAlquiler(eAlquileres* alquiler, int lenAlquiler, eCliente cliente[], int lenCliente, eJuegos juegos[], int lenJuegos)
{
    int retorno=-1;
    int found;

    system("cls");
    printf("\n  *** ALTA ALQUILER ***\n\n");

    found = buscarEspacioLibreAlquileres(alquiler, lenAlquiler);

    if(found == -1)
    {
        printf("No hay lugar\n\n");
    }

    else
    {
        alquiler[found].idJuegos = elegirJuegos(juegos, lenJuegos);

        if(alquiler[found].idJuegos == -1)
        {
            printf(" No existe el ID ingresado.\n");
        }
        else
        {
            alquiler[found].idCliente=elegirCliente(cliente, lenCliente);

            if(alquiler[found].idCliente == -1)
            {
                printf(" No existe el ID ingresado. \n");
            }
            else
            {

                getValidInt("Ingrese la fecha\n Dia: ",&alquiler[found].fecha.dia,1,31);
                getValidInt(" Mes: ",&alquiler[found].fecha.mes,1,12);
                getValidInt(" Anio: ",&alquiler[found].fecha.anio,1900,2018);
                alquiler[found].idAlquileres=generarNextId();//ID
                alquiler[found].isEmpty=1;

                printf("\n ALQUILER REALIZADO\n");
                printf(" ID Alquiler: %d  \n Fecha del alquiler: %d/%d/%d  \n Nombre Empleado: %s %s \n Juego elegido: %s\n", alquiler[found].idAlquileres, alquiler[found].fecha.dia, alquiler[found].fecha.mes, alquiler[found].fecha.anio, cliente[(alquiler[found].idCliente)-1].apellido, cliente[(alquiler[found].idCliente)-1].nombre, juegos[(alquiler[found].idJuegos)-1].descripcion);
                retorno=0;


            }
        }
    }

    return retorno;
}
///-------------------------------------------------------------------
///LISTAR ALQUILERES POR JUEGO
void listarAlquileresXJuego(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli)
{
    int idJuego;
    char descripcion[51];
    int flag=0;

    idJuego=elegirJuegos(juegos, lenJue);
    cargarDescripcionJuego(juegos, lenJue, idJuego, descripcion);

    system("cls");
    printf(" Alquileres de juego %s", descripcion);

    for(int i=0; i<lenAl; i++)
    {
        if(alquileres[i].isEmpty == 1 && alquileres[i].idJuegos == idJuego)
        {
            mostrarAlquiler(alquileres[i], lenAl, juegos, lenJue, cliente, lenCli);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf(" No hay alquileres para mostrar.\n");
    }
}
///--------------------------------------------------------------------
///CARGAR JUEGO
void cargarDescripcionJuego(eJuegos juego[], int lenJuego, int idJuego, char cadena[])
{
    for(int i=0; i < lenJuego; i++)
    {
        if( juego[i].idJuegos == idJuego)
        {
            strcpy(cadena, juego[i].descripcion);
            break;
        }
    }
}
///--------------------------------------------------------------------
///MOSTRAR ALQUILER
int mostrarAlquiler(eAlquileres alquiler, int lenAlqui, eJuegos* juegos, int lenJueg, eCliente* cliente, int lenClien)
{
    char descripcion[51];
    char apellido[31];

    cargarDescripcionJuego(juegos, lenJueg, alquiler.idJuegos, descripcion);
    cargarCliente(cliente, lenClien, alquiler.idCliente, apellido);

    printf("\n Juego: %s\n ID alquiler: %d\n Cliente: %s\n Fecha: %d/%d/%d\n\n", descripcion, alquiler.idAlquileres, apellido, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
    return 0;
}
///---------------------------------------------------------------
///CARGAR CLIENTE
void cargarCliente(eCliente cliente[], int lenCli, int idCliente, char apellido[])
{
    for(int i=0; i < lenCli; i++)
    {
        if(cliente[i].idCliente == idCliente)
        {
            strcpy(apellido, cliente[i].apellido);
            break;
        }
    }
}
///-------------------------------------------------------------------------
///MOSTRAR ALQUILERES
int mostrarAlquileres(eAlquileres* alquiler, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli)
{
    for(int i = 0; i<lenAl; i++)
    {
        if(alquiler[i].isEmpty == 0)
        {
            mostrarAlquiler(alquiler[i], lenAl, juegos, lenJue, cliente, lenCli);
        }
    }
    return 0;
}
///-------------------------------------------------------------------------
///MENU LISTAR
int menuListar(eCliente cliente[], int lenCli, eJuegos juego[], int lenJue, eAlquileres alquiler[], int lenAl)
{
    int opcionListar=0;

    do
    {
        system("cls");
        printf("\n *** MENU LISTAR *** \n\n");
        printf(" 1. ORDENAR ALQUILERES POR JUEGO\n");
        printf(" 2. ORDENAR ALQUILERES POR CLIENTES\n");
        printf(" Seleccione una opcion: ");
        fflush(stdin);
        scanf("%d",&opcionListar);

        switch(opcionListar)
        {
        case 1:
            listarAlquileresXJuego(alquiler, lenAl, juego, lenJue, cliente, lenCli);
            break;
        case 2:
            ordenarAlquileresXCliente(alquiler, lenAl, juego, lenJue, cliente, lenCli);
            break;
        case 3:
            printf("Saliendo..\n\n");
            system("pause");
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }
        system("pause");
    }
    while(opcionListar!=2);

    return opcionListar;
}
///-------------------------------------------------------------------------------------------------------
///ORDENAR ALQUILERES POR CLIENTE
void ordenarAlquileresXCliente(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJueg, eCliente* cliente, int lenCli)
{
    char nombreI[51];
    char nombreJ[51];

    eAlquileres alquiAux;

    for(int i=0; i<lenAl -1; i++)
    {
        for(int j = i +1; j < lenAl; j++)
        {
            cargarCliente(clientes, lenCli, alquileres[i].idCliente, nombreI);
            cargarCliente(clientes, lenCli, alquileres[j].idCliente, nombreJ);

            if(strcmp(nombreI, nombreJ)>0)
            {
                alquiAux = alquileres[i];
                alquileres[i] = alquileres[j];
                alquileres[j] = alquiAux;
            }
            else if(strcmp(nombreI, nombreJ)==0 && alquileres[i].idAlquileres > alquileres[j].idAlquileres)
            {
                alquiAux = alquileres[i];
                alquileres[i] = alquileres[j];
                alquileres[j] = alquiAux;
            }
        }
    }
}

float juegoTotal(eAlquileres* alquileres, eJuegos* juegos, eCliente* cliente, int lenJueg, int lenCli) {
    int i, j;
    float total = 0;
    for (i = 0; i < lenJueg; i++) {
        if (juegos[i].isEmpty == 0)
            for (j = 0; j < lenJueg * lenCli; j++) {
                if (alquileres[j].isEmpty == 0 && alquileres[j].idJuegos == juegos[i].idJuegos) {
                    total += juegos[i].importe;
                }
            }
    }
    return total;
}

/**
 * Calcula el importe promedio de los juegos calculados
 * @param alquileres Pointer to alquileres struct
 * @param juegos Pointer to juegos struct
 * @param clientes Pointer to clientes struct
 * @param lenJuegos int size juegos
 * @param lenClientes int size clientes
 * @return total/cantidad float
 */
float promedio(eAlquileres* alquileres, eJuegos* juegos, eCliente* cliente, int lenJueg, int lenCli) {
    int i;
    int j;
    int k;
    float total = 0;
    int cantidad = 0;

    for (i = 0; i < lenJueg; i++) {
        if (juegos[i].isEmpty == 0)
            for (j = 0; j < lenJueg * lenCli; j++) {
                if (alquileres[j].isEmpty == 0 && alquileres[j].idJuegos == juegos[i].idJuegos) {
                    total += juegos[i].importe;
                    cantidad++;
                }
            }
    }
    return total / cantidad;
}

/**
 * Muestra los importes que no superan el promedio.
 * @param alquileres Pointer to alquileres struct
 * @param juegos Pointer to juegos struct
 * @param clientes Pointer to clientes struct
 * @param lenJuegos int size juegos
 * @param lenClientes int size clientes
 * @return total int
 */
int NoPromedio(eAlquileres* alquileres, eJuegos* juegos, eCliente* cliente, int lenJueg, int lenCli) {
    int i, total = 0;
    float promedio = promedio(alquileres, juegos, cliente, lenJueg, lenCli);
    for (i = 0; i < lenJueg; i++) {
        if (juegos[i].importe < promedio && juegos[i].isEmpty == 0) {
            total++;
        }
    }
    return total;
}
/**
 * Muestra el/los alquileres de un juego determinado por la fecha que recibe como parametro
 *
 * @param idJuego int
 * @param alquileres Pointer to alquileres struct
 * @param juegos Pointer to juegos struct
 * @param clientes Pointer to clientes struct
 * @param lenJuegos int size juegos
 * @param lenClientes int size clientes
 */
void alquilerDeUnJuegoDeterminado(int idJuegos, eAlquileres* alquileres, eJuegos* juegos, eCliente* cliente, int lenJueg, int lenCli ) {
    int i;
    int j;
    int k;
    for (i = 0; i < lenCli; i++) {
        if (cliente[i].isEmpty == 0)
            for (k = 0; k < lenCli * lenJueg; k++) {
                if (alquileres[k].isEmpty == 0 && alquileres[k].idJuegos == idJuegos &&
                    cliente[i].idCliente == alquileres[k].idCliente) {
                    printf("------------------------------------------------------------\n");
                    printf("| ID        |    %d\n", clientes[i].idCliente);
                    printf("| Nombre    |    %s\n", clientes[i].nombre);
                    printf("| Apellido  |    %s\n", clientes[i].apellido);
                    printf("| Domicilio |    %s\n", clientes[i].domicilio);
                    printf("------------------------------------------------------------\n");

                }

            }
    }
}
/**
 * Muestra el/los alquileres de un cliente determinado por la fecha que recibe como parametro
 *
 * @param idCliente int
 * @param alquileres Pointer to alquileres struct
 * @param juegos Pointer to juegos struct
 * @param clientes Pointer to clientes struct
 * @param lenJuegos int size juegos
 * @param lenClientes int size clientes
 */

void alquilerDeUnClienteDeterminado(int idCliente, eAlquileres* alquileres, eJuegos* juegos, eCliente* cliente, int lenJueg, int lenCli) {
    int i;
    int j;
    int k;
    for (i = 0; i < lenJuegos; i++) {
        if (juegos[i].isEmpty == 0)
            for (k = 0; k < lenCli * lenJueg; k++) {
                if (alquileres[k].isEmpty == 0 && alquileres[k].idCliente == idCliente &&
                    juegos[i].idJuegos == alquileres[k].idJuegos) {
                    printf("------------------------------------------------------------\n");
                    printf("| ID           |    %d\n", juegos[i].idJuegos);
                    printf("| Descripcion  |    %s\n", juegos[i].descripcion);
                    printf("| Importe      |    %f\n", juegos[i].importe);
                    printf("------------------------------------------------------------\n");

                }

            }
    }
}
void fechaAlquileresClien (int dia, int mes, int anio, eAlquileres* alquileres, eJuegos* juegos, eCliente* cliente, int lenJueg, int lenCli) {
    int i, j, k;
    for (i = 0; i < lenClientes; i++) {
        if (clientes[i].isEmpty == 0)
            for (k = 0; k < lenCli * lenJueg; k++) {
                if (alquileres[k].isEmpty == 0 && alquileres[k].idCliente == clientes[i].idCliente &&
                    alquileres[k].fecha.dia == dia && alquileres[k].fecha.mes == mes &&
                    alquileres[k].fecha.anio == anio) {
                    printf("------------------------------------------------------------\n");
                    printf("| ID           |    %d\n", cliente[i].idCliente);
                    printf("| Nombre       |    %s\n", cliente[i].nombre);
                    printf("| Apellido     |    %s\n", cliente[i].apellido);
                    printf("| Domicilio    |    %s\n", cliente[i].domicilio);
                    printf("------------------------------------------------------------\n");

                }

            }
    }
}
void hardcodeoAlquiler(eAlquileres y[])
{
    eAlquileres x[]=
    {
        {1, 1, 4, {30, 5, 2018}, 1},
        {2, 3, 2, {06, 5, 2018}, 1},
        {3, 2, 4, {21, 5, 2018}, 1},
        {4, 1, 5, {04, 5, 2018}, 1},
        {5, 4, 3, {19, 5, 2018}, 1}
    };

    for(int i=0; i<5; i++)
    {
        y[i] = x[i];
    }
}
