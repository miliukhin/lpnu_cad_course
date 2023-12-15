#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 4

int m [N]={1,2,2,3};

int main(){

	srand(time(NULL));

	printf("Array items:\n");

	for(int i = 0; i<N; i++){
		int n = rand() % 9;
		if (n > 4)
			m[i] = -rand() % 10;
		else
			m[i] = rand() % 10;


			printf("%d\t", m[i] );
	}
			printf("\n\n");

	int count, paircount;

	for(int i = 0; i<N; i++){
	if(fmod(m[i],2) == 0){
		count++;
		if(fmod(count,2) == 0)
			paircount++;
		}
	}
			printf("even number pairs :\t%d\n", paircount);


}

