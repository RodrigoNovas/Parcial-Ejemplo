#ifndef JUEGOS_INCLUDE_H
#define JUEGOS_INCLUDE_H

typedef struct
{
    int idJuegos;
    char descripcion[51];
    float importe;
    int isEmpty;
} eJuegos;

void inicializarJuego(eJuegos* list, int len);

int buscarEspacioLibreJuego(eJuegos list[], int len);

int agregarJuego(eJuegos list[], int len);

int menuJuegos(eJuegos juegos[], int len);

void mostrarJuego(eJuegos list);

void mostrarJuegos(eJuegos list[], int len);

int buscarJuegoPorID(eJuegos list[], int len, int idJuego);

int mofidificarJuego(eJuegos list[], int len);

int borrarJuego(eJuegos list[], int len);

int ordenarJuego(eJuegos* list, int len);

void harcodearJuegos(eJuegos y[]);

#endif // JUEGOS_INCLUDE_H
