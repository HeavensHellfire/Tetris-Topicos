#include "tablero.h"

void tablero_inicializar(tablero* t)
{
    int i,j;
    for(i = 0; i < FILAS_TOTALES; i++)
    {
        for(j = 0; j < COLUMNAS ; j++)
        {
            t->celdas[i][j] = 0;
        }
    }
}

int tablero_colision(tablero *t, Pieza *p, int dx, int dy)
{
    int f, c;
    const int* forma /*= pieza_obtener_forma(p)*/;

    for (f = 0; f < 4; f++)
    {
        for (c = 0; c < 4; c++)
        {
            if (forma[f * 4 + c] == 0)
            {
                continue;
            }

            int nueva_fila = p->y + f + dy;
            int nueva_col = p->x + c + dx;

            if (nueva_col < 0 || nueva_col >= COLUMNAS || nueva_fila >= FILAS_TOTALES)
            {
                return 1;
            }

            if (nueva_fila >= 0 && t->celdas[nueva_fila][nueva_col] != 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

void tablero_fijar_pieza(tablero *t, Pieza *p)
{
    const int *forma/*= pieza_obtener_forma(p)*/;
    int f, c;
    for (f = 0; f < 4; f++)
    {
        for (c = 0; c < 4; c++)
        {
            if (forma[f * 4 + c] == 0)
            {
                continue;
            }

            int fila = p->y + f;
            int col  = p->x + c;

            t->celdas[fila][col] = p->tipo + 1;
        }
    }
}

void tablero_desplazar_filas(tablero *t, int desde) {
    int f, c;
    for (f = desde; f > 0; f--)
    {
        for (c = 0; c < COLUMNAS; c++)
        {
            t->celdas[f][c] = t->celdas[f - 1][c];
        }
    }

    for (c = 0; c < COLUMNAS; c++)
    {
        t->celdas[0][c] = 0;
    }
}

int tablero_limpiar_lineas(tablero *t) {
    int lineas_eliminadas = 0;
    int c,f = 0;

    while (f < FILAS_TOTALES) {
        int fila_completa = 1;
        for (c = 0; c < COLUMNAS; c++) {
            if (t->celdas[f][c] == 0) {
                fila_completa = 0;
                break;
            }
        }

        if (fila_completa) {
            tablero_desplazar_filas(t, f);
            lineas_eliminadas++;
        } else {
            f++;
        }
    }

    return lineas_eliminadas;
}
