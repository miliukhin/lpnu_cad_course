#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double x,y,z,i,r,num;
int func2(){
	printf("Введіть значення z:\nz = ");
	scanf("%lf",&z);

	x=(z>=-1)?fabs(z):-z/3;

	if(x==-2.5){
		printf("x = -2.5, функція невизначена (логарифм нуля)\n");
		exit(0);

	}

	r=x-log(x+2.5)+3*(exp(x)-exp(-x));
	printf("Результат обчислень: %lf\n",r);

	return 0;
}

int func1(){
	printf("Введіть значення x:\n");
	scanf("%lf",&x);

	printf("Введіть значення y:\n");
	scanf("%lf",&y);

	printf("Введіть значення z:\n");
	scanf("%lf",&z);

	i=pow(y,-sqrt(fabs(x)));

	if(i<=0){
		printf("Функція невизначена!\n");
		exit(0);
	}

	else{
	r=log(i)*(x-y/2)+pow(sin(atan(z)),2);
	printf("%lf\n",r);
	}

	return 0;
}

int main(){
	printf("Номер функції для подальшої роботи (1 або 2): ");
	scanf("%lf",&num);

	if(num==1)
		func1();
	if(num==2)
		func2();
}

