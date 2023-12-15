#include <stdio.h>
#include <math.h>

double y_x, s_x = 1, x = 0.1, eps = 0.0001, pox, dil;

int main(){

	printf("Введіть значення x (за замовчуванням - 0.1):\n");
	scanf("%lf", &x);
	printf("Введіть значення похибки (за замовчуванням - 0.0001):\n");
	scanf("%lf", &eps);

	y_x = exp(cos(x))*cos(sin(x));

	double kfact = 1, chys;
	int k = 1;

	for(pox = fabs(y_x-s_x);pox>eps;k++){
		kfact *=k;
		chys = cos(k*x);
		dil = (chys/kfact);
		s_x += dil;
		pox = fabs(y_x-s_x);
	}

	printf("Y(x) = %lf\n", y_x);
	printf("S(x) = %lf\n", s_x);
	printf("Похибка: %lf\n", pox);

}

