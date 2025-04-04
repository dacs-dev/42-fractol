/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:48:21 by dcid-san          #+#    #+#             */
/*   Updated: 2025/04/04 05:49:31 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Función que interpola entre negro y fill_color según el valor normalizado t.
// t es un valor entre 0.0 y 1.0, por ejemplo, t = iterations / quality.
int	scale_color_fill(double iterations, double quality, int fill_color)
{
    double t = iterations / quality;
    int r = ((fill_color >> 16) & 0xFF) * t;
    int g = ((fill_color >> 8) & 0xFF) * t;
    int b = (fill_color & 0xFF) * t;
    return (r << 16) | (g << 8) | b;
}

// Convierte valores H, S, V (cada uno en [0..1] excepto H en [0..360]) a un color 0xRRGGBB.
static int hsb_to_rgb(double h, double s, double v)
{
    // Aseguramos que hue esté en [0..360)
    while (h < 0.0)    h += 360.0;
    while (h >= 360.0) h -= 360.0;

    int hi = (int)(h / 60.0) % 6;
    double f = (h / 60.0) - hi;
    double p = v * (1.0 - s);
    double q = v * (1.0 - f * s);
    double t = v * (1.0 - (1.0 - f) * s);

    double r, g, b;
    if      (hi == 0) { r = v; g = t; b = p; }
    else if (hi == 1) { r = q; g = v; b = p; }
    else if (hi == 2) { r = p; g = v; b = t; }
    else if (hi == 3) { r = p; g = q; b = v; }
    else if (hi == 4) { r = t; g = p; b = v; }
    else              { r = v; g = p; b = q; }

    // Pasa cada componente a [0..255] y empaqueta en 0xRRGGBB
    return ((int)(r * 255) << 16) | ((int)(g * 255) << 8) | (int)(b * 255);
}

// Mapea la iteración suave a un color, reservando fill_color para el interior.
int smooth_color(double smooth_iter, double max_iter, int fill_color)
{
    // Si el punto NO escapa (llega al máximo), pintamos con fill_color
    if (smooth_iter >= max_iter)
        return fill_color;

    // Ajusta la escala para controlar cuántos “ciclos” de color quieres
    double hue = 360.0 * (smooth_iter / max_iter); 
    double saturation = 1.0;
    double brightness = 1.0;

    return hsb_to_rgb(hue, saturation, brightness);
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

void	init_pallete(t_f_data *data)
{
	data->pallete[0] = 0xFF0000;
	data->pallete[1] = 0x00FF00;
	data->pallete[2] = 0x0000FF;
	data->pallete[3] = 0xFFFF00;
	data->pallete[4] = 0xFF00FF;
	data->pallete[5] = 0x00FFFF;
	data->pallete[6] = 0xFFA500;
	data->pallete[7] = 0xFFFFFF;
}