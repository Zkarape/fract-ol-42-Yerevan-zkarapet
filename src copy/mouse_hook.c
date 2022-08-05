/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:01:09 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/04 16:23:56 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_mlx *coord)
{
	coord->r = (x / coord->scale_factor + coord->r) - (x / coord->scale_factor * 0.9);
	coord->i = (y / coord->scale_factor + coord->i) - (y / coord->scale_factor * 0.9);
	coord->scale_factor *= 0.9;
	coord->maxiter++;
}

void	zoom_out(int x, int y, t_mlx *coord)
{
	coord->r = (x / coord->scale_factor + coord->r) - (x / coord->scale_factor / 0.9);
	coord->i = (y / coord->scale_factor + coord->i) - (y / coord->scale_factor / 0.9);
	coord->scale_factor /= 0.9;
	coord->maxiter--;
}

int	mouse_hook(int mousecode, int x, int y, t_mlx *coord)
{
	int palette[8] = {0x8A39E1, 0xF1D00A, 0x2EB086, 0x54BAB9,
		0x5FD068, 0xFAC213, 0xFF06B7, 0xD4D925};
	if (mousecode == 5)
	{
		zoom_in(x, y, coord);
		//coord->scale_factor *= 2;
//		printf("4 == %f\n", coord->scale_factor);
	//	mandelbrot(palette, coord, coord->data);
	}
	else if (mousecode == 4)
	{
		zoom_out(x, y, coord);
	//	coord->scale_factor /= 2;
//		printf("5 == %f\n", coord->scale_factor);
	}
	mandelbrot(palette, coord, coord->data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	return (0);
}
