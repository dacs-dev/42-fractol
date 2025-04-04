/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:31:16 by dcid-san          #+#    #+#             */
/*   Updated: 2025/04/04 18:00:52 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xutil.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600
# define QUALITY 42
# define TITLE "Fractol by dcid-san"
# define COLOR_BLACK 0x000000 
# define COLOR_WHITE 0xFFFFFF
# define COLOR_MAGENTA 0xFF00FF
# define HELP_MSG "Uso:\n\t./fractol mandelbrot \
\n\t./fractol julia c_real c_imaginary -> ./fractol julia 0.5 -0.8\
\n\t./fractol burning_ship\n"
# define JULIA 0
# define MANDELBROT 1
# define BURNING_SHIP 2
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_coord
{
	double	real;
	double	imaginary;
}	t_coord;

typedef struct s_f_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	int		num;
	t_img	*img;
	int		pallete[9];
	double	added_x;
	double	added_y;
	double	quality;
	double	zoom;
	int		is_printed;
	int		fill_index;
	int		fill_color;
	double	scale_x;
	double	scale_y;
	double	julia_c_real;
	double	julia_c_imag;

}	t_f_data;

void	init_data(t_f_data *data);
void	print_fractal(t_f_data *data);
int		keyboard_handler(int keysym, t_f_data *data);
int		keyboard_handler(int keysym, t_f_data *data);
int		mouse_handler(int button, int x, int y, t_f_data *data);
int		close_handler(t_f_data *data);
void	exit_with_error(char *msg, int code,
			t_f_data *data, void (*callback)(t_f_data *));
void	exit_with_msg(char *msg, int code,
			t_f_data *data, void (*callback)(t_f_data *));
void	free_data(t_f_data *data);
void	init_pallete(t_f_data *data);
int		smooth_color(double smooth_iter, double max_iter, t_f_data *data);
double	scale_num(int num, double zoom, double scale, double added);
void	set_pixel_color(int x, int y, int color, t_img *img);

#endif