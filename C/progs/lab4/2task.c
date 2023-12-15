#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 4

int m [N][N], m2 [N][N], i, j;

int gen(){
	srand(time(NULL));

	printf("Array items:\n");

	FILE *fp = fopen("F1.txt", "w");

	for(i = 0; i<N; i++){
		for(j = 0; j<N; j++){
			int n = rand() % 9 - rand() % 9;
			m[i][j]=n;
			fprintf(fp, "%d\t", m[i][j]);
			printf("%d\t", m[i][j]);
		}
			fprintf(fp, "\n");
			printf("\n");

	}
			printf("\n");

	fclose(fp);
	}

void transpose(){

	printf("\n");

	FILE *f1 = fopen("F1.txt", "r");

	for(i = 0; i<N; i++){
		for(j = 0; j<N; j++){
			fscanf(f1, "%d\t", &m[i][j] );
			printf("%d\t", m[i][j] );
		}
			//fprintf(f2, "\n");
			printf("\n");
	}

	fclose(f1);

	printf("Transposed:\n");

	FILE *f2 = fopen("F2.txt", "w");

	for(i = 0; i<N; i++){
		for(j = 0; j<N; j++){
			m2[i][j]=m[j][i];
			fprintf(f2, "%d\t", m2[i][j] );
			printf("%d\t", m2[i][j] );
		}
			fprintf(f2, "\n");
			printf("\n");
	}

	fclose(f2);
}

int main(){
	gen();
	transpose();
	return 0;
}

