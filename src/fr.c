/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:33:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/01 16:05:10 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double	map_real_part(double x, double width, double min_r, double max_r)
{
	double	range;

	range = max_r - min_r;
	return (x * (range / width) + min_r);
}

double	map_img_part(double y, double height, double min_i, double max_i)
{
	double	range;

	range = max_i - min_i;
	return (y * (range / height) + min_i);
}

int	set_check(t_mlx coord, int maxiter)
{
	double	x_cmplx;
	double	y_cmplx;
	int		n;
	double	cr0;
	double	ci0;

	n = -1;
	coord.cr = map_real_part(coord.x, coord.width, -2, 2);
	coord.ci = map_img_part(coord.y, coord.height, -2, 2);
	cr0 = coord.cr;
	ci0 = coord.ci;
	while (++n < maxiter && coord.ci * coord.ci + coord.cr * coord.cr < 4)
	{
		x_cmplx = coord.cr * coord.cr - coord.ci * coord.ci;
		y_cmplx = 2 * coord.cr * coord.ci;
		coord.cr = x_cmplx + cr0;
		coord.ci = y_cmplx + ci0;
	}
	return (n);
}

t_mlx	declare(void)
{
	t_mlx	coord;

	coord.x = 0;
	coord.y = 0;
	coord.maxiter = 200;
	coord.width = 600;
	coord.height = 600;
	return (coord);
}

t_data	data_declare(double width, double height)
{
	t_data	data;

	data.line_length = width * 4;
	data.bpp = 32;
	data.endian = 1;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, width, height, "fract'ol");
	data.img = mlx_new_image(data.mlx, width, height);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
	return (data);
}

void	my_mlx_pixel_put(t_data data, double x, double y, int color)
{
	int		memory_offset;
	char	*get_data;

	memory_offset = y * data.line_length + x * (data.bpp / 8);
	//with this formula we calculate memory offset set by mlx_get_data_addr. / 8 is done to get in bytes,
	// line_length is already in bytes
	get_data = data.addr + memory_offset;
	*(unsigned int *)get_data = color;
}

int	main(void)
{
	t_mlx	coord;
	t_data	data;

	int		palette[8] = {0x8A39E1, 0xF1D00A, 0x2EB086, 0x54BAB9,
		0x5FD068, 0xFAC213, 0xFF06B7, 0xD4D925};

	coord = declare();
	data = data_declare(coord.width, coord.height);
	while (coord.x < coord.height)
	{
		coord.y = 0;
		while (coord.y < coord.width)
		{
			coord.k = set_check(coord, coord.maxiter);
			if (coord.k == coord.maxiter)
				my_mlx_pixel_put(data, coord.x, coord.y, 0x000000);
			else
				my_mlx_pixel_put(data, coord.x, coord.y, palette[coord.k % 8]);
			coord.y++;
		}
		coord.x++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}
