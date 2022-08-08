/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:33:11 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/08 21:13:07 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

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
	coord->color = 72013;
	coord->zr = -0.5;
	coord->zi = -0.5;
	coord->n = coord->argv_n;
	coord->flag = 5;
}

void	data_declare(double width, double height, t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "fract'ol");
	data->img = mlx_new_image(data->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
}

void	mlx_func(t_mlx *coord, t_data *data)
{
	mlx_hook(data->win, 17, 0, &destroy, data);
	mlx_key_hook(data->win, &key_hook, coord);
	mlx_mouse_hook(data->win, &mouse_hook, coord);
	mlx_string_put(data->mlx, data->win, 300, 0, 0xFFFFFF, "Press A, W, D, S");
	mlx_loop(data->mlx);
}

void	short_but_main(char **argv, t_mlx *coord, t_data *data)
{
	if (ft_atoi(argv[2]) >= 0)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		{
			coord->flag = 3;
			mandelbrot(coord, coord->data);
		}
		else if (ft_strncmp(argv[1], "julia", 5) == 0)
		{
			mlx_hook(data->win, 6, 1L << 6, &julia_animation, coord);
			coord->flag = 1;
			julia(coord, coord->data);
		}
		else if (ft_strncmp(argv[1], "bonus", 5) == 0)
		{
			coord->flag = 2;
			my_fractal(coord, coord->data);
		}
	}
}

int	main(int argc, char **argv)
{
	t_mlx	*coord;
	t_data	*data;

	coord = malloc(sizeof(t_mlx));
	data = malloc(sizeof(t_data));
	coord->argv_n = ft_atoi(argv[2]);
	declare(coord);
	data_declare(coord->width, coord->height, data);
	coord->data = data;
	if (argc >= 3 && coord->flag != 5)
	{
		short_but_main(argv, coord, coord->data);	
		mlx_func(coord, data);
	}
	else if (coord->flag == 5 || argc <= 2)
	{
		ft_putendl("Fractal name : mandelbrot || julia || bonus");
		ft_putendl("and then int N for color change");
		return (0);
	}
}
