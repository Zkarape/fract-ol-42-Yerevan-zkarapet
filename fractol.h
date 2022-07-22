/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:51:44 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/22 16:30:16 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL

#include <mlx.h>

typedef struct mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	double	x;
	double	y;
	double	width;
	double	height;
} mlx;

float	power(double x, int n);
float	mag(double x, double y);
void	fractol(double x, double y, int width, int height, int maxIter);

#endif
