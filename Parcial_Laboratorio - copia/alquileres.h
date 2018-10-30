#ifndef ALQUILERES_INCLUDE_H
#define ALQUILERES_INCLUDE_H
#include "juego.h"
#include "cliente.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idAlquileres;
    int idJuegos;
    int idCliente;
    eFecha fecha;
    int isEmpty;
} eAlquileres;


void inicializarAlquileres(eAlquileres* list, int len);

int buscarEspacioLibreAlquileres(eAlquileres list[], int len);

int agregarAlquiler(eAlquileres* alquiler, int lenAlquiler, eCliente cliente[], int lenCliente, eJuegos juegos[], int lenJuegos);
int elegirCliente(eCliente clientes[], int len);

int elegirJuegos(eJuegos juegos[], int len);



///-------------------------------
void listarAlquileresXJuego(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli);

void cargarDescripcionJuego(eJuegos juego[], int lenJuego, int idJuego, char cadena[]);

int mostrarAlquiler(eAlquileres alquiler, int lenAlqui, eJuegos* juegos, int lenJueg, eCliente* cliente, int lenClien);

void cargarCliente(eCliente cliente[], int lenCli, int idCliente, char apellido[]);

int mostrarAlquileres(eAlquileres* alquiler, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli);

int menuListar(eCliente cliente[], int lenCli, eJuegos juego[], int lenJue, eAlquileres alquiler[], int lenAl);

void ordenarAlquileresXCliente(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJueg, eCliente* clientes, int lenCli);
#endif // ALQUILERES_INCLUDE_H
