#ifndef CLIENTE_INCLUDE_H
#define CLIENTE_INCLUDE_H
#include "juego.h"

typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int isEmpty;
} eCliente;

int menuClientes(eCliente cliente[], int len);

void inicializarCliente(eCliente* list, int len);

int buscarEspacioLibreCliente(eCliente list[], int len);

int agregarCliente(eCliente list[], int len);

int buscarClientrePorID(eCliente list[], int len, int idCliente);

int modificarCliente(eCliente* list, int len);

void mostrarCliente(eCliente list);

void mostrarClientes(eCliente* list, int len);

int borrarCliente(eCliente list[], int len);

int ordenarCliente(eCliente* list, int len);

void harcodearCliente(eCliente y[]);


#endif // CLIENTE_INCLUDE_H
