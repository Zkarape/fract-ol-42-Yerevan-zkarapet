#include <stdio.h>

double	power(double x, int n)
{
	double	res;

	res = 1;
	while (n--)
		res = res * x;
	return (res);
}

double	sqroot(double x)
{
	double	temp;
	double	sqrt;

	temp = 0;
	sqrt = x / 2;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = ((x / temp) + temp) / 2;
	}
	return (sqrt);
}

double	find_mod(double a, double b)
{
	double	mod;

	mod = a;
	if (b < 0)
		b = -b;
	while (mod > b)
		mod = mod - b;
	return (mod);
}

double	v_formula(double iter_count, double maxIter, double N)//N is the count of palette items
{
	double	v;
	double	d;
	double res;

	d = power((iter_count / maxIter), 3);
	res = power(d * N, 2) / sqroot(d * N);
	v = find_mod(res, N);
	return (v);
}
