#include <stdio.h>
#include "integr.c"

double func(){
	double N;
	scanf("%lf", &N);
	return N;
}

int main(){

	integr(func());
}

