/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:07:59 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/11 11:23:06 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atoi(const char *str)
{
	unsigned int	res;
	int				min;
	int				i;

	min = 1;
	res = 0;
	i = 0;
	if (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				min = -1;
			i++;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			res = res * 10 + (str[i] - '0');
			i++;
		}
	}
	return ((double)(res * min));
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
}
