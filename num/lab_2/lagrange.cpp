#include <stdio.h>
#include <vector>

/* #define table */
#define testing

double
base_polynomial (std::vector<double> x, int i, double x_val)
{
	auto frac = [x, i] (double x_val)
	{
		double numerator = 1, denominator = 1;

		for (int j = 0; j < x.size(); j++)
			if (j!=i) {
#ifdef testing
				/* printf ("i:%d\tj:%d", i,j); */
				printf ("\\frac{(x - %.2lf)}"
					"{(%.2lf - %.2lf)}",
					x[j], x[i], x[j]);
				printf("\n");
#endif
				numerator *= x_val - x[j];
				denominator *= x[i] - x[j];
			}
		/* printf ("\\frac{%.0lf}{%.0lf}\n", numerator, denominator); */

		return numerator/denominator;
	};
	return frac(x_val);
}

double
interpolate (std::vector<double> x, std::vector<double> y, double x_val)
{
	std::vector<double> pnomials;
	double whole = 0;

#ifdef testing
	printf("$$\n");
#endif
	for (int i = 0; i < x.size(); i++)
	{
		printf("%.1lf", y[i]);
		pnomials.push_back(
				base_polynomial(x, i, x_val)
		);
		printf("+");
	}

	for (int i = 0; i < y.size(); i++)
		whole += y[i] * pnomials[i];
#ifdef testing
	printf("$$\n");
	printf("\n");
#endif
	return whole;
}

int
main ()
{
	std::vector<double> xes =	{0.0, 0.1, 0.3, 0.4, 0.5};
	std::vector<double> ys  =	{0.3, 0.6, 0.9, 1.2, 1.5};
	std::vector<double> l_3_x =	{0.1, 0.3, 0.4, 0.5};
	std::vector<double> l_3_y =	{0.6, 0.9, 1.2, 1.5};
	std::vector<double> l_2_x =	{0.3, 0.4, 0.5};
	std::vector<double> l_2_y =	{0.9, 1.2, 1.5};
	std::vector<double> l_1_x =	{0.4, 0.5};
	std::vector<double> l_1_y =	{1.2, 1.5};

#ifdef table
	printf ("x,y1,y2,y3,y4\n");
#else
	printf ("x\ty1\ty2\ty3\ty4\n");
#endif

	for (double x = 0; x < 0.6; x+=0.01)
	{
		/* base_polynomial(xes, 0, 1); */
		double y1 = interpolate(l_1_x, l_1_y, x);
		double y2 = interpolate(l_2_x, l_2_y, x);
		double y3 = interpolate(l_3_x, l_3_y, x);
		double y4 = interpolate(xes, ys, x);

		/* fprintf (stdout, */
/* #ifdef table */
		/* 	"%.2lf," */
		/* 	"%.2lf," */
		/* 	"%.2lf," */
		/* 	"%.2lf," */
/* #else */
		/* 	"%.2lf\t" */
		/* 	"%.2lf\t" */
		/* 	"%.2lf\t" */
		/* 	"%.2lf\t" */
/* #endif */
		/* 	"%.2lf\n", */
		/* 	x, y1, y2, y3, y4); */
		/* /1* FILE * plot = fopen("plot.csv","a"); *1/ */
		/* /1* fprintf (plot, *1/ */
		/* /1* 	"%.2lf," *1/ */
		/* /1* 	"%.2lf," *1/ */
		/* /1* 	"%.2lf," *1/ */
		/* /1* 	"%.2lf," *1/ */
		/* /1* 	"%.2lf\n", *1/ */
		/* /1* 	x, y1, y2, y3, y4); *1/ */

	}

	return 0;
}
