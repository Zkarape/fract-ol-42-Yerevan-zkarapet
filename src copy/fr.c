/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:33:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/04 16:24:24 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

//int	map_real_part(int x, int width, int min_r, int max_r)
//{
//	int	range;
//
//	range = max_r - min_r;
//	return (x * (range / width) + min_r);
//}
//
//int	map_img_part(int y, int height, int min_i, int max_i)
//{
//	int	range;
//
//	range = max_i - min_i;
//	return (y * (range / height) + min_i);
//}

comp	add(comp a, comp b)
{
	comp	ret;

	ret.real = a.real + b.real;
	ret.imag = a.imag + b.imag;
	return (ret);
}

comp 	multiply(comp a, comp b)
{
	comp	ret;

	ret.real = a.real * b.real - a.imag * b.imag;
	ret.imag = a.real * b.imag + a.imag * b.real;
	return (ret);
}

int	module(comp a)
{
	int	ret;

	ret = sqrt(a.real * a.real + a.imag * a.imag);
	return (ret);
}

int	mandel_set_check(t_mlx *coord, int maxiter, comp c)
{
//	int	x_cmplx;
//	int	y_cmplx;
//	int		n;
//	comp	c;
//
//	n = -1;
//	coord->cr = map_real_part(coord->x, coord->width, -2, 2);
//	coord->ci = map_img_part(coord->y, coord->height, -2, 2);
//	c.real = coord->x / coord->scale_factor + coord->r;
//	c.imag = coord->y / coord->scale_factor + coord->i;
//	while (++n < maxiter && coord->ci * coord->ci + coord->cr * coord->cr < 4)
//	{
//		x_cmplx = coord->cr * coord->cr - coord->ci * coord->ci;
//		y_cmplx = 2 * coord->cr * coord->ci;
//		coord->cr = x_cmplx + cr0;
//		coord->ci = y_cmplx + ci0;
//	}
//	return (n);
	int		n;
	comp	z;

	n = 0;
	z = (comp) {.real = 0, .imag = 0};
	while (module(z) <= 2 && n < maxiter)
	{
		z = multiply(z, z);
		z = add(z, c);
		n++;
	}
	return (n);
}

void	declare(t_mlx *coord)
{
	coord->scale_factor = 20;
	coord->r = -2;
	coord->i = -1.3;
	coord->x = 0;
	coord->y = 0;
	coord->maxiter = 200;
	coord->width = 600;
	coord->height = 600;
}

void	data_declare(int width, int height, t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "fract'ol");
	data->img = mlx_new_image(data->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int		memory_offset;
	char	*get_data;

	memory_offset = y * data->line_length + x * (data->bpp / 8);
	get_data = data->addr + memory_offset;
	*(unsigned int *)get_data = color;
}

void	mandelbrot(int palette[8], t_mlx *coord, t_data *data)
{
	comp	c;
	coord->x = 0;
	coord->y = 0;
	while (coord->x < coord->height)
	{
		coord->y = 0;
		while (coord->y < coord->width)
		{
			c.real = coord->x / coord->scale_factor + coord->r;
			c.imag = coord->y / coord->scale_factor + coord->i;
			coord->k = mandel_set_check(coord, coord->maxiter, c);
			if (coord->k == coord->maxiter)
				my_mlx_pixel_put(data, coord->x, coord->y, 0x000000);
			else
				my_mlx_pixel_put(data, coord->x, coord->y, palette[coord->k % 8]);
			coord->y++;
		}
		coord->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	main()
{
	t_mlx	*coord;
	t_data	*data;
	int palette[8] = {0x8A39E1, 0xF1D00A, 0x2EB086, 0x54BAB9,
		0x5FD068, 0xFAC213, 0xFF06B7, 0xD4D925};

	coord = malloc(sizeof(t_mlx));
	data = malloc(sizeof(t_data));
	declare(coord);
	data_declare(coord->width, coord->height, data);
	coord->data = data;
	//if (ft_strcmp(argv[1], "./mandelbrot") == 0)
		mandelbrot(palette, coord, data);
	mlx_key_hook(data->win, &key_hook, data);
	mlx_mouse_hook(data->win, &mouse_hook, coord);
	mlx_loop(data->mlx);
}
