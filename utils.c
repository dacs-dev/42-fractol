/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:48:21 by dcid-san          #+#    #+#             */
/*   Updated: 2025/04/02 16:55:48 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	scale_color(int unscaled, int curr_max)
{
	int	min_val;
	int	max_val;

	min_val = COLOR_BLACK;
	max_val = COLOR_WHITE;
	return ((max_val - min_val) * unscaled / curr_max + min_val);
}

t_coord	transform_coord(int x, int y, t_f_data *data)
{
	t_coord	coord;

	coord.real = ((x * data->scale_x) - 2.0) / data->zoom + data->added_x;
	coord.imaginary = ((y * data->scale_y) - 2.0) / data->zoom + data->added_y;
	return (coord);
}

void	set_pixel_color(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}
