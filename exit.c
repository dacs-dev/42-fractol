/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:28:34 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/26 03:28:58 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/ft_printf/ft_printf.h"

void	free_data(t_f_data *data)
{
	if (data)
	{
		if (data->img)
		{
			if (data->img->img && data->mlx_ptr)
				mlx_destroy_image(data->mlx_ptr, data->img->img);
			free(data->img);
		}
		if (data->window_ptr)
			mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		free(data);
	}
}

void	exit_with_error(char *msg, int code, t_f_data *data,
	void (*callback)(t_f_data *))
{
	if (callback)
		callback(data);
	perror(msg);
	exit(code);
}

void	exit_with_msg(char *msg, int code, t_f_data *data,
	void (*callback)(t_f_data *))
{
	if (callback)
		callback(data);
	if (msg)
		ft_printf("%s", msg);
	exit(code);
}
