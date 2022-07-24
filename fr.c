#include <stdio.h>
#include "fractol.h"
#include <mlx.h>
//from real to the needed range
double	map_real_part(double x, double width, double minR, double maxR)
{
	double	range = maxR - minR;//output range
	//input range [0, width] => width - 0
	//int res = range / width is how many ranges are in width
	//int dis = distance_from_inputStart("range of x") is x - inputStart
	//so int last_step = dis * res gives us the last step
	//last_step + outStart just moving the last_step from 0
	return (x * (range / width) + minR);
}

double	map_img_part(double y, double height, double minI, double maxI)
{
	double	range = maxI - minI;
	return (y * (range / height) + minI);
}

int	set_check(mlx coord, int maxIter)
{
	double	x_c;//x_complex
	double	y_c;//y_complex
	int		n;
	double	cr;	
	double	ci;
	double	a;
	double	b;
	static int	co = 0;
	static int	ham = 0;
	
	n = 0;
	a = coord.x;
	b = coord.y;
	cr = map_real_part(a, coord.width, -2, 2);
	ci = map_img_part(b, coord.height, -2, 2);
	double cr0 = cr;
	double ci0 = ci;
	while(n < maxIter)
	{
		x_c = cr * cr - ci * ci;
		y_c = 2 * cr * ci;
		cr = x_c + cr0;
		ci = y_c + ci0;
		if (ci + cr > 2)
		{
			return (n);
		}
		n++;
	}
	//printf("%d %d\n", ham, co);
	//printf("%d\n", n);
	return (0);
}

int main()
{
	mlx		coord;

	coord.x = 0;
	coord.y = 0;
	coord.width = 300;
	coord.height = 300;
	coord.mlx_ptr = mlx_init();
	coord.win_ptr = mlx_new_window(coord.mlx_ptr, 500, 500, "fract'ol");
	coord.img_ptr = mlx_new_image(coord.mlx_ptr, coord.width, coord.height); 
	while (coord.x < 300)
	{
		coord.y = 0;
		while (coord.y < 300)
		{
			if (set_check(coord, 50) == 0)
			{
				mlx_pixel_put(coord.mlx_ptr, coord.win_ptr, coord.x, coord.y, 0xFFFFFF);
			}
			else
			{
				mlx_pixel_put(coord.mlx_ptr, coord.win_ptr, coord.x, coord.y, 255 * 100);
			}
			coord.y++;;
		}
		coord.x++;
	}
	mlx_loop(coord.mlx_ptr);
}
