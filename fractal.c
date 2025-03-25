/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san < dcid-san@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:45:46 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/25 17:48:37 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static void set_pixel_color(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	prepare_pixel(int x, int y, t_f_data *data)
{
	t_coord	z;
	t_coord	c;
	int		i;
	int		color;

	z.real = 0;
	z.imaginary = 0;
	c.real = (scale_range(x, -2, 2, 0, WIDTH) * data->zoom) + data->added_x;
	c.imaginary = (scale_range(y, -2, 2, 0, HEIGHT)
			* data->zoom) + data->added_y;
	i = -1;
	while (++i < data->quality)
	{
		z = sum_coord(square_coord(z), c);
		if (((z.real * z.real) + (z.imaginary * z.imaginary))
			> data->hypotenuse_max)
		{
			color = scale_range(i, COLOR_BLACK, COLOR_WHITE, 0, data->quality);
			set_pixel_color(x, y, color, data->img);
			return
		}
	}
	set_pixel_color(x, y, COLOR_MAGENTA, data->img);
}

void print_fractal(t_f_data *data)
{
	int x;
	int y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			prepare_pixel(x, y, data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->img->img, 0, 0);
}
