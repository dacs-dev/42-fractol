/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 00:52:39 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 00:52:39 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/Xutil.h>

void	handle_arrows(int keysym, t_f_data *data)
{
	if (keysym == XK_Left)
		data->added_x -= 0.05 / data->zoom;
	else if (keysym == XK_Right)
		data->added_x += 0.05 / data->zoom;
	else if (keysym == XK_Up)
		data->added_y -= 0.05 / data->zoom;
	else if (keysym == XK_Down)
		data->added_y += 0.05 / data->zoom;
}

void	handle_quality(int keysym, t_f_data *data)
{
	if (keysym == XK_plus || keysym == XK_KP_Add)
		data->quality += 10;
	else if ((keysym == XK_minus || keysym == XK_KP_Subtract)
		&& data->quality >= 20)
		data->quality -= 10;
}

void	handle_nums(int keysym, t_f_data *data)
{
	if (keysym == XK_1)
		data->num = MANDELBROT;
	else if (keysym == XK_2)
		data->num = JULIA;
	else if (keysym == XK_3)
		data->num = BURNING_SHIP;
	else if (keysym == XK_0)
	{
		data->added_x = 0;
		data->added_y = 0;
		data->zoom = 1.0;
		data->quality = QUALITY;
		data->julia_c_real = -0.7;
		data->julia_c_imag = 0.27015;
	}
}

int	keyboard_handler(int keysym, t_f_data *data)
{
	if (keysym == XK_Escape)
		exit_with_msg("Cerrando...\n", 0, data, free_data);
	handle_arrows(keysym, data);
	handle_quality(keysym, data);
	handle_nums(keysym, data);
	print_fractal(data);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_f_data *data)
{
	double	cord_x;
	double	cord_y;
	double	old_zoom;

	old_zoom = data->zoom;
	if (button == Button5)
		data->zoom *= 1.1;
	else if (button == Button4)
		data->zoom *= 0.9;
	else
		return (0);
	cord_x = (x * data->scale_x - 2.0) / old_zoom + data->added_x;
	cord_y = (y * data->scale_y - 2.0) / old_zoom + data->added_y;
	data->added_x = cord_x - ((x * data->scale_x - 2.0) / data->zoom);
	data->added_y = cord_y - ((y * data->scale_y - 2.0) / data->zoom);
	print_fractal(data);
	return (0);
}
