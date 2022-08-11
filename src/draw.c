/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:52:36 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/11 12:22:08 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	int		memory_offset;
	char	*get_data;

	memory_offset = y * data->line_length + x * (data->bpp / 8);
	get_data = data->addr + memory_offset;
	*(unsigned int *)get_data = color;
}

void	string_put(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 10, 0, 0xFFFFFF,"Press A, S, D, W for colors.");
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFFFFFF,"Press arrows for move.");
	mlx_string_put(data->mlx, data->win, 10, 40, 0xFFFFFF,"Scroll for zoom.");
}
