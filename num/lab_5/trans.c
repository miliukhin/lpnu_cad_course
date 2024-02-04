#include<math.h>
#include<stdio.h>
double fun(double x)
{
	/* return x*x + 0.3 * x - 0.18; */
	return x*x + 1.08 * x - 0.144;
}
double dfun(double x)
{
	return x + 1.08;
	/* return 2 * x + 0.3; */
}
void bisection (
		double a,
		double b,
		double delta
		){
	double fa = fun(a);
	int signa = copysignf(1, fa);
	double fb = fun(b);
	int signb = copysignf(1, fb);
	double eps0 = 0;
	for (int i = 0; i < 60; i++)
	{
		double c = (a + b) / 2;
		double fc = fun(c);
		int signc = copysignf(1, fc);
		double eps = fabs(a - b);
		printf(
				"%d\t"
				"%lf\t"
				"%d\t"
				"%lf\t"
				"%d\t"
				"%lf\t"
				"%d\t"
				"\n"
				,i, a, signa, b, signb, c, signc);
		if (eps < delta)
			break;
		if (signb * signc > 0)
		{
			b = c;
			signb = signc;
		}
		else
		{
			a = c;
			signa = signc;
		}
		eps0 = eps;
	}
}

void newton(double x, double delta)
{
	double eps0 = 0;
	printf("0\t%lf\n", x);
	for (int i = 1; i < 20; ++i)
	{
		double f = fun(x);
		double df = dfun(x);
		double x1 = x - f /df;
		double eps = abs(x1 - x);
		double ksi = 2 * eps / (fabs(x1) + delta);
		printf(
				"%d\t"
				"%lf\t"
				"%lf\t"
				"%lf\t"
				"\n"
				, i, f, df, x1
				);
		if (eps < delta || ksi < delta)
			break;
		eps0 = eps;
		x = x1;
	}
}

int main()
{
	system("figlet bisection 1>&2");
	bisection(0, 0.35, 1e-10);
	system("figlet newton 1>&2");
	newton(0, 1e-10);
}

