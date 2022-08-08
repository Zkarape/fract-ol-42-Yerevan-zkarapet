/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:51:19 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/08 18:06:07 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	power(double x, int n)
{
	double	res;

	res = 1;
	while (n--)
		res = res * x;
	return (res);
}

double	sqroot(double x)
{
	double	temp;
	double	sqrt;

	temp = 0;
	sqrt = x / 2;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = ((x / temp) + temp) / 2;
	}
	return (sqrt);
}

double	find_mod(double a, double b)
{
	double	mod;

	mod = a;
	if (b < 0)
		b = -b;
	while (mod > b)
		mod = mod - b;
	return (mod);
}

double	v_formula(t_mlx *coord)
{
	double	v;
	double	d;
	double	res;

	d = power(((double)coord->k / (double)coord->maxiter), 3);
	res = power(d * coord->n, 2) / sqroot(d * coord->n);
	v = find_mod(res, coord->n);
	return (v);
}
//#include <stdio.h>
//int main()
//{
//	t_mlx *coord;
//
//	coord = malloc(sizeof(t_mlx));
//	coord->k = 60;
//	coord->maxiter = 200;
//	coord->n = 200;
//	printf("%f\n", v_formula(coord));
//}
