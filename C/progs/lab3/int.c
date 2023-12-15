#include <stdio.h>
#include <math.h>
//#include <.h>

#define N 11

int integral(){

	double y=0.0, x=-1.0, f=0.0, diff=2.0/N, integral = 0.0;
	/*double y=0.0;
	double x=-1.0;
	double f=0.0;
	double diff=2.0/N;
	double integral = 0.0;*/
	int i = 1;

	f=(1-x)/(1+x);

	while(x<=1.){
		y = atan (x) + atan (f);
		f=(1-x)/(1+x);
		integral = integral + diff * y;
//		printf("integr = %lf\tx = %lf\ty = %lf\ti = %d\n",integral,x,y,i);
		i++;
		f=(1-x)/(1+x);
		x=x+diff;
	}
	printf("Integral on segment [-1.0,1.0], calculated using left rectangle method with step11: %lf\n",integral);

	return 0;
}

	double y=0.0, x=-1.0, f=0.0;

int main(){


	printf("while:\n");
	int num = 1;
	f=(1-x)/(1+x);
	while(x<=1.0){
		y = atan(x)+atan(f);
		f=(1-x)/(1+x);
		printf("%d.\t%lf\t%lf\n",num,x,y);
		x=x+.1;
		num++;
		}

	x=-1.0;
	num = 1;
	f=(1-x)/(1+x);

		printf("do while:\n");
	do{
		y = atan(x)+atan(f);
		f=(1-x)/(1+x);
		printf("%d.\t%lf\t%lf\n",num,x,y);
		x=x+.1;
		num++;
		}
	while(x<=1.0);

	num = 1;

	printf("for:\n");

	x=-1.0; f=(1-x)/(1+x);

	for(x=-1.0;x<=1.0;x+=.1){
		y = atan(x)+atan(f);
		f=(1-x)/(1+x);
		printf("%d.\t%lf\t%lf\n",num,x,y);
		num++;
	}

	integral();

	return 0;
}

