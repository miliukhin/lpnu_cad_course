#include <stdio.h>
#include <math.h>

double integr(double N){

	double y=0.0;
	double x=0.0;
	double integral = 0.0;

	while(x<=3.1415){
		y = 1 + pow(cos(x), 2);
		integral = integral + N * y;
		x=x+N;
	}
	printf("Integral on segment [-1.0,3.1415], calculated using the left rectangle method"
		"with step %lf: %lf\n", N, integral);
	return integral;
}

