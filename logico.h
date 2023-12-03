// logico.h
#ifndef LOGICO_H
#define LOGICO_H

#include "fichero.h"
#include <stdbool.h>

#define MAXFILS 11
#define MAXCOLS 11
#define MAXFICHAS 100

typedef struct {
    int fils;
    int cols;
    int mat[MAXFILS][MAXCOLS];
} t_matriz;

// Definición de la estructura fichas
typedef struct {
    int x;
    int y;
} t_ficha;

typedef struct {
    int num_fichas;
    t_ficha ficha[MAXFICHAS];
} t_lista_fichas;

void readMe();
void imprimir_tablero(t_matriz* dominosa, t_lista_fichas* fichas_encontradas);
bool valorFichaValido(t_matriz *tablero, char filaLetra, int columna, int valor);
void actualizarTablero(t_matriz *tablero, char filaLetra, int columna, int valor);
bool verificarValor(t_matriz *tablero);

#endif // LOGICO_H
