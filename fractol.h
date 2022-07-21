/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:51:44 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/21 20:07:54 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL

#include <mlx.h>

float	power(double x, int n);
float	mag(double x, double y);
void	fractol(double x, double y, int width, int height, int maxIter);

#endif
