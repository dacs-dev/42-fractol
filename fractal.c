/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:38:29 by dcid-san          #+#    #+#             */
/*   Updated: 2025/04/04 18:11:55 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

// Transforma las coordenadas de píxel a las coordenadas del plano complejo.
// Función de iteración para Mandelbrot (se utiliza también para Julia).
t_coord	mandelbrot_iterate(t_coord z, t_coord c)
{
	t_coord	result;

	result.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
	result.imaginary = 2 * z.real * z.imaginary + c.imaginary;
	return (result);
}

// Función de iteración para Burning Ship.
// Se aplican los valores absolutos a las partes real
// e imaginaria antes de cada iteración.
t_coord	burningship_iterate(t_coord z, t_coord c)
{
	t_coord	result;
	double	abs_real;
	double	abs_imag;

	abs_real = fabs(z.real);
	abs_imag = fabs(z.imaginary);
	result.real = abs_real * abs_real - abs_imag * abs_imag + c.real;
	result.imaginary = 2 * abs_real * abs_imag + c.imaginary;
	return (result);
}

// Función genérica que computa la cantidad de iteraciones para un punto dado.
// La función 'iterate' se encarga de aplicar la fórmula propia del fractal.
double	compute_iterations(t_coord variable, t_coord constant, t_f_data *data,
						t_coord (*iterate)(t_coord, t_coord))
{
	int		i;
	t_coord	zn;
	double	smooth_iter;
	double	mod;

	zn = variable;
	i = 0;
	while ((zn.real * zn.real + zn.imaginary * zn.imaginary) < 4.0
		&& i < data->quality)
	{
		if (i == data->quality - 1)
			return (data->quality);
		zn = iterate(zn, constant);
		i++;
	}
	mod = sqrt(zn.real * zn.real + zn.imaginary * zn.imaginary);
	if (1.0f < log2(mod))
		smooth_iter = (double)i + 1 - log2(log2(mod));
	else
		smooth_iter = (double)i + 1 -  log2(1.0f);
	return (smooth_iter);
}

// Función principal que recorre cada píxel y dibuja el fractal seleccionado.
//t_coord c; Parámetro constante para fractales (por ejemplo, para Julia)
double	calculate_fractal(t_coord	coord, t_f_data *data )
{
	if (data->num == MANDELBROT)
		return (compute_iterations((t_coord){0, 0}
			, coord, data, mandelbrot_iterate));
	else if (data->num == JULIA)
	{
		return (compute_iterations(coord,
				(t_coord){data->julia_c_real, data->julia_c_imag},
			data, mandelbrot_iterate));
	}
	else if (data->num == BURNING_SHIP)
		return (compute_iterations((t_coord){0, 0}, coord
			, data, burningship_iterate));
	return (0);
}

void	print_fractal(t_f_data *data)
{
	int		x;
	int		y;
	double	iterations;
	t_coord	scaled;

	y = 0;
	while (y < HEIGHT)
	{
		scaled.imaginary = scale_num(y,
				data->zoom, data->scale_y, data->added_y);
		x = 0;
		while (x < WIDTH)
		{
			scaled.real = scale_num(x,
					data->zoom, data->scale_x, data->added_x);
			iterations = calculate_fractal(scaled, data);
			/* set_pixel_color(x, y,
				smooth_color(iterations, data->quality, data),
				data->img); */
			set_pixel_color(x, y,
				scale_color_fill(iterations, data->quality, data->fill_color),
				data->img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img->img, 0, 0);
}
