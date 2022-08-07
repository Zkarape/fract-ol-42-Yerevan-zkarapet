#include "fractol.h"

int	set_check(t_mlx *coord)
{
	double	x_cmplx;
    double	y_cmplx;
	int		n;
	double	cr0;
	double	ci0;

	n = -1;
	coord->cr = coord->x / coord->scale_factor + coord->r;
	coord->ci = coord->y / coord->scale_factor + coord->i;
	cr0 = coord->cr;
	ci0 = coord->ci;
	while (++n < coord->maxiter && coord->ci * coord->ci + coord->cr * coord->cr < 4)
	{
		x_cmplx = coord->cr * coord->cr - coord->ci * coord->ci;
		y_cmplx = 2 * coord->cr * coord->ci;
		coord->cr = x_cmplx + cr0;
		coord->ci = y_cmplx + ci0;
	}
	return (n);
}

void	mandelbrot(t_mlx *coord, t_data *data)
{
	coord->x = 0;
	while (coord->x < coord->width)
	{
		coord->y = 0;
		while (coord->y < coord->height)
		{
			coord->k = set_check(coord);
			if (coord->k == coord->maxiter)
				my_mlx_pixel_put(data, coord->x, coord->y, 0x000000);
			else
				my_mlx_pixel_put(data, coord->x, coord->y, coord->color * v_formula(coord));
			coord->y++;
		}
		coord->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
