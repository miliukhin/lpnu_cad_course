#include <stdio.h>
#include <math.h>

double x, y, z, i, r;

int main(){
	printf("Введіть значення x:\n");
	while(scanf("%lf",&x)==0){
		double x1;
		while((x1=getchar())!='\n' && x1!=EOF);
		printf("Неприйнятні дані (x має бути числом):");
	}

	printf("Введіть значення y:\n");
	while(scanf("%lf",&y)==0){
		double y1;
		while((y1=getchar())!='\n' && y1!=EOF);
		printf("Неприйнятні дані (y має бути числом):");
	}

	printf("Введіть значення z:\n");
	while(scanf("%lf",&z)==0){
		double z1;
		while((z1=getchar())!='\n' && z1!=EOF);
		printf("Неприйнятні дані (z має бути числом):");
	}

	i=pow(y,-sqrt(fabs(x)));

	if(i<=0){
		printf("Функція невизначена!\n");
	}

	else{
		r=log(i)*(x-y/2)+pow(sin(atan(z)),2); printf("%lf\n",r); }
	return 0;
}

