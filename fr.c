#include <stdio.h>
#include "fractol.h"
#include <mlx.h>
//from real to the needed range
double	map_real_part(double x, double width, int min, int max)
{
	int	range = max - min;//output range
	//input range [0, width] => width - 0
	//int res = range / width is how many ranges are in width
	//int dis = distance_from_inputStart("range of x") is x - inputStart
	//so int last_step = dis * res gives us the last step
	//last_step + outStart just moving the last_step from 0
	return (x * (range / width) + min);
}

double	map_img_part(double y, double height, int min, int max)
{
	return (y * ((max- min) / height) + min);
}

void	set_check(double x, double y, double width, double height, int maxIter)
{
	double	x_c;//x_complex
	double	y_c;//y_complex
	int		n;
	double	a = map_real_part(x, width, -2, 2);
	double	a_c;
	double	b = map_img_part(y, height, -2, 2);
	double	b_c;
	void	*mlx_ptr = mlx_init();
	void	*win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fract'ol");
	
	n = -1;
	a_c = a;
	b_c = b;
	while(++n < maxIter && a * a + b * b <= 4)
	{
		x_c = a * a - b * b;
		y_c = 2 * a * b;
		a = x_c + a_c;
		b = y_c + b_c;
	}
	if (n < maxIter)
		mlx_pixel_put(mlx_ptr, win_ptr, a, b, 072551);
	mlx_loop(mlx_ptr);
}

int main()
{
	double	x;
	double	y;
	double	width;
	double	height;

	x = -1;
	y = -1;
	width = 500;
	height = 500;
	while (++x < height)
	{
		y = 0;
		while (++y < width)
			set_check(x, y, width, height, 40);
	}
}
