#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double DERIV = -0.048;
double INT = 3.33333333333;

double fun (double x) {
	return 0.4 * exp(-0.12 * x);
}

void derivatives(double x, double h) {
	double d1 = (fun(x + h) - fun(x - h)) / (2 * h);
	double d2 = (-fun(x + 2*h) + 8 * fun(x + h) - 8 * fun(x - h) + fun(x - 2*h)) / (12*h);
	double delta_d1 = fabs((DERIV-d1)/DERIV)*100;
	double delta_d2 = fabs((DERIV-d2)/DERIV)*100;
	printf (
			"%.2e,"
			"%lf,"
			"%lf,"
			"%lf,"
			"%.2e,"
			"%.2e"
			"\n"
			,
			h,
			d1,
			d2,
			DERIV,
			delta_d1,
			delta_d2
			);
}

double integrals (
		double u,
		double v,
		int n
		)
{
	double sum_1 = 0;
	double sum_2 = 0;
	double h = (v - u) / n;

	for (int i=1; i < n; i++)
		sum_1 = sum_1 + fun(u + i * h);
	sum_1 = (sum_1 + (fun(u) - fun(v)) / 2) * h;
	for (int i=1; i < n/2; i++)
		sum_2 = sum_2 + (4 * fun(u + (2 * i - 1) * h) + 2.0 * fun(u + (2 * i) * h));
	sum_2 = (sum_2 + fun(u) - fun(v)) * h / 3;

	double delta_sum_1 = fabs((INT - sum_1)/INT) * 100;
	double delta_sum_2 = fabs((INT - sum_2)/INT) * 100;

	printf (
			"%d,"
			"%lf,"
			"%lf,"
			"%lf,"
			"%.2e,"
			"%.2e"
			"\n"
			,
			n,
			sum_1,
			sum_2,
			INT,
			delta_sum_1,
			delta_sum_2
			);
}

int main()
{
	system("toilet -f pagga DERGRAL.C");
	printf (
		    "h,"
		    "df/dx1,"
		    "df/dx2,"
		    "df/dx,"
		    "delta_d1(%),"
		    "delta_d2(%)"
		    "\n"
		    );

	derivatives(0, 1);
	derivatives(0, 0.1);
	derivatives(0, 0.01);
	derivatives(0, 0.001);
	derivatives(0, 0.0001);
	derivatives(0, 0.00001);
	derivatives(0, 0.000001);
	derivatives(0, 0.0000001);
	derivatives(0, 0.00000001);
	derivatives(0, 0.000000001);
	derivatives(0, 0.0000000001);
	derivatives(0, 0.00000000001);
	derivatives(0, 0.000000000001);
	derivatives(0, 0.0000000000001);
	derivatives(0, 0.00000000000001);
	derivatives(0, 0.000000000000001);
	derivatives(0, 0.0000000000000001);

	printf("\n");
	printf (
			"n,"
			"sum_1,"
			"sum_2,"
			"INT,"
			"delta_sum_1(%),"
			"delta_sum_2(%)"
			);
	printf("\n");

	integrals(0, 10000, 10);
	integrals(0, 10000, 100);
	integrals(0, 10000, 1000);
	integrals(0, 10000, 10000);
	integrals(0, 10000, 100000);
	integrals(0, 10000, 1000000);
	integrals(0, 10000, 10000000);

}

