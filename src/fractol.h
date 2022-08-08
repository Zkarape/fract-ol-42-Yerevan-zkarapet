/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:36:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/08 17:43:51 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>

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
	double	zi;
	double	zr;
	double	scale_factor;
	int		k;
	double	n;
	double	argv_n;
	int		maxiter;
	int		color;
	int		flag;
	t_data	*data;
}	t_mlx;

int		destroy(t_data *data);
void	ft_putendl(char *s);
int		julia_animation(int x, int y, t_mlx *coord);
double	ft_atoi(const char *str);
double	map_img_part(double y, double height, double minI, double maxI);
double	map_real_part(double x, double width, double minR, double maxR);
double	power(double x, int n);
double	sqroot(double x);
double	v_formula(t_mlx *coord);
void	zoom_in(int x, int y, t_mlx *coord);
void	zoom_out(int x, int y, t_mlx *coord);
int		close(t_data *data);
int		mouse_hook(int mousecode, int x, int y, t_mlx *coord);
int		key_hook(int keycode, t_mlx *coord);
double	ft_double_atoi(char *str);
void	mandelbrot(t_mlx *coord, t_data *data);
void	julia(t_mlx *coord, t_data *data);
void	my_fractal(t_mlx *coord, t_data *data);
void	my_mlx_pixel_put(t_data *data, double x, double y, int color);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

#endif
