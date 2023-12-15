#include<iostream>
#include<stdexcept>
#include<math.h>

double cone_frustum_area (double r, double R, double generatrix)
{
	if (r <= 0 || R <= 0 || generatrix <= 0)
		throw std::runtime_error("Input positive values");
	else
		return M_PI*(r*generatrix/R)*(R+r) + M_PI*R*R + M_PI*r*r;
}

double celsius_to_fahrenheit (double celsius)
{
	return 9*celsius/5 + 32;
}

double arctg_taylor (double x, int n)
{
	double sum;
	if (abs(x) < 1)
		for (int i=0; i <= n; i++)
			sum += pow(x, 2*i+1)*pow(-1, i)/(2*i + 1);
	else
		throw std::runtime_error("-1 < Input value < 1");
	return sum;
}

double sphere_area (double r)
{
	if (r <= 0)
		throw std::runtime_error("Input positive values");
	return 4*M_PI*pow(r,2);
};
double sphere_volume (double r)
{
	if (r <= 0)
		throw std::runtime_error("Input positive values");
	return M_PI*pow(r,3)*4/3;
};
