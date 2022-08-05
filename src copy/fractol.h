/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:36:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/04 16:23:07 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct s_complex
{
	double	real;
	double	imag;
}	comp;

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

typedef struct mlx
{
	int		x;
	int		y;
	double	r;
	double	i;
	int		width;
	int		height;
	double	cr;
	double	ci;
	double	origin_r;
	double	origin_y;
	double	scale_factor;
	int		k;
	int		maxiter;
	int		k_hook;
	int		m_hook;
	int		palette[8];
	t_data	*data;
}	t_mlx;

int		set_check(t_mlx *coord, int maxIter);
double	map_img_part(double y, double height, double minI, double maxI);
double	map_real_part(double x, double width, double minR, double maxR);
double	power(double x, int n);
double	sqroot(double x);
double	find_mod(double a, double b);
double	v_formula(double iter_count, double maxIter, double N);
void	zoom_in(int x, int y, t_mlx *coord);
void	zoom_out(int x, int y, t_mlx *coord);
int 	close(t_data *data);
int		mouse_hook(int mousecode, int x, int y, t_mlx *coord);
int		key_hook(int keycode, t_data *data);
double	ft_double_atoi(char *str);
void	mandelbrot(int palette[8], t_mlx *coord, t_data *data);

#endif
