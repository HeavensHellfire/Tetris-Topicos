#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

#define FILAS_VISIBLES 20
#define FILAS_BUFFER 4
#define FILAS_TOTALES (FILAS_VISIBLES+FILAS_BUFFER)
#define COLUMNAS 10
#include <stdio.h>
#include <stdlib.h>

typedef struct {int celdas[FILAS_TOTALES][COLUMNAS];} tablero;

typedef enum { I, O, T, S, Z, J, L } TipoPieza;
typedef struct { TipoPieza tipo;
                 int rotacion;
                 int x;
                 int y; } Pieza;

void tablero_inicializar (tablero *t);

int tablero_colision(tablero *t, Pieza *p, int dx, int dy);

void tablero_fijar_pieza(tablero *t, Pieza *p);

int tablero_limpiar_lineas(tablero *t);

void tablero_desplazar_filas(tablero *t, int desde);
#endif // TABLERO_H_INCLUDED
