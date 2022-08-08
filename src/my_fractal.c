/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:48:10 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/08 19:03:14 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_set_check(t_mlx *coord)
{
	double	x_cmplx;
	double	y_cmplx;
	int		n;

	n = -1;
	coord->cr = coord->x / coord->scale_factor + coord->r;
	coord->ci = coord->y / coord->scale_factor + coord->i;
	while (++n < coord->maxiter && coord->ci * coord->ci
		+ coord->cr * coord->cr < 4)
	{
		x_cmplx = coord->cr * coord->cr * coord->cr
			- 3 * coord->cr * coord->ci * coord->ci - 0.4;
		y_cmplx = 3 * coord->cr * coord->cr * coord->ci
			- coord->ci * coord->ci * coord->ci;
		coord->cr = x_cmplx;
		coord->ci = y_cmplx;
	}
	return (n);
}

void	my_fractal(t_mlx *coord, t_data *data)
{
	coord->x = 0;
	while (coord->x < coord->width)
	{
		coord->y = 0;
		while (coord->y < coord->height)
		{
			coord->k = my_set_check(coord);
			if (coord->k == coord->maxiter)
				my_mlx_pixel_put(data, coord->x,
					coord->y, 0x000000);
			else
				my_mlx_pixel_put(data, coord->x, coord->y,
					coord->color * v_formula(coord));
			coord->y++;
		}
		coord->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win,
		data->img, 0, 0);
}
