#include <stdio.h>
#include "logico.h"
#include <stdbool.h>

//Codigo para ejecutar el programa: gcc .\domino.c -o domino .\logico.c .\fichero.c .\colores.c

int main() {

    t_matriz dominosa;
    t_ficha ficha; //ficha para guardar valores x i y.
    t_lista_fichas fichas_encontradas; //Lista para guardar fichas
    int err, f, c, n, i = 0, select;
    int fichas_encontrada = 0;
    bool isOk = true, isFichaDuplicada = true, isGameOk = true;
    char nombre_fichero[SIZE_NOMBRE_FICHERO];

    //Menu del Juego:

    while(isGameOk){

    printf("\n ===== JUEGO PUZZLE DOMINOSA ===== \n\n");
    printf("1.START GAME\n");
    printf("2.READ ME\n");
    printf("3.EXIT GAME\n");
    printf("\nIntroduce tu seleccion: ");
    scanf("%d",&select);

    switch (select)
    {
    case 1:
        // Aquí hemos guardado ya la información de txt a nuestro matriz domino.

        do
        {
            printf("\nIntroduce el nombre del fichero: ");
            scanf("%s%*c", nombre_fichero);
            err = abrir_fichero(nombre_fichero);
            if (err != ABRIR_FICHERO_OK) {
                printf("ERROR: FICHERO NO ENCONTRADO.\n");
                printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
                isOk = false;
            }else{
                isOk = true;
            }
        } while (isOk != true);

        n = leer_int_fichero(); // Este valor no se usa actualmente
        dominosa.fils = leer_int_fichero();
        dominosa.cols = leer_int_fichero();

        // Leer los datos de la matriz
        for (f = 0; f < dominosa.fils; f++) {
            for (c = 0; c < dominosa.cols; c++) {
                dominosa.mat[f][c] = leer_int_fichero();
            }
        }
        cerrar_fichero();

        //Inicializar el numero de fichas de la lista fichas:
        fichas_encontradas.num_fichas = 0;

        // Bucle principal del juego
        bool juegoTerminado = false;
        while (!juegoTerminado) {
            imprimir_tablero(&dominosa, &fichas_encontradas);

            int numValoresValidos = 0; // Contador de valores válidos ingresados

            while (numValoresValidos < 2) {
                char filaLetra;
                int columna, valor;
                printf("Ingresa fila (letra), columna (numero) y valor del domino (por ejemplo, A 3 4): ");
                scanf("%c %d %d%*c", &filaLetra, &columna, &valor);

                // Si es un valor valido, actualizamos el tablero y guardamos el valor en x o y
                if (valorFichaValido(&dominosa, filaLetra, columna, valor)) {
                    actualizarTablero(&dominosa, filaLetra, columna, valor);
                    if (numValoresValidos == 0) {
                        fichas_encontradas.ficha[i].x = valor; // Guardar el primer valor válido en x
                    } else {
                        fichas_encontradas.ficha[i].y = valor; // Guardar el segundo valor válido en y
                    }
                    numValoresValidos++; // Incrementar el contador de valores válidos
                }
            }
            i++; // Incrementar posicion de ficha.
            fichas_encontradas.num_fichas++; // Incrementar numero de fichas.

            // Verificar si el juego ha terminado
            juegoTerminado = verificarValor(&dominosa);
        }

        //Ahora verificamos si existen fichas duplicadas o no.
        for (int i = 0; i < fichas_encontradas.num_fichas; i++) {
            for (int j = i + 1; j < fichas_encontradas.num_fichas; j++) {
                if ((fichas_encontradas.ficha[i].x == fichas_encontradas.ficha[j].x && fichas_encontradas.ficha[i].y == fichas_encontradas.ficha[j].y) ||
                    (fichas_encontradas.ficha[i].x == fichas_encontradas.ficha[j].y && fichas_encontradas.ficha[i].y == fichas_encontradas.ficha[j].x)) {
                    // Se encontró una ficha duplicada
                    isFichaDuplicada = false;
                }
            }
        }

        //Verificar si existe fichas duplicadas.
        if (isFichaDuplicada == false){
            printf("Hemos encontrado una ficha duplicada, no has terminado el puzzle dominosa. :(\n");
            printf("Intentalo del nuevo.\n");
        }else{
            printf("Genial! Has terminado el puzzle dominosa! :)\n\n");
        }
        break;
    case 2:
         readMe();
        break;
    case 3:
        printf("Has salido del juego.");
        isGameOk = false;
        break;
    default:
        printf("Seleccion Invalido Intentalo de nuevo.");
        break;
    }

    }

    return 0;
}
