/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:36:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/31 20:58:57 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>

typedef struct mlx
{
	double	x;
	double	y;
	double	r;
	double	i;
	double	width;
	double	height;
	double	cr;
	double	ci;
	double	origin_r;
	double	origin_y;
	int		k;
	int		maxiter;
	int		k_hook;
	int		m_hook;
	char	*scale_arg;
}	t_mlx;

typedef struct data
{
	void	*mlx;
	void	*win;
	char	*addr;
	void	*img;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

int		set_check(t_mlx coord, int maxIter);
double	map_img_part(double y, double height, double minI, double maxI);
double	map_real_part(double x, double width, double minR, double maxR);
double	power(double x, int n);
double	sqroot(double x);
double	find_mod(double a, double b);
double	v_formula(double iter_count, double maxIter, double N);

#endif
