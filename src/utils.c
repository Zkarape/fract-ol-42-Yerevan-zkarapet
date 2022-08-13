/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:07:59 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/13 11:46:28 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atoi(const char *str, t_mlx *coord)
{
	if (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				coord->min = -1;
			str++;
		}
		while (*str && *str >= 48 && *str <= 57)
		{
			coord->res = coord->res * 10 + (*str - '0');
			str++;
		}
		if ((*str < 48 || *str > 57) && *str)
		{
			coord->atoi_flag = 2;
			return (0);
		}
	}
	return ((double)(coord->res * coord->min));
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *s1 && *s2 && ((unsigned char)s1[i]
			|| (unsigned char)s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

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

void	print(void)
{
	ft_putendl("Fractal name : mandelbrot || julia || bonus");
	ft_putendl("and then int N >= 0 for color change");
	exit(1);
}
