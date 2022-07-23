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

void	set_check(mlx coord, int maxIter)
{
	double	x_c;//x_complex
	double	y_c;//y_complex
	int		n;
	double	a_c = map_real_part(coord.x, coord.width, -2, 2);
	double	a;
	double	b_c = map_img_part(coord.y, coord.height, -2, 2);
	double	b;
	
	n = -1;
	a = coord.x;
	b = coord.y;
	while(++n < maxIter && a * a + b * b <= 4)
	{
		x_c = a * a - b * b + a_c;
		y_c = 2 * a * b + b_c;
		a = x_c;
		b = y_c;
	}
	if (n < maxIter)
	{
		printf("done");
		mlx_pixel_put(coord.mlx_ptr, coord.win_ptr, a, b, 0xFFFFFF);
	}
}

int main()
{
	mlx		coord;

	coord.x = 0;
	coord.y = 0;
	coord.width = 500;
	coord.height = 500;
	coord.mlx_ptr = mlx_init();
	coord.win_ptr = mlx_new_window(coord.mlx_ptr, coord.width, coord.height, "fract'ol");
	coord.img_ptr = mlx_new_image(coord.mlx_ptr, coord.width, coord.height); 
	while (++coord.x < coord.height)
	{
		coord.y = 0;
		while (++coord.y < coord.width)
			set_check(coord, 40);
	}
	mlx_loop(coord.mlx_ptr);
}
