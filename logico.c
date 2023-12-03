// logico.c
#include "logico.h"
#include "fichero.h"
#include "colores.h"
#include <stdio.h>
#include <stdbool.h>

//Funcion para imprimir el tablero dominosa.
void imprimir_tablero(t_matriz* dominosa, t_lista_fichas* fichas_encontrada) {
    int n, totalFichas;

    // Imprimir el tablero
    printf("\nDominosa fils = %d, cols = %d\n\n", dominosa->fils, dominosa->cols);

    printf("  ");
    for (int i = 0; i < dominosa->cols; i++) {
        printf(" %d  ", i);
    }

    printf("\n +");
    for (int i = 0; i < dominosa->cols; i++) {
        printf("---+");
    }
    printf("\n");

    for (int i = 0; i < dominosa->fils; i++) {
        printf("%c|", 'A' + i);
        for (int j = 0; j < dominosa->cols; j++) {
            printf_color_num(dominosa->mat[i][j]);
            printf(" %d  ", dominosa->mat[i][j]);
            printf_reset_color();
        }
        printf("\n");
        for (int j = 0; j < dominosa->cols; j++) {
            printf(" +  ");
        }
        printf("\n");
    }
    printf("\n");

    //Calcular total ficha del tablero dominosa.

    n = dominosa->cols - 2;
    totalFichas = (n+2) * (n+1) / 2;

    printf("Total Fichas: %d | Fichas Encontradas: %d \n\n", totalFichas, fichas_encontrada->num_fichas);
}

//Funcion para comprobar si el valor del usuario introducido es valido o no.
//Los datos que introduce el usuario pueden estar en mayúsculas y/o minúsculas.

bool valorFichaValido(t_matriz *tablero, char filaLetra, int columna, int valor) {
    // Comprobar si la letra está en minúsculas y convertirla a mayúscula
    if (filaLetra >= 'a' && filaLetra <= 'z') {
        filaLetra -= ('a' - 'A'); // Convertir a mayúscula
    }

    // Convertir la letra de la fila en un índice numérico
    int fila = filaLetra - 'A';

    // Verificar los límites del tablero
    if (fila < 0 || fila >= tablero->fils || columna < 0 || columna >= tablero->cols) {
        printf("\n Valor ficha invalido!\n\n");
        return false;
    }

    // Verificar si el valor coincide y si las fichas adyacentes son válidas
    if (tablero->mat[fila][columna] == valor) {
        // Comprobar las casillas adyacentes horizontalmente y verticalmente
        if ((fila > 0 && tablero->mat[fila-1][columna] == valor) || // Arriba
            (fila < tablero->fils - 1 && tablero->mat[fila+1][columna] == valor) || // Abajo
            (columna > 0 && tablero->mat[fila][columna-1] == valor) || // Izquierda
            (columna < tablero->cols - 1 && tablero->mat[fila][columna+1] == valor)) { // Derecha
            printf("\n Valor ficha valido!\n\n");
            return true;
        }
    }
    
    printf("\n Valor ficha invalido o no seguido!\n\n");
    return false;
}


void actualizarTablero(t_matriz *tablero, char filaLetra, int columna, int valor) {
    // Convierte la letra de la fila en un índice numérico
    int fila = filaLetra - 'A';

    // Verifica si la fila y la columna están dentro de los límites del tablero
    if (fila < 0 || fila >= tablero->fils || columna < 0 || columna >= tablero->cols) {
        printf("Movimiento fuera del tablero.\n");
        return;
    }

    // Comprueba si el valor en la posición especificada coincide con el valor ingresado por el usuario
    if (tablero->mat[fila][columna] == valor) {
        tablero->mat[fila][columna] = -1; // Utiliza -1 u otro valor específico para representar 'x'
    } else {
        printf("Valor no coincide con el tablero.\n");
    }
}

//Funcion para comprobar que todos los valores del tablero son -1
bool verificarValor(t_matriz *tablero) {
    for (int i = 0; i < tablero->fils; i++) {
        for (int j = 0; j < tablero->cols; j++) {
            if (tablero->mat[i][j] != -1) {
                return false; // El juego aún no ha terminado
            }
        }
    }
    return true;
}

void readMe(){
printf("\n ====== READ ME - JUEGO DOMINOSA ====== \n\n");
printf("Bienvenido al juego Dominosa!\n\n");

printf("Descripcion:\n");
printf("Dominosa es un juego de rompecabezas que consiste en colocar fichas de domino en un tablero para cubrir todos los numeros presentes. ");
printf("Cada ficha de domino contiene dos numeros, y cada combinacion de numeros aparece exactamente una vez en el tablero.\n\n");

printf("Como Jugar:\n");
printf("1. Al inicio del juego, se presenta un tablero con una serie de numeros.\n");
printf("2. Tu tarea es colocar las fichas de domino sobre estos numeros de manera que los extremos de cada ficha coincidan con los numeros del tablero.\n");
printf("3. Cada combinacion de numeros solo puede usarse una vez.\n");
printf("4. El juego continua hasta que todas las fichas han sido colocadas correctamente, cubriendo todos los numeros del tablero.\n\n");

printf("Normas del Juego:\n");
printf("1. No puedes colocar fichas de domino de manera que se superpongan.\n");
printf("2. Cada ficha de domino debe colocarse en dos casillas adyacentes (horizontal o verticalmente), y los numeros en las fichas deben coincidir con los numeros del tablero en esas casillas.\n");
printf("3. No esta permitido dejar espacios vacios en el tablero.\n");
printf("4. Una ficha de domino no puede extenderse fuera de los limites del tablero.\n\n");

printf("Diviertete resolviendo este desafiante y entretenido rompecabezas!\n");

}