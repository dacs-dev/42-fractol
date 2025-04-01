/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:45:46 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/29 23:56:00 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	set_pixel_color(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	compute_mandelbrot(t_coord c, t_f_data *data)
{
	t_coord	z;
	t_coord	c;
	int		i;
	double	temp;

	c.real = ((x * data->scale_x) - 2.0) / data->zoom + data->added_x;
	c.imaginary = ((y * data->scale_y) - 2.0) / data->zoom + data->added_y;
	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i < data->quality)
	{
		temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = temp;
		if ((z.real * z.real + z.imaginary * z.imaginary) > 4)
			break ;
		i++;
	}
	if (i == data->quality)
		set_pixel_color(x, y, COLOR_MAGENTA, data->img);
	else
		set_pixel_color(x, y, scale_color(i, data->quality), data->img);
}

/* Cálculo del Julia */
void	compute_julia(t_coord z, t_f_data *data)
{
	t_coord	z;
	t_coord	c;
	int		i;
	double	temp;

	z.real = ((x * data->scale_x) - 2.0) / data->zoom + data->added_x;
	z.imaginary = ((y * data->scale_y) - 2.0) / data->zoom + data->added_y;
	c.real = data->julia_c_real;
	c.imaginary = data->julia_c_imag;
	i = 0;
	while (i < data->quality)
	{
		temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = temp;
		if ((z.real * z.real + z.imaginary * z.imaginary) > 4)
			break ;
		i++;
	}
	if (i == data->quality)
		set_pixel_color(x, y, COLOR_MAGENTA, data->img);
	else
		set_pixel_color(x, y, scale_color(i, data->quality), data->img);
}

void	compute_burningship(t_coord c, t_f_data *data)
{
	t_coord	z;
	int		i;

	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i < data->quality)
	{
		double
		if ((z.real * z.real + z.imaginary * z.imaginary) > 4)
			break ;
		i++;
	}
	if (i == data->quality)
		set_pixel_color(x, y, COLOR_MAGENTA, data->img);
	else
		set_pixel_color(x, y, scale_color(i, data->quality), data->img);
}



void	print_fractal(t_f_data *data)
{
	int	x;
	int	y;
	t_coord scaled;

	x = 0;
	while (x < WIDTH)
	{
		scaled.real = ((x * data->scale_x) - 2.0) / data->zoom + data->added_x;
		y = 0;
		while (y < HEIGHT)
		{
			scaled.imaginary = ((y * data->scale_y) - 2.0) / data->zoom + data->added_y;
			if (data->num == MANDELBROT)
				compute_mandelbrot(x, y, data);
			else if (data->num == JULIA)
				compute_julia(x, y, data);
			else if (data->num == BURNING_SHIP)
				compute_burningship(x, y, data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img->img, 0, 0);
}
