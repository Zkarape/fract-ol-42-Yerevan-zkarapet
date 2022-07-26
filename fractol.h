/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:36:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/26 22:20:21 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>

typedef struct mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		imput;
	double	x;
	double	y;
	double	width;
	double	height;
	double	cr;
	double	ci;
	int		k;
	int		maxiter;
	int		k_hook;
	int		m_hook;
}	t_mlx;

int		set_check(t_mlx coord, int maxIter);
double	map_img_part(double y, double height, double minI, double maxI);
double	map_real_part(double x, double width, double minR, double maxR);
double	power(double x, int n);
double	sqroot(double x);
double	find_mod(double a, double b);
double	v_formula(double iter_count, double maxIter, double N);

#endif
