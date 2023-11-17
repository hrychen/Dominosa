#include <stdio.h>
#include "fichero.h"
#include "colores.h"

#define SIZE_NOMBRE_FICHERO 80
#define MAXFILS 11
#define MAXCOLS 11

typedef struct {
    int fils;
    int cols;
    int mat[MAXFILS][MAXCOLS];
} t_matriz;

int main() {
	
    t_matriz dominosa;
    int err, f, c, n, i, j;
    char nombre_fichero[SIZE_NOMBRE_FICHERO];

    printf("\nIntroduce el nombre del fichero: ");
    scanf("%s%*c", nombre_fichero);
    err = abrir_fichero(nombre_fichero);
    if (err != ABRIR_FICHERO_OK) {
        printf("ERROR: FICHERO NO ENCONTRADO.\n");
        printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
        return -1; // Agrega return para terminar el programa si hay error
    }

    n = leer_int_fichero(); // Este valor no se usa actualmente
    dominosa.fils = leer_int_fichero();
    dominosa.cols = leer_int_fichero();

    // Leer los datos de la matriz
    for (f = 0; f < dominosa.fils; f++) {
        for (c = 0; c < dominosa.cols; c++) {
            dominosa.mat[f][c] = leer_int_fichero();
        }
    }

    // Imprimir el tablero

	printf("\nDominosa %dx%d, fils = %d, cols = %d\n\n", n, n, dominosa.fils, dominosa.cols);

    for (i = 0; i < dominosa.cols; i++) {
        printf("%d", i);
    }

    printf("\n +");
    for (i = 0; i < dominosa.cols; i++) {
        printf("---+");
    }
    printf("\n");

    for (i = 0; i < dominosa.fils; i++) {
        printf("%c|", 'A' + i);
        for (j = 0; j < dominosa.cols; j++) {
            printf_color_num(dominosa.mat[i][j]);
            printf(" %d  ", dominosa.mat[i][j]);
            printf_reset_color();
        }
        printf("\n");
        for (j = 0; j < dominosa.cols; j++) {
            printf(" +  ");
        }
        printf("\n");
    }
    printf("\n");

    cerrar_fichero();

    // Aquí continúa la lógica del juego



    return 0;
}
