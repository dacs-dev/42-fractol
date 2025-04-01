/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:10:29 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/29 13:58:47 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_args(int argc, char **argv, t_f_data *data)
{
	char *f_name;

	f_name = ft_strlower(argv[1]);
	if (argc == 2 && ft_strncmp(f_name, MANDELBROT_STR, 10) == 0)
	{
		data->num = MANDELBROT;
		data->name = MANDELBROT_STR;
	}
	else if (argc == 4 && ft_strncmp(f_name, JULIA_STR, 10) == 0)
	{
		data->num = JULIA;
		data->name = JULIA_STR;
	}
	else
	{
		exit_with_error("Nombre erroneo de fractal", 1, data, NULL);
	}
}

void	init_data(t_f_data *data)
{
	data->hypotenuse_max = 4;
	data->added_x = 0;
	data->added_y = 0;
	data->quality = QUALITY;
	data->julia_c_real = -0.7;
	data->julia_c_imag = 0.27015;
	data->scale_x = 4.0 / WIDTH;
	data->scale_y = 4.0 / HEIGHT;
	data->zoom = 1.0;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit_with_error("Malloc of mlx_ptr fail\n", 1, data, NULL);
	data->window_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (data->window_ptr == NULL)
		exit_with_error("window_ptr fail\n", 1, data, free_data);

	data->img = malloc(sizeof(t_img));
	if (data->img == NULL)
		exit_with_error("Malloc for img fail\n", 1, data, free_data);

	data->img->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (data->img->img == NULL)
		exit_with_error("Image creation fail\n", 1, data, free_data);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel,
			&data->img->line_length, &data->img->endian);
}

int	main(int argc, char **argv)
{
	t_f_data	*data;

	data = malloc(sizeof(t_f_data));
	parse_args(argc, argv, data);
	init_data(data);
	mlx_key_hook(data->window_ptr, keyboard_handler, data);
	mlx_hook(data->window_ptr, ButtonPress,
		ButtonPressMask, mouse_handler, data);
	mlx_hook(data->window_ptr, DestroyNotify,
		StructureNotifyMask, close_handler, data);
	print_fractal(data);
	mlx_loop(data->mlx_ptr);
	free_data(data);
	return (0);
}
