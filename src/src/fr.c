/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:33:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/05 13:06:45 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fractol.h"
#include <stdio.h>

//double	map_real_part(double x, double width, double min_r, double max_r)
//{
//	double	range;
//
//	range = max_r - min_r;
//	return (x * (range / width) + min_r);
//}
//
//double	map_img_part(double y, double height, double min_i, double max_i)
//{
//	double	range;
//
//	range = max_i - min_i;
//	return (y * (range / height) + min_i);
//}

int	set_check(t_mlx *coord)
{
	double	x_cmplx;
    double	y_cmplx;
	int		n;
	double	cr0;
	double	ci0;

	n = -1;
//	coord->cr = map_real_part(coord->x / coord->scale_factor + coord->r, coord->width, -2, 2);
	coord->cr = coord->x / coord->scale_factor + coord->r;
//	coord->ci = map_img_part(coord->y / coord->scale_factor + coord->i, coord->height, -2, 2);
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

void	declare(t_mlx *coord)
{
	coord->scale_factor = 200;
	coord->x = 0;
	coord->y = 0;
	coord->r = -2.05;
	coord->i = -1.3;
	coord->maxiter = 200;
	coord->width = 800;
	coord->height = 800;
}

void	data_declare(double width, double height, t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "fract'ol");
	data->img = mlx_new_image(data->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
}

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	int		memory_offset;
	char	*get_data;

	memory_offset = y * data->line_length + x * (data->bpp / 8);
	get_data = data->addr + memory_offset;
	*(unsigned int *)get_data = color;
}

void	mandelbrot(int palette[8], t_mlx *coord, t_data *data)
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
	int		palette[8] = {0x8A39E1, 0xF1D00A, 0x2EB086, 0x54BAB9,
		0x5FD068, 0xFAC213, 0xFF06B7, 0xD4D925};

	data = malloc(sizeof(t_data));
	coord = malloc(sizeof(t_mlx));
	declare(coord);
	data_declare(coord->width, coord->height, data);
	coord->data = data;
	//if (ft_strcmp(argv[1], "./mandelbrot") == 0)
		mandelbrot(palette, coord, data);
	mlx_key_hook(data->win, &key_hook, data);
	mlx_mouse_hook(data->win, &mouse_hook, coord);
	mlx_loop(data->mlx);
}
