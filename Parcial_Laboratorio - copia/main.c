#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "alquileres.h"
#include "juego.h"
#define ELEMENTS_CLIENTE 200
#define ELEMENTS_JUEGOS 200
#define ELEMENTS_ALQUILER 200

int main()
{
    int opcion=0;
     int idFind=0;

    //INICIALIZO, DECLARO y HARCODEO CLIENTES
    eCliente cliente[ELEMENTS_CLIENTE];
    inicializarCliente(cliente, ELEMENTS_CLIENTE);
    harcodearCliente(cliente);


    //INICIALIZO, DECLARO Y HARCODEO JUEGOS
    eJuegos juegos[ELEMENTS_JUEGOS];
    inicializarJuego(juegos, ELEMENTS_JUEGOS);
    harcodearJuegos(juegos);

    //INICIALIZO, DECLARO
    eAlquileres alquiler[ELEMENTS_ALQUILER];
    inicializarAlquileres(alquiler, ELEMENTS_ALQUILER);

    do
    {
        system("cls");
        printf("\n *** ABM *** \n\n");
        printf(" 1. JUEGOS\n");
        printf(" 2. CLIENTES\n");
        printf(" 3. ALTA ALQUILERES\n");
        printf(" 4. LISTAR\n");
        printf(" 5. INFORMES\n");
        printf(" 6. Salir\n");
        printf(" Seleccione una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1://JUEGOS
            menuJuegos(juegos, ELEMENTS_CLIENTE);
            break;
        case 2://CLIENTES
            menuClientes(cliente, ELEMENTS_CLIENTE);
            break;
        case 3://ALQUILERES
            agregarAlquiler(alquiler, ELEMENTS_ALQUILER, cliente, ELEMENTS_CLIENTE, juegos, ELEMENTS_JUEGOS);
            break;
        case 4:
            menuListar(cliente, ELEMENTS_CLIENTE, juegos, ELEMENTS_JUEGOS, alquiler, ELEMENTS_ALQUILER);
            break;
        case 5:
             do {
                    if (flagAlquileres == 0) {
                        printf("No se a ingresado nigun alquiler\n");
                        break;
                    }
                    printf("---------------------- MENU INFORMES     ----------------------\n");
                    printf("| 1 - PROMEDIO y TOTAL DE LOS IMPORTES DE JUEGOS ALQUILADOS    |\n");
                    printf("| 2 - TOTAL DE IMPORTES QUE NO SUPERAN EL PROMEDIO             |\n");
                    printf("| 3 - LISTAR CLIENTES DE DETERMINADO JUEGO (id del juego)      |\n");
                    printf("| 4 - LISTAR JUEGOS DE DETERMINADO CLIENTE (id del cliente)    |\n");
                    printf("| 5 - LISTAR JUEGOS MENOS ALQUILADOS                           |\n");
                    printf("| 6 - LISTAR CLIENTES QUE MAS ALQUILARON                       |\n");
                    printf("| 7 - LISTAR JUEGOS QUE ALQUILARON EN UNA FECHA                |\n");
                    printf("| 8 - LISTAR CLIENTES QUE REALIZARON EN UNA FECHA              |\n");
                    printf("| 9 - LISTAR JUEGOS POR IMPORTE(DESCENDENTE)                   |\n");
                    printf("| 10 - LISTAR CLIENTES POR APELLIDO(ASCENDENTE)                |\n");
                    printf("| 11 - SALIR                                                   |\n");;
                    printf("---------------------------------------------------------------\n");
                    fflush(stdin);
                    scanf("%d", &menuInformes);
                    switch (menuInformes) {
                        case 1:
                            printf("---------------------------------------------------------------\n");
                            printf(" Total de juegos = %f\n",
                                   juegoTotal(alquiler, juegos, cliente, ELEMENTS_JUEGOS, ELEMENTS_CLIENTE));
                            printf(" Promedio = %f\n",
                                   promedio(alquiler, juegos, cliente, ELEMENTS_JUEGOS, ELEMENTS_CLIENTE));
                            printf("---------------------------------------------------------------\n");
                            break;
                        case 2:

                            printf("---------------------------------------------------------------\n");
                            printf("| Total que no supera promedio = %d\n",
                                   NoPromedio(alquiler, juegos, cliente, ELEMENTS_JUEGOS, ELEMENTS_CLIENTE));
                            printf("---------------------------------------------------------------\n");

                            break;
                        case 3:
                            alquilerDeUnJuegoDeterminado(idFind, alquiler, juegos, cliente, ELEMENTS_JUEGOS, ELEMENTS_CLIENTE);
                            break;
                       
                        case 4:
                            alquilerDeUnClienteDeterminado(idFind, alquiler, juegos, cliente, ELEMENTS_JUEGOS, ELEMENTS_CLIENTE);
                            break;
                        case 5:
                             
               
                            break;

                        case 6:
                            
                            break;
                        case 7:
                             printf("Ingrese dia: \n")
                            scanf("%d", &dia);
                             printf("Ingrese mes: \n")
                            scanf("%d", &mes);
                             printf("Ingrese año: \n")
                            scanf("%d", &anio);
                            fechaAlquileresClien(dia, mes, anio, alquiler, juegos, cliente, ELEMENTS_JUEGOS, ELEMENTS_CLIENTE);
                            break;
                        case 8:
                           //************************************
                            break;

                        case 9:
                            ordenarJuego2(juegos, ELEMENTS_JUEGOS);
                            break;
                        case 10:
                             ordenarCliente(cliente, ELEMENTS_CLIENTE);
                            break;

                    }

                } while (menuInformes != 11);
               break;
        case 6:
            opcion=5;
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }
        system("pause");
    }
    while(opcion!=5);

    return 0;
}
