#include<stdio.h>
#include<cstdlib>
#include<cmath>
#include<getopt.h>

#define test

#ifdef test
	#define DELIM "\t"
#else
	#define DELIM ","
#endif


double fun(double x, double y)
{
	return -1.0 * y;
}
double precise(double x, double y)
{
	return exp (log(0.12)-x);
}
void euler(double y0, double x0, double x1, double n)
{
	double y = y0;
	double x = x0;
	double h = (x1 - x0) / n;
	printf("i" DELIM "k1" DELIM "y_1" DELIM "x" DELIM "y\n");
	printf("0" DELIM DELIM "%lf" DELIM "%lf" DELIM "%lf\n", y, x, precise(x,y));
	for (int i = 1; i < n + 1; i++)
	{
		double k1 = fun(x, y);
		double prec = precise(x, y);
		y = y + k1 * h;
		x = x + h;
		printf(
			"%d" DELIM "%lf" DELIM "%lf" DELIM "%lf" DELIM "%lf\n"
			, i, k1, y, x, prec
			);
	}
}

void heun
(double y0, double x0, double x1, double n)
{
	double y = y0;
	double x = x0;
	double h = (x1 - x0) / n;
	printf("i" DELIM "k1" DELIM "k2" DELIM "y" DELIM "x\n");
	printf("0" DELIM DELIM DELIM "%lf" DELIM "%lf\n", y, x);
	for (int i = 1; i < n + 1; i++)
	{
		double k1 = fun(x, y);
		double k2 = fun(x + h, y + h * k1);
		y = y + (k1 + k2) * h / 2;
		x = x + h;
		printf(
			"%d" DELIM ""
			"%lf" DELIM "%lf" DELIM ""
			"%lf" DELIM "%lf\n"
			, i, k1, k2, y, x
			);
	}
}

void runge_kutta4
(double y0, double x0, double x1, double n)
{
	double y = y0;
	double x = x0;
	double h = (x1 - x0) / n;
	printf("i" DELIM "k1" DELIM "k2" DELIM "k3" DELIM "k4" DELIM "y" DELIM "x\n");
	printf("0" DELIM DELIM DELIM DELIM DELIM "%lf" DELIM "%lf\n", y, x);
	for (int i = 1; i < n + 1; i++)
	{
		double k1 = fun(x, y);
		double k2 = fun(x + h / 2, y + k1 * h / 2);
		double k3 = fun(x + h / 2, y + k2 * h / 2);
		double k4 = fun(x + h, y + k3 * h);
		y = y + (k1 + 2 * k2 + 2 * k3 + k4) * h / 6;
		x = x + h;
		printf(
			"%d" DELIM ""
			"%lf" DELIM "%lf" DELIM ""
			"%lf" DELIM "%lf" DELIM ""
			"%lf" DELIM "%lf\n"
			, i, k1, k2, k3, k4, y, x
			);
	}
}
int main (int argc, char* argv[])
{
	int opt;

	while ((opt = getopt(argc, argv, "ehr")) != -1) {
		switch (opt) {
		case 'e':
			euler(0.12, 0, 1, 20);
			break;
		case 'h':
			heun(0.12, 0, 1, 20);
			break;
		case 'r':
			runge_kutta4(0.12, 0, 1, 20);
			break;
		default:
			euler(0.12, 0, 1, 20);
			heun(0.12, 0, 1, 20);
			runge_kutta4(0.12, 0, 1, 20);
		}
	}
}
