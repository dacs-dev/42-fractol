/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:48:21 by dcid-san          #+#    #+#             */
/*   Updated: 2025/04/04 18:13:42 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Función que interpola entre negro y fill_color según el valor normalizado t.
// t es un valor entre 0.0 y 1.0, por ejemplo, t = iterations / quality.
int	scale_color_fill(double iterations, double quality, int fill_color)
{
    double t = iterations / quality;
    int r;
	int g;
	int b;

	r = ((fill_color >> 16) & 0xFF) * t;
    g = ((fill_color >> 8) & 0xFF) * t;
    b = (fill_color & 0xFF) * t;
    return (r << 16) | (g << 8) | b;
}

int palette_color(double smooth_iter, double max_iter, t_f_data *data)
{
	double	n;
	double	p;
	int		i;                       // Variable 3: i (índice del color inferior)
    double t; 
	if (smooth_iter >= max_iter)
        return data->fill_color;
    n = smooth_iter / max_iter;    // Variable 1: n (valor normalizado)
    p = n * (data->pallete_size - 1);          // Variable 2: p (posición flotante en la paleta)
    i = (int)p;  
	t = p - i;                  // Variable 4: t (fracción para interpolar)
    // Se interpola línea a línea entre pal[i] y pal[i+1] sin variables adicionales:
    return (
        (((int)(((data->pallete[i]   >> 16) & 0xFF) + ((((data->pallete[i+1] >> 16) & 0xFF) - ((data->pallete[i]   >> 16) & 0xFF)) * t))) << 16)
        | (((int)(((data->pallete[i]   >> 8)  & 0xFF) + ((((data->pallete[i+1] >> 8)  & 0xFF) - ((data->pallete[i]   >> 8)  & 0xFF)) * t))) << 8)
        | ((int)((data->pallete[i]   & 0xFF) + ((((data->pallete[i+1] & 0xFF) - (data->pallete[i]   & 0xFF)) * t))))
    );
}


// Mapea la iteración suave a un color, reservando fill_color para el interior.
int	smooth_color(double smooth_iter, double max_iter, t_f_data *data)
{
	if (smooth_iter >= max_iter)
		return data->fill_color;
	else
		return palette_color(smooth_iter, max_iter, data);
}

double	scale_num(int num, double zoom, double scale, double added)
{
	return (((num * scale) - 2.0) / zoom + added);
}

void	set_pixel_color(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}


void	init_pallete(t_f_data *data)
{
	data->pallete[0] = 0x000000; // Negro (para puntos que escapan rápido)
	data->pallete[1] = 0xFF0000; // Rojo
	data->pallete[2] = 0x00FF00; // Verde
	data->pallete[3] = 0x0000FF; // Azul
	data->pallete[4] = 0xFFFF00; // Amarillo
	data->pallete[5] = 0xFF00FF; // Magenta
	data->pallete[6] = 0x00FFFF; // Cian
	data->pallete[7] = data->fill_color;
	data->pallete_size = 8;
}
