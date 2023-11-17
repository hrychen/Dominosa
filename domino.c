#include <stdio.h>
#include "colores.h"
#define MAXFILS	11
#define MAXCOLS	11

typedef struct {
	int fils;
	int cols;
	int mat[MAXFILS][MAXCOLS];
} t_matriz;

int main () {
	/*t_matriz dominosa = {10,11,
	{{0,2,1,0,6,0,3,4,4,6,2},
	{4,8,4,2,9,0,6,0,9,5,6},
	{8,4,5,7,2,1,1,3,4,0,4},
	{0,3,8,7,8,7,2,3,3,5,3},
	{1,6,9,8,9,1,1,4,6,1,9},
	{9,9,4,0,6,5,6,8,8,8,9},
	{6,2,9,0,6,3,8,3,7,5,7},
	{2,2,9,5,2,7,5,2,4,8,7},
	{4,5,0,7,7,6,1,2,1,8,7},
	{7,0,5,1,3,3,9,5,5,1,3}}};*/
	
	t_matriz dominosa = {3,4,{{2,2,2,1},{0,0,1,0},{2,0,1,1}}};
	int i, j;
	char f;
	
	printf("Introduce el nombre del fichero: ");
	//scanf
	
	printf("\n\n");
	//funcion para imprimir tablero: 
	for (i=0; i < dominosa.cols; i++) {
		printf("%d", i);
	}
	printf("\n +");
	for(i=0; i < dominosa.cols; i++) {
		printf("---+");
	}
	printf("\n");
	for (i=0; i < dominosa.fils; i++) {
		printf("%c|", 'A'+i);
		for (j=0; j < dominosa.cols; j++) {
			printf_color_num(dominosa.mat[i][j]);
			printf(" %d  ", dominosa.mat[i][j]);
			printf_reset_color();
			}
		printf("\n");
		for (j=0; j <= dominosa.cols; j++) {
			printf(" +  ");
		}
		printf("\n");
	}
	printf("\n");

	//Logico del juego.



}
