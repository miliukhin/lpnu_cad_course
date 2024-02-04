#include<vector>
#include<stdio.h>
#include<math.h>

#define test

void print_matrix (
		std::vector <std::vector <double> > A
		)
{
	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j < A.size(); j++)
			printf("%3.1lf\t", A[i][j]);
		printf("\n");
	}
}

void print_vector (
		std::vector <double> A
		)
{
	for(int j = 0; j < A.size(); j++)
#ifdef test
		printf("%0.2e\t", A[j]);
#else
		printf("%0.2e,", A[j]);
#endif
	printf("\n");
}

void gauss(
		std::vector <std::vector <double> > &A,
		std::vector<double> &B
		)
{
	int n = B.size();

	for (int k = 0; k < n-1; k++) {
		/* визначення найбільшого елемента */
		double value = 0;
		int index = 0;
		for (int i = k; i < n; ++i)
			if (fabs(A[i][k]) > value) {
				value = fabs(A[i][k]);
				index = i;
			}
#ifdef test
		printf("%lf \t%d\t%d\n", value, k, index);
#endif
		/* перестановка рядків */
		std::swap(A[k], A[index]);
		std::swap(B[k], B[index]);

		if (A[k][k] == 0) {
			printf("Error: A[k][k] == 0");
			return;
		}

		/* побудова трикутної матриці */
		for (int i = k+1; i < n; ++i) {
			double m = A[i][k] / A[k][k];
			for (int j = k; j < n; ++j)
				A[i][j] = A[i][j] - A[k][j] * m;
			B[i] = B[i] - B[k] * m;
		}
	}

	/* даємо значення B, щоб було зручно віднімати в циклі*/
	std::vector <double> X = B;

	X[n - 1] = B[n - 1] / A[n - 1][n - 1];
	for (int i = n-2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++)
			X[i] = X[i] - A[i][j] * X[j];
		X[i] = X[i] / A[i][i];
	}

	print_vector(X);
}

void seidel (
	std::vector <std::vector <double> > &A,
	std::vector<double> &B,
	std::vector<double> &X0,
	double delta
	)
{
	int dimension = X0.size();
	std::vector<double> X = X0;

#ifdef test
	printf("0\t");
#else
	printf("0,");
#endif
	print_vector(X0);

	for (int k = 1; k < 40; k++) {
		for (int i = 0; i < dimension; i++) {
			X[i] = B[i];
			for (int j = 0; j < dimension; j++) {
				if (i != j)
					X[i] = X[i] - A[i][j] * X[j];
			}
			X[i] = X[i] / A[i][i];
		}

		std::vector<double> eps;
		std::vector<double> ksi;
		for (int i = 0; i < dimension; i++) {
			eps.push_back(abs(X[i] - X0[i]));
			ksi.push_back(eps[i] / (abs(X[i]) + delta));
		}
#ifdef test
		printf("eps\t");
		print_vector(eps);
		printf("ksi\t");
		print_vector(ksi);
#endif

		X0 = X;
		int eps_max = 0;
		int ksi_max = 0;
		for (int i = 0; i < dimension; i++) {
			if (eps_max < eps[i]) eps_max = eps[i];
			if (ksi_max < ksi[i]) ksi_max = ksi[i];
		}
#ifdef test
	printf("%d\t", k);
#else
	printf("%d,", k);
#endif
		print_vector(X);
		if (eps_max < delta && ksi_max < delta)
			break;
	}
}

int main () {

std::vector <double> X0 = {0,0,0,0,0};
double delta = 1.0e-10;

std::vector <std::vector <double> > A = {
	{1,  1,  1,  1,  1},
	{-0.3,  2.3, -0.4, -0.4, -0.2},
	{-0.8, -0.6,  1.5, -0.8, -0.6},
	{-0.3, -0.9, -0.4,  2.1,  0},
	{-0.7, -0.4, -0.7, -0.4,  1.7}
};
std::vector <double> B = {6, 1.2, -1.56, 0.6, -0.6};

	gauss(A, B);
	seidel(A, B, X0, delta);
}
