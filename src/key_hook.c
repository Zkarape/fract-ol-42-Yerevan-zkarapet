/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:02:27 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/09 22:05:12 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(int keycode, t_mlx *coord)
{
	if (keycode == 0)
		coord->color = 25582242;
	else if (keycode == 1)
		coord->color = 255255255;
	else if (keycode == 2)
		coord->color = 233160160;
	else if (keycode == 13)
		coord->color = 163128203;
}

int	key_hook(int keycode, t_mlx *coord)
{
	if (keycode == 53)
	{
		mlx_destroy_window(coord->data->mlx, coord->data->win);
		exit(1);
	}
	color(keycode, coord);
	if (keycode == 126)
		coord->i += 30 / coord->scale_factor;
	else if (keycode == 124)
		coord->r -= 30 / coord->scale_factor;
	else if (keycode == 123)
		coord->r += 30 / coord->scale_factor;
	else if (keycode == 125)
		coord->i -= 30 / coord->scale_factor;
	if (coord->flag == 3)
		mandelbrot(coord, coord->data);
	else if (coord->flag == 1)
		julia(coord, coord->data);
	else if (coord->flag == 2)
		my_fractal(coord, coord->data);
	return (0);
}
