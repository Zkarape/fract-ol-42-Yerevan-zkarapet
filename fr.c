/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:33:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/26 22:21:30 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_real_part(double x, double width, double minR, double maxR)
{
	double	range;

	range = maxR - minR;
	return (x * (range / width) + minR);
}

double	map_img_part(double y, double height, double minI, double maxI)
{
	double	range;

	range = maxI - minI;
	return (y * (range / height) + minI);
}

int	set_check(t_mlx coord, int maxIter)
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
	while (++n < maxIter && coord.ci * coord.ci + coord.cr * coord.cr < 4)
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
	coord.mlx = mlx_init();
	coord.win = mlx_new_window(coord.mlx, 600, 600, "fract'ol");
	coord.img = mlx_new_image(coord.mlx, coord.width, coord.height);
	coord.imput = mlx_put_image_to_window(coord.mlx, coord.win, coord.img, 0, 0);
	return (coord);
}

int	main(void)
{
	t_mlx	coord;
	int		palette[8] = {0x8A39E1, 0xF1D00A, 0x2EB086, 0x54BAB9,
		0x5FD068, 0xFAC213, 0xFF06B7, 0xD4D925};

	coord = declare();
	while (coord.x < coord.height)
	{
		coord.y = 0;
		while (coord.y < coord.width)
		{
			coord.k = set_check(coord, coord.maxiter);
			if (coord.k == coord.maxiter)
				mlx_pixel_put(coord.mlx, coord.win, coord.x, coord.y, 0x000000);
			else
				mlx_pixel_put(coord.mlx, coord.win, coord.x, coord.y, palette[coord.k % 8]);
			coord.y++;
		}
		coord.x++;
	}
	mlx_loop(coord.mlx);
}
