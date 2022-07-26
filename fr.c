/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:33:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/26 15:42:42 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	double	x_cmplx;
	double	y_cmplx;
	int		n;
	double	cr;
	double	ci;
	double	cr0;
	double	ci0;

	n = -1;
	cr = map_real_part(coord.x, coord.width, -2, 2);
	ci = map_img_part(coord.y, coord.height, -2, 2);
	cr0 = cr;
	ci0 = ci;
	while(++n < maxIter && ci * ci + cr * cr < 4)
	{
		x_cmplx = cr * cr - ci * ci;
		y_cmplx = 2 * cr * ci;
		cr = x_cmplx + cr0;
		ci = y_cmplx + ci0;
	}
	return (n);
}

int main()
{
	mlx		coord;

	coord.x = 0;
	coord.y = 0;
	coord.maxIter = 50;
	coord.width = 300;
	coord.height = 300;
	coord.mlx_ptr = mlx_init();
	coord.win_ptr = mlx_new_window(coord.mlx_ptr, 500, 500, "fract'ol");
	coord.img_ptr = mlx_new_image(coord.mlx_ptr, coord.width, coord.height);
	coord.img_to_win = mlx_put_image_to_window(coord.mlx_ptr, coord.win_ptr, coord.img_ptr, 0, 0);
	while (coord.x < coord.height)
	{
		coord.y = 0;
		while (coord.y < coord.width)
		{
			coord.iter_count = set_check(coord, coord.maxIter);
			if (coord.iter_count == coord.maxIter)
				mlx_pixel_put(coord.mlx_ptr, coord.win_ptr, coord.x, coord.y, 25500);
			coord.y++;;
		}
		coord.x++;
	}
	mlx_loop(coord.mlx_ptr);
}
