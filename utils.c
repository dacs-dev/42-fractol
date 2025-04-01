/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:48:21 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/29 14:11:33 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale_range(double unscaled, double min_val, 
	double max_val, double curr_min, double curr_max)
{
	return (max_val - min_val) * (unscaled - curr_min)
		/ (curr_max - curr_min) + min_val;
}

t_coord sum_coord(t_coord coord1, t_coord coord2)
{
	t_coord sum;

	sum.real = coord1.real + coord2.real;
	sum.imaginary = coord1.imaginary + coord2.imaginary;
	return (sum);
}

t_coord square_coord(t_coord current)
{
	t_coord square;
	square.real = (current.real * current.real) - (current.imaginary * current.imaginary);
	square.imaginary = 2 * (current.real * current.imaginary);
	return (square);
}
int get_color(int i, int quality)
{
	double t;
	int		red;
	int		green;
	int		blue;
    
	t = (double)i / quality;
    red   = (int)(127.5 * (sin(2 * PI * t) + 1));
    green = (int)(127.5 * (sin(2 * PI * t + 2 * PI / 3) + 1));
    blue  = (int)(127.5 * (sin(2 * PI * t + 4 * PI / 3) + 1));
    return ((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF);
}