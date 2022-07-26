#include <stdio.h>
double	power(double x, double n)
{
	double	res;

	res = 1;
	while (n >= 0)
	{
		res = res * x;
		n -= 1;
	}
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

double	v_formula(mlx strct)
{
	double	v;

}

double	color_magic()
{

}

int main()
{
	sqroot(9);
//	printf("%f\n", power(4, 1.5));
//	printf("%f\n", sqroot(9));
}
