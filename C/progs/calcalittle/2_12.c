#include <stdio.h>
#include <math.h>

double x,z,r;

int main(){
	printf("Задайте значення z:\n"); scanf("%lf", &z);

	if(z<=1){
		x=pow(z,2)-1;
		//printf("z = %lf\n", z);
		//printf("z<=1, визначаю x як z^2-1\n");
		printf("z = %lf (<=1), визначаю x як 1/sqrt(z-1)\n", z);
	}
	else{
		x=1/sqrt(z-1);
		//printf("z = %lf\n", z);
		printf("z = %lf (>1), визначаю x як 1/sqrt(z-1)\n", z);
	}

	r=pow(sin(pow(x,2)-1),3)+log(fabs(x))+exp(x);
	printf("%lf\n", r);
}

