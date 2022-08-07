/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:33:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/07 17:36:41 by zkarapet         ###   ########.fr       */
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
	return (y * ((max_i - min_i) / height) + min_i);
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
    coord->color = 240255;
    coord->zr = -0.5;
    coord->zi = -0.5;
    coord->N = coord->argv_N;
}

void	data_declare(double width, double height, t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "fract'ol");
	data->img = mlx_new_image(data->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
}

int	main(int argc, char **argv)
{
	t_mlx	*coord;
	t_data	*data;

	data = malloc(sizeof(t_data));
	coord = malloc(sizeof(t_mlx));
    coord->argv_N = ft_atoi(argv[2]);
	declare(coord);
	data_declare(coord->width, coord->height, data);
	coord->data = data;
    if (argc >= 2)
    {
    	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
        {
            coord->flag = 3;
            mandelbrot(coord, data);
        }
        else if (ft_strncmp(argv[1], "julia", 5) == 0)
        {
            mlx_hook(data->win, 6, 1L<<6, &julia_animation, coord);
            coord->flag = 1;
            julia(coord, data);
        }
        else if (ft_strncmp(argv[1], "bonus", 5) == 0)
        {
            coord->flag = 2;
            bonus_fractal(coord, data);
        }
    }
    else if (argc == 1)
    {
        ft_putendl("Fractal name : mandelbrot || julia || bonus");
        ft_putendl("int N for color change");
        return (0);
    }
    mlx_hook(data->win, 17, 0, &destroy, data);
    mlx_key_hook(data->win, &key_hook, data);
	mlx_mouse_hook(data->win, &mouse_hook, coord);
	mlx_loop(data->mlx);
}
