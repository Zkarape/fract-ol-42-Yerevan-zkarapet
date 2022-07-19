//the formula is z = x + yi; (z)^2 = x^2 + y^2
#include <stdio.h>
#include "fractol.h"

float	mag(float x, float y)
{
	float	z_square;

	z_square = 0;
	z_square = x*x + y*y;
	return (z_square);
}
//
//int main()
//{
//	printf("%f\n", mag(2, 4));
//}
