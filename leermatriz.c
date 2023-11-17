#include <stdio.h>
#define MAXFILS	10
#define MAXCOLS	10

typedef struct {
	int fils;
	int cols;
	int mat[MAXFILS][MAXCOLS];
} t_matriz;

int main () {
	t_matriz m;
	int i, j;
	
	printf("Introduce N_FILS: ");
	scanf("%d", &m.fils);
	printf("Introduce N_COLS: ");
	scanf("%d", &m.cols);
	printf("Introduce la matriz:\n");
	for (i=0; i < m.fils; i++) {
		for (j=0; j < m.cols; j++) {
			scanf("%d", &m.mat[i][j]);
		}
		scanf("%*c");
	}
	
	printf("\nEl valor de m: \n");
	for (i=0; i < m.fils; i++) {
		for (j=0; j < m.cols; j++) {
			printf("%d ", m.mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
